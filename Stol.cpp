#include "Stol.h"
#include <stdio.h>
#include <stdlib.h>
Game::Game()
{
    player1=new Talia(5);
    player2=new Talia(5);
    walka1=new Talia(5);
    walka2=new Talia(5);
    Card zerujaca;
    zerujaca.set_nr(52);
        for(int i=1;i<6;i++)//tworzenie talii z zerowymi obiektami
        {
            player1->zastap(zerujaca,i);
            player2->zastap(zerujaca,i);
            walka1->zastap(zerujaca,i);
            walka2->zastap(zerujaca,i);
        }
}

bool Game::na_stol_1(Card nowa,int miejsce, Card trumf)
{
    int ile_zer=0;
    char kolor_trumfa=trumf.get_kolor();
    char kolor_nowej=nowa.get_kolor();

        for(int i=1;i<6;i++)//liczenie (5 - ile wylozonych kart przez gracza 2)
        {
            if(player2->get_wartosc(i)==0)
                ile_zer++;
        }

        if(ile_zer==5)//gracz 2 nie polozyl na stole jeszcze zadnej karty
        {
            if(player1->get_wartosc(miejsce)==0)//sprawdzanie, czy na wybranym miejscu na stole nie znajduje sie juz karta
            {
                player1->zastap(nowa,miejsce);
                return 1;
            }
            else
            {
                printf("Blad!!");
                system("pause");
                system("clear");
                return 0;
            }
        }
        else if(ile_zer<5&&player2->get_wartosc(miejsce)!=0)//gracz 2 wyrzucil juz karty na stol; sprawdzanie, czy wykladamy karte, by bic karte przeciwnika
        {

            if(player1->get_wartosc(miejsce)==0&&kolor_nowej==player2->get_kol(miejsce))
            {
                player1->zastap(nowa,miejsce);
                return 1;
            }
            else if(player1->get_wartosc(miejsce)==0&&kolor_nowej==kolor_trumfa&&player2->get_wartosc(miejsce)!=52)//nowe
            {
                player1->zastap(nowa,miejsce);
            }
            else
            {
                printf("Blad!!");
                system("pause");
                system("clear");
                return 0;
            }
        }
        else
        {
            return 0;
        }
}

bool Game::na_stol_2(Card nowa,int miejsce, Card trumf)//wszystko, jak wyzej
{
    char kolor_trumfa=trumf.get_kolor();
    int ile_zer=0;
    char kolor_nowej=nowa.get_kolor();

    for(int i=1;i<6;i++)
    {
        if(player1->get_wartosc(i)==0)
            ile_zer++;
    }

        if(ile_zer==5)
        {
            if(player2->get_wartosc(miejsce)==0)
            {

                player2->zastap(nowa,miejsce);
                return 1;
            }
            else
            {
                printf("Blad!!");
                system("pause");
                system("clear");
                return 0;
            }
        }
        else if(ile_zer<5&&player1->get_wartosc(miejsce)!=0)
        {
            if(player2->get_wartosc(miejsce)==0&&kolor_nowej==player1->get_kol(miejsce))
            {

                player2->zastap(nowa,miejsce);
                return 1;
            }
            else if(player2->get_wartosc(miejsce)==0&&kolor_nowej==kolor_trumfa&&player1->get_wartosc(miejsce)!=52)//nowe
            {
                player2->zastap(nowa,miejsce);
            }
            else
            {
                printf("Blad!!");
                system("pause");
                system("clear");
                return 0;
            }
        }
        else
        {
            return 0;
        }
}


void Game::show_player1()
{
    player1->show_all();
}

void Game::show_player2()
{
    player2->show_all();
}

