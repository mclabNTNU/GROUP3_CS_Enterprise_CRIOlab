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
 * Model version              : 1.114
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 27 14:50:42 2017
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Test'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Test'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Test'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Test'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Test'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Test'
                                        */
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
                                        * Referenced by: '<S7>/osi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/osi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/osi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/osi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/osi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/osi_0 '
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
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S2>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Constant4'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S12>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/noise pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/noise pos'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/noise pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/noise pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/noise pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/noise pos'
                                        */
  1.0E-7,                              /* Expression: 1e-7
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S19>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S19>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_j
                                        * Referenced by: '<S20>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S20>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/noise head'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/noise head'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/noise head'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/noise head'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/noise head'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/noise head'
                                        */
  1.0E-7,                              /* Expression: 1e-7
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_n
                                        * Referenced by: '<S18>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S18>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */

  /*  Expression: [1/1000 1/1000 pi/180]'
   * Referenced by: '<Root>/Gain'
   */
  { 0.001, 0.001, 0.017453292519943295 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/enable noise'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/enable noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/enable noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/enable noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/enable noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/drop_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/drop_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/drop_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S2>/Integrator, Second-Order'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S2>/Integrator, Second-Order'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/case_number'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/case_number'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/case_number'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/case_number'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/case_number'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/case_number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S1>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/mu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/mu'
                                        */
  7.0,                                 /* Expression: portnum
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
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rx'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/rx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rx'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rx'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/ry'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ry'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/ry'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ry'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ry'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ry'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/kp1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/kp1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/kp1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/kp1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/kp1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/kp1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/kp2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/kp2'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/kp2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/kp2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/kp2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/kp2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/kp3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/kp3'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/kp3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/kp3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/kp3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/kp3'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/k2_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/k2_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/k2_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/k2_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/k2_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/k2_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/k2_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k2_3'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/k2_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/k2_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/k2_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/k2_3'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S1>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]'
   * Referenced by: '<S1>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: width
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
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  1.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S1>/u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/x_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  6.0,                                 /* Expression: portnum
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
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S1>/demp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/demp'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/demp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/demp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/demp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/demp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  7.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/y_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S1>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  4.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Reset'
                                        */
  4.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/k_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k_0'
                                        */
  6.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_calb_ctrl'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_calb_ctrl1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/u_VSP2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/eta_dot_imu'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
