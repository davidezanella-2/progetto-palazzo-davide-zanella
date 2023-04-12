//
// Created by davide.zanella-2 on 05/04/23.
//

#ifndef UNTITLED1_PAVIMENTO_H
#define UNTITLED1_PAVIMENTO_H

class Pavimento {
protected:
    double lunghezza;
    double larghezza;

public:
    Pavimento (double lunghezza=4.0, double larghezza=3.0);
    double getlunghezza(); //restituisce la lunghezza del pavimento
    double getlarghezza(); //restituisce la larghezza del pavimento
    double area();         //restituisce l'area del pavimento
    double perimetro();    //restituisce il perimetro del pavimento

};

#endif //UNTITLED1_PAVIMENTO_H
