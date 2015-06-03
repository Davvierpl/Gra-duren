#pragma once

class Card
{
    int numer;//kazda karta posiada swoj numer, potrzebny do tworzenia pat
    int wartosc;
    char kolor;

public:
    ~Card();
    int get_wartosc();
    void set_nr(int);//ustawianie numeru karty, w podanym systemie: 0 = 2 pik, 1= 2 trefl, 2 = 2 kier, 3 = 2 karo, 5 = 3 pik itd.
    int get_nr();
    char get_kolor();
    void show_card();

};
