/*
 * ctrl_case_b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_case_b".
 *
 * Model version              : 1.278
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Mar 22 12:06:28 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_case_b.h"
#include "ctrl_case_b_private.h"

const real_T ctrl_case_b_RGND = 0.0;   /* real_T ground */

/* Block signals (auto storage) */
B_ctrl_case_b_T ctrl_case_b_B;

/* Continuous states */
X_ctrl_case_b_T ctrl_case_b_X;

/* Block states (auto storage) */
DW_ctrl_case_b_T ctrl_case_b_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_case_b_T ctrl_case_b_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_case_b_T ctrl_case_b_M_;
RT_MODEL_ctrl_case_b_T *const ctrl_case_b_M = &ctrl_case_b_M_;

/*
 * This function updates continuous states using the ODE2 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE2_IntgData *id = (ODE2_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
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
  ctrl_case_b_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  ctrl_case_b_output();
  ctrl_case_b_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
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

/* Model output function */
void ctrl_case_b_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  ZCEventType zcEvent;
  real_T mem[9];
  real_T mem_out;
  real_T rtb_Product;
  real_T rtb_Product_f;
  real_T rtb_Switch[3];
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T u_idx_0;
  real_T u_idx_1;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* set solver stop time */
    if (!(ctrl_case_b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_case_b_M->solverInfo,
                            ((ctrl_case_b_M->Timing.clockTickH0 + 1) *
        ctrl_case_b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_case_b_M->solverInfo,
                            ((ctrl_case_b_M->Timing.clockTick0 + 1) *
        ctrl_case_b_M->Timing.stepSize0 + ctrl_case_b_M->Timing.clockTickH0 *
        ctrl_case_b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_case_b_M)) {
    ctrl_case_b_M->Timing.t[0] = rtsiGetT(&ctrl_case_b_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S4>/Step size'
     *  Memory: '<S9>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S12>:1' */
    /* '<S12>:1:3' */
    if ((ctrl_case_b_DW.counter_PreviousInput + 1.0) *
        ctrl_case_b_P.Stepsize_Value >= 1.0 / ctrl_case_b_P.Constant1_Value) {
      /* '<S12>:1:4' */
      /* '<S12>:1:5' */
      ctrl_case_b_B.count = 0.0;
    } else {
      /* '<S12>:1:7' */
      ctrl_case_b_B.count = ctrl_case_b_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* RandomNumber: '<S15>/White Noise' */
    ctrl_case_b_B.WhiteNoise = ctrl_case_b_DW.NextOutput;
  }

  /* Product: '<S15>/Product' incorporates:
   *  Constant: '<S4>/Step size'
   *  Product: '<S15>/Divide'
   *  Sqrt: '<S15>/Sqrt'
   */
  rtb_Product = sqrt(ctrl_case_b_B.noise_power_p / ctrl_case_b_P.Stepsize_Value)
    * ctrl_case_b_B.WhiteNoise;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* RandomNumber: '<S16>/White Noise' */
    ctrl_case_b_B.WhiteNoise_e = ctrl_case_b_DW.NextOutput_c;
  }

  /* Product: '<S16>/Product' incorporates:
   *  Constant: '<S4>/Step size'
   *  Product: '<S16>/Divide'
   *  Sqrt: '<S16>/Sqrt'
   */
  rtb_Product_f = sqrt(ctrl_case_b_B.noise_power_p /
                       ctrl_case_b_P.Stepsize_Value) *
    ctrl_case_b_B.WhiteNoise_e;

  /* Product: '<S14>/Divide' incorporates:
   *  Constant: '<S4>/Step size'
   */
  rtb_Integrator = ctrl_case_b_B.noise_power_psi / ctrl_case_b_P.Stepsize_Value;

  /* Sqrt: '<S14>/Sqrt' */
  rtb_Integrator = sqrt(rtb_Integrator);
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* RandomNumber: '<S14>/White Noise' */
    ctrl_case_b_B.WhiteNoise_m = ctrl_case_b_DW.NextOutput_p;
  }

  /* Product: '<S14>/Product' */
  rtb_Integrator *= ctrl_case_b_B.WhiteNoise_m;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Constant: '<Root>/Constant4' */
    ctrl_case_b_B.Constant4 = ctrl_case_b_P.Constant4_Value;
  }

  /* Integrator: '<S5>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_case_b_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_case_b_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_case_b_X.Integrator1_CSTATE[0] = ctrl_case_b_B.Constant4;
      ctrl_case_b_X.Integrator1_CSTATE[1] = ctrl_case_b_B.Constant4;
      ctrl_case_b_X.Integrator1_CSTATE[2] = ctrl_case_b_B.Constant4;
    }
  }

  ctrl_case_b_B.Integrator1[0] = ctrl_case_b_X.Integrator1_CSTATE[0];
  ctrl_case_b_B.Integrator1[1] = ctrl_case_b_X.Integrator1_CSTATE[1];
  ctrl_case_b_B.Integrator1[2] = ctrl_case_b_X.Integrator1_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Memory: '<S10>/Hold' */
    ctrl_case_b_B.Hold[0] = ctrl_case_b_DW.Hold_PreviousInput[0];
    ctrl_case_b_B.Hold[1] = ctrl_case_b_DW.Hold_PreviousInput[1];
    ctrl_case_b_B.Hold[2] = ctrl_case_b_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S10>/MATLAB Function1' incorporates:
   *  Sum: '<S4>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S13>:1' */
  if (ctrl_case_b_B.count == 0.0) {
    /* '<S13>:1:4' */
    /* '<S13>:1:5' */
    ctrl_case_b_B.output[0] = rtb_Product + ctrl_case_b_B.Integrator1[0];
    ctrl_case_b_B.output[1] = rtb_Product_f + ctrl_case_b_B.Integrator1[1];
    ctrl_case_b_B.output[2] = rtb_Integrator + ctrl_case_b_B.Integrator1[2];
  } else {
    /* '<S13>:1:7' */
    ctrl_case_b_B.output[0] = ctrl_case_b_B.Hold[0];
    ctrl_case_b_B.output[1] = ctrl_case_b_B.Hold[1];
    ctrl_case_b_B.output[2] = ctrl_case_b_B.Hold[2];
  }

  /* End of MATLAB Function: '<S10>/MATLAB Function1' */

  /* Switch: '<S4>/Switch' */
  if (ctrl_case_b_B.noise != 0.0) {
    rtb_Switch[0] = ctrl_case_b_B.output[0];
    rtb_Switch[1] = ctrl_case_b_B.output[1];
    rtb_Switch[2] = ctrl_case_b_B.output[2];
  } else {
    rtb_Switch[0] = ctrl_case_b_B.Integrator1[0];
    rtb_Switch[1] = ctrl_case_b_B.Integrator1[1];
    rtb_Switch[2] = ctrl_case_b_B.Integrator1[2];
  }

  /* End of Switch: '<S4>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Memory: '<Root>/Memory' */
    memcpy(&ctrl_case_b_B.Memory[0], &ctrl_case_b_DW.Memory_PreviousInput[0], 9U
           * sizeof(real_T));
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:2' */
  ctrl_case_b_B.dead_x = 0.0;

  /* '<S1>:1:3' */
  /* '<S1>:1:4' */
  /* '<S1>:1:5' */
  for (i = 0; i < 9; i++) {
    mem[i] = ctrl_case_b_B.Memory[i];
    ctrl_case_b_B.newmem[i] = ctrl_case_b_B.Memory[i];
  }

  /*  This value needs to be changed based on the iteration speed */
  if (ctrl_case_b_B.Memory[0] - floor(ctrl_case_b_B.Memory[0] / 50.0) * 50.0 ==
      0.0) {
    /* '<S1>:1:9' */
    /* '<S1>:1:10' */
    mem[6] = ctrl_case_b_B.Memory[3];

    /* '<S1>:1:11' */
    mem[3] = rtb_Switch[0];

    /* '<S1>:1:12' */
    mem[0] = 1.0;
  }

  /* '<S1>:1:14' */
  ctrl_case_b_B.newmem[0] = mem[0] + 1.0;
  if (mem[3] == mem[6]) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    ctrl_case_b_B.dead_x = 1.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_case_b_PrevZCX.IntegratorSecondOrder_Reset_ZCE,
                       (ctrl_case_b_B.dead_x));
    if (zcEvent != NO_ZCEVENT) {
      ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0] =
        ctrl_case_b_P.IntegratorSecondOrder_ICX;
      ctrl_case_b_X.IntegratorSecondOrder_CSTATE[1] =
        ctrl_case_b_P.IntegratorSecondOrder_ICDXDT;
      ctrl_case_b_DW.IntegratorSecondOrder_MODE = 0;
      rtsiSetSolverNeedsReset(&ctrl_case_b_M->solverInfo, true);
    }
  }

  /* End of SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  /* MATLAB Function 'MATLAB Function1': '<S2>:1' */
  /* if is_dead == 1.0 */
  /*     eta = eta_m + x; */
  /* else */
  /*     eta = eta_m; */
  /* end */
  /* '<S2>:1:7' */
  ctrl_case_b_B.eta[0] = rtb_Switch[0];
  ctrl_case_b_B.eta[1] = rtb_Switch[1];
  ctrl_case_b_B.eta[2] = rtb_Switch[2];

  /* MATLAB Function: '<S6>/the rest ' */
  /* MATLAB Function 'SurgeObserver /the rest ': '<S20>:1' */
  /* '<S20>:1:3' */
  if (sin(ctrl_case_b_B.eta[2]) + cos(ctrl_case_b_B.eta[2]) < 0.0) {
    /* '<S20>:1:5' */
    /* '<S20>:1:6' */
    rtb_Product = -ctrl_case_b_B.k_0;
  } else {
    /* '<S20>:1:8' */
    rtb_Product = ctrl_case_b_B.k_0;
  }

  /* '<S20>:1:11' */
  rtb_Product *= ctrl_case_b_B.eta[0] + ctrl_case_b_B.eta[1];

  /* End of MATLAB Function: '<S6>/the rest ' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Constant: '<S6>/Constant' */
    ctrl_case_b_B.Constant = ctrl_case_b_P.Constant_Value;
  }

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_case_b_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_case_b_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_case_b_X.Integrator_CSTATE = ctrl_case_b_B.Constant;
    }
  }

  rtb_Integrator = ctrl_case_b_X.Integrator_CSTATE;

  /* Sum: '<S6>/Sum4' */
  ctrl_case_b_B.u_hat = rtb_Product + rtb_Integrator;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_case_b_PrevZCX.Integrator_Reset_ZCE_h,
                       ctrl_case_b_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_case_b_X.Integrator_CSTATE_b[0] = (ctrl_case_b_P.Integrator_IC[0]);
      ctrl_case_b_X.Integrator_CSTATE_b[1] = (ctrl_case_b_P.Integrator_IC[1]);
      ctrl_case_b_X.Integrator_CSTATE_b[2] = (ctrl_case_b_P.Integrator_IC[2]);
    }
  }

  ctrl_case_b_B.Integrator[0] = ctrl_case_b_X.Integrator_CSTATE_b[0];
  ctrl_case_b_B.Integrator[1] = ctrl_case_b_X.Integrator_CSTATE_b[1];
  ctrl_case_b_B.Integrator[2] = ctrl_case_b_X.Integrator_CSTATE_b[2];
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  Sum: '<S7>/Sum'
   */
  ctrl_case_b_B.Gain = (ctrl_case_b_B.L2_continuous -
                        ctrl_case_b_B.R2_continuous) * ctrl_case_b_P.Gain_Gain;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Memory: '<S7>/Memory' */
    ctrl_case_b_B.Memory_a = ctrl_case_b_DW.Memory_PreviousInput_m;

    /* Memory: '<S7>/Memory1' */
    ctrl_case_b_B.Memory1 = ctrl_case_b_DW.Memory1_PreviousInput;
  }

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'joystick/MATLAB Function': '<S21>:1' */
  /* '<S21>:1:7' */
  /* '<S21>:1:9' */
  u_idx_1 = ctrl_case_b_B.PosXRight - ctrl_case_b_B.PosYRight * 0.0;
  rtb_Product_f = ((ctrl_case_b_B.Gain - ctrl_case_b_B.PosYRight * 0.0) -
                   u_idx_1 * -0.4575) / 0.845;
  u_idx_1 -= rtb_Product_f;
  u_idx_0 = (ctrl_case_b_B.PosYRight - rtb_Product_f * 0.0) - u_idx_1 * 0.0;

  /* '<S21>:1:11' */
  if ((ctrl_case_b_B.ArrowUp > 0.5) && (ctrl_case_b_B.Memory1 !=
       ctrl_case_b_B.ArrowUp)) {
    /* '<S21>:1:12' */
    /* '<S21>:1:13' */
    mem_out = -ctrl_case_b_B.Memory_a;
  } else {
    /* '<S21>:1:15' */
    mem_out = ctrl_case_b_B.Memory_a;
  }

  /* checking which controller mapping to use */
  /*  -1 is the full thrust allocation */
  /*  1 is the simple thrust allocation */
  switch ((int32_T)mem_out) {
   case 1:
    /* '<S21>:1:23' */
    rtb_Product = sqrt(u_idx_0 * u_idx_0 + u_idx_1 * u_idx_1) / 2.33;

    /* '<S21>:1:24' */
    rtb_Product_f /= 2.629;

    /* '<S21>:1:25' */
    u_idx_1 = rt_atan2d_snf(u_idx_1, -u_idx_0);

    /*  If limits are violated u = 0 */
    if (fabs(rtb_Product) > 1.0) {
      /* '<S21>:1:27' */
      /* '<S21>:1:28' */
      rtb_Product = 0.0;
    }

    if (fabs(rtb_Product_f) > 1.0) {
      /* '<S21>:1:30' */
      /* '<S21>:1:31' */
      rtb_Product_f = 0.0;
    }
    break;

   case -1:
    /* '<S21>:1:34' */
    u_idx_1 = fabs(ctrl_case_b_B.PosYRight);
    if ((1.165 >= u_idx_1) || rtIsNaN(u_idx_1)) {
      u_idx_1 = 1.165;
    }

    rtb_Product = u_idx_1 / 1.165;

    /* '<S21>:1:35' */
    u_idx_1 = fabs(ctrl_case_b_B.PosXRight);
    if ((2.629 >= u_idx_1) || rtIsNaN(u_idx_1)) {
      u_idx_1 = 2.629;
    }

    if (ctrl_case_b_B.PosXRight < 0.0) {
      rtb_Product_f = -1.0;
    } else if (ctrl_case_b_B.PosXRight > 0.0) {
      rtb_Product_f = 1.0;
    } else if (ctrl_case_b_B.PosXRight == 0.0) {
      rtb_Product_f = 0.0;
    } else {
      rtb_Product_f = ctrl_case_b_B.PosXRight;
    }

    rtb_Product_f *= u_idx_1 / 2.629;
    if (ctrl_case_b_B.PosYRight < 0.0) {
      /* '<S21>:1:36' */
      /* '<S21>:1:37' */
      u_idx_1 = 3.1415926535897931;
    } else {
      /* '<S21>:1:39' */
      u_idx_1 = 0.0;
    }
    break;

   default:
    /* '<S21>:1:42' */
    u_idx_1 = fabs(ctrl_case_b_B.PosYRight);
    if ((1.165 >= u_idx_1) || rtIsNaN(u_idx_1)) {
      u_idx_1 = 1.165;
    }

    if (ctrl_case_b_B.PosYRight < 0.0) {
      rtb_Product_f = -1.0;
    } else if (ctrl_case_b_B.PosYRight > 0.0) {
      rtb_Product_f = 1.0;
    } else if (ctrl_case_b_B.PosYRight == 0.0) {
      rtb_Product_f = 0.0;
    } else {
      rtb_Product_f = ctrl_case_b_B.PosYRight;
    }

    rtb_Product = u_idx_1 / 1.165 * rtb_Product_f;

    /* '<S21>:1:43' */
    u_idx_1 = fabs(ctrl_case_b_B.PosXRight);
    if ((2.629 >= u_idx_1) || rtIsNaN(u_idx_1)) {
      u_idx_1 = 2.629;
    }

    if (ctrl_case_b_B.PosXRight < 0.0) {
      rtb_Product_f = -1.0;
    } else if (ctrl_case_b_B.PosXRight > 0.0) {
      rtb_Product_f = 1.0;
    } else if (ctrl_case_b_B.PosXRight == 0.0) {
      rtb_Product_f = 0.0;
    } else {
      rtb_Product_f = ctrl_case_b_B.PosXRight;
    }

    rtb_Product_f *= u_idx_1 / 2.629;

    /* '<S21>:1:44' */
    u_idx_1 = 0.0;
    break;
  }

  ctrl_case_b_B.u_vsp = rtb_Product;
  ctrl_case_b_B.u_bt = rtb_Product_f;
  ctrl_case_b_B.alpha = u_idx_1;
  ctrl_case_b_B.omega = 0.3;
  ctrl_case_b_B.mem_out = mem_out;
  ctrl_case_b_B.hold_out = ctrl_case_b_B.ArrowUp;

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   */
  ctrl_case_b_B.thrust_out[0] = ctrl_case_b_P.Gain1_Gain *
    ctrl_case_b_B.PosXRight;
  ctrl_case_b_B.thrust_out[1] = ctrl_case_b_P.Constant_Value_p;

  /* MATLAB Function 'MATLAB Function2': '<S3>:1' */
  /* '<S3>:1:2' */
  /*  Axis in the middle of the pool (assumed) */
  /* '<S3>:1:4' */
  if (rtb_Switch[0] > 16.0) {
    /* '<S3>:1:5' */
    /* '<S3>:1:6' */
    ctrl_case_b_B.thrust_out[0] = -ctrl_case_b_B.thrust_out[0];
  } else {
    if (rtb_Switch[0] < -16.0) {
      /* '<S3>:1:7' */
      /* '<S3>:1:8' */
      ctrl_case_b_B.thrust_out[0] = -ctrl_case_b_B.thrust_out[0];
    }
  }

  /* '<S3>:1:4' */
  if (rtb_Switch[1] > 2.58) {
    /* '<S3>:1:5' */
    /* '<S3>:1:6' */
    ctrl_case_b_B.thrust_out[1] = -ctrl_case_b_B.thrust_out[1];
  } else {
    if (rtb_Switch[0] < -2.58) {
      /* '<S3>:1:7' */
      /* '<S3>:1:8' */
      ctrl_case_b_B.thrust_out[1] = -ctrl_case_b_B.thrust_out[1];
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* '<S3>:1:4' */
  /* '<S3>:1:11' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  ctrl_case_b_B.Gain_n = (ctrl_case_b_B.L2_continuous -
    ctrl_case_b_B.R2_continuous) * ctrl_case_b_P.Gain_Gain_a;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }

  /* MATLAB Function: '<S5>/kinematics' */
  /* MATLAB Function 'Subsystem/kinematics': '<S17>:1' */
  /* '<S17>:1:3' */
  /* '<S17>:1:5' */
  /* '<S17>:1:9' */
  tmp[0] = cos(ctrl_case_b_B.Integrator1[2]);
  tmp[3] = -sin(ctrl_case_b_B.Integrator1[2]);
  tmp[6] = 0.0;
  tmp[1] = sin(ctrl_case_b_B.Integrator1[2]);
  tmp[4] = cos(ctrl_case_b_B.Integrator1[2]);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    ctrl_case_b_B.eta_dot[i] = 0.0;
    ctrl_case_b_B.eta_dot[i] += tmp[i] * ctrl_case_b_B.Integrator[0];
    ctrl_case_b_B.eta_dot[i] += tmp[i + 3] * ctrl_case_b_B.Integrator[1];
    ctrl_case_b_B.eta_dot[i] += tmp[i + 6] * ctrl_case_b_B.Integrator[2];
  }

  /* End of MATLAB Function: '<S5>/kinematics' */

  /* MATLAB Function: '<S5>/kinetics' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Subsystem/kinetics': '<S18>:1' */
  /* '<S18>:1:3' */
  /* '<S18>:1:4' */
  /* '<S18>:1:5' */
  /* '<S18>:1:7' */
  /* % MATRICES */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S18>:1:31' */
  /* '<S18>:1:35' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S18>:1:41' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* '<S18>:1:48' */
  rtb_Product = -15.79 * ctrl_case_b_B.Integrator[1] - 0.55462499999999992 *
    ctrl_case_b_B.Integrator[2];

  /* '<S18>:1:49' */
  rtb_Product_f = 16.79 * ctrl_case_b_B.Integrator[0];

  /* '<S18>:1:50' */
  /* % Assembly of the damping matrix */
  /* '<S18>:1:55' */
  /* '<S18>:1:56' */
  /* '<S18>:1:57' */
  /*  using abs(r) */
  /* '<S18>:1:59' */
  /* '<S18>:1:60' */
  /* '<S18>:1:61' */
  /* '<S18>:1:63' */
  /* % CALCULATION */
  /* '<S18>:1:70' */
  tmp_0[0] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[6] = rtb_Product;
  tmp_0[1] = 0.0;
  tmp_0[4] = 0.0;
  tmp_0[7] = rtb_Product_f;
  tmp_0[2] = -rtb_Product;
  tmp_0[5] = -rtb_Product_f;
  tmp_0[8] = 0.0;
  tmp_1[0] = (0.6555 - 0.3545 * ctrl_case_b_B.Integrator[0]) -
    ctrl_case_b_B.Integrator[0] * ctrl_case_b_B.Integrator[0] * -3.787;
  tmp_1[3] = (-0.0 - -2.443 * ctrl_case_b_B.Integrator[1]) -
    ctrl_case_b_B.Integrator[1] * ctrl_case_b_B.Integrator[1] * 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = ((1.33 - -2.776 * ctrl_case_b_B.Integrator[1]) -
              ctrl_case_b_B.Integrator[1] * ctrl_case_b_B.Integrator[1] * -64.91)
    - -0.805 * fabs(ctrl_case_b_B.Integrator[2]);
  tmp_1[7] = ((7.25 - -3.45 * fabs(ctrl_case_b_B.Integrator[2])) -
              ctrl_case_b_B.Integrator[2] * ctrl_case_b_B.Integrator[2] * 0.0) -
    -0.845 * fabs(ctrl_case_b_B.Integrator[1]);
  tmp_1[2] = 0.0;
  tmp_1[5] = ((-0.0 - -0.2088 * ctrl_case_b_B.Integrator[1]) -
              ctrl_case_b_B.Integrator[1] * ctrl_case_b_B.Integrator[1] * 0.0) -
    0.13 * fabs(ctrl_case_b_B.Integrator[2]);
  tmp_1[8] = ((1.9 - -0.75 * fabs(ctrl_case_b_B.Integrator[2])) -
              ctrl_case_b_B.Integrator[2] * ctrl_case_b_B.Integrator[2] * 0.0) -
    0.08 * fabs(ctrl_case_b_B.Integrator[1]);
  for (i = 0; i < 3; i++) {
    tmp[3 * i] = tmp_0[3 * i] + tmp_1[3 * i];
    tmp[1 + 3 * i] = tmp_0[3 * i + 1] + tmp_1[3 * i + 1];
    tmp[2 + 3 * i] = tmp_0[3 * i + 2] + tmp_1[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    rtb_Switch[i] = tmp[i + 6] * ctrl_case_b_B.Integrator[2] + (tmp[i + 3] *
      ctrl_case_b_B.Integrator[1] + tmp[i] * ctrl_case_b_B.Integrator[0]);
  }

  ctrl_case_b_B.nu_dot[0] = ctrl_case_b_B.thrust_out[0] - rtb_Switch[0];
  ctrl_case_b_B.nu_dot[1] = (ctrl_case_b_B.thrust_out[1] - rtb_Switch[1]) -
    ctrl_case_b_B.nu_dot[0] * 0.0;
  ctrl_case_b_B.nu_dot[2] = ((ctrl_case_b_B.Gain_n - rtb_Switch[2]) -
    ctrl_case_b_B.nu_dot[0] * 0.0) - ctrl_case_b_B.nu_dot[1] *
    0.035125079164027864;
  ctrl_case_b_B.nu_dot[2] /= 2.7405187529686508;
  ctrl_case_b_B.nu_dot[0] -= ctrl_case_b_B.nu_dot[2] * 0.0;
  ctrl_case_b_B.nu_dot[1] -= ctrl_case_b_B.nu_dot[2] * 0.55462499999999992;
  ctrl_case_b_B.nu_dot[1] /= 15.79;
  ctrl_case_b_B.nu_dot[0] -= ctrl_case_b_B.nu_dot[1] * 0.0;
  ctrl_case_b_B.nu_dot[0] /= 16.79;

  /* End of MATLAB Function: '<S5>/kinetics' */

  /* MATLAB Function: '<S6>/Integration block ' */
  rtb_Product_f = ctrl_case_b_B.u_hat;

  /* MATLAB Function 'SurgeObserver /Integration block ': '<S19>:1' */
  /* '<S19>:1:2' */
  u_idx_1 = sin(ctrl_case_b_B.eta[2]) + cos(ctrl_case_b_B.eta[2]);
  if (ctrl_case_b_B.reset != 0.0) {
    /* '<S19>:1:6' */
    rtb_Product_f = 0.0;
  }

  if (u_idx_1 < 0.0) {
    /* '<S19>:1:9' */
    /* '<S19>:1:10' */
    rtb_Product = -ctrl_case_b_B.k_0;
  } else {
    /* '<S19>:1:12' */
    rtb_Product = ctrl_case_b_B.k_0;
  }

  /* '<S19>:1:15' */
  /* '<S19>:1:17' */
  ctrl_case_b_B.y = (-((0.6555 - 0.3545 * fabs(rtb_Product_f)) + rtb_Product_f *
                       rtb_Product_f * 3.787) * rtb_Product_f +
                     ctrl_case_b_B.thrust_out[0]) / 14.79 - rtb_Product *
    u_idx_1 * rtb_Product_f;

  /* End of MATLAB Function: '<S6>/Integration block ' */
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
  }
}

