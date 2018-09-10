"""
Multiphase Flow Test
"""
from __future__ import division
from builtins import str
from past.utils import old_div
import numpy as np
from proteus import (Domain, Context,
                     MeshTools as mt)
from proteus.Profiling import logEvent
from proteus.TwoPhaseFlow.utils import parameters
from proteus.TwoPhaseFlow.utils.FESpace import *

# *************************** #
# ***** GENERAL OPTIONS ***** #
# *************************** #
opts= Context.Options([
    ("finalTime",3.0,"Final time for simulation"),
    ("dt_output",0.01,"Time interval to output solution"),
    ("cfl",0.33,"Desired CFL restriction"),
    ("useRans2p",True,"Use rans2p? Otherwise use rans3p"),
    ("useSuperlu",True,"Use super LU: run in serial"),
    ("spaceOrder",1,"Order of approximation of space"),
    ("genMesh",True,"Generate a new mesh"),    
    ("usePUMI",False,"usePUMI workflow")
    ])

# ******************************* #
# ***** PHYSICAL PROPERTIES ***** #
# ******************************* #
# Num. dim
nd=2 
physical_parameters = parameters.physical
#physical_parameters['surf_tension_coeff'] = 0.

# ****************** #
# ***** GAUGES ***** #
# ****************** #
# None

# ****************** #
# ***** DOMAIN ***** #
# ****************** #
# tank
tank_dim = (1.0,1.0)

# **************** #
# ***** MESH ***** #
# **************** #
# REFINEMENT 
refinement = 3
structured=True
boundaries = ['bottom', 'right', 'top', 'left', 'front', 'back']
boundaryTags = dict([(key, i + 1) for (i, key) in enumerate(boundaries)])
if structured:
    nnx = 4 * refinement**2 + 1
    nny = nnx
    triangleFlag=1
    domain = Domain.RectangularDomain(tank_dim)
    domain.boundaryTags = boundaryTags
    he = tank_dim[0]/(nnx - 1)
else:
    vertices = [[0.0, 0.0],  #0
                [tank_dim[0], 0.0],  #1
                [tank_dim[0], tank_dim[1]],  #2
                [0.0, tank_dim[1]]]  #3
    vertexFlags = [boundaryTags['bottom'],
                   boundaryTags['bottom'],
                   boundaryTags['top'],
                   boundaryTags['top']]
    segments = [[0, 1],
                [1, 2],
                [2, 3],
                [3, 0]]
    segmentFlags = [boundaryTags['bottom'],
                    boundaryTags['right'],
                    boundaryTags['top'],
                    boundaryTags['left']]
    regions = [[tank_dim[0]/2., tank_dim[1]/2.]]
    regionFlags = [1]
    domain = Domain.PlanarStraightLineGraphDomain(vertices=vertices,
                                                  vertexFlags=vertexFlags,
                                                  segments=segments,
                                                  segmentFlags=segmentFlags,
                                                  regions=regions,
                                                  regionFlags=regionFlags)
    domain.boundaryTags = boundaryTags
    domain.writePoly("mesh")
    domain.writePLY("mesh")
    domain.writeAsymptote("mesh")
    he = old_div(tank_dim[0], float(4 * refinement - 1))
    domain.MeshOptions.he = he
    triangleOptions = "VApq30Dena%8.8f" % (old_div((he ** 2), 2.0),)

# ****************************** #
# ***** INITIAL CONDITIONS ***** #
# ****************************** #
#################
# NAVIER STOKES #
#################
class pressure_init_cond(object):
    def uOfXT(self,x,t):
        return 0.
    
class vel_u_init_cond(object):
    def uOfXT(self,x,t):
        return 0.

class vel_v_init_cond(object):
    def uOfXT(self,x,t):
        return 0.

#############
# LEVEL SET #
#############
class clsvof_init_cond(object):
    def uOfXT(self,x,t):
        xB = 0.5
        yB = 0.5
        rB = 0.25
        zB = 0.0
        # dist to center of bubble
        r = np.sqrt((x[0]-xB)**2 + (x[1]-yB)**2)
        # dist to surface of bubble
        dB = -(rB - r)
        return dB

# ******************************* #
# ***** BOUNDARY CONDITIONS ***** #
# ******************************* #
#################
# NAVIER STOKES #
#################
# DIRICHLET BCs #
def pressure_DBC(x,flag):
    if (flag==boundaryTags['top']):
        return lambda x,t: 0.
def vel_u_DBC(x,flag):
    None
def vel_v_DBC(x,flag):
    None

# ADVECTIVE FLUX #
def pressure_AFBC(x,flag):
    if not (flag==boundaryTags['top']):
        return lambda x,t: 0.
def vel_u_AFBC(x,flag):
    if not (flag==boundaryTags['top']):
        return lambda x,t: 0.
def vel_v_AFBC(x,flag):
    if not (flag==boundaryTags['top']):
        return lambda x,t: 0.
    
# DIFFUSIVE FLUX #
def vel_u_DFBC(x,flag):
    return lambda x,t: 0.
def vel_v_DFBC(x,flag):
    return lambda x,t: 0.

#############
# LEVEL SET #
#############
def clsvof_DBC(x,flag):
    if (flag==boundaryTags['top']): #Just let air in
        return lambda x,t: 1.
def clsvof_AFBC(x,flag):
    if not (flag==boundaryTags['top']):
        return lambda x,t: 0.
def clsvof_DFBC(x,flag):
    return lambda x,t: 0.

# ************************* #
# ***** TIME STEPPING ***** #
# ************************* #
T=opts.finalTime
dt_output = opts.dt_output
dt_init = min(0.1 * dt_output, 0.001)
runCFL = opts.cfl
nDTout = int(round(old_div(T, dt_output)))

# ******************************** #
# ***** NUMERICAL PARAMETERS ***** #
# ******************************** #
# NS PARAMETERS #
rans2p_parameters = parameters.rans2p
# LS PARAMETERS #
clsvof_parameters = parameters.clsvof

# ***************************** #
# ***** FE DISCRETIZATION ***** #
# ***************************** #
FESpace = FESpace(nd,opts.spaceOrder).getFESpace()

# ******************************** #
# ***** PARALLEL PARITIONING ***** #
# ******************************** #
parallelPartitioningType = mt.MeshParallelPartitioningTypes.node
nLayersOfOverlapForParallel = 0
nLevels=1