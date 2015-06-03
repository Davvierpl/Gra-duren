#include "Deck.h"
#pragma once

class Player
{
    int nr;
    int N;
    Talia* reka;

public:
    Player(int,int=0);//konstruktor przyjmujacy numer gracza i ile ma miec kart na start
    void show_cards();//wyswietla wszystkie karty gracza
    void dobierz(Talia &,int=5);//dodaje z wybranej talii tyle kart z konca ile sie podaje
    Talia get_deck();//zwraca talie gracza
    void rzuc(int);//usuwanie wybranej karty z talii gracza
    int get_M();//zwraca ilosc posiadanych kart przez gracza
    Card karta(int);//zwraca karte gracza na podanym miejscu
    ~Player();
};