/* Model update function */
void ctrl_case_b_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Update for Memory: '<S9>/counter' */
    ctrl_case_b_DW.counter_PreviousInput = ctrl_case_b_B.count;

    /* Update for RandomNumber: '<S15>/White Noise' */
    ctrl_case_b_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed) * ctrl_case_b_P.WhiteNoise_StdDev +
      ctrl_case_b_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S16>/White Noise' */
    ctrl_case_b_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed_j) * ctrl_case_b_P.WhiteNoise_StdDev_d +
      ctrl_case_b_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S14>/White Noise' */
    ctrl_case_b_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed_c) * ctrl_case_b_P.WhiteNoise_StdDev_g +
      ctrl_case_b_P.WhiteNoise_Mean_f;
  }

  /* Update for Integrator: '<S5>/Integrator1' */
  ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Update for Memory: '<S10>/Hold' */
    ctrl_case_b_DW.Hold_PreviousInput[0] = ctrl_case_b_B.output[0];
    ctrl_case_b_DW.Hold_PreviousInput[1] = ctrl_case_b_B.output[1];
    ctrl_case_b_DW.Hold_PreviousInput[2] = ctrl_case_b_B.output[2];

    /* Update for Memory: '<Root>/Memory' */
    memcpy(&ctrl_case_b_DW.Memory_PreviousInput[0], &ctrl_case_b_B.newmem[0], 9U
           * sizeof(real_T));
  }

  /* Update for Integrator: '<S6>/Integrator' */
  ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    /* Update for Memory: '<S7>/Memory' */
    ctrl_case_b_DW.Memory_PreviousInput_m = ctrl_case_b_B.mem_out;

    /* Update for Memory: '<S7>/Memory1' */
    ctrl_case_b_DW.Memory1_PreviousInput = ctrl_case_b_B.hold_out;
  }

  if (rtmIsMajorTimeStep(ctrl_case_b_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_case_b_M->solverInfo);
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
  if (!(++ctrl_case_b_M->Timing.clockTick0)) {
    ++ctrl_case_b_M->Timing.clockTickH0;
  }

  ctrl_case_b_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_case_b_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_case_b_M->Timing.clockTick1)) {
      ++ctrl_case_b_M->Timing.clockTickH1;
    }

    ctrl_case_b_M->Timing.t[1] = ctrl_case_b_M->Timing.clockTick1 *
      ctrl_case_b_M->Timing.stepSize1 + ctrl_case_b_M->Timing.clockTickH1 *
      ctrl_case_b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_case_b_derivatives(void)
{
  XDot_ctrl_case_b_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  {
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)->
      Integrator1_CSTATE[0] = ctrl_case_b_B.eta_dot[0];
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)->
      Integrator1_CSTATE[1] = ctrl_case_b_B.eta_dot[1];
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)->
      Integrator1_CSTATE[2] = ctrl_case_b_B.eta_dot[2];
  }

  /* Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  if (ctrl_case_b_DW.IntegratorSecondOrder_MODE == 0) {
    _rtXdot->IntegratorSecondOrder_CSTATE[0] =
      ctrl_case_b_X.IntegratorSecondOrder_CSTATE[1];
    _rtXdot->IntegratorSecondOrder_CSTATE[1] = ctrl_case_b_B.u_dot_imu;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
  /* Derivatives for Integrator: '<S6>/Integrator' */
  {
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)->Integrator_CSTATE =
      ctrl_case_b_B.y;
  }

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)
      ->Integrator_CSTATE_b[0] = ctrl_case_b_B.nu_dot[0];
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)
      ->Integrator_CSTATE_b[1] = ctrl_case_b_B.nu_dot[1];
    ((XDot_ctrl_case_b_T *) ctrl_case_b_M->ModelData.derivs)
      ->Integrator_CSTATE_b[2] = ctrl_case_b_B.nu_dot[2];
  }
}

