/*
 * ctrl_case_c.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_case_c".
 *
 * Model version              : 1.136
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 02 14:20:59 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_case_c.h"
#include "ctrl_case_c_private.h"

/* Block signals (auto storage) */
B_ctrl_case_c_T ctrl_case_c_B;

/* Continuous states */
X_ctrl_case_c_T ctrl_case_c_X;

/* Block states (auto storage) */
DW_ctrl_case_c_T ctrl_case_c_DW;

/* Real-time model */
RT_MODEL_ctrl_case_c_T ctrl_case_c_M_;
RT_MODEL_ctrl_case_c_T *const ctrl_case_c_M = &ctrl_case_c_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_case_c_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_case_c_output();
  ctrl_case_c_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_case_c_output();
  ctrl_case_c_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_case_c_output();
  ctrl_case_c_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void ctrl_case_c_output(void)
{
  real_T L1[9];
  real_T L2[9];
  real_T L3[9];
  real_T R[9];
  static const real_T a[9] = { 0.059559261465157838, -0.0, 0.0, -0.0,
    0.04052100686778741, -0.0081423733365488769, -0.0, -0.0081423733365488769,
    0.36395498559871381 };

  static const real_T b_a[9] = { -4.088, -0.0, -0.0, -0.0, -68.211, -0.0788,
    -0.0, -0.0, -1.07 };

  int32_T i;
  real_T R_0[3];
  real_T L1_0[3];
  int32_T i_0;
  real_T b_a_0[3];
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_2;
  real_T eta_bar_idx_0;
  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
    /* set solver stop time */
    if (!(ctrl_case_c_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_case_c_M->solverInfo,
                            ((ctrl_case_c_M->Timing.clockTickH0 + 1) *
        ctrl_case_c_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_case_c_M->solverInfo,
                            ((ctrl_case_c_M->Timing.clockTick0 + 1) *
        ctrl_case_c_M->Timing.stepSize0 + ctrl_case_c_M->Timing.clockTickH0 *
        ctrl_case_c_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_case_c_M)) {
    ctrl_case_c_M->Timing.t[0] = rtsiGetT(&ctrl_case_c_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator' */
  ctrl_case_c_B.Integrator[0] = ctrl_case_c_X.Integrator_CSTATE[0];
  ctrl_case_c_B.Integrator[1] = ctrl_case_c_X.Integrator_CSTATE[1];
  ctrl_case_c_B.Integrator[2] = ctrl_case_c_X.Integrator_CSTATE[2];

  /* Integrator: '<S1>/Integrator1' */
  ctrl_case_c_B.Integrator1[0] = ctrl_case_c_X.Integrator1_CSTATE[0];
  ctrl_case_c_B.Integrator1[1] = ctrl_case_c_X.Integrator1_CSTATE[1];
  ctrl_case_c_B.Integrator1[2] = ctrl_case_c_X.Integrator1_CSTATE[2];

  /* Integrator: '<S1>/Integrator2' */
  ctrl_case_c_B.Integrator2[0] = ctrl_case_c_X.Integrator2_CSTATE[0];
  ctrl_case_c_B.Integrator2[1] = ctrl_case_c_X.Integrator2_CSTATE[1];
  ctrl_case_c_B.Integrator2[2] = ctrl_case_c_X.Integrator2_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
    /* Memory: '<S1>/Memory2' */
    ctrl_case_c_B.Memory2[0] = ctrl_case_c_DW.Memory2_PreviousInput[0];
    ctrl_case_c_B.Memory2[1] = ctrl_case_c_DW.Memory2_PreviousInput[1];
    ctrl_case_c_B.Memory2[2] = ctrl_case_c_DW.Memory2_PreviousInput[2];

    /* Memory: '<S1>/Memory3' */
    ctrl_case_c_B.Memory3[0] = ctrl_case_c_DW.Memory3_PreviousInput[0];
    ctrl_case_c_B.Memory3[1] = ctrl_case_c_DW.Memory3_PreviousInput[1];
    ctrl_case_c_B.Memory3[2] = ctrl_case_c_DW.Memory3_PreviousInput[2];

    /* Memory: '<S1>/Memory4' */
    ctrl_case_c_B.Memory4[0] = ctrl_case_c_DW.Memory4_PreviousInput[0];
    ctrl_case_c_B.Memory4[1] = ctrl_case_c_DW.Memory4_PreviousInput[1];
    ctrl_case_c_B.Memory4[2] = ctrl_case_c_DW.Memory4_PreviousInput[2];

    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<S2>/Step size'
     *  Memory: '<S6>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S9>:1' */
    /* '<S9>:1:3' */
    if ((ctrl_case_c_DW.counter_PreviousInput + 1.0) *
        ctrl_case_c_P.Stepsize_Value >= 1.0 / ctrl_case_c_P.Constant4_Value) {
      /* '<S9>:1:4' */
      /* '<S9>:1:5' */
      ctrl_case_c_B.count = 0.0;
    } else {
      /* '<S9>:1:7' */
      ctrl_case_c_B.count = ctrl_case_c_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S6>/MATLAB Function' */

    /* Product: '<S12>/Product' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S2>/Step size'
     *  Product: '<S12>/Divide'
     *  RandomNumber: '<S12>/White Noise'
     *  Sqrt: '<S12>/Sqrt'
     */
    ctrl_case_c_B.Product = sqrt(ctrl_case_c_P.Constant1_Value_c /
      ctrl_case_c_P.Stepsize_Value) * ctrl_case_c_DW.NextOutput;

    /* Product: '<S13>/Product' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S2>/Step size'
     *  Product: '<S13>/Divide'
     *  RandomNumber: '<S13>/White Noise'
     *  Sqrt: '<S13>/Sqrt'
     */
    ctrl_case_c_B.Product_l = sqrt(ctrl_case_c_P.Constant1_Value_c /
      ctrl_case_c_P.Stepsize_Value) * ctrl_case_c_DW.NextOutput_c;

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<S2>/Step size'
     *  Product: '<S11>/Divide'
     *  RandomNumber: '<S11>/White Noise'
     *  Sqrt: '<S11>/Sqrt'
     */
    ctrl_case_c_B.Product_e = sqrt(ctrl_case_c_P.Constant2_Value_i /
      ctrl_case_c_P.Stepsize_Value) * ctrl_case_c_DW.NextOutput_p;
  }

  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
    /* Memory: '<S7>/Hold' */
    ctrl_case_c_B.Hold[0] = ctrl_case_c_DW.Hold_PreviousInput[0];
    ctrl_case_c_B.Hold[1] = ctrl_case_c_DW.Hold_PreviousInput[1];
    ctrl_case_c_B.Hold[2] = ctrl_case_c_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S7>/MATLAB Function1' incorporates:
   *  Sum: '<S2>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S10>:1' */
  if (ctrl_case_c_B.count == 0.0) {
    /* '<S10>:1:4' */
    /* '<S10>:1:5' */
    ctrl_case_c_B.output[0] = ctrl_case_c_B.Product + ctrl_case_c_B.x_in;
    ctrl_case_c_B.output[1] = ctrl_case_c_B.Product_l + ctrl_case_c_B.y_in;
    ctrl_case_c_B.output[2] = ctrl_case_c_B.Product_e + ctrl_case_c_B.psi_in;
  } else {
    /* '<S10>:1:7' */
    ctrl_case_c_B.output[0] = ctrl_case_c_B.Hold[0];
    ctrl_case_c_B.output[1] = ctrl_case_c_B.Hold[1];
    ctrl_case_c_B.output[2] = ctrl_case_c_B.Hold[2];
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function1' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (ctrl_case_c_P.Constant3_Value != 0.0) {
    rtb_Switch_idx_0 = ctrl_case_c_B.output[0];
    rtb_Switch_idx_1 = ctrl_case_c_B.output[1];
    rtb_Switch_idx_2 = ctrl_case_c_B.output[2];
  } else {
    rtb_Switch_idx_0 = ctrl_case_c_B.x_in;
    rtb_Switch_idx_1 = ctrl_case_c_B.y_in;
    rtb_Switch_idx_2 = ctrl_case_c_B.psi_in;
  }

  /* End of Switch: '<S2>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
  }

  /* MATLAB Function: '<S1>/Observer ' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  /* MATLAB Function 'DP Observer /Observer ': '<S5>:1' */
  /*  if(first == 1) */
  /*  eta_hat = zeros(3,1) ;  */
  /*  nu_hat = zeros(3,1);  */
  /*  b_hau = zeros(3,1) */
  /*  first_out = 0;  */
  /*  end */
  /* '<S5>:1:8' */
  for (i = 0; i < 9; i++) {
    L1[i] = 0.0;
    L2[i] = 0.0;
    L3[i] = 0.0;
  }

  L1[0] = ctrl_case_c_P.Constant_Value[0];
  L1[4] = ctrl_case_c_P.Constant_Value[1];
  L1[8] = ctrl_case_c_P.Constant_Value[2];

  /* '<S5>:1:9' */
  L2[0] = ctrl_case_c_P.Constant1_Value[0];
  L2[4] = ctrl_case_c_P.Constant1_Value[1];
  L2[8] = ctrl_case_c_P.Constant1_Value[2];

  /* '<S5>:1:10' */
  L3[0] = ctrl_case_c_P.Constant2_Value[0];
  L3[4] = ctrl_case_c_P.Constant2_Value[1];
  L3[8] = ctrl_case_c_P.Constant2_Value[2];

  /*  The total damping matrix from the handbook page 53 */
  /* '<S5>:1:17' */
  eta_bar_idx_0 = rtb_Switch_idx_0 - ctrl_case_c_B.Memory4[0];
  rtb_Switch_idx_0 = rtb_Switch_idx_1 - ctrl_case_c_B.Memory4[1];
  rtb_Switch_idx_1 = rtb_Switch_idx_2 - ctrl_case_c_B.Memory4[2];

  /* '<S5>:1:18' */
  /* '<S5>:1:19' */
  R[0] = cos(rtb_Switch_idx_2);
  R[3] = sin(rtb_Switch_idx_2);
  R[6] = 0.0;
  R[1] = -sin(rtb_Switch_idx_2);
  R[4] = cos(rtb_Switch_idx_2);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S5>:1:23' */
  /* '<S5>:1:24' */
  for (i = 0; i < 3; i++) {
    R_0[i] = R[i + 6] * ctrl_case_c_B.Memory3[2] + (R[i + 3] *
      ctrl_case_c_B.Memory3[1] + R[i] * ctrl_case_c_B.Memory3[0]);
  }

  for (i = 0; i < 3; i++) {
    L1_0[i] = L1[i + 6] * rtb_Switch_idx_1 + (L1[i + 3] * rtb_Switch_idx_0 +
      L1[i] * eta_bar_idx_0);
  }

  ctrl_case_c_B.eta_hat_dot[0] = R_0[0] + L1_0[0];
  ctrl_case_c_B.eta_hat_dot[1] = R_0[1] + L1_0[1];
  ctrl_case_c_B.eta_hat_dot[2] = R_0[2] + L1_0[2];

  /* '<S5>:1:26' */
  for (i = 0; i < 3; i++) {
    L1_0[i] = b_a[i + 6] * ctrl_case_c_B.Memory3[2] + (b_a[i + 3] *
      ctrl_case_c_B.Memory3[1] + b_a[i] * ctrl_case_c_B.Memory3[0]);
  }

  for (i = 0; i < 3; i++) {
    R_0[i] = R[3 * i + 2] * ctrl_case_c_B.Memory2[2] + (R[3 * i + 1] *
      ctrl_case_c_B.Memory2[1] + R[3 * i] * ctrl_case_c_B.Memory2[0]);
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      L1[i + 3 * i_0] = 0.0;
      L1[i + 3 * i_0] += R[3 * i] * L2[3 * i_0];
      L1[i + 3 * i_0] += R[3 * i + 1] * L2[3 * i_0 + 1];
      L1[i + 3 * i_0] += R[3 * i + 2] * L2[3 * i_0 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    b_a_0[i] = ((L1[i + 3] * rtb_Switch_idx_0 + L1[i] * eta_bar_idx_0) + L1[i +
                6] * rtb_Switch_idx_1) + ((L1_0[i] + R_0[i]) +
      ctrl_case_c_B.PosXRight);
  }

  for (i = 0; i < 3; i++) {
    ctrl_case_c_B.nu_hat_dot[i] = 0.0;
    ctrl_case_c_B.nu_hat_dot[i] += a[i] * b_a_0[0];
    ctrl_case_c_B.nu_hat_dot[i] += a[i + 3] * b_a_0[1];
    ctrl_case_c_B.nu_hat_dot[i] += a[i + 6] * b_a_0[2];
  }

  for (i = 0; i < 3; i++) {
    ctrl_case_c_B.b_hat_dot[i] = 0.0;
    ctrl_case_c_B.b_hat_dot[i] += L3[i] * eta_bar_idx_0;
    ctrl_case_c_B.b_hat_dot[i] += L3[i + 3] * rtb_Switch_idx_0;
    ctrl_case_c_B.b_hat_dot[i] += L3[i + 6] * rtb_Switch_idx_1;
  }

  /* End of MATLAB Function: '<S1>/Observer ' */
  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
  }
}

/* Model update function */
void ctrl_case_c_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
    /* Update for Memory: '<S1>/Memory2' */
    ctrl_case_c_DW.Memory2_PreviousInput[0] = ctrl_case_c_B.Integrator2[0];
    ctrl_case_c_DW.Memory2_PreviousInput[1] = ctrl_case_c_B.Integrator2[1];
    ctrl_case_c_DW.Memory2_PreviousInput[2] = ctrl_case_c_B.Integrator2[2];

    /* Update for Memory: '<S1>/Memory3' */
    ctrl_case_c_DW.Memory3_PreviousInput[0] = ctrl_case_c_B.Integrator1[0];
    ctrl_case_c_DW.Memory3_PreviousInput[1] = ctrl_case_c_B.Integrator1[1];
    ctrl_case_c_DW.Memory3_PreviousInput[2] = ctrl_case_c_B.Integrator1[2];

    /* Update for Memory: '<S1>/Memory4' */
    ctrl_case_c_DW.Memory4_PreviousInput[0] = ctrl_case_c_B.Integrator[0];
    ctrl_case_c_DW.Memory4_PreviousInput[1] = ctrl_case_c_B.Integrator[1];
    ctrl_case_c_DW.Memory4_PreviousInput[2] = ctrl_case_c_B.Integrator[2];

    /* Update for Memory: '<S6>/counter' */
    ctrl_case_c_DW.counter_PreviousInput = ctrl_case_c_B.count;

    /* Update for RandomNumber: '<S12>/White Noise' */
    ctrl_case_c_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed) * ctrl_case_c_P.WhiteNoise_StdDev +
      ctrl_case_c_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S13>/White Noise' */
    ctrl_case_c_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed_j) * ctrl_case_c_P.WhiteNoise_StdDev_d +
      ctrl_case_c_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S11>/White Noise' */
    ctrl_case_c_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed_c) * ctrl_case_c_P.WhiteNoise_StdDev_g +
      ctrl_case_c_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S7>/Hold' */
    ctrl_case_c_DW.Hold_PreviousInput[0] = ctrl_case_c_B.output[0];
    ctrl_case_c_DW.Hold_PreviousInput[1] = ctrl_case_c_B.output[1];
    ctrl_case_c_DW.Hold_PreviousInput[2] = ctrl_case_c_B.output[2];
  }

  if (rtmIsMajorTimeStep(ctrl_case_c_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_case_c_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_case_c_M->Timing.clockTick0)) {
    ++ctrl_case_c_M->Timing.clockTickH0;
  }

  ctrl_case_c_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_case_c_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_case_c_M->Timing.clockTick1)) {
      ++ctrl_case_c_M->Timing.clockTickH1;
    }

    ctrl_case_c_M->Timing.t[1] = ctrl_case_c_M->Timing.clockTick1 *
      ctrl_case_c_M->Timing.stepSize1 + ctrl_case_c_M->Timing.clockTickH1 *
      ctrl_case_c_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_case_c_derivatives(void)
{
  XDot_ctrl_case_c_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_case_c_T *) ctrl_case_c_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_case_c_B.eta_hat_dot[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_case_c_B.eta_hat_dot[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_case_c_B.eta_hat_dot[2];

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_case_c_B.nu_hat_dot[0];
  _rtXdot->Integrator1_CSTATE[1] = ctrl_case_c_B.nu_hat_dot[1];
  _rtXdot->Integrator1_CSTATE[2] = ctrl_case_c_B.nu_hat_dot[2];

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_case_c_B.b_hat_dot[0];
  _rtXdot->Integrator2_CSTATE[1] = ctrl_case_c_B.b_hat_dot[1];
  _rtXdot->Integrator2_CSTATE[2] = ctrl_case_c_B.b_hat_dot[2];
}

/* Model initialize function */
void ctrl_case_c_initialize(void)
{
  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    ctrl_case_c_X.Integrator_CSTATE[0] = ctrl_case_c_P.Integrator_IC;
    ctrl_case_c_X.Integrator_CSTATE[1] = ctrl_case_c_P.Integrator_IC;
    ctrl_case_c_X.Integrator_CSTATE[2] = ctrl_case_c_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    ctrl_case_c_X.Integrator1_CSTATE[0] = ctrl_case_c_P.Integrator1_IC;
    ctrl_case_c_X.Integrator1_CSTATE[1] = ctrl_case_c_P.Integrator1_IC;
    ctrl_case_c_X.Integrator1_CSTATE[2] = ctrl_case_c_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator2' */
    ctrl_case_c_X.Integrator2_CSTATE[0] = ctrl_case_c_P.Integrator2_IC;
    ctrl_case_c_X.Integrator2_CSTATE[1] = ctrl_case_c_P.Integrator2_IC;
    ctrl_case_c_X.Integrator2_CSTATE[2] = ctrl_case_c_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    ctrl_case_c_DW.Memory2_PreviousInput[0] = ctrl_case_c_P.Memory2_X0[0];
    ctrl_case_c_DW.Memory2_PreviousInput[1] = ctrl_case_c_P.Memory2_X0[1];
    ctrl_case_c_DW.Memory2_PreviousInput[2] = ctrl_case_c_P.Memory2_X0[2];

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    ctrl_case_c_DW.Memory3_PreviousInput[0] = ctrl_case_c_P.Memory3_X0[0];
    ctrl_case_c_DW.Memory3_PreviousInput[1] = ctrl_case_c_P.Memory3_X0[1];
    ctrl_case_c_DW.Memory3_PreviousInput[2] = ctrl_case_c_P.Memory3_X0[2];

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    ctrl_case_c_DW.Memory4_PreviousInput[0] = ctrl_case_c_P.Memory4_X0[0];
    ctrl_case_c_DW.Memory4_PreviousInput[1] = ctrl_case_c_P.Memory4_X0[1];
    ctrl_case_c_DW.Memory4_PreviousInput[2] = ctrl_case_c_P.Memory4_X0[2];

    /* InitializeConditions for Memory: '<S6>/counter' */
    ctrl_case_c_DW.counter_PreviousInput = ctrl_case_c_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S12>/White Noise' */
    tmp = floor(ctrl_case_c_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_case_c_DW.RandSeed = tseed;
    ctrl_case_c_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed) * ctrl_case_c_P.WhiteNoise_StdDev +
      ctrl_case_c_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S12>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S13>/White Noise' */
    tmp = floor(ctrl_case_c_P.WhiteNoise_Seed_b);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_case_c_DW.RandSeed_j = tseed;
    ctrl_case_c_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed_j) * ctrl_case_c_P.WhiteNoise_StdDev_d +
      ctrl_case_c_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S13>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S11>/White Noise' */
    tmp = floor(ctrl_case_c_P.WhiteNoise_Seed_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_case_c_DW.RandSeed_c = tseed;
    ctrl_case_c_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_c_DW.RandSeed_c) * ctrl_case_c_P.WhiteNoise_StdDev_g +
      ctrl_case_c_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S11>/White Noise' */

    /* InitializeConditions for Memory: '<S7>/Hold' */
    ctrl_case_c_DW.Hold_PreviousInput[0] = ctrl_case_c_P.Hold_X0;
    ctrl_case_c_DW.Hold_PreviousInput[1] = ctrl_case_c_P.Hold_X0;
    ctrl_case_c_DW.Hold_PreviousInput[2] = ctrl_case_c_P.Hold_X0;
  }
}

