#include <16f877A.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,BROWNOUT,NOCPD,NOWRT,NODEBUG
#USE DELAY (CLOCK=4000000)
#DEFINE use_portb_kbd true
#INCLUDE <kbd.c>
#USE STANDARD_IO (a)

VOID MAIN ()
{
  CHAR k,kant='0';
  char  PWMH=0,PWML=0;
  kbd_init();
  PORT_B_PULLUPS(TRUE);

 WHILE (1) {
  k=kbd_getc();
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
