#include "mbed.h"

enum estados { esperando_pulsar, pulsado, esperando_soltar } estado;

Timer temporizador;

DigitalIn boton(BUTTON1); //BUTTON1 PORQUE ES DE LA PLACA

DigitalOut led(LED1);

void estado_esperando_pulsar() {
  if (boton==0) {
    temporizador.reset();
    temporizador.start();
    led = 1;
    estado = pulsado;
  }
}

void estado_pulsado() {
  if (boton ==0 && temporizador.read() > 2.0f) {
    led = 0;
    estado = esperando_soltar;
  }

 if (boton ==1 && temporizador.read() > 2.0f) {
    led = 0;
    estado = esperando_pulsar;
  }

}

void estado_esperando_soltar() {
  if (boton == 1) {
    estado = esperando_pulsar;
  }
}

int main() {
  led = 0;
  estado = esperando_pulsar;
  temporizador.reset();
  temporizador.start();
  while (1) {
    switch (estado) {
    case esperando_pulsar:
      estado_esperando_pulsar();
      break;
    case pulsado:
      estado_pulsado();
      break;
    case esperando_soltar:
      estado_esperando_soltar();
      break;
    }
  }
}