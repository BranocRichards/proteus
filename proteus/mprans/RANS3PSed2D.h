#ifndef RANS3PSed2D_H
#define RANS3PSed2D_H
#include <cmath>
#include <iostream>
#include "CompKernel.h"
#include "ModelFactory.h"
//#define COMPRESSIBLE_FORM
namespace proteus
{
  class cppRANS3PSed2D_base
  {
  public:
    virtual ~cppRANS3PSed2D_base(){}
    virtual void calculateResidual(//element
				   double* mesh_trial_ref,
				   double* mesh_grad_trial_ref,
				   double* mesh_dof,
				   double* mesh_velocity_dof,
				   double MOVING_DOMAIN,//0 or 1
				   int* mesh_l2g,
				   double* dV_ref,
				   double* p_trial_ref,
				   double* p_grad_trial_ref,
				   double* p_test_ref,
				   double* p_grad_test_ref,
				   double* vel_trial_ref,
				   double* vel_grad_trial_ref,
				   double* vel_test_ref,
				   double* vel_grad_test_ref,
				   //element boundary
				   double* mesh_trial_trace_ref,
				   double* mesh_grad_trial_trace_ref,
				   double* dS_ref,
				   double* p_trial_trace_ref,
				   double* p_grad_trial_trace_ref,
				   double* p_test_trace_ref,
				   double* p_grad_test_trace_ref,
				   double* vel_trial_trace_ref,
				   double* vel_grad_trial_trace_ref,
				   double* vel_test_trace_ref,
				   double* vel_grad_test_trace_ref,					 
				   double* normal_ref,
				   double* boundaryJac_ref,
				   //physics
				   double eb_adjoint_sigma,
				   double* elementDiameter,
				   double* nodeDiametersArray,
				   double hFactor,
				   int nElements_global,
				   int nElementBoundaries_owned,
				   double useRBLES,
			           double useMetrics, 
				   double alphaBDF,
				   double epsFact_rho,
				   double epsFact_mu, 
				   double sigma,
				   double rho_0,
				   double nu_0,
				   double rho_1,
				   double nu_1,
				   double smagorinskyConstant,
				   int turbulenceClosureModel,
				   double Ct_sge,
				   double Cd_sge,
				   double C_dc,
				   double C_b,
				   //VRANS
				   const double* eps_solid,
				   const double* q_velocity_fluid,
				   const double* q_p_fluid,
				   const double* q_grad_p_fluid,
				   const double* q_vos,
				   const double* q_dvos_dt,
				   const double* q_dragAlpha,
				   const double* q_dragBeta,
				   const double* q_mass_source,
				   const double* q_turb_var_0,
				   const double* q_turb_var_1,
				   const double* q_turb_var_grad_0,
				   double * q_eddy_viscosity, 
				   int* p_l2g, 
				   int* vel_l2g, 
				   double* p_dof, 
				   double* u_dof, 
				   double* v_dof, 
				   double* w_dof,
				   double* g,
				   const double useVF,
				   double* vf,
				   double* phi,
				   double* normal_phi,
				   double* kappa_phi,
				   double* q_mom_u_acc,
				   double* q_mom_v_acc,
				   double* q_mom_w_acc,
				   double* q_mass_adv,
				   double* q_mom_u_acc_beta_bdf, double* q_mom_v_acc_beta_bdf, double* q_mom_w_acc_beta_bdf,
                                   double* q_dV,
                                   double* q_dV_last,
				   double* q_velocity_sge,
				   double* q_cfl,
				   double* q_numDiff_u, double* q_numDiff_v, double* q_numDiff_w,
				   double* q_numDiff_u_last, double* q_numDiff_v_last, double* q_numDiff_w_last,
				   int* sdInfo_u_u_rowptr,int* sdInfo_u_u_colind,			      
				   int* sdInfo_u_v_rowptr,int* sdInfo_u_v_colind,
				   int* sdInfo_u_w_rowptr,int* sdInfo_u_w_colind,
				   int* sdInfo_v_v_rowptr,int* sdInfo_v_v_colind,
				   int* sdInfo_v_u_rowptr,int* sdInfo_v_u_colind,
				   int* sdInfo_v_w_rowptr,int* sdInfo_v_w_colind,
				   int* sdInfo_w_w_rowptr,int* sdInfo_w_w_colind,
				   int* sdInfo_w_u_rowptr,int* sdInfo_w_u_colind,
				   int* sdInfo_w_v_rowptr,int* sdInfo_w_v_colind,
				   int offset_p, int offset_u, int offset_v, int offset_w, 
				   int stride_p, int stride_u, int stride_v, int stride_w, 
				   double* globalResidual,
				   int nExteriorElementBoundaries_global,
				   int* exteriorElementBoundariesArray,
				   int* elementBoundaryElementsArray,
				   int* elementBoundaryLocalElementBoundariesArray,
				   double* ebqe_vf_ext,
				   double* bc_ebqe_vf_ext,
				   double* ebqe_phi_ext,
				   double* bc_ebqe_phi_ext,
				   double* ebqe_normal_phi_ext,
				   double* ebqe_kappa_phi_ext,
                                   //VRANS
				   const double* ebqe_vos_ext,
				   const double* ebqe_p_fluid_ext,
				   const double* ebqe_grad_p_fluid_ext,
				   const double* ebqe_turb_var_0,
				   const double* ebqe_turb_var_1,
                                   //VRANS end
				   int* isDOFBoundary_p,
				   int* isDOFBoundary_u,
				   int* isDOFBoundary_v,
				   int* isDOFBoundary_w,
				   int* isAdvectiveFluxBoundary_p,
				   int* isAdvectiveFluxBoundary_u,
				   int* isAdvectiveFluxBoundary_v,
				   int* isAdvectiveFluxBoundary_w,
				   int* isDiffusiveFluxBoundary_u,
				   int* isDiffusiveFluxBoundary_v,
				   int* isDiffusiveFluxBoundary_w,
				   double* ebqe_bc_p_ext,
				   double* ebqe_bc_flux_mass_ext,
				   double* ebqe_bc_flux_mom_u_adv_ext,
				   double* ebqe_bc_flux_mom_v_adv_ext,
				   double* ebqe_bc_flux_mom_w_adv_ext,
				   double* ebqe_bc_u_ext,
				   double* ebqe_bc_flux_u_diff_ext,
				   double* ebqe_penalty_ext,
				   double* ebqe_bc_v_ext,
				   double* ebqe_bc_flux_v_diff_ext,
				   double* ebqe_bc_w_ext,
				   double* ebqe_bc_flux_w_diff_ext,
				   double* q_x,
				   double* q_velocity,
				   double* ebqe_velocity,
				   double* flux,
				   double* elementResidual_p,
				   int* elementFlags,
				   int* boundaryFlags,
				   double* barycenters,
				   double* wettedAreas,
				   double* netForces_p,
				   double* netForces_v,
				   double* netMoments)=0;
    virtual void calculateJacobian(//element
				   double* mesh_trial_ref,
				   double* mesh_grad_trial_ref,
				   double* mesh_dof,
				   double* mesh_velocity_dof,
				   double MOVING_DOMAIN,
				   int* mesh_l2g,
				   double* dV_ref,
				   double* p_trial_ref,
				   double* p_grad_trial_ref,
				   double* p_test_ref,
				   double* p_grad_test_ref,
				   double* vel_trial_ref,
				   double* vel_grad_trial_ref,
				   double* vel_test_ref,
				   double* vel_grad_test_ref,
				   //element boundary
				   double* mesh_trial_trace_ref,
				   double* mesh_grad_trial_trace_ref,
				   double* dS_ref,
				   double* p_trial_trace_ref,
				   double* p_grad_trial_trace_ref,
				   double* p_test_trace_ref,
				   double* p_grad_test_trace_ref,
				   double* vel_trial_trace_ref,
				   double* vel_grad_trial_trace_ref,
				   double* vel_test_trace_ref,
				   double* vel_grad_test_trace_ref,					 
				   double* normal_ref,
				   double* boundaryJac_ref,
				   //physics
				   double eb_adjoint_sigma,
				   double* elementDiameter,
				   double* nodeDiametersArray,
				   double hFactor,
				   int nElements_global,
				   double useRBLES,
			           double useMetrics, 
				   double alphaBDF,
				   double epsFact_rho,
				   double epsFact_mu,
				   double sigma,
				   double rho_0,
				   double nu_0,
				   double rho_1,
				   double nu_1,
				   double smagorinskyConstant,
				   int turbulenceClosureModel,
				   double Ct_sge,
				   double Cd_sge,
				   double C_dg,
				   double C_b,
				   //VRANS
				   const double* eps_solid,
				   const double* q_velocity_fluid,
				   const double* q_p_fluid,
				   const double* q_grad_p_fluid,
				   const double* q_vos,
				   const double* q_dragAlpha,
				   const double* q_dragBeta,
				   const double* q_mass_source,
				   const double* q_turb_var_0,
				   const double* q_turb_var_1,
				   const double* q_turb_var_grad_0,
				   int* p_l2g, 
				   int* vel_l2g,
				   double* p_dof, double* u_dof, double* v_dof, double* w_dof,
				   double* g,
				   const double useVF,
				   double* vf,
				   double* phi,
				   double* normal_phi,
				   double* kappa_phi,
				   double* q_mom_u_acc_beta_bdf, double* q_mom_v_acc_beta_bdf, double* q_mom_w_acc_beta_bdf,
                                   double* q_dV,
                                   double* q_dV_last,
				   double* q_velocity_sge,
				   double* q_cfl,
				   double* q_numDiff_u_last, double* q_numDiff_v_last, double* q_numDiff_w_last,
				   int* sdInfo_u_u_rowptr,int* sdInfo_u_u_colind,			      
				   int* sdInfo_u_v_rowptr,int* sdInfo_u_v_colind,
				   int* sdInfo_u_w_rowptr,int* sdInfo_u_w_colind,
				   int* sdInfo_v_v_rowptr,int* sdInfo_v_v_colind,
				   int* sdInfo_v_u_rowptr,int* sdInfo_v_u_colind,
				   int* sdInfo_v_w_rowptr,int* sdInfo_v_w_colind,
				   int* sdInfo_w_w_rowptr,int* sdInfo_w_w_colind,
				   int* sdInfo_w_u_rowptr,int* sdInfo_w_u_colind,
				   int* sdInfo_w_v_rowptr,int* sdInfo_w_v_colind,
				   int* csrRowIndeces_p_p,int* csrColumnOffsets_p_p,
				   int* csrRowIndeces_p_u,int* csrColumnOffsets_p_u,
				   int* csrRowIndeces_p_v,int* csrColumnOffsets_p_v,
				   int* csrRowIndeces_p_w,int* csrColumnOffsets_p_w,
				   int* csrRowIndeces_u_p,int* csrColumnOffsets_u_p,
				   int* csrRowIndeces_u_u,int* csrColumnOffsets_u_u,
				   int* csrRowIndeces_u_v,int* csrColumnOffsets_u_v,
				   int* csrRowIndeces_u_w,int* csrColumnOffsets_u_w,
				   int* csrRowIndeces_v_p,int* csrColumnOffsets_v_p,
				   int* csrRowIndeces_v_u,int* csrColumnOffsets_v_u,
				   int* csrRowIndeces_v_v,int* csrColumnOffsets_v_v,
				   int* csrRowIndeces_v_w,int* csrColumnOffsets_v_w,
				   int* csrRowIndeces_w_p,int* csrColumnOffsets_w_p,
				   int* csrRowIndeces_w_u,int* csrColumnOffsets_w_u,
				   int* csrRowIndeces_w_v,int* csrColumnOffsets_w_v,
				   int* csrRowIndeces_w_w,int* csrColumnOffsets_w_w,
				   double* globalJacobian,
				   int nExteriorElementBoundaries_global,
				   int* exteriorElementBoundariesArray,
				   int* elementBoundaryElementsArray,
				   int* elementBoundaryLocalElementBoundariesArray,
				   double* ebqe_vf_ext,
				   double* bc_ebqe_vf_ext,
				   double* ebqe_phi_ext,
				   double* bc_ebqe_phi_ext,
				   double* ebqe_normal_phi_ext,
				   double* ebqe_kappa_phi_ext,
				   //VRANS
				   const double* ebqe_vos_ext,
				   const double* ebqe_p_fluid_ext,
				   const double* ebqe_grad_p_fluid_ext,
				   const double* ebqe_turb_var_0,
				   const double* ebqe_turb_var_1,
				   //VRANS end					   
				   int* isDOFBoundary_p,
				   int* isDOFBoundary_u,
				   int* isDOFBoundary_v,
				   int* isDOFBoundary_w,
				   int* isAdvectiveFluxBoundary_p,
				   int* isAdvectiveFluxBoundary_u,
				   int* isAdvectiveFluxBoundary_v,
				   int* isAdvectiveFluxBoundary_w,
				   int* isDiffusiveFluxBoundary_u,
				   int* isDiffusiveFluxBoundary_v,
				   int* isDiffusiveFluxBoundary_w,
				   double* ebqe_bc_p_ext,
				   double* ebqe_bc_flux_mass_ext,
				   double* ebqe_bc_flux_mom_u_adv_ext,
				   double* ebqe_bc_flux_mom_v_adv_ext,
				   double* ebqe_bc_flux_mom_w_adv_ext,
				   double* ebqe_bc_u_ext,
				   double* ebqe_bc_flux_u_diff_ext,
				   double* ebqe_penalty_ext,
				   double* ebqe_bc_v_ext,
				   double* ebqe_bc_flux_v_diff_ext,
				   double* ebqe_bc_w_ext,
				   double* ebqe_bc_flux_w_diff_ext,
				   int* csrColumnOffsets_eb_p_p,
				   int* csrColumnOffsets_eb_p_u,
				   int* csrColumnOffsets_eb_p_v,
				   int* csrColumnOffsets_eb_p_w,
				   int* csrColumnOffsets_eb_u_p,
				   int* csrColumnOffsets_eb_u_u,
				   int* csrColumnOffsets_eb_u_v,
				   int* csrColumnOffsets_eb_u_w,
				   int* csrColumnOffsets_eb_v_p,
				   int* csrColumnOffsets_eb_v_u,
				   int* csrColumnOffsets_eb_v_v,
				   int* csrColumnOffsets_eb_v_w,
				   int* csrColumnOffsets_eb_w_p,
				   int* csrColumnOffsets_eb_w_u,
				   int* csrColumnOffsets_eb_w_v,
				   int* csrColumnOffsets_eb_w_w,				   
				   int* elementFlags)=0;
    virtual void calculateVelocityAverage(int nExteriorElementBoundaries_global,
    					  int* exteriorElementBoundariesArray,
    					  int nInteriorElementBoundaries_global,
    					  int* interiorElementBoundariesArray,
    					  int* elementBoundaryElementsArray,
    					  int* elementBoundaryLocalElementBoundariesArray,
    					  double* mesh_dof,
                                          double* mesh_velocity_dof,
                                          double MOVING_DOMAIN,//0 or 1
    					  int* mesh_l2g,
    					  double* mesh_trial_trace_ref,
    					  double* mesh_grad_trial_trace_ref,
    					  double* normal_ref,
    					  double* boundaryJac_ref,
    					  int* vel_l2g,
    					  double* u_dof,
    					  double* v_dof,
    					  double* w_dof,
    					  double* vel_trial_trace_ref,
    					  double* ebqe_velocity,
    					  double* velocityAverage)=0;
  };
  
  template<class CompKernelType,
	   int nSpace,
	   int nQuadraturePoints_element,
	   int nDOF_mesh_trial_element,
	   int nDOF_trial_element,
	   int nDOF_test_element,
	   int nQuadraturePoints_elementBoundary>
  class cppRANS3PSed2D : public cppRANS3PSed2D_base
  {
  public:
    const int nDOF_test_X_trial_element;
    CompKernelType ck;
    cppRANS3PSed2D():
      nDOF_test_X_trial_element(nDOF_test_element*nDOF_trial_element),
      ck()
	{/*	     std::cout<<"Constructing cppRANS3PSed2D<CompKernelTemplate<"
		      <<0<<","
		      <<0<<","
		      <<0<<","
		      <<0<<">,"*/
		    /*  <<nSpaceIn<<","
		      <<nQuadraturePoints_elementIn<<","
		      <<nDOF_mesh_trial_elementIn<<","
		      <<nDOF_trial_elementIn<<","
		      <<nDOF_test_elementIn<<","
		      <<nQuadraturePoints_elementBoundaryIn<<">());"*/
	  /*  <<std::endl<<std::flush; */
	}
      
    inline double smoothedHeaviside(double eps, double phi)
    {
      double H;
      if (phi > eps)
	H=1.0;
      else if (phi < -eps)
	H=0.0;
      else if (phi==0.0)
	H=0.5;
      else
	H = 0.5*(1.0 + phi/eps + sin(M_PI*phi/eps)/M_PI);
      return H;
    }
    
    inline double smoothedHeaviside_integral(double eps, double phi)
    {
      double HI;
      if (phi > eps)
	{
	  HI= phi - eps							\
	    + 0.5*(eps + 0.5*eps*eps/eps - eps*cos(M_PI*eps/eps)/(M_PI*M_PI)) \
	    - 0.5*((-eps) + 0.5*(-eps)*(-eps)/eps - eps*cos(M_PI*(-eps)/eps)/(M_PI*M_PI));
	}
      else if (phi < -eps)
	{
	  HI=0.0;
	}
      else
	{
	  HI = 0.5*(phi + 0.5*phi*phi/eps - eps*cos(M_PI*phi/eps)/(M_PI*M_PI)) \
	    - 0.5*((-eps) + 0.5*(-eps)*(-eps)/eps - eps*cos(M_PI*(-eps)/eps)/(M_PI*M_PI));
	}
      return HI;
    }
 
    inline double smoothedDirac(double eps, double phi)
    {
      double d;
      if (phi > eps)
	d=0.0;
      else if (phi < -eps)
	d=0.0;
      else
	d = 0.5*(1.0 + cos(M_PI*phi/eps))/eps;
      return d;
    }

    inline
    void evaluateCoefficients(const double eps_rho,
			      const double eps_mu,
			      const double sigma,
			      const double rho_0,
			      double nu_0,
			      const double rho_1,
			      double nu_1,
			      const double h_e,
			      const double smagorinskyConstant,
			      const int turbulenceClosureModel,
			      const double g[nSpace],
			      const double useVF,
			      const double& vf,
			      const double& phi,
			      const double n[nSpace],
			      const double& kappa,
			      const double vos,//VRANS specific
			      const double& p_fluid,
			      const double grad_p_fluid[nSpace],
			      const double& vosStar,
			      const double grad_vosStar[nSpace],
			      const double grad_u[nSpace],
			      const double grad_v[nSpace],
			      const double grad_w[nSpace],
			      const double& u,
			      const double& v,
			      const double& w,
			      double& eddy_viscosity,
			      double& mom_u_acc,
			      double& dmom_u_acc_u,
			      double& mom_v_acc,
			      double& dmom_v_acc_v,
			      double& mom_w_acc,
			      double& dmom_w_acc_w,
			      double mass_adv[nSpace],
			      double dmass_adv_u[nSpace],
			      double dmass_adv_v[nSpace],
			      double dmass_adv_w[nSpace],
			      double mom_u_adv[nSpace],
			      double dmom_u_adv_u[nSpace],
			      double dmom_u_adv_v[nSpace],
			      double dmom_u_adv_w[nSpace],
			      double mom_v_adv[nSpace],
			      double dmom_v_adv_u[nSpace],
			      double dmom_v_adv_v[nSpace],
			      double dmom_v_adv_w[nSpace],
			      double mom_w_adv[nSpace],
			      double dmom_w_adv_u[nSpace],
			      double dmom_w_adv_v[nSpace],
			      double dmom_w_adv_w[nSpace],
			      double mom_uu_diff_ten[nSpace],
			      double mom_vv_diff_ten[nSpace],
			      double mom_ww_diff_ten[nSpace],
			      double mom_uv_diff_ten[1],
			      double mom_uw_diff_ten[1],
			      double mom_vu_diff_ten[1],
			      double mom_vw_diff_ten[1],
			      double mom_wu_diff_ten[1],
			      double mom_wv_diff_ten[1],
			      double& mom_u_source,
			      double& mom_v_source,
			      double& mom_w_source,
			      double& mom_u_ham,
			      double dmom_u_ham_grad_p[nSpace],
			      double& mom_v_ham,
			      double dmom_v_ham_grad_p[nSpace],
			      double& mom_w_ham,
			      double dmom_w_ham_grad_p[nSpace])
    {
      double rho,nu,mu,H_rho,d_rho,H_mu,d_mu,norm_n,nu_t0=0.0,nu_t1=0.0,nu_t;
      H_rho = (1.0-useVF)*smoothedHeaviside(eps_rho,phi) + useVF*fmin(1.0,fmax(0.0,vf));
      d_rho = (1.0-useVF)*smoothedDirac(eps_rho,phi);
      H_mu = (1.0-useVF)*smoothedHeaviside(eps_mu,phi) + useVF*fmin(1.0,fmax(0.0,vf));
      d_mu = (1.0-useVF)*smoothedDirac(eps_mu,phi);
  
      //calculate eddy viscosity
      switch (turbulenceClosureModel)
	{
	  double norm_S;
	case 1:
	  {
	    norm_S = sqrt(2.0*(grad_u[0]*grad_u[0] + grad_v[1]*grad_v[1] + //grad_w[2]*grad_w[2] +
			       0.5*(grad_u[1]+grad_v[0])*(grad_u[1]+grad_v[0])));/* + 
			       0.5*(grad_u[2]+grad_w[0])*(grad_u[2]+grad_w[0]) +
			       0.5*(grad_v[2]+grad_w[1])*(grad_v[2]+grad_w[1])));*/
	    nu_t0 = smagorinskyConstant*smagorinskyConstant*h_e*h_e*norm_S;
	    nu_t1 = smagorinskyConstant*smagorinskyConstant*h_e*h_e*norm_S;
	  }
	case 2:
	  {
	    double re_0,cs_0=0.0,re_1,cs_1=0.0;
	    norm_S = sqrt(2.0*(grad_u[0]*grad_u[0] + grad_v[1]*grad_v[1] + //grad_w[2]*grad_w[2] +
			       0.5*(grad_u[1]+grad_v[0])*(grad_u[1]+grad_v[0])));/* + 
			       0.5*(grad_u[2]+grad_w[0])*(grad_u[2]+grad_w[0]) +
			       0.5*(grad_v[2]+grad_w[1])*(grad_v[2]+grad_w[1])));*/
	    re_0 = h_e*h_e*norm_S/nu_0;
	    if (re_0 > 1.0)
	      cs_0=0.027*pow(10.0,-3.23*pow(re_0,-0.92));
	    nu_t0 = cs_0*h_e*h_e*norm_S;
	    re_1 = h_e*h_e*norm_S/nu_1;
	    if (re_1 > 1.0)
	      cs_1=0.027*pow(10.0,-3.23*pow(re_1,-0.92));
	    nu_t1 = cs_1*h_e*h_e*norm_S;
	  }
	}
      
      rho = rho_0*(1.0-H_rho)+rho_1*H_rho;
      nu_t= nu_t0*(1.0-H_mu)+nu_t1*H_mu;
      nu  = nu_0*(1.0-H_mu)+nu_1*H_mu;
      nu += nu_t;
      mu  = rho_0*nu_0*(1.0-H_mu)+rho_1*nu_1*H_mu;

      eddy_viscosity = nu_t;
#ifdef COMPRESSIBLE_FORM
      eddy_viscosity = nu_t*rho;

      //u momentum accumulation
      mom_u_acc=vos*rho*u;
      dmom_u_acc_u=vos*rho;
  
      //v momentum accumulation
      mom_v_acc=vos*rho*v;
      dmom_v_acc_v=vos*rho;
  
      /* //w momentum accumulation */
      /* mom_w_acc=vos*rho*w; */
      /* dmom_w_acc_w=vos*rho; */
  
  
      //mass advective flux
      mass_adv[0]=vos*u;
      mass_adv[1]=vos*v;
      /* mass_adv[2]=vos*w; */
  
      dmass_adv_u[0]=vos;
      dmass_adv_u[1]=0.0;
      /* dmass_adv_u[2]=0.0; */

      dmass_adv_v[0]=0.0;
      dmass_adv_v[1]=vos;
      /* dmass_adv_v[2]=0.0; */

      dmass_adv_w[0]=0.0;
      dmass_adv_w[1]=0.0;
      /* dmass_adv_w[2]=vos; */

      //u momentum advective flux
      mom_u_adv[0]=vos*rho*u*u;
      mom_u_adv[1]=vos*rho*u*v;
      /* mom_u_adv[2]=vos*rho*u*w; */
  
      dmom_u_adv_u[0]=vos*rho*2.0*u;
      dmom_u_adv_u[1]=vos*rho*v;
      /* dmom_u_adv_u[2]=vos*rho*w; */
  
      dmom_u_adv_v[0]=0.0;
      dmom_u_adv_v[1]=vos*rho*u;
      /* dmom_u_adv_v[2]=0.0; */
  
      /* dmom_u_adv_w[0]=0.0; */
      /* dmom_u_adv_w[1]=0.0; */
      /* dmom_u_adv_w[2]=vos*rho*u; */
  
      //v momentum advective_flux
      mom_v_adv[0]=vos*rho*v*u;
      mom_v_adv[1]=vos*rho*v*v;
      /* mom_v_adv[2]=vos*rho*v*w; */
  
      dmom_v_adv_u[0]=vos*rho*v;
      dmom_v_adv_u[1]=0.0;
      /* dmom_v_adv_u[2]=0.0; */
  
      /* dmom_v_adv_w[0]=0.0; */
      /* dmom_v_adv_w[1]=0.0; */
      /* dmom_v_adv_w[2]=vos*rho*v; */
  
      dmom_v_adv_v[0]=vos*rho*u;
      dmom_v_adv_v[1]=vos*rho*2.0*v;
      /* dmom_v_adv_v[2]=vos*rho*w; */
  
      /* //w momentum advective_flux */
      /* mom_w_adv[0]=vos*rho*w*u; */
      /* mom_w_adv[1]=vos*rho*w*v; */
      /* mom_w_adv[2]=vos*rho*w*w; */
  
      /* dmom_w_adv_u[0]=vos*rho*w; */
      /* dmom_w_adv_u[1]=0.0; */
      /* dmom_w_adv_u[2]=0.0; */
  
      /* dmom_w_adv_v[0]=0.0; */
      /* dmom_w_adv_v[1]=vos*rho*w; */
      /* dmom_w_adv_v[2]=0.0; */
  
      /* dmom_w_adv_w[0]=vos*rho*u; */
      /* dmom_w_adv_w[1]=vos*rho*v; */
      /* dmom_w_adv_w[2]=vos*rho*2.0*w; */
  
      //u momentum diffusion tensor
      mom_uu_diff_ten[0] = 2.0*vos*mu;
      mom_uu_diff_ten[1] = vos*mu;
      /* mom_uu_diff_ten[2] = vos*mu; */
  
      mom_uv_diff_ten[0]=vos*mu;
  
      /* mom_uw_diff_ten[0]=vos*mu; */
  
      //v momentum diffusion tensor
      mom_vv_diff_ten[0] = vos*mu;
      mom_vv_diff_ten[1] = 2.0*vos*mu;
      /* mom_vv_diff_ten[2] = vos*mu; */
  
      mom_vu_diff_ten[0]=vos*mu;
  
      /* mom_vw_diff_ten[0]=vos*mu; */
  
      /* //w momentum diffusion tensor */
      /* mom_ww_diff_ten[0] = vos*mu; */
      /* mom_ww_diff_ten[1] = vos*mu; */
      /* mom_ww_diff_ten[2] = 2.0*vos*mu; */
  
      /* mom_wu_diff_ten[0]=vos*mu; */
  
      /* mom_wv_diff_ten[0]=vos*mu; */
  
      //momentum sources
      norm_n = sqrt(n[0]*n[0]+n[1]*n[1]);//+n[2]*n[2]);
      mom_u_source = -vos*rho*g[0];// - vos*d_mu*sigma*kappa*n[0];
      mom_v_source = -vos*rho*g[1];// - vos*d_mu*sigma*kappa*n[1];
      /* mom_w_source = -vos*rho*g[2];// - vos*d_mu*sigma*kappa*n[2]; */
   
      //u momentum Hamiltonian (pressure)
      mom_u_ham = vos*grad_p_fluid[0] + grad_vosStar[0];
      dmom_u_ham_grad_p[0]=1.0;
      dmom_u_ham_grad_p[1]=0.0;
      /* dmom_u_ham_grad_p[2]=0.0; */
  
      //v momentum Hamiltonian (pressure)
      mom_v_ham = vos*grad_p_fluid[1] + grad_vosStar[1];
      dmom_v_ham_grad_p[0]=0.0;
      dmom_v_ham_grad_p[1]=1.0;
      /* dmom_v_ham_grad_p[2]=0.0; */
  
      /* //w momentum Hamiltonian (pressure) */
      /* mom_w_ham = vos*grad_p_fluid[2] + grad_vosStar[2]; */
      /* dmom_w_ham_grad_p[0]=0.0; */
      /* dmom_w_ham_grad_p[1]=0.0; */
      /* dmom_w_ham_grad_p[2]=1.0; */
#else
      //u momentum accumulation
      mom_u_acc=vos*u;
      dmom_u_acc_u=vos;
  
      //v momentum accumulation
      mom_v_acc=vos*v;
      dmom_v_acc_v=vos;
  
      /* //w momentum accumulation */
      /* mom_w_acc=vos*w; */
      /* dmom_w_acc_w=vos; */
  
  
      //mass advective flux
      mass_adv[0]=vos*u;
      mass_adv[1]=vos*v;
      /* mass_adv[2]=vos*w; */
  
      dmass_adv_u[0]=vos;
      dmass_adv_u[1]=0.0;
      /* dmass_adv_u[2]=0.0; */

      dmass_adv_v[0]=0.0;
      dmass_adv_v[1]=vos;
      /* dmass_adv_v[2]=0.0; */

      /* dmass_adv_w[0]=0.0; */
      /* dmass_adv_w[1]=0.0; */
      /* dmass_adv_w[2]=vos; */

      //u momentum advective flux
      mom_u_adv[0]=vos*u*u;
      mom_u_adv[1]=vos*u*v;
      /* mom_u_adv[2]=vos*u*w; */
  
      dmom_u_adv_u[0]=2.0*vos*u;
      dmom_u_adv_u[1]=vos*v;
      /* dmom_u_adv_u[2]=vos*w; */
  
      dmom_u_adv_v[0]=0.0;
      dmom_u_adv_v[1]=vos*u;
      /* dmom_u_adv_v[2]=0.0; */
  
      /* dmom_u_adv_w[0]=0.0; */
      /* dmom_u_adv_w[1]=0.0; */
      /* dmom_u_adv_w[2]=vos*u; */
  
      //v momentum advective_flux
      mom_v_adv[0]=vos*v*u;
      mom_v_adv[1]=vos*v*v;
      /* mom_v_adv[2]=vos*v*w; */
  
      dmom_v_adv_u[0]=vos*v;
      dmom_v_adv_u[1]=0.0;
      /* dmom_v_adv_u[2]=0.0; */
  
      /* dmom_v_adv_w[0]=0.0; */
      /* dmom_v_adv_w[1]=0.0; */
      /* dmom_v_adv_w[2]=vos*v; */
  
      dmom_v_adv_v[0]=vos*u;
      dmom_v_adv_v[1]=2.0*vos*v;
      /* dmom_v_adv_v[2]=vos*w; */
  
      /* //w momentum advective_flux */
      /* mom_w_adv[0]=vos*w*u; */
      /* mom_w_adv[1]=vos*w*v; */
      /* mom_w_adv[2]=vos*w*w; */
  
      /* dmom_w_adv_u[0]=vos*w; */
      /* dmom_w_adv_u[1]=0.0; */
      /* dmom_w_adv_u[2]=0.0; */
  
      /* dmom_w_adv_v[0]=0.0; */
      /* dmom_w_adv_v[1]=vos*w; */
      /* dmom_w_adv_v[2]=0.0; */
  
      /* dmom_w_adv_w[0]=vos*u; */
      /* dmom_w_adv_w[1]=vos*v; */
      /* dmom_w_adv_w[2]=2.0*vos*w; */

      //u momentum diffusion tensor
      mom_uu_diff_ten[0] = 2.0*vos*nu;
      mom_uu_diff_ten[1] = vos*nu;
      /* mom_uu_diff_ten[2] = vos*nu; */
  
      mom_uv_diff_ten[0]=vos*nu;
  
      /* mom_uw_diff_ten[0]=vos*nu; */
  
      //v momentum diffusion tensor
      mom_vv_diff_ten[0] = vos*nu;
      mom_vv_diff_ten[1] = 2.0*vos*nu;
      /* mom_vv_diff_ten[2] = vos*nu; */
  
      mom_vu_diff_ten[0]=vos*nu;
  
      /* mom_vw_diff_ten[0]=vos*nu; */
  
      /* //w momentum diffusion tensor */
      /* mom_ww_diff_ten[0] = vos*nu; */
      /* mom_ww_diff_ten[1] = vos*nu; */
      /* mom_ww_diff_ten[2] = 2.0*vos*nu; */
  
      /* mom_wu_diff_ten[0]=vos*nu; */
  
      /* mom_wv_diff_ten[0]=vos*nu; */
  
      //momentum sources
      norm_n = sqrt(n[0]*n[0]+n[1]*n[1]);//+n[2]*n[2]);
      mom_u_source = -vos*g[0];// - vos*d_mu*sigma*kappa*n[0]/(rho*(norm_n+1.0e-8));
      mom_v_source = -vos*g[1];// - vos*d_mu*sigma*kappa*n[1]/(rho*(norm_n+1.0e-8));
      /* mom_w_source = -vos*g[2];// - vos*d_mu*sigma*kappa*n[2]/(rho*(norm_n+1.0e-8)); */
   
      //u momentum Hamiltonian (pressure)
      mom_u_ham = vos*grad_p_fluid[0]/rho + grad_vosStar[0]/rho;
      dmom_u_ham_grad_p[0]=1.0/rho;
      dmom_u_ham_grad_p[1]=0.0;
      /* dmom_u_ham_grad_p[2]=0.0; */
  
      //v momentum Hamiltonian (pressure)
      mom_v_ham = vos*grad_p_fluid[1]/rho + grad_vosStar[1]/rho;
      dmom_v_ham_grad_p[0]=0.0;
      dmom_v_ham_grad_p[1]=1.0/rho;
      /* dmom_v_ham_grad_p[2]=0.0; */
  
      /* //w momentum Hamiltonian (pressure) */
      /* mom_w_ham = vos*grad_p_fluid[2]/rho + grad_vosStar[2]/rho; */
      /* dmom_w_ham_grad_p[0]=0.0; */
      /* dmom_w_ham_grad_p[1]=0.0; */
      /* dmom_w_ham_grad_p[2]=1.0/rho; */
#endif
    }
    //VRANS specific
    inline
      void updateDarcyForchheimerTerms_Ergun(/* const double linearDragFactor, */
					   /* const double nonlinearDragFactor, */
					   /* const double vos, */
					   /* const double meanGrainSize, */
					   const double alpha,
					   const double beta,
					   const double eps_rho,
					   const double eps_mu,
					   const double rho_0,
					   const double nu_0,
					   const double rho_1,
					   const double nu_1,
					   const double useVF,
					   const double vf,
					   const double phi,
					   const double u,
					   const double v,
					   const double w,
					   const double eps_s,
					   const double phi_s,
					   const double u_f,
					   const double v_f,
					   const double w_f,
					   double& mom_u_source,
					   double& mom_v_source,
					   double& mom_w_source,
					   double dmom_u_source[nSpace],
					   double dmom_v_source[nSpace],
					   double dmom_w_source[nSpace])
    {
      double mu,nu,H_mu,uc,duc_du,duc_dv,duc_dw,viscosity,H_s;
      H_mu = (1.0-useVF)*smoothedHeaviside(eps_mu,phi)+useVF*fmin(1.0,fmax(0.0,vf));
      nu  = nu_0*(1.0-H_mu)+nu_1*H_mu;
      mu  = rho_0*nu_0*(1.0-H_mu)+rho_1*nu_1*H_mu;
#ifdef COMPRESSIBLE_FORM
      viscosity = mu;
#else
      viscosity = nu;
#endif
      double x = fmax(0.0, fmin( 1.0, 0.5+phi_s/(2.0*eps_s)));//0 at phi_s = -eps, 1 at phi_s=eps
      x = 1. - x;
      H_s = 1.- (exp(pow(x,3.5)) - 1.)/ (exp(1.) - 1.);
      //
      uc = sqrt(u*u+v*v*+w*w); 
      duc_du = u/(uc+1.0e-12);
      duc_dv = v/(uc+1.0e-12);
      /* duc_dw = w/(uc+1.0e-12); */

      mom_u_source += H_s*viscosity*(alpha + beta*uc)*(u-u_f);
      mom_v_source += H_s*viscosity*(alpha + beta*uc)*(v-v_f);
      /* mom_w_source += H_s*viscosity*(alpha + beta*uc)*(w-w_f); */

      dmom_u_source[0] = H_s*viscosity*(alpha + beta*(uc + u*duc_du));
      dmom_u_source[1] = H_s*viscosity*beta*u*duc_dv;
      /* dmom_u_source[2] = H_s*viscosity*beta*u*duc_dw; */
    
      dmom_v_source[0] = H_s*viscosity*beta*v*duc_du;
      dmom_v_source[1] = H_s*viscosity*(alpha + beta*(uc + v*duc_dv));
      /* dmom_v_source[2] = H_s*viscosity*beta*w*duc_dw; */

      /* dmom_w_source[0] = H_s*viscosity*beta*w*duc_du; */
      /* dmom_w_source[1] = H_s*viscosity*beta*w*duc_dv; */
      /* dmom_w_source[2] = H_s*viscosity*(alpha + beta*(uc + w*duc_dw)); */
    }