int Game::check_p1()
{
    int ile_par=0;
    int ile_zer=0;
    int ile_zer2=0;
    int ile_wartosci=0;
    for(int i=1;i<6;i++)//liczenie ilosci tych samych kart w wystawionej talii gracza 1 i ile kart wystawil gracz 2
            {
                for(int j=i+1;j<6;j++)
                {
                    if((player1->get_wartosc(i)==player1->get_wartosc(j))&&(player1->get_wartosc(i)!=0))
                    ile_par++;
                }

                if(player1->get_wartosc(i)==0)
                    ile_zer++;

                if(walka2->get_wartosc(i)!=0)
                    ile_wartosci++;
            }

    //mozliwe poprawne kombinacje kart
    bool jednakarta=0;
    bool parai1karta=0;
    bool trojka=0;
    bool czwroka=0;
    bool dwiepary=0;
    bool trojkaipara=0;

        if(ile_par==0&&ile_zer==4)
            jednakarta=1;
        else if(ile_par==1&&ile_zer==2)
            parai1karta=1;
        else if(ile_par==3&&ile_zer==2)
            trojka=1;
        else if(ile_par==6&&ile_zer==0)
            czwroka=1;
        else if(ile_par==2&&ile_zer==0)
            dwiepary=1;
        else if(ile_par==4&&ile_zer==0)
            trojkaipara=1;

            if(((jednakarta==1)||(parai1karta==1)||(trojka==1)||(czwroka==1)||(dwiepary==1)||(trojkaipara==1))&&(ile_wartosci==0))
            {
                return 1;
            }
            else if(ile_zer==5)//gracz jeden nie wyrzucil zadnej karty na stol
            {
                for(int i=1;i<6;i++)//liczenie ile kart wyrzucil gracz 2
                {
                    if(player2->get_wartosc(i)==0)
                        ile_zer2++;
                }

                    if(ile_zer2!=0)
                    {
                        Card zerujaca;
                        zerujaca.set_nr(52);

                            for(int i=1;i<6;i++)
                            {
                                walka2->zastap(zerujaca,i);
                            }
                        return 2;
                    }
            }
            else if(ile_wartosci!=0)
            {
                return 3;
            }
            else
            {
                return 0;
            }
}

int Game::check_p2()
{
    int ile_par=0;
    int ile_zer=0;
    int ile_zer2=0;
    int ile_wartosci=0;
    for(int i=1;i<6;i++)
            {
                for(int j=i+1;j<6;j++)
                {
                    if((player2->get_wartosc(i)==player2->get_wartosc(j))&&(player2->get_wartosc(i)!=0))
                    ile_par++;
                }

                if(player2->get_wartosc(i)==0)
                    ile_zer++;

                if(walka1->get_wartosc(i)!=0)
                    ile_wartosci++;
            }

    bool jednakarta=0;
    bool parai1karta=0;
    bool trojka=0;
    bool czwroka=0;
    bool dwiepary=0;
    bool trojkaipara=0;

        if(ile_par==0&&ile_zer==4)
            jednakarta=1;
        else if(ile_par==1&&ile_zer==2)
            parai1karta=1;
        else if(ile_par==3&&ile_zer==2)
            trojka=1;
        else if(ile_par==6&&ile_zer==0)
            czwroka=1;
        else if(ile_par==2&&ile_zer==0)
            dwiepary=1;
        else if(ile_par==4&&ile_zer==0)
            trojkaipara=1;

            if(((jednakarta==1)||(parai1karta==1)||(trojka==1)||(czwroka==1)||(dwiepary==1)||(trojkaipara==1))&&(ile_wartosci==0))
            {
                return 1;
            }
            else if(ile_zer==5)
            {
                for(int i=1;i<6;i++)
                {
                    if(player1->get_wartosc(i)==0)
                        ile_zer2++;
                }

                    if(ile_zer2!=0)
                    {
                        Card zerujaca;
                        zerujaca.set_nr(52);

                            for(int i=1;i<6;i++)
                            {
                                walka1->zastap(zerujaca,i);
                            }
                        return 2;
                    }
            }
            else if(ile_wartosci!=0)
            {
                return 3;
            }
            else
            {
                return 0;
            }
}

void Game::przerzut_do_walka_1()
{
    Card zerujaca;
    zerujaca.set_nr(52);
                    for(int i=1;i<6;i++)
                    {
                            walka1->zastap(player1->karta(i),i);
                    }
}

void Game::przerzut_do_walka_2()
{
    Card zerujaca;
    zerujaca.set_nr(52);
                    for(int i=1;i<6;i++)
                    {
                            walka2->zastap(player2->karta(i),i);
                    }
}

Talia Game::zwroc_1()
{
    Talia zwracana(0);
    Card zerujaca;
    zerujaca.set_nr(52);

        for(int i=1;i<6;i++)
            if(player1->get_wartosc(i)!=0)
            {
                zwracana.dodaj_na_koniec(player1->karta(i));
                player1->zastap(zerujaca,i);
            }

    return zwracana;

}

Talia Game::zwroc_2()
{
    Talia zwracana(0);
    Card zerujaca;
    zerujaca.set_nr(52);

        for(int i=1;i<6;i++)
            if(player2->get_wartosc(i)!=0)
            {
                zwracana.dodaj_na_koniec(player2->karta(i));
                player2->zastap(zerujaca,i);
            }

    return zwracana;

}

