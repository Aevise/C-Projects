#pragma once

#include <iostream>

class Gra
{

public:
    int ile_statkow[4];
    int tryb;
    int statki_gracz1 = 0;
    int statki_gracz2 = 0;

    char tab_wl[30][30] = {};
    char tab_prz[30][30] = {};

    void ilosc_statkow();
    void wypelnienie_planszy();
    void wstawianie_statkow(int ile, int jaki_rozmiar, char plansza[30][30]);
    void strzal(char plansza[30][30], int zycie, bool A_I);
    void rozpocznij();
    void pokazanie_planszy(char plansza[30][30]);
    void pokazanie_planszy_przeciwnika(char plansza[30][30]);
};

