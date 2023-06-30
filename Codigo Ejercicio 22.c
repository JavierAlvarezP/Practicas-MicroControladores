#include <16F877A.h>
#device adc=10
#use delay(clock=20000000)
#fuses HS,NOWDT
#include <HDM64GS12.C>
#include <graphics.c>
int16 valor;
float tension;
#int_ad
void ad_int(){
valor=read_adc(ADC_READ_ONLY);
ccp_2=1000;
}

void main() {
  int8 xa=128,ya=0;
  glcd_init(ON);
  disable_interrupts(global);
  setup_adc_ports(AN0);
  setup_adc(ADC_CLOCK_INTERNAL);
  set_adc_channel(0);
  setup_ccp2(CCP_COMPARE_RESET_TIMER);
  
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
  set_timer1(0);
  ccp_2=1000;
  enable_interrupts(INT_AD);
  enable_interrupts(global);
  glcd_fillscreen(0);
  glcd_line(1,64,1,1,1);
  glcd_line(1,31,128,31,1);
  do {
       tension=(valor*5.0)/1024.0;
       ya=1.0+12.6*tension;
       glcd_pixel(xa,ya,1);
       xa--;
           if (xa<2)
           {xa=128;
              glcd_fillscreen(0);
              glcd_line(1,64,1,1,1);
              glcd_line(1,31,128,31,1);
           }
  } while (TRUE);
}
