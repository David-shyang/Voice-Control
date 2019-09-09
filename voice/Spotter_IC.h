#ifndef	__SPOTTER_IC_H
#define	__SPOTTER_IC_H

#include "CSpotterSDKApi_Const.h"

// lpbyCYBase(IN): The background model, contents of CYBase.mod.
// lppbyModel(IN): The  null-terminal array of command group.
int Spotter_Init(const void *lpbyCYBase, const void *lppbyModel[]);
int Spotter_Init2(const void *lpbyCYBase, const void *lppbyModel[], const void* lpbyRejModel);
void Spotter_Reset(void);
int Spotter_AddSample(short *lpsSample, int nNumSample);
int Spotter_GetResultId(void);
//command group index of result
int Spotter_GetResultGroupId(void);
void Spotter_Release(void);

int Spotter_VAD_Enable(int isEnabled);
int Spotter_VAD_SetMinEnergyThreshd(int nThreshold); // The default is 500. It is equal to the RMS amplitude and the wave amplitude is more than 4 times of that amount.
const char* Spotter_GetVersion(void); //get version info 

#endif
