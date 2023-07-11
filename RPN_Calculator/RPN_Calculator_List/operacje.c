#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "struktury.h"

t_elem *inicjuj_liste() { return NULL; } //inicjowanie pustej listy

t_elem *dodaj(t_elem *pierwszy, int arg) { //dodawanie elementu
    t_elem *nowy=(t_elem *)malloc(sizeof(t_elem));
    nowy->liczba = arg;
    nowy->nastepny = pierwszy;
    return nowy; //zwracanie nowego
}

t_elem *usun(t_elem *pierwszy) { //usuwanie elementu
    t_elem *drugi;
    drugi = pierwszy->nastepny;
    free(pierwszy);
    return drugi; //zwracanie starszego
}

t_stos *inicjuj_stos() { return NULL; } //inicjacja pustego stosu

t_stos *inicjuj(t_stos *stos) { //inicjacja stosu 
    stos=inicjuj_stos();
    stos=(t_stos *)malloc(sizeof(t_stos));
    stos->PoczListy=inicjuj_liste();
    return stos;
}

int isempty(t_stos *stos) { //funkcja sprawdzajaca czy stos jest pusty
    if (stos->PoczListy==NULL) return 0;
    else return 1;
}

int is_too_empty(t_stos *stos) { //funkcja sprawdzajaca czy na stosie sa minimum 2 elementy
    if (stos->PoczListy != NULL && stos->PoczListy->nastepny != NULL) return 1;
    else return 0; 
} //Te dwie ostatnie funkcje sa przydatne w celu sprawdzania do innych funkcji

void push(t_stos *stos, int arg) { //funkcja push, dodajaca element na stos
    stos->PoczListy=dodaj(stos->PoczListy,arg);
}

void pop(t_stos *stos, int *arg) { //funkcja pop, usuwajaca element i zwracajaca jego wartosc
    if (isempty(stos)) {
        *arg=stos->PoczListy->liczba;
        stos->PoczListy=usun(stos->PoczListy);
	}
}

void fullprint(t_stos *stos) { //funkcja fullprint, wyswietlajaca caly stos
    if (isempty(stos)) {
        t_elem *pom=stos->PoczListy;
            do {
            printf("%d", pom->liczba);
            printf("\n");
            pom = pom->nastepny;
            } while (pom != NULL);
    }
}

void print(t_stos *stos) { //funkcja print, wyswietlajaca pierwszy element
    if (isempty(stos)) {
        printf("%d\n",stos->PoczListy->liczba);
    }
}

void clear(t_stos *stos) { //funkcja clear, usuwajaca wszystkie wartosci ze stosu
    int arg;
    if (isempty(stos)) {
        do {
            pop(stos, &arg);
        } while (stos->PoczListy != NULL);
    }
}

void duplicate(t_stos *stos) { //funkcja duplicate, dodajaca na stos kopie pierwszego elementu
    if (isempty(stos)) {
        push(stos,stos->PoczListy->liczba);
    }
}

void reverse(t_stos *stos) { //funkcja reverse, zamieniajaca miejscami dwa pierwsze argumenty na stosie
    int arg1,arg2;
    if (is_too_empty(stos)) {
        pop(stos,&arg1);
        pop(stos,&arg2);
        push(stos,arg1);
        push(stos,arg2);
    }
}