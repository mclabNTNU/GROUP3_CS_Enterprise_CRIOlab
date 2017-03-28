/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.149
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Mar 28 11:39:03 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

const real_T ctrl_student_HIL_RGND = 0.0;/* real_T ground */

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_T ctrl_student_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/* Forward declaration for local functions */
static void ctrl_student_HIL_diag(const real_T v[3], real_T d[9]);
static real_T ctrl_student_HIL_norm(const real_T x[3]);
static real_T ctrl_student_HIL_angdiff(real_T alpha, real_T beta);

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
  int_T nXc = 18;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Transfer function' */
static void ctrl_student_HIL_diag(const real_T v[3], real_T d[9])
{
  memset(&d[0], 0, 9U * sizeof(real_T));
  d[0] = v[0];
  d[4] = v[1];
  d[8] = v[2];
}

/* Function for MATLAB Function: '<Root>/Transfer function' */
static real_T ctrl_student_HIL_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Transfer function' */
static real_T ctrl_student_HIL_angdiff(real_T alpha, real_T beta)
{
  real_T r;

  /* '<S6>:1:242' */
  r = ((beta - alpha) + 3.1415926535897931) / 6.2831853071795862;
  if (fabs(r - rt_roundd_snf(r)) <= 2.2204460492503131E-16 * fabs(r)) {
    r = 0.0;
  } else {
    r = (r - floor(r)) * 6.2831853071795862;
  }

  return r - 3.1415926535897931;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator_l;
  real_T rtb_Integrator_p;
  ZCEventType zcEvent;
  int32_T r;
  real_T s_dot;
  real_T K_p[9];
  real_T K_2[9];
  real_T D_tot[9];
  real_T U_s;
  real_T eta_d_s[3];
  real_T S[9];
  real_T R[9];
  real_T z_2[3];
  real_T z[2];
  real_T absx;
  int32_T j;
  static const real_T c_a[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  boolean_T exitg1;
  int32_T exitg2;
  static const real_T a[9] = { 0.059559261465157838, -0.0, 0.0, -0.0,
    0.040521023365024243, -0.0081427436897922364, -0.0, -0.0081427436897922364,
    0.36395513377498229 };

  real_T rtb_Product_a;
  real_T rtb_Product;
  real_T tmp[3];
  real_T K_p_0[9];
  real_T R_0[3];
  real_T S_0[3];
  real_T S_1[9];
  real_T S_2[3];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T rtb_eta_idx_2;
  real_T rtb_Gain_idx_2;
  real_T rtb_Gain_idx_0;
  real_T rtb_Gain_idx_1;
  real_T rtb_eta_idx_0;
  real_T rtb_eta_idx_1;
  real_T diff_idx_1;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S2>/Memory' */
    ctrl_student_HIL_B.Memory[0] = ctrl_student_HIL_DW.Memory_PreviousInput[0];
    ctrl_student_HIL_B.Memory[1] = ctrl_student_HIL_DW.Memory_PreviousInput[1];
    ctrl_student_HIL_B.Memory[2] = ctrl_student_HIL_DW.Memory_PreviousInput[2];

    /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
     *  Constant: '<S13>/Step size'
     *  Constant: '<S4>/Constant4'
     *  Memory: '<S14>/counter'
     */
    /* MATLAB Function 'Noise Generator/Noise generator/Downsample	signal/MATLAB Function': '<S17>:1' */
    /* '<S17>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Constant4_Value) {
      /* '<S17>:1:4' */
      /* '<S17>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S17>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S14>/MATLAB Function' */
  }

  /* Gain: '<S4>/Gain' */
  rtb_Product_a = ctrl_student_HIL_P.Gain_Gain * ctrl_student_HIL_B.noisepos;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S20>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;
  }

  /* Product: '<S20>/Product' incorporates:
   *  Constant: '<S13>/Step size'
   *  Product: '<S20>/Divide'
   *  Sqrt: '<S20>/Sqrt'
   */
  rtb_Product = sqrt(rtb_Product_a / ctrl_student_HIL_P.Stepsize_Value) *
    ctrl_student_HIL_B.WhiteNoise;

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S13>/Step size'
   */
  rtb_Product_a /= ctrl_student_HIL_P.Stepsize_Value;

  /* Sqrt: '<S21>/Sqrt' */
  rtb_Product_a = sqrt(rtb_Product_a);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S21>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_a = ctrl_student_HIL_DW.NextOutput_p;
  }

  /* Product: '<S21>/Product' */
  rtb_Product_a *= ctrl_student_HIL_B.WhiteNoise_a;

  /* Product: '<S19>/Divide' incorporates:
   *  Constant: '<S13>/Step size'
   *  Gain: '<S4>/Gain1'
   */
  rtb_Integrator_p = ctrl_student_HIL_P.Gain1_Gain *
    ctrl_student_HIL_B.noisehead / ctrl_student_HIL_P.Stepsize_Value;

  /* Sqrt: '<S19>/Sqrt' */
  rtb_Integrator_p = sqrt(rtb_Integrator_p);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_f = ctrl_student_HIL_DW.NextOutput_i;
  }

  /* Product: '<S19>/Product' */
  rtb_Integrator_p *= ctrl_student_HIL_B.WhiteNoise_f;

  /* Gain: '<Root>/Gain' */
  rtb_Gain_idx_2 = ctrl_student_HIL_P.Gain_Gain_d[2] * ctrl_student_HIL_B.psi;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Gain: '<Root>/Gain'
   */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  /* '<S3>:1:2' */
  ctrl_student_HIL_B.eta1[0] = ctrl_student_HIL_P.Gain_Gain_d[0] *
    ctrl_student_HIL_B.x;
  ctrl_student_HIL_B.eta1[1] = ctrl_student_HIL_P.Gain_Gain_d[1] *
    ctrl_student_HIL_B.y;
  ctrl_student_HIL_B.eta1[2] = rtb_Gain_idx_2;

  /* '<S3>:1:3' */
  /* '<S3>:1:6' */
  absx = ((rtb_Gain_idx_2 - 3.1415926535897931) + 3.1415926535897931) /
    6.2831853071795862;
  if (fabs(absx - rt_roundd_snf(absx)) <= 2.2204460492503131E-16 * fabs(absx)) {
    absx = 0.0;
  } else {
    absx = (absx - floor(absx)) * 6.2831853071795862;
  }

  ctrl_student_HIL_B.eta1[2] = absx - 3.1415926535897931;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S15>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S15>/MATLAB Function1' incorporates:
   *  Sum: '<S13>/Sum'
   */
  /* MATLAB Function 'Noise Generator/Noise generator/Sample & hold/MATLAB Function1': '<S18>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S18>:1:4' */
    /* '<S18>:1:5' */
    ctrl_student_HIL_B.output[0] = rtb_Product + ctrl_student_HIL_B.eta1[0];
    ctrl_student_HIL_B.output[1] = rtb_Product_a + ctrl_student_HIL_B.eta1[1];
    ctrl_student_HIL_B.output[2] = rtb_Integrator_p + ctrl_student_HIL_B.eta1[2];
  } else {
    /* '<S18>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function1' */

  /* Switch: '<S13>/Switch' */
  if (ctrl_student_HIL_B.enablenoise != 0.0) {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.eta1[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.eta1[1];
    ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_B.eta1[2];
  }

  /* End of Switch: '<S13>/Switch' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /* MATLAB Function 'Dead reckoning/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:2' */
  /* '<S11>:1:3' */
  ctrl_student_HIL_B.dead[0] = 0.0;
  ctrl_student_HIL_B.dead[1] = 0.0;
  ctrl_student_HIL_B.dead[2] = 0.0;

  /* '<S11>:1:4' */
  /* '<S11>:1:4' */
  if ((ctrl_student_HIL_B.Switch[0] == ctrl_student_HIL_B.Memory[0]) ||
      (ctrl_student_HIL_B.drop_out != 0.0)) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    ctrl_student_HIL_B.dead[0] = 1.0;

    /* '<S11>:1:7' */
    ctrl_student_HIL_B.newmem[0] = ctrl_student_HIL_B.Memory[0];
  } else {
    /* '<S11>:1:9' */
    ctrl_student_HIL_B.newmem[0] = ctrl_student_HIL_B.Switch[0];
  }

  /* '<S11>:1:4' */
  if ((ctrl_student_HIL_B.Switch[1] == ctrl_student_HIL_B.Memory[1]) ||
      (ctrl_student_HIL_B.drop_out != 0.0)) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    ctrl_student_HIL_B.dead[1] = 1.0;

    /* '<S11>:1:7' */
    ctrl_student_HIL_B.newmem[1] = ctrl_student_HIL_B.Memory[1];
  } else {
    /* '<S11>:1:9' */
    ctrl_student_HIL_B.newmem[1] = ctrl_student_HIL_B.Switch[1];
  }

  /* '<S11>:1:4' */
  if ((ctrl_student_HIL_B.Switch[2] == ctrl_student_HIL_B.Memory[2]) ||
      (ctrl_student_HIL_B.drop_out != 0.0)) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    ctrl_student_HIL_B.dead[2] = 1.0;

    /* '<S11>:1:7' */
    ctrl_student_HIL_B.newmem[2] = ctrl_student_HIL_B.Memory[2];
  } else {
    /* '<S11>:1:9' */
    ctrl_student_HIL_B.newmem[2] = ctrl_student_HIL_B.Switch[2];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  /* '<S11>:1:4' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[
                       0],
                       (ctrl_student_HIL_B.dead[0]));
    if (zcEvent != NO_ZCEVENT) {
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[0] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[3] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
      ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[0] = 0;
      rtsiSetSolverNeedsReset(&ctrl_student_HIL_M->solverInfo, true);
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[
                       1],
                       (ctrl_student_HIL_B.dead[1]));
    if (zcEvent != NO_ZCEVENT) {
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[1] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[4] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
      ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[1] = 0;
      rtsiSetSolverNeedsReset(&ctrl_student_HIL_M->solverInfo, true);
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[
                       2],
                       (ctrl_student_HIL_B.dead[2]));
    if (zcEvent != NO_ZCEVENT) {
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[2] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[5] =
        ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
      ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[2] = 0;
      rtsiSetSolverNeedsReset(&ctrl_student_HIL_M->solverInfo, true);
    }
  }

  eta_d_s[0] = ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[0];
  eta_d_s[1] = ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[1];

  /* End of SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */

  /* Integrator: '<S2>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.dead[2]);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;
    }
  }

  rtb_Integrator = ctrl_student_HIL_X.Integrator_CSTATE;

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  /* MATLAB Function 'Dead reckoning/MATLAB Function1': '<S12>:1' */
  /* '<S12>:1:2' */
  /* '<S12>:1:3' */
  if (ctrl_student_HIL_B.dead[0] != 0.0) {
    /* '<S12>:1:5' */
    rtb_eta_idx_0 = eta_d_s[0];
  } else {
    /* '<S12>:1:7' */
    rtb_eta_idx_0 = ctrl_student_HIL_B.newmem[0];
  }

  /* '<S12>:1:3' */
  if (ctrl_student_HIL_B.dead[1] != 0.0) {
    /* '<S12>:1:5' */
    rtb_eta_idx_1 = eta_d_s[1];
  } else {
    /* '<S12>:1:7' */
    rtb_eta_idx_1 = ctrl_student_HIL_B.newmem[1];
  }

  /* '<S12>:1:3' */
  if (ctrl_student_HIL_B.dead[2] != 0.0) {
    /* '<S12>:1:11' */
    rtb_eta_idx_2 = rtb_Integrator;
  } else {
    /* '<S12>:1:13' */
    rtb_eta_idx_2 = ctrl_student_HIL_B.newmem[2];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* Integrator: '<Root>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_j,
                       ctrl_student_HIL_B.case_number);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE_m =
        ctrl_student_HIL_P.Integrator_IC_g;
    }
  }

  rtb_Integrator_l = ctrl_student_HIL_X.Integrator_CSTATE_m;

  /* Integrator: '<S1>/Integrator' */
  ctrl_student_HIL_B.Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE_i[0];
  ctrl_student_HIL_B.Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE_i[1];
  ctrl_student_HIL_B.Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE_i[2];

  /* Switch: '<S1>/Switch' */
  if (ctrl_student_HIL_B.use_dp_observer > ctrl_student_HIL_P.Switch_Threshold)
  {
    rtb_Gain_idx_0 = rtb_eta_idx_0;
    rtb_Gain_idx_1 = rtb_eta_idx_1;
    rtb_Gain_idx_2 = rtb_eta_idx_2;
  } else {
    rtb_Gain_idx_0 = ctrl_student_HIL_B.Integrator[0];
    rtb_Gain_idx_1 = ctrl_student_HIL_B.Integrator[1];
    rtb_Gain_idx_2 = ctrl_student_HIL_B.Integrator[2];
  }

  /* End of Switch: '<S1>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<Root>/Memory' */
    ctrl_student_HIL_B.Memory_l[0] = ctrl_student_HIL_DW.Memory_PreviousInput_g
      [0];
    ctrl_student_HIL_B.Memory_l[1] = ctrl_student_HIL_DW.Memory_PreviousInput_g
      [1];
    ctrl_student_HIL_B.Memory_l[2] = ctrl_student_HIL_DW.Memory_PreviousInput_g
      [2];
  }

  /* MATLAB Function: '<Root>/Transfer function' */
  /* MATLAB Function 'Transfer function': '<S6>:1' */
  /* % Constants */
  /* '<S6>:1:3' */
  /* '<S6>:1:4' */
  S_2[0] = ctrl_student_HIL_B.kp1;
  S_2[1] = ctrl_student_HIL_B.kp2;
  S_2[2] = ctrl_student_HIL_B.kp3;
  ctrl_student_HIL_diag(S_2, K_p_0);

  /* '<S6>:1:5' */
  tmp[0] = ctrl_student_HIL_B.k2_1;
  tmp[1] = ctrl_student_HIL_B.k2_2;
  tmp[2] = ctrl_student_HIL_B.k2_3;
  ctrl_student_HIL_diag(tmp, S_1);
  for (r = 0; r < 9; r++) {
    K_p[r] = K_p_0[r] / 100.0;
    K_2[r] = S_1[r] / 100.0;
  }

  /* % Parameters */
  /*  Rigid body and added mass */
  /*  y_g = 0.0; */
  /*  Max Values in Surge X, Sway Y and Yaw N */
  /* [N] */
  /* [Nm] */
  /*  Hydro surge, Hydro sway and Hydro Yaw Parameters */
  /*  NB! We don't need most of them for now, that why they are commented */
  /*  out, but don't remove them!! */
  /* '<S6>:1:29' */
  /* '<S6>:1:32' */
  /*  Matrices */
  /* '<S6>:1:39' */
  /*  I need a test values;  */
  /* '<S6>:1:47' */
  /* '<S6>:1:48' */
  /* '<S6>:1:49' */
  /* '<S6>:1:50' */
  /* '<S6>:1:51' */
  /*  The total damping matrix from the handbook page 53 */
  /* '<S6>:1:54' */
  D_tot[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Memory_l[0])) -
    ctrl_student_HIL_B.Memory_l[0] * ctrl_student_HIL_B.Memory_l[0] * -3.787;
  D_tot[3] = 0.0;
  D_tot[6] = 0.0;
  D_tot[1] = 0.0;
  D_tot[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Memory_l[1])) -
              ctrl_student_HIL_B.Memory_l[1] * ctrl_student_HIL_B.Memory_l[1] *
              -64.91) - -0.805 * fabs(ctrl_student_HIL_B.Memory_l[2]);
  D_tot[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.Memory_l[1])) - -3.45 *
              fabs(ctrl_student_HIL_B.Memory_l[2])) -
    ctrl_student_HIL_B.Memory_l[2] * ctrl_student_HIL_B.Memory_l[2] * 0.0;
  D_tot[2] = 0.0;
  D_tot[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Memory_l[1])) -
              ctrl_student_HIL_B.Memory_l[1] * ctrl_student_HIL_B.Memory_l[1] *
              0.0) - 0.13 * fabs(ctrl_student_HIL_B.Memory_l[2]);
  D_tot[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.Memory_l[1])) - -0.75 * fabs
              (ctrl_student_HIL_B.Memory_l[2])) - ctrl_student_HIL_B.Memory_l[2]
    * ctrl_student_HIL_B.Memory_l[2] * 0.0;
  switch ((int32_T)ctrl_student_HIL_B.case_number) {
   case 1:
    /*         %% Straight line */
    /*         %% Speed mapping */
    /* '<S6>:1:61' */
    U_s = 0.020706594118782552;

    /*         %% Reference mapping */
    /* '<S6>:1:65' */
    if (rtb_Integrator_l <= 1.0) {
      rtb_Product_a = rtb_Integrator_l;
    } else {
      rtb_Product_a = 1.0;
    }

    if (!(rtb_Product_a >= 0.0)) {
      rtb_Product_a = 0.0;
    }

    /* '<S6>:1:66' */
    /* '<S6>:1:74' */
    ctrl_student_HIL_B.eta_d[0] = rtb_Product_a * 8.0 + 2.0;
    ctrl_student_HIL_B.eta_d[1] = rtb_Product_a * 4.0;
    ctrl_student_HIL_B.eta_d[2] = 0.46364760900080609;

    /* '<S6>:1:75' */
    eta_d_s[0] = 8.0;
    eta_d_s[1] = 4.0;
    eta_d_s[2] = 0.0;

    /*         %% Update law */
    /* '<S6>:1:79' */
    /* '<S6>:1:242' */
    absx = ((rtb_Gain_idx_2 - ctrl_student_HIL_B.eta_d[2]) + 3.1415926535897931)
      / 6.2831853071795862;
    if (fabs(absx - rt_roundd_snf(absx)) <= 2.2204460492503131E-16 * fabs(absx))
    {
      absx = 0.0;
    } else {
      absx = (absx - floor(absx)) * 6.2831853071795862;
    }

    /* '<S6>:1:83' */
    s_dot = 0.020706594118782552 - ((-(rtb_Gain_idx_0 -
      ctrl_student_HIL_B.eta_d[0]) * ctrl_student_HIL_B.mu * 8.0 +
      -(rtb_Gain_idx_1 - ctrl_student_HIL_B.eta_d[1]) * ctrl_student_HIL_B.mu *
      4.0) + -(absx - 3.1415926535897931) * ctrl_student_HIL_B.mu * 0.0) /
      8.94427190999916;
    if (rtb_Integrator_l >= 1.0) {
      /* '<S6>:1:85' */
      /* '<S6>:1:86' */
      s_dot = 0.0;

      /* '<S6>:1:87' */
      eta_d_s[0] = 0.0;
      eta_d_s[1] = 0.0;
      eta_d_s[2] = 0.0;
    }
    break;

   case 2:
    /*         %% Forward and backward on a straight line */
    /*         %% Speed mapping */
    /* '<S6>:1:93' */
    U_s = 0.020706594118782552;

    /*         %% Reference mapping */
    /*  These work, but go out of bounds below. */
    /* '<S6>:1:98' */
    rtb_Product_a = sin(rtb_Integrator_l);

    /* '<S6>:1:99' */
    rtb_Product = cos(rtb_Integrator_l);

    /* '<S6>:1:102' */
    /* '<S6>:1:103' */
    /* '<S6>:1:105' */
    /* '<S6>:1:106' */
    /* '<S6>:1:111' */
    ctrl_student_HIL_B.eta_d[0] = rtb_Product_a * 8.0 / 2.0 + 4.0;
    ctrl_student_HIL_B.eta_d[1] = rtb_Product_a * 4.0 / 2.0 + 2.0;
    ctrl_student_HIL_B.eta_d[2] = 0.46364760900080609;

    /* '<S6>:1:112' */
    eta_d_s[0] = rtb_Product * 8.0 / 2.0;
    eta_d_s[1] = rtb_Product * 4.0 / 2.0;
    eta_d_s[2] = 0.0;

    /*         %% Update law */
    /* '<S6>:1:116' */
    absx = rtb_Gain_idx_0 - ctrl_student_HIL_B.eta_d[0];
    diff_idx_1 = rtb_Gain_idx_1 - ctrl_student_HIL_B.eta_d[1];

    /* '<S6>:1:116' */
    /* '<S6>:1:242' */
    rtb_Product_a = ((rtb_Gain_idx_2 - ctrl_student_HIL_B.eta_d[2]) +
                     3.1415926535897931) / 6.2831853071795862;
    if (fabs(rtb_Product_a - rt_roundd_snf(rtb_Product_a)) <=
        2.2204460492503131E-16 * fabs(rtb_Product_a)) {
      rtb_Product_a = 0.0;
    } else {
      rtb_Product_a = (rtb_Product_a - floor(rtb_Product_a)) *
        6.2831853071795862;
    }

    if (ctrl_student_HIL_norm(eta_d_s) < 1.0E-5) {
      /* '<S6>:1:117' */
      /* '<S6>:1:118' */
      s_dot = 0.020706594118782552 - ((ctrl_student_HIL_B.mu * -absx +
        ctrl_student_HIL_B.mu * -diff_idx_1) + -(rtb_Product_a -
        3.1415926535897931) * ctrl_student_HIL_B.mu) / 1.7320508075688772;
    } else {
      /* '<S6>:1:120' */
      s_dot = 0.020706594118782552 - ((ctrl_student_HIL_B.mu * -absx * eta_d_s[0]
        + ctrl_student_HIL_B.mu * -diff_idx_1 * eta_d_s[1]) + -(rtb_Product_a -
        3.1415926535897931) * ctrl_student_HIL_B.mu * 0.0) /
        ctrl_student_HIL_norm(eta_d_s);
    }
    break;

   case 3:
    /*         %% Forward and backward on a straight line with sinusoidal parametrization of U_ref */
    /*         %% Speed mapping */
    /* '<S6>:1:125' */
    /* '<S6>:1:126' */
    U_s = (sin(6.2831853071795862 * rtb_Integrator_l - 1.5707963267948966) +
           1.01) * 0.13096000000000002 / 6.324555320336759;

    /*         %% Reference mapping */
    /* '<S6>:1:130' */
    rtb_Product_a = sin(rtb_Integrator_l);

    /* '<S6>:1:131' */
    rtb_Product = cos(rtb_Integrator_l);

    /* '<S6>:1:134' */
    /* '<S6>:1:135' */
    /* '<S6>:1:137' */
    /* '<S6>:1:138' */
    /* '<S6>:1:143' */
    ctrl_student_HIL_B.eta_d[0] = rtb_Product_a * 8.0 / 2.0 + 4.0;
    ctrl_student_HIL_B.eta_d[1] = rtb_Product_a * 4.0 / 2.0 + 2.0;
    ctrl_student_HIL_B.eta_d[2] = 0.46364760900080609;

    /* '<S6>:1:144' */
    eta_d_s[0] = rtb_Product * 8.0 / 2.0;
    eta_d_s[1] = rtb_Product * 4.0 / 2.0;
    eta_d_s[2] = 0.0;

    /*         %% Update law */
    /* '<S6>:1:148' */
    absx = rtb_Gain_idx_0 - ctrl_student_HIL_B.eta_d[0];
    diff_idx_1 = rtb_Gain_idx_1 - ctrl_student_HIL_B.eta_d[1];

    /* '<S6>:1:148' */
    /* '<S6>:1:242' */
    rtb_Product_a = ((rtb_Gain_idx_2 - ctrl_student_HIL_B.eta_d[2]) +
                     3.1415926535897931) / 6.2831853071795862;
    if (fabs(rtb_Product_a - rt_roundd_snf(rtb_Product_a)) <=
        2.2204460492503131E-16 * fabs(rtb_Product_a)) {
      rtb_Product_a = 0.0;
    } else {
      rtb_Product_a = (rtb_Product_a - floor(rtb_Product_a)) *
        6.2831853071795862;
    }

    if (ctrl_student_HIL_norm(eta_d_s) < 1.0E-5) {
      /* '<S6>:1:149' */
      /* '<S6>:1:150' */
      s_dot = U_s - ((ctrl_student_HIL_B.mu * -absx + ctrl_student_HIL_B.mu *
                      -diff_idx_1) + -(rtb_Product_a - 3.1415926535897931) *
                     ctrl_student_HIL_B.mu) / 1.7320508075688772;
    } else {
      /* '<S6>:1:152' */
      s_dot = U_s - ((ctrl_student_HIL_B.mu * -absx * eta_d_s[0] +
                      ctrl_student_HIL_B.mu * -diff_idx_1 * eta_d_s[1]) +
                     -(rtb_Product_a - 3.1415926535897931) *
                     ctrl_student_HIL_B.mu * 0.0) / ctrl_student_HIL_norm
        (eta_d_s);
    }
    break;

   case 4:
    /*         %% Ellipse tracking */
    /* '<S6>:1:156' */
    /*         %% Speed mapping */
    /*  rx = 5; */
    /*  ry = 3; */
    /* '<S6>:1:162' */
    absx = ctrl_student_HIL_B.rx * sin(rtb_Integrator_l);
    rtb_Product_a = ctrl_student_HIL_B.ry * cos(rtb_Integrator_l);
    U_s = 0.06548000000000001 / sqrt(absx * absx + rtb_Product_a * rtb_Product_a);

    /*         %% Reference mapping */
    /* '<S6>:1:166' */
    /* '<S6>:1:167' */
    /* '<S6>:1:169' */
    /* '<S6>:1:170' */
    rtb_Product_a = cos(rtb_Integrator_l);
    rtb_Product = sin(rtb_Integrator_l);

    /* '<S6>:1:175' */
    ctrl_student_HIL_B.eta_d[0] = ctrl_student_HIL_B.rx * cos(rtb_Integrator_l)
      + 6.0;
    ctrl_student_HIL_B.eta_d[1] = ctrl_student_HIL_B.ry * sin(rtb_Integrator_l);
    ctrl_student_HIL_B.eta_d[2] = rt_atan2d_snf(ctrl_student_HIL_B.ry * cos
      (rtb_Integrator_l), -ctrl_student_HIL_B.rx * sin(rtb_Integrator_l));

    /* '<S6>:1:176' */
    eta_d_s[0] = -ctrl_student_HIL_B.rx * sin(rtb_Integrator_l);
    eta_d_s[1] = ctrl_student_HIL_B.ry * cos(rtb_Integrator_l);
    eta_d_s[2] = ctrl_student_HIL_B.rx * ctrl_student_HIL_B.ry /
      (ctrl_student_HIL_B.ry * ctrl_student_HIL_B.ry * (rtb_Product_a *
        rtb_Product_a) + ctrl_student_HIL_B.rx * ctrl_student_HIL_B.rx *
       (rtb_Product * rtb_Product));

    /*         %% Update law */
    /* '<S6>:1:180' */
    absx = rtb_Gain_idx_0 - ctrl_student_HIL_B.eta_d[0];
    diff_idx_1 = rtb_Gain_idx_1 - ctrl_student_HIL_B.eta_d[1];

    /* '<S6>:1:180' */
    rtb_Product = ctrl_student_HIL_angdiff(ctrl_student_HIL_B.eta_d[2],
      rtb_Gain_idx_2);
    if (ctrl_student_HIL_norm(eta_d_s) < 1.0E-5) {
      /* '<S6>:1:181' */
      /* '<S6>:1:182' */
      s_dot = U_s - ((ctrl_student_HIL_B.mu * -absx + ctrl_student_HIL_B.mu *
                      -diff_idx_1) + ctrl_student_HIL_B.mu * -rtb_Product) /
        1.7320508075688772;
    } else {
      /* '<S6>:1:184' */
      s_dot = U_s - ((ctrl_student_HIL_B.mu * -absx * eta_d_s[0] +
                      ctrl_student_HIL_B.mu * -diff_idx_1 * eta_d_s[1]) +
                     ctrl_student_HIL_B.mu * -rtb_Product * eta_d_s[2]) /
        ctrl_student_HIL_norm(eta_d_s);
    }
    break;

   default:
    /*         %% Speed mapping */
    /* '<S6>:1:188' */
    /* '<S6>:1:189' */
    U_s = 0.13096000000000002;

    /*         %% Reference mapping */
    /*  atan2(0 - eta(2), 0 - eta(1)); */
    /* '<S6>:1:196' */
    /* '<S6>:1:197' */
    /* '<S6>:1:202' */
    ctrl_student_HIL_B.eta_d[0] = 3.0;
    ctrl_student_HIL_B.eta_d[1] = 0.0;
    ctrl_student_HIL_B.eta_d[2] = 0.0;

    /* '<S6>:1:203' */
    eta_d_s[0] = 0.0;
    eta_d_s[1] = 0.0;
    eta_d_s[2] = 0.0;

    /*         %% Update law */
    /* '<S6>:1:208' */
    s_dot = 0.0;
    break;
  }

  /* % Control law */
  /*  Define z_1 and z_1_dot */
  /* '<S6>:1:214' */
  S[0] = 0.0;
  S[3] = -ctrl_student_HIL_B.Memory_l[2];
  S[6] = 0.0;
  S[1] = ctrl_student_HIL_B.Memory_l[2];
  S[4] = 0.0;
  S[7] = 0.0;
  S[2] = 0.0;
  S[5] = 0.0;
  S[8] = 0.0;

  /* '<S6>:1:215' */
  /* '<S6>:1:216' */
  R[0] = cos(rtb_Gain_idx_2);
  R[3] = -sin(rtb_Gain_idx_2);
  R[6] = 0.0;
  R[1] = sin(rtb_Gain_idx_2);
  R[4] = cos(rtb_Gain_idx_2);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S6>:1:220' */
  absx = rtb_Gain_idx_0 - ctrl_student_HIL_B.eta_d[0];
  diff_idx_1 = rtb_Gain_idx_1 - ctrl_student_HIL_B.eta_d[1];

  /* '<S6>:1:221' */
  /* '<S6>:1:242' */
  rtb_Product_a = ((rtb_Gain_idx_2 - ctrl_student_HIL_B.eta_d[2]) +
                   3.1415926535897931) / 6.2831853071795862;
  if (fabs(rtb_Product_a - rt_roundd_snf(rtb_Product_a)) <=
      2.2204460492503131E-16 * fabs(rtb_Product_a)) {
    rtb_Product_a = 0.0;
  } else {
    rtb_Product_a = (rtb_Product_a - floor(rtb_Product_a)) * 6.2831853071795862;
  }

  /* '<S6>:1:222' */
  /* '<S6>:1:223' */
  for (r = 0; r < 3; r++) {
    ctrl_student_HIL_B.z_1[r] = 0.0;
    ctrl_student_HIL_B.z_1[r] += R[3 * r] * absx;
    ctrl_student_HIL_B.z_1[r] += R[3 * r + 1] * diff_idx_1;
    ctrl_student_HIL_B.z_1[r] += R[3 * r + 2] * (rtb_Product_a -
      3.1415926535897931);
  }

  /* '<S6>:1:224' */
  /*  alpha_1, alpha_1_dot, and z_2 */
  /* '<S6>:1:227' */
  /* '<S6>:1:228' */
  for (r = 0; r < 3; r++) {
    K_p_0[3 * r] = -K_p[3 * r];
    K_p_0[1 + 3 * r] = -K_p[3 * r + 1];
    K_p_0[2 + 3 * r] = -K_p[3 * r + 2];
  }

  for (r = 0; r < 3; r++) {
    R_0[r] = R[3 * r + 2] * eta_d_s[2] + (R[3 * r + 1] * eta_d_s[1] + R[3 * r] *
      eta_d_s[0]);
  }

  for (r = 0; r < 3; r++) {
    z_2[r] = ctrl_student_HIL_B.Memory_l[r] - (((K_p_0[r + 3] *
      ctrl_student_HIL_B.z_1[1] + K_p_0[r] * ctrl_student_HIL_B.z_1[0]) +
      K_p_0[r + 6] * ctrl_student_HIL_B.z_1[2]) + R_0[r] * U_s);
  }

  /* '<S6>:1:229' */
  for (r = 0; r < 3; r++) {
    R_0[r] = R[3 * r + 2] * eta_d_s[2] + (R[3 * r + 1] * eta_d_s[1] + R[3 * r] *
      eta_d_s[0]);
  }

  for (r = 0; r < 3; r++) {
    K_p_0[3 * r] = -K_p[3 * r];
    K_p_0[1 + 3 * r] = -K_p[3 * r + 1];
    K_p_0[2 + 3 * r] = -K_p[3 * r + 2];
  }

  for (r = 0; r < 3; r++) {
    S_0[r] = (((S[3 * r + 1] * ctrl_student_HIL_B.z_1[1] + S[3 * r] *
                ctrl_student_HIL_B.z_1[0]) + S[3 * r + 2] *
               ctrl_student_HIL_B.z_1[2]) + ctrl_student_HIL_B.Memory_l[r]) -
      R_0[r] * s_dot;
  }

  for (r = 0; r < 3; r++) {
    for (exitg2 = 0; exitg2 < 3; exitg2++) {
      S_1[r + 3 * exitg2] = 0.0;
      S_1[r + 3 * exitg2] += S[3 * r] * R[exitg2];
      S_1[r + 3 * exitg2] += S[3 * r + 1] * R[exitg2 + 3];
      S_1[r + 3 * exitg2] += S[3 * r + 2] * R[exitg2 + 6];
    }
  }

  for (r = 0; r < 3; r++) {
    S_2[r] = S_1[r + 6] * eta_d_s[2] + (S_1[r + 3] * eta_d_s[1] + S_1[r] *
      eta_d_s[0]);
  }

  for (r = 0; r < 3; r++) {
    eta_d_s[r] = ((K_p_0[r + 3] * S_0[1] + K_p_0[r] * S_0[0]) + K_p_0[r + 6] *
                  S_0[2]) + S_2[r] * U_s;
  }

  /*  + R'*eta_d_ss*s_dot*U_s + R'*eta_d_s*U_s_s*s_dot; */
  /* '<S6>:1:231' */
  /* '<S6>:1:232' */
  /* '<S6>:1:233' */
  /* '<S6>:1:234' */
  for (r = 0; r < 3; r++) {
    S_2[r] = D_tot[r + 6] * 0.0 * ctrl_student_HIL_B.Memory_l[2] + (D_tot[r + 3]
      * 0.0 * ctrl_student_HIL_B.Memory_l[1] + 0.0 * D_tot[r] *
      ctrl_student_HIL_B.Memory_l[0]);
  }

  for (r = 0; r < 3; r++) {
    tmp[r] = 0.0 * eta_d_s[2] + (0.0 * eta_d_s[1] + 0.0 * eta_d_s[0]);
  }

  for (r = 0; r < 3; r++) {
    S_0[r] = (S_2[r] + tmp[r]) - ((K_p[r + 3] * ctrl_student_HIL_B.z_1[1] +
      K_p[r] * ctrl_student_HIL_B.z_1[0]) + K_p[r + 6] * ctrl_student_HIL_B.z_1
      [2]);
  }

  for (r = 0; r < 3; r++) {
    S_2[r] = K_2[r + 6] * z_2[2] + (K_2[r + 3] * z_2[1] + K_2[r] * z_2[0]);
  }

  ctrl_student_HIL_B.tau[0] = S_0[0] - S_2[0];
  ctrl_student_HIL_B.tau[1] = S_0[1] - S_2[1];
  ctrl_student_HIL_B.tau[2] = S_0[2] - S_2[2];

  /* '<S6>:1:235' */
  /* '<S6>:1:236' */
  ctrl_student_HIL_B.taus[0] = ctrl_student_HIL_B.tau[0];
  ctrl_student_HIL_B.taus[1] = ctrl_student_HIL_B.tau[1];
  ctrl_student_HIL_B.taus[2] = ctrl_student_HIL_B.tau[2];

  /* '<S6>:1:237' */
  /*  Axis in the middle of the pool (assumed) */
  /* '<S6>:1:251' */
  /* '<S6>:1:252' */
  /* '<S6>:1:254' */
  /* '<S6>:1:257' */
  z[0] = rtb_Gain_idx_0 / 19.0;
  z[1] = rtb_Gain_idx_1 / 2.58;
  rtb_Product_a = 0.0;
  rtb_Product = 0.0;
  r = 0;
  do {
    exitg2 = 0;
    if (r < 2) {
      absx = fabs(z[r]);
      if (rtIsNaN(absx)) {
        rtb_Product_a = (rtNaN);
        exitg2 = 2;
      } else if (rtIsInf(absx)) {
        rtb_Product_a = (rtInf);
        j = 0;
        exitg2 = 1;
      } else {
        if (absx > 0.0) {
          if (rtb_Product < absx) {
            rtb_Product_a = rt_powd_snf(rtb_Product / absx, 4.0) * rtb_Product_a
              + 1.0;
            rtb_Product = absx;
          } else {
            rtb_Product_a += rt_powd_snf(absx / rtb_Product, 4.0);
          }
        }

        r++;
      }
    } else {
      if ((rtb_Product_a > 0.0) && (!rtIsInf(rtb_Product_a))) {
        rtb_Product_a = rtb_Product * rt_powd_snf(rtb_Product_a, 0.25);
      }

      exitg2 = 2;
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
    exitg1 = false;
    while ((!exitg1) && (j <= -r)) {
      if (rtIsNaN(z[1 + r])) {
        rtb_Product_a = (rtNaN);
        exitg1 = true;
      } else {
        j = 1;
      }
    }
  }

  if (rtb_Product_a > 1.0) {
    /* '<S6>:1:259' */
    /* '<S6>:1:260' */
    /* '<S6>:1:261' */
    ctrl_student_HIL_B.tau[0] = -(rt_powd_snf(rtb_Gain_idx_0 / 19.0, 3.0) *
      0.21052631578947367) * 10.0 * (rtb_Product_a - 0.5);
    ctrl_student_HIL_B.tau[1] = -(rt_powd_snf(rtb_Gain_idx_1 / 2.58, 3.0) *
      1.5503875968992247) * 10.0 * (rtb_Product_a - 0.5);

    /* '<S6>:1:262' */
    tmp_0[0] = cos(rtb_Gain_idx_2);
    tmp_0[1] = -sin(rtb_Gain_idx_2);
    tmp_0[2] = 0.0;
    tmp_0[3] = sin(rtb_Gain_idx_2);
    tmp_0[4] = cos(rtb_Gain_idx_2);
    tmp_0[5] = 0.0;
    tmp_0[6] = 0.0;
    tmp_0[7] = 0.0;
    tmp_0[8] = 1.0;
    for (r = 0; r < 3; r++) {
      S_2[r] = tmp_0[r + 6] * ctrl_student_HIL_B.tau[2] + (tmp_0[r + 3] *
        ctrl_student_HIL_B.tau[1] + tmp_0[r] * ctrl_student_HIL_B.tau[0]);
    }

    ctrl_student_HIL_B.tau[0] = S_2[0];
    ctrl_student_HIL_B.tau[1] = S_2[1];
    ctrl_student_HIL_B.tau[2] = S_2[2];

    /*  This heuristic ensures that eta_d outside the basin */
    /*  will not immediately throttle the actuator towards eta_d once the */
    /*  vessel is back in the "safety zone" (norm4 < 1) */
    /*  We thus throttle the actuator forces down to avoid heavy */
    /*  oscillations. */
  } else {
    if (rtb_Product_a >= 0.9) {
      /* '<S6>:1:268' */
      /* '<S6>:1:269' */
      rtb_Product_a = 1.0 - rtb_Product_a * 0.75;
      ctrl_student_HIL_B.tau[0] *= rtb_Product_a;
      ctrl_student_HIL_B.tau[1] *= rtb_Product_a;
      ctrl_student_HIL_B.tau[2] *= rtb_Product_a;
    }
  }

  /* '<S6>:1:238' */
  absx = ctrl_student_HIL_B.tau[0];
  diff_idx_1 = ctrl_student_HIL_B.tau[1];
  rtb_Product = ctrl_student_HIL_B.tau[2];
  if ((1.03 <= absx) || rtIsNaN(absx)) {
    ctrl_student_HIL_B.tau[0] = 1.03;
  } else {
    ctrl_student_HIL_B.tau[0] = absx;
  }

  if ((0.0 <= diff_idx_1) || rtIsNaN(diff_idx_1)) {
    ctrl_student_HIL_B.tau[1] = 0.0;
  } else {
    ctrl_student_HIL_B.tau[1] = diff_idx_1;
  }

  if ((0.98 <= rtb_Product) || rtIsNaN(rtb_Product)) {
    ctrl_student_HIL_B.tau[2] = 0.98;
  } else {
    ctrl_student_HIL_B.tau[2] = rtb_Product;
  }

  /* '<S6>:1:239' */
  absx = ctrl_student_HIL_B.tau[0];
  diff_idx_1 = ctrl_student_HIL_B.tau[1];
  rtb_Product = ctrl_student_HIL_B.tau[2];
  if ((-1.03 >= absx) || rtIsNaN(absx)) {
    ctrl_student_HIL_B.tau[0] = -1.03;
  } else {
    ctrl_student_HIL_B.tau[0] = absx;
  }

  if ((-0.0 >= diff_idx_1) || rtIsNaN(diff_idx_1)) {
    ctrl_student_HIL_B.tau[1] = -0.0;
  } else {
    ctrl_student_HIL_B.tau[1] = diff_idx_1;
  }

  if ((-0.98 >= rtb_Product) || rtIsNaN(rtb_Product)) {
    ctrl_student_HIL_B.tau[2] = -0.98;
  } else {
    ctrl_student_HIL_B.tau[2] = rtb_Product;
  }

  ctrl_student_HIL_B.s_dot = s_dot;
  for (r = 0; r < 3; r++) {
    ctrl_student_HIL_B.dtot_nu[r] = 0.0;
    ctrl_student_HIL_B.dtot_nu[r] += D_tot[r] * ctrl_student_HIL_B.Memory_l[0];
    ctrl_student_HIL_B.dtot_nu[r] += D_tot[r + 3] * ctrl_student_HIL_B.Memory_l
      [1];
    ctrl_student_HIL_B.dtot_nu[r] += D_tot[r + 6] * ctrl_student_HIL_B.Memory_l
      [2];
  }

  for (r = 0; r < 3; r++) {
    ctrl_student_HIL_B.m_alpha_1_dot[r] = 0.0;
    ctrl_student_HIL_B.m_alpha_1_dot[r] += c_a[r] * eta_d_s[0];
    ctrl_student_HIL_B.m_alpha_1_dot[r] += c_a[r + 3] * eta_d_s[1];
    ctrl_student_HIL_B.m_alpha_1_dot[r] += c_a[r + 6] * eta_d_s[2];
  }

  for (r = 0; r < 3; r++) {
    ctrl_student_HIL_B.K_2_z_2[r] = 0.0;
    ctrl_student_HIL_B.K_2_z_2[r] += K_2[r] * z_2[0];
    ctrl_student_HIL_B.K_2_z_2[r] += K_2[r + 3] * z_2[1];
    ctrl_student_HIL_B.K_2_z_2[r] += K_2[r + 6] * z_2[2];
  }

  /* End of MATLAB Function: '<Root>/Transfer function' */

  /* Integrator: '<S1>/Integrator1'
   *
   * Regarding '<S1>/Integrator1':
   *  Limited Integrator
   */
  if (ctrl_student_HIL_X.Integrator1_CSTATE[0] >=
      (ctrl_student_HIL_P.Integrator1_UpperSat[0]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[0] =
      (ctrl_student_HIL_P.Integrator1_UpperSat[0]);
  } else if (ctrl_student_HIL_X.Integrator1_CSTATE[0] <=
             (ctrl_student_HIL_P.Integrator1_LowerSat[0]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[0] =
      (ctrl_student_HIL_P.Integrator1_LowerSat[0]);
  }

  if (ctrl_student_HIL_X.Integrator1_CSTATE[1] >=
      (ctrl_student_HIL_P.Integrator1_UpperSat[1]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[1] =
      (ctrl_student_HIL_P.Integrator1_UpperSat[1]);
  } else if (ctrl_student_HIL_X.Integrator1_CSTATE[1] <=
             (ctrl_student_HIL_P.Integrator1_LowerSat[1]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[1] =
      (ctrl_student_HIL_P.Integrator1_LowerSat[1]);
  }

  if (ctrl_student_HIL_X.Integrator1_CSTATE[2] >=
      (ctrl_student_HIL_P.Integrator1_UpperSat[2]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[2] =
      (ctrl_student_HIL_P.Integrator1_UpperSat[2]);
  } else if (ctrl_student_HIL_X.Integrator1_CSTATE[2] <=
             (ctrl_student_HIL_P.Integrator1_LowerSat[2]) ) {
    ctrl_student_HIL_X.Integrator1_CSTATE[2] =
      (ctrl_student_HIL_P.Integrator1_LowerSat[2]);
  }

  ctrl_student_HIL_B.Integrator1[0] = ctrl_student_HIL_X.Integrator1_CSTATE[0];
  ctrl_student_HIL_B.Integrator1[1] = ctrl_student_HIL_X.Integrator1_CSTATE[1];
  ctrl_student_HIL_B.Integrator1[2] = ctrl_student_HIL_X.Integrator1_CSTATE[2];

  /* MATLAB Function: '<S1>/Observer ' incorporates:
   *  Integrator: '<S1>/Integrator2'
   */
  /* MATLAB Function 'DP Observer /Observer ': '<S10>:1' */
  /*  if(first == 1) */
  /*  eta_hat = zeros(3,1) ;  */
  /*  nu_hat = zeros(3,1);  */
  /*  b_hau = zeros(3,1) */
  /*  first_out = 0;  */
  /*  end */
  /* '<S10>:1:8' */
  for (r = 0; r < 9; r++) {
    K_p[r] = 0.0;
    K_2[r] = 0.0;
  }

  K_p[0] = ctrl_student_HIL_B.L1_diag[0] + 4.0;
  K_p[4] = ctrl_student_HIL_B.L1_diag[1] + 4.0;
  K_p[8] = ctrl_student_HIL_B.L1_diag[2] + 3.0;

  /* '<S10>:1:9' */
  K_2[0] = ctrl_student_HIL_B.L2_diag[0];
  K_2[4] = ctrl_student_HIL_B.L2_diag[1];
  K_2[8] = ctrl_student_HIL_B.L2_diag[2];

  /*  + [50 50 10]');  */
  /*  M = [16.79 0 0; 0 24.79 0.5546; 0 0.5546 2.7600]; */
  /* % Parameters */
  /*  Rigid body and added mass */
  /*  y_g = 0.0; */
  /*  Max Values in Surge X, Sway Y and Yaw N */
  /* [N] */
  /* [Nm] */
  /*  Hydro surge, Hydro sway and Hydro Yaw Parameters */
  /*  NB! We don't need most of them for now, that why they are commented */
  /*  out, but don't remove them!! */
  /* '<S10>:1:36' */
  /* '<S10>:1:39' */
  /*  Matrices */
  /* '<S10>:1:46' */
  /*  I need a test values;  */
  /* '<S10>:1:54' */
  /* '<S10>:1:55' */
  /* '<S10>:1:56' */
  /* '<S10>:1:57' */
  /* '<S10>:1:58' */
  /*  The total damping matrix from the handbook page 53 */
  /* '<S10>:1:61' */
  /* '<S10>:1:63' */
  rtb_Gain_idx_0 = rtb_eta_idx_0 - ctrl_student_HIL_B.Integrator[0];
  rtb_Gain_idx_1 = rtb_eta_idx_1 - ctrl_student_HIL_B.Integrator[1];

  /* '<S10>:1:64' */
  ctrl_student_HIL_B.x_bar = rtb_Gain_idx_0;

  /* '<S10>:1:65' */
  ctrl_student_HIL_B.y_bar = rtb_Gain_idx_1;

  /* '<S10>:1:66' */
  /* L3*eta_bar + b;  */
  /* '<S10>:1:79' */
  absx = ((rtb_eta_idx_2 - ctrl_student_HIL_B.Integrator[2]) +
          3.1415926535897931) / 6.2831853071795862;
  if (fabs(absx - rt_roundd_snf(absx)) <= 2.2204460492503131E-16 * fabs(absx)) {
    absx = 0.0;
  } else {
    absx = (absx - floor(absx)) * 6.2831853071795862;
  }

  /* '<S10>:1:67' */
  /* '<S10>:1:68' */
  /* '<S10>:1:69' */
  R[0] = cos(rtb_eta_idx_2);
  R[3] = -sin(rtb_eta_idx_2);
  R[6] = 0.0;
  R[1] = sin(rtb_eta_idx_2);
  R[4] = cos(rtb_eta_idx_2);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S10>:1:73' */
  /* '<S10>:1:74' */
  for (r = 0; r < 3; r++) {
    R_0[r] = R[r + 6] * ctrl_student_HIL_B.Integrator1[2] + (R[r + 3] *
      ctrl_student_HIL_B.Integrator1[1] + R[r] * ctrl_student_HIL_B.Integrator1
      [0]);
  }

  for (r = 0; r < 3; r++) {
    S_2[r] = K_p[r + 6] * (absx - 3.1415926535897931) + (K_p[r + 3] *
      rtb_Gain_idx_1 + K_p[r] * rtb_Gain_idx_0);
  }

  ctrl_student_HIL_B.eta_hat_dot[0] = R_0[0] + S_2[0];
  ctrl_student_HIL_B.eta_hat_dot[1] = R_0[1] + S_2[1];
  ctrl_student_HIL_B.eta_hat_dot[2] = R_0[2] + S_2[2];

  /* '<S10>:1:76' */
  ctrl_student_HIL_B.b_hat_dot = 0.0;
  tmp_1[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Integrator1[0])) -
    ctrl_student_HIL_B.Integrator1[0] * ctrl_student_HIL_B.Integrator1[0] *
    -3.787;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Integrator1[1])) -
              ctrl_student_HIL_B.Integrator1[1] *
              ctrl_student_HIL_B.Integrator1[1] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_B.Integrator1[2]);
  tmp_1[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.Integrator1[1])) - -3.45 *
              fabs(ctrl_student_HIL_B.Integrator1[2])) -
    ctrl_student_HIL_B.Integrator1[2] * ctrl_student_HIL_B.Integrator1[2] * 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Integrator1[1])) -
              ctrl_student_HIL_B.Integrator1[1] *
              ctrl_student_HIL_B.Integrator1[1] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_B.Integrator1[2]);
  tmp_1[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.Integrator1[1])) - -0.75 *
              fabs(ctrl_student_HIL_B.Integrator1[2])) -
    ctrl_student_HIL_B.Integrator1[2] * ctrl_student_HIL_B.Integrator1[2] * 0.0;
  for (r = 0; r < 3; r++) {
    K_p_0[3 * r] = -(ctrl_student_HIL_B.demp + 1.0) * tmp_1[3 * r];
    K_p_0[1 + 3 * r] = tmp_1[3 * r + 1] * -(ctrl_student_HIL_B.demp + 1.0);
    K_p_0[2 + 3 * r] = tmp_1[3 * r + 2] * -(ctrl_student_HIL_B.demp + 1.0);
  }

  for (r = 0; r < 3; r++) {
    S_2[r] = K_p_0[r + 6] * ctrl_student_HIL_B.Integrator1[2] + (K_p_0[r + 3] *
      ctrl_student_HIL_B.Integrator1[1] + K_p_0[r] *
      ctrl_student_HIL_B.Integrator1[0]);
  }

  for (r = 0; r < 3; r++) {
    R_0[r] = R[3 * r + 2] * ctrl_student_HIL_X.Integrator2_CSTATE[2] + (R[3 * r
      + 1] * ctrl_student_HIL_X.Integrator2_CSTATE[1] + R[3 * r] *
      ctrl_student_HIL_X.Integrator2_CSTATE[0]);
  }

  for (r = 0; r < 3; r++) {
    for (exitg2 = 0; exitg2 < 3; exitg2++) {
      K_p_0[r + 3 * exitg2] = 0.0;
      K_p_0[r + 3 * exitg2] += R[3 * r] * K_2[3 * exitg2];
      K_p_0[r + 3 * exitg2] += R[3 * r + 1] * K_2[3 * exitg2 + 1];
      K_p_0[r + 3 * exitg2] += R[3 * r + 2] * K_2[3 * exitg2 + 2];
    }
  }

  for (r = 0; r < 3; r++) {
    tmp[r] = ((K_p_0[r + 3] * rtb_Gain_idx_1 + K_p_0[r] * rtb_Gain_idx_0) +
              K_p_0[r + 6] * (absx - 3.1415926535897931)) + ((S_2[r] + R_0[r]) +
      ctrl_student_HIL_B.tau[r]);
  }

  for (r = 0; r < 3; r++) {
    ctrl_student_HIL_B.nu_hat_dot[r] = 0.0;
    ctrl_student_HIL_B.nu_hat_dot[r] += a[r] * tmp[0];
    ctrl_student_HIL_B.nu_hat_dot[r] += a[r + 3] * tmp[1];
    ctrl_student_HIL_B.nu_hat_dot[r] += a[r + 6] * tmp[2];
  }

  ctrl_student_HIL_B.psi_bar = absx - 3.1415926535897931;

  /* End of MATLAB Function: '<S1>/Observer ' */

  /* MATLAB Function: '<S5>/the rest ' */
  /* MATLAB Function 'SurgeObserver /the rest ': '<S23>:1' */
  /* '<S23>:1:3' */
  if (sin(rtb_eta_idx_2) + cos(rtb_eta_idx_2) < 0.0) {
    /* '<S23>:1:5' */
    /* '<S23>:1:6' */
    rtb_Product_a = -ctrl_student_HIL_B.k_0;
  } else {
    /* '<S23>:1:8' */
    rtb_Product_a = ctrl_student_HIL_B.k_0;
  }

  /* '<S23>:1:11' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Constant: '<S5>/Constant' */
    ctrl_student_HIL_B.Constant = ctrl_student_HIL_P.Constant_Value_h;
  }

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_d,
                       ctrl_student_HIL_B.Reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_j = ctrl_student_HIL_B.Constant;
    }
  }

  rtb_Integrator_p = ctrl_student_HIL_X.Integrator_CSTATE_j;

  /* Sum: '<S5>/Sum4' incorporates:
   *  MATLAB Function: '<S5>/the rest '
   */
  ctrl_student_HIL_B.u_hat = (rtb_eta_idx_0 + rtb_eta_idx_1) * rtb_Product_a +
    rtb_Integrator_p;

  /* MATLAB Function: '<S5>/Integration block ' */
  rtb_Product = ctrl_student_HIL_B.u_hat;

  /* MATLAB Function 'SurgeObserver /Integration block ': '<S22>:1' */
  /* '<S22>:1:2' */
  absx = sin(rtb_eta_idx_2) + cos(rtb_eta_idx_2);
  if (ctrl_student_HIL_B.Reset != 0.0) {
    /* '<S22>:1:6' */
    rtb_Product = 0.0;
  }

  if (absx < 0.0) {
    /* '<S22>:1:9' */
    /* '<S22>:1:10' */
    rtb_Product_a = -ctrl_student_HIL_B.k_0;
  } else {
    /* '<S22>:1:12' */
    rtb_Product_a = ctrl_student_HIL_B.k_0;
  }

  /* '<S22>:1:15' */
  /* '<S22>:1:17' */
  ctrl_student_HIL_B.y_k = (-((0.6555 - 0.3545 * fabs(rtb_Product)) +
    rtb_Product * rtb_Product * 3.787) * rtb_Product + ctrl_student_HIL_B.tau[0])
    / 14.79 - rtb_Product_a * absx * rtb_Product;

  /* End of MATLAB Function: '<S5>/Integration block ' */

  /* MATLAB Function: '<S9>/Limited allocation: VSP only  in surge and BT only in yaw' */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw': '<S25>:1' */
  /* '<S25>:1:5' */
  ctrl_student_HIL_B.u_BT = ctrl_student_HIL_B.tau[2] / 1.0187375;

  /* '<S25>:1:7' */
  ctrl_student_HIL_B.omega_VSP = 0.3;

  /* Sum: '<S9>/Sum' incorporates:
   *  MATLAB Function: '<S9>/Limited allocation: VSP only  in surge and BT only in yaw'
   */
  /* '<S25>:1:9' */
  /* '<S25>:1:10' */
  /*  0 if positive X_VSP, pi if negative */
  ctrl_student_HIL_B.Sum = fabs(ctrl_student_HIL_B.tau[0]) / 2.33 +
    ctrl_student_HIL_B.u_calb_ctrl;

  /* Sum: '<S9>/Sum1' incorporates:
   *  MATLAB Function: '<S9>/Limited allocation: VSP only  in surge and BT only in yaw'
   */
  ctrl_student_HIL_B.Sum1 = (real_T)(ctrl_student_HIL_B.tau[0] <= 0.0) *
    3.1415926535897931 + ctrl_student_HIL_B.alpha_calb_ctrl1;

  /* MATLAB Function: '<S26>/control limit checking' incorporates:
   *  SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking': '<S27>:1' */
  /* '<S27>:1:2' */
  /* '<S27>:1:3' */
  /* '<S27>:1:4' */
  /* '<S27>:1:5' */
  /* '<S27>:1:6' */
  /* '<S27>:1:7' */
  /* '<S27>:1:8' */
  /* '<S27>:1:10' */
  /* '<S27>:1:18' */
  ctrl_student_HIL_B.fault = !((-1.0 <= ctrl_student_HIL_B.u_BT) &&
    (ctrl_student_HIL_B.u_BT <= 1.0) && (0.0 <= ctrl_student_HIL_B.Sum) &&
    (ctrl_student_HIL_B.Sum <= 1.0) && (0.0 <= ctrl_student_HIL_B.Sum) &&
    (ctrl_student_HIL_B.Sum <= 1.0) && (-3.1415926535897931 <=
    ctrl_student_HIL_B.Sum1) && (ctrl_student_HIL_B.Sum1 <= 3.1415926535897931) &&
    (-3.1415926535897931 <= ctrl_student_HIL_B.Sum1) && (ctrl_student_HIL_B.Sum1
    <= 3.1415926535897931) && (-1.0 <= ctrl_student_HIL_B.omega_VSP) &&
    (ctrl_student_HIL_B.omega_VSP <= 1.0) && (-1.0 <=
    ctrl_student_HIL_B.omega_VSP) && (ctrl_student_HIL_B.omega_VSP <= 1.0));

  /* Sum: '<S2>/Add' */
  ctrl_student_HIL_B.Add = ctrl_student_HIL_B.r_gyro +
    ctrl_student_HIL_B.bias_r_gyro;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_B.newmem[0];
    ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_B.newmem[1];
    ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_B.newmem[2];

    /* Update for Memory: '<S14>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S20>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S21>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_j
      + ctrl_student_HIL_P.WhiteNoise_Mean_j;

    /* Update for RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_a) * ctrl_student_HIL_P.WhiteNoise_StdDev_n
      + ctrl_student_HIL_P.WhiteNoise_Mean_b;

    /* Update for Memory: '<S15>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<Root>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_g[0] =
      ctrl_student_HIL_B.Integrator1[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_g[1] =
      ctrl_student_HIL_B.Integrator1[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_g[2] =
      ctrl_student_HIL_B.Integrator1[2];
  }

  /* Update for Integrator: '<S5>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
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
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

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
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  XDot_ctrl_student_HIL_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs);

  /* Derivatives for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  if (ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[0] == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[0] =
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[3];
    _rtXdot->IntegratorSecondOrder_CSTATE[3] = ctrl_student_HIL_B.eta_dot_imu;
  }

  if (ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[1] == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[1] =
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[4];
    _rtXdot->IntegratorSecondOrder_CSTATE[4] = ctrl_student_HIL_B.eta_dot_imu;
  }

  if (ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[2] == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[2] =
      ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[5];
    _rtXdot->IntegratorSecondOrder_CSTATE[5] = ctrl_student_HIL_B.eta_dot_imu;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
  /* Derivatives for Integrator: '<S2>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE = ctrl_student_HIL_B.Add;
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_m = ctrl_student_HIL_B.s_dot;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[0] = ctrl_student_HIL_B.eta_hat_dot[0];
  _rtXdot->Integrator_CSTATE_i[1] = ctrl_student_HIL_B.eta_hat_dot[1];
  _rtXdot->Integrator_CSTATE_i[2] = ctrl_student_HIL_B.eta_hat_dot[2];

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( ctrl_student_HIL_X.Integrator1_CSTATE[0] <=
            (ctrl_student_HIL_P.Integrator1_LowerSat[0]) );
    usat = ( ctrl_student_HIL_X.Integrator1_CSTATE[0] >=
            (ctrl_student_HIL_P.Integrator1_UpperSat[0]) );
    if ((!lsat && !usat) ||
        (lsat && (ctrl_student_HIL_B.nu_hat_dot[0] > 0)) ||
        (usat && (ctrl_student_HIL_B.nu_hat_dot[0] < 0)) ) {
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[0] = ctrl_student_HIL_B.nu_hat_dot[0];
    } else {
      /* in saturation */
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[0] = 0.0;
    }

    lsat = ( ctrl_student_HIL_X.Integrator1_CSTATE[1] <=
            (ctrl_student_HIL_P.Integrator1_LowerSat[1]) );
    usat = ( ctrl_student_HIL_X.Integrator1_CSTATE[1] >=
            (ctrl_student_HIL_P.Integrator1_UpperSat[1]) );
    if ((!lsat && !usat) ||
        (lsat && (ctrl_student_HIL_B.nu_hat_dot[1] > 0)) ||
        (usat && (ctrl_student_HIL_B.nu_hat_dot[1] < 0)) ) {
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[1] = ctrl_student_HIL_B.nu_hat_dot[1];
    } else {
      /* in saturation */
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[1] = 0.0;
    }

    lsat = ( ctrl_student_HIL_X.Integrator1_CSTATE[2] <=
            (ctrl_student_HIL_P.Integrator1_LowerSat[2]) );
    usat = ( ctrl_student_HIL_X.Integrator1_CSTATE[2] >=
            (ctrl_student_HIL_P.Integrator1_UpperSat[2]) );
    if ((!lsat && !usat) ||
        (lsat && (ctrl_student_HIL_B.nu_hat_dot[2] > 0)) ||
        (usat && (ctrl_student_HIL_B.nu_hat_dot[2] < 0)) ) {
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[2] = ctrl_student_HIL_B.nu_hat_dot[2];
    } else {
      /* in saturation */
      ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
        ->Integrator1_CSTATE[2] = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_student_HIL_B.b_hat_dot;
  _rtXdot->Integrator2_CSTATE[1] = ctrl_student_HIL_B.b_hat_dot;
  _rtXdot->Integrator2_CSTATE[2] = ctrl_student_HIL_B.b_hat_dot;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_j = ctrl_student_HIL_B.y_k;
  }
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for Constant: '<S5>/Constant' */
  ctrl_student_HIL_B.Constant = ctrl_student_HIL_P.Constant_Value_h;
  ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[0] =
    UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[1] =
    UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.IntegratorSecondOrder_Reset_ZCE[2] =
    UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_P.Memory_X0[0];
    ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_P.Memory_X0[1];
    ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_P.Memory_X0[2];

    /* InitializeConditions for Memory: '<S14>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S20>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
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

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S20>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S21>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_l);
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

    ctrl_student_HIL_DW.RandSeed_j = tseed;
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_j
      + ctrl_student_HIL_P.WhiteNoise_Mean_j;

    /* End of InitializeConditions for RandomNumber: '<S21>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S19>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_j);
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

    ctrl_student_HIL_DW.RandSeed_a = tseed;
    ctrl_student_HIL_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_a) * ctrl_student_HIL_P.WhiteNoise_StdDev_n
      + ctrl_student_HIL_P.WhiteNoise_Mean_b;

    /* End of InitializeConditions for RandomNumber: '<S19>/White Noise' */

    /* InitializeConditions for Memory: '<S15>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for SecondOrderIntegrator: '<S2>/Integrator, Second-Order' */
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[0] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[1] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[2] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICX;
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[3] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[4] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
    ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[5] =
      ctrl_student_HIL_P.IntegratorSecondOrder_ICDXDT;
    ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[0] = 0;
    ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[1] = 0;
    ctrl_student_HIL_DW.IntegratorSecondOrder_MODE[2] = 0;

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_m = ctrl_student_HIL_P.Integrator_IC_g;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_i[0] =
      ctrl_student_HIL_P.Integrator_IC_gv[0];
    ctrl_student_HIL_X.Integrator_CSTATE_i[1] =
      ctrl_student_HIL_P.Integrator_IC_gv[1];
    ctrl_student_HIL_X.Integrator_CSTATE_i[2] =
      ctrl_student_HIL_P.Integrator_IC_gv[2];

    /* InitializeConditions for Memory: '<Root>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_g[0] =
      ctrl_student_HIL_P.Memory_X0_d;
    ctrl_student_HIL_DW.Memory_PreviousInput_g[1] =
      ctrl_student_HIL_P.Memory_X0_d;
    ctrl_student_HIL_DW.Memory_PreviousInput_g[2] =
      ctrl_student_HIL_P.Memory_X0_d;

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE[0] =
      (ctrl_student_HIL_P.Integrator1_IC[0]);
    ctrl_student_HIL_X.Integrator1_CSTATE[1] =
      (ctrl_student_HIL_P.Integrator1_IC[1]);
    ctrl_student_HIL_X.Integrator1_CSTATE[2] =
      (ctrl_student_HIL_P.Integrator1_IC[2]);

    /* InitializeConditions for Integrator: '<S1>/Integrator2' */
    ctrl_student_HIL_X.Integrator2_CSTATE[0] =
      ctrl_student_HIL_P.Integrator2_IC[0];
    ctrl_student_HIL_X.Integrator2_CSTATE[1] =
      ctrl_student_HIL_P.Integrator2_IC[1];
    ctrl_student_HIL_X.Integrator2_CSTATE[2] =
      ctrl_student_HIL_P.Integrator2_IC[2];

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_j = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
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
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
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
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ctrl_student_HIL_P.Integrator1_UpperSat[2] = rtInf;
  ctrl_student_HIL_P.Integrator1_LowerSat[2] = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_M->ModelData.odeF[3];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_student_HIL_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (18);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (161);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (79);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (618);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
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
#ifdef NI_ROOTMODEL_ctrl_student_HIL
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,10,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // joystick/L2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Noise Generator/noise pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.noisepos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Noise Generator/noise head
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.noisehead, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Noise Generator/enable noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.enablenoise, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Dead reckoning/drop_out
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.drop_out, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // DP Observer /L1_diag
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_diag, 0, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_diag, 1, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_diag, 2, data[index++], 18, 0);
  } else {
    index += 3;
  }

  // DP Observer /L2_diag
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_diag, 0, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_diag, 1, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_diag, 2, data[index++], 18, 0);
  } else {
    index += 3;
  }

  // DP Observer /L3_diag
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_diag, 0, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_diag, 1, data[index++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_diag, 2, data[index++], 18, 0);
  } else {
    index += 3;
  }

  // case_number
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.case_number, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // DP Observer /use_dp_observer
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.use_dp_observer, 0, data[index++],
      36, 0);
  } else {
    index += 1;
  }

  // mu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.mu, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // rx
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.rx, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // ry
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ry, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // kp1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.kp1, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // kp2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.kp2, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // kp3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.kp3, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // k2_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.k2_1, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // k2_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.k2_2, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // k2_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.k2_3, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // DP Observer /b
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.b, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // DP Observer /demp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.demp, 0, data[index++], 36, 0);
  } else {
    index += 1;
  }

  // Reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // k_0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.k_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/u_calb_ctrl
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_calb_ctrl, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/alpha_calb_ctrl1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.alpha_calb_ctrl1, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Dead reckoning/r_gyro
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_gyro, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Dead reckoning/bias_r_gyro
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.bias_r_gyro, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Dead reckoning/eta_dot_imu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.eta_dot_imu, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 48;
}