/* Model initialize function */
void ctrl_case_b_initialize(void)
{
  /* Start for Constant: '<Root>/Constant4' */
  ctrl_case_b_B.Constant4 = ctrl_case_b_P.Constant4_Value;

  /* Start for Constant: '<S6>/Constant' */
  ctrl_case_b_B.Constant = ctrl_case_b_P.Constant_Value;
  ctrl_case_b_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_case_b_PrevZCX.IntegratorSecondOrder_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_case_b_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_case_b_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S9>/counter' */
    ctrl_case_b_DW.counter_PreviousInput = ctrl_case_b_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S15>/White Noise' */
    tmp = floor(ctrl_case_b_P.WhiteNoise_Seed);
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

    ctrl_case_b_DW.RandSeed = tseed;
    ctrl_case_b_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed) * ctrl_case_b_P.WhiteNoise_StdDev +
      ctrl_case_b_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S15>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S16>/White Noise' */
    tmp = floor(ctrl_case_b_P.WhiteNoise_Seed_b);
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

    ctrl_case_b_DW.RandSeed_j = tseed;
    ctrl_case_b_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed_j) * ctrl_case_b_P.WhiteNoise_StdDev_d +
      ctrl_case_b_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S16>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S14>/White Noise' */
    tmp = floor(ctrl_case_b_P.WhiteNoise_Seed_l);
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

    ctrl_case_b_DW.RandSeed_c = tseed;
    ctrl_case_b_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_case_b_DW.RandSeed_c) * ctrl_case_b_P.WhiteNoise_StdDev_g +
      ctrl_case_b_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S14>/White Noise' */
    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    if (rtmIsFirstInitCond(ctrl_case_b_M)) {
      ctrl_case_b_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_case_b_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_case_b_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Memory: '<S10>/Hold' */
    ctrl_case_b_DW.Hold_PreviousInput[0] = ctrl_case_b_P.Hold_X0;
    ctrl_case_b_DW.Hold_PreviousInput[1] = ctrl_case_b_P.Hold_X0;
    ctrl_case_b_DW.Hold_PreviousInput[2] = ctrl_case_b_P.Hold_X0;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    memcpy(&ctrl_case_b_DW.Memory_PreviousInput[0], &ctrl_case_b_P.Memory_X0[0],
           9U * sizeof(real_T));

    /* InitializeConditions for SecondOrderIntegrator: '<Root>/Integrator, Second-Order' */
    ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0] =
      ctrl_case_b_P.IntegratorSecondOrder_ICX;
    ctrl_case_b_X.IntegratorSecondOrder_CSTATE[1] =
      ctrl_case_b_P.IntegratorSecondOrder_ICDXDT;
    ctrl_case_b_DW.IntegratorSecondOrder_MODE = 0;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_case_b_M)) {
      ctrl_case_b_X.Integrator_CSTATE = 0.0;
    }

    ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    ctrl_case_b_X.Integrator_CSTATE_b[0] = (ctrl_case_b_P.Integrator_IC[0]);
    ctrl_case_b_X.Integrator_CSTATE_b[1] = (ctrl_case_b_P.Integrator_IC[1]);
    ctrl_case_b_X.Integrator_CSTATE_b[2] = (ctrl_case_b_P.Integrator_IC[2]);

    /* InitializeConditions for Memory: '<S7>/Memory' */
    ctrl_case_b_DW.Memory_PreviousInput_m = ctrl_case_b_P.Memory_X0_m;

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    ctrl_case_b_DW.Memory1_PreviousInput = ctrl_case_b_P.Memory1_X0;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_case_b_M)) {
      rtmSetFirstInitCond(ctrl_case_b_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_case_b_terminate(void)
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
  ctrl_case_b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_case_b_update();
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
  ctrl_case_b_initialize();
}

void MdlTerminate(void)
{
  ctrl_case_b_terminate();
}

/* Registration function */
RT_MODEL_ctrl_case_b_T *ctrl_case_b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_case_b_M, 0,
                sizeof(RT_MODEL_ctrl_case_b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_case_b_M->solverInfo,
                          &ctrl_case_b_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_case_b_M->solverInfo, &rtmGetTPtr(ctrl_case_b_M));
    rtsiSetStepSizePtr(&ctrl_case_b_M->solverInfo,
                       &ctrl_case_b_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_case_b_M->solverInfo, &ctrl_case_b_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_case_b_M->solverInfo, (real_T **)
                         &ctrl_case_b_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_case_b_M->solverInfo,
      &ctrl_case_b_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_case_b_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_case_b_M)));
    rtsiSetRTModelPtr(&ctrl_case_b_M->solverInfo, ctrl_case_b_M);
  }

  rtsiSetSimTimeStep(&ctrl_case_b_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_case_b_M->ModelData.intgData.y = ctrl_case_b_M->ModelData.odeY;
  ctrl_case_b_M->ModelData.intgData.f[0] = ctrl_case_b_M->ModelData.odeF[0];
  ctrl_case_b_M->ModelData.intgData.f[1] = ctrl_case_b_M->ModelData.odeF[1];
  ctrl_case_b_M->ModelData.contStates = ((real_T *) &ctrl_case_b_X);
  rtsiSetSolverData(&ctrl_case_b_M->solverInfo, (void *)
                    &ctrl_case_b_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_case_b_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_case_b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_case_b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_case_b_M->Timing.sampleTimes = (&ctrl_case_b_M->
      Timing.sampleTimesArray[0]);
    ctrl_case_b_M->Timing.offsetTimes = (&ctrl_case_b_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_case_b_M->Timing.sampleTimes[0] = (0.0);
    ctrl_case_b_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    ctrl_case_b_M->Timing.offsetTimes[0] = (0.0);
    ctrl_case_b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_case_b_M, &ctrl_case_b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_case_b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_case_b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_case_b_M, -1);
  ctrl_case_b_M->Timing.stepSize0 = 0.001;
  ctrl_case_b_M->Timing.stepSize1 = 0.001;
  rtmSetFirstInitCond(ctrl_case_b_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_case_b_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_case_b_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_case_b_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_case_b_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_case_b_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_case_b_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_case_b_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_case_b_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_case_b_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_case_b_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_case_b_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_case_b_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_case_b_M->rtwLogInfo, (NULL));
  }

  ctrl_case_b_M->solverInfoPtr = (&ctrl_case_b_M->solverInfo);
  ctrl_case_b_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ctrl_case_b_M->solverInfo, 0.001);
  rtsiSetSolverMode(&ctrl_case_b_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_case_b_M->ModelData.blockIO = ((void *) &ctrl_case_b_B);
  (void) memset(((void *) &ctrl_case_b_B), 0,
                sizeof(B_ctrl_case_b_T));

  /* parameters */
  ctrl_case_b_M->ModelData.defaultParam = ((real_T *)&ctrl_case_b_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_case_b_X;
    ctrl_case_b_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_case_b_X, 0,
                  sizeof(X_ctrl_case_b_T));
  }

  /* states (dwork) */
  ctrl_case_b_M->ModelData.dwork = ((void *) &ctrl_case_b_DW);
  (void) memset((void *)&ctrl_case_b_DW, 0,
                sizeof(DW_ctrl_case_b_T));

  /* Initialize Sizes */
  ctrl_case_b_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_case_b_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_case_b_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_case_b_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_case_b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_case_b_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_case_b_M->Sizes.numBlocks = (102);/* Number of blocks */
  ctrl_case_b_M->Sizes.numBlockIO = (46);/* Number of block outputs */
  ctrl_case_b_M->Sizes.numBlockPrms = (291);/* Sum of parameter "widths" */
  return ctrl_case_b_M;
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
#ifdef NI_ROOTMODEL_ctrl_case_b
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_case_b_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // y_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise_power_p
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.noise_power_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise_power_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.noise_power_psi, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.noise, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // k_0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.k_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_dot_imu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.u_dot_imu, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.L2_continuous, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.PosYRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.PosXRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.R2_continuous, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_case_b_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 17;
}

