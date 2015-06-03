#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Stol.h"


int main()
{
    Talia deck(52);//stworzenie talii z 52 pustymi miejscami
    deck.start();//zapelnienie miejsc wszystkimi kartami
    deck.tasuj();
    Card trumf=deck.karta(1);//ostatnia karta jest trumfem
    Player p1(1),p2(2);
    p1.dobierz(deck);
    p2.dobierz(deck);
    Game gra;

    //zmienne obslugujace petle gry
    bool play=1;
    int tura=1;//decyduje kogo tura
    int menu=1;

    bool dorzucanie_p1=1;
    bool dorzucanie_p2=1;
    //zmienne odpowiadajace wyborowi karty z reki i miejsca polozenia na stole
    int ktora_karta;
    int na_ktore_miejsce;

    bool sukces;
    int sprawdzanie;

    while(menu)
    {
        printf("\n\n\n\n\n\t\tWITAJ W GRZE KARCIANEJ DUREN!\n\n\n\n<1>\tNowa gra\n<2>\tZasady\n<3>\tAutor\n<0>\tKoniec\n\nTwoj wybor:");
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:
            play=1;

            while(play==1)
            {
                while(tura==1)
                {
                    system("clear");
                    printf("\n\n\n\t\t\tTura gracza 1.\n\n\n\n");
                    system("pause");
                    system("clear");
                    dorzucanie_p1=1;

                    while(dorzucanie_p1==1)
                    {
                        printf("Kart w talii: %d\nTrumf: ",deck.get_N());
                        trumf.show_card();

                        printf("\n\t\t\t");
                        gra.show_player2();
                        printf("\n\n\t\t\t");
                        gra.show_player1();
                        printf("\n\n\n");

                        p1.show_cards();

                            if(p1.get_M()!=0)//sprawdzenie czy gracz nie wylozyl juz wszystkich kart z reki na stol
                            {
                                printf("\nWybierz karte(wpisz 0, aby zakonczyc ture): ");
                                scanf("%d",&ktora_karta);

                                if(ktora_karta!=0)
                                {
                                    printf("Wybierz miejsce: ");
                                    scanf("%d",&na_ktore_miejsce);

                                        if(ktora_karta<=p1.get_M())//SPRAWDZANIE CZY WYBOR KARTY NIE JEST WIEKSZY OD CALEJ TALII W RECE
                                        {
                                            sukces=gra.na_stol_1(p1.karta(ktora_karta),na_ktore_miejsce,trumf);
                                        }

                                            if (sukces==1)
                                            {
                                                p1.rzuc(ktora_karta);//usuwanie z reki player'a 1 danej karty
                                                system("clear");
                                            }
                                }
                                else
                                {
                                    dorzucanie_p1=0;
                                }
                            }
                            else
                            {
                                dorzucanie_p1=0;
                            }
                    system("cls");
                    }//koniec dorzucania

                    sprawdzanie=gra.check_p1();//sprawdzanie kombinacji kart itp.

                        if(sprawdzanie==1)//gracz 2 nie wykladal jeszcze na stol kart; gracz 1 wylozyl na stol odpowiednia kombinacje kart
                        {
                            gra.przerzut_do_walka_1();
                            tura=2;

                            //dobieranie kart z talii, jesli na reku pozostalo mniej niz 5 kart
                            if(p1.get_M()<5&&(deck.get_N()>=(5-p1.get_M())))
                            {
                                p1.dobierz(deck,5-p1.get_M());
                            }
                            else if(p1.get_M()<5&&deck.get_N()<(5-p1.get_M()))
                            {
                                p1.dobierz(deck,deck.get_N());
                            }
                        }
                        else if(sprawdzanie==2)//gracz 1 zbiera wszystko, co rzucil na stol gracz 2
                        {
                            tura=2;
                            Talia do_zwrocenia=gra.zwroc_2();
                            p1.dobierz(do_zwrocenia,do_zwrocenia.get_N());
                        }
                        else if(sprawdzanie==3)//sprawdzanie kto wygrywa dana ture, gdy obaj zawodnicy rzucili karty na stol
                        {
                            gra.przerzut_do_walka_1();
                            Talia po_walce=gra.walka_1(trumf);

                                if(po_walce.get_N()==0)//wygrywa gracz 1, przebijajac wszystkie karty rzucone przez gracza 2
                                {
                                    tura=1;
                                }
                                if(po_walce.get_N()>0)//gracz 1 nie przebil wszystkich kart, dobiera pozostale na stole karty, zmiana tury
                                {
                                    p1.dobierz(po_walce,po_walce.get_N());
                                    tura=2;
                                }
                            //dobieranie kart do 5 na rece
                            if(p1.get_M()<5&&(deck.get_N()>=(5-p1.get_M())))
                            {
                                p1.dobierz(deck,5-p1.get_M());
                            }
                            else if(p1.get_M()<5&&deck.get_N()<(5-p1.get_M()))
                            {
                                p1.dobierz(deck,deck.get_N());
                            }

                        }
                        else
                        {
                            printf("Bledna kombinacja kart! Sprobuj raz jeszcze\n");
                            system("pause");
                            system("clear");
                            dorzucanie_p1=1;

                            Talia kopia=gra.zwroc_1();
                            p1.dobierz(kopia,kopia.get_N());
                        }

                        if(p1.get_M()==0&&deck.get_N()==0)//sprawdzanie czy gracz 1 zwyciezyl
                        {
                            tura=0;
                            play=0;
                            system("clear");
                            printf("\n\n\n\n\n\t\t\tZwyciestwo gracza 1!!!!!!\n\n\n\n\n");
                        }
                }

                while(tura==2)//tura gracza 2; wszystkie funkcje analogiczne do gracza 1
                {
                    system("clear");
                    printf("\n\n\n\t\t\tTura gracza 2.\n\n\n\n");
                    system("pause");
                    system("clear");

                    dorzucanie_p2=1;

                    while(dorzucanie_p2==1)
                    {
                        printf("Kart w talii: %d\nTrumf: ",deck.get_N());
                        trumf.show_card();

                        printf("\n\t\t\t");
                        gra.show_player1();
                        printf("\n\n\t\t\t");
                        gra.show_player2();
                        printf("\n\n\n");

                        p2.show_cards();

                            if(p2.get_M()!=0)
                            {
                                printf("\nWybierz karte(wpisz 0, aby zakonczyc ture): ");
                                scanf("%d",&ktora_karta);

                                if(ktora_karta!=0)
                                {
                                    printf("Wybierz miejsce: ");
                                    scanf("%d",&na_ktore_miejsce);

                                        if(ktora_karta<=p2.get_M())
                                        {
                                            sukces=gra.na_stol_2(p2.karta(ktora_karta),na_ktore_miejsce,trumf);
                                        }

                                            if (sukces==1)
                                            {
                                                p2.rzuc(ktora_karta);
                                                system("clear");
                                            }
                                }
                                else
                                {
                                    dorzucanie_p2=0;
                                }
                            }
                            else
                            {
                                dorzucanie_p2=0;
                            }
                        system("clear");
                    }

                    sprawdzanie=gra.check_p2();

                        if(sprawdzanie==1)
                        {
printf("przed przerzut do walka 2");
                            gra.przerzut_do_walka_2();
printf("po przerzut do walka 2");
                            tura=1;
                            if(p2.get_M()<5&&(deck.get_N()>=(5-p2.get_M())))
                            {
                                p2.dobierz(deck,5-p2.get_M());
                            }
                            else if(p2.get_M()<5&&deck.get_N()<(5-p2.get_M()))
                            {
                                p2.dobierz(deck,deck.get_N());
                            }
                        }
                        else if(sprawdzanie==2)
                        {
                            tura=1;
                            Talia do_zwrocenia=gra.zwroc_1();
                            p2.dobierz(do_zwrocenia,do_zwrocenia.get_N());
                        }
                        else if(sprawdzanie==3)
                        {

                            gra.przerzut_do_walka_2();
printf("przed walka 2");
                            Talia po_walce=gra.walka_2(trumf);
printf("po walka 2");
                                if(po_walce.get_N()==0)
                                {
                                    tura=2;
                                }
                                if(po_walce.get_N()>0)
                                {
                                    p2.dobierz(po_walce,po_walce.get_N());
                                    tura=1;
                                }

                            if(p2.get_M()<5&&(deck.get_N()>=(5-p2.get_M())))
                            {
                                p2.dobierz(deck,5-p2.get_M());
                            }
                            else if(p2.get_M()<5&&deck.get_N()<(5-p2.get_M()))
                            {
                                p2.dobierz(deck,deck.get_N());
                            }

                        }
                        else
                        {
                            printf("Bledna kombinacja kart! Sprobuj raz jeszcze\n");
                            system("pause");
                            system("clear");
                            dorzucanie_p1=1;

                            Talia kopia=gra.zwroc_2();
                            p2.dobierz(kopia,kopia.get_N());
                        }

                        if(p2.get_M()==0&&deck.get_N()==0)
                        {
                            tura=0;
                            play=0;
                            system("clear");
                            printf("\n\n\n\n\n\t\t\tZwyciestwo gracza 2!!!!!!\n\n\n\n\n");
                        }
                }
            }
            break;
        case 2:
            system("clear");
            printf("Kolory w grze:\nP - pik(wino)\nT - trefl(zoladz)\nD - karo(dzwonek)\nK - kier(czerwien)");
            printf("\n\nZasady:\n1. Gracze dostaje po 5 kart\n2. Odslania sie ostatnia karte z talii, ktora jest karta atutowa(trumfem)");
            printf("\n3. Pierwszy gracz wyrzuca karte lub odpowiednia kombinacje kart na stol i ciagnie, aby miec \"na rece\" 5 kart");
            printf("\n4. Drugi gracz probuje pobic karty starszymi lub trumfami, pobite karty odklada na bok, pozostale bierze do reki.");
            printf("Jesli pobil wszystkie nastepuje jego tura.");
            printf("\n5. Wygrywa gracz, ktory pierwszy pozbedzie sie kart");
            printf("\n6. \"Druniem\"zostaje przegrany\n");
            printf("\n\nDostepne kombinacje kart:\nPara i dowolna karta:      |2T||2D||JP|\nTrojka:\t\t\t   |7P||7D||7K|\nCzworka i dowolna karta:   |DD||DK||DP||DT||3D|");
            printf("\nDwie pary i dowolna karta: |4P||4D||AD||AT||JK|\nTrojka i para: \t\t   |AD||AK||AT||5T||5P|\n");
            break;
        case 3:
            system("clear");
            printf("\n\n\n\n\n\nAutorem gry jest Dawid Wozniak\n\n\n\n\n\n");
            break;
        case 0:
            break;
        default:
            printf("Blad! Sprobuj raz jeszcze");
            break;
        }
    }

}