double ni_extout[53];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // Test: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.R2_continuous,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.R2_continuous,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/osi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // Noise Generator/x_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,17,
      0);
  } else {
    index += 1;
  }

  // Noise Generator/psi_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,2,17,
      0);
  } else {
    index += 1;
  }

  // Noise Generator/y_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,1,17,
      0);
  } else {
    index += 1;
  }

  // DP Observer /psi_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.psi_bar,0,0,
      0);
  } else {
    index += 1;
  }

  // DP Observer /psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      2,17,0);
  } else {
    index += 1;
  }

  // DP Observer /r_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      2,17,0);
  } else {
    index += 1;
  }

  // DP Observer /u_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      0,17,0);
  } else {
    index += 1;
  }

  // DP Observer /v_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      1,17,0);
  } else {
    index += 1;
  }

  // DP Observer /x_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_bar,0,0,0);
  } else {
    index += 1;
  }

  // DP Observer /x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      0,17,0);
  } else {
    index += 1;
  }

  // DP Observer /y_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.y_bar,0,0,0);
  } else {
    index += 1;
  }

  // DP Observer /y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      1,17,0);
  } else {
    index += 1;
  }

  // x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,0,17,
      0);
  } else {
    index += 1;
  }

  // y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,1,17,
      0);
  } else {
    index += 1;
  }

  // psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,2,17,
      0);
  } else {
    index += 1;
  }

  // psi_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,2,17,0);
  } else {
    index += 1;
  }

  // x_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,0,17,0);
  } else {
    index += 1;
  }

  // y_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,1,17,0);
  } else {
    index += 1;
  }

  // tau_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,17,0);
  } else {
    index += 1;
  }

  // tau_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,17,0);
  } else {
    index += 1;
  }

  // tau_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,17,0);
  } else {
    index += 1;
  }

  // tau_psi1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,2,17,0);
  } else {
    index += 1;
  }

  // tau_x1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,0,17,0);
  } else {
    index += 1;
  }

  // tau_y1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,1,17,0);
  } else {
    index += 1;
  }

  // dtot_nu_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,2,
      17,0);
  } else {
    index += 1;
  }

  // dtot_nu_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,0,
      17,0);
  } else {
    index += 1;
  }

  // dtot_nu_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,1,
      17,0);
  } else {
    index += 1;
  }

  // m_alpha_1_dot_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.m_alpha_1_dot,2,17,0);
  } else {
    index += 1;
  }

  // m_alpha_1_dot_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.m_alpha_1_dot,0,17,0);
  } else {
    index += 1;
  }

  // m_alpha_1_dot_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.m_alpha_1_dot,1,17,0);
  } else {
    index += 1;
  }

  // K_2_z_2_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,2,
      17,0);
  } else {
    index += 1;
  }

  // K_2_z_2_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,0,
      17,0);
  } else {
    index += 1;
  }

  // K_2_z_2_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,1,
      17,0);
  } else {
    index += 1;
  }

  // z_1_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,2,17,0);
  } else {
    index += 1;
  }

  // z_1_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,0,17,0);
  } else {
    index += 1;
  }

  // SurgeObserver /u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_hat,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,0,0);
  } else {
    index += 1;
  }

  // z_1_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,1,17,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 53;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // Test: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.R2_continuous,
    0,0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.R2_continuous,
    0,0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/osi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // Noise Generator/x_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,17,0);

  // Noise Generator/psi_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,2,17,0);

  // Noise Generator/y_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,1,17,0);

  // DP Observer /psi_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.psi_bar,0,0,0);

  // DP Observer /psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,2,
    17,0);

  // DP Observer /r_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,2,
    17,0);

  // DP Observer /u_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    17,0);

  // DP Observer /v_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,1,
    17,0);

  // DP Observer /x_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_bar,0,0,0);

  // DP Observer /x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,0,
    17,0);

  // DP Observer /y_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.y_bar,0,0,0);

  // DP Observer /y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,1,
    17,0);

  // x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,0,17,0);

  // y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,1,17,0);

  // psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_d,2,17,0);

  // psi_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,2,17,0);

  // x_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,0,17,0);

  // y_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta1,1,17,0);

  // tau_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,17,0);

  // tau_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,17,0);

  // tau_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,17,0);

  // tau_psi1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,2,17,0);

  // tau_x1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,0,17,0);

  // tau_y1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.taus,1,17,0);

  // dtot_nu_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,2,17,
    0);

  // dtot_nu_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,0,17,
    0);

  // dtot_nu_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dtot_nu,1,17,
    0);

  // m_alpha_1_dot_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.m_alpha_1_dot,
    2,17,0);

  // m_alpha_1_dot_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.m_alpha_1_dot,
    0,17,0);

  // m_alpha_1_dot_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.m_alpha_1_dot,
    1,17,0);

  // K_2_z_2_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,2,17,
    0);

  // K_2_z_2_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,0,17,
    0);

  // K_2_z_2_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_2_z_2,1,17,
    0);

  // z_1_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,2,17,0);

  // z_1_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,0,17,0);

  // SurgeObserver /u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_hat,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,0,0);

  // z_1_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,1,17,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 36, 1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value), 36, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 36, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Dead reckoning/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 18, 3, 2, 6, 0 },

  { 4, "ctrl_student_hil/Noise Generator/Constant4/Value", offsetof
    (P_ctrl_student_HIL_T, Constant4_Value), 36, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Noise Generator/Noise generator/Step size/Value",
    offsetof(P_ctrl_student_HIL_T, Stepsize_Value), 36, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/Noise Generator/Noise generator/Downsamplesignal/counter/X0",
    offsetof(P_ctrl_student_HIL_T, counter_X0), 36, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Noise Generator/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain), 36, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 36, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 36, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 36, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_j), 36, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_j), 36, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 36, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/Noise Generator/Gain1/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain1_Gain), 36, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_b), 36, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_n), 36, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_j), 36, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Gain/Gain", offsetof(P_ctrl_student_HIL_T, Gain_Gain_d),
    18, 3, 2, 36, 0 },

  { 19, "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/Hold/X0",
    offsetof(P_ctrl_student_HIL_T, Hold_X0), 36, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Dead reckoning/Integrator, Second-Order/ICX", offsetof
    (P_ctrl_student_HIL_T, IntegratorSecondOrder_ICX), 36, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Dead reckoning/Integrator, Second-Order/ICDXDT",
    offsetof(P_ctrl_student_HIL_T, IntegratorSecondOrder_ICDXDT), 36, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil/Dead reckoning/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 36, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_g), 36, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/DP Observer /Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_gv), 18, 3, 2, 48, 0 },

  { 25, "ctrl_student_hil/DP Observer /Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold), 36, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Memory/X0", offsetof(P_ctrl_student_HIL_T, Memory_X0_d),
    36, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/DP Observer /Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC), 18, 3, 2, 54, 0 },

  { 28, "ctrl_student_hil/DP Observer /Integrator1/UpperSaturationLimit",
    offsetof(P_ctrl_student_HIL_T, Integrator1_UpperSat), 18, 3, 2, 56, 0 },

  { 29, "ctrl_student_hil/DP Observer /Integrator1/LowerSaturationLimit",
    offsetof(P_ctrl_student_HIL_T, Integrator1_LowerSat), 18, 3, 2, 58, 0 },

  { 30, "ctrl_student_hil/DP Observer /Integrator2/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator2_IC), 18, 3, 2, 60, 0 },

  { 31, "ctrl_student_hil/SurgeObserver /Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_h), 36, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_l), 36, 1, 2, 64, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 33;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  3, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  3, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  3, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  3, 1,                                /* Parameter at index 27 */
  3, 1,                                /* Parameter at index 28 */
  3, 1,                                /* Parameter at index 29 */
  3, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 1, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2,
    0 },

  { 2, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4,
    0 },

  { 3, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    6, 0 },

  { 4, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8,
    0 },

  { 5, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10,
    0 },

  { 6, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 16,
    0 },

  { 9, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof(B_ctrl_student_HIL_T,
    ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 20,
    0 },

  { 11, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    22, 0 },

  { 12, "ctrl_student_hil/y", 0, "", offsetof(B_ctrl_student_HIL_T, y)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Dead reckoning/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 26,
    0 },

  { 14, "ctrl_student_hil/Dead reckoning/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 28,
    0 },

  { 15, "ctrl_student_hil/Dead reckoning/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 30,
    0 },

  { 16, "ctrl_student_hil/Noise Generator/noise pos", 0, "", offsetof
    (B_ctrl_student_HIL_T, noisepos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 32,
    0 },

  { 17,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_a)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Noise Generator/noise head", 0, "", offsetof
    (B_ctrl_student_HIL_T, noisehead)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38,
    0 },

  { 20,
    "ctrl_student_hil/Noise Generator/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_f)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/x", 0, "", offsetof(B_ctrl_student_HIL_T, x)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/psi", 0, "", offsetof(B_ctrl_student_HIL_T, psi)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/Hold", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/Hold", 0,
    "(1,2)", offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/Hold", 0,
    "(1,3)", offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Noise Generator/enable noise", 0, "", offsetof
    (B_ctrl_student_HIL_T, enablenoise)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    52, 0 },

  { 27, "ctrl_student_hil/Noise Generator/Noise generator/Switch", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 54, 0 },

  { 28, "ctrl_student_hil/Noise Generator/Noise generator/Switch", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Switch)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 56, 0 },

  { 29, "ctrl_student_hil/Noise Generator/Noise generator/Switch", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Switch)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 58, 0 },

  { 30, "ctrl_student_hil/Dead reckoning/drop_out", 0, "", offsetof
    (B_ctrl_student_HIL_T, drop_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 60,
    0 },

  { 31, "ctrl_student_hil/DP Observer /L1_diag", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L1_diag)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 62,
    0 },

  { 32, "ctrl_student_hil/DP Observer /L1_diag", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L1_diag)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 64,
    0 },

  { 33, "ctrl_student_hil/DP Observer /L1_diag", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L1_diag)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 66,
    0 },

  { 34, "ctrl_student_hil/DP Observer /L2_diag", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L2_diag)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 68,
    0 },

  { 35, "ctrl_student_hil/DP Observer /L2_diag", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L2_diag)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 70,
    0 },

  { 36, "ctrl_student_hil/DP Observer /L2_diag", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L2_diag)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 72,
    0 },

  { 37, "ctrl_student_hil/DP Observer /L3_diag", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L3_diag)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/DP Observer /L3_diag", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L3_diag)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 76,
    0 },

  { 39, "ctrl_student_hil/DP Observer /L3_diag", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L3_diag)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 78,
    0 },

  { 40, "ctrl_student_hil/case_number", 0, "", offsetof(B_ctrl_student_HIL_T,
    case_number)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil/DP Observer /use_dp_observer", 0, "", offsetof
    (B_ctrl_student_HIL_T, use_dp_observer)+0*sizeof(real_T), BLOCKIO_SIG, 36, 1,
    2, 82, 0 },

  { 42, "ctrl_student_hil/DP Observer /Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    84, 0 },

  { 43, "ctrl_student_hil/DP Observer /Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    86, 0 },

  { 44, "ctrl_student_hil/DP Observer /Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    88, 0 },

  { 45, "ctrl_student_hil/Memory", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Memory_l)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 90, 0 },

  { 46, "ctrl_student_hil/Memory", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T,
    Memory_l)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 92, 0 },

  { 47, "ctrl_student_hil/Memory", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T,
    Memory_l)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 94, 0 },

  { 48, "ctrl_student_hil/mu", 0, "", offsetof(B_ctrl_student_HIL_T, mu)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/rx", 0, "", offsetof(B_ctrl_student_HIL_T, rx)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/ry", 0, "", offsetof(B_ctrl_student_HIL_T, ry)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/kp1", 0, "", offsetof(B_ctrl_student_HIL_T, kp1)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 102, 0 },

  { 52, "ctrl_student_hil/kp2", 0, "", offsetof(B_ctrl_student_HIL_T, kp2)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil/kp3", 0, "", offsetof(B_ctrl_student_HIL_T, kp3)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil/k2_1", 0, "", offsetof(B_ctrl_student_HIL_T, k2_1)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil/k2_2", 0, "", offsetof(B_ctrl_student_HIL_T, k2_2)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 110, 0 },

  { 56, "ctrl_student_hil/k2_3", 0, "", offsetof(B_ctrl_student_HIL_T, k2_3)+0*
    sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 112, 0 },

  { 57, "ctrl_student_hil/DP Observer /Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    114, 0 },

  { 58, "ctrl_student_hil/DP Observer /Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    116, 0 },

  { 59, "ctrl_student_hil/DP Observer /Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    118, 0 },

  { 60, "ctrl_student_hil/DP Observer /b", 0, "", offsetof(B_ctrl_student_HIL_T,
    b)+0*sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 120, 0 },

  { 61, "ctrl_student_hil/DP Observer /demp", 0, "", offsetof
    (B_ctrl_student_HIL_T, demp)+0*sizeof(real_T), BLOCKIO_SIG, 36, 1, 2, 122, 0
  },

  { 62, "ctrl_student_hil/Reset", 0, "", offsetof(B_ctrl_student_HIL_T, Reset)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 124, 0 },

  { 63, "ctrl_student_hil/k_0", 0, "", offsetof(B_ctrl_student_HIL_T, k_0)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 126, 0 },

  { 64, "ctrl_student_hil/SurgeObserver /Constant", 0, "", offsetof
    (B_ctrl_student_HIL_T, Constant)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 128,
    0 },

  { 65, "ctrl_student_hil/SurgeObserver /Sum4", 0, "u_hat", offsetof
    (B_ctrl_student_HIL_T, u_hat)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 130, 0
  },

  { 66, "ctrl_student_hil/tau to real ship (only use in MCLab)/u_calb_ctrl", 0,
    "", offsetof(B_ctrl_student_HIL_T, u_calb_ctrl)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 132, 0 },

  { 67, "ctrl_student_hil/tau to real ship (only use in MCLab)/Sum", 0, "",
    offsetof(B_ctrl_student_HIL_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    134, 0 },

  { 68, "ctrl_student_hil/tau to real ship (only use in MCLab)/alpha_calb_ctrl1",
    0, "", offsetof(B_ctrl_student_HIL_T, alpha_calb_ctrl1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil/tau to real ship (only use in MCLab)/Sum1", 0, "",
    offsetof(B_ctrl_student_HIL_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    138, 0 },

  { 70, "ctrl_student_hil/Dead reckoning/r_gyro", 0, "", offsetof
    (B_ctrl_student_HIL_T, r_gyro)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 140,
    0 },

  { 71, "ctrl_student_hil/Dead reckoning/bias_r_gyro", 0, "", offsetof
    (B_ctrl_student_HIL_T, bias_r_gyro)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/Dead reckoning/Add", 0, "", offsetof
    (B_ctrl_student_HIL_T, Add)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 144, 0 },

  { 73, "ctrl_student_hil/Dead reckoning/eta_dot_imu", 0, "", offsetof
    (B_ctrl_student_HIL_T, eta_dot_imu)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    146, 0 },

  { 74,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw",
    0, "u_BT", offsetof(B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 148, 0 },

  { 75,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw",
    3, "omega_VSP", offsetof(B_ctrl_student_HIL_T, omega_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil/Transfer function", 0, "s_dot", offsetof
    (B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 152, 0
  },

  { 77, "ctrl_student_hil/Transfer function", 1, "tau(1,1)", offsetof
    (B_ctrl_student_HIL_T, tau)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 154, 0
  },

  { 78, "ctrl_student_hil/Transfer function", 1, "tau(1,2)", offsetof
    (B_ctrl_student_HIL_T, tau)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 156, 0
  },

  { 79, "ctrl_student_hil/Transfer function", 1, "tau(1,3)", offsetof
    (B_ctrl_student_HIL_T, tau)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 158, 0
  },

  { 80, "ctrl_student_hil/Transfer function", 2, "eta_d(1,1)", offsetof
    (B_ctrl_student_HIL_T, eta_d)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 160,
    0 },

  { 81, "ctrl_student_hil/Transfer function", 2, "eta_d(1,2)", offsetof
    (B_ctrl_student_HIL_T, eta_d)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 162,
    0 },

  { 82, "ctrl_student_hil/Transfer function", 2, "eta_d(1,3)", offsetof
    (B_ctrl_student_HIL_T, eta_d)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 164,
    0 },

  { 83, "ctrl_student_hil/Transfer function", 3, "taus(1,1)", offsetof
    (B_ctrl_student_HIL_T, taus)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 166, 0
  },

  { 84, "ctrl_student_hil/Transfer function", 3, "taus(1,2)", offsetof
    (B_ctrl_student_HIL_T, taus)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 168, 0
  },

  { 85, "ctrl_student_hil/Transfer function", 3, "taus(1,3)", offsetof
    (B_ctrl_student_HIL_T, taus)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 170, 0
  },

  { 86, "ctrl_student_hil/Transfer function", 4, "dtot_nu(1,1)", offsetof
    (B_ctrl_student_HIL_T, dtot_nu)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 172,
    0 },

  { 87, "ctrl_student_hil/Transfer function", 4, "dtot_nu(1,2)", offsetof
    (B_ctrl_student_HIL_T, dtot_nu)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 174,
    0 },

  { 88, "ctrl_student_hil/Transfer function", 4, "dtot_nu(1,3)", offsetof
    (B_ctrl_student_HIL_T, dtot_nu)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 176,
    0 },

  { 89, "ctrl_student_hil/Transfer function", 5, "m_alpha_1_dot(1,1)", offsetof
    (B_ctrl_student_HIL_T, m_alpha_1_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 178, 0 },

  { 90, "ctrl_student_hil/Transfer function", 5, "m_alpha_1_dot(1,2)", offsetof
    (B_ctrl_student_HIL_T, m_alpha_1_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 180, 0 },

  { 91, "ctrl_student_hil/Transfer function", 5, "m_alpha_1_dot(1,3)", offsetof
    (B_ctrl_student_HIL_T, m_alpha_1_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 182, 0 },

  { 92, "ctrl_student_hil/Transfer function", 6, "K_2_z_2(1,1)", offsetof
    (B_ctrl_student_HIL_T, K_2_z_2)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 184,
    0 },

  { 93, "ctrl_student_hil/Transfer function", 6, "K_2_z_2(1,2)", offsetof
    (B_ctrl_student_HIL_T, K_2_z_2)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 186,
    0 },

  { 94, "ctrl_student_hil/Transfer function", 6, "K_2_z_2(1,3)", offsetof
    (B_ctrl_student_HIL_T, K_2_z_2)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 188,
    0 },

  { 95, "ctrl_student_hil/Transfer function", 7, "z_1(1,1)", offsetof
    (B_ctrl_student_HIL_T, z_1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 190, 0
  },

  { 96, "ctrl_student_hil/Transfer function", 7, "z_1(1,2)", offsetof
    (B_ctrl_student_HIL_T, z_1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 192, 0
  },

  { 97, "ctrl_student_hil/Transfer function", 7, "z_1(1,3)", offsetof
    (B_ctrl_student_HIL_T, z_1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 194, 0
  },

  { 98, "ctrl_student_hil/SurgeObserver /Integration block", 0, "y", offsetof
    (B_ctrl_student_HIL_T, y_k)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 196, 0 },

  { 99,
    "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 198, 0 },

  { 100,
    "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 200, 0 },

  { 101,
    "ctrl_student_hil/Noise Generator/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 202, 0 },

  { 102,
    "ctrl_student_hil/Noise Generator/Noise generator/Downsamplesignal/MATLAB Function",
    0, "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 204, 0 },

  { 103, "ctrl_student_hil/MATLAB Function", 0, "eta1(1,1)", offsetof
    (B_ctrl_student_HIL_T, eta1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 206, 0
  },

  { 104, "ctrl_student_hil/MATLAB Function", 0, "eta1(1,2)", offsetof
    (B_ctrl_student_HIL_T, eta1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 208, 0
  },

  { 105, "ctrl_student_hil/MATLAB Function", 0, "eta1(1,3)", offsetof
    (B_ctrl_student_HIL_T, eta1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 210, 0
  },

  { 106, "ctrl_student_hil/Dead reckoning/MATLAB Function", 0, "newmem(1,1)",
    offsetof(B_ctrl_student_HIL_T, newmem)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 212, 0 },

  { 107, "ctrl_student_hil/Dead reckoning/MATLAB Function", 0, "newmem(1,2)",
    offsetof(B_ctrl_student_HIL_T, newmem)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 214, 0 },

  { 108, "ctrl_student_hil/Dead reckoning/MATLAB Function", 0, "newmem(1,3)",
    offsetof(B_ctrl_student_HIL_T, newmem)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 216, 0 },

  { 109, "ctrl_student_hil/Dead reckoning/MATLAB Function", 1, "dead(1,1)",
    offsetof(B_ctrl_student_HIL_T, dead)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    218, 0 },

  { 110, "ctrl_student_hil/Dead reckoning/MATLAB Function", 1, "dead(1,2)",
    offsetof(B_ctrl_student_HIL_T, dead)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    220, 0 },

  { 111, "ctrl_student_hil/Dead reckoning/MATLAB Function", 1, "dead(1,3)",
    offsetof(B_ctrl_student_HIL_T, dead)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    222, 0 },

  { 112, "ctrl_student_hil/DP Observer /Observer", 0, "eta_hat_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, eta_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 224, 0 },

  { 113, "ctrl_student_hil/DP Observer /Observer", 0, "eta_hat_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, eta_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 226, 0 },

  { 114, "ctrl_student_hil/DP Observer /Observer", 0, "eta_hat_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, eta_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 228, 0 },

  { 115, "ctrl_student_hil/DP Observer /Observer", 1, "nu_hat_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, nu_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 230, 0 },

  { 116, "ctrl_student_hil/DP Observer /Observer", 1, "nu_hat_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, nu_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 232, 0 },

  { 117, "ctrl_student_hil/DP Observer /Observer", 1, "nu_hat_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, nu_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 234, 0 },

  { 118, "ctrl_student_hil/DP Observer /Observer", 2, "b_hat_dot", offsetof
    (B_ctrl_student_HIL_T, b_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    236, 0 },

  { 119, "ctrl_student_hil/DP Observer /Observer", 3, "x_bar", offsetof
    (B_ctrl_student_HIL_T, x_bar)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 238, 0
  },

  { 120, "ctrl_student_hil/DP Observer /Observer", 4, "y_bar", offsetof
    (B_ctrl_student_HIL_T, y_bar)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 240, 0
  },

  { 121, "ctrl_student_hil/DP Observer /Observer", 5, "psi_bar", offsetof
    (B_ctrl_student_HIL_T, psi_bar)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 242,
    0 },

  { 122,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking",
    0, "fault", offsetof(B_ctrl_student_HIL_T, fault)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 244, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 123;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 95;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 1, "joystick/PosXRight", 1, EXT_IN, 1, 1, 1 },

  { 2, "joystick/PosYRight", 1, EXT_IN, 1, 1, 1 },

  { 3, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 4, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 5, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 6, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 7, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 9, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 10, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 11, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 12, "y", 0, EXT_IN, 1, 1, 1 },

  { 13, "Noise Generator/noise pos", 0, EXT_IN, 1, 1, 1 },

  { 14, "Noise Generator/noise head", 0, EXT_IN, 1, 1, 1 },

  { 15, "x", 0, EXT_IN, 1, 1, 1 },

  { 16, "psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Noise Generator/enable noise", 0, EXT_IN, 1, 1, 1 },

  { 18, "Dead reckoning/drop_out", 0, EXT_IN, 1, 1, 1 },

  { 19, "DP Observer /L1_diag", 0, EXT_IN, 3, 3, 1 },

  { 20, "DP Observer /L2_diag ", 0, EXT_IN, 3, 3, 1 },

  { 21, "DP Observer /L3_diag", 0, EXT_IN, 3, 3, 1 },

  { 22, "case_number", 0, EXT_IN, 1, 1, 1 },

  { 23, "DP Observer /use_dp_observer", 0, EXT_IN, 1, 1, 1 },

  { 24, "mu", 0, EXT_IN, 1, 1, 1 },

  { 25, "rx", 0, EXT_IN, 1, 1, 1 },

  { 26, "ry", 0, EXT_IN, 1, 1, 1 },

  { 27, "kp1", 0, EXT_IN, 1, 1, 1 },

  { 28, "kp2", 0, EXT_IN, 1, 1, 1 },

  { 29, "kp3", 0, EXT_IN, 1, 1, 1 },

  { 30, "k2_1", 0, EXT_IN, 1, 1, 1 },

  { 31, "k2_2", 0, EXT_IN, 1, 1, 1 },

  { 32, "k2_3", 0, EXT_IN, 1, 1, 1 },

  { 33, "DP Observer /b", 0, EXT_IN, 1, 1, 1 },

  { 34, "DP Observer /demp", 0, EXT_IN, 1, 1, 1 },

  { 35, "Reset", 0, EXT_IN, 1, 1, 1 },

  { 36, "k_0", 0, EXT_IN, 1, 1, 1 },

  { 37, "tau to real ship (only use in MCLab)/u_calb_ctrl", 0, EXT_IN, 1, 1, 1 },

  { 38, "tau to real ship (only use in MCLab)/alpha_calb_ctrl1", 0, EXT_IN, 1, 1,
    1 },

  { 39, "Dead reckoning/r_gyro", 0, EXT_IN, 1, 1, 1 },

  { 40, "Dead reckoning/bias_r_gyro", 0, EXT_IN, 1, 1, 1 },

  { 41, "Dead reckoning/eta_dot_imu", 0, EXT_IN, 1, 1, 1 },

  { 0, "Test", 1, EXT_OUT, 1, 1, 1 },

  { 1, "tau to CSE mocell (only use for HIL testing)/X_d", 1, EXT_OUT, 1, 1, 1 },

  { 2, "tau to CSE mocell (only use for HIL testing)/N_d", 1, EXT_OUT, 1, 1, 1 },

  { 3, "tau to CSE mocell (only use for HIL testing)/Y_d", 1, EXT_OUT, 1, 1, 1 },

  { 4, "tau to CSE mocell (only use for HIL testing)/osi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 5, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1 },

  { 6, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1 },

  { 7, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 1,
    EXT_OUT, 1, 1, 1 },

  { 8, "Noise Generator/x_m", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Noise Generator/psi_m", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Noise Generator/y_m", 0, EXT_OUT, 1, 1, 1 },

  { 11, "DP Observer /psi_bar", 0, EXT_OUT, 1, 1, 1 },

  { 12, "DP Observer /psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 13, "DP Observer /r_dot", 0, EXT_OUT, 1, 1, 1 },

  { 14, "DP Observer /u_dot", 0, EXT_OUT, 1, 1, 1 },

  { 15, "DP Observer /v_dot", 0, EXT_OUT, 1, 1, 1 },

  { 16, "DP Observer /x_bar", 0, EXT_OUT, 1, 1, 1 },

  { 17, "DP Observer /x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 18, "DP Observer /y_bar", 0, EXT_OUT, 1, 1, 1 },

  { 19, "DP Observer /y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 20, "x_d", 0, EXT_OUT, 1, 1, 1 },

  { 21, "y_d", 0, EXT_OUT, 1, 1, 1 },

  { 22, "psi_d", 0, EXT_OUT, 1, 1, 1 },

  { 23, "psi_1", 0, EXT_OUT, 1, 1, 1 },

  { 24, "x_1", 0, EXT_OUT, 1, 1, 1 },

  { 25, "y_1", 0, EXT_OUT, 1, 1, 1 },

  { 26, "tau_psi", 0, EXT_OUT, 1, 1, 1 },

  { 27, "tau_x", 0, EXT_OUT, 1, 1, 1 },

  { 28, "tau_y", 0, EXT_OUT, 1, 1, 1 },

  { 29, "tau_psi1", 0, EXT_OUT, 1, 1, 1 },

  { 30, "tau_x1", 0, EXT_OUT, 1, 1, 1 },

  { 31, "tau_y1", 0, EXT_OUT, 1, 1, 1 },

  { 32, "dtot_nu_psi", 0, EXT_OUT, 1, 1, 1 },

  { 33, "dtot_nu_x", 0, EXT_OUT, 1, 1, 1 },

  { 34, "dtot_nu_y", 0, EXT_OUT, 1, 1, 1 },

  { 35, "m_alpha_1_dot_psi", 0, EXT_OUT, 1, 1, 1 },

  { 36, "m_alpha_1_dot_x", 0, EXT_OUT, 1, 1, 1 },

  { 37, "m_alpha_1_dot_y", 0, EXT_OUT, 1, 1, 1 },

  { 38, "K_2_z_2_psi", 0, EXT_OUT, 1, 1, 1 },

  { 39, "K_2_z_2_x", 0, EXT_OUT, 1, 1, 1 },

  { 40, "K_2_z_2_y", 0, EXT_OUT, 1, 1, 1 },

  { 41, "z_1_psi", 0, EXT_OUT, 1, 1, 1 },

  { 42, "z_1_x", 0, EXT_OUT, 1, 1, 1 },

  { 43, "SurgeObserver /u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 44,
    "tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds",
    0, EXT_OUT, 1, 1, 1 },

  { 45,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 46,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 47,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 48,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 49, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT",
    0, EXT_OUT, 1, 1, 1 },

  { 50, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 51, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 52, "z_1_y", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.149";
static char* NI_CompiledModelDateTime = "Tue Mar 28 11:39:03 2017";
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
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
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
             (P_ctrl_student_HIL_T));
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
               (P_ctrl_student_HIL_T));

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
           (P_ctrl_student_HIL_T));
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
           (P_ctrl_student_HIL_T));
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
           (P_ctrl_student_HIL_T));
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
      *numContStates = 18;
      *numDiscStates = 1815;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      contStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[0], count, 0, 0);
      strcpy(contStatesNames + (idx++ * 100), "IntegratorSecondOrder_CSTATE");
    }

    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_m, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_m");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_j, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_j");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Test_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Test_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.osi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.osi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.noisepos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.noisepos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.noisehead_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.noisehead_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_i,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.enablenoise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.enablenoise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.drop_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.drop_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L1_diag_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L1_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L1_diag_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L1_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L1_diag_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L1_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_diag_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_diag_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_diag_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L3_diag_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L3_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L3_diag_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L3_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L3_diag_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L3_diag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.case_number_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.case_number_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.use_dp_observer_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.use_dp_observer_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_g, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_g, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_g, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.mu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.rx_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.rx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ry_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ry_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.b_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.b_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.demp_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.demp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_bar_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_dot_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_dot_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_dot_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Reset_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_psi1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_x1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_y1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.dtot_nu_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.dtot_nu_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.dtot_nu_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.dtot_nu_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.dtot_nu_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.dtot_nu_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.K_2_z_2_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.K_2_z_2_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.K_2_z_2_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.K_2_z_2_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.z_1_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.z_1_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z_1_x_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z_1_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_calb_ctrl_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_calb_ctrl_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z_1_y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z_1_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_gyro_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_gyro_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.bias_r_gyro_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.bias_r_gyro_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_dot_imu_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_dot_imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_a, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 0, 20, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 1, 20, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 2, 20, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Test_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Test_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.osi_0_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.osi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.noisepos_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.noisepos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.noisehead_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.noisehead_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.enablenoise_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.enablenoise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_m_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.drop_out_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.drop_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L1_diag_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L1_diag_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_diag_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_diag_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L3_diag_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L3_diag_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.case_number_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.case_number_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.use_dp_observer_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.use_dp_observer_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.mu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.rx_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.rx_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ry_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ry_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kp3_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kp3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k2_3_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k2_3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.b_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.b_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.demp_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.demp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_bar_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_hat_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.r_dot_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.r_dot_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_dot_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_dot_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.v_dot_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.v_dot_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_bar_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_bar_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_hat_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_d_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_d_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_d_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Reset_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.k_0_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.k_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_psi_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_psi1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_psi1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_x1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_x1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_y1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_y1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.dtot_nu_psi_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.dtot_nu_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.dtot_nu_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.dtot_nu_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.dtot_nu_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.dtot_nu_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_2_z_2_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_2_z_2_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_2_z_2_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_2_z_2_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.z_1_psi_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.z_1_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.z_1_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.z_1_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_hat_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_calb_ctrl_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_calb_ctrl_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_j, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_j");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.z_1_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.z_1_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.r_gyro_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.r_gyro_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bias_r_gyro_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bias_r_gyro_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_dot_imu_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_dot_imu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IntegratorSecondOrder_DWORK1, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IntegratorSecondOrder_DWORK1");
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
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_X.IntegratorSecondOrder_CSTATE[0],
        count, contStates[idx++], 0, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_m, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_i[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_j, 0,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Test_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.osi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepos_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisehead_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_i, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enablenoise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.drop_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_diag_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_diag_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_diag_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_diag_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_diag_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_diag_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_diag_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_diag_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_diag_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.case_number_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.use_dp_observer_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_g, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_g, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_g, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.rx_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ry_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.b_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.demp_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_bar_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_dot_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_dot_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_dot_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Reset_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_x_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_calb_ctrl_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_y_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_gyro_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_r_gyro_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_dot_imu_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_a, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 0,
      discStates[idx++], 20, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 1,
      discStates[idx++], 20, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IntegratorSecondOrder_MODE, 2,
      discStates[idx++], 20, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Test_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.osi_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepos_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisehead_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enablenoise_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.drop_out_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_diag_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_diag_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_diag_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.case_number_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.use_dp_observer_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.rx_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ry_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kp3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k2_3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.b_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.demp_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_bar_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_dot_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_dot_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_dot_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Reset_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.k_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dtot_nu_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_psi_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.m_alpha_1_dot_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_2_z_2_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_calb_ctrl_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_calb_ctrl1_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_j, count,
         discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z_1_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_gyro_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_r_gyro_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_dot_imu_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 21, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IntegratorSecondOrder_DWORK1, 0,
      discStates[idx++], 8, 0);
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
