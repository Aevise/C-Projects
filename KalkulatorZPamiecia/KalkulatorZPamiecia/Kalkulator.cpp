#include "Kalkulator.h"
#include <iostream>
#include <string>
#include <math.h>

double Kalkulator::dodawanie(double a)
{
    wynik = wynik + a;
    return wynik;
}

double Kalkulator::odejmowanie(double a)
{
    wynik = wynik - a;
    return wynik;
}

double Kalkulator::mnozenie(double a)
{
    wynik = wynik * a;
    return wynik;
}

double Kalkulator::dzielenie(double a)
{
    if (a == 0)
    {
        std::cout << "\nNie dzieli sie przez 0\n";
    }
    else
    {
        wynik = wynik / a;
    }

    return wynik;
}

double Kalkulator::modulo(int a)
{
    zamiennik = static_cast<int>(wynik);
    wynik = zamiennik % a;
    return wynik;
}

double Kalkulator::pierwiastek()
{
    if (wynik < 0)
    {
        std::cout << "\nKalkulator nie obsluguje liczb zespolonych\n";
    }
    else
    {
        wynik = sqrt(wynik);
    }
    return wynik;
}

double Kalkulator::czyszczenie()
{
    wynik = 0;
    return wynik;
}

double Kalkulator::zmiana_wartosci(double* a)
{
    return wynik = *a;
}

double Kalkulator::zapis_pamieci(double a)
{
    pamiec = a;
    return pamiec;
}

double Kalkulator::czyszczenie_pamieci()
{
    pamiec = 0;
    return pamiec;
}

double Kalkulator::przywolanie_pamieci()
{
    wynik = pamiec;
    return wynik;
}

double Kalkulator::dodawanie_pamiec(double a)
{
    pamiec = pamiec + a;
    return pamiec;
}

double Kalkulator::odejmowanie_pamiec(double a)
{
    pamiec = pamiec - a;
    return pamiec;
}

double Kalkulator::mnozenie_pamiec(double a)
{
    pamiec = pamiec * a;
    return pamiec;
}

double Kalkulator::dzielenie_pamiec(double a)
{
    if (a == 0)
    {
        std::cout << "\nNie dzieli sie przez 0\n";
    }
    else
    {
        pamiec = pamiec / a;
    }

    return pamiec;
}

double Kalkulator::modulo_pamiec(int a)
{
    zamiennik = static_cast<int>(pamiec);
    pamiec = zamiennik % a;
    return pamiec;
}

double Kalkulator::pierwiastek_pamiec()
{
    if (pamiec < 0)
    {
        std::cout << "\nKalkulator nie obsluguje liczb zespolonych\n";
    }
    else
    {
        pamiec = sqrt(pamiec);
    }
    return pamiec;
}

void Kalkulator::ster(std::string &wybor, char wybor2[2], double pomocnik, double a, Kalkulator &kalkulator)
{

    while (wybor2[0] != 'E')
    {
    liczba1:
        std::cout << "\nObecna wartosc: " << kalkulator.wynik << std::endl;
        std::cin >> wybor;
        std::cin.clear();

        try {
            kalkulator.wynik = std::stod(wybor);
            pomocnik = std::stod(wybor);
            goto liczba1;
        }
        catch (std::invalid_argument) {
            if (wybor.length() == 2)
            {
                std::cout << "\nDzialanie na pamieci: " << wybor[1] << std::endl;
                wybor2[1] = wybor[1];
                goto koniec;
            }
            else
            {
                std::cout << "\nWybrane dzialanie: " << wybor[0] << std::endl;
                wybor2[0] = wybor[0];
            }
        }

    dzialanie:
        if (wybor2[0] == 'E' || wybor2[0] == 's' || wybor2[0] == 'C')
        {
            goto koniec;
        }
        else
        {
            std::cin >> wybor;
            std::cin.clear();
            try
            {
                a = std::stod(wybor);
                goto pkt1;
            }
            catch (std::invalid_argument)
            {
                std::cout << "\nObecnie wybrane dzialanie: " << wybor[0] << std::endl;

                wybor2[0] = wybor[0];
                goto dzialanie;
            }
        }
    koniec:
        if (wybor.length() == 1)
        {
            pkt1:
            switch (wybor2[0])
            {
            case  '+':
                kalkulator.wynik = kalkulator.dodawanie(a);
                std::cout << "Wynik: " << kalkulator.wynik;
                break;
            case '-':
                kalkulator.wynik = kalkulator.odejmowanie(a);
                std::cout << "Wynik: " << kalkulator.wynik;
                break;
            case '*':
                kalkulator.wynik = kalkulator.mnozenie(a);
                std::cout << "Wynik: " << kalkulator.wynik;
                break;
            case '/':
                kalkulator.wynik = kalkulator.dzielenie(a);
                std::cout << "Wynik: " << kalkulator.wynik;
                break;
            case '%':
                kalkulator.wynik = kalkulator.modulo(a);
                std::cout << "Wynik: " << kalkulator.wynik;
                break;
            case 's':
                kalkulator.wynik = kalkulator.pierwiastek();
                std::cout << "Wynik: " << kalkulator.wynik << std::endl;
                break;
            case 'C':
                kalkulator.wynik = kalkulator.czyszczenie();
                break;
            case 'E':
                std::cout << "\nZakañczam dzia³anie";
                break;
            default:
                std::cout << "\nPodaj wlasciwe dzialanie";
                break;
            }
        }
        else
        {
            a = pomocnik;
            switch (wybor2[1])
            {
            case '+':
                kalkulator.pamiec = kalkulator.dodawanie_pamiec(a);
                break;
            case '-':
                kalkulator.pamiec = kalkulator.odejmowanie_pamiec(a);
                break;
            case '*':
                kalkulator.pamiec = kalkulator.mnozenie_pamiec(a);
                break;
            case '/':
                kalkulator.pamiec = kalkulator.dzielenie_pamiec(a);
                break;
            case '%':
                kalkulator.pamiec = kalkulator.modulo_pamiec(a);
                break;
            case 's':
                kalkulator.pamiec = kalkulator.pierwiastek_pamiec();
                break;
            case 'C':
                kalkulator.pamiec = kalkulator.czyszczenie_pamieci();
                break;
            case 'R':
                std::cout << "Wartosc przechowana w pamieci: " << kalkulator.pamiec;
                break;
            default:
                std::cout << "\nPodaj wlasciwe dzialanie";
                break;
            }
        }
    }
}