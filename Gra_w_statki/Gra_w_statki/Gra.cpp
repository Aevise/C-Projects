#include "Gra.h"

void Gra::ilosc_statkow()
{

    for (int i = 0; i <= 3; i++)
        {
            std::cout << "Ile statkow " << i + 2 << " masztowych: ";
            std::cin >> ile_statkow[i];
    }
}

void Gra::rozpocznij()
{
    wypelnienie_planszy();
    ilosc_statkow();
    int tryb_gry;
    bool AI1 = 0;
    bool AI2 = 0;

    do
    {
        std::cout << "Podaj tryb gry: 0 - PvP, 1 - Gracz vs AI, 2 - AI vs AI: ";
        std::cin >> tryb_gry;
    } while (tryb_gry < 0 || tryb_gry > 3);

    if (tryb_gry == 1)
    {
        AI2 = 1;
    }
    else if (tryb_gry == 2)
    {
        AI1 = 1;
        AI2 = 1;
    }
    std::cout << "\nWstawianie statkow gracza 1: \n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "\nRozstawiam statki " << i + 2 << " masztowe\n";
        wstawianie_statkow(ile_statkow[i], i + 2, tab_wl);
    }

    std::cout << "\nWstawianie statkow gracza 2: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "\nRozstawiam statki " << i + 2 << " masztowe\n";
        wstawianie_statkow(ile_statkow[i], i + 2, tab_prz);
    }
    
    for (int i = 0; i < 4; i++)
    {
        statki_gracz1 = statki_gracz1 + (ile_statkow[i] * (i + 2));
        statki_gracz2 = statki_gracz2 + (ile_statkow[i] * (i + 2));
    }

    while (statki_gracz1 != 0 || statki_gracz2 != 0)
    {
        if (tryb_gry == 0 || tryb_gry == 2)
        {
            std::cout << "Ruch pierwszegi gracza: \n";
            strzal(tab_prz, statki_gracz2, AI1);
            std::cout << "Wyswietlenie tablic" << std::endl << "Twoja tablica:\n";
            pokazanie_planszy(tab_wl);
            std::cout << "Tablica przeciwnika: \n";
            pokazanie_planszy_przeciwnika(tab_prz);
            std::cout << "\nPrzyjzyj sie swojej planszy i planszy przeciwnika, po czym wcisnij enter\n";

            system("PAUSE");
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;


            std::cout << "Ruch 2 gracza: \n";
            strzal(tab_wl, statki_gracz1, AI2);
            std::cout << "Tablica 2 gracza: \n";
            pokazanie_planszy(tab_prz);
            std::cout << "Tablica Twojego przeciwnika: \n";
            pokazanie_planszy_przeciwnika(tab_wl);
            std::cout << "\nPrzyjrzyj sie swojej planszy i planszy przeciwnika, po czym wcisnij enter\n";
            system("PAUSE");
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        }
        else if (tryb_gry == 1)
        {
            std::cout << "Ruch pierwszegi gracza: \n";
            strzal(tab_prz, statki_gracz2, AI1);
            std::cout << "Wyswietlenie tablic" << std::endl << "Twoja tablica:\n";
            pokazanie_planszy(tab_wl);
            std::cout << "Tablica przeciwnika: \n";
            pokazanie_planszy_przeciwnika(tab_prz);
            std::cout << "\nPrzyjzyj sie swojej planszy i planszy przeciwnika, po czym wcisnij enter\n";

            system("PAUSE");
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;


            std::cout << "Ruch 2 gracza: \n";
            strzal(tab_wl, statki_gracz1, AI2);
        }

    }

    if (statki_gracz1 == 0)
    {
        std::cout << "\nGratulacje, wygral gracz nr 1";
    }
    else
    {
        std::cout << "\nGratulacje, wygral gracz nr 2";
    }
}

