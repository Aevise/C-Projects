#pragma once
#include <string>

class Kalkulator
{

public:
    double wynik = 0;
    double pamiec = 0;
    int zamiennik = 0;
    int sterowanie = 0;
    double dodawanie(double a);
    double odejmowanie(double a);
    double mnozenie(double a);
    double dzielenie(double a);
    double modulo(int a);
    double pierwiastek();
    double czyszczenie();
    double zmiana_wartosci(double* a);
    double zapis_pamieci(double a);
    double czyszczenie_pamieci();
    double przywolanie_pamieci();
    double dodawanie_pamiec(double a);
    double odejmowanie_pamiec(double a);
    double mnozenie_pamiec(double a);
    double dzielenie_pamiec(double a);
    double modulo_pamiec(int a);
    double pierwiastek_pamiec();
    void ster(std::string &wybor, char wybor2[2], double pomocnik, double a, Kalkulator& kalkulator);
};

