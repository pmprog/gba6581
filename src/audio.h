
#pragma once

#include "main.h"

#define REG_SOUND1CNT		REG32(0x04000060)
#define REG_SOUND1CNT_L		REG16(0x04000060)
#define REG_SOUND1CNT_H		REG16(0x04000062)
#define REG_SOUND1CNT_X		REG16(0x04000064)
#define REG_SOUND2CNT_L		REG16(0x04000068)
#define REG_SOUND2CNT_H		REG16(0x0400006C)
#define REG_SOUND3CNT		REG32(0x04000070)
#define REG_SOUND3CNT_L		REG16(0x04000070)
#define REG_SOUND3CNT_H		REG16(0x04000072)
#define REG_SOUND3CNT_X		REG16(0x04000074)
#define REG_SOUND4CNT_L		REG16(0x04000078)
#define REG_SOUND4CNT_H		REG16(0x0400007C)
#define REG_SOUNDCNT		REG32(0x04000080)
#define REG_SOUNDCNT_L		REG16(0x04000080)
#define REG_SOUNDCNT_H		REG16(0x04000082)
#define REG_SOUNDCNT_X		REG16(0x04000084)
#define REG_SOUNDBIAS		REG16(0x04000088)

#define REG_FIFO_A             REG32(0x040000A0)

#define SDS_DMG25			 0	//!< Tone generators at 25% volume
#define SDS_DMG50		0x0001	//!< Tone generators at 50% volume
#define SDS_DMG100		0x0002	//!< Tone generators at 100% volume
#define SDS_A50			 0	//!< Direct Sound A at 50% volume
#define SDS_A100		0x0004	//!< Direct Sound A at 100% volume
#define SDS_B50			 0	//!< Direct Sound B at 50% volume
#define SDS_B100		0x0008	//!< Direct Sound B at 100% volume
#define SDS_AR			0x0100	//!< Enable Direct Sound A on right
#define SDS_AL			0x0200	//!< Enable Direct Sound A on left
#define SDS_ATMR0			 0	//!< Direct Sound A to use timer 0
#define SDS_ATMR1		0x0400	//!< Direct Sound A to use timer 1
#define SDS_ARESET		0x0800	//!< Reset FIFO of Direct Sound A
#define SDS_BR			0x1000	//!< Enable Direct Sound B on right
#define SDS_BL			0x2000	//!< Enable Direct Sound B on left
#define SDS_BTMR0			 0	//!< Direct Sound B to use timer 0
#define SDS_BTMR1		0x4000	//!< Direct Sound B to use timer 1
#define SDS_BRESET		0x8000	//!< Reset FIFO of Direct Sound B
#define SNDSTAT_ENABLE	0x0080	//!< Enable sound. NOTE: enable before using any other sound regs
#define SNDA_VOL_50			SDS_A50
#define SNDA_VOL_100		SDS_A100
#define SNDB_VOL_50			SDS_B50
#define SNDB_VOL_100		SDS_B100
#define SNDA_R_ENABLE		SDS_AR
#define SNDA_L_ENABLE		SDS_AL
#define SNDA_RESET_FIFO		SDS_ARESET
#define SNDB_R_ENABLE		SDS_BR
#define SNDB_L_ENABLE		SDS_BL
#define SNDB_RESET_FIFO		SDS_BRESET

void init_audio();
