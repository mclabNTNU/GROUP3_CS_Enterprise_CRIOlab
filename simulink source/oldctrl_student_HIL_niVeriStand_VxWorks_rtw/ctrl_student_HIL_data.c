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
 * Model version              : 1.198
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Mar 24 10:37:00 2017
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S4>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/counter'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise pos'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/noise pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S15>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S15>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S16>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S16>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise head'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise head'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/noise head'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise head'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise head'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise head'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S14>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S14>/White Noise'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/enable noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_m'
                                        */
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
                                        * Referenced by: '<Root>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_m'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/r_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/r_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/b'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/b'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/b'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/b'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/b'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/b'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/u_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/u_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/v_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/v_dot'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/v_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/v_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/v_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/v_dot'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory4'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory3'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory2'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/y_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/y_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/y_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/x_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/x_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/x_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Expression: [1 0 0; 0 1 0; 0 0 1]
   * Referenced by: '<Root>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */

  /*  Expression: [100 0]'
   * Referenced by: '<Root>/Constant6'
   */
  { 100.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S5>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowRight'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