/* Model terminate function */
void ctrl_case_c_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_case_c_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_case_c_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_case_c_initialize();
}

void MdlTerminate(void)
{
  ctrl_case_c_terminate();
}

/* Registration function */
RT_MODEL_ctrl_case_c_T *ctrl_case_c(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_case_c_M, 0,
                sizeof(RT_MODEL_ctrl_case_c_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_case_c_M->solverInfo,
                          &ctrl_case_c_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_case_c_M->solverInfo, &rtmGetTPtr(ctrl_case_c_M));
    rtsiSetStepSizePtr(&ctrl_case_c_M->solverInfo,
                       &ctrl_case_c_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_case_c_M->solverInfo, &ctrl_case_c_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_case_c_M->solverInfo, (real_T **)
                         &ctrl_case_c_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_case_c_M->solverInfo,
      &ctrl_case_c_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_case_c_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_case_c_M)));
    rtsiSetRTModelPtr(&ctrl_case_c_M->solverInfo, ctrl_case_c_M);
  }

  rtsiSetSimTimeStep(&ctrl_case_c_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_case_c_M->ModelData.intgData.y = ctrl_case_c_M->ModelData.odeY;
  ctrl_case_c_M->ModelData.intgData.f[0] = ctrl_case_c_M->ModelData.odeF[0];
  ctrl_case_c_M->ModelData.intgData.f[1] = ctrl_case_c_M->ModelData.odeF[1];
  ctrl_case_c_M->ModelData.intgData.f[2] = ctrl_case_c_M->ModelData.odeF[2];
  ctrl_case_c_M->ModelData.intgData.f[3] = ctrl_case_c_M->ModelData.odeF[3];
  ctrl_case_c_M->ModelData.contStates = ((real_T *) &ctrl_case_c_X);
  rtsiSetSolverData(&ctrl_case_c_M->solverInfo, (void *)
                    &ctrl_case_c_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_case_c_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_case_c_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_case_c_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_case_c_M->Timing.sampleTimes = (&ctrl_case_c_M->
      Timing.sampleTimesArray[0]);
    ctrl_case_c_M->Timing.offsetTimes = (&ctrl_case_c_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_case_c_M->Timing.sampleTimes[0] = (0.0);
    ctrl_case_c_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_case_c_M->Timing.offsetTimes[0] = (0.0);
    ctrl_case_c_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_case_c_M, &ctrl_case_c_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_case_c_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_case_c_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_case_c_M, -1);
  ctrl_case_c_M->Timing.stepSize0 = 0.01;
  ctrl_case_c_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_case_c_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_case_c_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_case_c_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_case_c_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_case_c_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_case_c_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_case_c_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_case_c_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_case_c_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_case_c_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_case_c_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_case_c_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_case_c_M->rtwLogInfo, (NULL));
  }

  ctrl_case_c_M->solverInfoPtr = (&ctrl_case_c_M->solverInfo);
  ctrl_case_c_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_case_c_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_case_c_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_case_c_M->ModelData.blockIO = ((void *) &ctrl_case_c_B);
  (void) memset(((void *) &ctrl_case_c_B), 0,
                sizeof(B_ctrl_case_c_T));

  /* parameters */
  ctrl_case_c_M->ModelData.defaultParam = ((real_T *)&ctrl_case_c_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_case_c_X;
    ctrl_case_c_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_case_c_X, 0,
                  sizeof(X_ctrl_case_c_T));
  }

  /* states (dwork) */
  ctrl_case_c_M->ModelData.dwork = ((void *) &ctrl_case_c_DW);
  (void) memset((void *)&ctrl_case_c_DW, 0,
                sizeof(DW_ctrl_case_c_T));

  /* Initialize Sizes */
  ctrl_case_c_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_case_c_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_case_c_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_case_c_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_case_c_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_case_c_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_case_c_M->Sizes.numBlocks = (52);/* Number of blocks */
  ctrl_case_c_M->Sizes.numBlockIO = (30);/* Number of block outputs */
  ctrl_case_c_M->Sizes.numBlockPrms = (128);/* Sum of parameter "widths" */
  return ctrl_case_c_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_case_c
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_case_c_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.L2_continuous, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.PosXRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.PosYRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.R2_continuous, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.ArrowDown, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.ArrowLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_c_B.ArrowRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 15;
}

