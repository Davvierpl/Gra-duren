#include "Card.h"
#pragma once

class Talia
{
    int N;//liczba kart w talii
    Card* tal;//wskaznik na tablice dynamiczna kart

public:
    Talia(int);//kostruktor; tworzy talie o podanej ilosci kart
    int get_N();// pobiera wielkosc talii
    void set_N(int);//ustawia wielkosc tablicy zawierajacej karty
    void start();//wypelnia talie wszystkimi kartami
    void show_all();//metoda wyswietlajaca wszystkie karty w talii
    void tasuj();
    void przeloz(int);//metoda przekladajaca talie od podanego numery karty w talii
    void dodaj_na_koniec(Card);//dodaje wskazana tarte na koniec talii
    Card usun_z_konca();
    void dodaj_na_miejsce(Card,int);
    Card usun_z_miejsca(int);
    void zastap(Card,int);
    int get_wartosc(int);
    Card karta(int);//zwraca wysokosc wskazanej karty z talii
    int get_num(int);
    char get_kol(int);
    ~Talia();
};
