#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>

void tabliczkaMnozenia();
void sumaCyfr();
void liczbyLosowe();
void szachownica();

int main() {

    bool petla = true;
    char wybor,
    tab_s[6/*ilosc stringow*/][43/*dlugosc najdluzszego stringa*/] =
            {"1.Tabliczka mnozenia", "2.Suma cyfr", "3.Losowe liczby", "4.Szachownica", "Zakoncz",
             "\'w\' - w gore \'s\' - w dol \'e\' - zatwierdz\n"};
    int pozycja = 0;

    printf("%s", tab_s[5]);
    printf("\033[36m%s\033[0m\n%s\n%s\n%s\n\n%s", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
    while(petla){
        //zbieranie danych na temat pozycji strzalki
        wybor = getch();
        switch(wybor){
            case 'w':
                pozycja--;
                break;
            case 's':
                pozycja++;
                break;
        }
        //nie pozwala wyjsc poza zakres
        if(pozycja > 4){
            pozycja = 4;
        } else if(pozycja < 0) {
            pozycja = 0;
        }
        //ustalanie pozycji strzalki
        switch(pozycja){
            case 0:
                system("cls");
                printf("%s", tab_s[5]);
                printf("\033[36m%s\033[0m\n%s\n%s\n%s\n\n%s", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
                break;
            case 1:
                system("cls");
                printf("%s", tab_s[5]);
                printf("%s\n\033[36m%s\033[0m\n%s\n%s\n\n%s", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
                break;
            case 2:
                system("cls");
                printf("%s", tab_s[5]);
                printf("%s\n%s\n\033[36m%s\033[0m\n%s\n\n%s", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
                break;
            case 3:
                system("cls");
                printf("%s", tab_s[5]);
                printf("%s\n%s\n%s\n\033[36m%s\033[0m\n\n%s", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
                break;
            case 4:
                system("cls");
                printf("%s", tab_s[5]);
                printf("%s\n%s\n%s\n%s\n\n\033[36m%s\033[0m", tab_s[0], tab_s[1], tab_s[2], tab_s[3], tab_s[4]);
                break;
        }

        if(pozycja == 0 && wybor == 101){
            system("cls");
            tabliczkaMnozenia();
        } else if(pozycja == 1 && wybor == 101){
            system("cls");
            sumaCyfr();
        } else if(pozycja == 2 && wybor == 101){
            system("cls");
            liczbyLosowe();
        } else if(pozycja == 3 && wybor == 101){
            system("cls");
            szachownica();
        } else  if(pozycja == 4 && wybor == 101){
            system("cls");
            petla = false;
        }
    }
    return 0;
}

void tabliczkaMnozenia(){
    int wiersze, kolumny;
    bool kontynuowac = true;
    printf("Program drukuje tabliczke mnozenia\n");
    printf("Podaje ilosc wierszy(maks: 25): "); scanf("%d", &wiersze);
    printf("Podaje ilosc kolumn(maks: 25): "); scanf("%d", &kolumny);

    if(wiersze > 25 || wiersze < 0){
        printf("Niepoprawne dane");
    } else if(kolumny > 25 || kolumny < 0){
        printf("Niepoprawne dane");
    } else {
        for (int i = 0; i < wiersze + 2; i++) {
            if (i == 0) {
                printf("    |  ");
                for (int j = 0; j < kolumny; j++) {
                    printf("%4d", j + 1);
                }
            } else if (i == 1) {
                printf("----|--");
                for (int j = 0; j < 4 * kolumny; j++) {
                    printf("%c", '-');
                }
            } else {
                printf("%4d|  ", i - 1);
                for (int j = 1; j < kolumny + 1; j++) {
                    printf("%4d", (i - 1) * j);
                }
            }
            printf("\n");
        }
    }
}

void sumaCyfr(){
    unsigned long liczba;
    int cyfra, suma = 0;
    printf("Wprowadz duza liczbe calkowita dodatnia: ");
    scanf("%lu", &liczba);

    if(liczba < 0 || liczba > 4294967295){
        printf("Niepoprawne dane");
    } else {
        while(liczba != 0){
            cyfra = liczba%10;
            suma += cyfra;
            liczba /= 10;
        }
    }
    printf("Suma cyfr tej liczby to: %d", suma);
}

void liczbyLosowe(){
    int min, max, ile, losowa, ile_dod, ile_uj, suma_dod, suma_uj;
    float srednia_dod, srednia_uj;
    system("cls");
    printf("Podaj przedzial liczb losowych\n");
    printf("od: "); scanf("%d", &min);
    printf("do: "); scanf("%d", &max);
    printf("ilosc liczb losowych: "); scanf("%d", &ile);
    srand(time(NULL));
    printf("\n");

    suma_dod = 0;
    suma_uj = 0;
    ile_dod = 0;
    ile_uj = 0;
    for(int i = 1; i <= ile; i++){
        losowa = min + rand()%(max - min + 1);
        if(losowa > 0){
            suma_dod += losowa;
            ile_dod += 1;
            printf("liczba: %d, suma dodatnich: %d, ile dodatnich: %d\n", losowa, suma_dod, ile_dod);
        } else if(losowa < 0) {
            suma_uj += losowa;
            ile_uj += 1;
            printf("liczba: %d, suma ujemnych: %d, ile ujemnych: %d\n", losowa, suma_uj, ile_uj);
        } else {
            printf("liczba: 0\n");
            continue;
        }
    }

    if(ile_uj == 0){
        srednia_dod = suma_dod/ile_dod;
        printf("\n\nLiczb dodatnich bylo: %d\nLiczb ujemnych bylo: %d\nSrednia liczb dodatnich: %.2f\nSrednia liczb ujemnych: 0",
               ile_dod, ile_uj, srednia_dod);
    } else if(ile_dod == 0){
        srednia_uj = suma_uj/ile_uj;
        printf("\n\nLiczb dodatnich bylo: %d\nLiczb ujemnych bylo: %d\nSrednia liczb dodatnich: 0\nSrednia liczb ujemnych: %.2f",
               ile_dod, ile_uj, srednia_uj);
    } else {
        srednia_dod = suma_dod/ile_dod;
        srednia_uj = suma_uj/ile_uj;
        printf("\n\nLiczb dodatnich bylo: %d\nLiczb ujemnych bylo: %d\nSrednia liczb dodatnich: %.2f\nSrednia liczb ujemnych: %.2f",
               ile_dod, ile_uj, srednia_dod, srednia_uj);
    }
    printf("\n\n");
}

void szachownica(){
    int pole_s, pole_w, szachownica_s, szachownica_w;
    system("cls");
    printf("Podaj wymiary jednego pola szachownicy\n");
    printf("Wysokosc: "); scanf("%d", &pole_w);
    printf("Szerokosc: "); scanf("%d", &pole_s);
    printf("\nPodaj wymiary szachownicy\n");
    printf("Wysokosc: "); scanf("%d", &szachownica_w);
    printf("Szerokosc: "); scanf("%d", &szachownica_s);

    if(pole_s < 0 || pole_w < 0 || szachownica_s < 0 || szachownica_w < 0) {
        printf("Wartosci nie moga byc ujemne!!!");
    } else {
        goto start;
    }

    start:
    for(int a = 0; a < szachownica_w; a++){
        if(a%2 == 0){
            for(int b = 0; b < pole_w; b++){
                printf("\n");
                for(int i = 0; i < szachownica_s; i+=2){
                    for(int j = 0; j < pole_s; j++){
                        printf("\033[32m#");
                    }
                    for(int k = 0; k < pole_s; k++){
                        printf("\033[31m#");
                    }
                }
            }
        } else {
            for(int b = 0; b < pole_w; b++){
                printf("\n");
                for(int i = 0; i < szachownica_s; i+=2){
                    for(int j = 0; j < pole_s; j++){
                        printf("\033[31m#");
                    }
                    for(int k = 0; k < pole_s; k++){
                        printf("\033[32m#");
                    }
                }
            }
        }
    }

    printf("\033[0m");
    printf("\n\n");
}