void SetExternalOutputs(double* data, int* TaskSampleHit)
{
}

long NumOutputPorts(void)
{
  return 0;
}

int NI_InitExternalOutputs()
{
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_case_c/DP Observer /Constant/Value", offsetof(P_ctrl_case_c_T,
    Constant_Value), 20, 3, 2, 0, 0 },

  { 1, "ctrl_case_c/DP Observer /Constant1/Value", offsetof(P_ctrl_case_c_T,
    Constant1_Value), 20, 3, 2, 2, 0 },

  { 2, "ctrl_case_c/DP Observer /Constant2/Value", offsetof(P_ctrl_case_c_T,
    Constant2_Value), 20, 3, 2, 4, 0 },

  { 3, "ctrl_case_c/DP Observer /Integrator/InitialCondition", offsetof
    (P_ctrl_case_c_T, Integrator_IC), 30, 1, 2, 6, 0 },

  { 4, "ctrl_case_c/DP Observer /Integrator1/InitialCondition", offsetof
    (P_ctrl_case_c_T, Integrator1_IC), 30, 1, 2, 8, 0 },

  { 5, "ctrl_case_c/DP Observer /Integrator2/InitialCondition", offsetof
    (P_ctrl_case_c_T, Integrator2_IC), 30, 1, 2, 10, 0 },

  { 6, "ctrl_case_c/DP Observer /Memory2/X0", offsetof(P_ctrl_case_c_T,
    Memory2_X0), 21, 3, 2, 12, 0 },

  { 7, "ctrl_case_c/DP Observer /Memory3/X0", offsetof(P_ctrl_case_c_T,
    Memory3_X0), 21, 3, 2, 14, 0 },

  { 8, "ctrl_case_c/DP Observer /Memory4/X0", offsetof(P_ctrl_case_c_T,
    Memory4_X0), 21, 3, 2, 16, 0 },

  { 9, "ctrl_case_c/Noise generator/Step size/Value", offsetof(P_ctrl_case_c_T,
    Stepsize_Value), 30, 1, 2, 18, 0 },

  { 10, "ctrl_case_c/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_case_c_T, counter_X0), 30, 1, 2, 20, 0 },

  { 11, "ctrl_case_c/Constant4/Value", offsetof(P_ctrl_case_c_T, Constant4_Value),
    30, 1, 2, 22, 0 },

  { 12, "ctrl_case_c/Constant1/Value", offsetof(P_ctrl_case_c_T,
    Constant1_Value_c), 30, 1, 2, 24, 0 },

  { 13,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Mean), 30, 1, 2, 26, 0 },

  { 14,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_case_c_T, WhiteNoise_StdDev), 30, 1, 2, 28, 0 },

  { 15,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Seed), 30, 1, 2, 30, 0 },

  { 16,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Mean_h), 30, 1, 2, 32, 0 },

  { 17,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_case_c_T, WhiteNoise_StdDev_d), 30, 1, 2, 34, 0 },

  { 18,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Seed_b), 30, 1, 2, 36, 0 },

  { 19, "ctrl_case_c/Constant2/Value", offsetof(P_ctrl_case_c_T,
    Constant2_Value_i), 30, 1, 2, 38, 0 },

  { 20,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Mean_f), 30, 1, 2, 40, 0 },

  { 21,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_case_c_T, WhiteNoise_StdDev_g), 30, 1, 2, 42, 0 },

  { 22,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_case_c_T, WhiteNoise_Seed_l), 30, 1, 2, 44, 0 },

  { 23, "ctrl_case_c/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_case_c_T, Hold_X0), 30, 1, 2, 46, 0 },

  { 24, "ctrl_case_c/Constant3/Value", offsetof(P_ctrl_case_c_T, Constant3_Value),
    30, 1, 2, 48, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 25;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 3,                                /* Parameter at index 0 */
  1, 3,                                /* Parameter at index 1 */
  1, 3,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  3, 1,                                /* Parameter at index 6 */
  3, 1,                                /* Parameter at index 7 */
  3, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_case_c/y_in", 0, "", offsetof(B_ctrl_case_c_T, y_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_case_c/psi_in", 0, "", offsetof(B_ctrl_case_c_T, psi_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_case_c/DP Observer /Integrator", 0, "(1,1)", offsetof
    (B_ctrl_case_c_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 4, 0
  },

  { 3, "ctrl_case_c/DP Observer /Integrator", 0, "(1,2)", offsetof
    (B_ctrl_case_c_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 6, 0
  },

  { 4, "ctrl_case_c/DP Observer /Integrator", 0, "(1,3)", offsetof
    (B_ctrl_case_c_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 8, 0
  },

  { 5, "ctrl_case_c/DP Observer /Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_case_c_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 10,
    0 },

  { 6, "ctrl_case_c/DP Observer /Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_case_c_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 12,
    0 },

  { 7, "ctrl_case_c/DP Observer /Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_case_c_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 14,
    0 },

  { 8, "ctrl_case_c/DP Observer /Integrator2", 0, "(1,1)", offsetof
    (B_ctrl_case_c_T, Integrator2)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 16,
    0 },

  { 9, "ctrl_case_c/DP Observer /Integrator2", 0, "(1,2)", offsetof
    (B_ctrl_case_c_T, Integrator2)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 18,
    0 },

  { 10, "ctrl_case_c/DP Observer /Integrator2", 0, "(1,3)", offsetof
    (B_ctrl_case_c_T, Integrator2)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 20,
    0 },

  { 11, "ctrl_case_c/DP Observer /Memory2", 0, "(1,1)", offsetof(B_ctrl_case_c_T,
    Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 22, 0 },

  { 12, "ctrl_case_c/DP Observer /Memory2", 0, "(1,2)", offsetof(B_ctrl_case_c_T,
    Memory2)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 24, 0 },

  { 13, "ctrl_case_c/DP Observer /Memory2", 0, "(1,3)", offsetof(B_ctrl_case_c_T,
    Memory2)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 26, 0 },

  { 14, "ctrl_case_c/DP Observer /Memory3", 0, "(1,1)", offsetof(B_ctrl_case_c_T,
    Memory3)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 28, 0 },

  { 15, "ctrl_case_c/DP Observer /Memory3", 0, "(1,2)", offsetof(B_ctrl_case_c_T,
    Memory3)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 30, 0 },

  { 16, "ctrl_case_c/DP Observer /Memory3", 0, "(1,3)", offsetof(B_ctrl_case_c_T,
    Memory3)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 32, 0 },

  { 17, "ctrl_case_c/DP Observer /Memory4", 0, "(1,1)", offsetof(B_ctrl_case_c_T,
    Memory4)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 34, 0 },

  { 18, "ctrl_case_c/DP Observer /Memory4", 0, "(1,2)", offsetof(B_ctrl_case_c_T,
    Memory4)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 36, 0 },

  { 19, "ctrl_case_c/DP Observer /Memory4", 0, "(1,3)", offsetof(B_ctrl_case_c_T,
    Memory4)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 38, 0 },

  { 20,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise x/Product",
    0, "", offsetof(B_ctrl_case_c_T, Product)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 40, 0 },

  { 21,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise y/Product",
    0, "", offsetof(B_ctrl_case_c_T, Product_l)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 42, 0 },

  { 22,
    "ctrl_case_c/Noise generator/noise generator/Band-limited white noise psi/Product",
    0, "", offsetof(B_ctrl_case_c_T, Product_e)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 44, 0 },

  { 23, "ctrl_case_c/x_in", 0, "", offsetof(B_ctrl_case_c_T, x_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 46, 0 },

  { 24, "ctrl_case_c/Noise generator/Sample & hold/Hold", 0, "(1,1)", offsetof
    (B_ctrl_case_c_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 48, 0 },

  { 25, "ctrl_case_c/Noise generator/Sample & hold/Hold", 0, "(1,2)", offsetof
    (B_ctrl_case_c_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 50, 0 },

  { 26, "ctrl_case_c/Noise generator/Sample & hold/Hold", 0, "(1,3)", offsetof
    (B_ctrl_case_c_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 52, 0 },

  { 27, "ctrl_case_c/joystick/L2_continuous", 0, "", offsetof(B_ctrl_case_c_T,
    L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28, "ctrl_case_c/joystick/PosXRight", 0, "", offsetof(B_ctrl_case_c_T,
    PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29, "ctrl_case_c/joystick/PosYRight", 0, "", offsetof(B_ctrl_case_c_T,
    PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_case_c/joystick/R2_continuous", 0, "", offsetof(B_ctrl_case_c_T,
    R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 60, 0 },

  { 31, "ctrl_case_c/joystick/PosXLeft", 0, "", offsetof(B_ctrl_case_c_T,
    PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 62, 0 },

  { 32, "ctrl_case_c/joystick/PosYLeft", 0, "", offsetof(B_ctrl_case_c_T,
    PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 64, 0 },

  { 33, "ctrl_case_c/joystick/L1", 0, "", offsetof(B_ctrl_case_c_T, L1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 66, 0 },

  { 34, "ctrl_case_c/joystick/R1", 0, "", offsetof(B_ctrl_case_c_T, R1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35, "ctrl_case_c/joystick/ArrowDown", 0, "", offsetof(B_ctrl_case_c_T,
    ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 70, 0 },

  { 36, "ctrl_case_c/joystick/ArrowUp", 0, "", offsetof(B_ctrl_case_c_T, ArrowUp)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72, 0 },

  { 37, "ctrl_case_c/joystick/ArrowLeft", 0, "", offsetof(B_ctrl_case_c_T,
    ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74, 0 },

  { 38, "ctrl_case_c/joystick/ArrowRight", 0, "", offsetof(B_ctrl_case_c_T,
    ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 76, 0 },

  { 39, "ctrl_case_c/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_case_c_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 78, 0 },

  { 40, "ctrl_case_c/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_case_c_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 80, 0 },

  { 41, "ctrl_case_c/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_case_c_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 82, 0 },

  { 42, "ctrl_case_c/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_case_c_T, count)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 84, 0 },

  { 43, "ctrl_case_c/DP Observer /Observer", 0, "eta_hat_dot(1,1)", offsetof
    (B_ctrl_case_c_T, eta_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 86,
    0 },

  { 44, "ctrl_case_c/DP Observer /Observer", 0, "eta_hat_dot(1,2)", offsetof
    (B_ctrl_case_c_T, eta_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 88,
    0 },

  { 45, "ctrl_case_c/DP Observer /Observer", 0, "eta_hat_dot(1,3)", offsetof
    (B_ctrl_case_c_T, eta_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 90,
    0 },

  { 46, "ctrl_case_c/DP Observer /Observer", 1, "nu_hat_dot(1,1)", offsetof
    (B_ctrl_case_c_T, nu_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 92, 0
  },

  { 47, "ctrl_case_c/DP Observer /Observer", 1, "nu_hat_dot(1,2)", offsetof
    (B_ctrl_case_c_T, nu_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 94, 0
  },

  { 48, "ctrl_case_c/DP Observer /Observer", 1, "nu_hat_dot(1,3)", offsetof
    (B_ctrl_case_c_T, nu_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 96, 0
  },

  { 49, "ctrl_case_c/DP Observer /Observer", 2, "b_hat_dot(1,1)", offsetof
    (B_ctrl_case_c_T, b_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 98, 0
  },

  { 50, "ctrl_case_c/DP Observer /Observer", 2, "b_hat_dot(1,2)", offsetof
    (B_ctrl_case_c_T, b_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 100, 0
  },

  { 51, "ctrl_case_c/DP Observer /Observer", 2, "b_hat_dot(1,3)", offsetof
    (B_ctrl_case_c_T, b_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 102, 0
  },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 52;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 15;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 4, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 5, "joystick/PosYRight", 1, EXT_IN, 1, 1, 1 },

  { 6, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 7, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 9, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 10, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 11, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 12, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 13, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 14, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_case_c";
static char* NI_CompiledModelVersion = "1.136";
static char* NI_CompiledModelDateTime = "Thu Mar 02 14:20:58 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_case_c_P
   In the rest of the code ctrl_case_c_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_case_c_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_case_c_P, sizeof(P_ctrl_case_c_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_case_c_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_case_c_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_case_c_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_case_c_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_case_c_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_case_c_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_case_c_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 9;
      *numDiscStates = 282;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE
      [0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE
      [0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE
      [0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE
      [0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE
      [0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE
      [0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.y_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.psi_in_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory2_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory2_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory2_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory3_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory3_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory3_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory4_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory4_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.Memory4_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.NextOutput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.NextOutput_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.NextOutput_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.x_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput,
      0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput,
      1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput,
      2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosXRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosYRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosXLeft_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosYLeft_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.L1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.R1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowDown_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowUp_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowLeft_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.RandSeed_j, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.RandSeed_c, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.RandSeed_c");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.y_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.y_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.psi_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.x_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.x_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_c_DW.L2_continuous_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_c_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosXRight_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosYRight_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_c_DW.R2_continuous_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_c_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosXLeft_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.PosYLeft_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.L1_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.L1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.R1_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.R1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowDown_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowUp_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_c_DW.ArrowLeft_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_c_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_c_DW.ArrowRight_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_c_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK1, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 55; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK3, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK3");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_case_c_DW.y_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.psi_in_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory2_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory2_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory3_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory3_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory4_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory4_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Memory4_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.NextOutput, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.NextOutput_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.NextOutput_p, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.x_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.PosXRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.PosYRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.PosXLeft_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.PosYLeft_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.L1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.R1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowDown_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowUp_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowLeft_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK2, 0,
      discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.RandSeed, 0, discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.RandSeed_j, 0, discStates[idx++], 7,
      0);
    NIRT_SetValueByDataType(&ctrl_case_c_DW.RandSeed_c, 0, discStates[idx++], 7,
      0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.y_in_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.psi_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.x_in_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.PosXRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.PosYRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.L1_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.R1_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 55; count++) {
      NIRT_SetValueByDataType(&ctrl_case_c_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 19, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_case_c
