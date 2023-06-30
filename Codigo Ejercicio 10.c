#include <16F877A.h>
#device adc=10
#FUSES XT,NOWDT
#FUSES
#USE delay(clock=4000000)
#include <math.h>
#include <LCD.C>
#BYTE TRISA = 0X85
#BYTE PORTA = 0x05

void main() {
   int16 q;
   float tv,tr,temp,y,tf,error;                    
   float p,presion,pres_atm,pres_psi,alt;         
                                                 
   int cnt=0;
   bit_set (TRISA , 2);
   setup_adc_ports(RA0_RA1_RA3_ANALOG);         
   setup_adc(ADC_CLOCK_INTERNAL);
   lcd_init();
   
for (;;) {
   set_adc_channel(0);                      
   delay_us(20);
   q = read_adc();
   p = 5.0 * q / 1024.0;
   presion= (0.475+p)/0.45;                    
   
   set_adc_channel(1);                      
   delay_us(20);
   q = read_adc();
   tv = 5.0 * q / 1024.0;
   tr = tv * 10000.0 / (5.0 - tv);
   y = log(tr/20000.0);
   y = (1.0/298.15) + (y *(1.0/4050.0));
   temp=1.0/y;
   temp = temp -273.15;
     if (temp>=0 && temp<=85) TF=1.0;
     else TF=3.0;
   ERROR = TF * 1.5;         
                            
   presion=presion-ERROR;                      
   pres_atm = presion * 0.0098692;            
   pres_psi = presion * 0.1450377;             
   alt = -7990.652789*log(presion/101.304);   
  if (BIT_TEST(PORTA,2)==0) cnt++;    
  if(cnt>=4) cnt=0;
   Switch (cnt) {           
     case 0:
     lcd_gotoxy(1,1);
     printf(lcd_putc, "\P= %5.2f Kpa ", PRESION);
     printf(lcd_putc,"\nT = %04.2f C", temp);
     break;
     case 1:
     lcd_gotoxy(1,1);
     printf(lcd_putc, "\P= %4.2f atm ", PRES_atm);
     printf(lcd_putc,"\nT = %04.2f C", temp);
     break;
     case 2:
     lcd_gotoxy(1,1);
     printf(lcd_putc, "\P= %3.2f psi ", PRES_psi);
     printf(lcd_putc,"\nT = %04.2f C", temp);
     break;
     case 3:
     lcd_gotoxy(1,1);
     printf(lcd_putc, "\Alt= %7.2f m ", alt);
     printf(lcd_putc,"\nT = %04.2f C", temp);
     break;
      }
  delay_ms(100);
    }
}
