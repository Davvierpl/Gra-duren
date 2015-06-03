#include "Deck.h"
#include "Card.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>


Talia::Talia(int wielkosc_talii)
{
    N=wielkosc_talii;
    tal=new Card[N];
}

int Talia::get_N()
{
    return N;
}

void Talia::set_N(int Nka)
{
    N=Nka;
}

void Talia::start()
{
        for (int i=0;i<N;i++)
        {
            tal[i].set_nr(i);
        }
}

void Talia::show_all()
{
        for (int i=0;i<N;i++)
    {

        tal[i].show_card();
    }
    printf("\n");
}

void Talia::tasuj()
{
    srand( time( NULL ) );
    Card x;
    int losowa;

        for(int i=N-1;i>=0;i--)
        {
            losowa=rand()%N;
            x=tal[i];
            tal[i]=tal[losowa];
            tal[losowa]=x;

        }
}

void Talia::przeloz(int ile_przelozyc)
{
    if(ile_przelozyc<0||ile_przelozyc>N)
        printf("Bledna liczba");
    else
        {
            Card na_koniec[ile_przelozyc];

            for(int i=0;i<ile_przelozyc;i++)
            {
                na_koniec[i]=tal[i];
            }

            for(int i=0;i<(N-ile_przelozyc);i++)
            {
                tal[i]=tal[i+ile_przelozyc];
            }

            for(int i=0;i<ile_przelozyc;i++)
            {
                tal[i+(N-ile_przelozyc)]=na_koniec[i];
            }
        }
}

void Talia::dodaj_na_koniec(Card nowa_karta)
{
    Card kopia_talii[N+1];

        for(int i=0;i<N;i++)
        {
            kopia_talii[i]=tal[i];
        }

    tal= new Card [N+1];
    tal[N]=nowa_karta;

        for(int i=0;i<N;i++)
        {
            tal[i]=kopia_talii[i];
        }

    N++;
}

Card Talia::usun_z_konca()
{
    Card ostatnia_karta=tal[N-1];
    Card kopia_talii[N-1];
        for(int i=0;i<N-1;i++)
        {
            kopia_talii[i]=tal[i];
        }

    tal= new Card [N-1];

        for(int i=0;i<N-1;i++)
        {
            tal[i]=kopia_talii[i];
        }

    N--;
    return ostatnia_karta;
}

void Talia::dodaj_na_miejsce(Card nowa_karta, int miejsce)
{
    Card kopia_talii[N+1];
        for(int i=0;i<N;i++)
        {
            kopia_talii[i]=tal[i];
        }

    tal= new Card [N+1];
    tal[miejsce-1]=nowa_karta;

        for(int i=0;i<(miejsce-1);i++)
        {
            tal[i]=kopia_talii[i];
        }

        for(int i=miejsce-1;i<N;i++)
        {
            tal[i+1]=kopia_talii[i];
        }
    N++;
}

Card Talia::usun_z_miejsca(int miejsce)
{

        Card wybrana_karta=tal[miejsce-1];
        Card kopia_talii[N-1];

            for(int i=0;i<N;i++)
            {
                kopia_talii[i]=tal[i];
            }

        tal= new Card [N-1];

            for(int i=0;i<miejsce-1;i++)
            {
                tal[i]=kopia_talii[i];
            }

            for(int i=miejsce;i<N;i++)
            {
                tal[i-1]=kopia_talii[i];
            }
        N--;
        return wybrana_karta;


}

void Talia::zastap(Card nowa, int miejsce)
{
    tal[miejsce-1]=nowa;
}

int Talia::get_wartosc(int ktora)
{
    return tal[ktora-1].get_wartosc();
}

Card Talia::karta(int ktora)
{
    return tal[ktora-1];
}

int Talia::get_num(int ktora)
{
    return tal[ktora-1].get_nr();
}

char Talia::get_kol(int ktora)
{
    return tal[ktora-1].get_kolor();
}

Talia::~Talia()
{
    delete []tal;
}


