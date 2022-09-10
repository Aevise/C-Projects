// KalkulatorZPamiecia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <math.h>
#include "Kalkulator.h"



int main()
{
    Kalkulator kalkulator;
    double pomocnik = 0;
    double a = 0;
    
    char wybor2[2] = { 0,0 };
    std::setlocale(LC_ALL, "pl_PL");

  //------------------------------------------------------------------------------------------------------//  
    std::string wybor;
    std::cout << "Rozpoczynam działanie:\n";
    std::cin >> wybor;
    size_t pozycja;
    std::string liczba1;
    std::string liczba2;
    std::string dzialanie_pomocnik;
    std::string wybor_kopia_bez_dzialania;
    std::string pomocnik1;
    char dzialanie;
    double zmieniona_liczba1{};
    double zmieniona_liczba2{};
    int dlugosc_wejscia;
    double wynik;
    dlugosc_wejscia = wybor.length();

    std::string spr;
    std::string tablica_ster = "%p^/*-+";
    std::string tablica_pr1 = "%p^";
    std::string tablica_pr2 = "/*";
    std::string tablica_pr3 = "-+";
   
    try
    {
        pozycja = wybor.find_first_of(tablica_pr1, 0);
    }
    catch (std::out_of_range)
    {
        try
        {
            pozycja = wybor.find_first_of(tablica_pr2, 0);
        }
        catch (std::out_of_range)
        {
            pozycja = wybor.find_first_of(tablica_pr3, 0);
        }
    }

    

    dzialanie_pomocnik = wybor.substr(pozycja, 1);
    dzialanie = dzialanie_pomocnik[0];

    wybor_kopia_bez_dzialania = wybor;
    wybor_kopia_bez_dzialania.erase(pozycja, 1);
    std::cout << "TEST:: " << wybor_kopia_bez_dzialania;
    system("PAUSE");

    if (pozycja != std::string::npos)
    {
        for (int i = 0; i < tablica_ster.length(); i++)
        {
            
        }
    }

    pozycja = wybor.find("+");
    if (pozycja != std::string::npos)
    {
        std::cout << "tu znalezione: " << pozycja;
        liczba1 = wybor.substr(0, pozycja);
        liczba2 = wybor.substr(pozycja + 1, std::string::npos);
        zmieniona_liczba1 = std::stod(liczba1);
        zmieniona_liczba2 = std::stod(liczba2);
        wynik = zmieniona_liczba1 + zmieniona_liczba2;
        std::cout << "\nWynik: " << wynik;
    }

    pozycja = wybor.find("-");
    if (pozycja != std::string::npos)
    {
        std::cout << "tu znalezione: " << pozycja;
        liczba1 = wybor.substr(0, pozycja);
        liczba2 = wybor.substr(pozycja + 1, std::string::npos);
        zmieniona_liczba1 = std::stod(liczba1);
        zmieniona_liczba2 = std::stod(liczba2);
        wynik = zmieniona_liczba1 - zmieniona_liczba2;
        std::cout << "\nWynik: " << wynik;
    }
    //------------------------------------------------------------------------------------------------------// 
        kalkulator.ster(wybor, wybor2, pomocnik, a, kalkulator);

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
