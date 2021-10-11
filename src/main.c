
#include "main.h"
#include "audio.h"

int8_t sid_buffer[2 * SID_BUFFER_SIZE + 32];

uint8_t xpos = 0;
uint8_t ypos = 0;

int main(void)
{
    // Setup IRQs
    irqInit(NULL);
    IRQ_TABLE[0].irqs = IRQ_VBLANK;
    IRQ_TABLE[0].fn = vblank_irq;
    IRQ_TABLE[1].irqs = IRQ_TIMER_1;
    IRQ_TABLE[1].fn = timer0_irq;
    irqEnable(IRQ_VBLANK | IRQ_TIMER_1);

    // Configure display in Mode 3 Bitmap
    REG_DISPSTAT = LCD_VBLANK_IRQ_ENABLE;
    REG_DISPCNT  = LCD_MODE_3 | LCD_BG2_ENABLE;

    init_audio();
    //mos6581_reset();

    timerSet(0, 128, TIMER_ENABLE);
    timerSet(1, 1, TIMER_FREQ_64KHZ | TIMER_IRQ_ENABLE | TIMER_ENABLE);

    int sdjcik = 0;
    while (1)
    {
        //mos6581_write(0, xpos);
        MODE3_FRAME[ypos][xpos] = RGB5(0, 31,  0);
        svcVBlankIntrWait();
    }
}

void vblank_irq()
{
}

void timer0_irq()
{
    //mos6581_run(SID_BUFFER_SIZE >> 1, (int8_t*)&sid_buffer);

    REG_DMA2CNT = 0;
    REG_DMA2SRC = &main; // &sid_buffer[0];
    REG_DMA2DST = &REG_FIFO_A;
    REG_DMA2LEN = SID_BUFFER_SIZE;
    REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_INCREMENT | DMA_REPEAT | DMA_32BIT | DMA_START_SOUND | DMA_ENABLE;

    //REG_FIFO_A = 0x64736473;

    xpos = (xpos+1) % 240;
    if(xpos == 0) { ypos = (ypos+1) % 160; }
}


