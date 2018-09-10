# ***************************************** #
# ********** PHYSICAL PARAMETERS ********** #
# ***************************************** #
physical ={'densityA': 998.2,
           'viscosityA': 1.004e-6,
           'densityB': 1.205,
           'viscosityB': 1.500e-5,
           'surf_tension_coeff': 72.8E-3,
           'gravity': 'gy'}
           
# ****************************************** #
# ********** NUMERICAL PARAMETERS ********** #
# ****************************************** #
rans2p = {'useMetrics': 1.0,
          'epsFact_viscosity': 3.0,
          'epsFact_density': 3.0,
          'ns_forceStrongDirichlet': False,
          'weak_bc_penalty_constant': 1.0E6,
          'useRBLES': 0.0,
          'useRANS': 0.0,
          'ns_closure': 0,
          'useVF': 1.0,
          'ns_shockCapturingFactor': 0.25,
          'ns_lag_shockCapturing': True,
          'ns_lag_subgridError': True,
          'timeDiscretization': 'vbdf',
          'timeOrder': 2}
clsvof = {'useMetrics': 1.0,
          'epsFactHeaviside': 1.5,
          'epsFactDirac': 1.5,
          'epsFactRedist': 0.33,
          'lambdaFact': 10.0,
          'outputQuantDOFs': True,
          'computeMetrics': 1,
          'eps_tolerance_clsvof': False}