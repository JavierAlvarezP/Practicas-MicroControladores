#include <16F877A.h>
#device adc=10
#fuses XT,NOWDT
int16 valor;
#int_ad
void ad_int(){
valor=read_adc();
set_pwm1_duty(valor);
}
void main() {
disable_interrupts(global);

setup_adc_ports(AN0);
setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0);

setup_timer_2(T2_DIV_BY_1,224,1);
setup_ccp1(CCP_PWM);
setup_ccp2(CCP_COMPARE_RESET_TIMER);

setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
set_timer1(0);
ccp_2=1000;
enable_interrupts(INT_AD);
enable_interrupts(global);
do { 
 } while (TRUE);
}
