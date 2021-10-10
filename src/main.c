#include <seven/prelude.h>
#include <mos6581.h>

#define SID_BUFFER_SIZE 656
int8_t sid_buffer[2 * SID_BUFFER_SIZE + 32];

extern struct { u32 irqs; void *fn; } IRQ_TABLE[14];

void vblank_irq();
void timer0_irq();

uint8_t xpos = 0;
uint8_t ypos = 0;

int main(void)
{
    irqInit(NULL);

    IRQ_TABLE[0].irqs = IRQ_VBLANK;
    IRQ_TABLE[0].fn = vblank_irq;
    IRQ_TABLE[1].irqs = IRQ_TIMER_0;
    IRQ_TABLE[1].fn = timer0_irq;


    irqEnable(IRQ_VBLANK);
    irqEnable(IRQ_TIMER_0);

    REG_DISPSTAT = LCD_ENABLE_VBLANK_IRQ;
    REG_DISPCNT  = LCD_MODE_3 | LCD_ENABLE_BG2;

    
    MODE3_FRAME[80][136] = RGB5( 0, 31,  0);
    MODE3_FRAME[96][120] = RGB5( 0,  0, 31);

    while (1)
    {
        MODE3_FRAME[ypos][xpos] = RGB5(0, 31,  0);
        svcVBlankIntrWait();
    }
}

void vblank_irq()
{
    xpos = (xpos+1) % 240;
    if(xpos == 0) { ypos = (ypos+1) % 160; }
}

void timer0_irq()
{

}
