#ifndef OPERACJE_H
#define OPERACJE_H

#include "struktury.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

t_elem *inicjuj_liste();
t_elem *dodaj(t_elem *, int);
t_elem *usun(t_elem *);
t_stos *inicjuj_stos();
t_stos *inicjuj();
int isempty(t_stos *);
void push(t_stos *, int);
void pop(t_stos *, int *);
void fullprint(t_stos *);
void print(t_stos *);
void clear(t_stos *);
void duplicate(t_stos *);
void reverse(t_stos *);
int is_too_empty(t_stos *);

#endif
