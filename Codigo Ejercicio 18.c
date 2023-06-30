#INCLUDE <16F877A.h>
#device adc=10
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOPROTECT,NOBROWNOUT,NOLVP,NOCPD,NOWRT,NODEBUG
#USE FAST_IO (B)

#BYTE TRISA =0x85
#BYTE PORTA =0x05
#BYTE TRISC =0x87
#BYTE PORTC =0x07
#BYTE TRISD =0x88
#BYTE PORTD =0x08
#BYTE TIMER0 =0x01
#BIT RA5 = 0x05.5
#BIT RC2 = 0x07.2

CHAR D6,FUNCION_D6,CON_D6;
INT1 CNT;

//*****************INTERRUPCION TIMER0******************
#int_TIMER0
void TIMER0_isr(void) {
   IF (INPUT(PIN_d6)==0) {
      IF (D6 >= 150) {
          IF (CON_D6==0) { 
              D6=0;
              FUNCION_D6=1;}
         ELSE {
             D6=0;
             FUNCION_D6=3;
             CON_D6=0; }
      }
     ELSE D6++;
   }
     ELSE {
     if (D6>0 && funcion_D6 ==1) D6=0;
     IF (D6 > 0 && FUNCION_D6 !=1 && FUNCION_D6 !=3 )
            {FUNCION_D6=2;
            D6=0;}

}
SET_TIMER0 (100);
}

//************************PRINCIPAL*****************
void main(){
      disable_interrupts (GLOBAL);
      setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);
      D6=0; FUNCION_D6=0; CON_D6=0;
      TRISA = 0X00;
      TRISC = 0X00;
      TRISD = 0X40;
      BIT_CLEAR(PORTA,5);
      BIT_CLEAR(PORTC,2);
      enable_interrupts (GLOBAL);
      SET_TIMER0 (100);
      enable_interrupts (INT_TIMER0);
      
  WHILE (1){
      IF (FUNCION_D6==1) RC2=1;
      IF (FUNCION_D6==3) {
            RC2=0;
            DELAY_MS(400);
            FUNCION_D6=0; }
      IF (FUNCION_D6==2) {
        CNT++;
        IF (CNT==0) RA5=1;
        ELSE RA5=0;
        FUNCION_D6=0;
      }
   }
}
      
