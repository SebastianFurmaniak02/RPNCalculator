#ifndef STRUKTURY_H
#define STRUKTURY_H

typedef struct elem {
  int liczba;
  struct elem *nastepny;
} t_elem;

typedef struct stos {
  t_elem *PoczListy;
} t_stos;

#endif 
