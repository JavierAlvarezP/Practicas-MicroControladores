#include <16F877A.h>
#fuses XT,NOWDT
#use delay(clock=4000000)
int16 i;
void main() {
   setup_timer_2(T2_DIV_BY_1,224,1);
   setup_ccp1(CCP_PWM);
for (i=0;i<1024;i++) {
   set_pwm1_duty(i);
   delay_ms(25);
   }
}
