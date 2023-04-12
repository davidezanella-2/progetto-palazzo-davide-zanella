//
// Created by davide.zanella-2 on 05/04/23.
//

#include "Pavimento.h"



Pavimento::Pavimento(double lunghezza, double larghezza) {
    this->lunghezza=lunghezza;
    this->larghezza=larghezza;
}

double Pavimento::getlunghezza() {
    return lunghezza;
}

double Pavimento::getlarghezza() {
    return larghezza;
}

double Pavimento::perimetro() {
    return lunghezza*larghezza;
}

double Pavimento::area() {
    return lunghezza*2+larghezza*2;
}




