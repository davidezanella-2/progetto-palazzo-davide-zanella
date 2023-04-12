//
// Created by davide.zanella-2 on 05/04/23.
//
#include <iostream>

#include "Palazzo.h"
#include "Stanza.h"
using namespace std;
Palazzo::Palazzo( int dimensione, Stanza *s) {

    this->dimensione=dimensione;
    stanze=new Stanza[dimensione];
    for(int i=0;i<dimensione;i++){

        stanze[i]=s[i];
    }
}

int Palazzo::nstanze() {

    return dimensione;
}

double Palazzo::superficiepavimenti()  {
    double tot=0;
    for(int i=0;i<dimensione;i++){
        tot+=stanze[i].areapavimento();
    }
    return tot;
}

double Palazzo::superficiepareti() {
    double tot=0;
    for(int i=0;i<dimensione;i++){
        tot+=stanze[i].areapareti();
    }
    return tot;
}

double Palazzo::volume() {
    double tot=0;
    for(int i=0;i<dimensione;i++){
        tot+=stanze[i].volume();
    }
    return tot;
}

int Palazzo::npersone() {
    int tot=0;
    for(int i=0;i<dimensione;i++){
        tot+=stanze[i].getpersone();
    }
    return tot;
}

int Palazzo::add(double lunghezza, double larghezza, double altezza) {

    Stanza *st;
    st=new Stanza[dimensione+1];
    st[dimensione]=Stanza(lunghezza,larghezza,altezza,0);
    for(int i=0;i<dimensione;i++){
        st[i]=stanze[i];
    }
    deletememdinamica();
    dimensione++;
    stanze=st;
    return dimensione;
}

int Palazzo::add(Stanza s) {
    Stanza *st;
    st=new Stanza[dimensione+1];
    st[dimensione]=s;
    for(int i=0;i<dimensione;i++){
        st[i]=stanze[i];
    }
    deletememdinamica();
    dimensione++;
    stanze=st;          //stanze va a puntare dove punta st, poi st muore qua, stanze no
    return dimensione;
}

int Palazzo::entrareposto(int n) {
    bool postoresiduo=true;
    if(dimensione<1)
        postoresiduo=false;

    int i=0;
    while(n>0 && postoresiduo==true){
        n=stanze[i].aggiungi(n);
        i++;
        if(i==dimensione)
            postoresiduo=false;
    }

    return n;
}

int Palazzo::sposta(int n, int index1, int index2) {
    int toglibili=stanze[index1].getpersone(), //persone che posso togliere
        aggiunte=n-stanze[index2].aggiungi(n),   //persone che posso aggiungere (e sono immediatamente aggiunte)
        left=0;


    if(toglibili>=aggiunte) {
        stanze[index1].togli(aggiunte);
        left=n-aggiunte;
    }
    else{
        stanze[index1].togli(toglibili);
        stanze[index2].togli(n-toglibili);
        left=n-toglibili;
    }


    return left;
}

int Palazzo::allarmeantiincendio() {
    for(int i=0;i<dimensione;i++){
        stanze[i].togli(stanze[i].getpersone());
    }
    return 0;
}

int Palazzo::deletememdinamica() {
    delete[]stanze;
    return 0;
}

int Palazzo::getpersone(int index) {

    return stanze[index].getpersone();
}

double Palazzo::getlarghezza(int index) {
    return stanze[index].getlarghezza();
}

double Palazzo::getaltezza(int index) {
    return stanze[index].getaltezza();
}

double Palazzo::getlunghezza(int index) {
    return stanze[index].getlunghezza();
}

int Palazzo::unisci(int index1, int index2) {
    stanze[index1]=stanze[index1]+stanze[index2];
    return 0;
}



