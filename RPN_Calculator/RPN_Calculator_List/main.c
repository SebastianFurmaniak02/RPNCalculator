#include "kalkulator.h"
#include "operacje.h"

int main()
{
  char buf[10]=""; //bufor do przyjmowania danych
  int arg, l1, l2, wynik, pom; //wartosc argumentu,liczb do dzialan matematycznych oraz pomocnicza wartosc
  t_stos *stos=NULL; //stos glowny
  t_stos *pamiec=NULL; //stos uzywany do podrecznej pamieci
  stos=inicjuj(stos); //inicjacja stosu
  pamiec=inicjuj(pamiec); //inicjacja stosu

  while(buf[0] != 'q'){    //petla do wczytywania
    scanf("%s", buf);    //wczytanie do bufora
    if(isdigit(buf[0])){  //jestli to liczba to daj ja na stos
        arg=atoi(buf);
        push(stos,arg);
    }
    else if(buf[0]== '-' && strlen(buf)>1) { //jestli to liczba ujemna daj ja na stos
        arg=atoi(buf);
        push(stos,arg);
    }
    else {  //jestli to znak 
        switch (buf[0]) { //switch do obslugi opcji
            case 'p':  //opcja pop
                pop(stos,&arg);
                break;
            case 'c':  //opcja clear
                clear(stos);
                break;
            case 'P':  //opcja print (jeden z gory)
                print(stos);
                break;
            case 'r':  //opcja reverse (zamiana dwoch pierwszych elementow miejscami) 
                reverse(stos);
                break;
            case 'd':  //opcja duplicate duplikujaca pierwszy element
                duplicate(stos);
                break;
            case 'f':  //opcja fullprint wyswietlajaca caly stos glowny
                fullprint(stos);
                break;
            case 'q':  //opcja wyjscia
                break;
            case 'm':  //opcja zapisujaca w stosie pamieciowym pierwszej wartosci ze stosu glownego
                if (isempty(stos)) {
                    pop(stos,&pom);
                    push(stos,pom);
                    push(pamiec,pom);
                }
                break;
            case 'M':  //opcja wyswietlajaca stos pamieciowy
                fullprint(pamiec);
                break;
            case 'w':  //opcja czyszczaca stos pamieciowy
                clear(pamiec);
                break;
            case '+':  //dodawanie
                if (is_too_empty(stos)) {
                    pop(stos,&l2);
                    pop(stos,&l1); //zdejmij ze stosu 2 pierwsze wartosci zapamietujac je
                    wynik=dodawanie(l1,l2); //dodaj te wartosci
                    push(stos,wynik); //daj wynik na szczyt stosu
                    printf("%d\n",wynik); //wyswietl wynik
                }
                break;
            case '-':  //odejmowanie
                if (is_too_empty(stos)) {
                    pop(stos,&l2);
                    pop(stos,&l1); //analogicznie jak dodawanie
                    wynik=odejmowanie(l1,l2); 
                    push(stos,wynik); 
                    printf("%d\n",wynik);
                }
                break;
            case '*':  //mnozenie
                if (is_too_empty(stos)) {
                    pop(stos,&l2);
                    pop(stos,&l1); //analogicznie jak dodawanie
                    wynik=mnozenie(l1,l2);
                    push(stos,wynik);
                    printf("%d\n",wynik);
                }
                break;
            case '/': //dzielenie
                if (is_too_empty(stos)) {
                    pop(stos,&l2);
                    pop(stos,&l1);  //analogicznie jak dodawanie
                    wynik=dzielenie(l1,l2);
                    push(stos,wynik);
                    printf("%d\n",wynik);
                }
                break;
            case '^': //potegowanie
                if (is_too_empty(stos)) {
                    pop(stos,&l2);
                    pop(stos,&l1);  //analogicznie jak dodawanie
                    wynik=potegowanie(l1,l2);
                    push(stos,wynik);
                    printf("%d\n",wynik);
                }
                break;
            case '%':  //pierwiastkowanie
                if (isempty(stos)) {
                    pop(stos,&l1); //zdejmij wartosc z gory
                    wynik=pierwiastkowanie(l1); //zpierwiastkuja ja
                    push(stos,wynik); //wrzuc wynik na stos
                    printf("%d\n",wynik);  //wyswietl wynik
                }
                break;
            default: //jak opcja nie jest obslugiwana to nic nie robi
                break;
        }
    }
  }
  return (0);
}
