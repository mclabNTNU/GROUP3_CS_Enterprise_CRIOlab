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
 * Model version              : 1.402
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Mar 26 16:49:07 2017
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/case_number'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/case_number'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/X_d'
                                        */
  2.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  4.0,                                 /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  5.0,                                 /* Expression: portnum
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
  6.0,                                 /* Expression: portnum
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
  7.0,                                 /* Expression: portnum
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
