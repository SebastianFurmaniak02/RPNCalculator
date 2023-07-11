#include "kalkulator.h"

//Wszystkie funkcje zwracaja inta 
int dodawanie(int l1, int l2) { //prosta funkcja dodawania
    return l1+l2; //zwraca sume
}

int odejmowanie(int l1, int l2) { //prosta funkcja odejmowania
    return l1-l2;  //zwraca odejmowanie
}

int mnozenie(int l1, int l2) { //prosta funkcja mnozenia
    return l1*l2; //zwraca mnozenie
}

int dzielenie(int l1, int l2) { //funkcja dzielenia
    if (l2 == 0) { //sprawdzenie czy dzielimy przez zero
        printf("BLAD: DZIELENIE PRZEZ 0\n"); //jestli tak wyswietl komunikat
        return l1; //i zwroc licznik
    }
    else return l1/l2; //jesli nie to zwroc dzielenie
}

int potegowanie(int l1, int l2) { //funkcja potegowania
    if (l2>=0) {  //sprawdzenie czy wykladnik wiekszy od zera poniewaz dzialamy na liczbach calkowitych
        l1=(double)l1;
        l2=(double)l2; //zmiana wartosci na duble, chyba niekonieczna ale gdzies wyczytalem ze funkcja pow musi miec zmienne typu double,float.
        return (int)pow(l1,l2); //zwroc wynik bedacy intem
    }
    else { //jesli wykladnik mniejszy od zera 
        printf("BLAD: WART. WYKLADNIKA <0\n"); //komunikat 
        return l1; //i zwroc podstawe 
    }
}

int pierwiastkowanie(int l1) { //funkcja pierwiastkowania 
    if (l1>=0) { //czy podstawa mniejsza od zera
        l1=(double)l1; //analogicznie jak w potegowaniu
        return (int)sqrt(l1); //zwroc wynik bedacy intem
    }
    else { //jesli podstawa mniejsza od zera 
        printf("BLAD: WART. POD PIERW. <0"); //komunikat
        return l1; //zwroc podstawe
    }
}