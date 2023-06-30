#include "16f877A.h"
#device adc=10
#fuses XT,NOWDT
#use delay (clock=4000000)
#include <math.h>
#include <lcd.c>

void main() {
float tv,tr,temp,y;
int16 value;
lcd_init();
setup_port_a( ALL_ANALOG );
setup_adc( ADC_CLOCK_INTERNAL );
set_adc_channel( 0 );
delay_us(10);
do {
value = Read_ADC();
tv = 5.0 * value / 1024.0;
tr = tv * 10000.0 / (5.0 - tv);
y = log(tr/20000.0);
y = (1.0/298.15) + (y *(1.0/4050.0));
temp=1.0/y;
temp = temp -273.15;
printf(lcd_putc,"\nT = %04.2fC", temp);
} while (TRUE);
}
