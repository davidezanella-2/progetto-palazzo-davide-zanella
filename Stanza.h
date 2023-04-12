//
// Created by davide.zanella-2 on 05/04/23.
//

#ifndef UNTITLED1_STANZA_H
#define UNTITLED1_STANZA_H

#include "Pavimento.h"


class Stanza: public Pavimento{
protected:
    double altezza;
    int persone;
public:
    Stanza(double lunghezza=4.0, double larghezza=3.0, double altezza=2.7, int persone=0);
    int getpersone();           //restituisce il numero di persone nella stanza
    double getlunghezza();      //restituisce la lunghezza della stanza
    double getlarghezza();      //restituisce la larghezza della stanza
    double getaltezza();        //restituisce l'altezza della stanza
    double areapavimento();     //restituisce l'area del pavimento della stanza
    double areapareti();        //restituisce l'area delle pareti della stanza
    double volume();            //restituisce il volume della stanza
    int aggiungi(int n=1);        //aggiunge tutte le persone che ci stanno (spazio vitale minimo di 10m^3 e 8m^2 a persona) fino ad un massimo delle n richieste, ritorna il numero di persone che non sono potute entrare;
    int togli(int n=1);           //toglie le persone presenti fino ad un massimo di n; ritorna 0 se vengono tolte n persone, altrimenti n-persone
    int svuota();               //svuota la stanza da tutte le persone che sono presenti in essa
    Stanza operator+(Stanza s); //definizione operatore + tra due stanze, il risultato è una nuova stanza con lunghezza la somma della lunghezze e larghezza e altezza quelle masime
};
#endif //UNTITLED1_STANZA_H
