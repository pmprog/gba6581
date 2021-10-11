
#include "audio.h"


void init_audio()
{
   	REG_SOUNDCNT_H = SNDA_VOL_100 | SNDA_R_ENABLE | SNDA_L_ENABLE | SNDA_RESET_FIFO;
	REG_SOUNDCNT_X = SNDSTAT_ENABLE;
}

// For MOS6581 code
uint32_t __attribute__ ((section (".iwram"))) calc_step_scaled(uint32_t step)
{
	uint64_t temp64 = step;
	temp64 *= PAL_PHI << 8;
	return temp64 / PLAYBACK_RATE;
}

