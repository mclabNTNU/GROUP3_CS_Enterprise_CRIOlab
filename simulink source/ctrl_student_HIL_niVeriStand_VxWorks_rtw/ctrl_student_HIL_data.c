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
<<<<<<< HEAD
 * Model version              : 1.85
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 20 17:42:15 2017
=======
 * Model version              : 1.159
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 09 17:27:09 2017
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
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
<<<<<<< HEAD
=======
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise power pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S12>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S12>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S13>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S13>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise poser head'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S11>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S11>/White Noise'
                                        */
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
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
  -1.0,                                /* Expression: width
<<<<<<< HEAD
=======
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
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  9.0,                                 /* Expression: portnum
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S1>/Step size'
                                        */
<<<<<<< HEAD
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/counter'
=======
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Enable noise'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Enable noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Enable noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Enable noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Enable noise'
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
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
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
                                        * Referenced by: '<S5>/Hold'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S10>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S10>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S11>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S11>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S9>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S9>/White Noise'
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
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
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
<<<<<<< HEAD
                                        * Referenced by: '<Root>/u_in'
=======
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
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
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
<<<<<<< HEAD
                                        * Referenced by: '<Root>/v_in'
=======
                                        * Referenced by: '<S1>/signal loss'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/signal loss'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/signal loss'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/signal loss'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/signal loss'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/signal loss'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/v_dot'
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
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
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
<<<<<<< HEAD
                                        * Referenced by: '<S3>/integrator reset model'
=======
                                        * Referenced by: '<S4>/integrator reset model'
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
<<<<<<< HEAD
=======

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
>>>>>>> 36131a4df6b7a33ef16fb81cb1b9b1ddb1e9dbe2
};

#endif
