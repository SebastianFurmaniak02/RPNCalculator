#include "kalkulator.h"
#include "operacje.h"

int main()
{
  char buf[10]=""; //bufor do przyjmowania danych
  int arg, l1, l2, wynik, pom; //wartosc argumentu,liczb do dzialan matematycznych oraz pomocnicza wartosc
  t_stos *stos=inicjuj(); //stos glowny, inicjacja
  t_stos *pamiec=inicjuj(); //stos uzywany do podrecznej pamieci, inicjacja
  
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
            case 'v':  //pierwiastkowanie
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

/* SPRAWOZDANIE
Sebastian Furmaniak, kalkulator RPN, 21.01.2022 r.
Pelny program powinien zawierac nastepujace pliki: main.c kalkulator.c kalkulator.h operacje.c operacje.h struktury.h Makefile 
Jako zadanie dodatkowe: operacjetab.h operacjetab.c strukturytab.h
Dodatkowo program zawiera potegowanie oraz pierwiastkowanie.
Dodatkowo program zawiera dodatkowy stos pelniacy role pamieci podrecznej, w ktorym sa zapisywane wyniki na zyczenie.
Wynik po kazdej operacji jest wyswietlany na std wyjscie, a takze zapisywany na stosie.

Test 0
Sprawdzenie Makefile.
Makefile jest tylko do pierwotnej wersji programu gdzie stos jest zrobiony na liscie.

Dane wejsciowe:
make

Rezultat:
Powstal program KalkulatorRPN.

Test 1
Sprawdzanie poprawnego dzialania operacji +,-
Dane wejsciowe:
./KalkulatorRPN
1) 2 5 + 
2) 6 8 -

Dane wyjsciowe:
1) 7
2) -2

Rezultat:
Te operacje dzialaja poprawnie.

Test 2
Sprawdzanie poprawnego dzialania operacji *,/
Dane wejsciowe:
./KalkulatorRPN
1) 2 3 *
2) 5 0 *
3) 3 2 /
4) 0 2 /
5) 5 0 /

Dane wyjsciowe:
1) 6
2) 0
3) 1
4) 0
5) BLAD: DZIELENIE PRZEZ ZERO

Rezultat:
Te operacje dzialaja poprawnie.


Test 3
Sprawdzenie poprawnego dzialania operacji ^,v
Dane wejsciowe:
./KalkulatorRPN
1) 2 3 ^
2) 5 -2 ^
3) 81 v
4) -5 v
5) 2 0 ^
6) 0 6 ^
7) 0 v
8) 5 v

Dane wyjsciowe:
1) 8
2) BLAD: WART. WYKLADNIKA <0
3) 9
4) BLAD: WART. POD PIERW. <0
5) 1
6) 0 
7) 0
8) 2

Rezultat:
Operacje dzialaja prawidlowo.

Test 4
Test opcji.
Dane wejsciowe:
./KalkulatorRPN
1) 2 d f
2) 2 3 p f
3) 2 3 P
4) 2 3 4 c f
5) 2 3 f r f
6) q

Dane wyjsciowe:
1) 
2
2
2) 
2
3)
3
4)

5)
3
2
2
3

6) (poprostu wychodzi)

Rezultat:
Operacje dzialaja poprawnie.

Test 5
Co jak jest za malo danych na operacje
Dane wejsciowe:
./KalkulatorRPN
1) r
2) p
3) P
4) f
5) c
6) d

Dane wyjsciowe:

Rezultat:
Operacje nie wykonaja sie poniewaz jest za malo danych.
Dodatkowo tam gdzie potrzebne sa minimum dwa elementy funkcje nie wykonuja sie gdy na stosie jest tylko jeden.

Test 6
Liczby ujemne
Dane wejsciowe:
./KalkulatorRPN
1) -2 -2 +
2) 6 -2 -
3) -2 -5 *
4) -2 5 *
5) -4 -2 /
6) -6 2 /

Dane wyjsciowe:
1) -4
2) 8
3) 10
4) -10
5) 2
6) -3

Rezultat:
Liczby ujemne dzialaja w operacjach

Test 7
Sprawdzanie pamieci podrecznej pod M, m, w
Dane wejsciowe:
./KalkulatorRPN
2 2 + m 4 5 + m M w M

Dane wyjsciowe:
10
4 (tu pierwsze M)
  (Tu juz nic nie wyswietli bo pamiec jest pusta)

Rezultat:
Zapis dziala poprawnie i dziala na podobnej zasadzie co operacje na glownym stosie ale pod innymi literkami oraz na innym stosie

Test 8
Co jak nie ma danej opcji
Dane wejsciowe:
./KalkulatorRPN
2 3 + k f

Dane wyjsciowe:
5
5

Rezultat:
Gdy wybrana zostanie nierozpoznana opcja nic sie nie stanie.
Program po prostu to zignoruje.

Test 9
Test trudniejszego dzialania. (2+4*5)/(1+7)

Dane wejsciowe:
./KalkulatorRPN
2 4 5 * + 1 7 + / f

Dane wyjsciowe:
20
22
8
2 (ostateczny wynik)
2 (z fullprinta)
Rezultat:
Dzialanie zostalo poprawnie rozwiazane.
Tu widac ze printf(wynik) sprawia ze jest to troche mniej czytelne.
Rozwazalem jego usuniecie, ale ostatecznie zdecydowalem sie go zostawic.

Test 10
Test ten polega na podmianie naglowku w main.c z operacje.h na operacjetab.h i skompilowac recznie bez makefile.
gcc main.c operacjetab.c kalkulator.c -lm
Dalej sprawdzenia poprawnosci dzialania tego samego programu ale ze stosem na bazie tablicy jednowymiarowej.
Najlepiej bylo wykonac te same testy co powyzej.

Rezultat:
Program dziala w analogiczny sposob jak ten powyzej.

Test 11
Test polega na sprawdzeniu przepelnienia stosu w opcji z tablica
(jedyna roznica pomiedzy wersjami to to ze w tej stos jest zdefiniowany w strukturytab.h i nie jest ograniczony).

Dane wejsciowe:
./a.out
1 2 3 4 5 6 7 8 9 10 11 f

Dane wyjsciowe:
BLAD: STOS PELNY
1
2
3
4
5
6
7
8
9
10

Rezultat: 
Wszystkie wartosci oprocz 11 zapisaly sie na stosie poniewaz limit liczb wynosi 10. Mozna to zmienic w strukturytab.h

Wnioski: 
Program dziala poprawnie, chodz mozna zastanowic sie nad printf(wynik), czy wogole jest potrzebny.
*/