void Gra::pokazanie_planszy(char plansza[30][30])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            std::cout << plansza[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void Gra::pokazanie_planszy_przeciwnika(char plansza[30][30])
{
    char maskowanie = '*';
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (plansza[i][j] == '2')
            {
                std::cout << maskowanie << " ";
            }
            else if (plansza[i][j] == '3')
            {
                std::cout << maskowanie << " ";
            }
            else if (plansza[i][j] == '4')
            {
                std::cout << maskowanie << " ";
            }
            else if (plansza[i][j] == '5')
            {
                std::cout << maskowanie << " ";
            }
            else
            {
                std::cout << plansza[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

}

void Gra::wypelnienie_planszy()
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            tab_wl[i][j] = '*';
            tab_prz[i][j] = '*';
        }
    }
}

void Gra::strzal(char plansza[30][30], int zycie, bool A_I)
{
    int gdzieV;
    int gdzieP;
    bool sukces = 1;
    bool test = 1;
    int AI_trafilo = 0;
    int zapamietaj1;
    int zapamietaj2;
    int losowosc;

    if (A_I == 1)
    {
        while (sukces)
        {
            if (AI_trafilo == 0)
            {
                test = 1;
                gdzieV = rand() % 30;
                gdzieP = rand() % 30;
            }
            else
            {
                if (AI_trafilo > 1)
                {
                    losowosc = losowosc;
                }
                else
                {
                    losowosc = rand() % 3;
                }
                    if (losowosc == 0)
                    {
                        gdzieV++;
                    }
                    else if (losowosc == 1)
                    {
                        gdzieV--;
                    }
                    else if (losowosc == 2)
                    {
                        gdzieP++;
                    }
                    else
                    {
                        gdzieP--;
                    }
            }

            if (plansza[gdzieV][gdzieP] == 'O')
            {
                test = 0;
            }
            else if (plansza[gdzieV][gdzieP] == 'X')
            {
                test = 0;
            }

            if (test == 1)
            {
                if (plansza[gdzieV][gdzieP] == '*')
                {
                    plansza[gdzieV][gdzieP] = 'O';
                    std::cout << "\nPudlo!\n";
                    sukces = 0;
                }
                else
                {
                    plansza[gdzieV][gdzieP] = 'X';
                    zycie = zycie = 1;
                    std::cout << ("\nGratulacje trafiono w statek. Mozesz strzelac jeszcze raz\n");
                    sukces = 1;
                    AI_trafilo++;
                    zapamietaj1 = gdzieV;
                    zapamietaj2 = gdzieP;
                }
            }
        }
    }
    else
    {
        while (sukces)
        {
            test = 1;
            std::cout << "Gdzie oddac strzal: \n";
            do
            {
                std::cout << "Poziomo: ";
                std::cin >> gdzieV;
            } while (gdzieV < 0 || gdzieV > 30);

            do
            {
                std::cout << "Pionowo: ";
                std::cin >> gdzieP;
            } while (gdzieV < 0 || gdzieV > 30);

            if (plansza[gdzieV][gdzieP] == 'O')
            {
                std::cout << "\nJuz strzelano w to pole, sprobuj jeszcze raz: \n";
                test = 0;
            }
            else if (plansza[gdzieV][gdzieP] == 'X')
            {
                std::cout << "\nJuz strzelano w to pole, sprobuj jeszcze raz: \n";
                test = 0;
            }
            
            if (test == 1)
            {
                if (plansza[gdzieV][gdzieP] == '*')
                {
                    plansza[gdzieV][gdzieP] = 'O';
                    sukces = 0;
                    std::cout << "\nPudlo!\n";
                }
                else
                {
                    plansza[gdzieV][gdzieP] = 'X';
                    zycie = zycie = 1;
                    sukces = 1;
                    std::cout<<("\nGratulacje trafiono w statek. Mozesz strzelac jeszcze raz\n");
                }
            }
        }
    }


}

