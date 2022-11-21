#include "mbed.h"

enum estados {apagado, encendido} estado;
 
Timer temporizador;
 
 
DigitalOut led(LED1);
 
void estadoApagado()
{
    if(temporizador.read()>1.0f) {
        temporizador.reset();
        led=1;
        estado=encendido;
    }
}
 
void estadoEncendido()
{
    if(temporizador.read()>0.5f) {
        temporizador.reset();
        led=0;
        estado=apagado;
 
    }
}
 
int main()
{
    led=0;
    estado=apagado;
    temporizador.reset();
    temporizador.start();
    while(1) {
        switch(estado) {
            case apagado:
                estadoApagado();
                break;
            case encendido:
                estadoEncendido();
                break;
        }
 
    }
}