Talia Game::walka_1(Card trumf)
{
    char kolor_trumfa=trumf.get_kolor();
    Talia zwracana(0);
    int ile_zer=0;
    Card zerujaca;
    zerujaca.set_nr(52);

    for(int i=1;i<6;i++)//usuwanie kart ze stolu i liczenie dopelnienia do 5 kart na stole gracza 2
    {
        player1->zastap(zerujaca,i);
        player2->zastap(zerujaca,i);

        if(walka2->get_num(i)==52)
        {
            ile_zer++;
        }
    }

        if (ile_zer==5)
        {
            return 0;
        }
        else
        {
            for(int i=1;i<6;i++)
                {
                    if((walka2->get_kol(i)==walka1->get_kol(i))&&(walka1->get_wartosc(i)!=0))//sprawdzanie zgodnosci kolorow kart gracza 1 i 2 na danym miejscu
                    {
                        if(walka1->get_wartosc(i)>walka2->get_wartosc(i))//gracz 1 przebija gracza 2
                        {
                            walka1->zastap(zerujaca,i);
                            walka2->zastap(zerujaca,i);
                        }
                        else if(walka1->get_wartosc(i)<walka2->get_wartosc(i))//gracz 1 nie przebija gracza 2
                        {
                            zwracana.dodaj_na_koniec(walka1->karta(i));
                            zwracana.dodaj_na_koniec(walka2->karta(i));
                        }
                    }
                    else if((walka1->get_wartosc(i)==0)&&(walka2->get_wartosc(i)!=0))//gracz 1 nie przebijal karty gracza 2
                    {
                        zwracana.dodaj_na_koniec(walka2->karta(i));
                    }
                    else if(walka2->get_kol(i)==kolor_trumfa)//gracz 2 polozyl trumfa, a gracz jeden nie polozyl na to miejsce trumfa
                    {
                            zwracana.dodaj_na_koniec(walka1->karta(i));
                            zwracana.dodaj_na_koniec(walka2->karta(i));
                    }
                    else if(walka1->get_kol(i)==kolor_trumfa)//gracz 1 polozyl trumfa na karte gracza 2 o innym kolorze
                    {
                        walka1->zastap(zerujaca,i);
                        walka2->zastap(zerujaca,i);
                    }

                    //czyszczenie talii walka1 walka2
                    walka1->zastap(zerujaca,i);
                    walka2->zastap(zerujaca,i);
                }
        return zwracana;
        }


}

Talia Game::walka_2(Card trumf)
{
    char kolor_trumfa=trumf.get_kolor();
    Talia zwracana(0);
    int ile_zer=0;
    Card zerujaca;
    zerujaca.set_nr(52);

    for(int i=1;i<6;i++)
    {
        player1->zastap(zerujaca,i);
        player2->zastap(zerujaca,i);

        if(walka1->get_num(i)==52)
        {
            ile_zer++;
        }
    }

        if (ile_zer==5)
        {
            return 0;
        }
        else
        {
            for(int i=1;i<6;i++)
                {
                    if((walka1->get_kol(i)==walka2->get_kol(i))&&(walka2->get_wartosc(i)!=0))
                    {
                        if((walka2->get_wartosc(i))>(walka1->get_wartosc(i)))
                        {
printf("\nW > , przed zastapieniem karta zerujaca");
                            walka1->zastap(zerujaca,i);
                            walka2->zastap(zerujaca,i);
printf("\nW < , po zastapieniem karta zerujaca");

                        }
                        else if(walka2->get_wartosc(i)<walka1->get_wartosc(i))
                        {
                            zwracana.dodaj_na_koniec(walka1->karta(i));
                            zwracana.dodaj_na_koniec(walka2->karta(i));
                        }
                    }
                    else if((walka2->get_wartosc(i)==0)&&(walka1->get_wartosc(i)!=0))
                    {
                        zwracana.dodaj_na_koniec(walka1->karta(i));
                    }
                    else if(walka1->get_kol(i)==kolor_trumfa)
                    {
                        zwracana.dodaj_na_koniec(walka1->karta(i));
                        zwracana.dodaj_na_koniec(walka2->karta(i));
                    }
                    else if(walka2->get_kol(i)==kolor_trumfa)
                    {
                        walka1->zastap(zerujaca,i);
                        walka2->zastap(zerujaca,i);
                    }
                    walka1->zastap(zerujaca,i);
                    walka2->zastap(zerujaca,i);
                }
        return zwracana;
        }


}

int Game::ile_zer_1()//sprawdzanie dopelnienia do 5 ilosci wyrzuconych kart przez przeciwnika
{
    int ile_zer;
        for(int i=1;i<6;i++)
    {
        if(walka2->get_num(i)==52)
        {
            ile_zer++;
        }
    }
    return ile_zer;
}

int Game::ile_zer_2()
{
    int ile_zer;
        for(int i=1;i<6;i++)
    {
        if(walka1->get_num(i)==52)
        {
            ile_zer++;
        }
    }
    return ile_zer;
}

Game::~Game()
{
    delete player1;
    delete player2;
    delete walka1;
    delete walka2;
}
