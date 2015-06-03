#include "Player.h"
#include <stdio.h>


Player::Player(int numer,int ile)
{
    N=ile;
    nr=numer;
    reka= new Talia(ile);
}

void Player::show_cards()
{
    printf("Gracz nr.%d:\t\t",nr);
    reka->show_all();
}

void Player::dobierz(Talia &t,int ile)
{
    Card x;
    {

        for(int i=0;i<ile;i++)
        {
            x=t.usun_z_konca();
            reka->dodaj_na_koniec(x);
        }
    }
}

Talia Player::get_deck()
{
        return *reka;
}

void Player::rzuc(int ktora)
{
    if(ktora>0&&ktora<=reka->get_N())
    {
        reka->usun_z_miejsca(ktora);
    }
}

int Player::get_M()
{
    return reka->get_N();
}

Card Player::karta(int ktora)
{
    return reka->karta(ktora);
}


Player::~Player()
{
    delete reka;
}
