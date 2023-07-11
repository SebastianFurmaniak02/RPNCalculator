#ifndef STRUKTURYTAB_H
#define STRUKTURYTAB_H

#define WIELKOSC 10

typedef struct tab {
  int dlugosc;
  int tab[WIELKOSC];
} t_tab;

typedef struct stos {
  t_tab *PoczListy;
} t_stos;

#endif 