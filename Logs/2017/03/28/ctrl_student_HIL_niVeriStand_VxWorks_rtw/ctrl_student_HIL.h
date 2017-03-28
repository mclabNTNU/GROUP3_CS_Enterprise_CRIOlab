/*
 * ctrl_student_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.149
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Mar 28 13:00:49 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_h_
#define RTW_HEADER_ctrl_student_HIL_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_student_HIL_COMMON_INCLUDES_
# define ctrl_student_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_HIL_COMMON_INCLUDES_ */

#include "ctrl_student_HIL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_student_HIL_rtModel       RT_MODEL_ctrl_student_HIL_T

/* Block signals (auto storage) */
typedef struct {
  real_T L2_continuous;                /* '<S7>/L2_continuous' */
  real_T PosXRight;                    /* '<S7>/PosXRight' */
  real_T PosYRight;                    /* '<S7>/PosYRight' */
  real_T R2_continuous;                /* '<S7>/R2_continuous' */
  real_T PosXLeft;                     /* '<S7>/PosXLeft' */
  real_T PosYLeft;                     /* '<S7>/PosYLeft' */
  real_T L1;                           /* '<S7>/L1' */
  real_T R1;                           /* '<S7>/R1' */
  real_T ArrowDown;                    /* '<S7>/ArrowDown' */
  real_T ArrowUp;                      /* '<S7>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S7>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S7>/ArrowRight' */
  real_T y;                            /* '<Root>/y' */
  real_T Memory[3];                    /* '<S2>/Memory' */
  real_T noisepos;                     /* '<S4>/noise pos' */
  real_T WhiteNoise;                   /* '<S20>/White Noise' */
  real_T WhiteNoise_a;                 /* '<S21>/White Noise' */
  real_T noisehead;                    /* '<S4>/noise head' */
  real_T WhiteNoise_f;                 /* '<S19>/White Noise' */
  real_T x;                            /* '<Root>/x' */
  real_T psi;                          /* '<Root>/psi' */
  real_T Hold[3];                      /* '<S15>/Hold' */
  real_T enablenoise;                  /* '<S4>/enable noise' */
  real_T Switch[3];                    /* '<S13>/Switch' */
  real_T drop_out;                     /* '<S2>/drop_out' */
  real_T L1_diag[3];                   /* '<S1>/L1_diag' */
  real_T L2_diag[3];                   /* '<S1>/L2_diag ' */
  real_T L3_diag[3];                   /* '<S1>/L3_diag' */
  real_T case_number;                  /* '<Root>/case_number' */
  real_T use_dp_observer;              /* '<S1>/use_dp_observer' */
  real_T Integrator[3];                /* '<S1>/Integrator' */
  real_T Memory_l[3];                  /* '<Root>/Memory' */
  real_T mu;                           /* '<Root>/mu' */
  real_T rx;                           /* '<Root>/rx' */
  real_T ry;                           /* '<Root>/ry' */
  real_T kp1;                          /* '<Root>/kp1' */
  real_T kp2;                          /* '<Root>/kp2' */
  real_T kp3;                          /* '<Root>/kp3' */
  real_T k2_1;                         /* '<Root>/k2_1' */
  real_T k2_2;                         /* '<Root>/k2_2' */
  real_T k2_3;                         /* '<Root>/k2_3' */
  real_T Integrator1[3];               /* '<S1>/Integrator1' */
  real_T b;                            /* '<S1>/b' */
  real_T demp;                         /* '<S1>/demp' */
  real_T Reset;                        /* '<Root>/Reset' */
  real_T k_0;                          /* '<Root>/k_0' */
  real_T Constant;                     /* '<S5>/Constant' */
  real_T u_hat;                        /* '<S5>/Sum4' */
  real_T u_calb_ctrl;                  /* '<S9>/u_calb_ctrl' */
  real_T Sum;                          /* '<S9>/Sum' */
  real_T alpha_calb_ctrl1;             /* '<S9>/alpha_calb_ctrl1' */
  real_T Sum1;                         /* '<S9>/Sum1' */
  real_T r_gyro;                       /* '<S2>/r_gyro' */
  real_T bias_r_gyro;                  /* '<S2>/bias_r_gyro' */
  real_T Add;                          /* '<S2>/Add' */
  real_T eta_dot_imu;                  /* '<S2>/eta_dot_imu' */
  real_T u_BT;                         /* '<S9>/Limited allocation: VSP only  in surge and BT only in yaw' */
  real_T omega_VSP;                    /* '<S9>/Limited allocation: VSP only  in surge and BT only in yaw' */
  real_T s_dot;                        /* '<Root>/Transfer function' */
  real_T tau[3];                       /* '<Root>/Transfer function' */
  real_T eta_d[3];                     /* '<Root>/Transfer function' */
  real_T taus[3];                      /* '<Root>/Transfer function' */
  real_T dtot_nu[3];                   /* '<Root>/Transfer function' */
  real_T m_alpha_1_dot[3];             /* '<Root>/Transfer function' */
  real_T K_2_z_2[3];                   /* '<Root>/Transfer function' */
  real_T z_1[3];                       /* '<Root>/Transfer function' */
  real_T y_k;                          /* '<S5>/Integration block ' */
  real_T output[3];                    /* '<S15>/MATLAB Function1' */
  real_T count;                        /* '<S14>/MATLAB Function' */
  real_T eta1[3];                      /* '<Root>/MATLAB Function' */
  real_T newmem[3];                    /* '<S2>/MATLAB Function' */
  real_T dead[3];                      /* '<S2>/MATLAB Function' */
  real_T eta_hat_dot[3];               /* '<S1>/Observer ' */
  real_T nu_hat_dot[3];                /* '<S1>/Observer ' */
  real_T b_hat_dot;                    /* '<S1>/Observer ' */
  real_T x_bar;                        /* '<S1>/Observer ' */
  real_T y_bar;                        /* '<S1>/Observer ' */
  real_T psi_bar;                      /* '<S1>/Observer ' */
  boolean_T fault;                     /* '<S26>/control limit checking' */
} B_ctrl_student_HIL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T L2_continuous_DWORK1;         /* '<S7>/L2_continuous' */
  real_T PosXRight_DWORK1;             /* '<S7>/PosXRight' */
  real_T PosYRight_DWORK1;             /* '<S7>/PosYRight' */
  real_T R2_continuous_DWORK1;         /* '<S7>/R2_continuous' */
  real_T PosXLeft_DWORK1;              /* '<S7>/PosXLeft' */
  real_T PosYLeft_DWORK1;              /* '<S7>/PosYLeft' */
  real_T L1_DWORK1;                    /* '<S7>/L1' */
  real_T R1_DWORK1;                    /* '<S7>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S7>/ArrowDown' */
  real_T ArrowUp_DWORK1;               /* '<S7>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S7>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S7>/ArrowRight' */
  real_T Test_DWORK1;                  /* '<Root>/Test' */
  real_T X_d_DWORK1;                   /* '<S8>/X_d' */
  real_T N_d_DWORK1;                   /* '<S8>/N_d' */
  real_T Y_d_DWORK1;                   /* '<S8>/Y_d' */
  real_T osi_0_DWORK1;                 /* '<S8>/osi_0 ' */
  real_T x_0_DWORK1;                   /* '<S8>/x_0' */
  real_T y_0_DWORK1;                   /* '<S8>/y_0' */
  real_T integratorresetmodel_DWORK1;  /* '<S8>/integrator reset model' */
  real_T y_DWORK1;                     /* '<Root>/y' */
  real_T Memory_PreviousInput[3];      /* '<S2>/Memory' */
  real_T counter_PreviousInput;        /* '<S14>/counter' */
  real_T noisepos_DWORK1;              /* '<S4>/noise pos' */
  real_T NextOutput;                   /* '<S20>/White Noise' */
  real_T NextOutput_p;                 /* '<S21>/White Noise' */
  real_T noisehead_DWORK1;             /* '<S4>/noise head' */
  real_T NextOutput_i;                 /* '<S19>/White Noise' */
  real_T x_DWORK1;                     /* '<Root>/x' */
  real_T psi_DWORK1;                   /* '<Root>/psi' */
  real_T Hold_PreviousInput[3];        /* '<S15>/Hold' */
  real_T enablenoise_DWORK1;           /* '<S4>/enable noise' */
  real_T x_m_DWORK1;                   /* '<S4>/x_m' */
  real_T psi_m_DWORK1;                 /* '<S4>/psi_m' */
  real_T y_m_DWORK1;                   /* '<S4>/y_m' */
  real_T drop_out_DWORK1;              /* '<S2>/drop_out' */
  real_T L1_diag_DWORK1[3];            /* '<S1>/L1_diag' */
  real_T L2_diag_DWORK1[3];            /* '<S1>/L2_diag ' */
  real_T L3_diag_DWORK1[3];            /* '<S1>/L3_diag' */
  real_T case_number_DWORK1;           /* '<Root>/case_number' */
  real_T use_dp_observer_DWORK1;       /* '<S1>/use_dp_observer' */
  real_T Memory_PreviousInput_g[3];    /* '<Root>/Memory' */
  real_T mu_DWORK1;                    /* '<Root>/mu' */
  real_T rx_DWORK1;                    /* '<Root>/rx' */
  real_T ry_DWORK1;                    /* '<Root>/ry' */
  real_T kp1_DWORK1;                   /* '<Root>/kp1' */
  real_T kp2_DWORK1;                   /* '<Root>/kp2' */
  real_T kp3_DWORK1;                   /* '<Root>/kp3' */
  real_T k2_1_DWORK1;                  /* '<Root>/k2_1' */
  real_T k2_2_DWORK1;                  /* '<Root>/k2_2' */
  real_T k2_3_DWORK1;                  /* '<Root>/k2_3' */
  real_T b_DWORK1;                     /* '<S1>/b' */
  real_T demp_DWORK1;                  /* '<S1>/demp' */
  real_T psi_bar_DWORK1;               /* '<S1>/psi_bar' */
  real_T psi_hat_DWORK1;               /* '<S1>/psi_hat' */
  real_T r_dot_DWORK1;                 /* '<S1>/r_dot' */
  real_T u_dot_DWORK1;                 /* '<S1>/u_dot' */
  real_T v_dot_DWORK1;                 /* '<S1>/v_dot' */
  real_T x_bar_DWORK1;                 /* '<S1>/x_bar' */
  real_T x_hat_DWORK1;                 /* '<S1>/x_hat' */
  real_T y_bar_DWORK1;                 /* '<S1>/y_bar' */
  real_T y_hat_DWORK1;                 /* '<S1>/y_hat' */
  real_T x_d_DWORK1;                   /* '<Root>/x_d' */
  real_T y_d_DWORK1;                   /* '<Root>/y_d' */
  real_T psi_d_DWORK1;                 /* '<Root>/psi_d' */
  real_T Reset_DWORK1;                 /* '<Root>/Reset' */
  real_T psi_1_DWORK1;                 /* '<Root>/psi_1' */
  real_T x_1_DWORK1;                   /* '<Root>/x_1' */
  real_T k_0_DWORK1;                   /* '<Root>/k_0' */
  real_T y_1_DWORK1;                   /* '<Root>/y_1' */
  real_T tau_psi_DWORK1;               /* '<Root>/tau_psi' */
  real_T tau_x_DWORK1;                 /* '<Root>/tau_x' */
  real_T tau_y_DWORK1;                 /* '<Root>/tau_y' */
  real_T tau_psi1_DWORK1;              /* '<Root>/tau_psi1' */
  real_T tau_x1_DWORK1;                /* '<Root>/tau_x1' */
  real_T tau_y1_DWORK1;                /* '<Root>/tau_y1' */
  real_T dtot_nu_psi_DWORK1;           /* '<Root>/dtot_nu_psi' */
  real_T dtot_nu_x_DWORK1;             /* '<Root>/dtot_nu_x' */
  real_T dtot_nu_y_DWORK1;             /* '<Root>/dtot_nu_y' */
  real_T m_alpha_1_dot_psi_DWORK1;     /* '<Root>/m_alpha_1_dot_psi' */
  real_T m_alpha_1_dot_x_DWORK1;       /* '<Root>/m_alpha_1_dot_x' */
  real_T m_alpha_1_dot_y_DWORK1;       /* '<Root>/m_alpha_1_dot_y' */
  real_T K_2_z_2_psi_DWORK1;           /* '<Root>/K_2_z_2_psi' */
  real_T K_2_z_2_x_DWORK1;             /* '<Root>/K_2_z_2_x' */
  real_T K_2_z_2_y_DWORK1;             /* '<Root>/K_2_z_2_y' */
  real_T z_1_psi_DWORK1;               /* '<Root>/z_1_psi' */
  real_T z_1_x_DWORK1;                 /* '<Root>/z_1_x' */
  real_T u_hat_DWORK1;                 /* '<S5>/u_hat' */
  real_T u_calb_ctrl_DWORK1;           /* '<S9>/u_calb_ctrl' */
  real_T alpha_calb_ctrl1_DWORK1;      /* '<S9>/alpha_calb_ctrl1' */
  real_T controlinputuexceedsbounds_DWOR;/* '<S26>/control input u exceeds bounds' */
  real_T alpha_VSP2_DWORK1;            /* '<S28>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S28>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S28>/omega_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S28>/alpha_VSP1' */
  real_T u_BT_DWORK1;                  /* '<S28>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S28>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S28>/u_VSP2' */
  real_T z_1_y_DWORK1;                 /* '<Root>/z_1_y' */
  real_T r_gyro_DWORK1;                /* '<S2>/r_gyro' */
  real_T bias_r_gyro_DWORK1;           /* '<S2>/bias_r_gyro' */
  real_T eta_dot_imu_DWORK1;           /* '<S2>/eta_dot_imu' */
  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint32_T RandSeed;                   /* '<S20>/White Noise' */
  uint32_T RandSeed_j;                 /* '<S21>/White Noise' */
  uint32_T RandSeed_a;                 /* '<S19>/White Noise' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S5>/Integrator' */

  int_T IntegratorSecondOrder_MODE[3]; /* '<S2>/Integrator, Second-Order' */
  uint8_T L2_continuous_DWORK2[17];    /* '<S7>/L2_continuous' */
  uint8_T PosXRight_DWORK2[17];        /* '<S7>/PosXRight' */
  uint8_T PosYRight_DWORK2[17];        /* '<S7>/PosYRight' */
  uint8_T R2_continuous_DWORK2[17];    /* '<S7>/R2_continuous' */
  uint8_T PosXLeft_DWORK2[17];         /* '<S7>/PosXLeft' */
  uint8_T PosYLeft_DWORK2[17];         /* '<S7>/PosYLeft' */
  uint8_T L1_DWORK2[17];               /* '<S7>/L1' */
  uint8_T R1_DWORK2[17];               /* '<S7>/R1' */
  uint8_T ArrowDown_DWORK2[17];        /* '<S7>/ArrowDown' */
  uint8_T ArrowUp_DWORK2[17];          /* '<S7>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[17];        /* '<S7>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[17];       /* '<S7>/ArrowRight' */
  uint8_T Test_DWORK2[17];             /* '<Root>/Test' */
  uint8_T X_d_DWORK2[17];              /* '<S8>/X_d' */
  uint8_T N_d_DWORK2[17];              /* '<S8>/N_d' */
  uint8_T Y_d_DWORK2[17];              /* '<S8>/Y_d' */
  uint8_T osi_0_DWORK2[17];            /* '<S8>/osi_0 ' */
  uint8_T x_0_DWORK2[17];              /* '<S8>/x_0' */
  uint8_T y_0_DWORK2[17];              /* '<S8>/y_0' */
  uint8_T integratorresetmodel_DWORK2[17];/* '<S8>/integrator reset model' */
  uint8_T y_DWORK2[17];                /* '<Root>/y' */
  uint8_T noisepos_DWORK2[17];         /* '<S4>/noise pos' */
  uint8_T noisehead_DWORK2[17];        /* '<S4>/noise head' */
  uint8_T x_DWORK2[17];                /* '<Root>/x' */
  uint8_T psi_DWORK2[17];              /* '<Root>/psi' */
  uint8_T enablenoise_DWORK2[17];      /* '<S4>/enable noise' */
  uint8_T x_m_DWORK2[17];              /* '<S4>/x_m' */
  uint8_T psi_m_DWORK2[17];            /* '<S4>/psi_m' */
  uint8_T y_m_DWORK2[17];              /* '<S4>/y_m' */
  uint8_T drop_out_DWORK2[17];         /* '<S2>/drop_out' */
  uint8_T L1_diag_DWORK2[17];          /* '<S1>/L1_diag' */
  uint8_T L2_diag_DWORK2[17];          /* '<S1>/L2_diag ' */
  uint8_T L3_diag_DWORK2[17];          /* '<S1>/L3_diag' */
  uint8_T case_number_DWORK2[17];      /* '<Root>/case_number' */
  uint8_T use_dp_observer_DWORK2[17];  /* '<S1>/use_dp_observer' */
  uint8_T mu_DWORK2[17];               /* '<Root>/mu' */
  uint8_T rx_DWORK2[17];               /* '<Root>/rx' */
  uint8_T ry_DWORK2[17];               /* '<Root>/ry' */
  uint8_T kp1_DWORK2[17];              /* '<Root>/kp1' */
  uint8_T kp2_DWORK2[17];              /* '<Root>/kp2' */
  uint8_T kp3_DWORK2[17];              /* '<Root>/kp3' */
  uint8_T k2_1_DWORK2[17];             /* '<Root>/k2_1' */
  uint8_T k2_2_DWORK2[17];             /* '<Root>/k2_2' */
  uint8_T k2_3_DWORK2[17];             /* '<Root>/k2_3' */
  uint8_T b_DWORK2[17];                /* '<S1>/b' */
  uint8_T demp_DWORK2[17];             /* '<S1>/demp' */
  uint8_T psi_bar_DWORK2[17];          /* '<S1>/psi_bar' */
  uint8_T psi_hat_DWORK2[17];          /* '<S1>/psi_hat' */
  uint8_T r_dot_DWORK2[17];            /* '<S1>/r_dot' */
  uint8_T u_dot_DWORK2[17];            /* '<S1>/u_dot' */
  uint8_T v_dot_DWORK2[17];            /* '<S1>/v_dot' */
  uint8_T x_bar_DWORK2[17];            /* '<S1>/x_bar' */
  uint8_T x_hat_DWORK2[17];            /* '<S1>/x_hat' */
  uint8_T y_bar_DWORK2[17];            /* '<S1>/y_bar' */
  uint8_T y_hat_DWORK2[17];            /* '<S1>/y_hat' */
  uint8_T x_d_DWORK2[17];              /* '<Root>/x_d' */
  uint8_T y_d_DWORK2[17];              /* '<Root>/y_d' */
  uint8_T psi_d_DWORK2[17];            /* '<Root>/psi_d' */
  uint8_T Reset_DWORK2[17];            /* '<Root>/Reset' */
  uint8_T psi_1_DWORK2[17];            /* '<Root>/psi_1' */
  uint8_T x_1_DWORK2[17];              /* '<Root>/x_1' */
  uint8_T k_0_DWORK2[17];              /* '<Root>/k_0' */
  uint8_T y_1_DWORK2[17];              /* '<Root>/y_1' */
  uint8_T tau_psi_DWORK2[17];          /* '<Root>/tau_psi' */
  uint8_T tau_x_DWORK2[17];            /* '<Root>/tau_x' */
  uint8_T tau_y_DWORK2[17];            /* '<Root>/tau_y' */
  uint8_T tau_psi1_DWORK2[17];         /* '<Root>/tau_psi1' */
  uint8_T tau_x1_DWORK2[17];           /* '<Root>/tau_x1' */
  uint8_T tau_y1_DWORK2[17];           /* '<Root>/tau_y1' */
  uint8_T dtot_nu_psi_DWORK2[17];      /* '<Root>/dtot_nu_psi' */
  uint8_T dtot_nu_x_DWORK2[17];        /* '<Root>/dtot_nu_x' */
  uint8_T dtot_nu_y_DWORK2[17];        /* '<Root>/dtot_nu_y' */
  uint8_T m_alpha_1_dot_psi_DWORK2[17];/* '<Root>/m_alpha_1_dot_psi' */
  uint8_T m_alpha_1_dot_x_DWORK2[17];  /* '<Root>/m_alpha_1_dot_x' */
  uint8_T m_alpha_1_dot_y_DWORK2[17];  /* '<Root>/m_alpha_1_dot_y' */
  uint8_T K_2_z_2_psi_DWORK2[17];      /* '<Root>/K_2_z_2_psi' */
  uint8_T K_2_z_2_x_DWORK2[17];        /* '<Root>/K_2_z_2_x' */
  uint8_T K_2_z_2_y_DWORK2[17];        /* '<Root>/K_2_z_2_y' */
  uint8_T z_1_psi_DWORK2[17];          /* '<Root>/z_1_psi' */
  uint8_T z_1_x_DWORK2[17];            /* '<Root>/z_1_x' */
  uint8_T u_hat_DWORK2[17];            /* '<S5>/u_hat' */
  uint8_T u_calb_ctrl_DWORK2[17];      /* '<S9>/u_calb_ctrl' */
  uint8_T alpha_calb_ctrl1_DWORK2[17]; /* '<S9>/alpha_calb_ctrl1' */
  uint8_T controlinputuexceedsbounds_DW_j[17];/* '<S26>/control input u exceeds bounds' */
  uint8_T alpha_VSP2_DWORK2[17];       /* '<S28>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[17];       /* '<S28>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[17];       /* '<S28>/omega_VSP2' */
  uint8_T alpha_VSP1_DWORK2[17];       /* '<S28>/alpha_VSP1' */
  uint8_T u_BT_DWORK2[17];             /* '<S28>/u_BT' */
  uint8_T u_VSP1_DWORK2[17];           /* '<S28>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[17];           /* '<S28>/u_VSP2' */
  uint8_T z_1_y_DWORK2[17];            /* '<Root>/z_1_y' */
  uint8_T r_gyro_DWORK2[17];           /* '<S2>/r_gyro' */
  uint8_T bias_r_gyro_DWORK2[17];      /* '<S2>/bias_r_gyro' */
  uint8_T eta_dot_imu_DWORK2[17];      /* '<S2>/eta_dot_imu' */
  uint8_T NIVeriStandSignalProbe_DWORK1[17];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[60];/* '<Root>/NIVeriStandSignalProbe' */
  boolean_T IntegratorSecondOrder_DWORK1;/* '<S2>/Integrator, Second-Order' */
} DW_ctrl_student_HIL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[6];/* '<S2>/Integrator, Second-Order' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_i[3];       /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S1>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S5>/Integrator' */
} X_ctrl_student_HIL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T IntegratorSecondOrder_CSTATE[6];/* '<S2>/Integrator, Second-Order' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_i[3];       /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S1>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S5>/Integrator' */
} XDot_ctrl_student_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T IntegratorSecondOrder_CSTATE[6];/* '<S2>/Integrator, Second-Order' */
  boolean_T Integrator_CSTATE;         /* '<S2>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<Root>/Integrator' */
  boolean_T Integrator_CSTATE_i[3];    /* '<S1>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S1>/Integrator2' */
  boolean_T Integrator_CSTATE_j;       /* '<S5>/Integrator' */
} XDis_ctrl_student_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState IntegratorSecondOrder_Reset_ZCE[3];/* '<S2>/Integrator, Second-Order' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S2>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_j;   /* '<Root>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S5>/Integrator' */
} PrevZCX_ctrl_student_HIL_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_HIL_B
#define BlockIO                        B_ctrl_student_HIL_T
#define rtX                            ctrl_student_HIL_X
#define ContinuousStates               X_ctrl_student_HIL_T
#define rtXdot                         ctrl_student_HIL_XDot
#define StateDerivatives               XDot_ctrl_student_HIL_T
#define tXdis                          ctrl_student_HIL_XDis
#define StateDisabled                  XDis_ctrl_student_HIL_T
#define rtP                            ctrl_student_HIL_P
#define Parameters                     P_ctrl_student_HIL_T
#define rtDWork                        ctrl_student_HIL_DW
#define D_Work                         DW_ctrl_student_HIL_T
#define rtPrevZCSigState               ctrl_student_HIL_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_HIL_T

