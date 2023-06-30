#include <16F877A.h>
#fuses XT,NOWDT,PUT,NOWRT
#use delay(clock=4000000)
#use standard_io(B)

int1 cont=0;

#int_TIMER1
void templs(void)
{
if (cont==1) output_toggle(PIN_B1);
set_timer1 (3036);
cont++;
}

void main()
{
setup_timer_1 (T1_INTERNAL | T1_DIV_BY_8);
set_timer1 (3036);
enable_interrupts(INT_TIMER1);
enable_interrupts(global);

while(1);
}

