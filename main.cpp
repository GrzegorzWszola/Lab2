#include<stdio.h>
#include<conio.h>
#include<math.h>

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

void sumaCyfr(){}
void liczbyLosowe(){}
void szachownica(){}