/* Parameters (auto storage) */
struct P_ctrl_student_HIL_T_ {
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T PosXRight_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosYRight_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T L1_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T R1_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowLeft_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowRight_P1;                /* Expression: width
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T Test_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T Test_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T Test_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T Test_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T Test_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T Test_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/Test'
                                        */
  real_T X_d_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T X_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T X_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T X_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T X_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T X_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/X_d'
                                        */
  real_T N_d_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T N_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T N_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T N_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T N_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T N_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/N_d'
                                        */
  real_T Y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T osi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T osi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T osi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T osi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T osi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T osi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S8>/osi_0 '
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/x_0'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/y_0'
                                        */
  real_T integratorresetmodel_P1;      /* Expression: width
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T integratorresetmodel_P2;      /* Expression: dtype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T integratorresetmodel_P3;      /* Expression: portnum
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T integratorresetmodel_P4;      /* Expression: stime
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T integratorresetmodel_P5;      /* Expression: stype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T integratorresetmodel_P6;      /* Expression: btype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  real_T y_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T Memory_X0[3];                 /* Expression: [0 0 0]'
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Constant4_Value;              /* Expression: 10
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Stepsize_Value;               /* Expression: 0.01
                                        * Referenced by: '<S13>/Step size'
                                        */
  real_T counter_X0;                   /* Expression: 0
                                        * Referenced by: '<S14>/counter'
                                        */
  real_T noisepos_P1;                  /* Expression: width
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T noisepos_P2;                  /* Expression: dtype
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T noisepos_P3;                  /* Expression: portnum
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T noisepos_P4;                  /* Expression: stime
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T noisepos_P5;                  /* Expression: stype
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T noisepos_P6;                  /* Expression: btype
                                        * Referenced by: '<S4>/noise pos'
                                        */
  real_T Gain_Gain;                    /* Expression: 1e-7
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S20>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S20>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S20>/White Noise'
                                        */
  real_T WhiteNoise_Mean_j;            /* Expression: 0
                                        * Referenced by: '<S21>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_j;          /* Computed Parameter: WhiteNoise_StdDev_j
                                        * Referenced by: '<S21>/White Noise'
                                        */
  real_T WhiteNoise_Seed_l;            /* Expression: 123
                                        * Referenced by: '<S21>/White Noise'
                                        */
  real_T noisehead_P1;                 /* Expression: width
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T noisehead_P2;                 /* Expression: dtype
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T noisehead_P3;                 /* Expression: portnum
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T noisehead_P4;                 /* Expression: stime
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T noisehead_P5;                 /* Expression: stype
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T noisehead_P6;                 /* Expression: btype
                                        * Referenced by: '<S4>/noise head'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1e-7
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T WhiteNoise_Mean_b;            /* Expression: 0
                                        * Referenced by: '<S19>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_n;          /* Computed Parameter: WhiteNoise_StdDev_n
                                        * Referenced by: '<S19>/White Noise'
                                        */
  real_T WhiteNoise_Seed_j;            /* Expression: 9025
                                        * Referenced by: '<S19>/White Noise'
                                        */
  real_T x_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T psi_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T Gain_Gain_d[3];               /* Expression: [1/1000 1/1000 pi/180]'
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S15>/Hold'
                                        */
  real_T enablenoise_P1;               /* Expression: width
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T enablenoise_P2;               /* Expression: dtype
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T enablenoise_P3;               /* Expression: portnum
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T enablenoise_P4;               /* Expression: stime
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T enablenoise_P5;               /* Expression: stype
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T enablenoise_P6;               /* Expression: btype
                                        * Referenced by: '<S4>/enable noise'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T drop_out_P1;                  /* Expression: width
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T drop_out_P2;                  /* Expression: dtype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T drop_out_P3;                  /* Expression: portnum
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T drop_out_P4;                  /* Expression: stime
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T drop_out_P5;                  /* Expression: stype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T drop_out_P6;                  /* Expression: btype
                                        * Referenced by: '<S2>/drop_out'
                                        */
  real_T IntegratorSecondOrder_ICX;    /* Expression: 0.0
                                        * Referenced by: '<S2>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT; /* Expression: 0.0
                                        * Referenced by: '<S2>/Integrator, Second-Order'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T L1_diag_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L1_diag_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L1_diag_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L1_diag_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L1_diag_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L1_diag_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/L1_diag'
                                        */
  real_T L2_diag_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L2_diag_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L2_diag_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L2_diag_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L2_diag_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L2_diag_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/L2_diag '
                                        */
  real_T L3_diag_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T L3_diag_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T L3_diag_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T L3_diag_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T L3_diag_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T L3_diag_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/L3_diag'
                                        */
  real_T case_number_P1;               /* Expression: width
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T case_number_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T case_number_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T case_number_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T case_number_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T case_number_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/case_number'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T use_dp_observer_P1;           /* Expression: width
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T use_dp_observer_P2;           /* Expression: dtype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T use_dp_observer_P3;           /* Expression: portnum
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T use_dp_observer_P4;           /* Expression: stime
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T use_dp_observer_P5;           /* Expression: stype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T use_dp_observer_P6;           /* Expression: btype
                                        * Referenced by: '<S1>/use_dp_observer'
                                        */
  real_T Integrator_IC_gv[3];          /* Expression: [0 0 0]'
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Memory_X0_d;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T mu_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T mu_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T mu_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T mu_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T mu_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T mu_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/mu'
                                        */
  real_T rx_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T rx_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T rx_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T rx_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T rx_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T rx_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/rx'
                                        */
  real_T ry_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T ry_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T ry_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T ry_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T ry_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T ry_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/ry'
                                        */
  real_T kp1_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp1_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp1_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp1_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp1_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp1_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T kp2_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp2_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp2_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp2_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp2_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp2_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/kp2'
                                        */
  real_T kp3_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T kp3_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T kp3_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T kp3_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T kp3_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T kp3_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/kp3'
                                        */
  real_T k2_1_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_1_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_1_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_1_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_1_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_1_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/k2_1'
                                        */
  real_T k2_2_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_2_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_2_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_2_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_2_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_2_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/k2_2'
                                        */
  real_T k2_3_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T k2_3_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T k2_3_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T k2_3_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T k2_3_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T k2_3_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/k2_3'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator1_UpperSat[3];      /* Expression: [0.3 0.3 inf]'
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator1_LowerSat[3];      /* Expression: [-0.3 -0.3 -inf]'
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real_T b_P1;                         /* Expression: width
                                        * Referenced by: '<S1>/b'
                                        */
  real_T b_P2;                         /* Expression: dtype
                                        * Referenced by: '<S1>/b'
                                        */
  real_T b_P3;                         /* Expression: portnum
                                        * Referenced by: '<S1>/b'
                                        */
  real_T b_P4;                         /* Expression: stime
                                        * Referenced by: '<S1>/b'
                                        */
  real_T b_P5;                         /* Expression: stype
                                        * Referenced by: '<S1>/b'
                                        */
  real_T b_P6;                         /* Expression: btype
                                        * Referenced by: '<S1>/b'
                                        */
  real_T demp_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T demp_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T demp_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T demp_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T demp_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T demp_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/demp'
                                        */
  real_T psi_bar_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_bar_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_bar_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_bar_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_bar_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_bar_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/psi_bar'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/psi_hat'
                                        */
  real_T r_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T r_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T r_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T r_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T r_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T r_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/r_dot'
                                        */
  real_T u_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T u_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T u_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T u_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T u_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T u_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/u_dot'
                                        */
  real_T v_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T v_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T v_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T v_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T v_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T v_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/v_dot'
                                        */
  real_T x_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/x_bar'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/x_hat'
                                        */
  real_T y_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/y_bar'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/y_hat'
                                        */
  real_T x_d_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T x_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T x_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T x_d_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T x_d_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T x_d_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/x_d'
                                        */
  real_T y_d_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/y_d'
                                        */
  real_T psi_d_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T psi_d_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T psi_d_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T psi_d_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T psi_d_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T psi_d_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/psi_d'
                                        */
  real_T Reset_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Reset_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Reset_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Reset_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T psi_1_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T psi_1_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T psi_1_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T psi_1_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T psi_1_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T psi_1_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/psi_1'
                                        */
  real_T x_1_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T x_1_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T x_1_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T x_1_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T x_1_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T x_1_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/x_1'
                                        */
  real_T k_0_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T k_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T k_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T k_0_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T k_0_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T k_0_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/k_0'
                                        */
  real_T y_1_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T y_1_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T y_1_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T y_1_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T y_1_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T y_1_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/y_1'
                                        */
  real_T tau_psi_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/tau_psi'
                                        */
  real_T tau_x_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_x_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_x_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_x_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/tau_x'
                                        */
  real_T tau_y_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_y_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_y_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_y_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/tau_y'
                                        */
  real_T tau_psi1_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_psi1_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_psi1_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_psi1_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_psi1_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_psi1_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/tau_psi1'
                                        */
  real_T tau_x1_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_x1_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_x1_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_x1_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_x1_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_x1_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/tau_x1'
                                        */
  real_T tau_y1_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T tau_y1_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T tau_y1_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T tau_y1_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T tau_y1_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T tau_y1_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/tau_y1'
                                        */
  real_T dtot_nu_psi_P1;               /* Expression: width
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_psi_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_psi_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_psi_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_psi_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_psi_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/dtot_nu_psi'
                                        */
  real_T dtot_nu_x_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_x_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_x_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_x_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_x_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_x_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/dtot_nu_x'
                                        */
  real_T dtot_nu_y_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T dtot_nu_y_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T dtot_nu_y_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T dtot_nu_y_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T dtot_nu_y_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T dtot_nu_y_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/dtot_nu_y'
                                        */
  real_T m_alpha_1_dot_psi_P1;         /* Expression: width
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_psi_P2;         /* Expression: dtype
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_psi_P3;         /* Expression: portnum
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_psi_P4;         /* Expression: stime
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_psi_P5;         /* Expression: stype
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_psi_P6;         /* Expression: btype
                                        * Referenced by: '<Root>/m_alpha_1_dot_psi'
                                        */
  real_T m_alpha_1_dot_x_P1;           /* Expression: width
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_x_P2;           /* Expression: dtype
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_x_P3;           /* Expression: portnum
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_x_P4;           /* Expression: stime
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_x_P5;           /* Expression: stype
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_x_P6;           /* Expression: btype
                                        * Referenced by: '<Root>/m_alpha_1_dot_x'
                                        */
  real_T m_alpha_1_dot_y_P1;           /* Expression: width
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T m_alpha_1_dot_y_P2;           /* Expression: dtype
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T m_alpha_1_dot_y_P3;           /* Expression: portnum
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T m_alpha_1_dot_y_P4;           /* Expression: stime
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T m_alpha_1_dot_y_P5;           /* Expression: stype
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T m_alpha_1_dot_y_P6;           /* Expression: btype
                                        * Referenced by: '<Root>/m_alpha_1_dot_y'
                                        */
  real_T K_2_z_2_psi_P1;               /* Expression: width
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_psi_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_psi_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_psi_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_psi_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_psi_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/K_2_z_2_psi'
                                        */
  real_T K_2_z_2_x_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_x_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_x_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_x_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_x_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_x_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/K_2_z_2_x'
                                        */
  real_T K_2_z_2_y_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T K_2_z_2_y_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T K_2_z_2_y_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T K_2_z_2_y_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T K_2_z_2_y_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T K_2_z_2_y_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/K_2_z_2_y'
                                        */
  real_T z_1_psi_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/z_1_psi'
                                        */
  real_T z_1_x_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T z_1_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T z_1_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T z_1_x_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T z_1_x_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T z_1_x_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/z_1_x'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/u_hat'
                                        */
  real_T u_calb_ctrl_P1;               /* Expression: width
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T u_calb_ctrl_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T u_calb_ctrl_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T u_calb_ctrl_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T u_calb_ctrl_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T u_calb_ctrl_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/u_calb_ctrl'
                                        */
  real_T alpha_calb_ctrl1_P1;          /* Expression: width
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T alpha_calb_ctrl1_P2;          /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T alpha_calb_ctrl1_P3;          /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T alpha_calb_ctrl1_P4;          /* Expression: stime
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T alpha_calb_ctrl1_P5;          /* Expression: stype
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T alpha_calb_ctrl1_P6;          /* Expression: btype
                                        * Referenced by: '<S9>/alpha_calb_ctrl1'
                                        */
  real_T controlinputuexceedsbounds_P1;/* Expression: width
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P2;/* Expression: dtype
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P3;/* Expression: portnum
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P4;/* Expression: stime
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P5;/* Expression: stype
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P6;/* Expression: btype
                                        * Referenced by: '<S26>/control input u exceeds bounds'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S28>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S28>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S28>/omega_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S28>/alpha_VSP1'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S28>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S28>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S28>/u_VSP2'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T z_1_y_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T z_1_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T z_1_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T z_1_y_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T z_1_y_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T z_1_y_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/z_1_y'
                                        */
  real_T r_gyro_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T r_gyro_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T r_gyro_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T r_gyro_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T r_gyro_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T r_gyro_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/r_gyro'
                                        */
  real_T bias_r_gyro_P1;               /* Expression: width
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T bias_r_gyro_P2;               /* Expression: dtype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T bias_r_gyro_P3;               /* Expression: portnum
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T bias_r_gyro_P4;               /* Expression: stime
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T bias_r_gyro_P5;               /* Expression: stype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T bias_r_gyro_P6;               /* Expression: btype
                                        * Referenced by: '<S2>/bias_r_gyro'
                                        */
  real_T eta_dot_imu_P1;               /* Expression: width
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T eta_dot_imu_P2;               /* Expression: dtype
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T eta_dot_imu_P3;               /* Expression: portnum
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T eta_dot_imu_P4;               /* Expression: stime
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T eta_dot_imu_P5;               /* Expression: stype
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T eta_dot_imu_P6;               /* Expression: btype
                                        * Referenced by: '<S2>/eta_dot_imu'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_HIL_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[18];
    real_T odeF[4][18];
    ODE4_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_student_HIL_T ctrl_student_HIL_P;

/* Block signals (auto storage) */
extern B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
extern DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* External data declarations for dependent source files */
extern const real_T ctrl_student_HIL_RGND;/* real_T ground */

/* Model entry point functions */
extern void ctrl_student_HIL_initialize(void);
extern void ctrl_student_HIL_output(void);
extern void ctrl_student_HIL_update(void);
extern void ctrl_student_HIL_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_HIL_rtModel *ctrl_student_HIL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_student_HIL'
 * '<S1>'   : 'ctrl_student_HIL/DP Observer '
 * '<S2>'   : 'ctrl_student_HIL/Dead reckoning'
 * '<S3>'   : 'ctrl_student_HIL/MATLAB Function'
 * '<S4>'   : 'ctrl_student_HIL/Noise Generator'
 * '<S5>'   : 'ctrl_student_HIL/SurgeObserver '
 * '<S6>'   : 'ctrl_student_HIL/Transfer function'
 * '<S7>'   : 'ctrl_student_HIL/joystick'
 * '<S8>'   : 'ctrl_student_HIL/tau to CSE mocell (only use for HIL testing)'
 * '<S9>'   : 'ctrl_student_HIL/tau to real ship (only use in MCLab)'
 * '<S10>'  : 'ctrl_student_HIL/DP Observer /Observer '
 * '<S11>'  : 'ctrl_student_HIL/Dead reckoning/MATLAB Function'
 * '<S12>'  : 'ctrl_student_HIL/Dead reckoning/MATLAB Function1'
 * '<S13>'  : 'ctrl_student_HIL/Noise Generator/Noise generator'
 * '<S14>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/Downsample	signal'
 * '<S15>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/Sample & hold'
 * '<S16>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/noise generator'
 * '<S17>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/Downsample	signal/MATLAB Function'
 * '<S18>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/Sample & hold/MATLAB Function1'
 * '<S19>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/noise generator/Band-limited white noise psi'
 * '<S20>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/noise generator/Band-limited white noise x'
 * '<S21>'  : 'ctrl_student_HIL/Noise Generator/Noise generator/noise generator/Band-limited white noise y'
 * '<S22>'  : 'ctrl_student_HIL/SurgeObserver /Integration block '
 * '<S23>'  : 'ctrl_student_HIL/SurgeObserver /the rest '
 * '<S24>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Full thrust allocation'
 * '<S25>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw'
 * '<S26>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship'
 * '<S27>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking'
 * '<S28>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/u'
 */
#endif                                 /* RTW_HEADER_ctrl_student_HIL_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_student_HIL_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_HIL_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_student_HIL_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_student_HIL_T* param_lookup[NUMST][2];

#else

extern P_ctrl_student_HIL_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_student_HIL_P             (*param_lookup[tid][READSIDE])
#else
#define ctrl_student_HIL_P             rtParameter[READSIDE]
#endif
#endif
#endif