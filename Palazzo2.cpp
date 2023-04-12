//
// Created by Davide on 07/04/2023.
//
#include <iostream>
#include "Stanza.h"
#include "Palazzo2.h"
#include "vector"


Palazzo2::Palazzo2( int dimensione, Stanza *stanze) {


    for(int i=0;i<dimensione;i++){
        st.push_back(stanze[i]);
    }

}

Palazzo2::Palazzo2( std::vector <Stanza> st) {


    for(int i=0;i<st.size();i++){
        this->st=st;
    }

}

int Palazzo2::nstanze() {

    return st.size();
}

double Palazzo2::superficiepavimenti()  {
    double tot=0;
    for(int i=0;i<st.size();i++){
        tot+=st[i].areapavimento();
    }
    return tot;
}

double Palazzo2::superficiepareti() {
    double tot=0;
    for(int i=0;i<st.size();i++){
        tot+=st[i].areapareti();
    }
    return tot;
}

double Palazzo2::volume() {
    double tot=0;
    for(int i=0;i<st.size();i++){
        tot+=st[i].volume();
    }
    return tot;
}

int Palazzo2::npersone()  {
    int tot=0;
    for(int i=0;i<st.size();i++){
        tot+=st[i].getpersone();
    }
    return tot;
}

int Palazzo2::add(double lunghezza, double larghezza, double altezza) {
    st.push_back(Stanza(lunghezza,larghezza,altezza,0));
    return st.size();
}

int Palazzo2::add(Stanza s) {
    st.push_back(s);
    return st.size();
}

int Palazzo2::entrareposto(int n) {
    bool postoresiduo=true;
    if(st.size()<1)
        postoresiduo=false;

    int i=0;

    while(n>0 && postoresiduo==true){
        n=st[i].aggiungi(n);
        i++;
        if(i==st.size())
            postoresiduo=false;
    }

    return n;
}

int Palazzo2::sposta(int n, int index1, int index2) {
    int toglibili=st[index1].getpersone(), //persone che posso togliere
    aggiunte=n-st[index2].aggiungi(n),   //persone che posso aggiungere (e sono immediatamente aggiunte)
    left=0;

    if(toglibili>=aggiunte) {
        st[index1].togli(aggiunte);
        left=n-aggiunte;
    }
    else{
        st[index1].togli(toglibili);
        st[index2].togli(n-toglibili);
        left=n-toglibili;
    }


    return left;
}

int Palazzo2::allarmeantiincendio() {
    for(int i=0;i<st.size();i++){
        st[i].togli(st[i].getpersone());
    }
    return 0;
}

int Palazzo2::getpersone(int index) {

    return st[index].getpersone();
}

double Palazzo2::getlarghezza(int index) {
    return st[index].getlarghezza();
}

double Palazzo2::getaltezza(int index) {
    return st[index].getaltezza();
}

double Palazzo2::getlunghezza(int index) {
    return st[index].getlunghezza();
}

int Palazzo2::unisci(int index1, int index2) {
    st[index1]=st[index1]+st[index2];
    return 0;
}