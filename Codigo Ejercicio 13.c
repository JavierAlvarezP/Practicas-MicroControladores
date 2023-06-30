#INCLUDE <16F877A.h>
#fuses XT,NOWDT,PUT,NOWRT
#use delay(clock=4000000)
#use standard_io(B)
#int_TIMER0
void TIMER0_isr(void) {
output_toggle(PIN_B0);
set_timer0 (0x1B); }
void main() {
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
set_timer0 (0x1B);
enable_interrupts(INT_TIMER0);
enable_interrupts(global);
while (1);
}
