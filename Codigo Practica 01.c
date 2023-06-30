#include <16F877A.H>                                           //primero definimos el pic a usar en nuestro caso es el
#fuses XT,NOWDT,PUT,NOWRT,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT     //en este añadimos fuses a usar
#use delay(clock=4000000)                                      //delcaramos un delay del reloj, lo defini igual que las practicas previas a 4mhz
#include <lcd.c>                                               //añadimos la libreria para la pantalla LCD
#byte TRISB=0x86                                               //declaramos el uso del puerto B donde esta la interrupcion externa
#byte PORTB=0x06

int i=1;                                                       //definimos una variable que usaremos mas adelante
char a[]={"PIC16F877A: USO DE LA INTERRUPCION EXTERNA  PIC16F877A: USO DE LA INTERRUPCION EXTERNA "};   //declaramos una variable "a" de tipo caracter y ponemos el texto que queremos mostrar
#int_ext

ext_isr(){

PORTB=0x04;                                                     //el puerto RB2 queda declarado como salida, que al momento de presionarse el boton energisara este puerto encendiendo el lec y el buzzer

      lcd_init();                                               // esta parte inicia la activacion de la pantalla lcd
      lcd_gotoxy(1,1);                                          //aqui detinimos donde estara el texto en este casi en la linea de arriba comenzando desde la izquierda
      lcd_putc("LA INTERRUPCION EXTERNA");                      //como el texto es muy grande lo ponermos por partes esta iria en la parte de arriba
      lcd_gotoxy(1,2);                                          //aqui activamos la parte de abajo del display
      lcd_putc("HA SIDO ACTIVADA");                             //aqui ponemos la segunda parte del texto
      delay_ms(1000);                                           //con un tiempo de espera de 1 segundo
      PORTB=0x00;                                               
     }
void main(){

   TRISB=0x01;                                                  //definimos el puerto b como entrada 
   PORTB=0;                                                     //ponemos puerto B en ceros
     
enable_interrupts(int_ext);                                    //Habilita la interrupción externa (RB0)
ext_int_edge(L_TO_H);                                          //determina un flanco de subida para la interrupción
enable_interrupts(GLOBAL);                                     //Habilita interrupciones

while (1){
      lcd_init();                                              //aqui iniciamos la pantalla lcd de nuevo
      lcd_gotoxy(i,1);                                         //la posicion de inicio del texto en este caso es  la posicion de izquierda superior
      printf(lcd_putc,"%s",a);                                 //este es el texto que se mostrara en la pantalla, en este caso lo que esta en la variable "a"
     delay_ms(100);                                            //un tiempo de espera de 100ms
      i--;                                                     //indicamos que "i" se mueva una posision en este caso hacia la izquieda, si comienza en 1,1 su siguiente punto es el -1,1
      
     if (i==-42)                                              // hacemos es conteo de caracteres que colocamos, cuentan tambien los espacios entre letras, en este caso son 42 espacios
      {
       i=1;                                                   //aqui le decimos que si termina lo anterior, se regrese a la posision 1 y continue el ciclo
      }
}

        

}

