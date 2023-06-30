#INCLUDE <16F877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT
#use standard_io(B)

#int_TIMER2
void TIMER2_isr(void) {
output_TOGGLE(PIN_B0);
set_timer2(11);}

void main() {
setup_timer_2(T2_DIV_BY_4,124,1);
enable_interrupts(INT_TIMER2);
enable_interrupts(global);

while (1);
}
