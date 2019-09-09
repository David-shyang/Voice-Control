#ifndef __CSPOTTERSDK_API_H
#define __CSPOTTERSDK_API_H
#include "base_types.h"
#include "CSpotterSDKApi_Const.h"

#ifdef __cplusplus
extern "C"{
#endif

// Purpose: Create a recognizer
// lpbyCYBase(IN): The background model, contents of CYBase.mod.
// lppbyModel(IN): The command model.
// nMaxTime(IN): The maximum buffer length in number of frames for keeping the status of commands.
// lpbyMemPool(IN/OUT): Memory buffer for the recognizer.
// nMemSize(IN): Size in bytes of the memory buffer lpbyMemPool.
// lpbyState(IN/OUT): State buffer for recognizer.
// nStateSize(IN): Size in bytes of the state buffer lpbyState.
// pnErr(OUT): CSPOTTER_SUCCESS indicates success, else error code. It can be NULL.
// Return: a recognizer handle or NULL
HANDLE CSpotter_Init_Sep(BYTE *lpbyCYBase, BYTE *lpbyModel, INT nMaxTime, BYTE *lpbyMemPool, INT nMemSize, BYTE *lpbyState, INT nStateSize, INT *pnErr);
HANDLE CSpotter_Init_Multi(BYTE *lpbyCYBase, BYTE *lppbyModel[], INT nNumModel, INT nMaxTime, BYTE *lpbyMemPool, INT nMemSize, BYTE *lpbyState, INT nStateSize, INT *pnErr);
HANDLE CSpotter_Init_MultiWithExtRejModel(BYTE *lpbyCYBase, BYTE *lppbyModel[], INT nNumModel, INT nMaxTime, BYTE *lpbyRejModel, BYTE *lpbyMemPool, INT nMemSize, BYTE *lpbyState, INT nStateSize, INT *pnErr);

// Purpose: Destroy a recognizer (free resources)
// hCSpotter(IN): a handle of the recognizer
// Return: Success or error code
INT CSpotter_Release(HANDLE hCSpotter);

// Purpose: Reset recognizer
// hCSpotter(IN): a handle of the recognizer
// Return: Success or error code
INT CSpotter_Reset(HANDLE hCSpotter);

// Purpose: Transfer voice samples to the recognizer for recognizing.
// hCSpotter(IN): a handle of the recognizer
// lpsSample(IN): the pointer of voice data buffer
// nNumSample(IN): the number of voice data (a unit is a short, we prefer to add 160 samples per call)
// Return: "CSPOTTER_ERR_NeedMoreSample" indicates call this function again, else call CSpotter_GetResult(...)
INT CSpotter_AddSample(HANDLE hCSpotter, SHORT *lpsSample, INT nNumSample);

// Purpose: Get recognition results.
// hCSpotter(IN): a handle of the recognizer
// Return: the command ID. It is 0 based
INT CSpotter_GetResult(HANDLE hCSpotter);

INT CSpotter_GetNumWord(BYTE *lpbyModel);

INT CSpotter_GetMemoryUsage_Sep(BYTE *lpbyCYBase, BYTE *lpbyModel, INT nMaxTime);
INT CSpotter_GetMemoryUsage_Multi(BYTE *lpbyCYBase, BYTE *lppbyModel[], INT nNumModel, INT nMaxTime);
INT CSpotter_GetMemoryUsage_MultiWithExtRejModel(BYTE *lpbyCYBase, BYTE *lppbyModel[], INT nNumModel, INT nMaxTime, BYTE *lpbyRejModel);

INT CSpotter_GetStateSize(BYTE *lpbyModel);

/************************************************************************/
//  Threshold Adjust API                                                                   
/************************************************************************/
// Purpose: Set model rejection level
// hCSpotter(IN): a handle of the recognizer
// nRejectionLevel(IN): rejection level
// Return: Success or error code
INT CSpotter_SetRejectionLevel(HANDLE hCSpotter, INT nRejectionLevel);

// Purpose: Set engine response time
// hCSpotter(IN): a handle of the recognizer
// nResponseTime(IN): response time
// Return: Success or error code
INT CSpotter_SetResponseTime(HANDLE hCSpotter, INT nResponseTime);

// Purpose: Set Cmd reward
// hCSpotter(IN): a handle of the recognizer
// nCmdIdx(IN): the command ID. It is 0 based
// nReward(IN): the reward
// Return: Success or error code
INT CSpotter_SetCmdReward(HANDLE hCSpotter, INT nCmdIdx, INT nReward);

// Purpose: Set Cmd response reward
// hCSpotter(IN): a handle of the recognizer
// nCmdIdx(IN): the command ID. It is 0 based
// nReward(IN): the reward
// Return: Success or error code
INT CSpotter_SetCmdResponseReward(HANDLE hCSpotter, INT nCmdIdx, INT nReward);

INT CSpotter_VAD_Enable(HANDLE hCSpotter, INT bEnable);
INT CSpotter_VAD_SetMinEnergyThreshd(HANDLE hCSpotter, INT nThreshold); // The default is 500. It is equal to the RMS amplitude and the wave amplitude is more than 4 times of that amount.

const char* CSpotter_GetVersion();

#ifdef __cplusplus
}
#endif

#endif // __CSPOTTERSDK_API_H
