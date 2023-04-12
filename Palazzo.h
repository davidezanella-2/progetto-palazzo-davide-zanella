//
// Created by davide.zanella-2 on 05/04/23.
//

#ifndef UNTITLED1_PALAZZO_H
#define UNTITLED1_PALAZZO_H
#include "Stanza.h"

class Palazzo{
private:
    int dimensione;
    Stanza *stanze;

public:
    Palazzo(int dimensione, Stanza *stanze);
    int nstanze();                              //restituisce il numero di stanze nel palazzo
    double superficiepavimenti();               //calcola la superficie totale dei pavimenti nel palazzo
    double superficiepareti();                  //calcola la superficie totale delle pareti nel palazzo
    double volume();                            //calcola il volume totale del palazzo
    int npersone();                             //calcola le persone totali nel palazzo
    int getpersone(int index);                  //ritorna il numero di persone nella stanza all'idice index
    double getlunghezza(int index);                //ritorna la lunghezza della stanza all'idice index
    double getlarghezza(int index);                //ritorna la larghezza della stanza all'idice index
    double getaltezza(int index);                  //ritorna l'altezza della stanza all'idice index
    int add(Stanza s);                          //viene aggiunta la Stanza s al palazzo, qui con ingresso una stanza, sotto con ingresso le variabili di una stanza
    int add(double lunghezza=4.0, double larghezza=3.0, double altezza=2.7); //quando creo una stanza le peronse dentro saranno 0
    int entrareposto(int n=1);                    //metodo per vedere se possono entrare tot persone; ritorna il numero di persone non entrato, se 0 sono entrate tutte
    int sposta(int n, int index1, int index2);  //sposta fino ad un massimo di persone dalla stanza in indice 1 a quella in indice 2, se non si posono spostare n persone, verrà ritornato il valore di persone non spostate
    int allarmeantiincendio();                  //svuota il palazzo
    int deletememdinamica();                    //elimina il vettore dinamico contenente le stanze
    int unisci(int index1, int index2);         //usa l'operatore + per unire due stanze dentro un palazzo, la stanza unita si troverà all'index1, all'index2 resterà l'altra anche per non andare a rompere l'ordine di quelle già presenti
};


#endif //UNTITLED1_PALAZZO_H