    inline
      void updateTurbulenceClosure(const int turbulenceClosureModel,
				   const double eps_rho,
				   const double eps_mu,
				   const double rho_0,
				   const double nu_0,
				   const double rho_1,
				   const double nu_1,
				   const double useVF,
				   const double vf,
				   const double phi,
				   const double vos,
				   const double eddy_visc_coef_0,
				   const double turb_var_0, //k for k-eps or k-omega
				   const double turb_var_1, //epsilon for k-epsilon, omega for k-omega
				   const double turb_grad_0[nSpace],//grad k for k-eps,k-omega
				   double& eddy_viscosity,
				   double mom_uu_diff_ten[nSpace],
				   double mom_vv_diff_ten[nSpace],
				   double mom_ww_diff_ten[nSpace],
				   double mom_uv_diff_ten[1],
				   double mom_uw_diff_ten[1],
				   double mom_vu_diff_ten[1],
				   double mom_vw_diff_ten[1],
				   double mom_wu_diff_ten[1],
				   double mom_wv_diff_ten[1],
				   double& mom_u_source,
				   double& mom_v_source,
				   double& mom_w_source)
    {
      /****
	   eddy_visc_coef 
	       <= 2  LES (do nothing)
	       == 3  k-epsilon 
	
      */
      assert (turbulenceClosureModel >=3);
      double rho,nu,H_mu,nu_t=0.0,nu_t_keps =0.0, nu_t_komega=0.0;
      double isKEpsilon = 1.0;
      if (turbulenceClosureModel == 4)
	isKEpsilon = 0.0;
      H_mu = (1.0-useVF)*smoothedHeaviside(eps_mu,phi)+useVF*fmin(1.0,fmax(0.0,vf));
      nu  = nu_0*(1.0-H_mu)+nu_1*H_mu;
      rho  = rho_0*(1.0-H_mu)+rho_1*H_mu;

      const double twoThirds = 2.0/3.0; const double div_zero = 1.0e-2*fmin(nu_0,nu_1);
      mom_u_source += twoThirds*turb_grad_0[0];
      mom_v_source += twoThirds*turb_grad_0[1];
      /* mom_w_source += twoThirds*turb_grad_0[2]; */

      //--- closure model specific ---
      //k-epsilon
      nu_t_keps = eddy_visc_coef_0*turb_var_0*turb_var_0/(fabs(turb_var_1) + div_zero);
      //k-omega
      nu_t_komega = turb_var_0/(fabs(turb_var_1) + div_zero);
      //
      nu_t = isKEpsilon*nu_t_keps + (1.0-isKEpsilon)*nu_t_komega;
      //mwf debug
      //if (nu_t > 1.e6*nu)
      //{
      //  std::cout<<"RANS3PSed2D WARNING isKEpsilon = "<<isKEpsilon<<" nu_t = " <<nu_t<<" nu= "<<nu<<" k= "<<turb_var_0<<" turb_var_1= "<<turb_var_1<<std::endl; 
      //}

      nu_t = fmax(nu_t,1.0e-4*nu); //limit according to Lew, Buscaglia etal 01
      //mwf hack
      nu_t     = fmin(nu_t,1.0e6*nu);
#ifdef COMPRESSIBLE_FORM
      eddy_viscosity = nu_t*rho;
      //u momentum diffusion tensor
      mom_uu_diff_ten[0] += 2.0*vos*eddy_viscosity;
      mom_uu_diff_ten[1] += vos*eddy_viscosity;
      /* mom_uu_diff_ten[2] += vos*eddy_viscosity; */
  
      mom_uv_diff_ten[0] +=vos*eddy_viscosity;
  
      /* mom_uw_diff_ten[0] +=vos*eddy_viscosity; */
  
      //v momentum diffusion tensor
      mom_vv_diff_ten[0] += vos*eddy_viscosity;
      mom_vv_diff_ten[1] += 2.0*vos*eddy_viscosity;
      /* mom_vv_diff_ten[2] += vos*eddy_viscosity; */
  
      mom_vu_diff_ten[0] += vos*eddy_viscosity;
  
      /* mom_vw_diff_ten[0] += vos*eddy_viscosity; */
  
      /* //w momentum diffusion tensor */
      /* mom_ww_diff_ten[0] += vos*eddy_viscosity; */
      /* mom_ww_diff_ten[1] += vos*eddy_viscosity; */
      /* mom_ww_diff_ten[2] += 2.0*vos*eddy_viscosity; */
  
      /* mom_wu_diff_ten[0] += vos*eddy_viscosity; */
  
      /* mom_wv_diff_ten[0] += vos*eddy_viscosity; */
  
#else
      eddy_viscosity = nu_t;
      //u momentum diffusion tensor
      mom_uu_diff_ten[0] += 2.0*vos*eddy_viscosity;
      mom_uu_diff_ten[1] += vos*eddy_viscosity;
      /* mom_uu_diff_ten[2] += vos*eddy_viscosity; */
  
      mom_uv_diff_ten[0]+=vos*eddy_viscosity;
  
      /* mom_uw_diff_ten[0]+=vos*eddy_viscosity; */
  
      //v momentum diffusion tensor
      mom_vv_diff_ten[0] += vos*eddy_viscosity;
      mom_vv_diff_ten[1] += 2.0*vos*eddy_viscosity;
      /* mom_vv_diff_ten[2] += vos*eddy_viscosity; */
  
      mom_vu_diff_ten[0]+=vos*eddy_viscosity;
  
      /* mom_vw_diff_ten[0]+=vos*eddy_viscosity; */
  
      /* //w momentum diffusion tensor */
      /* mom_ww_diff_ten[0] += vos*eddy_viscosity; */
      /* mom_ww_diff_ten[1] += vos*eddy_viscosity; */
      /* mom_ww_diff_ten[2] += 2.0*vos*eddy_viscosity; */
  
      /* mom_wu_diff_ten[0]+=vos*eddy_viscosity; */
  
      /* mom_wv_diff_ten[0]+=vos*eddy_viscosity; */
  
#endif
    }

    inline
    void calculateSubgridError_tau(const double&  hFactor,
				   const double& elementDiameter,
				   const double& dmt,
				   const double& dm,
				   const double df[nSpace],
				   const double& a,
				   const double&  pfac,
				   double& tau_v,
				   double& tau_p,
				   double& cfl)
    {
      double h,oneByAbsdt,density,viscosity,nrm_df;
      h = hFactor*elementDiameter;
      density = dm;
      viscosity =  a;
      nrm_df=0.0;
      for(int I=0;I<nSpace;I++)
	nrm_df+=df[I]*df[I];
      nrm_df = sqrt(nrm_df);
      cfl = nrm_df/(h*density);//this is really cfl/dt, but that's what we want to know, the step controller expect this
      oneByAbsdt =  fabs(dmt);
      tau_v = 1.0/(4.0*viscosity/(h*h) + 2.0*nrm_df/h + oneByAbsdt);
      tau_p = (4.0*viscosity + 2.0*nrm_df*h + oneByAbsdt*h*h)/pfac;
      /* std::cout<<"tau_v "<<tau_v<<" tau_p "<<tau_p<<std::endl; */
    }

    inline
    void calculateSubgridError_tau(     const double&  Ct_sge,
                                        const double&  Cd_sge,
			                const double   G[nSpace*nSpace],
					const double&  G_dd_G,
					const double&  tr_G,
					const double&  A0,
					const double   Ai[nSpace],
					const double&  Kij,
					const double&  pfac,
					double& tau_v,
					double& tau_p,
					double& q_cfl)	
    {
      double v_d_Gv=0.0; 
      for(int I=0;I<nSpace;I++) 
         for (int J=0;J<nSpace;J++) 
           v_d_Gv += Ai[I]*G[I*nSpace+J]*Ai[J];
      tau_v = 1.0/sqrt(Ct_sge*A0*A0 + v_d_Gv + Cd_sge*Kij*Kij*G_dd_G + 1.0e-12); 
      tau_p = 1.0/(pfac*tr_G*tau_v);     
    }

    inline
    void calculateSubgridError_tauRes(const double& tau_p,
				      const double& tau_v,
				      const double& pdeResidualP,
				      const double& pdeResidualU,
				      const double& pdeResidualV,
				      const double& pdeResidualW,
				      double& subgridErrorP,
				      double& subgridErrorU,
				      double& subgridErrorV,
				      double& subgridErrorW)
    {
      /* GLS pressure */
      subgridErrorP = -tau_p*pdeResidualP;
      /* GLS momentum */
      subgridErrorU = -tau_v*pdeResidualU;
      subgridErrorV = -tau_v*pdeResidualV;
      /* subgridErrorW = -tau_v*pdeResidualW; */
    }

    inline
    void calculateSubgridErrorDerivatives_tauRes(const double& tau_p,
						 const double& tau_v,
						 const double dpdeResidualP_du[nDOF_trial_element],
						 const double dpdeResidualP_dv[nDOF_trial_element],
						 const double dpdeResidualP_dw[nDOF_trial_element],
						 const double dpdeResidualU_dp[nDOF_trial_element],
						 const double dpdeResidualU_du[nDOF_trial_element],
						 const double dpdeResidualV_dp[nDOF_trial_element],
						 const double dpdeResidualV_dv[nDOF_trial_element],
						 const double dpdeResidualW_dp[nDOF_trial_element],
						 const double dpdeResidualW_dw[nDOF_trial_element],
						 double dsubgridErrorP_du[nDOF_trial_element],
						 double dsubgridErrorP_dv[nDOF_trial_element],
						 double dsubgridErrorP_dw[nDOF_trial_element],
						 double dsubgridErrorU_dp[nDOF_trial_element],
						 double dsubgridErrorU_du[nDOF_trial_element],
						 double dsubgridErrorV_dp[nDOF_trial_element],
						 double dsubgridErrorV_dv[nDOF_trial_element],
						 double dsubgridErrorW_dp[nDOF_trial_element],
						 double dsubgridErrorW_dw[nDOF_trial_element])
    {
      for (int j=0;j<nDOF_trial_element;j++)
	{
	  /* GLS pressure */
	  dsubgridErrorP_du[j] = -tau_p*dpdeResidualP_du[j];
	  dsubgridErrorP_dv[j] = -tau_p*dpdeResidualP_dv[j];
	  /* dsubgridErrorP_dw[j] = -tau_p*dpdeResidualP_dw[j]; */
	  /* GLS  momentum*/
	  /* u */
	  dsubgridErrorU_dp[j] = -tau_v*dpdeResidualU_dp[j];
	  dsubgridErrorU_du[j] = -tau_v*dpdeResidualU_du[j];
	  /* v */
	  dsubgridErrorV_dp[j] = -tau_v*dpdeResidualV_dp[j];
	  dsubgridErrorV_dv[j] = -tau_v*dpdeResidualV_dv[j];
	  /* /\* w *\/ */
	  /* dsubgridErrorW_dp[j] = -tau_v*dpdeResidualW_dp[j]; */
	  /* dsubgridErrorW_dw[j] = -tau_v*dpdeResidualW_dw[j]; */
	}
    }

    inline
    void exteriorNumericalAdvectiveFlux(const int& isDOFBoundary_p,
					const int& isDOFBoundary_u,
					const int& isDOFBoundary_v,
					const int& isDOFBoundary_w,
					const int& isFluxBoundary_p,
					const int& isFluxBoundary_u,
					const int& isFluxBoundary_v,
					const int& isFluxBoundary_w,
					const double& oneByRho,
					const double& bc_oneByRho,
					const double n[nSpace],
					const double& bc_p,
					const double bc_f_mass[nSpace],
					const double bc_f_umom[nSpace],
					const double bc_f_vmom[nSpace],
					const double bc_f_wmom[nSpace],
					const double& bc_flux_mass,
					const double& bc_flux_umom,
					const double& bc_flux_vmom,
					const double& bc_flux_wmom,
					const double& p,
					const double f_mass[nSpace],
					const double f_umom[nSpace],
					const double f_vmom[nSpace],
					const double f_wmom[nSpace],
					const double df_mass_du[nSpace],
					const double df_mass_dv[nSpace],
					const double df_mass_dw[nSpace],
					const double df_umom_dp[nSpace],
					const double df_umom_du[nSpace],
					const double df_umom_dv[nSpace],
					const double df_umom_dw[nSpace],
					const double df_vmom_dp[nSpace],
					const double df_vmom_du[nSpace],
					const double df_vmom_dv[nSpace],
					const double df_vmom_dw[nSpace],
					const double df_wmom_dp[nSpace],
					const double df_wmom_du[nSpace],
					const double df_wmom_dv[nSpace],
					const double df_wmom_dw[nSpace],
					double& flux_mass,
					double& flux_umom,
					double& flux_vmom,
					double& flux_wmom,
					double* velocity)
    {
      double flowDirection;
      flux_mass = 0.0;
      flux_umom = 0.0;
      flux_vmom = 0.0;
      /* flux_wmom = 0.0; */
      flowDirection=n[0]*df_vmom_dv[0]+n[1]*df_umom_du[1];//tricky, works for  moving and fixed domains
      if (isDOFBoundary_u != 1)
	{
	  flux_mass += n[0]*f_mass[0];
	  velocity[0] = f_mass[0];
	  if (flowDirection >= 0.0)
	    {
	      flux_umom += n[0]*f_umom[0];
	      flux_vmom += n[0]*f_vmom[0];
	      /* flux_wmom += n[0]*f_wmom[0]; */
	    }
	}
      else
	{
	  flux_mass += n[0]*f_mass[0];
	  velocity[0] = f_mass[0];
	  if (flowDirection >= 0.0)
	    {
	      flux_umom += n[0]*f_umom[0];
	      flux_vmom += n[0]*f_vmom[0];
	      /* flux_wmom += n[0]*f_wmom[0]; */
	    }
	  else
	    {
	      flux_umom+=n[0]*bc_f_umom[0];
	      flux_vmom+=n[0]*bc_f_vmom[0];
	      /* flux_wmom+=n[0]*bc_f_wmom[0]; */
	    }
	}
      if (isDOFBoundary_v != 1)
	{
	  flux_mass+=n[1]*f_mass[1];
	  velocity[1] = f_mass[1];
	  if (flowDirection >= 0.0)
	    {
	      flux_umom+=n[1]*f_umom[1];
	      flux_vmom+=n[1]*f_vmom[1];
	      /* flux_wmom+=n[1]*f_wmom[1]; */
	    }
	}
      else
	{
	  flux_mass+=n[1]*f_mass[1];
	  velocity[1] = f_mass[1];
	  if (flowDirection >= 0.0)
	    {
	      flux_umom+=n[1]*f_umom[1];
	      flux_vmom+=n[1]*f_vmom[1];
	      /* flux_wmom+=n[1]*f_wmom[1]; */
	    }
	  else
	    {
	      flux_umom+=n[1]*bc_f_umom[1];
	      flux_vmom+=n[1]*bc_f_vmom[1];
	      /* flux_wmom+=n[1]*bc_f_wmom[1]; */
	    }
	}
      /* if (isDOFBoundary_w != 1) */
      /* 	{ */
      /* 	  flux_mass+=n[2]*f_mass[2]; */
      /* 	  velocity[2] = f_mass[2]; */
      /* 	  if (flowDirection >= 0.0) */
      /* 	    { */
      /* 	      flux_umom+=n[2]*f_umom[2]; */
      /* 	      flux_vmom+=n[2]*f_vmom[2]; */
      /* 	      flux_wmom+=n[2]*f_wmom[2]; */
      /* 	    } */
      /* 	} */
      /* else */
      /* 	{ */
      /* 	  flux_mass +=n[2]*f_mass[2]; */
      /* 	  velocity[2] = f_mass[2]; */
      /* 	  if (flowDirection >= 0.0) */
      /* 	    { */
      /* 	      flux_umom+=n[2]*f_umom[2]; */
      /* 	      flux_vmom+=n[2]*f_vmom[2]; */
      /* 	      flux_wmom+=n[2]*f_wmom[2]; */
      /* 	    } */
      /* 	  else */
      /* 	    { */
      /* 	      flux_umom+=n[2]*bc_f_umom[2]; */
      /* 	      flux_vmom+=n[2]*bc_f_vmom[2]; */
      /* 	      flux_wmom+=n[2]*bc_f_wmom[2]; */
      /* 	    } */
      /* 	} */
      if (isDOFBoundary_p == 1)
	{
	  flux_umom+= n[0]*(bc_p*bc_oneByRho-p*oneByRho);
	  flux_vmom+= n[1]*(bc_p*bc_oneByRho-p*oneByRho);
	  /* flux_wmom+= n[2]*(bc_p*bc_oneByRho-p*oneByRho); */
	}
      if (isFluxBoundary_p == 1)
	{
	  velocity[0] += (bc_flux_mass - flux_mass)*n[0];
	  velocity[1] += (bc_flux_mass - flux_mass)*n[1];
	  /* velocity[2] += (bc_flux_mass - flux_mass)*n[2]; */
	  flux_mass = bc_flux_mass;
	}
      if (isFluxBoundary_u == 1)
	{
	  flux_umom = bc_flux_umom;
	}
      if (isFluxBoundary_v == 1)
	{
	  flux_vmom = bc_flux_vmom;
	}
      /* if (isFluxBoundary_w == 1) */
      /* 	{ */
      /* 	  flux_wmom = bc_flux_wmom; */
      /* 	} */
      /* if (fabs(flux_mass) > 1.0e-4) */
      /* 	std::cout<<"flux_mass "<<flux_mass<<std::endl */
      /* 		 <<"n_0       "<<n[0]<<std::endl */
      /* 		 <<"n_1       "<<n[1]<<std::endl */
      /* 		 <<"norm(n)   "<<sqrt(n[0]*n[0]+n[1]*n[1])<<std::endl */
      /* 		 <<"v_0       "<<velocity[0]<<std::endl */
      /* 		 <<"v_1       "<<velocity[1]<<std::endl */
      /* 		 <<std::endl; */
    }

    inline
    void exteriorNumericalAdvectiveFluxDerivatives(const int& isDOFBoundary_p,
						   const int& isDOFBoundary_u,
						   const int& isDOFBoundary_v,
						   const int& isDOFBoundary_w,
						   const int& isFluxBoundary_p,
						   const int& isFluxBoundary_u,
						   const int& isFluxBoundary_v,
						   const int& isFluxBoundary_w,
						   const double& oneByRho,
						   const double n[nSpace],
						   const double& bc_p,
						   const double bc_f_mass[nSpace],
						   const double bc_f_umom[nSpace],
						   const double bc_f_vmom[nSpace],
						   const double bc_f_wmom[nSpace],
						   const double& bc_flux_mass,
						   const double& bc_flux_umom,
						   const double& bc_flux_vmom,
						   const double& bc_flux_wmom,
						   const double& p,
						   const double f_mass[nSpace],
						   const double f_umom[nSpace],
						   const double f_vmom[nSpace],
						   const double f_wmom[nSpace],
						   const double df_mass_du[nSpace],
						   const double df_mass_dv[nSpace],
						   const double df_mass_dw[nSpace],
						   const double df_umom_dp[nSpace],
						   const double df_umom_du[nSpace],
						   const double df_umom_dv[nSpace],
						   const double df_umom_dw[nSpace],
						   const double df_vmom_dp[nSpace],
						   const double df_vmom_du[nSpace],
						   const double df_vmom_dv[nSpace],
						   const double df_vmom_dw[nSpace],
						   const double df_wmom_dp[nSpace],
						   const double df_wmom_du[nSpace],
						   const double df_wmom_dv[nSpace],
						   const double df_wmom_dw[nSpace],
						   double& dflux_mass_du,
						   double& dflux_mass_dv,
						   double& dflux_mass_dw,
						   double& dflux_umom_dp,
						   double& dflux_umom_du,
						   double& dflux_umom_dv,
						   double& dflux_umom_dw,
						   double& dflux_vmom_dp,
						   double& dflux_vmom_du,
						   double& dflux_vmom_dv,
						   double& dflux_vmom_dw,
						   double& dflux_wmom_dp,
						   double& dflux_wmom_du,
						   double& dflux_wmom_dv,
						   double& dflux_wmom_dw)
    {
      double flowDirection;
      dflux_mass_du = 0.0;
      dflux_mass_dv = 0.0;
      /* dflux_mass_dw = 0.0; */
  
      dflux_umom_dp = 0.0;
      dflux_umom_du = 0.0;
      dflux_umom_dv = 0.0;
      /* dflux_umom_dw = 0.0; */
  
      dflux_vmom_dp = 0.0;
      dflux_vmom_du = 0.0;
      dflux_vmom_dv = 0.0;
      /* dflux_vmom_dw = 0.0; */
  
      dflux_wmom_dp = 0.0;
      dflux_wmom_du = 0.0;
      dflux_wmom_dv = 0.0;
      /* dflux_wmom_dw = 0.0; */
      flowDirection=n[0]*df_vmom_dv[0]+n[1]*df_umom_du[1];//tricky, works for moving and fixed  domains
      if (isDOFBoundary_u != 1)
	{
	  dflux_mass_du += n[0]*df_mass_du[0];
	  if (flowDirection >= 0.0)
	    {
	      dflux_umom_du += n[0]*df_umom_du[0];
	      dflux_vmom_du += n[0]*df_vmom_du[0];
	      dflux_vmom_dv += n[0]*df_vmom_dv[0];
	      /* dflux_wmom_du += n[0]*df_wmom_du[0]; */
	      /* dflux_wmom_dw += n[0]*df_wmom_dw[0]; */
	    }
	}
      else
	{
	  //cek still upwind the advection for Dirichlet?
	  dflux_mass_du += n[0]*df_mass_du[0];
	  if (flowDirection >= 0.0)
	    {
	      dflux_umom_du += n[0]*df_umom_du[0];
	      dflux_vmom_du += n[0]*df_vmom_du[0];
	      dflux_vmom_dv += n[0]*df_vmom_dv[0];
	      /* dflux_wmom_du += n[0]*df_wmom_du[0]; */
	      /* dflux_wmom_dw += n[0]*df_wmom_dw[0]; */
	    }
	  else
	    {
	      if (isDOFBoundary_v != 1)
		dflux_vmom_dv += n[0]*df_vmom_dv[0];
	      /* if (isDOFBoundary_w != 1) */
	      /* 	dflux_wmom_dw += n[0]*df_wmom_dw[0]; */
	    }
	}
      if (isDOFBoundary_v != 1)
	{
	  dflux_mass_dv += n[1]*df_mass_dv[1];
	  if (flowDirection >= 0.0)
	    {
	      dflux_umom_du += n[1]*df_umom_du[1];
	      dflux_umom_dv += n[1]*df_umom_dv[1];
	      dflux_vmom_dv += n[1]*df_vmom_dv[1];
	      /* dflux_wmom_dw += n[1]*df_wmom_dw[1]; */
	      /* dflux_wmom_dv += n[1]*df_wmom_dv[1]; */
	    }
	}
      else
	{
	  //cek still upwind the advection for Dirichlet?
	  dflux_mass_dv += n[1]*df_mass_dv[1];
	  if (flowDirection >= 0.0)
	    {
	      dflux_umom_du += n[1]*df_umom_du[1];
	      dflux_umom_dv += n[1]*df_umom_dv[1];
	      dflux_vmom_dv += n[1]*df_vmom_dv[1];
	      /* dflux_wmom_dw += n[1]*df_wmom_dw[1]; */
	      /* dflux_wmom_dv += n[1]*df_wmom_dv[1]; */
	    }
	  else
	    {
	      if (isDOFBoundary_u != 1)
		dflux_umom_du += n[1]*df_umom_du[1];
	      /* if (isDOFBoundary_w != 1) */
	      /* 	dflux_wmom_dw += n[1]*df_wmom_dw[1]; */
	    }
	}
      /* if (isDOFBoundary_w != 1) */
      /* 	{ */
      /* 	  dflux_mass_dw+=n[2]*df_mass_dw[2]; */
      /* 	  if (flowDirection >= 0.0) */
      /* 	    { */
      /* 	      dflux_umom_du += n[2]*df_umom_du[2]; */
      /* 	      dflux_umom_dw += n[2]*df_umom_dw[2]; */
      /* 	      dflux_vmom_dv += n[2]*df_vmom_dv[2]; */
      /* 	      dflux_vmom_dw += n[2]*df_vmom_dw[2]; */
      /* 	      dflux_wmom_dw += n[2]*df_wmom_dw[2]; */
      /* 	    } */
      /* 	} */
      /* else */
      /* 	{ */
      /* 	  //cek still upwind the advection for Dirichlet? */
      /* 	  dflux_mass_dw += n[2]*df_mass_dw[2]; */
      /* 	  if (flowDirection >= 0.0) */
      /* 	    { */
      /* 	      dflux_umom_du += n[2]*df_umom_du[2]; */
      /* 	      dflux_umom_dw += n[2]*df_umom_dw[2]; */
      /* 	      dflux_vmom_dv += n[2]*df_vmom_dv[2]; */
      /* 	      dflux_vmom_dw += n[2]*df_vmom_dw[2]; */
      /* 	      dflux_wmom_dw += n[2]*df_wmom_dw[2]; */
      /* 	    } */
      /* 	  else */
      /* 	    { */
      /* 	      if (isDOFBoundary_u != 1) */
      /* 		dflux_umom_du += n[2]*df_umom_du[2]; */
      /* 	      if (isDOFBoundary_v != 1) */
      /* 		dflux_vmom_dv += n[2]*df_vmom_dv[2]; */
      /* 	    } */
	/* } */
      if (isDOFBoundary_p == 1)
	{
	  dflux_umom_dp= -n[0]*oneByRho;
	  dflux_vmom_dp= -n[1]*oneByRho;
	  /* dflux_wmom_dp= -n[2]*oneByRho; */
	}
      if (isFluxBoundary_p == 1)
	{
	  dflux_mass_du = 0.0;
	  dflux_mass_dv = 0.0;
	  /* dflux_mass_dw = 0.0; */
	}
      if (isFluxBoundary_u == 1)
	{
	  dflux_umom_dp = 0.0;
	  dflux_umom_du = 0.0;
	  dflux_umom_dv = 0.0;
	  /* dflux_umom_dw = 0.0; */
	}
      if (isFluxBoundary_v == 1)
	{
	  dflux_vmom_dp = 0.0;
	  dflux_vmom_du = 0.0;
	  dflux_vmom_dv = 0.0;
	  /* dflux_vmom_dw = 0.0; */
	}
      /* if (isFluxBoundary_w == 1) */
      /* 	{ */
      /* 	  dflux_wmom_dp = 0.0; */
      /* 	  dflux_wmom_du = 0.0; */
      /* 	  dflux_wmom_dv = 0.0; */
      /* 	  dflux_wmom_dw = 0.0; */
      /* 	} */
    }

