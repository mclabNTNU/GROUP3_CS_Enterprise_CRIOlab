/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.299
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat Mar 25 14:33:19 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  /*  Variable: C
   * Referenced by: '<S27>/C'
   */
  { 0.0, 0.0 },

  /*  Variable: K_p
   * Referenced by:
   *   '<S12>/K_p'
   *   '<S26>/K_p'
   *   '<S38>/K_p'
   */
  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.1 },

  /*  Variable: P_d
   * Referenced by:
   *   '<S13>/P_d'
   *   '<S14>/Constant'
   *   '<S39>/P_d'
   *   '<S40>/Constant'
   */
  { 2.0, 10.0, 0.0, 4.0 },

  /*  Variable: R
   * Referenced by: '<S27>/R'
   */
  { 1.0, 0.0, 0.0, 1.0 },
  2.5,                                 /* Variable: U_max
                                        * Referenced by:
                                        *   '<Root>/Constant5'
                                        *   '<Root>/u_ref'
                                        */

  /*  Variable: r
   * Referenced by: '<S28>/Constant'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */

  /*  Expression: [1 0 1; 1 0 1; 1 0 1]
   * Referenced by: '<S4>/Memory'
   */
  { 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S4>/Integrator, Second-Order'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S4>/Integrator, Second-Order'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/mu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/mu'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/mu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/mu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/mu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/mu'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S29>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */

  /*  Expression: [1.03 2.5 0.98]'
   * Referenced by: '<S26>/Saturation'
   */
  { 1.03, 2.5, 0.98 },

  /*  Expression: -[1.03 2.5 0.98]'
   * Referenced by: '<S26>/Saturation'
   */
  { -1.03, -2.5, -0.98 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S41>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Saturation'
                                        */

  /*  Expression: [1.03 2.5 0.98]'
   * Referenced by: '<S38>/Saturation'
   */
  { 1.03, 2.5, 0.98 },

  /*  Expression: -[1.03 2.5 0.98]'
   * Referenced by: '<S38>/Saturation'
   */
  { -1.03, -2.5, -0.98 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Uref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Uref'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/Uref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Uref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Uref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Uref'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S15>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [1.03 2.5 0.98]'
   * Referenced by: '<S12>/Saturation'
   */
  { 1.03, 2.5, 0.98 },

  /*  Expression: -[1.03 2.5 0.98]'
   * Referenced by: '<S12>/Saturation'
   */
  { -1.03, -2.5, -0.98 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Reset'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Reset'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L1_diag'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L2_diag '
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S2>/L3_diag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L3_diag'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L3_diag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L3_diag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L3_diag'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L3_diag'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory4'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory3'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory2'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/b'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/b'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/b'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/b'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/b'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/b'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_bar'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/r_dot'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/r_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/r_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/r_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/r_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_dot'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/v_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/v_dot'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/v_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/v_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/v_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/v_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_bar'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_hat'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_bar'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_hat'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/k_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k_0'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/k_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/k_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/k_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/k_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
