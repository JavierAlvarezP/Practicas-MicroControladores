#include <16F877A.h>
#fuses XT,NOWDT
#use delay (clock=4000000)
#include <lcd.c>
#byte PIR1=0X0C

int1 nuevopulso=0;
int16 TFB=0,TFS=0,TF=0;
float AP=0.0;
int1 cambio=0;

#int_ccp1
void ccp1_int() {
   if(cambio==0) {
     TFS=CCP_1;
     setup_ccp1(CCP_CAPTURE_FE);
     cambio=1;
   } else {
   TFB=CCP_1;
     setup_ccp1(CCP_CAPTURE_RE);
     cambio=0;
     
   if(nuevopulso==0) {
    nuevopulso=1;
   }
   }
}

void main() {

lcd_init();
setup_timer_1(T1_INTERNAL);
setup_ccp1(CCP_CAPTURE_RE);
cambio = 0;
enable_interrupts(int_ccp1);
enable_interrupts(global);
  do {
    if(nuevopulso==1)  {
       TF=(TFB-TFS);
       AP = TF*1.0;
      printf(lcd_putc,"\nPulso = %6.1fuS ", AP);
     nuevopulso=0;
    }
  } while(TRUE);
}
