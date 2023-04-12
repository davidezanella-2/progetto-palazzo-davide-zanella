#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stanza.h"
#include "Palazzo.h"
using namespace std;
int main() {

    srand(time(NULL));

    Stanza s0;
    Stanza s1(10.0,5.0,3.0,2);

    Stanza s2;
    Stanza s3(9.0,12.0,2.7,3);
    Stanza s4(4.7,5.0,2.5,1);

    Stanza st[]={s0,s1,s2,s3,s4};
    Stanza *s;
    s=st;
    Palazzo palazzo(5,s);

    cout << "--------CARATTERISTICHE PALAZZO---------"<<endl;
    cout << "il palazzo contiene "<<palazzo.nstanze() << " stanze e " <<palazzo.npersone()<< " persone" <<endl;
    cout << "il palazzo ha "<<palazzo.superficiepavimenti() << " metri quadrati di superficie di pavimenti" <<endl;
    cout << "il palazzo ha " <<palazzo.superficiepareti()<< " metri quadrati di superficie delle pareti" <<endl;
    cout << "il palazzo ha " <<palazzo.volume()<< " metri cubi di volume" <<endl;

    cout << endl<<"--------CREAZIONE STANZA 5 CON OPERATORE + DEFINITO---------"<<endl;

    cout << "nella stanza 3, persone: " << palazzo.getpersone(3)<< ", lunghezza: "<<palazzo.getlunghezza(3)<<", larghezza: " <<palazzo.getlarghezza(3)<<", altezza "<<palazzo.getaltezza(3)<<endl;
    cout << "nella stanza 4, persone: " << palazzo.getpersone(4)<< ", lunghezza: "<<palazzo.getlunghezza(4)<<", larghezza: " <<palazzo.getlarghezza(4)<<", altezza "<<palazzo.getaltezza(4)<<endl;
    Stanza s5= s3+s4;
    cout << "nella stanza 5, persone: " << s5.getpersone()<< ", lunghezza: "<<s5.getlunghezza()<<", larghezza: " <<s5.getlarghezza()<<", altezza "<<s5.getaltezza()<<endl;
    cout << "dove s5 e' la somma di s3 e s4"<<endl;

    cout <<endl<< "--------SPOSTARE 2 PERSONE DALLA STANZA 3 ALLA STANZA 4---------"<<endl;

    palazzo.sposta(2,3,4);
    cout << "nella stanza 3, persone: " << palazzo.getpersone(3)<< ", lunghezza: "<<palazzo.getlunghezza(3)<<", larghezza: " <<palazzo.getlarghezza(3)<<", altezza "<<palazzo.getaltezza(3)<<endl;
    cout << "nella stanza 4, persone: " << palazzo.getpersone(4)<< ", lunghezza: "<<palazzo.getlunghezza(4)<<", larghezza: " <<palazzo.getlarghezza(4)<<", altezza "<<palazzo.getaltezza(4)<<endl;
    cout <<"nel particolare caso presentato non ci sta piu' di un'altra persona nella stanza 4, allora se ne sposta solo 1"<<endl;

    cout <<endl<< "--------UNIONE STANZA 3 E 4 CON OPERATORE + MA CON METODO IN CLASSE PALAZZO---------"<<endl;

    palazzo.unisci(3,4);
    cout << "nella stanza 3, persone: " << palazzo.getpersone(3)<< ", lunghezza: "<<palazzo.getlunghezza(3)<<", larghezza: " <<palazzo.getlarghezza(3)<<", altezza "<<palazzo.getaltezza(3)<<endl;
    cout << "nella stanza 4, persone: " << palazzo.getpersone(4)<< ", lunghezza: "<<palazzo.getlunghezza(4)<<", larghezza: " <<palazzo.getlarghezza(4)<<", altezza "<<palazzo.getaltezza(4)<<endl;
    cout <<"come si vede al posto della stanza 3 e' comparsa la somma delle 3 e 4, cioe' come la 5 di prima"<<endl;

    cout <<endl<< "--------AGGIUNTA DI UNA STANZA: st5---------"<<endl;
    Stanza st5(4.5,2.9,2.6,1);
    palazzo.add(st5);
    cout << "nella stanza 5, persone: " << palazzo.getpersone(5)<< ", lunghezza: "<<palazzo.getlunghezza(5)<<", larghezza: " <<palazzo.getlarghezza(5)<<", altezza "<<palazzo.getaltezza(5)<<endl;

    cout <<endl<< "--------AGGIUNTA DI PERSONE RANDOM TRA 1 E 5 FINO A MASSIMA CAPIENZA---------"<<endl;
    int a=0;
    do{
        int r=(int)rand()%5+1;
        a=palazzo.entrareposto(r);
        cout<< "nel palazzo sono entrate " << r-a <<" persone"<<endl;
    } while(a==0);
    cout << "------il palazzo e' pieno, speriamo non suoni l'allarme------" << endl;
    cout <<"(ahime') e' suonata l'allarme  antiincendio, persone rimaste nell'edificio: "<< palazzo.allarmeantiincendio()<< endl;


    palazzo.deletememdinamica();
    return 0;
}
