
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
    mos6581_reset();

/*
    // From C64 example program poking the MOS6581
    u32 sidaddress = MOS6581_REGISTER_BASE;
    for(int addr = 0; addr <= 24; addr++ )
    {
        mos6581_write(sidaddress + addr, 0);
    }
    mos6581_write(sidaddress + 1, 130);
    mos6581_write(sidaddress + 5, 9);
    mos6581_write(sidaddress + 15, 30);
    mos6581_write(sidaddress + 24, 15);
*/  

    timerSet(0, 65536 - 512, TIMER_ENABLE);
    timerSet(1, 1, TIMER_FREQ_262KHZ | TIMER_IRQ_ENABLE | TIMER_ENABLE);

    while (1)
    {
        MODE3_FRAME[ypos][xpos] = RGB5(24, 18, 0);
        svcVBlankIntrWait();
    }
}

void vblank_irq()
{
}

void timer0_irq()
{
    mos6581_run(SID_BUFFER_SIZE, (int8_t*)&sid_buffer);

    dmaSoundFifoATransfer((void*)&sid_buffer[0], DMA_ENABLE);

    xpos = (xpos+1) % 240;
    if(xpos == 0) { ypos = (ypos+1) % 160; }
}


