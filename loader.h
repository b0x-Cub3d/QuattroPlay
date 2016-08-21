#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED
#include "stdint.h"
#include "drv/quattro.h"

typedef struct {

    char Name[256]; // short name (filename-legal)
    char Title[1024]; // display title

    uint8_t *Data;
    uint32_t DataSize;
    uint8_t *WaveData;
    uint32_t WaveMask;

    Q_State *QDrv;

    // Global configuration
    int WavLog;
    int VgmLog;
    int AutoPlay;
    int PortaFix;
    int BootSong;
    float BaseGain;

    // Game configuration
    float Gain;
    int MuteRear;
    int ChipFreq; // sound chip frequency, best to not touch this.
    int PitchOverflow; // out of bounds value for pitch table. if -1, use default (C74-C76)

} game_t;

int LoadGame(game_t *Game);
int UnloadGame(game_t *Game);

void InitGame(game_t *Game);
void DeInitGame(game_t *Game);

#endif // LOADER_H_INCLUDED
