//
// Created by davide.zanella-2 on 05/04/23.
//

#include "Stanza.h"
#include "Pavimento.h"
#include "algorithm"
#include <iostream>


Stanza::Stanza(double lunghezza, double larghezza,  double altezza, int persone): Pavimento(lunghezza, larghezza)
                                                                                           {

    this->altezza=altezza;
    this->persone=persone;
}

int Stanza::getpersone() {
    return persone;
}

double Stanza::getlunghezza() {
    return lunghezza;
}

double Stanza::getlarghezza() {
    return larghezza;
}

double Stanza::getaltezza() {
    return altezza;
}

double Stanza::areapavimento() {
    return Pavimento::area();
}

double Stanza::areapareti() {
    return 2*altezza*(lunghezza+larghezza);
}

double Stanza::volume() {
    return altezza*lunghezza*larghezza;
}

int Stanza::aggiungi(int n) { //fatto in questo modo un po' laborioso perché l'operatore % non è definito per i double e non vorrei che approssimando vengano fatto errori
    int left=0;
    double volumeresiduo =Stanza::volume()-10.0*(double)persone;

    double arearesidua= Stanza::areapavimento()-8.0*(double)persone;
    for(int i=0;i<n;i++) {
        if (volumeresiduo >= 10.0 && arearesidua >= 8.0) {
            persone++;

            volumeresiduo -= 10.0;
            arearesidua -= 8.0;
        } else {
            left = n - i;
            break;

        }


    }
    return left;
}

int Stanza::togli(int n) {
    int left=0;
    if(n<persone)
        persone-=n;


    else {
        persone=0;
        left=n-persone;
        }


    return left;
}

int Stanza::svuota() {
    persone=0;
    return 0;
}

Stanza Stanza::operator+( Stanza s) {
    double h=std::max(altezza,s.altezza);
    double l=std::max(larghezza,s.larghezza);
    return Stanza(lunghezza+s.lunghezza,l,h,persone+s.persone);
}







