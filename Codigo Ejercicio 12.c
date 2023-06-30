#include <16F877A.h>
#fuses XT,NOWDT,PUT,NOWRT
#use delay(clock= 4000000)
#use fast_io(B)
int1 cambio=0;
#INT_EXT
ext_isr(){
output_toggle(PIN_B7);
}
void main() {
set_tris_B(0x01);
output_low(PIN_B7);
port_b_pullups(TRUE);
enable_interrupts(int_ext);
ext_int_edge(L_TO_H);
enable_interrupts(GLOBAL);
while (1){
}
}
