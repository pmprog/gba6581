
#pragma once

#include <seven/prelude.h>
#include <seven/hw/dma.h>
#include <seven/hw/timer.h>
#include <mos6581.h>

#define SID_BUFFER_SIZE 656

extern struct { u32 irqs; void *fn; } IRQ_TABLE[14];


void vblank_irq();
void timer0_irq();

#define PAL_PHI 985248
#define PLAYBACK_RATE 19973
