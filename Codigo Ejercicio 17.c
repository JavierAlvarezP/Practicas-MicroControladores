#include <16f877A.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#USE DELAY (CLOCK=4000000)
#INCLUDE <kbd.C>
#include <lcd.c>
#USE STANDARD_IO (a)
int16 counter=0;

//************** INT TIMER1 **************//
#int_TIMER1
void TIMER1_isr(void) {
counter=get_timer0();
counter=counter*2*120;
printf(lcd_putc,"%6lu rpm",counter);
lcd_gotoxy(1,1);
set_timer0(0);
set_timer1(3036);
}

VOID MAIN()
{
CHAR K,kant='0';
char PWMH=0,PWML=0;
lcd_init();
kbd_init();
PORT_B_PULLUPS(TRUE);

setup_timer_0(rtcc_ext_l_to_h|RTCC_DIV_2);
setup_timer_1(T1_internal|T1_DIV_BY_8);
set_timer0(0);
set_timer1(3036);
enable_interrupts(int_timer1);
enable_interrupts(global);

WHILE (1) {
k=kbd_getc;
if (k=='\0') k=kant;
if ((k=='*') || (k=='#')) k='0';
kant=k;
k=k-48;
PWMH=k*28;
PWML=255-PWMH;
for(PWMH;PWMH>0;PWMH--){
OUTPUT_HIGH(PIN_A0);}
for(PWML;PWML>0;PWML--){
OUTPUT_LOW(PIN_A0);}
}
}
