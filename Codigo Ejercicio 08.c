#include <16F877A.h>
#device adc=10

#FUSES XT,NOWDT
#FUSES
#use delay(clock=4000000)
#include <LCD.C>

void main() {
   int16 q;
   float p;
   
   setup_adc_portS(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   lcd_init();
   
   for (;;) {
       set_adc_channel(0);
       delay_us(20);
       q = read_adc();
       p = 5.0*q/1024.0;
       
       printf(lcd_putc, "\fADC = %4ld", q);
       printf(lcd_putc, "\nVolatage = %01.2fV", p);
       
       delay_ms(100);
   }
}
