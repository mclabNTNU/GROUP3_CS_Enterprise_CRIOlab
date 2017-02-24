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
 * Model version              : 1.278
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Feb 24 18:24:26 2017
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
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise_power_p'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise_power_p'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/noise_power_p'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise_power_p'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise_power_p'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise_power_p'
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
                                        * Referenced by: '<Root>/noise_power_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise_power_psi'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/noise_power_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise_power_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise_power_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise_power_psi'
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
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise'
                                        */

  /*  Expression: [1 0 1; 1 0 1; 1 0 1]
   * Referenced by: '<Root>/Memory'
   */
  { 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<Root>/Integrator, Second-Order'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<Root>/Integrator, Second-Order'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/k_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k_0'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S6>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi'
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

  /*  Expression: [0 0 0]'
   * Referenced by: '<S5>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_newModel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  5.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_newModel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_newModel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_newModel1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_newModel1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_newModel1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -0.5,                                /* Expression: -.5
                                        * Referenced by: '<S7>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Combine'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Combine'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Combine'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Combine'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Combine'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Combine'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/X_d'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/integrator reset model'
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

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
