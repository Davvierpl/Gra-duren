#include "Card.h"
#include <stdio.h>

int Card::get_wartosc()
{
    return wartosc;
}

char Card::get_kolor()
{
    return kolor;
}

int Card::get_nr()
{
    return numer;
}
void Card::show_card()
{
    printf("|");
    if(wartosc<=10)
        printf("%d",wartosc);
    else if(wartosc==11)
        printf("J");
    else if(wartosc==12)
        printf("Q");
    else if(wartosc==13)
        printf("K");
    else if(wartosc==14)
        printf("A");

    printf("%c|",kolor);
}

Card::~Card()
{

}

void Card::set_nr(int nr)
{
        if (nr>=0&&nr<=51)
    {
        numer=nr;
        if(numer%4==0)
            kolor='P';
        else if(numer%4==1)
            kolor='T';
        else if(numer%4==2)
            kolor='D';
        else if(numer%4==3)
            kolor='K';

        for(int i=2;i<=14;i++)
        {
            if(numer>=4*(i-2)&&numer<=4*(i))
            {
                wartosc=i;
            }
        }
    }
        else if(nr=52)
        {
            wartosc=0;
            kolor=' ';
        }

}
