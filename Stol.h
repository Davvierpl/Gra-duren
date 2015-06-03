#include "Deck.h"
#include "Player.h"

class Game
{
    Talia* player1;
    Talia* player2;
    Talia* walka1;
    Talia* walka2;

public:
    Game();
    bool na_stol_1(Card,int,Card);
    bool na_stol_2(Card,int,Card);
    void show_player1();
    void show_player2();
    int check_p1();
    int check_p2();
    void przerzut_do_walka_1();
    void przerzut_do_walka_2();
    Talia zwroc_1();
    Talia zwroc_2();
    Talia walka_1(Card);
    Talia walka_2(Card);
    int ile_zer_1();
    int ile_zer_2();
    ~Game();
};
