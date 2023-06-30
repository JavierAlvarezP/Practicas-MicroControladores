#include <16F877A.h>
#fuses XT,NOWDT,PUT,NOWRT,NOPROTECT,BROWNOUT,NOCPD,NODEBUG
#use delay(clock=4000000)
#define use_portd_lcd true
#include <lcd.c>

Int16 TFB;
float AP;
int1 nuevopulso=0;
int1 cambio=0;

#int_ext
void funcion_ext_int() {
if(cambio==0) {
set_timer1(0);
ext_int_edge(0,H_TO_L);
cambio=1;
} else {
TFB=get_timer1();
ext_int_edge(0,L_TO_H);
cambio=0;
if(nuevopulso==0){
nuevopulso=1;
}
}
}

void main() {
lcd_init();
setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
ext_int_edge(0,L_TO_H);
cambio=0;
enable_interrupts(int_ext);
enable_interrupts(global);
do {
if(nuevopulso==1){
AP=TFB*1.0;

printf(lcd_putc,"\nPulso = %6.1fuS ", AP);

}
nuevopulso=0;
}
while (TRUE);
}