    inline
    void exteriorNumericalDiffusiveFlux(const double& eps,
					const double& phi,
					int* rowptr,
					int* colind,
					const int& isDOFBoundary,
					const int& isFluxBoundary,
					const double n[nSpace],
					double* bc_a,
					const double& bc_u,
					const double& bc_flux,
					double* a,
					const double grad_potential[nSpace],
					const double& u,
					const double& penalty,
					double& flux)
    {
      double diffusiveVelocityComponent_I,penaltyFlux,max_a;
      if(isFluxBoundary == 1)
	{
	  flux = bc_flux;
	}
      else if(isDOFBoundary == 1)
	{
	  flux = 0.0;
	  max_a=0.0;
	  for(int I=0;I<nSpace;I++)
	    {
	      diffusiveVelocityComponent_I=0.0;
	      for(int m=rowptr[I];m<rowptr[I+1];m++)
		{
		  diffusiveVelocityComponent_I -= a[m]*grad_potential[colind[m]];
		  max_a = fmax(max_a,a[m]);
		}
	      flux+= diffusiveVelocityComponent_I*n[I];
	    }
	  penaltyFlux = max_a*penalty*(u-bc_u);
	  flux += penaltyFlux;
	  //contact line slip
	  //flux*=(smoothedDirac(eps,0) - smoothedDirac(eps,phi))/smoothedDirac(eps,0);
	}
      else
	{
	  std::cerr<<"warning, diffusion term with no boundary condition set, setting diffusive flux to 0.0"<<std::endl;
	  flux = 0.0;
	}
    }


    inline
    double ExteriorNumericalDiffusiveFluxJacobian(const double& eps,
						  const double& phi,
						  int* rowptr,
						  int* colind,
						  const int& isDOFBoundary,
						  const int& isFluxBoundary,
						  const double n[nSpace],
						  double* a,
						  const double& v,
						  const double grad_v[nSpace],
						  const double& penalty)
    {
      double dvel_I,tmp=0.0,max_a=0.0;
      if(isFluxBoundary==0 && isDOFBoundary==1)
	{
	  for(int I=0;I<nSpace;I++)
	    {
	      dvel_I=0.0;
	      for(int m=rowptr[I];m<rowptr[I+1];m++)
		{
		  dvel_I -= a[m]*grad_v[colind[m]];
		  max_a = fmax(max_a,a[m]);
		}
	      tmp += dvel_I*n[I];
	    }
	  tmp +=max_a*penalty*v;
	  //contact line slip
	  //tmp*=(smoothedDirac(eps,0) - smoothedDirac(eps,phi))/smoothedDirac(eps,0);
	}
      return tmp;
    }