void Gra::wstawianie_statkow(int ile, int jaki_rozmiar, char plansza[30][30])
{
    int gdzieP;
    int gdzieV;
    char jak;
    bool koniec = 1;
    bool sprawdzenie = 1;
    bool blad = 1;
    bool sterowanie;

    std::cout << "Rozstawic statki recznie, czy automatycznie? 0 - automatycznie 1 - recznie. Wybor: ";
    std::cin >> sterowanie;

    if (sterowanie == 1)
    {
        for (int i = 0; i < ile; i++)
        {
            while (1)
            {
                blad = 0;
                do
                {
                    std::cout << "Gdzie mam wstawic statek? Podaj wartosc od 0 do 30 (wiersz)";
                    std::cin >> gdzieP;
                } while (gdzieP < 0 || gdzieP > 30);

                do
                {
                    std::cout << "Gdzie mam wstawic statek? Podaj wartosc od 0 do 30 (kolumna)";
                    std::cin >> gdzieV;
                } while (gdzieV < 0 || gdzieV > 30);

                do
                {
                    std::cout << "Jak mam wstawic statek? V - poziomo, P - pionowo: ";
                    std::cin >> jak;
                    if (jak == 'P')
                    {
                        koniec = 0;
                    }
                    if (jak == 'V')
                    {
                        koniec = 0;
                    }

                } while (koniec);

                if ((gdzieP + jaki_rozmiar > 29) && (jak == 'P'))
                {
                    std::cout << "Blad 1 wprowadzania statku, sprobuj jeszcze raz" << std::endl;
                    blad = 1;
                }
                else if ((gdzieV + jaki_rozmiar > 29) && (jak == 'V'))
                {
                    std::cout << "Blad 2 wprowadzania statku, sprobuj jeszcze raz" << std::endl;
                    blad = 1;
                }

                if (blad == 0)
                {
                    for (int j = 0; j < jaki_rozmiar; j++)
                    {
                        if (jak == 'P')
                        {
                            if (plansza[gdzieP + j][gdzieV + 1] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP + j][gdzieV - 1] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP + j - 1][gdzieV] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP + j + 1][gdzieV] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else
                            {
                                std::cout << "\nPrzechodze do wprowadzania kolejnego statku:\n";
                                break;
                            }
                        }
                        else
                        {
                            if (plansza[gdzieP + 1][gdzieV + j] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP - 1][gdzieV + j] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP][gdzieV + j - 1] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else if (plansza[gdzieP][gdzieV + j + 1] != '*')
                            {
                                std::cout << "\nStatki nachodza sie na siebie";
                                blad = 1;
                                break;
                            }
                            else
                            {
                                std::cout << "\nPrzechodze do wprowadzania kolejnego statku:\n";
                                break;
                            }
                        }
                    }
                }

                if (blad == 0)
                {
                    break;
                }

            }

            for (int j = 0; j < jaki_rozmiar; j++)
            {
                if (jak == 'P')
                {
                    plansza[gdzieP + j][gdzieV] = jaki_rozmiar + 48;
                }
                else
                {
                    plansza[gdzieP][gdzieV + j] = jaki_rozmiar + 48;
                }
            }
        }
    }
    else
    {
    int orientowanie;
    for (int i = 0; i < ile; i++)
    {
        while (1)
        {
            blad = 0;
            gdzieP = rand() % 30;
            gdzieV = rand() % 30;
            orientowanie = rand() % 2;
            if (orientowanie == 0)
            {
                jak = 'P';
            }
            else
            {
                jak = 'V';
            }

            if ((gdzieP + jaki_rozmiar > 29) && (jak == 'P'))
            {
                blad = 1;
            }
            else if ((gdzieV + jaki_rozmiar > 29) && (jak == 'V'))
            {
                blad = 1;
            }

            if (blad == 0)
            {
                for (int j = 0; j < jaki_rozmiar; j++)
                {
                    if (jak == 'P')
                    {
                        if (plansza[gdzieP + j][gdzieV + 1] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else if (plansza[gdzieP + j][gdzieV - 1] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else if (plansza[gdzieP + j - 1][gdzieV] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (plansza[gdzieP + 1][gdzieV + j] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else if (plansza[gdzieP - 1][gdzieV + j] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else if (plansza[gdzieP][gdzieV + j - 1] != '*')
                        {
                            blad = 1;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            if (blad == 0)
            {
                break;
            }

        }

        for (int j = 0; j < jaki_rozmiar; j++)
        {
            if (jak == 'P')
            {
                plansza[gdzieP + j][gdzieV] = jaki_rozmiar + 48;
            }
            else
            {
                plansza[gdzieP][gdzieV + j] = jaki_rozmiar + 48;
            }
        }
    }
    }
}