double ni_extout[25];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_hat,0,0,0);
  } else {
    index += 1;
  }

  // x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,0,18,0);
  } else {
    index += 1;
  }

  // y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,1,18,0);
  } else {
    index += 1;
  }

  // psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,2,18,0);
  } else {
    index += 1;
  }

  // v_newModel: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,1,18,
      0);
  } else {
    index += 1;
  }

  // u_newModel: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,0,18,
      0);
  } else {
    index += 1;
  }

  // r_newModel: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,2,18,
      0);
  } else {
    index += 1;
  }

  // psi_newModel1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator1,2,18,
      0);
  } else {
    index += 1;
  }

  // x_newModel1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator1,0,18,
      0);
  } else {
    index += 1;
  }

  // y_newModel1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_case_b_RGND,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_vsp,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.alpha,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.alpha,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_vsp,0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.omega,0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.omega,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_bt,0,0,0);
  } else {
    index += 1;
  }

  // joystick/Combine: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Gain,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.thrust_out,0,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Gain_n,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.thrust_out,1,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_P.Constant2_Value,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_P.Constant_Value_i,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_case_b_P.Constant1_Value_h,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.reset,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 25;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_hat,0,0,0);

  // x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,0,18,0);

  // y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,1,18,0);

  // psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.eta,2,18,0);

  // v_newModel: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,1,18,0);

  // u_newModel: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,0,18,0);

  // r_newModel: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator,2,18,0);

  // psi_newModel1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator1,2,18,0);

  // x_newModel1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Integrator1,0,18,0);

  // y_newModel1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_case_b_RGND,0,0,0);

  // joystick/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_vsp,0,0,0);

  // joystick/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.alpha,0,0,0);

  // joystick/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.alpha,0,0,0);

  // joystick/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_vsp,0,0,0);

  // joystick/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.omega,0,0,0);

  // joystick/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.omega,0,0,0);

  // joystick/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.u_bt,0,0,0);

  // joystick/Combine: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Gain,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.thrust_out,0,17,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.Gain_n,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.thrust_out,1,17,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_P.Constant2_Value,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_P.Constant_Value_i,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_P.Constant1_Value_h,
    0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_case_b_B.reset,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_case_b/Noise generator/Step size/Value", offsetof(P_ctrl_case_b_T,
    Stepsize_Value), 34, 1, 2, 0, 0 },

  { 1, "ctrl_case_b/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_case_b_T, counter_X0), 34, 1, 2, 2, 0 },

  { 2, "ctrl_case_b/Constant1/Value", offsetof(P_ctrl_case_b_T, Constant1_Value),
    34, 1, 2, 4, 0 },

  { 3,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Mean), 34, 1, 2, 6, 0 },

  { 4,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_case_b_T, WhiteNoise_StdDev), 34, 1, 2, 8, 0 },

  { 5,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Seed), 34, 1, 2, 10, 0 },

  { 6,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Mean_h), 34, 1, 2, 12, 0 },

  { 7,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_case_b_T, WhiteNoise_StdDev_d), 34, 1, 2, 14, 0 },

  { 8,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Seed_b), 34, 1, 2, 16, 0 },

  { 9,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Mean_f), 34, 1, 2, 18, 0 },

  { 10,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_case_b_T, WhiteNoise_StdDev_g), 34, 1, 2, 20, 0 },

  { 11,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_case_b_T, WhiteNoise_Seed_l), 34, 1, 2, 22, 0 },

  { 12, "ctrl_case_b/Constant4/Value", offsetof(P_ctrl_case_b_T, Constant4_Value),
    34, 1, 2, 24, 0 },

  { 13, "ctrl_case_b/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_case_b_T, Hold_X0), 34, 1, 2, 26, 0 },

  { 14, "ctrl_case_b/Memory/X0", offsetof(P_ctrl_case_b_T, Memory_X0), 19, 9, 2,
    28, 0 },

  { 15, "ctrl_case_b/Integrator, Second-Order/ICX", offsetof(P_ctrl_case_b_T,
    IntegratorSecondOrder_ICX), 34, 1, 2, 30, 0 },

  { 16, "ctrl_case_b/Integrator, Second-Order/ICDXDT", offsetof(P_ctrl_case_b_T,
    IntegratorSecondOrder_ICDXDT), 34, 1, 2, 32, 0 },

  { 17, "ctrl_case_b/SurgeObserver /Constant/Value", offsetof(P_ctrl_case_b_T,
    Constant_Value), 34, 1, 2, 34, 0 },

  { 18, "ctrl_case_b/Subsystem/Integrator/InitialCondition", offsetof
    (P_ctrl_case_b_T, Integrator_IC), 23, 3, 2, 36, 0 },

  { 19, "ctrl_case_b/joystick/Gain/Gain", offsetof(P_ctrl_case_b_T, Gain_Gain),
    34, 1, 2, 38, 0 },

  { 20, "ctrl_case_b/joystick/Memory/X0", offsetof(P_ctrl_case_b_T, Memory_X0_m),
    34, 1, 2, 40, 0 },

  { 21, "ctrl_case_b/joystick/Memory1/X0", offsetof(P_ctrl_case_b_T, Memory1_X0),
    34, 1, 2, 42, 0 },

  { 22, "ctrl_case_b/Gain1/Gain", offsetof(P_ctrl_case_b_T, Gain1_Gain), 34, 1,
    2, 44, 0 },

  { 23, "ctrl_case_b/Constant/Value", offsetof(P_ctrl_case_b_T, Constant_Value_p),
    34, 1, 2, 46, 0 },

  { 24, "ctrl_case_b/Gain/Gain", offsetof(P_ctrl_case_b_T, Gain_Gain_a), 34, 1,
    2, 48, 0 },

  { 25,
    "ctrl_case_b/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_case_b_T, Constant2_Value), 34, 1, 2, 50, 0 },

  { 26,
    "ctrl_case_b/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_case_b_T, Constant_Value_i), 34, 1, 2, 52, 0 },

  { 27,
    "ctrl_case_b/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_case_b_T, Constant1_Value_h), 34, 1, 2, 54, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 28;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
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
  3, 3,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  3, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_case_b/y_in", 0, "", offsetof(B_ctrl_case_b_T, y_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_case_b/noise_power_p", 0, "", offsetof(B_ctrl_case_b_T,
    noise_power_p)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_case_b_T, WhiteNoise)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 4, 0 },

  { 3,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_case_b_T, WhiteNoise_e)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 6, 0 },

  { 4, "ctrl_case_b/noise_power_psi", 0, "", offsetof(B_ctrl_case_b_T,
    noise_power_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5,
    "ctrl_case_b/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_case_b_T, WhiteNoise_m)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 10, 0 },

  { 6, "ctrl_case_b/reset", 0, "", offsetof(B_ctrl_case_b_T, reset)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_case_b/Constant4", 0, "", offsetof(B_ctrl_case_b_T, Constant4)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_case_b/Subsystem/Integrator1", 0, "(1,1)", offsetof(B_ctrl_case_b_T,
    Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 16, 0 },

  { 9, "ctrl_case_b/Subsystem/Integrator1", 0, "(1,2)", offsetof(B_ctrl_case_b_T,
    Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 18, 0 },

  { 10, "ctrl_case_b/Subsystem/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_case_b_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 20,
    0 },

  { 11, "ctrl_case_b/Noise generator/Sample & hold/Hold", 0, "(1,1)", offsetof
    (B_ctrl_case_b_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 22, 0 },

  { 12, "ctrl_case_b/Noise generator/Sample & hold/Hold", 0, "(1,2)", offsetof
    (B_ctrl_case_b_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 24, 0 },

  { 13, "ctrl_case_b/Noise generator/Sample & hold/Hold", 0, "(1,3)", offsetof
    (B_ctrl_case_b_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 26, 0 },

  { 14, "ctrl_case_b/noise", 0, "", offsetof(B_ctrl_case_b_T, noise)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "ctrl_case_b/Memory", 0, "(1,1)", offsetof(B_ctrl_case_b_T, Memory)+0*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 30, 0 },

  { 16, "ctrl_case_b/Memory", 0, "(2,1)", offsetof(B_ctrl_case_b_T, Memory)+1*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 32, 0 },

  { 17, "ctrl_case_b/Memory", 0, "(3,1)", offsetof(B_ctrl_case_b_T, Memory)+2*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 34, 0 },

  { 18, "ctrl_case_b/Memory", 0, "(1,2)", offsetof(B_ctrl_case_b_T, Memory)+3*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 36, 0 },

  { 19, "ctrl_case_b/Memory", 0, "(2,2)", offsetof(B_ctrl_case_b_T, Memory)+4*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 38, 0 },

  { 20, "ctrl_case_b/Memory", 0, "(3,2)", offsetof(B_ctrl_case_b_T, Memory)+5*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 40, 0 },

  { 21, "ctrl_case_b/Memory", 0, "(1,3)", offsetof(B_ctrl_case_b_T, Memory)+6*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 42, 0 },

  { 22, "ctrl_case_b/Memory", 0, "(2,3)", offsetof(B_ctrl_case_b_T, Memory)+7*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 44, 0 },

  { 23, "ctrl_case_b/Memory", 0, "(3,3)", offsetof(B_ctrl_case_b_T, Memory)+8*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 46, 0 },

  { 24, "ctrl_case_b/k_0", 0, "", offsetof(B_ctrl_case_b_T, k_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_case_b/SurgeObserver /Constant", 0, "", offsetof(B_ctrl_case_b_T,
    Constant)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0 },

  { 26, "ctrl_case_b/SurgeObserver /Sum4", 0, "u_hat", offsetof(B_ctrl_case_b_T,
    u_hat)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_case_b/psi_in", 0, "", offsetof(B_ctrl_case_b_T, psi_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28, "ctrl_case_b/x_in", 0, "", offsetof(B_ctrl_case_b_T, x_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29, "ctrl_case_b/u_in", 0, "", offsetof(B_ctrl_case_b_T, u_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_case_b/Subsystem/Integrator", 0, "(1,1)", offsetof(B_ctrl_case_b_T,
    Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 60, 0 },

  { 31, "ctrl_case_b/Subsystem/Integrator", 0, "(1,2)", offsetof(B_ctrl_case_b_T,
    Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 62, 0 },

  { 32, "ctrl_case_b/Subsystem/Integrator", 0, "(1,3)", offsetof(B_ctrl_case_b_T,
    Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 64, 0 },

  { 33, "ctrl_case_b/r_in", 0, "", offsetof(B_ctrl_case_b_T, r_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 66, 0 },

  { 34, "ctrl_case_b/v_in", 0, "", offsetof(B_ctrl_case_b_T, v_in)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35, "ctrl_case_b/u_dot_imu", 0, "", offsetof(B_ctrl_case_b_T, u_dot_imu)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 70, 0 },

  { 36, "ctrl_case_b/joystick/L2_continuous", 0, "", offsetof(B_ctrl_case_b_T,
    L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72, 0 },

  { 37, "ctrl_case_b/joystick/PosYRight", 0, "", offsetof(B_ctrl_case_b_T,
    PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74, 0 },

  { 38, "ctrl_case_b/joystick/PosXRight", 0, "", offsetof(B_ctrl_case_b_T,
    PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 76, 0 },

  { 39, "ctrl_case_b/joystick/R2_continuous", 0, "", offsetof(B_ctrl_case_b_T,
    R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 78, 0 },

  { 40, "ctrl_case_b/joystick/Gain", 0, "", offsetof(B_ctrl_case_b_T, Gain)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 80, 0 },

  { 41, "ctrl_case_b/joystick/ArrowUp", 0, "", offsetof(B_ctrl_case_b_T, ArrowUp)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 82, 0 },

  { 42, "ctrl_case_b/joystick/Memory", 0, "", offsetof(B_ctrl_case_b_T, Memory_a)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 84, 0 },

  { 43, "ctrl_case_b/joystick/Memory1", 0, "", offsetof(B_ctrl_case_b_T, Memory1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 86, 0 },

  { 44, "ctrl_case_b/Gain", 0, "", offsetof(B_ctrl_case_b_T, Gain_n)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 88, 0 },

  { 45, "ctrl_case_b/joystick/MATLAB Function", 0, "u_vsp", offsetof
    (B_ctrl_case_b_T, u_vsp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 90, 0 },

  { 46, "ctrl_case_b/joystick/MATLAB Function", 1, "u_bt", offsetof
    (B_ctrl_case_b_T, u_bt)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 92, 0 },

  { 47, "ctrl_case_b/joystick/MATLAB Function", 2, "alpha", offsetof
    (B_ctrl_case_b_T, alpha)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 94, 0 },

  { 48, "ctrl_case_b/joystick/MATLAB Function", 3, "omega", offsetof
    (B_ctrl_case_b_T, omega)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 96, 0 },

  { 49, "ctrl_case_b/joystick/MATLAB Function", 4, "mem_out", offsetof
    (B_ctrl_case_b_T, mem_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 98, 0 },

  { 50, "ctrl_case_b/joystick/MATLAB Function", 5, "hold_out", offsetof
    (B_ctrl_case_b_T, hold_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 100, 0 },

  { 51, "ctrl_case_b/SurgeObserver /Integration block", 0, "y", offsetof
    (B_ctrl_case_b_T, y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 102, 0 },

  { 52, "ctrl_case_b/Subsystem/kinetics", 0, "nu_dot(1,1)", offsetof
    (B_ctrl_case_b_T, nu_dot)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 104, 0 },

  { 53, "ctrl_case_b/Subsystem/kinetics", 0, "nu_dot(1,2)", offsetof
    (B_ctrl_case_b_T, nu_dot)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 106, 0 },

  { 54, "ctrl_case_b/Subsystem/kinetics", 0, "nu_dot(1,3)", offsetof
    (B_ctrl_case_b_T, nu_dot)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 108, 0 },

  { 55, "ctrl_case_b/Subsystem/kinematics", 0, "eta_dot(1,1)", offsetof
    (B_ctrl_case_b_T, eta_dot)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 110, 0 },

  { 56, "ctrl_case_b/Subsystem/kinematics", 0, "eta_dot(1,2)", offsetof
    (B_ctrl_case_b_T, eta_dot)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 112, 0 },

  { 57, "ctrl_case_b/Subsystem/kinematics", 0, "eta_dot(1,3)", offsetof
    (B_ctrl_case_b_T, eta_dot)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 114, 0 },

  { 58, "ctrl_case_b/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_case_b_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 116, 0 },

  { 59, "ctrl_case_b/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_case_b_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 118, 0 },

  { 60, "ctrl_case_b/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_case_b_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 120, 0 },

  { 61, "ctrl_case_b/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_case_b_T, count)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 122, 0 },

  { 62, "ctrl_case_b/MATLAB Function2", 0, "thrust_out(1,1)", offsetof
    (B_ctrl_case_b_T, thrust_out)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 124,
    0 },

  { 63, "ctrl_case_b/MATLAB Function2", 0, "thrust_out(1,2)", offsetof
    (B_ctrl_case_b_T, thrust_out)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 126,
    0 },

  { 64, "ctrl_case_b/MATLAB Function1", 0, "eta(1,1)", offsetof(B_ctrl_case_b_T,
    eta)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 128, 0 },

  { 65, "ctrl_case_b/MATLAB Function1", 0, "eta(1,2)", offsetof(B_ctrl_case_b_T,
    eta)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 130, 0 },

  { 66, "ctrl_case_b/MATLAB Function1", 0, "eta(1,3)", offsetof(B_ctrl_case_b_T,
    eta)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 132, 0 },

  { 67, "ctrl_case_b/MATLAB Function", 0, "dead_x", offsetof(B_ctrl_case_b_T,
    dead_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134, 0 },

  { 68, "ctrl_case_b/MATLAB Function", 3, "newmem(1,1)", offsetof
    (B_ctrl_case_b_T, newmem)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 136, 0 },

  { 69, "ctrl_case_b/MATLAB Function", 3, "newmem(2,1)", offsetof
    (B_ctrl_case_b_T, newmem)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 138, 0 },

  { 70, "ctrl_case_b/MATLAB Function", 3, "newmem(3,1)", offsetof
    (B_ctrl_case_b_T, newmem)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 140, 0 },

  { 71, "ctrl_case_b/MATLAB Function", 3, "newmem(1,2)", offsetof
    (B_ctrl_case_b_T, newmem)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 142, 0 },

  { 72, "ctrl_case_b/MATLAB Function", 3, "newmem(2,2)", offsetof
    (B_ctrl_case_b_T, newmem)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 144, 0 },

  { 73, "ctrl_case_b/MATLAB Function", 3, "newmem(3,2)", offsetof
    (B_ctrl_case_b_T, newmem)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 146, 0 },

  { 74, "ctrl_case_b/MATLAB Function", 3, "newmem(1,3)", offsetof
    (B_ctrl_case_b_T, newmem)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 148, 0 },

  { 75, "ctrl_case_b/MATLAB Function", 3, "newmem(2,3)", offsetof
    (B_ctrl_case_b_T, newmem)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 150, 0 },

  { 76, "ctrl_case_b/MATLAB Function", 3, "newmem(3,3)", offsetof
    (B_ctrl_case_b_T, newmem)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 152, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 77;
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
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 42;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 1, EXT_IN, 1, 1, 1 },

  { 1, "noise_power_p", 0, EXT_IN, 1, 1, 1 },

  { 2, "noise_power_psi", 0, EXT_IN, 1, 1, 1 },

  { 3, "reset", 0, EXT_IN, 1, 1, 1 },

  { 4, "noise", 0, EXT_IN, 1, 1, 1 },

  { 5, "k_0", 0, EXT_IN, 1, 1, 1 },

  { 6, "psi_in", 1, EXT_IN, 1, 1, 1 },

  { 7, "x_in", 1, EXT_IN, 1, 1, 1 },

  { 8, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 9, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 10, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 11, "u_dot_imu", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 15, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 16, "joystick/ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 0, "u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 1, "x", 0, EXT_OUT, 1, 1, 1 },

  { 2, "y", 0, EXT_OUT, 1, 1, 1 },

  { 3, "psi", 0, EXT_OUT, 1, 1, 1 },

  { 4, "v_newModel", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u_newModel", 0, EXT_OUT, 1, 1, 1 },

  { 6, "r_newModel", 0, EXT_OUT, 1, 1, 1 },

  { 7, "psi_newModel1", 0, EXT_OUT, 1, 1, 1 },

  { 8, "x_newModel1", 0, EXT_OUT, 1, 1, 1 },

  { 9, "y_newModel1", 1, EXT_OUT, 1, 1, 1 },

  { 10, "joystick/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 11, "joystick/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 12, "joystick/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 13, "joystick/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 14, "joystick/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 15, "joystick/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 16, "joystick/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 17, "joystick/Combine", 0, EXT_OUT, 1, 1, 1 },

  { 18, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 19, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 20, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 21, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 22, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 23, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 24, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.001, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_case_b";
static char* NI_CompiledModelVersion = "1.278";
static char* NI_CompiledModelDateTime = "Wed Mar 22 12:06:28 2017";
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
   The undef allows us to access the real ctrl_case_b_P
   In the rest of the code ctrl_case_b_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_case_b_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_case_b_P, sizeof(P_ctrl_case_b_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_case_b_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_case_b_T));
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
             (P_ctrl_case_b_T));
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
               (P_ctrl_case_b_T));

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
           (P_ctrl_case_b_T));
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
           (P_ctrl_case_b_T));
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
           (P_ctrl_case_b_T));
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
      *numDiscStates = 639;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE
      [0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE
      [0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE
      [0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "IntegratorSecondOrder_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "IntegratorSecondOrder_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_X.Integrator_CSTATE,
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_X.Integrator_CSTATE_b[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_X.Integrator_CSTATE_b[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_X.Integrator_CSTATE_b[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.noise_power_p_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.noise_power_p_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.NextOutput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.NextOutput_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.noise_power_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.noise_power_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.NextOutput_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.reset_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.noise_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.noise_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.Memory_PreviousInput, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.Memory_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.k_0_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.k_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_in_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.v_newModel_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.v_newModel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.r_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_newModel_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_newModel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.v_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.r_newModel_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.r_newModel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_dot_imu_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_dot_imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.psi_newModel1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.psi_newModel1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_newModel1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_newModel1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_newModel1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_newModel1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.PosYRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.PosXRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.ArrowUp_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.Memory_PreviousInput_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.Memory_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.Memory1_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.alpha_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.alpha_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.omega_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.omega_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_BT_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Combine_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Combine_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.X_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.N_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Y_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_0_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_0_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_0_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.RandSeed_j, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.RandSeed_c, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.IntegratorSecondOrder_MODE, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.IntegratorSecondOrder_MODE");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.noise_power_p_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.noise_power_p_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.noise_power_psi_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.noise_power_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.reset_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.reset_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.noise_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.noise_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.k_0_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.k_0_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.v_newModel_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.v_newModel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.r_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.r_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.u_newModel_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.u_newModel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.v_in_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.v_in_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.r_newModel_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.r_newModel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_dot_imu_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_dot_imu_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.psi_newModel1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.psi_newModel1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.x_newModel1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.x_newModel1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.y_newModel1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.y_newModel1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.L2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.PosYRight_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.PosXRight_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.R2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.ArrowUp_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_VSP1_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.alpha_VSP2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.alpha_VSP1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_VSP2_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.omega_VSP1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.omega_VSP2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.u_BT_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Combine_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Combine_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.X_d_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.X_d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.N_d_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.N_d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.Y_d_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.psi_0_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.x_0_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.x_0_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_case_b_DW.y_0_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_case_b_DW.y_0_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.integratorresetmodel_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK1, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 55; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK3, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_case_b_DW.IntegratorSecondOrder_DWORK1, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_case_b_DW.IntegratorSecondOrder_DWORK1");
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
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.IntegratorSecondOrder_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator_CSTATE, 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator_CSTATE_b[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator_CSTATE_b[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_X.Integrator_CSTATE_b[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_case_b_DW.y_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_power_p_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.NextOutput, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.NextOutput_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_power_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.NextOutput_p, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.Memory_PreviousInput, count,
        discStates[idx++], 20, 0);
    }

    NIRT_SetValueByDataType(&ctrl_case_b_DW.k_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_in_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.x_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.v_newModel_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.r_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_newModel_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.v_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.r_newModel_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_dot_imu_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_newModel1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.x_newModel1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.y_newModel1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.PosYRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.PosXRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.ArrowUp_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Memory_PreviousInput_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.alpha_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.alpha_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.omega_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.omega_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Combine_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.X_d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.N_d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Y_d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.x_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.y_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK2, 0,
      discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.RandSeed, 0, discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.RandSeed_j, 0, discStates[idx++], 7,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.RandSeed_c, 0, discStates[idx++], 7,
      0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Integrator1_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.Integrator_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_case_b_DW.IntegratorSecondOrder_MODE, 0,
      discStates[idx++], 10, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.y_in_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_power_p_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_power_psi_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.reset_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.noise_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.k_0_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.x_in_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_in_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.v_newModel_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.r_in_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_newModel_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.v_in_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.r_newModel_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_dot_imu_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_newModel1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.x_newModel1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.y_newModel1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.PosYRight_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.PosXRight_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.u_BT_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.Combine_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.X_d_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.N_d_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.Y_d_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.psi_0_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.x_0_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.y_0_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.integratorresetmodel_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 55; count++) {
      NIRT_SetValueByDataType(&ctrl_case_b_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 22, 0);
    }

    NIRT_SetValueByDataType(&ctrl_case_b_DW.IntegratorSecondOrder_DWORK1, 0,
      discStates[idx++], 8, 0);
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_case_b