    void calculateResidual(//element
			   double* mesh_trial_ref,
			   double* mesh_grad_trial_ref,
			   double* mesh_dof,
			   double* mesh_velocity_dof,
			   double MOVING_DOMAIN,
			   int* mesh_l2g,
			   double* dV_ref,
			   double* p_trial_ref,
			   double* p_grad_trial_ref,
			   double* p_test_ref,
			   double* p_grad_test_ref,
			   double* vel_trial_ref,
			   double* vel_grad_trial_ref,
			   double* vel_test_ref,
			   double* vel_grad_test_ref,
			   //element boundary
			   double* mesh_trial_trace_ref,
			   double* mesh_grad_trial_trace_ref,
			   double* dS_ref,
			   double* p_trial_trace_ref,
			   double* p_grad_trial_trace_ref,
			   double* p_test_trace_ref,
			   double* p_grad_test_trace_ref,
			   double* vel_trial_trace_ref,
			   double* vel_grad_trial_trace_ref,
			   double* vel_test_trace_ref,
			   double* vel_grad_test_trace_ref,					 
			   double* normal_ref,
			   double* boundaryJac_ref,
			   //physics
			   double eb_adjoint_sigma,
			   double* elementDiameter,
			   double* nodeDiametersArray,
			   double hFactor,
			   int nElements_global,
			   int nElementBoundaries_owned,
			   double useRBLES,
			   double useMetrics, 
			   double alphaBDF,
			   double epsFact_rho,
			   double epsFact_mu, 
			   double sigma,
			   double rho_0,
			   double nu_0,
			   double rho_1,
			   double nu_1,
			   double smagorinskyConstant,
			   int turbulenceClosureModel,
			   double Ct_sge,
			   double Cd_sge,
			   double C_dc,
			   double C_b,
			   //VRANS
			   const double* eps_solid,
			   const double* q_velocity_fluid,
			   const double* q_p_fluid,
			   const double* q_grad_p_fluid,
			   const double* q_vos,
			   const double* q_dvos_dt,
			   const double* q_dragAlpha,
			   const double* q_dragBeta,
			   const double* q_mass_source,
                           const double* q_turb_var_0,
			   const double* q_turb_var_1,
			   const double* q_turb_var_grad_0,
			   double * q_eddy_viscosity,
			   //
			   int* p_l2g, 
			   int* vel_l2g, 
			   double* p_dof, 
			   double* u_dof, 
			   double* v_dof, 
			   double* w_dof,
			   double* g,
			   const double useVF,
			   double* vf,
			   double* phi,
			   double* normal_phi,
			   double* kappa_phi,
			   double* q_mom_u_acc,
			   double* q_mom_v_acc,
			   double* q_mom_w_acc,
			   double* q_mass_adv,
			   double* q_mom_u_acc_beta_bdf, double* q_mom_v_acc_beta_bdf, double* q_mom_w_acc_beta_bdf,
                           double* q_dV,
                           double* q_dV_last,
			   double* q_velocity_sge,
			   double* q_cfl,
			   double* q_numDiff_u, double* q_numDiff_v, double* q_numDiff_w,
			   double* q_numDiff_u_last, double* q_numDiff_v_last, double* q_numDiff_w_last,
			   int* sdInfo_u_u_rowptr,int* sdInfo_u_u_colind,			      
			   int* sdInfo_u_v_rowptr,int* sdInfo_u_v_colind,
			   int* sdInfo_u_w_rowptr,int* sdInfo_u_w_colind,
			   int* sdInfo_v_v_rowptr,int* sdInfo_v_v_colind,
			   int* sdInfo_v_u_rowptr,int* sdInfo_v_u_colind,
			   int* sdInfo_v_w_rowptr,int* sdInfo_v_w_colind,
			   int* sdInfo_w_w_rowptr,int* sdInfo_w_w_colind,
			   int* sdInfo_w_u_rowptr,int* sdInfo_w_u_colind,
			   int* sdInfo_w_v_rowptr,int* sdInfo_w_v_colind,
			   int offset_p, int offset_u, int offset_v, int offset_w, 
			   int stride_p, int stride_u, int stride_v, int stride_w, 
			   double* globalResidual,
			   int nExteriorElementBoundaries_global,
			   int* exteriorElementBoundariesArray,
			   int* elementBoundaryElementsArray,
			   int* elementBoundaryLocalElementBoundariesArray,
			   double* ebqe_vf_ext,
			   double* bc_ebqe_vf_ext,
			   double* ebqe_phi_ext,
			   double* bc_ebqe_phi_ext,
			   double* ebqe_normal_phi_ext,
			   double* ebqe_kappa_phi_ext,
			   //VRANS
			   const double* ebqe_vos_ext,
			   const double* ebqe_p_fluid_ext,
			   const double* ebqe_grad_p_fluid_ext,
			   const double* ebqe_turb_var_0,
			   const double* ebqe_turb_var_1,
			   //VRANS end
			   int* isDOFBoundary_p,
			   int* isDOFBoundary_u,
			   int* isDOFBoundary_v,
			   int* isDOFBoundary_w,
			   int* isAdvectiveFluxBoundary_p,
			   int* isAdvectiveFluxBoundary_u,
			   int* isAdvectiveFluxBoundary_v,
			   int* isAdvectiveFluxBoundary_w,
			   int* isDiffusiveFluxBoundary_u,
			   int* isDiffusiveFluxBoundary_v,
			   int* isDiffusiveFluxBoundary_w,
			   double* ebqe_bc_p_ext,
			   double* ebqe_bc_flux_mass_ext,
			   double* ebqe_bc_flux_mom_u_adv_ext,
			   double* ebqe_bc_flux_mom_v_adv_ext,
			   double* ebqe_bc_flux_mom_w_adv_ext,
			   double* ebqe_bc_u_ext,
			   double* ebqe_bc_flux_u_diff_ext,
			   double* ebqe_penalty_ext,
			   double* ebqe_bc_v_ext,
			   double* ebqe_bc_flux_v_diff_ext,
			   double* ebqe_bc_w_ext,
			   double* ebqe_bc_flux_w_diff_ext,
			   double* q_x,
			   double* q_velocity,
			   double* ebqe_velocity,
			   double* flux,
			   double* elementResidual_p_save,
			   int* elementFlags,
			   int* boundaryFlags,
			   double* barycenters,
			   double* wettedAreas,
			   double* netForces_p,
			   double* netForces_v,
			   double* netMoments)
    {
      //
      //loop over elements to compute volume integrals and load them into element and global residual
      //
      double mesh_volume_conservation=0.0,
        mesh_volume_conservation_weak=0.0,
        mesh_volume_conservation_err_max=0.0,
        mesh_volume_conservation_err_max_weak=0.0;
      double globalConservationError=0.0;
      for(int eN=0;eN<nElements_global;eN++)
	{
	  //declare local storage for element residual and initialize
	  register double elementResidual_p[nDOF_test_element],elementResidual_mesh[nDOF_test_element],
	    elementResidual_u[nDOF_test_element],
	    elementResidual_v[nDOF_test_element],
	    //elementResidual_w[nDOF_test_element],
	    eps_rho,eps_mu;
	  const double* elementResidual_w(NULL);
          double mesh_volume_conservation_element=0.0,
            mesh_volume_conservation_element_weak=0.0;
	  for (int i=0;i<nDOF_test_element;i++)
	    {
	      int eN_i = eN*nDOF_test_element+i;
	      elementResidual_p_save[eN_i]=0.0;
	      elementResidual_mesh[i]=0.0;
	      elementResidual_p[i]=0.0;
	      elementResidual_u[i]=0.0;
	      elementResidual_v[i]=0.0;
	      /* elementResidual_w[i]=0.0; */
	    }//i
	  //
	  //loop over quadrature points and compute integrands
	  //
	  for(int k=0;k<nQuadraturePoints_element;k++)
	    {
	      //compute indices and declare local storage
	      register int eN_k = eN*nQuadraturePoints_element+k,
		eN_k_nSpace = eN_k*nSpace,
		eN_k_3d     = eN_k*3,
		eN_nDOF_trial_element = eN*nDOF_trial_element;
	      register double vosStar=0.0,u=0.0,v=0.0,w=0.0,
		grad_vosStar[nSpace],grad_u[nSpace],grad_v[nSpace],grad_w[nSpace],
		mom_u_acc=0.0,
		dmom_u_acc_u=0.0,
		mom_v_acc=0.0,
		dmom_v_acc_v=0.0,
		mom_w_acc=0.0,
		dmom_w_acc_w=0.0,
		mass_adv[nSpace],
		dmass_adv_u[nSpace],
		dmass_adv_v[nSpace],
		dmass_adv_w[nSpace],
		mom_u_adv[nSpace],
		dmom_u_adv_u[nSpace],
		dmom_u_adv_v[nSpace],
		dmom_u_adv_w[nSpace],
		mom_v_adv[nSpace],
		dmom_v_adv_u[nSpace],
		dmom_v_adv_v[nSpace],
		dmom_v_adv_w[nSpace],
		mom_w_adv[nSpace],
		dmom_w_adv_u[nSpace],
		dmom_w_adv_v[nSpace],
		dmom_w_adv_w[nSpace],
		mom_uu_diff_ten[nSpace],
		mom_vv_diff_ten[nSpace],
		mom_ww_diff_ten[nSpace],
		mom_uv_diff_ten[1],
		mom_uw_diff_ten[1],
		mom_vu_diff_ten[1],
		mom_vw_diff_ten[1],
		mom_wu_diff_ten[1],
		mom_wv_diff_ten[1],
		mom_u_source=0.0,
		mom_v_source=0.0,
		mom_w_source=0.0,
		mom_u_ham=0.0,
		dmom_u_ham_grad_p[nSpace],
		mom_v_ham=0.0,
		dmom_v_ham_grad_p[nSpace],
		mom_w_ham=0.0,
		dmom_w_ham_grad_p[nSpace],
		mom_u_acc_t=0.0,
		dmom_u_acc_u_t=0.0,
		mom_v_acc_t=0.0,
		dmom_v_acc_v_t=0.0,
		mom_w_acc_t=0.0,
		dmom_w_acc_w_t=0.0,
		pdeResidual_p=0.0,
		pdeResidual_u=0.0,
		pdeResidual_v=0.0,
		pdeResidual_w=0.0,
		Lstar_u_p[nDOF_test_element],
		Lstar_v_p[nDOF_test_element],
		Lstar_w_p[nDOF_test_element],
		Lstar_u_u[nDOF_test_element],
		Lstar_v_v[nDOF_test_element],
		Lstar_w_w[nDOF_test_element],
		Lstar_p_u[nDOF_test_element],
		Lstar_p_v[nDOF_test_element],
		Lstar_p_w[nDOF_test_element],
		subgridError_p=0.0,
		subgridError_u=0.0,
		subgridError_v=0.0,
		subgridError_w=0.0,
		tau_p=0.0,tau_p0=0.0,tau_p1=0.0,
		tau_v=0.0,tau_v0=0.0,tau_v1=0.0,
		jac[nSpace*nSpace],
		jacDet,
		jacInv[nSpace*nSpace],
		p_grad_trial[nDOF_trial_element*nSpace],vel_grad_trial[nDOF_trial_element*nSpace],
		p_test_dV[nDOF_trial_element],vel_test_dV[nDOF_trial_element],
		p_grad_test_dV[nDOF_test_element*nSpace],vel_grad_test_dV[nDOF_test_element*nSpace],
		dV,x,y,z,xt,yt,zt,
		//
		vos,
		//meanGrainSize,
		mass_source,
		dmom_u_source[nSpace],
		dmom_v_source[nSpace],
		dmom_w_source[nSpace],
		//
		G[nSpace*nSpace],G_dd_G,tr_G,norm_Rv,h_phi, dmom_adv_star[nSpace],dmom_adv_sge[nSpace];
	      //get jacobian, etc for mapping reference element
	      ck.calculateMapping_element(eN,
					  k,
					  mesh_dof,
					  mesh_l2g,
					  mesh_trial_ref,
					  mesh_grad_trial_ref,
					  jac,
					  jacDet,
					  jacInv,
					  x,y,z);
	      ck.calculateH_element(eN,
				    k,
				    nodeDiametersArray,
				    mesh_l2g,
				    mesh_trial_ref,
				    h_phi);
	      
	      ck.calculateMappingVelocity_element(eN,
						  k,
						  mesh_velocity_dof,
						  mesh_l2g,
						  mesh_trial_ref,
						  xt,yt,zt);
	      //xt=0.0;yt=0.0;zt=0.0;
	      //std::cout<<"xt "<<xt<<'\t'<<yt<<'\t'<<zt<<std::endl;
	      //get the physical integration weight
	      dV = fabs(jacDet)*dV_ref[k];
	      ck.calculateG(jacInv,G,G_dd_G,tr_G);
	      //ck.calculateGScale(G,&normal_phi[eN_k_nSpace],h_phi);
	      
	      eps_rho = epsFact_rho*(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      eps_mu  = epsFact_mu *(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	     
	      //get the trial function gradients
	      ck.gradTrialFromRef(&p_grad_trial_ref[k*nDOF_trial_element*nSpace],jacInv,p_grad_trial);
	      ck.gradTrialFromRef(&vel_grad_trial_ref[k*nDOF_trial_element*nSpace],jacInv,vel_grad_trial);
	      //get the solution
	      ck.valFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],&p_trial_ref[k*nDOF_trial_element],vosStar);
	      ck.valFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],u);
	      ck.valFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],v);
	      /* ck.valFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],w); */
	      //get the solution gradients
	      ck.gradFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],p_grad_trial,grad_vosStar);
	      ck.gradFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_u);
	      ck.gradFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_v);
	      /* ck.gradFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_w); */
	      //precalculate test function products with integration weights
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  p_test_dV[j] = p_test_ref[k*nDOF_trial_element+j]*dV;
		  vel_test_dV[j] = vel_test_ref[k*nDOF_trial_element+j]*dV;
		  for (int I=0;I<nSpace;I++)
		    {
		      p_grad_test_dV[j*nSpace+I]   = p_grad_trial[j*nSpace+I]*dV;//cek warning won't work for Petrov-Galerkin
		      vel_grad_test_dV[j*nSpace+I] = vel_grad_trial[j*nSpace+I]*dV;//cek warning won't work for Petrov-Galerkin
		    }
		}
              //cek hack
              double div_mesh_velocity=0.0;
              int NDOF_MESH_TRIAL_ELEMENT=3;
              for (int j=0;j<NDOF_MESH_TRIAL_ELEMENT;j++)
                {
                  int eN_j=eN*NDOF_MESH_TRIAL_ELEMENT+j;
                  div_mesh_velocity +=
                    mesh_velocity_dof[mesh_l2g[eN_j]*3+0]*vel_grad_trial[j*nSpace+0] +
                    mesh_velocity_dof[mesh_l2g[eN_j]*3+1]*vel_grad_trial[j*nSpace+1];
                }
              mesh_volume_conservation_element += (alphaBDF*(dV-q_dV_last[eN_k])/dV - div_mesh_velocity)*dV;
              div_mesh_velocity = DM3*div_mesh_velocity + (1.0-DM3)*alphaBDF*(dV-q_dV_last[eN_k])/dV;
	      //VRANS
	      vos      = q_vos[eN_k];
	      //meanGrainSize = q_meanGrain[eN_k]; 
	      //
	      //save velocity at quadrature points for other models to use
	      q_velocity[eN_k_nSpace+0]=u;
	      q_velocity[eN_k_nSpace+1]=v;
	      /* q_velocity[eN_k_nSpace+2]=w; */
	      q_x[eN_k_3d+0]=x;
	      q_x[eN_k_3d+1]=y;
	      /* q_x[eN_k_3d+2]=z; */
	      /* // */
	      //calculate pde coefficients at quadrature points
	      //
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   vf[eN_k],
				   phi[eN_k],
				   &normal_phi[eN_k_nSpace],
				   kappa_phi[eN_k],
				   //VRANS
				   q_vos[eN_k],
				   //
				   q_p_fluid[eN_k],
				   &q_grad_p_fluid[eN_k_nSpace],
                                   vosStar,
                                   grad_vosStar,
				   grad_u,
				   grad_v,
				   grad_w,
				   u,
				   v,
				   w,
				   q_eddy_viscosity[eN_k],
				   mom_u_acc,
				   dmom_u_acc_u,
				   mom_v_acc,
				   dmom_v_acc_v,
				   mom_w_acc,
				   dmom_w_acc_w,
				   mass_adv,
				   dmass_adv_u,
				   dmass_adv_v,
				   dmass_adv_w,
				   mom_u_adv,
				   dmom_u_adv_u,
				   dmom_u_adv_v,
				   dmom_u_adv_w,
				   mom_v_adv,
				   dmom_v_adv_u,
				   dmom_v_adv_v,
				   dmom_v_adv_w,
				   mom_w_adv,
				   dmom_w_adv_u,
				   dmom_w_adv_v,
				   dmom_w_adv_w,
				   mom_uu_diff_ten,
				   mom_vv_diff_ten,
				   mom_ww_diff_ten,
				   mom_uv_diff_ten,
				   mom_uw_diff_ten,
				   mom_vu_diff_ten,
				   mom_vw_diff_ten,
				   mom_wu_diff_ten,
				   mom_wv_diff_ten,
				   mom_u_source,
				   mom_v_source,
				   mom_w_source,
				   mom_u_ham,
				   dmom_u_ham_grad_p,
				   mom_v_ham,
				   dmom_v_ham_grad_p,
				   mom_w_ham,
				   dmom_w_ham_grad_p);          
	      //VRANS
	      mass_source = q_mass_source[eN_k];
	      //todo: decide if these should be lagged or not?
	      updateDarcyForchheimerTerms_Ergun(/* linearDragFactor, */
						/* nonlinearDragFactor, */
						/* vos, */
						/* meanGrainSize, */
						q_dragAlpha[eN_k],
						q_dragBeta[eN_k],
						eps_rho,
						eps_mu,
						rho_0,
						nu_0,
						rho_1,
						nu_1,
						useVF,
						vf[eN_k],
						phi[eN_k],
						u,//q_velocity_sge[eN_k_nSpace+0],//u
						v,//q_velocity_sge[eN_k_nSpace+1],//v
						w,//q_velocity_sge[eN_k_nSpace+2],//w
						eps_solid[elementFlags[eN]],
						q_vos[eN_k],
						q_velocity_fluid[eN_k_nSpace+0],
						q_velocity_fluid[eN_k_nSpace+1],
						q_velocity_fluid[eN_k_nSpace+2],
						mom_u_source,
						mom_v_source,
						mom_w_source,
						dmom_u_source,
						dmom_v_source,
						dmom_w_source);

	      //Turbulence closure model
	      if (turbulenceClosureModel >= 3)
		{
		  const double c_mu = 0.09;//mwf hack 
		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  vf[eN_k],
					  phi[eN_k],
					  vos,
					  c_mu, //mwf hack
					  q_turb_var_0[eN_k],
					  q_turb_var_1[eN_k],
					  &q_turb_var_grad_0[eN_k_nSpace],
					  q_eddy_viscosity[eN_k],
					  mom_uu_diff_ten,
					  mom_vv_diff_ten,
					  mom_ww_diff_ten,
					  mom_uv_diff_ten,
					  mom_uw_diff_ten,
					  mom_vu_diff_ten,
					  mom_vw_diff_ten,
					  mom_wu_diff_ten,
					  mom_wv_diff_ten,
					  mom_u_source,
					  mom_v_source,
					  mom_w_source);					  

		}
	      //
	      //save momentum for time history and velocity for subgrid error
	      //
	      q_mom_u_acc[eN_k] = mom_u_acc;                            
	      q_mom_v_acc[eN_k] = mom_v_acc;                            
	      /* q_mom_w_acc[eN_k] = mom_w_acc; */
	      //subgrid error uses grid scale velocity
	      q_mass_adv[eN_k_nSpace+0] = u;
	      q_mass_adv[eN_k_nSpace+1] = v;
	      /* q_mass_adv[eN_k_nSpace+2] = w; */
	      //
	      //moving mesh
	      //
	      mom_u_adv[0] -= MOVING_DOMAIN*mom_u_acc*xt;
	      mom_u_adv[1] -= MOVING_DOMAIN*mom_u_acc*yt;
	      /* mom_u_adv[2] -= MOVING_DOMAIN*mom_u_acc*zt; */
	      dmom_u_adv_u[0] -= MOVING_DOMAIN*dmom_u_acc_u*xt;
	      dmom_u_adv_u[1] -= MOVING_DOMAIN*dmom_u_acc_u*yt;
	      /* dmom_u_adv_u[2] -= MOVING_DOMAIN*dmom_u_acc_u*zt; */

	      mom_v_adv[0] -= MOVING_DOMAIN*mom_v_acc*xt;
	      mom_v_adv[1] -= MOVING_DOMAIN*mom_v_acc*yt;
	      /* mom_v_adv[2] -= MOVING_DOMAIN*mom_v_acc*zt; */
	      dmom_v_adv_v[0] -= MOVING_DOMAIN*dmom_v_acc_v*xt;
	      dmom_v_adv_v[1] -= MOVING_DOMAIN*dmom_v_acc_v*yt;
	      /* dmom_v_adv_v[2] -= MOVING_DOMAIN*dmom_v_acc_v*zt; */

	      /* mom_w_adv[0] -= MOVING_DOMAIN*mom_w_acc*xt; */
	      /* mom_w_adv[1] -= MOVING_DOMAIN*mom_w_acc*yt; */
	      /* mom_w_adv[2] -= MOVING_DOMAIN*mom_w_acc*zt; */
	      /* dmom_w_adv_w[0] -= MOVING_DOMAIN*dmom_w_acc_w*xt; */
	      /* dmom_w_adv_w[1] -= MOVING_DOMAIN*dmom_w_acc_w*yt; */
	      /* dmom_w_adv_w[2] -= MOVING_DOMAIN*dmom_w_acc_w*zt; */
	      //
	      //calculate time derivative at quadrature points
	      //
              if (q_dV_last[eN_k] <= -100)
                q_dV_last[eN_k] = dV;
              q_dV[eN_k] = dV;
	      ck.bdf(alphaBDF,
		     q_mom_u_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV,
		     mom_u_acc,
		     dmom_u_acc_u,
		     mom_u_acc_t,
		     dmom_u_acc_u_t);
	      ck.bdf(alphaBDF,
		     q_mom_v_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV,
		     mom_v_acc,
		     dmom_v_acc_v,
		     mom_v_acc_t,
		     dmom_v_acc_v_t);
	      /* ck.bdf(alphaBDF, */
	      /* 	     q_mom_w_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV, */
	      /* 	     mom_w_acc, */
	      /* 	     dmom_w_acc_w, */
	      /* 	     mom_w_acc_t, */
	      /* 	     dmom_w_acc_w_t); */
	      /* // */
	      //calculate subgrid error (strong residual and adjoint)
	      //
	      //calculate strong residual
	      pdeResidual_p = ck.Mass_strong(q_dvos_dt[eN_k]) +
                ck.Advection_strong(dmass_adv_u,grad_u) +
                ck.Advection_strong(dmass_adv_v,grad_v) +
		/* ck.Advection_strong(dmass_adv_w,grad_w) + */
                DM2*MOVING_DOMAIN*ck.Reaction_strong(alphaBDF*(dV-q_dV_last[eN_k])/dV - div_mesh_velocity) +
		//VRANS
		ck.Reaction_strong(mass_source);
		//
	  
              dmom_adv_sge[0] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+0] - MOVING_DOMAIN*xt);
              dmom_adv_sge[1] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+1] - MOVING_DOMAIN*yt);
              /* dmom_adv_sge[2] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+2] - MOVING_DOMAIN*zt); */

	      pdeResidual_u = ck.Mass_strong(mom_u_acc_t) +
		ck.Advection_strong(dmom_adv_sge,grad_u) +
		ck.Hamiltonian_strong(dmom_u_ham_grad_p,grad_vosStar) +
		ck.Reaction_strong(mom_u_source) -
                ck.Reaction_strong(u*div_mesh_velocity);
	  
	      pdeResidual_v = ck.Mass_strong(mom_v_acc_t) +
		ck.Advection_strong(dmom_adv_sge,grad_v) +
		ck.Hamiltonian_strong(dmom_v_ham_grad_p,grad_vosStar) + 
		ck.Reaction_strong(mom_v_source) -
                ck.Reaction_strong(v*div_mesh_velocity);
              
	      pdeResidual_w = ck.Mass_strong(mom_w_acc_t) +
	      	ck.Advection_strong(dmom_adv_sge,grad_w) +
	      	ck.Hamiltonian_strong(dmom_w_ham_grad_p,grad_vosStar) +
	      	ck.Reaction_strong(mom_w_source) -
                ck.Reaction_strong(w*div_mesh_velocity);
	
	      //calculate tau and tau*Res
	      //cek debug
	      double tmpR=dmom_u_acc_u_t + dmom_u_source[0];
	      calculateSubgridError_tau(hFactor,
					elementDiameter[eN],
					tmpR,//dmom_u_acc_u_t,
					dmom_u_acc_u,
					dmom_adv_sge,
					mom_uu_diff_ten[1],
					dmom_u_ham_grad_p[0],
					tau_v0,
					tau_p0,
					q_cfl[eN_k]);

	      calculateSubgridError_tau(Ct_sge,Cd_sge,
			                G,G_dd_G,tr_G,
					tmpR,//dmom_u_acc_u_t,
					dmom_adv_sge,
					mom_uu_diff_ten[1],
					dmom_u_ham_grad_p[0],
					tau_v1,
					tau_p1,
					q_cfl[eN_k]);	

	      tau_v = useMetrics*tau_v1+(1.0-useMetrics)*tau_v0;
	      tau_p = useMetrics*tau_p1+(1.0-useMetrics)*tau_p0;

	      calculateSubgridError_tauRes(tau_p,
					   tau_v,
					   pdeResidual_p,
					   pdeResidual_u,
					   pdeResidual_v,
					   pdeResidual_w,
					   subgridError_p,
					   subgridError_u,
					   subgridError_v,
					   subgridError_w);
	      // velocity used in adjoint (VMS or RBLES, with or without lagging the grid scale velocity)
	      dmom_adv_star[0] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+0] - MOVING_DOMAIN*xt + useRBLES*subgridError_u);
	      dmom_adv_star[1] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+1] - MOVING_DOMAIN*yt + useRBLES*subgridError_v);
              /* dmom_adv_star[2] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+2] - MOVING_DOMAIN*zt + useRBLES*subgridError_w); */
         
	      mom_u_adv[0] += dmom_u_acc_u*(useRBLES*subgridError_u*q_velocity_sge[eN_k_nSpace+0]);  	   
	      mom_u_adv[1] += dmom_u_acc_u*(useRBLES*subgridError_v*q_velocity_sge[eN_k_nSpace+0]); 
              /* mom_u_adv[2] += dmom_u_acc_u*(useRBLES*subgridError_w*q_velocity_sge[eN_k_nSpace+0]);  */
         
	      mom_v_adv[0] += dmom_u_acc_u*(useRBLES*subgridError_u*q_velocity_sge[eN_k_nSpace+1]);   	   
	      mom_v_adv[1] += dmom_u_acc_u*(useRBLES*subgridError_v*q_velocity_sge[eN_k_nSpace+1]); 
              /* mom_v_adv[2] += dmom_u_acc_u*(useRBLES*subgridError_w*q_velocity_sge[eN_k_nSpace+1]);  */
         
	      /* mom_w_adv[0] += dmom_u_acc_u*(useRBLES*subgridError_u*q_velocity_sge[eN_k_nSpace+2]);   	    */
	      /* mom_w_adv[1] += dmom_u_acc_u*(useRBLES*subgridError_v*q_velocity_sge[eN_k_nSpace+2]);  */
              /* mom_w_adv[2] += dmom_u_acc_u*(useRBLES*subgridError_w*q_velocity_sge[eN_k_nSpace+2]);  */
              
	      // adjoint times the test functions 
	      for (int i=0;i<nDOF_test_element;i++)
		{
		  register int i_nSpace = i*nSpace;
		  Lstar_u_p[i]=ck.Advection_adjoint(dmass_adv_u,&p_grad_test_dV[i_nSpace]);
		  Lstar_v_p[i]=ck.Advection_adjoint(dmass_adv_v,&p_grad_test_dV[i_nSpace]);
		  /* Lstar_w_p[i]=ck.Advection_adjoint(dmass_adv_w,&p_grad_test_dV[i_nSpace]); */
                  //use the same advection adjoint for all three since we're approximating the linearized adjoint
		  Lstar_u_u[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]);
		  Lstar_v_v[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]);
		  /* Lstar_w_w[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]); */
		  Lstar_p_u[i]=ck.Hamiltonian_adjoint(dmom_u_ham_grad_p,&vel_grad_test_dV[i_nSpace]);
		  Lstar_p_v[i]=ck.Hamiltonian_adjoint(dmom_v_ham_grad_p,&vel_grad_test_dV[i_nSpace]);
		  /* Lstar_p_w[i]=ck.Hamiltonian_adjoint(dmom_w_ham_grad_p,&vel_grad_test_dV[i_nSpace]); */
		  
		  //VRANS account for drag terms, diagonal only here ... decide if need off diagonal terms too
		  Lstar_u_u[i]+=ck.Reaction_adjoint(dmom_u_source[0],vel_test_dV[i]);
		  Lstar_v_v[i]+=ck.Reaction_adjoint(dmom_v_source[1],vel_test_dV[i]);
		  /* Lstar_w_w[i]+=ck.Reaction_adjoint(dmom_w_source[2],vel_test_dV[i]); */
		  //
		}

	      norm_Rv = sqrt(pdeResidual_u*pdeResidual_u + pdeResidual_v*pdeResidual_v);// + pdeResidual_w*pdeResidual_w);
	      q_numDiff_u[eN_k] = C_dc*norm_Rv*(useMetrics/sqrt(G_dd_G+1.0e-12)  + 
	                                        (1.0-useMetrics)*hFactor*hFactor*elementDiameter[eN]*elementDiameter[eN]);
	      q_numDiff_v[eN_k] = q_numDiff_u[eN_k];
	      q_numDiff_w[eN_k] = q_numDiff_u[eN_k];
	      // 
	      //update element residual 
	      //
              double mesh_vel[2];
              mesh_vel[0] = xt;
              mesh_vel[1] = yt;
	      for(int i=0;i<nDOF_test_element;i++) 
		{ 
		  register int i_nSpace=i*nSpace;
                  /* std::cout<<"elemRes_mesh "<<mesh_vel[0]<<'\t'<<mesh_vel[2]<<'\t'<<p_test_dV[i]<<'\t'<<(q_dV_last[eN_k]/dV)<<'\t'<<dV<<std::endl; */
		  elementResidual_mesh[i] += ck.Mass_weak(q_dvos_dt[eN_k], p_test_dV[i]) +
                    ck.Reaction_weak(1.0,p_test_dV[i]) -
                    ck.Reaction_weak(1.0,p_test_dV[i]*q_dV_last[eN_k]/dV) -
                    ck.Advection_weak(mesh_vel,&p_grad_test_dV[i_nSpace]);
                  
		  elementResidual_p[i] += ck.Advection_weak(mass_adv,&p_grad_test_dV[i_nSpace]) +
		    DM*MOVING_DOMAIN*(ck.Reaction_weak(alphaBDF*1.0,p_test_dV[i]) -
                                      ck.Reaction_weak(alphaBDF*1.0,p_test_dV[i]*q_dV_last[eN_k]/dV) -
                                      ck.Advection_weak(mesh_vel,&p_grad_test_dV[i_nSpace])) +
		    //VRANS
		    ck.Reaction_weak(mass_source,p_test_dV[i])   + //VRANS source term for wave maker
		    //
		    ck.SubgridError(subgridError_u,Lstar_u_p[i]) + 
		    ck.SubgridError(subgridError_v,Lstar_v_p[i]);// + 
		    /* ck.SubgridError(subgridError_w,Lstar_w_p[i]); */

		  elementResidual_u[i] += ck.Mass_weak(mom_u_acc_t,vel_test_dV[i]) + 
		    ck.Advection_weak(mom_u_adv,&vel_grad_test_dV[i_nSpace]) +
		    ck.Diffusion_weak(sdInfo_u_u_rowptr,sdInfo_u_u_colind,mom_uu_diff_ten,grad_u,&vel_grad_test_dV[i_nSpace]) + 
		    ck.Diffusion_weak(sdInfo_u_v_rowptr,sdInfo_u_v_colind,mom_uv_diff_ten,grad_v,&vel_grad_test_dV[i_nSpace]) + 
		    /* ck.Diffusion_weak(sdInfo_u_w_rowptr,sdInfo_u_w_colind,mom_uw_diff_ten,grad_w,&vel_grad_test_dV[i_nSpace]) +  */
		    ck.Reaction_weak(mom_u_source,vel_test_dV[i]) + 
		    ck.Hamiltonian_weak(mom_u_ham,vel_test_dV[i]) + 
		    ck.SubgridError(subgridError_p,Lstar_p_u[i]) + 
		    ck.SubgridError(subgridError_u,Lstar_u_u[i]) + 
		    ck.NumericalDiffusion(q_numDiff_u_last[eN_k],grad_u,&vel_grad_test_dV[i_nSpace]); 
		 
		  elementResidual_v[i] += ck.Mass_weak(mom_v_acc_t,vel_test_dV[i]) + 
		    ck.Advection_weak(mom_v_adv,&vel_grad_test_dV[i_nSpace]) +
		    ck.Diffusion_weak(sdInfo_v_u_rowptr,sdInfo_v_u_colind,mom_vu_diff_ten,grad_u,&vel_grad_test_dV[i_nSpace]) + 
		    ck.Diffusion_weak(sdInfo_v_v_rowptr,sdInfo_v_v_colind,mom_vv_diff_ten,grad_v,&vel_grad_test_dV[i_nSpace]) + 
		    /* ck.Diffusion_weak(sdInfo_v_w_rowptr,sdInfo_v_w_colind,mom_vw_diff_ten,grad_w,&vel_grad_test_dV[i_nSpace]) +  */
		    ck.Reaction_weak(mom_v_source,vel_test_dV[i]) + 
		    ck.Hamiltonian_weak(mom_v_ham,vel_test_dV[i]) + 
		    ck.SubgridError(subgridError_p,Lstar_p_v[i]) + 
		    ck.SubgridError(subgridError_v,Lstar_v_v[i]) + 
		    ck.NumericalDiffusion(q_numDiff_v_last[eN_k],grad_v,&vel_grad_test_dV[i_nSpace]); 

		  /* elementResidual_w[i] +=  ck.Mass_weak(mom_w_acc_t,vel_test_dV[i]) + */
		  /*   ck.Advection_weak(mom_w_adv,&vel_grad_test_dV[i_nSpace]) +  */
		  /*   ck.Diffusion_weak(sdInfo_w_u_rowptr,sdInfo_w_u_colind,mom_wu_diff_ten,grad_u,&vel_grad_test_dV[i_nSpace]) +  */
		  /*   ck.Diffusion_weak(sdInfo_w_v_rowptr,sdInfo_w_v_colind,mom_wv_diff_ten,grad_v,&vel_grad_test_dV[i_nSpace]) +  */
		  /*   ck.Diffusion_weak(sdInfo_w_w_rowptr,sdInfo_w_w_colind,mom_ww_diff_ten,grad_w,&vel_grad_test_dV[i_nSpace]) +  */
		  /*   ck.Reaction_weak(mom_w_source,vel_test_dV[i]) +  */
		  /*   ck.Hamiltonian_weak(mom_w_ham,vel_test_dV[i]) +  */
		  /*   ck.SubgridError(subgridError_p,Lstar_p_w[i]) +  */
		  /*   ck.SubgridError(subgridError_w,Lstar_w_w[i]) +  */
		  /*   ck.NumericalDiffusion(q_numDiff_w_last[eN_k],grad_w,&vel_grad_test_dV[i_nSpace]);  */
		}//i
	    }
	  //
	  //load element into global residual and save element residual
	  //
	  for(int i=0;i<nDOF_test_element;i++) 
	    { 
	      register int eN_i=eN*nDOF_test_element+i;

	      elementResidual_p_save[eN_i] +=  elementResidual_p[i];
              mesh_volume_conservation_element_weak += elementResidual_mesh[i];
	      globalResidual[offset_p+stride_p*p_l2g[eN_i]]+=elementResidual_p[i];
	      globalResidual[offset_u+stride_u*vel_l2g[eN_i]]+=elementResidual_u[i];
	      globalResidual[offset_v+stride_v*vel_l2g[eN_i]]+=elementResidual_v[i];
	      /* globalResidual[offset_w+stride_w*vel_l2g[eN_i]]+=elementResidual_w[i]; */
	    }//i
          mesh_volume_conservation += mesh_volume_conservation_element;
          mesh_volume_conservation_weak += mesh_volume_conservation_element_weak;
          mesh_volume_conservation_err_max=fmax(mesh_volume_conservation_err_max,fabs(mesh_volume_conservation_element));
          mesh_volume_conservation_err_max_weak=fmax(mesh_volume_conservation_err_max_weak,fabs(mesh_volume_conservation_element_weak));
	}//elements
      //
      //loop over exterior element boundaries to calculate surface integrals and load into element and global residuals
      //
      //ebNE is the Exterior element boundary INdex
      //ebN is the element boundary INdex
      //eN is the element index
      for (int ebNE = 0; ebNE < nExteriorElementBoundaries_global; ebNE++) 
	{ 
	  register int ebN = exteriorElementBoundariesArray[ebNE], 
	    eN  = elementBoundaryElementsArray[ebN*2+0],
	    ebN_local = elementBoundaryLocalElementBoundariesArray[ebN*2+0],
	    eN_nDOF_trial_element = eN*nDOF_trial_element;
	  register double elementResidual_mesh[nDOF_test_element],
            elementResidual_p[nDOF_test_element],
	    elementResidual_u[nDOF_test_element],
	    elementResidual_v[nDOF_test_element],
	    //elementResidual_w[nDOF_test_element],
	    eps_rho,eps_mu;
	  const double* elementResidual_w(NULL);
	  for (int i=0;i<nDOF_test_element;i++)
	    {
	      elementResidual_mesh[i]=0.0;
	      elementResidual_p[i]=0.0;
	      elementResidual_u[i]=0.0;
	      elementResidual_v[i]=0.0;
	      /* elementResidual_w[i]=0.0; */
	    }
	  for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++) 
	    { 
	      register int ebNE_kb = ebNE*nQuadraturePoints_elementBoundary+kb,
		ebNE_kb_nSpace = ebNE_kb*nSpace,
		ebN_local_kb = ebN_local*nQuadraturePoints_elementBoundary+kb,
		ebN_local_kb_nSpace = ebN_local_kb*nSpace;
	      register double vosStar_ext=0.0,
		u_ext=0.0,
		v_ext=0.0,
		w_ext=0.0,
		grad_vosStar_ext[nSpace],
		grad_u_ext[nSpace],
		grad_v_ext[nSpace],
		grad_w_ext[nSpace],
		mom_u_acc_ext=0.0,
		dmom_u_acc_u_ext=0.0,
		mom_v_acc_ext=0.0,
		dmom_v_acc_v_ext=0.0,
		mom_w_acc_ext=0.0,
		dmom_w_acc_w_ext=0.0,
		mass_adv_ext[nSpace],
		dmass_adv_u_ext[nSpace],
		dmass_adv_v_ext[nSpace],
		dmass_adv_w_ext[nSpace],
		mom_u_adv_ext[nSpace],
		dmom_u_adv_u_ext[nSpace],
		dmom_u_adv_v_ext[nSpace],
		dmom_u_adv_w_ext[nSpace],
		mom_v_adv_ext[nSpace],
		dmom_v_adv_u_ext[nSpace],
		dmom_v_adv_v_ext[nSpace],
		dmom_v_adv_w_ext[nSpace],
		mom_w_adv_ext[nSpace],
		dmom_w_adv_u_ext[nSpace],
		dmom_w_adv_v_ext[nSpace],
		dmom_w_adv_w_ext[nSpace],
		mom_uu_diff_ten_ext[nSpace],
		mom_vv_diff_ten_ext[nSpace],
		mom_ww_diff_ten_ext[nSpace],
		mom_uv_diff_ten_ext[1],
		mom_uw_diff_ten_ext[1],
		mom_vu_diff_ten_ext[1],
		mom_vw_diff_ten_ext[1],
		mom_wu_diff_ten_ext[1],
		mom_wv_diff_ten_ext[1],
		mom_u_source_ext=0.0,
		mom_v_source_ext=0.0,
		mom_w_source_ext=0.0,
		mom_u_ham_ext=0.0,
		dmom_u_ham_grad_p_ext[nSpace],
		mom_v_ham_ext=0.0,
		dmom_v_ham_grad_p_ext[nSpace],
		mom_w_ham_ext=0.0,
		dmom_w_ham_grad_p_ext[nSpace],
		dmom_u_adv_p_ext[nSpace],
		dmom_v_adv_p_ext[nSpace],
		dmom_w_adv_p_ext[nSpace],
		flux_mass_ext=0.0,
		flux_mom_u_adv_ext=0.0,
		flux_mom_v_adv_ext=0.0,
		flux_mom_w_adv_ext=0.0,
		flux_mom_uu_diff_ext=0.0,
		flux_mom_uv_diff_ext=0.0,
		flux_mom_uw_diff_ext=0.0,
		flux_mom_vu_diff_ext=0.0,
		flux_mom_vv_diff_ext=0.0,
		flux_mom_vw_diff_ext=0.0,
		flux_mom_wu_diff_ext=0.0,
		flux_mom_wv_diff_ext=0.0,
		flux_mom_ww_diff_ext=0.0,
		bc_vosStar_ext=0.0,
		bc_u_ext=0.0,
		bc_v_ext=0.0,
		bc_w_ext=0.0,
		bc_mom_u_acc_ext=0.0,
		bc_dmom_u_acc_u_ext=0.0,
		bc_mom_v_acc_ext=0.0,
		bc_dmom_v_acc_v_ext=0.0,
		bc_mom_w_acc_ext=0.0,
		bc_dmom_w_acc_w_ext=0.0,
		bc_mass_adv_ext[nSpace],
		bc_dmass_adv_u_ext[nSpace],
		bc_dmass_adv_v_ext[nSpace],
		bc_dmass_adv_w_ext[nSpace],
		bc_mom_u_adv_ext[nSpace],
		bc_dmom_u_adv_u_ext[nSpace],
		bc_dmom_u_adv_v_ext[nSpace],
		bc_dmom_u_adv_w_ext[nSpace],
		bc_mom_v_adv_ext[nSpace],
		bc_dmom_v_adv_u_ext[nSpace],
		bc_dmom_v_adv_v_ext[nSpace],
		bc_dmom_v_adv_w_ext[nSpace],
		bc_mom_w_adv_ext[nSpace],
		bc_dmom_w_adv_u_ext[nSpace],
		bc_dmom_w_adv_v_ext[nSpace],
		bc_dmom_w_adv_w_ext[nSpace],
		bc_mom_uu_diff_ten_ext[nSpace],
		bc_mom_vv_diff_ten_ext[nSpace],
		bc_mom_ww_diff_ten_ext[nSpace],
		bc_mom_uv_diff_ten_ext[1],
		bc_mom_uw_diff_ten_ext[1],
		bc_mom_vu_diff_ten_ext[1],
		bc_mom_vw_diff_ten_ext[1],
		bc_mom_wu_diff_ten_ext[1],
		bc_mom_wv_diff_ten_ext[1],
		bc_mom_u_source_ext=0.0,
		bc_mom_v_source_ext=0.0,
		bc_mom_w_source_ext=0.0,
		bc_mom_u_ham_ext=0.0,
		bc_dmom_u_ham_grad_p_ext[nSpace],
		bc_mom_v_ham_ext=0.0,
		bc_dmom_v_ham_grad_p_ext[nSpace],
		bc_mom_w_ham_ext=0.0,
		bc_dmom_w_ham_grad_p_ext[nSpace],
		jac_ext[nSpace*nSpace],
		jacDet_ext,
		jacInv_ext[nSpace*nSpace],
		boundaryJac[nSpace*(nSpace-1)],
		metricTensor[(nSpace-1)*(nSpace-1)],
		metricTensorDetSqrt,
		dS,p_test_dS[nDOF_test_element],vel_test_dS[nDOF_test_element],
		p_grad_trial_trace[nDOF_trial_element*nSpace],vel_grad_trial_trace[nDOF_trial_element*nSpace],
		vel_grad_test_dS[nDOF_trial_element*nSpace],
		normal[2],x_ext,y_ext,z_ext,xt_ext,yt_ext,zt_ext,integralScaling,
		//VRANS
		vos_ext,
		//
		G[nSpace*nSpace],G_dd_G,tr_G,h_phi,h_penalty,penalty,
		force_x,force_y,force_z,force_p_x,force_p_y,force_p_z,force_v_x,force_v_y,force_v_z,r_x,r_y,r_z;
	      //compute information about mapping from reference element to physical element
	      ck.calculateMapping_elementBoundary(eN,
						  ebN_local,
						  kb,
						  ebN_local_kb,
						  mesh_dof,
						  mesh_l2g,
						  mesh_trial_trace_ref,
						  mesh_grad_trial_trace_ref,
						  boundaryJac_ref,
						  jac_ext,
						  jacDet_ext,
						  jacInv_ext,
						  boundaryJac,
						  metricTensor,
						  metricTensorDetSqrt,
						  normal_ref,
						  normal,
						  x_ext,y_ext,z_ext);
	      ck.calculateMappingVelocity_elementBoundary(eN,
							  ebN_local,
							  kb,
							  ebN_local_kb,
							  mesh_velocity_dof,
							  mesh_l2g,
							  mesh_trial_trace_ref,
							  xt_ext,yt_ext,zt_ext,
							  normal,
							  boundaryJac,
							  metricTensor,
							  integralScaling);
	      //xt_ext=0.0;yt_ext=0.0;zt_ext=0.0;
	      //std::cout<<"xt_ext "<<xt_ext<<'\t'<<yt_ext<<'\t'<<zt_ext<<std::endl;
	      //std::cout<<"x_ext "<<x_ext<<'\t'<<y_ext<<'\t'<<z_ext<<std::endl;
	      //std::cout<<"integralScaling - metricTensorDetSrt ==============================="<<integralScaling-metricTensorDetSqrt<<std::endl;
	      /* std::cout<<"metricTensorDetSqrt "<<metricTensorDetSqrt */
	      /* 	       <<"dS_ref[kb]"<<dS_ref[kb]<<std::endl; */
	      //dS = ((1.0-MOVING_DOMAIN)*metricTensorDetSqrt + MOVING_DOMAIN*integralScaling)*dS_ref[kb];//cek need to test effect on accuracy
	      dS = metricTensorDetSqrt*dS_ref[kb];
	      //get the metric tensor
	      //cek todo use symmetry
	      ck.calculateG(jacInv_ext,G,G_dd_G,tr_G);
	      ck.calculateGScale(G,&ebqe_normal_phi_ext[ebNE_kb_nSpace],h_phi);
	      
	      eps_rho = epsFact_rho*(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      eps_mu  = epsFact_mu *(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      
	      //compute shape and solution information
	      //shape
	      ck.gradTrialFromRef(&p_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,p_grad_trial_trace);
	      ck.gradTrialFromRef(&vel_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,vel_grad_trial_trace);
	      //cek hack use trial ck.gradTrialFromRef(&vel_grad_test_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,vel_grad_test_trace);
	      //solution and gradients	
	      ck.valFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],&p_trial_trace_ref[ebN_local_kb*nDOF_test_element],vosStar_ext);
	      ck.valFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],u_ext);
	      ck.valFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],v_ext);
	      /* ck.valFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],w_ext); */
	      ck.gradFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],p_grad_trial_trace,grad_vosStar_ext);
	      ck.gradFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_u_ext);
	      ck.gradFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_v_ext);
	      /* ck.gradFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_w_ext); */
	      //precalculate test function products with integration weights
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  p_test_dS[j] = p_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
		  vel_test_dS[j] = vel_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
		  for (int I=0;I<nSpace;I++)
		    vel_grad_test_dS[j*nSpace+I] = vel_grad_trial_trace[j*nSpace+I]*dS;//cek hack, using trial
		}
	      bc_vosStar_ext = isDOFBoundary_p[ebNE_kb]*ebqe_bc_p_ext[ebNE_kb]+(1-isDOFBoundary_p[ebNE_kb])*vosStar_ext;
              //note, our convention is that bc values at moving boundaries are relative to boundary velocity so we add it here
	      bc_u_ext = isDOFBoundary_u[ebNE_kb]*(ebqe_bc_u_ext[ebNE_kb] + MOVING_DOMAIN*xt_ext) + (1-isDOFBoundary_u[ebNE_kb])*u_ext;
	      bc_v_ext = isDOFBoundary_v[ebNE_kb]*(ebqe_bc_v_ext[ebNE_kb] + MOVING_DOMAIN*yt_ext) + (1-isDOFBoundary_v[ebNE_kb])*v_ext;
	      /* bc_w_ext = isDOFBoundary_w[ebNE_kb]*(ebqe_bc_w_ext[ebNE_kb] + MOVING_DOMAIN*zt_ext) + (1-isDOFBoundary_w[ebNE_kb])*w_ext; */
	      //VRANS
	      vos_ext = ebqe_vos_ext[ebNE_kb];
	      //
	      //calculate the pde coefficients using the solution and the boundary values for the solution 
	      // 
	      double eddy_viscosity_ext(0.),bc_eddy_viscosity_ext(0.); //not interested in saving boundary eddy viscosity for now
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   ebqe_vf_ext[ebNE_kb],
				   ebqe_phi_ext[ebNE_kb],
				   &ebqe_normal_phi_ext[ebNE_kb_nSpace],
				   ebqe_kappa_phi_ext[ebNE_kb],
				   //VRANS
				   ebqe_vos_ext[ebNE_kb],
				   //
				   ebqe_p_fluid_ext[ebNE_kb],
				   &ebqe_grad_p_fluid_ext[ebNE_kb_nSpace],
                                   vosStar_ext,
                                   grad_vosStar_ext,
				   grad_u_ext,
				   grad_v_ext,
				   grad_w_ext,
				   u_ext,
				   v_ext,
				   w_ext,
				   eddy_viscosity_ext,
				   mom_u_acc_ext,
				   dmom_u_acc_u_ext,
				   mom_v_acc_ext,
				   dmom_v_acc_v_ext,
				   mom_w_acc_ext,
				   dmom_w_acc_w_ext,
				   mass_adv_ext,
				   dmass_adv_u_ext,
				   dmass_adv_v_ext,
				   dmass_adv_w_ext,
				   mom_u_adv_ext,
				   dmom_u_adv_u_ext,
				   dmom_u_adv_v_ext,
				   dmom_u_adv_w_ext,
				   mom_v_adv_ext,
				   dmom_v_adv_u_ext,
				   dmom_v_adv_v_ext,
				   dmom_v_adv_w_ext,
				   mom_w_adv_ext,
				   dmom_w_adv_u_ext,
				   dmom_w_adv_v_ext,
				   dmom_w_adv_w_ext,
				   mom_uu_diff_ten_ext,
				   mom_vv_diff_ten_ext,
				   mom_ww_diff_ten_ext,
				   mom_uv_diff_ten_ext,
				   mom_uw_diff_ten_ext,
				   mom_vu_diff_ten_ext,
				   mom_vw_diff_ten_ext,
				   mom_wu_diff_ten_ext,
				   mom_wv_diff_ten_ext,
				   mom_u_source_ext,
				   mom_v_source_ext,
				   mom_w_source_ext,
				   mom_u_ham_ext,
				   dmom_u_ham_grad_p_ext,
				   mom_v_ham_ext,
				   dmom_v_ham_grad_p_ext,
				   mom_w_ham_ext,
				   dmom_w_ham_grad_p_ext);          
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   bc_ebqe_vf_ext[ebNE_kb],
				   bc_ebqe_phi_ext[ebNE_kb],
				   &ebqe_normal_phi_ext[ebNE_kb_nSpace],
				   ebqe_kappa_phi_ext[ebNE_kb],
				   //VRANS
				   ebqe_vos_ext[ebNE_kb],
				   //
				   ebqe_p_fluid_ext[ebNE_kb],
				   &ebqe_grad_p_fluid_ext[ebNE_kb_nSpace],
				   vosStar_ext,
                                   grad_vosStar_ext,
                                   grad_u_ext,
				   grad_v_ext,
				   grad_w_ext,
				   bc_u_ext,
				   bc_v_ext,
				   bc_w_ext,
				   bc_eddy_viscosity_ext,
				   bc_mom_u_acc_ext,
				   bc_dmom_u_acc_u_ext,
				   bc_mom_v_acc_ext,
				   bc_dmom_v_acc_v_ext,
				   bc_mom_w_acc_ext,
				   bc_dmom_w_acc_w_ext,
				   bc_mass_adv_ext,
				   bc_dmass_adv_u_ext,
				   bc_dmass_adv_v_ext,
				   bc_dmass_adv_w_ext,
				   bc_mom_u_adv_ext,
				   bc_dmom_u_adv_u_ext,
				   bc_dmom_u_adv_v_ext,
				   bc_dmom_u_adv_w_ext,
				   bc_mom_v_adv_ext,
				   bc_dmom_v_adv_u_ext,
				   bc_dmom_v_adv_v_ext,
				   bc_dmom_v_adv_w_ext,
				   bc_mom_w_adv_ext,
				   bc_dmom_w_adv_u_ext,
				   bc_dmom_w_adv_v_ext,
				   bc_dmom_w_adv_w_ext,
				   bc_mom_uu_diff_ten_ext,
				   bc_mom_vv_diff_ten_ext,
				   bc_mom_ww_diff_ten_ext,
				   bc_mom_uv_diff_ten_ext,
				   bc_mom_uw_diff_ten_ext,
				   bc_mom_vu_diff_ten_ext,
				   bc_mom_vw_diff_ten_ext,
				   bc_mom_wu_diff_ten_ext,
				   bc_mom_wv_diff_ten_ext,
				   bc_mom_u_source_ext,
				   bc_mom_v_source_ext,
				   bc_mom_w_source_ext,
				   bc_mom_u_ham_ext,
				   bc_dmom_u_ham_grad_p_ext,
				   bc_mom_v_ham_ext,
				   bc_dmom_v_ham_grad_p_ext,
				   bc_mom_w_ham_ext,
				   bc_dmom_w_ham_grad_p_ext);          

	      //Turbulence closure model
	      if (turbulenceClosureModel >= 3)
		{
		  const double turb_var_grad_0_dummy[2] = {0.,0.};
		  const double c_mu = 0.09;//mwf hack 
		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  ebqe_vf_ext[ebNE_kb],
					  ebqe_phi_ext[ebNE_kb],
					  vos_ext,
					  c_mu, //mwf hack
					  ebqe_turb_var_0[ebNE_kb],
					  ebqe_turb_var_1[ebNE_kb],
					  turb_var_grad_0_dummy, //not needed
					  eddy_viscosity_ext,
					  mom_uu_diff_ten_ext,
					  mom_vv_diff_ten_ext,
					  mom_ww_diff_ten_ext,
					  mom_uv_diff_ten_ext,
					  mom_uw_diff_ten_ext,
					  mom_vu_diff_ten_ext,
					  mom_vw_diff_ten_ext,
					  mom_wu_diff_ten_ext,
					  mom_wv_diff_ten_ext,
					  mom_u_source_ext,
					  mom_v_source_ext,
					  mom_w_source_ext);					  

		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  bc_ebqe_vf_ext[ebNE_kb],
					  bc_ebqe_phi_ext[ebNE_kb],
					  vos_ext,
					  c_mu, //mwf hack
					  ebqe_turb_var_0[ebNE_kb],
					  ebqe_turb_var_1[ebNE_kb],
					  turb_var_grad_0_dummy, //not needed
					  bc_eddy_viscosity_ext,
					  bc_mom_uu_diff_ten_ext,
					  bc_mom_vv_diff_ten_ext,
					  bc_mom_ww_diff_ten_ext,
					  bc_mom_uv_diff_ten_ext,
					  bc_mom_uw_diff_ten_ext,
					  bc_mom_vu_diff_ten_ext,
					  bc_mom_vw_diff_ten_ext,
					  bc_mom_wu_diff_ten_ext,
					  bc_mom_wv_diff_ten_ext,
					  bc_mom_u_source_ext,
					  bc_mom_v_source_ext,
					  bc_mom_w_source_ext);					  
		}


	      //
	      //moving domain
	      //
	      mom_u_adv_ext[0] -= MOVING_DOMAIN*mom_u_acc_ext*xt_ext;
	      mom_u_adv_ext[1] -= MOVING_DOMAIN*mom_u_acc_ext*yt_ext;
	      /* mom_u_adv_ext[2] -= MOVING_DOMAIN*mom_u_acc_ext*zt_ext; */
	      dmom_u_adv_u_ext[0] -= MOVING_DOMAIN*dmom_u_acc_u_ext*xt_ext;
	      dmom_u_adv_u_ext[1] -= MOVING_DOMAIN*dmom_u_acc_u_ext*yt_ext;
	      /* dmom_u_adv_u_ext[2] -= MOVING_DOMAIN*dmom_u_acc_u_ext*zt_ext; */

	      mom_v_adv_ext[0] -= MOVING_DOMAIN*mom_v_acc_ext*xt_ext;
	      mom_v_adv_ext[1] -= MOVING_DOMAIN*mom_v_acc_ext*yt_ext;
	      /* mom_v_adv_ext[2] -= MOVING_DOMAIN*mom_v_acc_ext*zt_ext; */
	      dmom_v_adv_v_ext[0] -= MOVING_DOMAIN*dmom_v_acc_v_ext*xt_ext;
	      dmom_v_adv_v_ext[1] -= MOVING_DOMAIN*dmom_v_acc_v_ext*yt_ext;
	      /* dmom_v_adv_v_ext[2] -= MOVING_DOMAIN*dmom_v_acc_v_ext*zt_ext; */

	      /* mom_w_adv_ext[0] -= MOVING_DOMAIN*mom_w_acc_ext*xt_ext; */
	      /* mom_w_adv_ext[1] -= MOVING_DOMAIN*mom_w_acc_ext*yt_ext; */
	      /* mom_w_adv_ext[2] -= MOVING_DOMAIN*mom_w_acc_ext*zt_ext; */
	      /* dmom_w_adv_w_ext[0] -= MOVING_DOMAIN*dmom_w_acc_w_ext*xt_ext; */
	      /* dmom_w_adv_w_ext[1] -= MOVING_DOMAIN*dmom_w_acc_w_ext*yt_ext; */
	      /* dmom_w_adv_w_ext[2] -= MOVING_DOMAIN*dmom_w_acc_w_ext*zt_ext; */

	      //bc's
	      bc_mom_u_adv_ext[0] -= MOVING_DOMAIN*bc_mom_u_acc_ext*xt_ext;
	      bc_mom_u_adv_ext[1] -= MOVING_DOMAIN*bc_mom_u_acc_ext*yt_ext;
	      /* bc_mom_u_adv_ext[2] -= MOVING_DOMAIN*bc_mom_u_acc_ext*zt_ext; */

	      bc_mom_v_adv_ext[0] -= MOVING_DOMAIN*bc_mom_v_acc_ext*xt_ext;
	      bc_mom_v_adv_ext[1] -= MOVING_DOMAIN*bc_mom_v_acc_ext*yt_ext;
	      /* bc_mom_v_adv_ext[2] -= MOVING_DOMAIN*bc_mom_v_acc_ext*zt_ext; */

	      /* bc_mom_w_adv_ext[0] -= MOVING_DOMAIN*bc_mom_w_acc_ext*xt_ext; */
	      /* bc_mom_w_adv_ext[1] -= MOVING_DOMAIN*bc_mom_w_acc_ext*yt_ext; */
	      /* bc_mom_w_adv_ext[2] -= MOVING_DOMAIN*bc_mom_w_acc_ext*zt_ext; */
	      // 
	      //calculate the numerical fluxes 
	      // 
	      ck.calculateGScale(G,normal,h_penalty);
	      penalty = useMetrics*C_b*h_penalty + (1.0-useMetrics)*ebqe_penalty_ext[ebNE_kb];
	      exteriorNumericalAdvectiveFlux(isDOFBoundary_p[ebNE_kb],
					     isDOFBoundary_u[ebNE_kb],
					     isDOFBoundary_v[ebNE_kb],
					     isDOFBoundary_w[ebNE_kb],
					     isAdvectiveFluxBoundary_p[ebNE_kb],
					     isAdvectiveFluxBoundary_u[ebNE_kb],
					     isAdvectiveFluxBoundary_v[ebNE_kb],
					     isAdvectiveFluxBoundary_w[ebNE_kb],
					     dmom_u_ham_grad_p_ext[0],//=1/rho,
					     bc_dmom_u_ham_grad_p_ext[0],//=1/bc_rho,
					     normal,
					     bc_vosStar_ext,
					     bc_mass_adv_ext,
					     bc_mom_u_adv_ext,
					     bc_mom_v_adv_ext,
					     bc_mom_w_adv_ext,
					     ebqe_bc_flux_mass_ext[ebNE_kb]+MOVING_DOMAIN*(xt_ext*normal[0]+yt_ext*normal[1]),//BC is relative mass flux
					     ebqe_bc_flux_mom_u_adv_ext[ebNE_kb],
					     ebqe_bc_flux_mom_v_adv_ext[ebNE_kb],
					     ebqe_bc_flux_mom_w_adv_ext[ebNE_kb],
					     vosStar_ext,
					     mass_adv_ext,
					     mom_u_adv_ext,
					     mom_v_adv_ext,
					     mom_w_adv_ext,
					     dmass_adv_u_ext,
					     dmass_adv_v_ext,
					     dmass_adv_w_ext,
					     dmom_u_adv_p_ext,
					     dmom_u_adv_u_ext,
					     dmom_u_adv_v_ext,
					     dmom_u_adv_w_ext,
					     dmom_v_adv_p_ext,
					     dmom_v_adv_u_ext,
					     dmom_v_adv_v_ext,
					     dmom_v_adv_w_ext,
					     dmom_w_adv_p_ext,
					     dmom_w_adv_u_ext,
					     dmom_w_adv_v_ext,
					     dmom_w_adv_w_ext,
					     flux_mass_ext,
					     flux_mom_u_adv_ext,
					     flux_mom_v_adv_ext,
					     flux_mom_w_adv_ext,
					     &ebqe_velocity[ebNE_kb_nSpace]);
	      exteriorNumericalDiffusiveFlux(eps_rho,
					     ebqe_phi_ext[ebNE_kb],
					     sdInfo_u_u_rowptr,
					     sdInfo_u_u_colind,
					     isDOFBoundary_u[ebNE_kb],
					     isDiffusiveFluxBoundary_u[ebNE_kb],
					     normal,
					     bc_mom_uu_diff_ten_ext,
					     bc_u_ext,
					     ebqe_bc_flux_u_diff_ext[ebNE_kb],
					     mom_uu_diff_ten_ext,
					     grad_u_ext,
					     u_ext,
					     penalty,//ebqe_penalty_ext[ebNE_kb],
					     flux_mom_uu_diff_ext);
	      exteriorNumericalDiffusiveFlux(eps_rho,
					     ebqe_phi_ext[ebNE_kb],
					     sdInfo_u_v_rowptr,
					     sdInfo_u_v_colind,
					     isDOFBoundary_v[ebNE_kb],
					     isDiffusiveFluxBoundary_v[ebNE_kb],
					     normal,
					     bc_mom_uv_diff_ten_ext,
					     bc_v_ext,
					     0.0,//assume all of the flux gets applied in diagonal component
					     mom_uv_diff_ten_ext,
					     grad_v_ext,
					     v_ext,
					     penalty,//ebqe_penalty_ext[ebNE_kb],
					     flux_mom_uv_diff_ext);
	      /* exteriorNumericalDiffusiveFlux(eps_rho, */
	      /* 				     ebqe_phi_ext[ebNE_kb], */
	      /* 				     sdInfo_u_w_rowptr, */
	      /* 				     sdInfo_u_w_colind, */
	      /* 				     isDOFBoundary_w[ebNE_kb], */
	      /* 				     isDiffusiveFluxBoundary_u[ebNE_kb], */
	      /* 				     normal, */
	      /* 				     bc_mom_uw_diff_ten_ext, */
	      /* 				     bc_w_ext, */
	      /* 				     0.0,//see above */
	      /* 				     mom_uw_diff_ten_ext, */
	      /* 				     grad_w_ext, */
	      /* 				     w_ext, */
	      /* 				     penalty,//ebqe_penalty_ext[ebNE_kb], */
	      /* 				     flux_mom_uw_diff_ext); */
	      exteriorNumericalDiffusiveFlux(eps_rho,
					     ebqe_phi_ext[ebNE_kb],
					     sdInfo_v_u_rowptr,
					     sdInfo_v_u_colind,
					     isDOFBoundary_u[ebNE_kb],
					     isDiffusiveFluxBoundary_u[ebNE_kb],
					     normal,
					     bc_mom_vu_diff_ten_ext,
					     bc_u_ext,
					     0.0,//see above
					     mom_vu_diff_ten_ext,
					     grad_u_ext,
					     u_ext,
					     penalty,//ebqe_penalty_ext[ebNE_kb],
					     flux_mom_vu_diff_ext);
	      exteriorNumericalDiffusiveFlux(eps_rho,
					     ebqe_phi_ext[ebNE_kb],
					     sdInfo_v_v_rowptr,
					     sdInfo_v_v_colind,
					     isDOFBoundary_v[ebNE_kb],
					     isDiffusiveFluxBoundary_v[ebNE_kb],
					     normal,
					     bc_mom_vv_diff_ten_ext,
					     bc_v_ext,
					     ebqe_bc_flux_v_diff_ext[ebNE_kb],
					     mom_vv_diff_ten_ext,
					     grad_v_ext,
					     v_ext,
					     penalty,//ebqe_penalty_ext[ebNE_kb],
					     flux_mom_vv_diff_ext);
	      /* exteriorNumericalDiffusiveFlux(eps_rho, */
	      /* 				     ebqe_phi_ext[ebNE_kb], */
	      /* 				     sdInfo_v_w_rowptr, */
	      /* 				     sdInfo_v_w_colind, */
	      /* 				     isDOFBoundary_w[ebNE_kb], */
	      /* 				     isDiffusiveFluxBoundary_v[ebNE_kb], */
	      /* 				     normal, */
	      /* 				     bc_mom_vw_diff_ten_ext, */
	      /* 				     bc_w_ext, */
	      /* 				     0.0,//see above */
	      /* 				     mom_vw_diff_ten_ext, */
	      /* 				     grad_w_ext, */
	      /* 				     w_ext, */
	      /* 				     penalty,//ebqe_penalty_ext[ebNE_kb], */
	      /* 				     flux_mom_vw_diff_ext); */
	      /* exteriorNumericalDiffusiveFlux(eps_rho, */
	      /* 				     ebqe_phi_ext[ebNE_kb], */
	      /* 				     sdInfo_w_u_rowptr, */
	      /* 				     sdInfo_w_u_colind, */
	      /* 				     isDOFBoundary_u[ebNE_kb], */
	      /* 				     isDiffusiveFluxBoundary_w[ebNE_kb], */
	      /* 				     normal, */
	      /* 				     bc_mom_wu_diff_ten_ext, */
	      /* 				     bc_u_ext, */
	      /* 				     0.0,//see above */
	      /* 				     mom_wu_diff_ten_ext, */
	      /* 				     grad_u_ext, */
	      /* 				     u_ext, */
	      /* 				     penalty,//ebqe_penalty_ext[ebNE_kb], */
	      /* 				     flux_mom_wu_diff_ext); */
	      /* exteriorNumericalDiffusiveFlux(eps_rho, */
	      /* 				     ebqe_phi_ext[ebNE_kb], */
	      /* 				     sdInfo_w_v_rowptr, */
	      /* 				     sdInfo_w_v_colind, */
	      /* 				     isDOFBoundary_v[ebNE_kb], */
	      /* 				     isDiffusiveFluxBoundary_w[ebNE_kb], */
	      /* 				     normal, */
	      /* 				     bc_mom_wv_diff_ten_ext, */
	      /* 				     bc_v_ext, */
	      /* 				     0.0,//see above */
	      /* 				     mom_wv_diff_ten_ext, */
	      /* 				     grad_v_ext, */
	      /* 				     v_ext, */
	      /* 				     penalty,//ebqe_penalty_ext[ebNE_kb], */
	      /* 				     flux_mom_wv_diff_ext); */
	      /* exteriorNumericalDiffusiveFlux(eps_rho, */
	      /* 				     ebqe_phi_ext[ebNE_kb], */
	      /* 				     sdInfo_w_w_rowptr, */
	      /* 				     sdInfo_w_w_colind, */
	      /* 				     isDOFBoundary_w[ebNE_kb], */
	      /* 				     isDiffusiveFluxBoundary_w[ebNE_kb], */
	      /* 				     normal, */
	      /* 				     bc_mom_ww_diff_ten_ext, */
	      /* 				     bc_w_ext, */
	      /* 				     ebqe_bc_flux_w_diff_ext[ebNE_kb], */
	      /* 				     mom_ww_diff_ten_ext, */
	      /* 				     grad_w_ext, */
	      /* 				     w_ext, */
	      /* 				     penalty,//ebqe_penalty_ext[ebNE_kb], */
	      /* 				     flux_mom_ww_diff_ext); */
	      flux[ebN*nQuadraturePoints_elementBoundary+kb] = flux_mass_ext;
	      /* std::cout<<"external u,v,u_n " */
	      /* 	       <<ebqe_velocity[ebNE_kb_nSpace+0]<<'\t' */
	      /* 	       <<ebqe_velocity[ebNE_kb_nSpace+1]<<'\t' */
	      /* 	       <<flux[ebN*nQuadraturePoints_elementBoundary+kb]<<std::endl; */
	      // 
	      //integrate the net force and moment on flagged boundaries
	      //
	      if (ebN < nElementBoundaries_owned)
		{
		  force_v_x = (flux_mom_u_adv_ext + flux_mom_uu_diff_ext + flux_mom_uv_diff_ext + flux_mom_uw_diff_ext)/dmom_u_ham_grad_p_ext[0];//same as *rho
		  force_v_y = (flux_mom_v_adv_ext + flux_mom_vu_diff_ext + flux_mom_vv_diff_ext + flux_mom_vw_diff_ext)/dmom_u_ham_grad_p_ext[0];
		  //force_v_z = (flux_mom_wu_diff_ext + flux_mom_wv_diff_ext + flux_mom_ww_diff_ext)/dmom_u_ham_grad_p_ext[0];
		  
		  force_p_x = vosStar_ext*normal[0];
		  force_p_y = vosStar_ext*normal[1];
		  /* force_p_z = vosStar_ext*normal[2]; */
		  
		  force_x = force_p_x + force_v_x;
		  force_y = force_p_y + force_v_y;
		  //force_z = force_p_z + force_v_z;
		  
		  r_x = x_ext - barycenters[3*boundaryFlags[ebN]+0];
		  r_y = y_ext - barycenters[3*boundaryFlags[ebN]+1];
		  //r_z = z_ext - barycenters[3*boundaryFlags[ebN]+2];
		  
		  wettedAreas[boundaryFlags[ebN]] += dS*(1.0-ebqe_vf_ext[ebNE_kb]);
		  
		  netForces_p[3*boundaryFlags[ebN]+0] += force_p_x*dS;
		  netForces_p[3*boundaryFlags[ebN]+1] += force_p_y*dS;
		  //netForces_p[3*boundaryFlags[ebN]+2] += force_p_z*dS;
		  
		  netForces_v[3*boundaryFlags[ebN]+0] += force_v_x*dS;
		  netForces_v[3*boundaryFlags[ebN]+1] += force_v_y*dS;
		  //netForces_v[3*boundaryFlags[ebN]+2] += force_v_z*dS;
		  
		  //netMoments[3*boundaryFlags[ebN]+0] += (r_y*force_z - r_z*force_y)*dS;
		  //netMoments[3*boundaryFlags[ebN]+1] += (r_z*force_x - r_x*force_z)*dS;
		  netMoments[3*boundaryFlags[ebN]+2] += (r_x*force_y - r_y*force_x)*dS;
		}
	      //
	      //update residuals
	      //
	      for (int i=0;i<nDOF_test_element;i++)
		{
		  elementResidual_mesh[i] -= ck.ExteriorElementBoundaryFlux(MOVING_DOMAIN*(xt_ext*normal[0]+yt_ext*normal[1]),p_test_dS[i]);
		  elementResidual_p[i] += ck.ExteriorElementBoundaryFlux(flux_mass_ext,p_test_dS[i]);
		  elementResidual_p[i] -= DM*ck.ExteriorElementBoundaryFlux(MOVING_DOMAIN*(xt_ext*normal[0]+yt_ext*normal[1]),p_test_dS[i]); 
		  globalConservationError += ck.ExteriorElementBoundaryFlux(flux_mass_ext,p_test_dS[i]);
		  
		  elementResidual_u[i] += ck.ExteriorElementBoundaryFlux(flux_mom_u_adv_ext,vel_test_dS[i])+
		    ck.ExteriorElementBoundaryFlux(flux_mom_uu_diff_ext,vel_test_dS[i])+
		    ck.ExteriorElementBoundaryFlux(flux_mom_uv_diff_ext,vel_test_dS[i])+
		    /* ck.ExteriorElementBoundaryFlux(flux_mom_uw_diff_ext,vel_test_dS[i])+ */
		    ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_u[ebNE_kb],
							       isDiffusiveFluxBoundary_u[ebNE_kb],
							       eb_adjoint_sigma,
							       u_ext,
							       bc_u_ext,
							       normal,
							       sdInfo_u_u_rowptr,
							       sdInfo_u_u_colind,
							       mom_uu_diff_ten_ext,
							       &vel_grad_test_dS[i*nSpace])+
		    ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_v[ebNE_kb],
							       isDiffusiveFluxBoundary_u[ebNE_kb],
							       eb_adjoint_sigma,
							       v_ext,
							       bc_v_ext,
							       normal,
							       sdInfo_u_v_rowptr,
							       sdInfo_u_v_colind,
							       mom_uv_diff_ten_ext,
							       &vel_grad_test_dS[i*nSpace]);//+
		    /* ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_w[ebNE_kb], */
		    /* 					       isDiffusiveFluxBoundary_u[ebNE_kb], */
		    /* 					       eb_adjoint_sigma, */
		    /* 					       w_ext, */
		    /* 					       bc_w_ext, */
		    /* 					       normal, */
		    /* 					       sdInfo_u_w_rowptr, */
		    /* 					       sdInfo_u_w_colind, */
		    /* 					       mom_uw_diff_ten_ext, */
		    /* 					       &vel_grad_test_dS[i*nSpace]); */
		  elementResidual_v[i] += ck.ExteriorElementBoundaryFlux(flux_mom_v_adv_ext,vel_test_dS[i]) +
		    ck.ExteriorElementBoundaryFlux(flux_mom_vu_diff_ext,vel_test_dS[i])+
		    ck.ExteriorElementBoundaryFlux(flux_mom_vv_diff_ext,vel_test_dS[i])+
		    /* ck.ExteriorElementBoundaryFlux(flux_mom_vw_diff_ext,vel_test_dS[i])+ */
		    ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_u[ebNE_kb],
							       isDiffusiveFluxBoundary_v[ebNE_kb],
							       eb_adjoint_sigma,
							       u_ext,
							       bc_u_ext,
							       normal,
							       sdInfo_v_u_rowptr,
							       sdInfo_v_u_colind,
							       mom_vu_diff_ten_ext,
							       &vel_grad_test_dS[i*nSpace])+
		    ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_v[ebNE_kb],
							       isDiffusiveFluxBoundary_v[ebNE_kb],
							       eb_adjoint_sigma,
							       v_ext,
							       bc_v_ext,
							       normal,
							       sdInfo_v_v_rowptr,
							       sdInfo_v_v_colind,
							       mom_vv_diff_ten_ext,
							       &vel_grad_test_dS[i*nSpace]);//+
		    /* ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_w[ebNE_kb], */
		    /* 					       isDiffusiveFluxBoundary_v[ebNE_kb], */
		    /* 					       eb_adjoint_sigma, */
		    /* 					       w_ext, */
		    /* 					       bc_w_ext, */
		    /* 					       normal, */
		    /* 					       sdInfo_v_w_rowptr, */
		    /* 					       sdInfo_v_w_colind, */
		    /* 					       mom_vw_diff_ten_ext, */
		    /* 					       &vel_grad_test_dS[i*nSpace]);  */
		  
		  /* elementResidual_w[i] += ck.ExteriorElementBoundaryFlux(flux_mom_w_adv_ext,vel_test_dS[i]) + */
		  /*   ck.ExteriorElementBoundaryFlux(flux_mom_wu_diff_ext,vel_test_dS[i])+ */
		  /*   ck.ExteriorElementBoundaryFlux(flux_mom_wv_diff_ext,vel_test_dS[i])+ */
		  /*   ck.ExteriorElementBoundaryFlux(flux_mom_ww_diff_ext,vel_test_dS[i])+ */
		  /*   ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_u[ebNE_kb], */
		  /* 					       isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					       eb_adjoint_sigma, */
		  /* 					       u_ext, */
		  /* 					       bc_u_ext, */
		  /* 					       normal, */
		  /* 					       sdInfo_w_u_rowptr, */
		  /* 					       sdInfo_w_u_colind, */
		  /* 					       mom_wu_diff_ten_ext, */
		  /* 					       &vel_grad_test_dS[i*nSpace])+ */
		  /*   ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_v[ebNE_kb], */
		  /* 					       isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					       eb_adjoint_sigma, */
		  /* 					       v_ext, */
		  /* 					       bc_v_ext, */
		  /* 					       normal, */
		  /* 					       sdInfo_w_v_rowptr, */
		  /* 					       sdInfo_w_v_colind, */
		  /* 					       mom_wv_diff_ten_ext, */
		  /* 					       &vel_grad_test_dS[i*nSpace])+ */
		  /*   ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_w[ebNE_kb], */
		  /* 					       isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					       eb_adjoint_sigma, */
		  /* 					       w_ext, */
		  /* 					       bc_w_ext, */
		  /* 					       normal, */
		  /* 					       sdInfo_w_w_rowptr, */
		  /* 					       sdInfo_w_w_colind, */
		  /* 					       mom_ww_diff_ten_ext, */
		  /* 					       &vel_grad_test_dS[i*nSpace]);  */
		}//i
	    }//kb
	  //
	  //update the element and global residual storage
	  //
	  for (int i=0;i<nDOF_test_element;i++)
	    {
	      int eN_i = eN*nDOF_test_element+i;
	      
	      elementResidual_p_save[eN_i] +=  elementResidual_p[i];
              mesh_volume_conservation_weak += elementResidual_mesh[i];		  
	      globalResidual[offset_p+stride_p*p_l2g[eN_i]]+=elementResidual_p[i];
	      globalResidual[offset_u+stride_u*vel_l2g[eN_i]]+=elementResidual_u[i];
	      globalResidual[offset_v+stride_v*vel_l2g[eN_i]]+=elementResidual_v[i];
	      /* globalResidual[offset_w+stride_w*vel_l2g[eN_i]]+=elementResidual_w[i]; */
	    }//i
	}//ebNE
      /* std::cout<<"mesh volume conservation = "<<mesh_volume_conservation<<std::endl; */
      /* std::cout<<"mesh volume conservation weak = "<<mesh_volume_conservation_weak<<std::endl; */
      /* std::cout<<"mesh volume conservation err max= "<<mesh_volume_conservation_err_max<<std::endl; */
      /* std::cout<<"mesh volume conservation err max weak = "<<mesh_volume_conservation_err_max_weak<<std::endl; */
    }

    void calculateJacobian(//element
			   double* mesh_trial_ref,
			   double* mesh_grad_trial_ref,
			   double* mesh_dof,
			   double* mesh_velocity_dof,
			   double MOVING_DOMAIN,
			   int* mesh_l2g,
			   double* dV_ref,
			   double* p_trial_ref,
			   double* p_grad_trial_ref,
			   double* p_test_ref,
			   double* p_grad_test_ref,
			   double* vel_trial_ref,
			   double* vel_grad_trial_ref,
			   double* vel_test_ref,
			   double* vel_grad_test_ref,
			   //element boundary
			   double* mesh_trial_trace_ref,
			   double* mesh_grad_trial_trace_ref,
			   double* dS_ref,
			   double* p_trial_trace_ref,
			   double* p_grad_trial_trace_ref,
			   double* p_test_trace_ref,
			   double* p_grad_test_trace_ref,
			   double* vel_trial_trace_ref,
			   double* vel_grad_trial_trace_ref,
			   double* vel_test_trace_ref,
			   double* vel_grad_test_trace_ref,					 
			   double* normal_ref,
			   double* boundaryJac_ref,
			   //physics
			   double eb_adjoint_sigma,
			   double* elementDiameter,
			   double* nodeDiametersArray,
			   double hFactor,
			   int nElements_global,
			   double useRBLES,
			   double useMetrics, 
			   double alphaBDF,
			   double epsFact_rho,
			   double epsFact_mu,
			   double sigma,
			   double rho_0,
			   double nu_0,
			   double rho_1,
			   double nu_1,
			   double smagorinskyConstant,
			   int turbulenceClosureModel,
			   double Ct_sge,
			   double Cd_sge,
			   double C_dg,
			   double C_b,
			   //VRANS
			   const double* eps_solid,
			   const double* q_velocity_fluid,
                           const double* q_p_fluid,
                           const double* q_grad_p_fluid,
			   const double* q_vos,
			   const double* q_dragAlpha,
			   const double* q_dragBeta,
			   const double* q_mass_source,
			   const double* q_turb_var_0,
			   const double* q_turb_var_1,
			   const double* q_turb_var_grad_0,
			   //
			   int* p_l2g, 
			   int* vel_l2g,
			   double* p_dof, double* u_dof, double* v_dof, double* w_dof,
			   double* g,
			   const double useVF,
			   double* vf,
			   double* phi,
			   double* normal_phi,
			   double* kappa_phi,
			   double* q_mom_u_acc_beta_bdf, double* q_mom_v_acc_beta_bdf, double* q_mom_w_acc_beta_bdf,
                           double* q_dV,
                           double* q_dV_last,
			   double* q_velocity_sge,
			   double* q_cfl,
			   double* q_numDiff_u_last, double* q_numDiff_v_last, double* q_numDiff_w_last,
			   int* sdInfo_u_u_rowptr,int* sdInfo_u_u_colind,			      
			   int* sdInfo_u_v_rowptr,int* sdInfo_u_v_colind,
			   int* sdInfo_u_w_rowptr,int* sdInfo_u_w_colind,
			   int* sdInfo_v_v_rowptr,int* sdInfo_v_v_colind,
			   int* sdInfo_v_u_rowptr,int* sdInfo_v_u_colind,
			   int* sdInfo_v_w_rowptr,int* sdInfo_v_w_colind,
			   int* sdInfo_w_w_rowptr,int* sdInfo_w_w_colind,
			   int* sdInfo_w_u_rowptr,int* sdInfo_w_u_colind,
			   int* sdInfo_w_v_rowptr,int* sdInfo_w_v_colind,
			   int* csrRowIndeces_p_p,int* csrColumnOffsets_p_p,
			   int* csrRowIndeces_p_u,int* csrColumnOffsets_p_u,
			   int* csrRowIndeces_p_v,int* csrColumnOffsets_p_v,
			   int* csrRowIndeces_p_w,int* csrColumnOffsets_p_w,
			   int* csrRowIndeces_u_p,int* csrColumnOffsets_u_p,
			   int* csrRowIndeces_u_u,int* csrColumnOffsets_u_u,
			   int* csrRowIndeces_u_v,int* csrColumnOffsets_u_v,
			   int* csrRowIndeces_u_w,int* csrColumnOffsets_u_w,
			   int* csrRowIndeces_v_p,int* csrColumnOffsets_v_p,
			   int* csrRowIndeces_v_u,int* csrColumnOffsets_v_u,
			   int* csrRowIndeces_v_v,int* csrColumnOffsets_v_v,
			   int* csrRowIndeces_v_w,int* csrColumnOffsets_v_w,
			   int* csrRowIndeces_w_p,int* csrColumnOffsets_w_p,
			   int* csrRowIndeces_w_u,int* csrColumnOffsets_w_u,
			   int* csrRowIndeces_w_v,int* csrColumnOffsets_w_v,
			   int* csrRowIndeces_w_w,int* csrColumnOffsets_w_w,
			   double* globalJacobian,
			   int nExteriorElementBoundaries_global,
			   int* exteriorElementBoundariesArray,
			   int* elementBoundaryElementsArray,
			   int* elementBoundaryLocalElementBoundariesArray,
			   double* ebqe_vf_ext,
			   double* bc_ebqe_vf_ext,
			   double* ebqe_phi_ext,
			   double* bc_ebqe_phi_ext,
			   double* ebqe_normal_phi_ext,
			   double* ebqe_kappa_phi_ext,
			   //VRANS
			   const double* ebqe_vos_ext,
			   const double* ebqe_p_fluid_ext,
			   const double* ebqe_grad_p_fluid_ext,
			   const double* ebqe_turb_var_0,
			   const double* ebqe_turb_var_1,
			   //
			   int* isDOFBoundary_p,
			   int* isDOFBoundary_u,
			   int* isDOFBoundary_v,
			   int* isDOFBoundary_w,
			   int* isAdvectiveFluxBoundary_p,
			   int* isAdvectiveFluxBoundary_u,
			   int* isAdvectiveFluxBoundary_v,
			   int* isAdvectiveFluxBoundary_w,
			   int* isDiffusiveFluxBoundary_u,
			   int* isDiffusiveFluxBoundary_v,
			   int* isDiffusiveFluxBoundary_w,
			   double* ebqe_bc_p_ext,
			   double* ebqe_bc_flux_mass_ext,
			   double* ebqe_bc_flux_mom_u_adv_ext,
			   double* ebqe_bc_flux_mom_v_adv_ext,
			   double* ebqe_bc_flux_mom_w_adv_ext,
			   double* ebqe_bc_u_ext,
			   double* ebqe_bc_flux_u_diff_ext,
			   double* ebqe_penalty_ext,
			   double* ebqe_bc_v_ext,
			   double* ebqe_bc_flux_v_diff_ext,
			   double* ebqe_bc_w_ext,
			   double* ebqe_bc_flux_w_diff_ext,
			   int* csrColumnOffsets_eb_p_p,
			   int* csrColumnOffsets_eb_p_u,
			   int* csrColumnOffsets_eb_p_v,
			   int* csrColumnOffsets_eb_p_w,
			   int* csrColumnOffsets_eb_u_p,
			   int* csrColumnOffsets_eb_u_u,
			   int* csrColumnOffsets_eb_u_v,
			   int* csrColumnOffsets_eb_u_w,
			   int* csrColumnOffsets_eb_v_p,
			   int* csrColumnOffsets_eb_v_u,
			   int* csrColumnOffsets_eb_v_v,
			   int* csrColumnOffsets_eb_v_w,
			   int* csrColumnOffsets_eb_w_p,
			   int* csrColumnOffsets_eb_w_u,
			   int* csrColumnOffsets_eb_w_v,
			   int* csrColumnOffsets_eb_w_w,
			   int* elementFlags)
    {
      //
      //loop over elements to compute volume integrals and load them into the element Jacobians and global Jacobian
      //
      for(int eN=0;eN<nElements_global;eN++)
	{
	  register double eps_rho,eps_mu;

	  register double  elementJacobian_p_p[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_p_u[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_p_v[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_p_w[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_u_p[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_u_u[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_u_v[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_u_w[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_v_p[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_v_u[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_v_v[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_v_w[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_w_p[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_w_u[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_w_v[nDOF_test_element][nDOF_trial_element],
	    elementJacobian_w_w[nDOF_test_element][nDOF_trial_element];
	  for (int i=0;i<nDOF_test_element;i++)
	    for (int j=0;j<nDOF_trial_element;j++)
	      {
		elementJacobian_p_p[i][j]=0.0;
		elementJacobian_p_u[i][j]=0.0;
		elementJacobian_p_v[i][j]=0.0;
		elementJacobian_p_w[i][j]=0.0;
		elementJacobian_u_p[i][j]=0.0;
		elementJacobian_u_u[i][j]=0.0;
		elementJacobian_u_v[i][j]=0.0;
		elementJacobian_u_w[i][j]=0.0;
		elementJacobian_v_p[i][j]=0.0;
		elementJacobian_v_u[i][j]=0.0;
		elementJacobian_v_v[i][j]=0.0;
		elementJacobian_v_w[i][j]=0.0;
		elementJacobian_w_p[i][j]=0.0;
		elementJacobian_w_u[i][j]=0.0;
		elementJacobian_w_v[i][j]=0.0;
		elementJacobian_w_w[i][j]=0.0;
	      }
	  for  (int k=0;k<nQuadraturePoints_element;k++)
	    {
	      int eN_k = eN*nQuadraturePoints_element+k, //index to a scalar at a quadrature point
		eN_k_nSpace = eN_k*nSpace,
		eN_nDOF_trial_element = eN*nDOF_trial_element; //index to a vector at a quadrature point

	      //declare local storage
	      register double vosStar=0.0,u=0.0,v=0.0,w=0.0,
		grad_vosStar[nSpace],grad_u[nSpace],grad_v[nSpace],grad_w[nSpace],
		mom_u_acc=0.0,
		dmom_u_acc_u=0.0,
		mom_v_acc=0.0,
		dmom_v_acc_v=0.0,
		mom_w_acc=0.0,
		dmom_w_acc_w=0.0,
		mass_adv[nSpace],
		dmass_adv_u[nSpace],
		dmass_adv_v[nSpace],
		dmass_adv_w[nSpace],
		mom_u_adv[nSpace],
		dmom_u_adv_u[nSpace],
		dmom_u_adv_v[nSpace],
		dmom_u_adv_w[nSpace],
		mom_v_adv[nSpace],
		dmom_v_adv_u[nSpace],
		dmom_v_adv_v[nSpace],
		dmom_v_adv_w[nSpace],
		mom_w_adv[nSpace],
		dmom_w_adv_u[nSpace],
		dmom_w_adv_v[nSpace],
		dmom_w_adv_w[nSpace],
		mom_uu_diff_ten[nSpace],
		mom_vv_diff_ten[nSpace],
		mom_ww_diff_ten[nSpace],
		mom_uv_diff_ten[1],
		mom_uw_diff_ten[1],
		mom_vu_diff_ten[1],
		mom_vw_diff_ten[1],
		mom_wu_diff_ten[1],
		mom_wv_diff_ten[1],
		mom_u_source=0.0,
		mom_v_source=0.0,
		mom_w_source=0.0,
		mom_u_ham=0.0,
		dmom_u_ham_grad_p[nSpace],
		mom_v_ham=0.0,
		dmom_v_ham_grad_p[nSpace],
		mom_w_ham=0.0,
		dmom_w_ham_grad_p[nSpace],
		mom_u_acc_t=0.0,
		dmom_u_acc_u_t=0.0,
		mom_v_acc_t=0.0,
		dmom_v_acc_v_t=0.0,
		mom_w_acc_t=0.0,
		dmom_w_acc_w_t=0.0,
		pdeResidual_p=0.0,
		pdeResidual_u=0.0,
		pdeResidual_v=0.0,
		pdeResidual_w=0.0,	    
		dpdeResidual_p_u[nDOF_trial_element],dpdeResidual_p_v[nDOF_trial_element],dpdeResidual_p_w[nDOF_trial_element],
		dpdeResidual_u_p[nDOF_trial_element],dpdeResidual_u_u[nDOF_trial_element],
		dpdeResidual_v_p[nDOF_trial_element],dpdeResidual_v_v[nDOF_trial_element],
		dpdeResidual_w_p[nDOF_trial_element],dpdeResidual_w_w[nDOF_trial_element],
		Lstar_u_p[nDOF_test_element],
		Lstar_v_p[nDOF_test_element],
		Lstar_w_p[nDOF_test_element],
		Lstar_u_u[nDOF_test_element],
		Lstar_v_v[nDOF_test_element],
		Lstar_w_w[nDOF_test_element],
		Lstar_p_u[nDOF_test_element],
		Lstar_p_v[nDOF_test_element],
		Lstar_p_w[nDOF_test_element],
		subgridError_p=0.0,
		subgridError_u=0.0,
		subgridError_v=0.0,
		subgridError_w=0.0,	    
		dsubgridError_p_u[nDOF_trial_element],
		dsubgridError_p_v[nDOF_trial_element],
		dsubgridError_p_w[nDOF_trial_element],
		dsubgridError_u_p[nDOF_trial_element],
		dsubgridError_u_u[nDOF_trial_element],
		dsubgridError_v_p[nDOF_trial_element],
		dsubgridError_v_v[nDOF_trial_element],
		dsubgridError_w_p[nDOF_trial_element],
		dsubgridError_w_w[nDOF_trial_element],
		tau_p=0.0,tau_p0=0.0,tau_p1=0.0,
		tau_v=0.0,tau_v0=0.0,tau_v1=0.0,
		jac[nSpace*nSpace],
		jacDet,
		jacInv[nSpace*nSpace],
		p_grad_trial[nDOF_trial_element*nSpace],vel_grad_trial[nDOF_trial_element*nSpace],
		dV,
		p_test_dV[nDOF_test_element],vel_test_dV[nDOF_test_element],
		p_grad_test_dV[nDOF_test_element*nSpace],vel_grad_test_dV[nDOF_test_element*nSpace],
		x,y,z,xt,yt,zt,
		//VRANS
		vos,
		//meanGrainSize,
		dmom_u_source[nSpace],
		dmom_v_source[nSpace],
		dmom_w_source[nSpace],
		mass_source,
		//
		G[nSpace*nSpace],G_dd_G,tr_G,h_phi, dmom_adv_star[nSpace], dmom_adv_sge[nSpace];
	      //get jacobian, etc for mapping reference element
	      ck.calculateMapping_element(eN,
					  k,
					  mesh_dof,
					  mesh_l2g,
					  mesh_trial_ref,
					  mesh_grad_trial_ref,
					  jac,
					  jacDet,
					  jacInv,
					  x,y,z);
	      ck.calculateH_element(eN,
				    k,
				    nodeDiametersArray,
				    mesh_l2g,
				    mesh_trial_ref,
				    h_phi);
	      ck.calculateMappingVelocity_element(eN,
						  k,
						  mesh_velocity_dof,
						  mesh_l2g,
						  mesh_trial_ref,
						  xt,yt,zt);
	      //xt=0.0;yt=0.0;zt=0.0;
	      //std::cout<<"xt "<<xt<<'\t'<<yt<<'\t'<<zt<<std::endl;
	      //get the physical integration weight
	      dV = fabs(jacDet)*dV_ref[k];
	      ck.calculateG(jacInv,G,G_dd_G,tr_G);
	      //ck.calculateGScale(G,&normal_phi[eN_k_nSpace],h_phi);
	
	      eps_rho = epsFact_rho*(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      eps_mu  = epsFact_mu *(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      
	      //get the trial function gradients
	      ck.gradTrialFromRef(&p_grad_trial_ref[k*nDOF_trial_element*nSpace],jacInv,p_grad_trial);
	      ck.gradTrialFromRef(&vel_grad_trial_ref[k*nDOF_trial_element*nSpace],jacInv,vel_grad_trial);
	      //get the solution 	
	      ck.valFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],&p_trial_ref[k*nDOF_trial_element],vosStar);
	      ck.valFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],u);
	      ck.valFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],v);
	      /* ck.valFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_ref[k*nDOF_trial_element],w); */
	      //get the solution gradients
	      ck.gradFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],p_grad_trial,grad_vosStar);
	      ck.gradFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_u);
	      ck.gradFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_v);
	      /* ck.gradFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial,grad_w); */
	      //precalculate test function products with integration weights
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  p_test_dV[j] = p_test_ref[k*nDOF_trial_element+j]*dV;
		  vel_test_dV[j] = vel_test_ref[k*nDOF_trial_element+j]*dV;
		  for (int I=0;I<nSpace;I++)
		    {
		      p_grad_test_dV[j*nSpace+I]   = p_grad_trial[j*nSpace+I]*dV;//cek warning won't work for Petrov-Galerkin
		      vel_grad_test_dV[j*nSpace+I] = vel_grad_trial[j*nSpace+I]*dV;//cek warning won't work for Petrov-Galerkin}
		    }
		}
              //cek hack
              double div_mesh_velocity=0.0;
              int NDOF_MESH_TRIAL_ELEMENT=3;
              for (int j=0;j<NDOF_MESH_TRIAL_ELEMENT;j++)
                {
                  int eN_j=eN*NDOF_MESH_TRIAL_ELEMENT+j;
                  div_mesh_velocity +=
                    mesh_velocity_dof[mesh_l2g[eN_j]*3+0]*vel_grad_trial[j*2+0] +
                    mesh_velocity_dof[mesh_l2g[eN_j]*3+1]*vel_grad_trial[j*2+1];
                }
              div_mesh_velocity = DM3*div_mesh_velocity + (1.0-DM3)*alphaBDF*(dV-q_dV_last[eN_k])/dV;
	      //
	      //VRANS
	      vos = q_vos[eN_k];
	      //
	      //
	      //calculate pde coefficients and derivatives at quadrature points
	      //
	      double eddy_viscosity(0.);//not really interested in saving eddy_viscosity in jacobian
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   vf[eN_k],
				   phi[eN_k],
				   &normal_phi[eN_k_nSpace],
				   kappa_phi[eN_k],
				   //VRANS
				   q_vos[eN_k],
				   //
				   q_p_fluid[eN_k],
				   &q_grad_p_fluid[eN_k_nSpace],
				   vosStar,
                                   grad_vosStar,
                                   grad_u,
				   grad_v,
				   grad_w,
				   u,
				   v,
				   w,
				   eddy_viscosity,
				   mom_u_acc,
				   dmom_u_acc_u,
				   mom_v_acc,
				   dmom_v_acc_v,
				   mom_w_acc,
				   dmom_w_acc_w,
				   mass_adv,
				   dmass_adv_u,
				   dmass_adv_v,
				   dmass_adv_w,
				   mom_u_adv,
				   dmom_u_adv_u,
				   dmom_u_adv_v,
				   dmom_u_adv_w,
				   mom_v_adv,
				   dmom_v_adv_u,
				   dmom_v_adv_v,
				   dmom_v_adv_w,
				   mom_w_adv,
				   dmom_w_adv_u,
				   dmom_w_adv_v,
				   dmom_w_adv_w,
				   mom_uu_diff_ten,
				   mom_vv_diff_ten,
				   mom_ww_diff_ten,
				   mom_uv_diff_ten,
				   mom_uw_diff_ten,
				   mom_vu_diff_ten,
				   mom_vw_diff_ten,
				   mom_wu_diff_ten,
				   mom_wv_diff_ten,
				   mom_u_source,
				   mom_v_source,
				   mom_w_source,
				   mom_u_ham,
				   dmom_u_ham_grad_p,
				   mom_v_ham,
				   dmom_v_ham_grad_p,
				   mom_w_ham,
				   dmom_w_ham_grad_p);          
	      //VRANS
	      mass_source = q_mass_source[eN_k];
	      //todo: decide if these should be lagged or not
	      updateDarcyForchheimerTerms_Ergun(/* linearDragFactor, */
						/* nonlinearDragFactor, */
						/* vos, */
						/* meanGrainSize, */
						q_dragAlpha[eN_k],
						q_dragBeta[eN_k],
						eps_rho,
						eps_mu,
						rho_0,
						nu_0,
						rho_1,
						nu_1,
						useVF,
						vf[eN_k],
						phi[eN_k],
						u,//q_velocity_sge[eN_k_nSpace+0],//u
						v,//q_velocity_sge[eN_k_nSpace+1],//v
						w,//q_velocity_sge[eN_k_nSpace+2],//w
						eps_solid[elementFlags[eN]],
						q_vos[eN_k],
						q_velocity_fluid[eN_k_nSpace+0],
						q_velocity_fluid[eN_k_nSpace+1],
						q_velocity_fluid[eN_k_nSpace+2],
						mom_u_source,
						mom_v_source,
						mom_w_source,
						dmom_u_source,
						dmom_v_source,
						dmom_w_source);
	      //Turbulence closure model
	      if (turbulenceClosureModel >= 3)
		{
		  const double c_mu = 0.09;//mwf hack 
		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  vf[eN_k],
					  phi[eN_k],
					  vos,
					  c_mu, //mwf hack
					  q_turb_var_0[eN_k],
					  q_turb_var_1[eN_k],
					  &q_turb_var_grad_0[eN_k_nSpace],
					  eddy_viscosity,
					  mom_uu_diff_ten,
					  mom_vv_diff_ten,
					  mom_ww_diff_ten,
					  mom_uv_diff_ten,
					  mom_uw_diff_ten,
					  mom_vu_diff_ten,
					  mom_vw_diff_ten,
					  mom_wu_diff_ten,
					  mom_wv_diff_ten,
					  mom_u_source,
					  mom_v_source,
					  mom_w_source);					  

		}
	      //
	      //
	      //moving mesh
	      //
	      mom_u_adv[0] -= MOVING_DOMAIN*mom_u_acc*xt;
	      mom_u_adv[1] -= MOVING_DOMAIN*mom_u_acc*yt;
	      /* mom_u_adv[2] -= MOVING_DOMAIN*mom_u_acc*zt; */
	      dmom_u_adv_u[0] -= MOVING_DOMAIN*dmom_u_acc_u*xt;
	      dmom_u_adv_u[1] -= MOVING_DOMAIN*dmom_u_acc_u*yt;
	      /* dmom_u_adv_u[2] -= MOVING_DOMAIN*dmom_u_acc_u*zt; */

	      mom_v_adv[0] -= MOVING_DOMAIN*mom_v_acc*xt;
	      mom_v_adv[1] -= MOVING_DOMAIN*mom_v_acc*yt;
	      /* mom_v_adv[2] -= MOVING_DOMAIN*mom_v_acc*zt; */
	      dmom_v_adv_v[0] -= MOVING_DOMAIN*dmom_v_acc_v*xt;
	      dmom_v_adv_v[1] -= MOVING_DOMAIN*dmom_v_acc_v*yt;
	      /* dmom_v_adv_v[2] -= MOVING_DOMAIN*dmom_v_acc_v*zt; */

	      /* mom_w_adv[0] -= MOVING_DOMAIN*mom_w_acc*xt; */
	      /* mom_w_adv[1] -= MOVING_DOMAIN*mom_w_acc*yt; */
	      /* mom_w_adv[2] -= MOVING_DOMAIN*mom_w_acc*zt; */
	      /* dmom_w_adv_w[0] -= MOVING_DOMAIN*dmom_w_acc_w*xt; */
	      /* dmom_w_adv_w[1] -= MOVING_DOMAIN*dmom_w_acc_w*yt; */
	      /* dmom_w_adv_w[2] -= MOVING_DOMAIN*dmom_w_acc_w*zt; */
	      //
	      //calculate time derivatives
	      //
	      ck.bdf(alphaBDF,
		     q_mom_u_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV,
		     mom_u_acc,
		     dmom_u_acc_u,
		     mom_u_acc_t,
		     dmom_u_acc_u_t);
	      ck.bdf(alphaBDF,
		     q_mom_v_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV,
		     mom_v_acc,
		     dmom_v_acc_v,
		     mom_v_acc_t,
		     dmom_v_acc_v_t);
	      /* ck.bdf(alphaBDF, */
	      /* 	     q_mom_w_acc_beta_bdf[eN_k]*q_dV_last[eN_k]/dV, */
	      /* 	     mom_w_acc, */
	      /* 	     dmom_w_acc_w, */
	      /* 	     mom_w_acc_t, */
	      /* 	     dmom_w_acc_w_t); */
	      //
	      //calculate subgrid error contribution to the Jacobian (strong residual, adjoint, jacobian of strong residual)
	      //
              dmom_adv_sge[0] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+0] - MOVING_DOMAIN*xt);
              dmom_adv_sge[1] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+1] - MOVING_DOMAIN*yt);
              /* dmom_adv_sge[2] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+2] - MOVING_DOMAIN*zt); */
	      //
	      //calculate strong residual
	      //
	      pdeResidual_p = ck.Advection_strong(dmass_adv_u,grad_u) +
		ck.Advection_strong(dmass_adv_v,grad_v) +
		/* ck.Advection_strong(dmass_adv_w,grad_w) + */
                DM2*MOVING_DOMAIN*ck.Reaction_strong(alphaBDF*(dV-q_dV_last[eN_k])/dV - div_mesh_velocity) +
                //VRANS
		ck.Reaction_strong(mass_source);
		//
	      
	      pdeResidual_u = ck.Mass_strong(mom_u_acc_t) +
		ck.Advection_strong(dmom_adv_sge,grad_u) +
		ck.Hamiltonian_strong(dmom_u_ham_grad_p,grad_vosStar) +
		ck.Reaction_strong(mom_u_source) -
                ck.Reaction_strong(u*div_mesh_velocity);
	  
	      pdeResidual_v = ck.Mass_strong(mom_v_acc_t) +
		ck.Advection_strong(dmom_adv_sge,grad_v) +
		ck.Hamiltonian_strong(dmom_v_ham_grad_p,grad_vosStar) + 
		ck.Reaction_strong(mom_v_source)  - 
                ck.Reaction_strong(v*div_mesh_velocity);
	  
	      /* pdeResidual_w = ck.Mass_strong(mom_w_acc_t) +  */
	      /*   ck.Advection_strong(dmom_adv_sge,grad_w) + */
	      /*   ck.Hamiltonian_strong(dmom_w_ham_grad_p,grad_vosStar) + */
	      /*   ck.Reaction_strong(mom_w_source) -  */
              /*   ck.Reaction_strong(w*div_mesh_velocity); */

	      //calculate the Jacobian of strong residual
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  register int j_nSpace = j*nSpace;
		  dpdeResidual_p_u[j]=ck.AdvectionJacobian_strong(dmass_adv_u,&vel_grad_trial[j_nSpace]);
		  dpdeResidual_p_v[j]=ck.AdvectionJacobian_strong(dmass_adv_v,&vel_grad_trial[j_nSpace]);
		  /* dpdeResidual_p_w[j]=ck.AdvectionJacobian_strong(dmass_adv_w,&vel_grad_trial[j_nSpace]); */

		  dpdeResidual_u_p[j]=ck.HamiltonianJacobian_strong(dmom_u_ham_grad_p,&p_grad_trial[j_nSpace]);
		  dpdeResidual_u_u[j]=ck.MassJacobian_strong(dmom_u_acc_u_t,vel_trial_ref[k*nDOF_trial_element+j]) +
		    ck.AdvectionJacobian_strong(dmom_adv_sge,&vel_grad_trial[j_nSpace]) -
                    ck.ReactionJacobian_strong(div_mesh_velocity,vel_trial_ref[k*nDOF_trial_element+j]);
	      
		  dpdeResidual_v_p[j]=ck.HamiltonianJacobian_strong(dmom_v_ham_grad_p,&p_grad_trial[j_nSpace]);
		  dpdeResidual_v_v[j]=ck.MassJacobian_strong(dmom_v_acc_v_t,vel_trial_ref[k*nDOF_trial_element+j]) +
		    ck.AdvectionJacobian_strong(dmom_adv_sge,&vel_grad_trial[j_nSpace]) -
                    ck.ReactionJacobian_strong(div_mesh_velocity,vel_trial_ref[k*nDOF_trial_element+j]);
	      
		  /* dpdeResidual_w_p[j]=ck.HamiltonianJacobian_strong(dmom_w_ham_grad_p,&p_grad_trial[j_nSpace]); */
		  /* dpdeResidual_w_w[j]=ck.MassJacobian_strong(dmom_w_acc_w_t,vel_trial_ref[k*nDOF_trial_element+j]) +  */
		  /*   ck.AdvectionJacobian_strong(dmom_adv_sge,&vel_grad_trial[j_nSpace]) -
                    ck.ReactionJacobian_strong(div_mesh_velocity,vel_trial_ref[k*nDOF_trial_element+j]); */

		  //VRANS account for drag terms, diagonal only here ... decide if need off diagonal terms too
		  dpdeResidual_u_u[j]+= ck.ReactionJacobian_strong(dmom_u_source[0],vel_trial_ref[k*nDOF_trial_element+j]);
		  dpdeResidual_v_v[j]+= ck.ReactionJacobian_strong(dmom_v_source[1],vel_trial_ref[k*nDOF_trial_element+j]);
		  /* dpdeResidual_w_w[j]+= ck.ReactionJacobian_strong(dmom_w_source[2],vel_trial_ref[k*nDOF_trial_element+j]); */
		  //
		}
	      //calculate tau and tau*Res
	      //cek debug
	      double tmpR=dmom_u_acc_u_t + dmom_u_source[0];
	      calculateSubgridError_tau(hFactor,
					elementDiameter[eN],
					tmpR,//dmom_u_acc_u_t,
					dmom_u_acc_u,
					dmom_adv_sge,
					mom_uu_diff_ten[1],
					dmom_u_ham_grad_p[0],
					tau_v0,
					tau_p0,
					q_cfl[eN_k]);
					
	      calculateSubgridError_tau(Ct_sge,Cd_sge,
			                G,G_dd_G,tr_G,
					tmpR,//dmom_u_acc_u_t,
					dmom_adv_sge,
					mom_uu_diff_ten[1],
                                        dmom_u_ham_grad_p[0],					
					tau_v1,
					tau_p1,
					q_cfl[eN_k]);					
					
					
	      tau_v = useMetrics*tau_v1+(1.0-useMetrics)*tau_v0;
	      tau_p = useMetrics*tau_p1+(1.0-useMetrics)*tau_p0;					
					
	      calculateSubgridError_tauRes(tau_p,
					   tau_v,
					   pdeResidual_p,
					   pdeResidual_u,
					   pdeResidual_v,
					   pdeResidual_w,
					   subgridError_p,
					   subgridError_u,
					   subgridError_v,
					   subgridError_w);	      
	      
	      calculateSubgridErrorDerivatives_tauRes(tau_p,
						      tau_v,
						      dpdeResidual_p_u,
						      dpdeResidual_p_v,
						      dpdeResidual_p_w,
						      dpdeResidual_u_p,
						      dpdeResidual_u_u,
						      dpdeResidual_v_p,
						      dpdeResidual_v_v,
						      dpdeResidual_w_p,
						      dpdeResidual_w_w,
						      dsubgridError_p_u,
						      dsubgridError_p_v,
						      dsubgridError_p_w,
						      dsubgridError_u_p,
						      dsubgridError_u_u,
						      dsubgridError_v_p,
						      dsubgridError_v_v,
						      dsubgridError_w_p,
						      dsubgridError_w_w);
	      // velocity used in adjoint (VMS or RBLES, with or without lagging the grid scale velocity)
	      dmom_adv_star[0] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+0] - MOVING_DOMAIN*xt + useRBLES*subgridError_u);
	      dmom_adv_star[1] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+1] - MOVING_DOMAIN*yt + useRBLES*subgridError_v);
	      /* dmom_adv_star[2] = dmom_u_acc_u*(q_velocity_sge[eN_k_nSpace+2] - MOVING_DOMAIN*zt + useRBLES*subgridError_w); */
          
	      //calculate the adjoint times the test functions
	      for (int i=0;i<nDOF_test_element;i++)
		{
		  register int i_nSpace = i*nSpace;
		  Lstar_u_p[i]=ck.Advection_adjoint(dmass_adv_u,&p_grad_test_dV[i_nSpace]);
		  Lstar_v_p[i]=ck.Advection_adjoint(dmass_adv_v,&p_grad_test_dV[i_nSpace]);
		  /* Lstar_w_p[i]=ck.Advection_adjoint(dmass_adv_w,&p_grad_test_dV[i_nSpace]); */
		  Lstar_u_u[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]);
		  Lstar_v_v[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]);
		  /* Lstar_w_w[i]=ck.Advection_adjoint(dmom_adv_star,&vel_grad_test_dV[i_nSpace]); */
		  Lstar_p_u[i]=ck.Hamiltonian_adjoint(dmom_u_ham_grad_p,&vel_grad_test_dV[i_nSpace]);
		  Lstar_p_v[i]=ck.Hamiltonian_adjoint(dmom_v_ham_grad_p,&vel_grad_test_dV[i_nSpace]);
		  /* Lstar_p_w[i]=ck.Hamiltonian_adjoint(dmom_w_ham_grad_p,&vel_grad_test_dV[i_nSpace]); */
		  //VRANS account for drag terms, diagonal only here ... decide if need off diagonal terms too
		  Lstar_u_u[i]+=ck.Reaction_adjoint(dmom_u_source[0],vel_test_dV[i]);
		  Lstar_v_v[i]+=ck.Reaction_adjoint(dmom_v_source[1],vel_test_dV[i]);
		  /* Lstar_w_w[i]+=ck.Reaction_adjoint(dmom_w_source[2],vel_test_dV[i]); */
		}

              // Assumes non-lagged subgrid velocity
	      dmom_u_adv_u[0] += dmom_u_acc_u*(useRBLES*subgridError_u);  	   
	      dmom_u_adv_u[1] += dmom_u_acc_u*(useRBLES*subgridError_v); 
              /* dmom_u_adv_u[2] += dmom_u_acc_u*(useRBLES*subgridError_w);  */
         
	      dmom_v_adv_v[0] += dmom_u_acc_u*(useRBLES*subgridError_u);   	   
	      dmom_v_adv_v[1] += dmom_u_acc_u*(useRBLES*subgridError_v); 
              /* dmom_v_adv_v[2] += dmom_u_acc_u*(useRBLES*subgridError_w);  */
         
	      /* dmom_w_adv_w[0] += dmom_u_acc_u*(useRBLES*subgridError_u);   	    */
	      /* dmom_w_adv_w[1] += dmom_u_acc_u*(useRBLES*subgridError_v);  */
              /* dmom_w_adv_w[2] += dmom_u_acc_u*(useRBLES*subgridError_w);  */


	      //cek todo add RBLES terms consistent to residual modifications or ignore the partials w.r.t the additional RBLES terms
	      for(int i=0;i<nDOF_test_element;i++)
		{
		  register int i_nSpace = i*nSpace;
		  for(int j=0;j<nDOF_trial_element;j++) 
		    { 
		      register int j_nSpace = j*nSpace;
		      elementJacobian_p_p[i][j] += ck.SubgridErrorJacobian(dsubgridError_u_p[j],Lstar_u_p[i]) + 
			ck.SubgridErrorJacobian(dsubgridError_v_p[j],Lstar_v_p[i]);// + 
			/* ck.SubgridErrorJacobian(dsubgridError_w_p[j],Lstar_w_p[i]);  */

		      elementJacobian_p_u[i][j] += ck.AdvectionJacobian_weak(dmass_adv_u,vel_trial_ref[k*nDOF_trial_element+j],&p_grad_test_dV[i_nSpace]) + 
			ck.SubgridErrorJacobian(dsubgridError_u_u[j],Lstar_u_p[i]); 
		      elementJacobian_p_v[i][j] += ck.AdvectionJacobian_weak(dmass_adv_v,vel_trial_ref[k*nDOF_trial_element+j],&p_grad_test_dV[i_nSpace]) + 
			ck.SubgridErrorJacobian(dsubgridError_v_v[j],Lstar_v_p[i]); 
		      /* elementJacobian_p_w[i][j] += ck.AdvectionJacobian_weak(dmass_adv_w,vel_trial_ref[k*nDOF_trial_element+j],&p_grad_test_dV[i_nSpace]) +  */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_w_w[j],Lstar_w_p[i]);  */

		      elementJacobian_u_p[i][j] += ck.HamiltonianJacobian_weak(dmom_u_ham_grad_p,&p_grad_trial[j_nSpace],vel_test_dV[i]) + 
			ck.SubgridErrorJacobian(dsubgridError_u_p[j],Lstar_u_u[i]); 
		      elementJacobian_u_u[i][j] += ck.MassJacobian_weak(dmom_u_acc_u_t,vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + 
			ck.AdvectionJacobian_weak(dmom_u_adv_u,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +
			ck.SimpleDiffusionJacobian_weak(sdInfo_u_u_rowptr,sdInfo_u_u_colind,mom_uu_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) + 
			//VRANS
			ck.ReactionJacobian_weak(dmom_u_source[0],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) +
			//
			ck.SubgridErrorJacobian(dsubgridError_p_u[j],Lstar_p_u[i]) + 
			ck.SubgridErrorJacobian(dsubgridError_u_u[j],Lstar_u_u[i]) + 
			ck.NumericalDiffusionJacobian(q_numDiff_u_last[eN_k],&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]); 
		      elementJacobian_u_v[i][j] += ck.AdvectionJacobian_weak(dmom_u_adv_v,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) + 
			ck.SimpleDiffusionJacobian_weak(sdInfo_u_v_rowptr,sdInfo_u_v_colind,mom_uv_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) + 
			//VRANS
			ck.ReactionJacobian_weak(dmom_u_source[1],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) +
			//
			ck.SubgridErrorJacobian(dsubgridError_p_v[j],Lstar_p_u[i]); 
		      /* elementJacobian_u_w[i][j] += ck.AdvectionJacobian_weak(dmom_u_adv_w,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	ck.SimpleDiffusionJacobian_weak(sdInfo_u_w_rowptr,sdInfo_u_w_colind,mom_uw_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	//VRANS */
		      /* 	ck.ReactionJacobian_weak(dmom_u_source[2],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + */
		      /* 	// */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_p_w[j],Lstar_p_u[i]);  */

		      elementJacobian_v_p[i][j] += ck.HamiltonianJacobian_weak(dmom_v_ham_grad_p,&p_grad_trial[j_nSpace],vel_test_dV[i]) + 
			ck.SubgridErrorJacobian(dsubgridError_v_p[j],Lstar_v_v[i]); 
		      elementJacobian_v_u[i][j] += ck.AdvectionJacobian_weak(dmom_v_adv_u,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) + 
			ck.SimpleDiffusionJacobian_weak(sdInfo_v_u_rowptr,sdInfo_v_u_colind,mom_vu_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) + 
			//VRANS
			ck.ReactionJacobian_weak(dmom_v_source[0],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) +
			//
			ck.SubgridErrorJacobian(dsubgridError_p_u[j],Lstar_p_v[i]);
		      elementJacobian_v_v[i][j] += ck.MassJacobian_weak(dmom_v_acc_v_t,vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + 
			ck.AdvectionJacobian_weak(dmom_v_adv_v,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +
			ck.SimpleDiffusionJacobian_weak(sdInfo_v_v_rowptr,sdInfo_v_v_colind,mom_vv_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) + 
			//VRANS
			ck.ReactionJacobian_weak(dmom_v_source[1],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) +
			//
			ck.SubgridErrorJacobian(dsubgridError_p_v[j],Lstar_p_v[i]) +
			ck.SubgridErrorJacobian(dsubgridError_v_v[j],Lstar_v_v[i]) + 
			ck.NumericalDiffusionJacobian(q_numDiff_v_last[eN_k],&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]); 
		      /* elementJacobian_v_w[i][j] += ck.AdvectionJacobian_weak(dmom_v_adv_w,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +   */
		      /* 	ck.SimpleDiffusionJacobian_weak(sdInfo_v_w_rowptr,sdInfo_v_w_colind,mom_vw_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	//VRANS */
		      /* 	ck.ReactionJacobian_weak(dmom_v_source[2],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + */
		      /* 	// */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_p_w[j],Lstar_p_v[i]); */

		      /* elementJacobian_w_p[i][j] += ck.HamiltonianJacobian_weak(dmom_w_ham_grad_p,&p_grad_trial[j_nSpace],vel_test_dV[i]) +  */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_w_p[j],Lstar_w_w[i]);  */
		      /* elementJacobian_w_u[i][j] += ck.AdvectionJacobian_weak(dmom_w_adv_u,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +   */
		      /* 	ck.SimpleDiffusionJacobian_weak(sdInfo_w_u_rowptr,sdInfo_w_u_colind,mom_wu_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	//VRANS */
		      /* 	ck.ReactionJacobian_weak(dmom_w_source[0],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + */
		      /* 	// */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_p_u[j],Lstar_p_w[i]);  */
		      /* elementJacobian_w_v[i][j] += ck.AdvectionJacobian_weak(dmom_w_adv_v,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	ck.SimpleDiffusionJacobian_weak(sdInfo_w_v_rowptr,sdInfo_w_v_colind,mom_wv_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	//VRANS */
		      /* 	ck.ReactionJacobian_weak(dmom_w_source[1],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + */
		      /* 	// */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_p_v[j],Lstar_p_w[i]);  */
		      /* elementJacobian_w_w[i][j] += ck.MassJacobian_weak(dmom_w_acc_w_t,vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) +  */
		      /* 	ck.AdvectionJacobian_weak(dmom_w_adv_w,vel_trial_ref[k*nDOF_trial_element+j],&vel_grad_test_dV[i_nSpace]) +   */
		      /* 	ck.SimpleDiffusionJacobian_weak(sdInfo_w_w_rowptr,sdInfo_w_w_colind,mom_ww_diff_ten,&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]) +  */
		      /* 	//VRANS */
		      /* 	ck.ReactionJacobian_weak(dmom_w_source[2],vel_trial_ref[k*nDOF_trial_element+j],vel_test_dV[i]) + */
		      /* 	// */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_p_w[j],Lstar_p_w[i]) +  */
		      /* 	ck.SubgridErrorJacobian(dsubgridError_w_w[j],Lstar_w_w[i]) +  */
		      /* 	ck.NumericalDiffusionJacobian(q_numDiff_w_last[eN_k],&vel_grad_trial[j_nSpace],&vel_grad_test_dV[i_nSpace]);  */
		    }//j
		}//i
	    }//k
	  //
	  //load into element Jacobian into global Jacobian
	  //
	  for (int i=0;i<nDOF_test_element;i++)
	    {
	      register int eN_i = eN*nDOF_test_element+i;
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  register int eN_i_j = eN_i*nDOF_trial_element+j;
		  globalJacobian[csrRowIndeces_p_p[eN_i] + csrColumnOffsets_p_p[eN_i_j]] += elementJacobian_p_p[i][j];
		  globalJacobian[csrRowIndeces_p_u[eN_i] + csrColumnOffsets_p_u[eN_i_j]] += elementJacobian_p_u[i][j];
		  globalJacobian[csrRowIndeces_p_v[eN_i] + csrColumnOffsets_p_v[eN_i_j]] += elementJacobian_p_v[i][j];
		  /* globalJacobian[csrRowIndeces_p_w[eN_i] + csrColumnOffsets_p_w[eN_i_j]] += elementJacobian_p_w[i][j]; */

		  globalJacobian[csrRowIndeces_u_p[eN_i] + csrColumnOffsets_u_p[eN_i_j]] += elementJacobian_u_p[i][j];
		  globalJacobian[csrRowIndeces_u_u[eN_i] + csrColumnOffsets_u_u[eN_i_j]] += elementJacobian_u_u[i][j];
		  globalJacobian[csrRowIndeces_u_v[eN_i] + csrColumnOffsets_u_v[eN_i_j]] += elementJacobian_u_v[i][j];
		  /* globalJacobian[csrRowIndeces_u_w[eN_i] + csrColumnOffsets_u_w[eN_i_j]] += elementJacobian_u_w[i][j]; */

		  globalJacobian[csrRowIndeces_v_p[eN_i] + csrColumnOffsets_v_p[eN_i_j]] += elementJacobian_v_p[i][j];
		  globalJacobian[csrRowIndeces_v_u[eN_i] + csrColumnOffsets_v_u[eN_i_j]] += elementJacobian_v_u[i][j];
		  globalJacobian[csrRowIndeces_v_v[eN_i] + csrColumnOffsets_v_v[eN_i_j]] += elementJacobian_v_v[i][j];
		  /* globalJacobian[csrRowIndeces_v_w[eN_i] + csrColumnOffsets_v_w[eN_i_j]] += elementJacobian_v_w[i][j]; */

		  /* globalJacobian[csrRowIndeces_w_p[eN_i] + csrColumnOffsets_w_p[eN_i_j]] += elementJacobian_w_p[i][j]; */
		  /* globalJacobian[csrRowIndeces_w_u[eN_i] + csrColumnOffsets_w_u[eN_i_j]] += elementJacobian_w_u[i][j]; */
		  /* globalJacobian[csrRowIndeces_w_v[eN_i] + csrColumnOffsets_w_v[eN_i_j]] += elementJacobian_w_v[i][j]; */
		  /* globalJacobian[csrRowIndeces_w_w[eN_i] + csrColumnOffsets_w_w[eN_i_j]] += elementJacobian_w_w[i][j]; */
		}//j
	    }//i
	}//elements
      //
      //loop over exterior element boundaries to compute the surface integrals and load them into the global Jacobian
      //
      for (int ebNE = 0; ebNE < nExteriorElementBoundaries_global; ebNE++) 
	{ 
	  register int ebN = exteriorElementBoundariesArray[ebNE],
	    eN  = elementBoundaryElementsArray[ebN*2+0],
	    eN_nDOF_trial_element = eN*nDOF_trial_element,
	    ebN_local = elementBoundaryLocalElementBoundariesArray[ebN*2+0];
	  register double eps_rho,eps_mu;
	  for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++) 
	    { 
	      register int ebNE_kb = ebNE*nQuadraturePoints_elementBoundary+kb,
		ebNE_kb_nSpace = ebNE_kb*nSpace,
		ebN_local_kb = ebN_local*nQuadraturePoints_elementBoundary+kb,
		ebN_local_kb_nSpace = ebN_local_kb*nSpace;

	      register double vosStar_ext=0.0,
		u_ext=0.0,
		v_ext=0.0,
		w_ext=0.0,
		grad_vosStar_ext[nSpace],
		grad_u_ext[nSpace],
		grad_v_ext[nSpace],
		grad_w_ext[nSpace],
		mom_u_acc_ext=0.0,
		dmom_u_acc_u_ext=0.0,
		mom_v_acc_ext=0.0,
		dmom_v_acc_v_ext=0.0,
		mom_w_acc_ext=0.0,
		dmom_w_acc_w_ext=0.0,
		mass_adv_ext[nSpace],
		dmass_adv_u_ext[nSpace],
		dmass_adv_v_ext[nSpace],
		dmass_adv_w_ext[nSpace],
		mom_u_adv_ext[nSpace],
		dmom_u_adv_u_ext[nSpace],
		dmom_u_adv_v_ext[nSpace],
		dmom_u_adv_w_ext[nSpace],
		mom_v_adv_ext[nSpace],
		dmom_v_adv_u_ext[nSpace],
		dmom_v_adv_v_ext[nSpace],
		dmom_v_adv_w_ext[nSpace],
		mom_w_adv_ext[nSpace],
		dmom_w_adv_u_ext[nSpace],
		dmom_w_adv_v_ext[nSpace],
		dmom_w_adv_w_ext[nSpace],
		mom_uu_diff_ten_ext[nSpace],
		mom_vv_diff_ten_ext[nSpace],
		mom_ww_diff_ten_ext[nSpace],
		mom_uv_diff_ten_ext[1],
		mom_uw_diff_ten_ext[1],
		mom_vu_diff_ten_ext[1],
		mom_vw_diff_ten_ext[1],
		mom_wu_diff_ten_ext[1],
		mom_wv_diff_ten_ext[1],
		mom_u_source_ext=0.0,
		mom_v_source_ext=0.0,
		mom_w_source_ext=0.0,
		mom_u_ham_ext=0.0,
		dmom_u_ham_grad_p_ext[nSpace],
		mom_v_ham_ext=0.0,
		dmom_v_ham_grad_p_ext[nSpace],
		mom_w_ham_ext=0.0,
		dmom_w_ham_grad_p_ext[nSpace],
		dmom_u_adv_p_ext[nSpace],
		dmom_v_adv_p_ext[nSpace],
		dmom_w_adv_p_ext[nSpace],
		dflux_mass_u_ext=0.0,
		dflux_mass_v_ext=0.0,
		dflux_mass_w_ext=0.0,
		dflux_mom_u_adv_p_ext=0.0,
		dflux_mom_u_adv_u_ext=0.0,
		dflux_mom_u_adv_v_ext=0.0,
		dflux_mom_u_adv_w_ext=0.0,
		dflux_mom_v_adv_p_ext=0.0,
		dflux_mom_v_adv_u_ext=0.0,
		dflux_mom_v_adv_v_ext=0.0,
		dflux_mom_v_adv_w_ext=0.0,
		dflux_mom_w_adv_p_ext=0.0,
		dflux_mom_w_adv_u_ext=0.0,
		dflux_mom_w_adv_v_ext=0.0,
		dflux_mom_w_adv_w_ext=0.0,
		bc_vosStar_ext=0.0,
		bc_u_ext=0.0,
		bc_v_ext=0.0,
		bc_w_ext=0.0,
		bc_mom_u_acc_ext=0.0,
		bc_dmom_u_acc_u_ext=0.0,
		bc_mom_v_acc_ext=0.0,
		bc_dmom_v_acc_v_ext=0.0,
		bc_mom_w_acc_ext=0.0,
		bc_dmom_w_acc_w_ext=0.0,
		bc_mass_adv_ext[nSpace],
		bc_dmass_adv_u_ext[nSpace],
		bc_dmass_adv_v_ext[nSpace],
		bc_dmass_adv_w_ext[nSpace],
		bc_mom_u_adv_ext[nSpace],
		bc_dmom_u_adv_u_ext[nSpace],
		bc_dmom_u_adv_v_ext[nSpace],
		bc_dmom_u_adv_w_ext[nSpace],
		bc_mom_v_adv_ext[nSpace],
		bc_dmom_v_adv_u_ext[nSpace],
		bc_dmom_v_adv_v_ext[nSpace],
		bc_dmom_v_adv_w_ext[nSpace],
		bc_mom_w_adv_ext[nSpace],
		bc_dmom_w_adv_u_ext[nSpace],
		bc_dmom_w_adv_v_ext[nSpace],
		bc_dmom_w_adv_w_ext[nSpace],
		bc_mom_uu_diff_ten_ext[nSpace],
		bc_mom_vv_diff_ten_ext[nSpace],
		bc_mom_ww_diff_ten_ext[nSpace],
		bc_mom_uv_diff_ten_ext[1],
		bc_mom_uw_diff_ten_ext[1],
		bc_mom_vu_diff_ten_ext[1],
		bc_mom_vw_diff_ten_ext[1],
		bc_mom_wu_diff_ten_ext[1],
		bc_mom_wv_diff_ten_ext[1],
		bc_mom_u_source_ext=0.0,
		bc_mom_v_source_ext=0.0,
		bc_mom_w_source_ext=0.0,
		bc_mom_u_ham_ext=0.0,
		bc_dmom_u_ham_grad_p_ext[nSpace],
		bc_mom_v_ham_ext=0.0,
		bc_dmom_v_ham_grad_p_ext[nSpace],
		bc_mom_w_ham_ext=0.0,
		bc_dmom_w_ham_grad_p_ext[nSpace],
		fluxJacobian_p_p[nDOF_trial_element],
		fluxJacobian_p_u[nDOF_trial_element],
		fluxJacobian_p_v[nDOF_trial_element],
		fluxJacobian_p_w[nDOF_trial_element],
		fluxJacobian_u_p[nDOF_trial_element],
		fluxJacobian_u_u[nDOF_trial_element],
		fluxJacobian_u_v[nDOF_trial_element],
		fluxJacobian_u_w[nDOF_trial_element],
		fluxJacobian_v_p[nDOF_trial_element],
		fluxJacobian_v_u[nDOF_trial_element],
		fluxJacobian_v_v[nDOF_trial_element],
		fluxJacobian_v_w[nDOF_trial_element],
		fluxJacobian_w_p[nDOF_trial_element],
		fluxJacobian_w_u[nDOF_trial_element],
		fluxJacobian_w_v[nDOF_trial_element],
		fluxJacobian_w_w[nDOF_trial_element],
		jac_ext[nSpace*nSpace],
		jacDet_ext,
		jacInv_ext[nSpace*nSpace],
		boundaryJac[nSpace*(nSpace-1)],
		metricTensor[(nSpace-1)*(nSpace-1)],
		metricTensorDetSqrt,
		p_grad_trial_trace[nDOF_trial_element*nSpace],
		vel_grad_trial_trace[nDOF_trial_element*nSpace],
		dS,
		p_test_dS[nDOF_test_element],
		vel_test_dS[nDOF_test_element],
		normal[2],
		x_ext,y_ext,z_ext,xt_ext,yt_ext,zt_ext,integralScaling,
		vel_grad_test_dS[nDOF_trial_element*nSpace],
		//VRANS
		vos_ext,
		//
		G[nSpace*nSpace],G_dd_G,tr_G,h_phi,h_penalty,penalty;
	      ck.calculateMapping_elementBoundary(eN,
						  ebN_local,
						  kb,
						  ebN_local_kb,
						  mesh_dof,
						  mesh_l2g,
						  mesh_trial_trace_ref,
						  mesh_grad_trial_trace_ref,
						  boundaryJac_ref,
						  jac_ext,
						  jacDet_ext,
						  jacInv_ext,
						  boundaryJac,
						  metricTensor,
						  metricTensorDetSqrt,
						  normal_ref,
						  normal,
						  x_ext,y_ext,z_ext);
	      ck.calculateMappingVelocity_elementBoundary(eN,
							  ebN_local,
							  kb,
							  ebN_local_kb,
							  mesh_velocity_dof,
							  mesh_l2g,
							  mesh_trial_trace_ref,
							  xt_ext,yt_ext,zt_ext,
							  normal,
							  boundaryJac,
							  metricTensor,
							  integralScaling);
	      //dS = ((1.0-MOVING_DOMAIN)*metricTensorDetSqrt + MOVING_DOMAIN*integralScaling)*dS_ref[kb];
	      dS = metricTensorDetSqrt*dS_ref[kb];
	      ck.calculateG(jacInv_ext,G,G_dd_G,tr_G);
	      ck.calculateGScale(G,&ebqe_normal_phi_ext[ebNE_kb_nSpace],h_phi);

	      eps_rho = epsFact_rho*(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);
	      eps_mu  = epsFact_mu *(useMetrics*h_phi+(1.0-useMetrics)*elementDiameter[eN]);

	      //compute shape and solution information
	      //shape
	      ck.gradTrialFromRef(&p_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,p_grad_trial_trace);
	      ck.gradTrialFromRef(&vel_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,vel_grad_trial_trace);
	      //solution and gradients	
	      ck.valFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],&p_trial_trace_ref[ebN_local_kb*nDOF_test_element],vosStar_ext);
	      ck.valFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],u_ext);
	      ck.valFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],v_ext);
	      /* ck.valFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],&vel_trial_trace_ref[ebN_local_kb*nDOF_test_element],w_ext); */
	      ck.gradFromDOF(p_dof,&p_l2g[eN_nDOF_trial_element],p_grad_trial_trace,grad_vosStar_ext);
	      ck.gradFromDOF(u_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_u_ext);
	      ck.gradFromDOF(v_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_v_ext);
	      /* ck.gradFromDOF(w_dof,&vel_l2g[eN_nDOF_trial_element],vel_grad_trial_trace,grad_w_ext); */
	      //precalculate test function products with integration weights
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  p_test_dS[j] = p_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
		  vel_test_dS[j] = vel_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
		  for (int I=0;I<nSpace;I++)
		    vel_grad_test_dS[j*nSpace+I] = vel_grad_trial_trace[j*nSpace+I]*dS;//cek hack, using trial
		}
	      //
	      //load the boundary values
	      //
	      bc_vosStar_ext = isDOFBoundary_p[ebNE_kb]*ebqe_bc_p_ext[ebNE_kb]+(1-isDOFBoundary_p[ebNE_kb])*vosStar_ext;
              //bc values at moving boundaries are specified relative to boundary motion so we need to add it here
	      bc_u_ext = isDOFBoundary_u[ebNE_kb]*(ebqe_bc_u_ext[ebNE_kb] + MOVING_DOMAIN*xt_ext) + (1-isDOFBoundary_u[ebNE_kb])*u_ext;
	      bc_v_ext = isDOFBoundary_v[ebNE_kb]*(ebqe_bc_v_ext[ebNE_kb] + MOVING_DOMAIN*yt_ext) + (1-isDOFBoundary_v[ebNE_kb])*v_ext;
	      /* bc_w_ext = isDOFBoundary_w[ebNE_kb]*(ebqe_bc_w_ext[ebNE_kb] + MOVING_DOMAIN*zt_ext) + (1-isDOFBoundary_w[ebNE_kb])*w_ext; */
	      //VRANS
	      vos_ext = ebqe_vos_ext[ebNE_kb];
	      // 
	      //calculate the internal and external trace of the pde coefficients 
	      // 
	      double eddy_viscosity_ext(0.),bc_eddy_viscosity_ext(0.);//not interested in saving boundary eddy viscosity for now
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   ebqe_vf_ext[ebNE_kb],
				   ebqe_phi_ext[ebNE_kb],
				   &ebqe_normal_phi_ext[ebNE_kb_nSpace],
				   ebqe_kappa_phi_ext[ebNE_kb],
				   //VRANS
				   ebqe_vos_ext[ebNE_kb],
				   //
				   ebqe_p_fluid_ext[ebNE_kb],
				   &ebqe_grad_p_fluid_ext[ebNE_kb_nSpace],
				   vosStar_ext,
                                   grad_vosStar_ext,
                                   grad_u_ext,
				   grad_v_ext,
				   grad_w_ext,
				   u_ext,
				   v_ext,
				   w_ext,
				   eddy_viscosity_ext,
				   mom_u_acc_ext,
				   dmom_u_acc_u_ext,
				   mom_v_acc_ext,
				   dmom_v_acc_v_ext,
				   mom_w_acc_ext,
				   dmom_w_acc_w_ext,
				   mass_adv_ext,
				   dmass_adv_u_ext,
				   dmass_adv_v_ext,
				   dmass_adv_w_ext,
				   mom_u_adv_ext,
				   dmom_u_adv_u_ext,
				   dmom_u_adv_v_ext,
				   dmom_u_adv_w_ext,
				   mom_v_adv_ext,
				   dmom_v_adv_u_ext,
				   dmom_v_adv_v_ext,
				   dmom_v_adv_w_ext,
				   mom_w_adv_ext,
				   dmom_w_adv_u_ext,
				   dmom_w_adv_v_ext,
				   dmom_w_adv_w_ext,
				   mom_uu_diff_ten_ext,
				   mom_vv_diff_ten_ext,
				   mom_ww_diff_ten_ext,
				   mom_uv_diff_ten_ext,
				   mom_uw_diff_ten_ext,
				   mom_vu_diff_ten_ext,
				   mom_vw_diff_ten_ext,
				   mom_wu_diff_ten_ext,
				   mom_wv_diff_ten_ext,
				   mom_u_source_ext,
				   mom_v_source_ext,
				   mom_w_source_ext,
				   mom_u_ham_ext,
				   dmom_u_ham_grad_p_ext,
				   mom_v_ham_ext,
				   dmom_v_ham_grad_p_ext,
				   mom_w_ham_ext,
				   dmom_w_ham_grad_p_ext);          
	      evaluateCoefficients(eps_rho,
				   eps_mu,
				   sigma,
				   rho_0,
				   nu_0,
				   rho_1,
				   nu_1,
				   elementDiameter[eN],
				   smagorinskyConstant,
				   turbulenceClosureModel,
				   g,
				   useVF,
				   bc_ebqe_vf_ext[ebNE_kb],
				   bc_ebqe_phi_ext[ebNE_kb],
				   &ebqe_normal_phi_ext[ebNE_kb_nSpace],
				   ebqe_kappa_phi_ext[ebNE_kb],
				   //VRANS
				   ebqe_vos_ext[ebNE_kb],
				   //
				   ebqe_p_fluid_ext[ebNE_kb],
				   &ebqe_grad_p_fluid_ext[ebNE_kb_nSpace],
				   vosStar_ext,
                                   grad_vosStar_ext,
                                   grad_u_ext,
				   grad_v_ext,
				   grad_w_ext,
				   bc_u_ext,
				   bc_v_ext,
				   bc_w_ext,
				   bc_eddy_viscosity_ext,
				   bc_mom_u_acc_ext,
				   bc_dmom_u_acc_u_ext,
				   bc_mom_v_acc_ext,
				   bc_dmom_v_acc_v_ext,
				   bc_mom_w_acc_ext,
				   bc_dmom_w_acc_w_ext,
				   bc_mass_adv_ext,
				   bc_dmass_adv_u_ext,
				   bc_dmass_adv_v_ext,
				   bc_dmass_adv_w_ext,
				   bc_mom_u_adv_ext,
				   bc_dmom_u_adv_u_ext,
				   bc_dmom_u_adv_v_ext,
				   bc_dmom_u_adv_w_ext,
				   bc_mom_v_adv_ext,
				   bc_dmom_v_adv_u_ext,
				   bc_dmom_v_adv_v_ext,
				   bc_dmom_v_adv_w_ext,
				   bc_mom_w_adv_ext,
				   bc_dmom_w_adv_u_ext,
				   bc_dmom_w_adv_v_ext,
				   bc_dmom_w_adv_w_ext,
				   bc_mom_uu_diff_ten_ext,
				   bc_mom_vv_diff_ten_ext,
				   bc_mom_ww_diff_ten_ext,
				   bc_mom_uv_diff_ten_ext,
				   bc_mom_uw_diff_ten_ext,
				   bc_mom_vu_diff_ten_ext,
				   bc_mom_vw_diff_ten_ext,
				   bc_mom_wu_diff_ten_ext,
				   bc_mom_wv_diff_ten_ext,
				   bc_mom_u_source_ext,
				   bc_mom_v_source_ext,
				   bc_mom_w_source_ext,
				   bc_mom_u_ham_ext,
				   bc_dmom_u_ham_grad_p_ext,
				   bc_mom_v_ham_ext,
				   bc_dmom_v_ham_grad_p_ext,
				   bc_mom_w_ham_ext,
				   bc_dmom_w_ham_grad_p_ext);          
	      //Turbulence closure model
	      if (turbulenceClosureModel >= 3)
		{
		  const double turb_var_grad_0_dummy[2] = {0.,0.};
		  const double c_mu = 0.09;//mwf hack 
		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  ebqe_vf_ext[ebNE_kb],
					  ebqe_phi_ext[ebNE_kb],
					  ebqe_vos_ext[ebNE_kb],
					  c_mu, //mwf hack
					  ebqe_turb_var_0[ebNE_kb],
					  ebqe_turb_var_1[ebNE_kb],
					  turb_var_grad_0_dummy, //not needed
					  eddy_viscosity_ext,
					  mom_uu_diff_ten_ext,
					  mom_vv_diff_ten_ext,
					  mom_ww_diff_ten_ext,
					  mom_uv_diff_ten_ext,
					  mom_uw_diff_ten_ext,
					  mom_vu_diff_ten_ext,
					  mom_vw_diff_ten_ext,
					  mom_wu_diff_ten_ext,
					  mom_wv_diff_ten_ext,
					  mom_u_source_ext,
					  mom_v_source_ext,
					  mom_w_source_ext);					  

		  updateTurbulenceClosure(turbulenceClosureModel,
					  eps_rho,
					  eps_mu,
					  rho_0,
					  nu_0,
					  rho_1,
					  nu_1,
					  useVF,
					  ebqe_vf_ext[ebNE_kb],
					  ebqe_phi_ext[ebNE_kb],
					  ebqe_vos_ext[ebNE_kb],
					  c_mu, //mwf hack
					  ebqe_turb_var_0[ebNE_kb],
					  ebqe_turb_var_1[ebNE_kb],
					  turb_var_grad_0_dummy, //not needed
					  bc_eddy_viscosity_ext,
					  bc_mom_uu_diff_ten_ext,
					  bc_mom_vv_diff_ten_ext,
					  bc_mom_ww_diff_ten_ext,
					  bc_mom_uv_diff_ten_ext,
					  bc_mom_uw_diff_ten_ext,
					  bc_mom_vu_diff_ten_ext,
					  bc_mom_vw_diff_ten_ext,
					  bc_mom_wu_diff_ten_ext,
					  bc_mom_wv_diff_ten_ext,
					  bc_mom_u_source_ext,
					  bc_mom_v_source_ext,
					  bc_mom_w_source_ext);					  
		}
	      //
	      //moving domain
	      //
	      mom_u_adv_ext[0] -= MOVING_DOMAIN*mom_u_acc_ext*xt_ext;
	      mom_u_adv_ext[1] -= MOVING_DOMAIN*mom_u_acc_ext*yt_ext;
	      /* mom_u_adv_ext[2] -= MOVING_DOMAIN*mom_u_acc_ext*zt_ext; */
	      dmom_u_adv_u_ext[0] -= MOVING_DOMAIN*dmom_u_acc_u_ext*xt_ext;
	      dmom_u_adv_u_ext[1] -= MOVING_DOMAIN*dmom_u_acc_u_ext*yt_ext;
	      /* dmom_u_adv_u_ext[2] -= MOVING_DOMAIN*dmom_u_acc_u_ext*zt_ext; */
	      
	      mom_v_adv_ext[0] -= MOVING_DOMAIN*mom_v_acc_ext*xt_ext;
	      mom_v_adv_ext[1] -= MOVING_DOMAIN*mom_v_acc_ext*yt_ext;
	      /* mom_v_adv_ext[2] -= MOVING_DOMAIN*mom_v_acc_ext*zt_ext; */
	      dmom_v_adv_v_ext[0] -= MOVING_DOMAIN*dmom_v_acc_v_ext*xt_ext;
	      dmom_v_adv_v_ext[1] -= MOVING_DOMAIN*dmom_v_acc_v_ext*yt_ext;
	      /* dmom_v_adv_v_ext[2] -= MOVING_DOMAIN*dmom_v_acc_v_ext*zt_ext; */
	      
	      /* mom_w_adv_ext[0] -= MOVING_DOMAIN*mom_w_acc_ext*xt_ext; */
	      /* mom_w_adv_ext[1] -= MOVING_DOMAIN*mom_w_acc_ext*yt_ext; */
	      /* mom_w_adv_ext[2] -= MOVING_DOMAIN*mom_w_acc_ext*zt_ext; */
	      /* dmom_w_adv_w_ext[0] -= MOVING_DOMAIN*dmom_w_acc_w_ext*xt_ext; */
	      /* dmom_w_adv_w_ext[1] -= MOVING_DOMAIN*dmom_w_acc_w_ext*yt_ext; */
	      /* dmom_w_adv_w_ext[2] -= MOVING_DOMAIN*dmom_w_acc_w_ext*zt_ext; */
	      
	      //moving domain bc's
	      bc_mom_u_adv_ext[0] -= MOVING_DOMAIN*bc_mom_u_acc_ext*xt_ext;
	      bc_mom_u_adv_ext[1] -= MOVING_DOMAIN*bc_mom_u_acc_ext*yt_ext;
	      /* bc_mom_u_adv_ext[2] -= MOVING_DOMAIN*bc_mom_u_acc_ext*zt_ext; */
	      
	      bc_mom_v_adv_ext[0] -= MOVING_DOMAIN*bc_mom_v_acc_ext*xt_ext;
	      bc_mom_v_adv_ext[1] -= MOVING_DOMAIN*bc_mom_v_acc_ext*yt_ext;
	      /* bc_mom_v_adv_ext[2] -= MOVING_DOMAIN*bc_mom_v_acc_ext*zt_ext; */

	      /* bc_mom_w_adv_ext[0] -= MOVING_DOMAIN*bc_mom_w_acc_ext*xt_ext; */
	      /* bc_mom_w_adv_ext[1] -= MOVING_DOMAIN*bc_mom_w_acc_ext*yt_ext; */
	      /* bc_mom_w_adv_ext[2] -= MOVING_DOMAIN*bc_mom_w_acc_ext*zt_ext; */
	      // 
	      //calculate the numerical fluxes 
	      // 
	      exteriorNumericalAdvectiveFluxDerivatives(isDOFBoundary_p[ebNE_kb],
							isDOFBoundary_u[ebNE_kb],
							isDOFBoundary_v[ebNE_kb],
							isDOFBoundary_w[ebNE_kb],
							isAdvectiveFluxBoundary_p[ebNE_kb],
							isAdvectiveFluxBoundary_u[ebNE_kb],
							isAdvectiveFluxBoundary_v[ebNE_kb],
							isAdvectiveFluxBoundary_w[ebNE_kb],
							dmom_u_ham_grad_p_ext[0],//=1/rho
							normal,
							bc_vosStar_ext,
							bc_mass_adv_ext,
							bc_mom_u_adv_ext,
							bc_mom_v_adv_ext,
							bc_mom_w_adv_ext,
							ebqe_bc_flux_mass_ext[ebNE_kb]+MOVING_DOMAIN*(xt_ext*normal[0]+yt_ext*normal[1]),//bc is relative mass  flux
							ebqe_bc_flux_mom_u_adv_ext[ebNE_kb],
							ebqe_bc_flux_mom_v_adv_ext[ebNE_kb],
							ebqe_bc_flux_mom_w_adv_ext[ebNE_kb],
							vosStar_ext,
							mass_adv_ext,
							mom_u_adv_ext,
							mom_v_adv_ext,
							mom_w_adv_ext,
							dmass_adv_u_ext,
							dmass_adv_v_ext,
							dmass_adv_w_ext,
							dmom_u_adv_p_ext,
							dmom_u_adv_u_ext,
							dmom_u_adv_v_ext,
							dmom_u_adv_w_ext,
							dmom_v_adv_p_ext,
							dmom_v_adv_u_ext,
							dmom_v_adv_v_ext,
							dmom_v_adv_w_ext,
							dmom_w_adv_p_ext,
							dmom_w_adv_u_ext,
							dmom_w_adv_v_ext,
							dmom_w_adv_w_ext,
							dflux_mass_u_ext,
							dflux_mass_v_ext,
							dflux_mass_w_ext,
							dflux_mom_u_adv_p_ext,
							dflux_mom_u_adv_u_ext,
							dflux_mom_u_adv_v_ext,
							dflux_mom_u_adv_w_ext,
							dflux_mom_v_adv_p_ext,
							dflux_mom_v_adv_u_ext,
							dflux_mom_v_adv_v_ext,
							dflux_mom_v_adv_w_ext,
							dflux_mom_w_adv_p_ext,
							dflux_mom_w_adv_u_ext,
							dflux_mom_w_adv_v_ext,
							dflux_mom_w_adv_w_ext);
	      //
	      //calculate the flux jacobian
	      //
	      ck.calculateGScale(G,normal,h_penalty);
	      penalty = useMetrics*C_b*h_penalty + (1.0-useMetrics)*ebqe_penalty_ext[ebNE_kb];
	      for (int j=0;j<nDOF_trial_element;j++)
		{
		  register int j_nSpace = j*nSpace,ebN_local_kb_j=ebN_local_kb*nDOF_trial_element+j;
		  fluxJacobian_p_p[j]=0.0;
		  fluxJacobian_p_u[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mass_u_ext,vel_trial_trace_ref[ebN_local_kb_j]);
		  fluxJacobian_p_v[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mass_v_ext,vel_trial_trace_ref[ebN_local_kb_j]);
		  /* fluxJacobian_p_w[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mass_w_ext,vel_trial_trace_ref[ebN_local_kb_j]); */

		  fluxJacobian_u_p[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_u_adv_p_ext,p_trial_trace_ref[ebN_local_kb_j]);
		  fluxJacobian_u_u[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_u_adv_u_ext,vel_trial_trace_ref[ebN_local_kb_j]) +
		    ExteriorNumericalDiffusiveFluxJacobian(eps_rho,
							   ebqe_phi_ext[ebNE_kb],
							   sdInfo_u_u_rowptr,
							   sdInfo_u_u_colind,
							   isDOFBoundary_u[ebNE_kb],
							   isDiffusiveFluxBoundary_u[ebNE_kb],
							   normal,
							   mom_uu_diff_ten_ext,
							   vel_trial_trace_ref[ebN_local_kb_j],
							   &vel_grad_trial_trace[j_nSpace],
							   penalty);//ebqe_penalty_ext[ebNE_kb]);
		  fluxJacobian_u_v[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_u_adv_v_ext,vel_trial_trace_ref[ebN_local_kb_j]) +
		    ExteriorNumericalDiffusiveFluxJacobian(eps_rho,
							   ebqe_phi_ext[ebNE_kb],
							   sdInfo_u_v_rowptr,
							   sdInfo_u_v_colind,
							   isDOFBoundary_v[ebNE_kb],
							   isDiffusiveFluxBoundary_v[ebNE_kb],
							   normal,
							   mom_uv_diff_ten_ext,
							   vel_trial_trace_ref[ebN_local_kb_j],
							   &vel_grad_trial_trace[j_nSpace],
							   penalty);//ebqe_penalty_ext[ebNE_kb]);
		  /* fluxJacobian_u_w[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_u_adv_w_ext,vel_trial_trace_ref[ebN_local_kb_j]) + */
		  /*   ExteriorNumericalDiffusiveFluxJacobian(eps_rho, */
		  /* 					   ebqe_phi_ext[ebNE_kb], */
		  /* 					   sdInfo_u_w_rowptr, */
		  /* 					   sdInfo_u_w_colind, */
		  /* 					   isDOFBoundary_w[ebNE_kb], */
		  /* 					   isDiffusiveFluxBoundary_u[ebNE_kb], */
		  /* 					   normal, */
		  /* 					   mom_uw_diff_ten_ext, */
		  /* 					   vel_trial_trace_ref[ebN_local_kb_j], */
		  /* 					   &vel_grad_trial_trace[j_nSpace], */
		  /* 					   penalty);//ebqe_penalty_ext[ebNE_kb]); */

		  fluxJacobian_v_p[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_v_adv_p_ext,p_trial_trace_ref[ebN_local_kb_j]);
		  fluxJacobian_v_u[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_v_adv_u_ext,vel_trial_trace_ref[ebN_local_kb_j]) +
		    ExteriorNumericalDiffusiveFluxJacobian(eps_rho,
							   ebqe_phi_ext[ebNE_kb],
							   sdInfo_v_u_rowptr,
							   sdInfo_v_u_colind,
							   isDOFBoundary_u[ebNE_kb],
							   isDiffusiveFluxBoundary_u[ebNE_kb],
							   normal,
							   mom_vu_diff_ten_ext,
							   vel_trial_trace_ref[ebN_local_kb_j],
							   &vel_grad_trial_trace[j_nSpace],
							   penalty);//ebqe_penalty_ext[ebNE_kb]);
		  fluxJacobian_v_v[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_v_adv_v_ext,vel_trial_trace_ref[ebN_local_kb_j]) +
		    ExteriorNumericalDiffusiveFluxJacobian(eps_rho,
							   ebqe_phi_ext[ebNE_kb],
							   sdInfo_v_v_rowptr,
							   sdInfo_v_v_colind,
							   isDOFBoundary_v[ebNE_kb],
							   isDiffusiveFluxBoundary_v[ebNE_kb],
							   normal,
							   mom_vv_diff_ten_ext,
							   vel_trial_trace_ref[ebN_local_kb_j],
							   &vel_grad_trial_trace[j_nSpace],
							   penalty);//ebqe_penalty_ext[ebNE_kb]);
		  /* fluxJacobian_v_w[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_v_adv_w_ext,vel_trial_trace_ref[ebN_local_kb_j]) + */
		  /*   ExteriorNumericalDiffusiveFluxJacobian(eps_rho, */
		  /* 					   ebqe_phi_ext[ebNE_kb], */
		  /* 					   sdInfo_v_w_rowptr, */
		  /* 					   sdInfo_v_w_colind, */
		  /* 					   isDOFBoundary_w[ebNE_kb], */
		  /* 					   isDiffusiveFluxBoundary_v[ebNE_kb], */
		  /* 					   normal, */
		  /* 					   mom_vw_diff_ten_ext, */
		  /* 					   vel_trial_trace_ref[ebN_local_kb_j], */
		  /* 					   &vel_grad_trial_trace[j_nSpace], */
		  /* 					   penalty);//ebqe_penalty_ext[ebNE_kb]); */

		  /* fluxJacobian_w_p[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_w_adv_p_ext,p_trial_trace_ref[ebN_local_kb_j]); */
		  /* fluxJacobian_w_u[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_w_adv_u_ext,vel_trial_trace_ref[ebN_local_kb_j]) + */
		  /*   ExteriorNumericalDiffusiveFluxJacobian(eps_rho, */
		  /* 					   ebqe_phi_ext[ebNE_kb], */
		  /* 					   sdInfo_w_u_rowptr, */
		  /* 					   sdInfo_w_u_colind, */
		  /* 					   isDOFBoundary_u[ebNE_kb], */
		  /* 					   isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					   normal, */
		  /* 					   mom_wu_diff_ten_ext, */
		  /* 					   vel_trial_trace_ref[ebN_local_kb_j], */
		  /* 					   &vel_grad_trial_trace[j_nSpace], */
		  /* 					   penalty);//ebqe_penalty_ext[ebNE_kb]); */
		  /* fluxJacobian_w_v[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_w_adv_v_ext,vel_trial_trace_ref[ebN_local_kb_j]) + */
		  /*   ExteriorNumericalDiffusiveFluxJacobian(eps_rho, */
		  /* 					   ebqe_phi_ext[ebNE_kb], */
		  /* 					   sdInfo_w_v_rowptr, */
		  /* 					   sdInfo_w_v_colind, */
		  /* 					   isDOFBoundary_v[ebNE_kb], */
		  /* 					   isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					   normal, */
		  /* 					   mom_wv_diff_ten_ext, */
		  /* 					   vel_trial_trace_ref[ebN_local_kb_j], */
		  /* 					   &vel_grad_trial_trace[j_nSpace], */
		  /* 					   penalty);//ebqe_penalty_ext[ebNE_kb]); */
		  /* fluxJacobian_w_w[j]=ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_mom_w_adv_w_ext,vel_trial_trace_ref[ebN_local_kb_j]) + */
		  /*   ExteriorNumericalDiffusiveFluxJacobian(eps_rho, */
		  /* 					   ebqe_phi_ext[ebNE_kb], */
		  /* 					   sdInfo_w_w_rowptr, */
		  /* 					   sdInfo_w_w_colind, */
		  /* 					   isDOFBoundary_w[ebNE_kb], */
		  /* 					   isDiffusiveFluxBoundary_w[ebNE_kb], */
		  /* 					   normal, */
		  /* 					   mom_ww_diff_ten_ext, */
		  /* 					   vel_trial_trace_ref[ebN_local_kb_j], */
		  /* 					   &vel_grad_trial_trace[j_nSpace], */
		  /* 					   penalty);//ebqe_penalty_ext[ebNE_kb]); */
		}//j
	      //
	      //update the global Jacobian from the flux Jacobian
	      //
	      for (int i=0;i<nDOF_test_element;i++)
		{
		  register int eN_i = eN*nDOF_test_element+i;
		  for (int j=0;j<nDOF_trial_element;j++)
		    {
		      register int ebN_i_j = ebN*4*nDOF_test_X_trial_element + i*nDOF_trial_element + j,ebN_local_kb_j=ebN_local_kb*nDOF_trial_element+j;
		  
		      globalJacobian[csrRowIndeces_p_p[eN_i] + csrColumnOffsets_eb_p_p[ebN_i_j]] += fluxJacobian_p_p[j]*p_test_dS[i];
		      globalJacobian[csrRowIndeces_p_u[eN_i] + csrColumnOffsets_eb_p_u[ebN_i_j]] += fluxJacobian_p_u[j]*p_test_dS[i];
		      globalJacobian[csrRowIndeces_p_v[eN_i] + csrColumnOffsets_eb_p_v[ebN_i_j]] += fluxJacobian_p_v[j]*p_test_dS[i];
		      /* globalJacobian[csrRowIndeces_p_w[eN_i] + csrColumnOffsets_eb_p_w[ebN_i_j]] += fluxJacobian_p_w[j]*p_test_dS[i]; */
		   
		      globalJacobian[csrRowIndeces_u_p[eN_i] + csrColumnOffsets_eb_u_p[ebN_i_j]] += fluxJacobian_u_p[j]*vel_test_dS[i];
		      globalJacobian[csrRowIndeces_u_u[eN_i] + csrColumnOffsets_eb_u_u[ebN_i_j]] += fluxJacobian_u_u[j]*vel_test_dS[i]+
			ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_u[ebNE_kb],
									   isDiffusiveFluxBoundary_u[ebNE_kb],
									   eb_adjoint_sigma,
									   vel_trial_trace_ref[ebN_local_kb_j],
									   normal,
									   sdInfo_u_u_rowptr,
									   sdInfo_u_u_colind,
									   mom_uu_diff_ten_ext,
									   &vel_grad_test_dS[i*nSpace]);
		      globalJacobian[csrRowIndeces_u_v[eN_i] + csrColumnOffsets_eb_u_v[ebN_i_j]] += fluxJacobian_u_v[j]*vel_test_dS[i]+
			ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_v[ebNE_kb],
									   isDiffusiveFluxBoundary_u[ebNE_kb],
									   eb_adjoint_sigma,
									   vel_trial_trace_ref[ebN_local_kb_j],
									   normal,
									   sdInfo_u_v_rowptr,
									   sdInfo_u_v_colind,
									   mom_uv_diff_ten_ext,
									   &vel_grad_test_dS[i*nSpace]);
		      /* globalJacobian[csrRowIndeces_u_w[eN_i] + csrColumnOffsets_eb_u_w[ebN_i_j]] += fluxJacobian_u_w[j]*vel_test_dS[i]+ */
		      /* 	ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_w[ebNE_kb], */
		      /* 							   isDiffusiveFluxBoundary_u[ebNE_kb], */
		      /* 							   eb_adjoint_sigma, */
		      /* 							   vel_trial_trace_ref[ebN_local_kb_j], */
		      /* 							   normal, */
		      /* 							   sdInfo_u_w_rowptr, */
		      /* 							   sdInfo_u_w_colind, */
		      /* 							   mom_uw_diff_ten_ext, */
		      /* 							   &vel_grad_test_dS[i*nSpace]); */
		   
		      globalJacobian[csrRowIndeces_v_p[eN_i] + csrColumnOffsets_eb_v_p[ebN_i_j]] += fluxJacobian_v_p[j]*vel_test_dS[i];
		      globalJacobian[csrRowIndeces_v_u[eN_i] + csrColumnOffsets_eb_v_u[ebN_i_j]] += fluxJacobian_v_u[j]*vel_test_dS[i]+
			ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_u[ebNE_kb],
									   isDiffusiveFluxBoundary_v[ebNE_kb],
									   eb_adjoint_sigma,
									   vel_trial_trace_ref[ebN_local_kb_j],
									   normal,
									   sdInfo_v_u_rowptr,
									   sdInfo_v_u_colind,
									   mom_vu_diff_ten_ext,
									   &vel_grad_test_dS[i*nSpace]);
		      globalJacobian[csrRowIndeces_v_v[eN_i] + csrColumnOffsets_eb_v_v[ebN_i_j]] += fluxJacobian_v_v[j]*vel_test_dS[i]+
			ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_v[ebNE_kb],
									   isDiffusiveFluxBoundary_v[ebNE_kb],
									   eb_adjoint_sigma,
									   vel_trial_trace_ref[ebN_local_kb_j],
									   normal,
									   sdInfo_v_v_rowptr,
									   sdInfo_v_v_colind,
									   mom_vv_diff_ten_ext,
									   &vel_grad_test_dS[i*nSpace]);
		      /* globalJacobian[csrRowIndeces_v_w[eN_i] + csrColumnOffsets_eb_v_w[ebN_i_j]] += fluxJacobian_v_w[j]*vel_test_dS[i]+ */
		      /* 	ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_w[ebNE_kb], */
		      /* 							   isDiffusiveFluxBoundary_v[ebNE_kb], */
		      /* 							   eb_adjoint_sigma, */
		      /* 							   vel_trial_trace_ref[ebN_local_kb_j], */
		      /* 							   normal, */
		      /* 							   sdInfo_v_w_rowptr, */
		      /* 							   sdInfo_v_w_colind, */
		      /* 							   mom_vw_diff_ten_ext, */
		      /* 							   &vel_grad_test_dS[i*nSpace]); */
		   
		      /* globalJacobian[csrRowIndeces_w_p[eN_i] + csrColumnOffsets_eb_w_p[ebN_i_j]] += fluxJacobian_w_p[j]*vel_test_dS[i]; */
		      /* globalJacobian[csrRowIndeces_w_u[eN_i] + csrColumnOffsets_eb_w_u[ebN_i_j]] += fluxJacobian_w_u[j]*vel_test_dS[i]+ */
		      /* 	ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_u[ebNE_kb], */
		      /* 							   isDiffusiveFluxBoundary_w[ebNE_kb], */
		      /* 							   eb_adjoint_sigma, */
		      /* 							   vel_trial_trace_ref[ebN_local_kb_j], */
		      /* 							   normal, */
		      /* 							   sdInfo_w_u_rowptr, */
		      /* 							   sdInfo_w_u_colind, */
		      /* 							   mom_wu_diff_ten_ext, */
		      /* 							   &vel_grad_test_dS[i*nSpace]); */
		      /* globalJacobian[csrRowIndeces_w_v[eN_i] + csrColumnOffsets_eb_w_v[ebN_i_j]] += fluxJacobian_w_v[j]*vel_test_dS[i]+ */
		      /* 	ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_v[ebNE_kb], */
		      /* 							   isDiffusiveFluxBoundary_w[ebNE_kb], */
		      /* 							   eb_adjoint_sigma, */
		      /* 							   vel_trial_trace_ref[ebN_local_kb_j], */
		      /* 							   normal, */
		      /* 							   sdInfo_w_v_rowptr, */
		      /* 							   sdInfo_w_v_colind, */
		      /* 							   mom_wv_diff_ten_ext, */
		      /* 							   &vel_grad_test_dS[i*nSpace]); */
		      /* globalJacobian[csrRowIndeces_w_w[eN_i] + csrColumnOffsets_eb_w_w[ebN_i_j]] += fluxJacobian_w_w[j]*vel_test_dS[i]+ */
		      /* 	ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_w[ebNE_kb], */
		      /* 							   isDiffusiveFluxBoundary_w[ebNE_kb], */
		      /* 							   eb_adjoint_sigma, */
		      /* 							   vel_trial_trace_ref[ebN_local_kb_j], */
		      /* 							   normal, */
		      /* 							   sdInfo_w_w_rowptr, */
		      /* 							   sdInfo_w_w_colind, */
		      /* 							   mom_ww_diff_ten_ext, */
		      /* 							   &vel_grad_test_dS[i*nSpace]); */
		    }//j
		}//i
	    }//kb
	}//ebNE
    }//computeJacobian

    void calculateVelocityAverage(int nExteriorElementBoundaries_global,
    				  int* exteriorElementBoundariesArray,
    				  int nInteriorElementBoundaries_global,
    				  int* interiorElementBoundariesArray,
    				  int* elementBoundaryElementsArray,
    				  int* elementBoundaryLocalElementBoundariesArray,
    				  double* mesh_dof,
                                  double* mesh_velocity_dof,
                                  double MOVING_DOMAIN,//0 or 1
    				  int* mesh_l2g,
    				  double* mesh_trial_trace_ref,
    				  double* mesh_grad_trial_trace_ref,
    				  double* normal_ref,
    				  double* boundaryJac_ref,
    				  int* vel_l2g,
    				  double* u_dof,
    				  double* v_dof,
    				  double* w_dof,
    				  double* vel_trial_trace_ref,
    				  double* ebqe_velocity,
    				  double* velocityAverage)
    {
      int permutations[nQuadraturePoints_elementBoundary];
      double xArray_left[nQuadraturePoints_elementBoundary*2],
    	xArray_right[nQuadraturePoints_elementBoundary*2];
      for (int i=0;i<nQuadraturePoints_elementBoundary;i++)
	permutations[i]=i;//just to initialize
      for (int ebNE = 0; ebNE < nExteriorElementBoundaries_global; ebNE++)
    	{
    	  register int ebN = exteriorElementBoundariesArray[ebNE];
    	  for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++)
    	    {
    	      register int ebN_kb_nSpace = ebN*nQuadraturePoints_elementBoundary*nSpace+kb*nSpace,
    		ebNE_kb_nSpace = ebNE*nQuadraturePoints_elementBoundary*nSpace+kb*nSpace;
    	      velocityAverage[ebN_kb_nSpace+0]=ebqe_velocity[ebNE_kb_nSpace+0];
    	      velocityAverage[ebN_kb_nSpace+1]=ebqe_velocity[ebNE_kb_nSpace+1];
    	    }//ebNE
    	}
      for (int ebNI = 0; ebNI < nInteriorElementBoundaries_global; ebNI++)
    	{
    	  register int ebN = interiorElementBoundariesArray[ebNI],
    	    left_eN_global   = elementBoundaryElementsArray[ebN*2+0],
    	    left_ebN_element  = elementBoundaryLocalElementBoundariesArray[ebN*2+0],
    	    right_eN_global  = elementBoundaryElementsArray[ebN*2+1],
    	    right_ebN_element = elementBoundaryLocalElementBoundariesArray[ebN*2+1],
    	    left_eN_nDOF_trial_element = left_eN_global*nDOF_trial_element,
    	    right_eN_nDOF_trial_element = right_eN_global*nDOF_trial_element;
    	  double jac[nSpace*nSpace],
    	    jacDet,
    	    jacInv[nSpace*nSpace],
    	    boundaryJac[nSpace*(nSpace-1)],
    	    metricTensor[(nSpace-1)*(nSpace-1)],
    	    metricTensorDetSqrt,
    	    normal[2],
    	    x,y,z,
    	    xt,yt,zt,integralScaling;
	  
    	  for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++)
    	    {
    	      ck.calculateMapping_elementBoundary(left_eN_global,
    						  left_ebN_element,
    						  kb,
    						  left_ebN_element*nQuadraturePoints_elementBoundary+kb,
    						  mesh_dof,
    						  mesh_l2g,
    						  mesh_trial_trace_ref,
    						  mesh_grad_trial_trace_ref,
    						  boundaryJac_ref,
    						  jac,
    						  jacDet,
    						  jacInv,
    						  boundaryJac,
    						  metricTensor,
    						  metricTensorDetSqrt,
    						  normal_ref,
    						  normal,
    						  x,y,z);
    	      xArray_left[kb*2+0] = x;
    	      xArray_left[kb*2+1] = y;
    	      /* xArray_left[kb*3+2] = z; */
    	      ck.calculateMapping_elementBoundary(right_eN_global,
    						  right_ebN_element,
    						  kb,
    						  right_ebN_element*nQuadraturePoints_elementBoundary+kb,
    						  mesh_dof,
    						  mesh_l2g,
    						  mesh_trial_trace_ref,
    						  mesh_grad_trial_trace_ref,
    						  boundaryJac_ref,
    						  jac,
    						  jacDet,
    						  jacInv,
    						  boundaryJac,
    						  metricTensor,
    						  metricTensorDetSqrt,
    						  normal_ref,
    						  normal,
    						  x,y,z);
	      ck.calculateMappingVelocity_elementBoundary(left_eN_global,
	        					  left_ebN_element,
	        					  kb,
	        					  left_ebN_element*nQuadraturePoints_elementBoundary+kb,
	        					  mesh_velocity_dof,
	        					  mesh_l2g,
	        					  mesh_trial_trace_ref,
	        					  xt,yt,zt,
	        					  normal,
	        					  boundaryJac,
	        					  metricTensor,
	        					  integralScaling);
    	      xArray_right[kb*2+0] = x;
    	      xArray_right[kb*2+1] = y;
    	      /* xArray_right[kb*3+2] = z; */
    	    }
    	  for  (int kb_left=0;kb_left<nQuadraturePoints_elementBoundary;kb_left++)
    	    {
    	      double errorNormMin = 1.0;
    	      for  (int kb_right=0;kb_right<nQuadraturePoints_elementBoundary;kb_right++)
    		{
    		  double errorNorm=0.0;
    		  for (int I=0;I<nSpace;I++)
    		    {
    		      errorNorm += fabs(xArray_left[kb_left*2+I]
    					-
    					xArray_right[kb_right*2+I]);
    		    }
    		  if (errorNorm < errorNormMin)
    		    {
    		      permutations[kb_right] = kb_left;
    		      errorNormMin = errorNorm;
    		    }
    		}
    	    }
    	  for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++)
    	    {
    	      register int ebN_kb_nSpace = ebN*nQuadraturePoints_elementBoundary*nSpace+kb*nSpace;
    	      register double u_left=0.0,
    		v_left=0.0,
    		w_left=0.0,
    		u_right=0.0,
    		v_right=0.0,
    		w_right=0.0;
    	      register int left_kb = kb,
    		right_kb = permutations[kb],
    		left_ebN_element_kb_nDOF_test_element=(left_ebN_element*nQuadraturePoints_elementBoundary+left_kb)*nDOF_test_element,
		right_ebN_element_kb_nDOF_test_element=(right_ebN_element*nQuadraturePoints_elementBoundary+right_kb)*nDOF_test_element;
    	      //
    	      //calculate the velocity solution at quadrature points on left and right
    	      //
    	      ck.valFromDOF(u_dof,&vel_l2g[left_eN_nDOF_trial_element],&vel_trial_trace_ref[left_ebN_element_kb_nDOF_test_element],u_left);
    	      ck.valFromDOF(v_dof,&vel_l2g[left_eN_nDOF_trial_element],&vel_trial_trace_ref[left_ebN_element_kb_nDOF_test_element],v_left);
    	      /* ck.valFromDOF(w_dof,&vel_l2g[left_eN_nDOF_trial_element],&vel_trial_trace_ref[left_ebN_element_kb_nDOF_test_element],w_left); */
    	      //
    	      ck.valFromDOF(u_dof,&vel_l2g[right_eN_nDOF_trial_element],&vel_trial_trace_ref[right_ebN_element_kb_nDOF_test_element],u_right);
    	      ck.valFromDOF(v_dof,&vel_l2g[right_eN_nDOF_trial_element],&vel_trial_trace_ref[right_ebN_element_kb_nDOF_test_element],v_right);
    	      /* ck.valFromDOF(w_dof,&vel_l2g[right_eN_nDOF_trial_element],&vel_trial_trace_ref[right_ebN_element_kb_nDOF_test_element],w_right); */
    	      //
    	      velocityAverage[ebN_kb_nSpace+0]=0.5*(u_left + u_right);
    	      velocityAverage[ebN_kb_nSpace+1]=0.5*(v_left + v_right);
    	      /* velocityAverage[ebN_kb_nSpace+2]=0.5*(w_left + w_right); */
    	    }//ebNI
    	}
    }
  };//RANS3PSed2D
  
  inline cppRANS3PSed2D_base* newRANS3PSed2D(int nSpaceIn,
                                         int nQuadraturePoints_elementIn,
                                         int nDOF_mesh_trial_elementIn,
                                         int nDOF_trial_elementIn,
                                         int nDOF_test_elementIn,
                                         int nQuadraturePoints_elementBoundaryIn,
                                         int CompKernelFlag)
  {
    return proteus::chooseAndAllocateDiscretization2D<cppRANS3PSed2D_base,cppRANS3PSed2D,CompKernel>(nSpaceIn,
											 nQuadraturePoints_elementIn,
											 nDOF_mesh_trial_elementIn,
											 nDOF_trial_elementIn,
											 nDOF_test_elementIn,
											 nQuadraturePoints_elementBoundaryIn,
											 CompKernelFlag);
  }
}//proteus

#endif