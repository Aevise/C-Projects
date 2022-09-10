// Drzewo_BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

typedef struct Drzewo_BST
{
    struct Drzewo_BST* prawy;
    struct Drzewo_BST* lewy;
    struct Drzewo_BST* ojciec;
    int dane;
}BST_Tree;

void insertBST(BST_Tree** Korzen, int dane_do_dodania); 
BST_Tree *(Znajdz_Dane)(BST_Tree* Korzen, int dane_do_wyszukania); //jezeli nie znajdzie szukanej danej to zwroci NULL
void printBST(BST_Tree* Korzen, int sposob_wypisania);
void wypisz_poziom(BST_Tree* Korzen, int lev); //0 - to poziom korzenia
int hBST(BST_Tree* Korzen);
int countLevBST(BST_Tree* Korzen, int lev);
void InOrder(BST_Tree* Korzen);
void PreOrder(BST_Tree* Korzen);
void PostOrder(BST_Tree* Korzen);
void LevelOrder(BST_Tree* Korzen);
void RysujBST(BST_Tree* Korzen);
void wypisz_poziom2(BST_Tree* Korzen, int lev);
void removeBST(BST_Tree** Korzen, int dane);
void tableBST(BST_Tree* Korzen);
int potegowanie(int liczba, int stopien);
//BST_Tree* inpreBST(t1, t2);

int main()
{
    int dane;
    int n;
    BST_Tree* korzen_glowny = NULL;
    BST_Tree *gdzie;
    int ile = 0;
    int wysokosc_drzewa;

    /*
    printf("Podaj liczbe elementow do dodania: ");
    scanf_s("%d", &n);

   for (int i = 0; i < n; i++)
    {
        dane = 1 + rand() % 1000;
        insertBST(&korzen_glowny, i);
    }*/

        insertBST(&korzen_glowny, 15);
        insertBST(&korzen_glowny, 18);
        insertBST(&korzen_glowny, 3);
        insertBST(&korzen_glowny, 7);
        insertBST(&korzen_glowny, 12);
        insertBST(&korzen_glowny, 4);
        insertBST(&korzen_glowny, 1);
        insertBST(&korzen_glowny, 13);
        insertBST(&korzen_glowny, 20);

        gdzie = Znajdz_Dane(korzen_glowny, 13);

        gdzie = Znajdz_Dane(korzen_glowny, 15);

        gdzie = Znajdz_Dane(korzen_glowny, 5);

        printf("\nWypisanie: ");
        for (int i = 1; i <= 5; i++)
        {
            printBST(korzen_glowny, i);
        }
        wysokosc_drzewa = hBST(korzen_glowny);

        printf("\nWysokosc drzewa: %d", wysokosc_drzewa);
        printf("\n-------------------------------------------");
        wypisz_poziom(korzen_glowny, 3);
        printf("\n-------------------------------------------");
        ile = countLevBST(korzen_glowny, 5);
        printf("\nWartosc zwrocna przez ILE %d XDDDD", ile);
        tableBST(korzen_glowny);

        gdzie = Znajdz_Dane(korzen_glowny, 4);
        removeBST(&korzen_glowny, 7);
        tableBST(korzen_glowny);
        for (int i = 1; i <= 5; i++)
        {
            printBST(korzen_glowny, i);
        }


    system("PAUSE");
}

void insertBST(BST_Tree** Korzen, int dane_do_dodania)
{
    if (*Korzen == NULL)    //wykonuje sie przy pierwszym wywolaniu funkcji
    {
        BST_Tree* nowa = (BST_Tree*)malloc(sizeof(BST_Tree));
        *Korzen = nowa;
        nowa->prawy = NULL;
        nowa->lewy = NULL;
        nowa->ojciec = NULL;
        nowa->dane = dane_do_dodania;
    }
    else //dodanie liscia
    {
        BST_Tree* straznik = *Korzen;
        BST_Tree* pomocnik = *Korzen;
        BST_Tree* nowa = (BST_Tree*)malloc(sizeof(BST_Tree));

        char ktora_strona = 0;

        while (*Korzen != NULL) //dotarcie do ostatniego i wlasciwego elementu
        {
            if (dane_do_dodania >= (*Korzen)->dane)
            {
                pomocnik = *Korzen;
                *Korzen = (*Korzen)->prawy;
                ktora_strona = 'P';
            }
            else
            {
                pomocnik = *Korzen;
                *Korzen = (*Korzen)->lewy;
                ktora_strona = 'L';
            }
        }

        if (ktora_strona == 'P') //wybor z ktorej strony drzewa umiescic dane
        {
            pomocnik->prawy = nowa;
        }
        else if (ktora_strona == 'L')
        {
            pomocnik->lewy = nowa;
        }
        else
        {
            printf("\nWystapil blad przy dodawaniu elementu");
        }
        
        nowa->ojciec = pomocnik;
        nowa->prawy = NULL;
        nowa->lewy = NULL;
        pomocnik = NULL;
        nowa->dane = dane_do_dodania;
        *Korzen = straznik;
        straznik = NULL;
    }
}

BST_Tree *(Znajdz_Dane)(BST_Tree* Korzen, int dane_do_wyszukania)
{
    BST_Tree* pomocnik = Korzen;
    int wartosc_liscia = Korzen->dane;

    while (Korzen != NULL)
    {
        if (dane_do_wyszukania == wartosc_liscia)
        {
            return Korzen;
        }
        else if (dane_do_wyszukania >= wartosc_liscia)
        {
            pomocnik = Korzen;
            Korzen = Korzen->prawy;
            if (Korzen == NULL)
            {
                break;
            }
            else
            {
                wartosc_liscia = Korzen->dane;
            }
        }
        else if (dane_do_wyszukania < wartosc_liscia)
        {
            pomocnik = Korzen;
            Korzen = Korzen->lewy;
            if (Korzen == NULL)
            {
                break;
            }
            else
            {
                wartosc_liscia = Korzen->dane;
            }
        }
    }

    if (pomocnik->dane != dane_do_wyszukania)
    {
        printf("\nNie odnaleziono szukanej wartosci. Funkcja zwroci NULL");
        return NULL;
    }
}

void InOrder(BST_Tree* Korzen)
{
    if (Korzen->lewy != NULL)
    {
        InOrder(Korzen->lewy);
    }

    printf("%d\t", Korzen->dane);
    
    if (Korzen->prawy != NULL)
    {
        InOrder(Korzen->prawy);
    }
}

void PreOrder(BST_Tree* Korzen)
{
    printf("%d\t", Korzen->dane);

    if (Korzen->lewy != NULL)
    {
        InOrder(Korzen->lewy);
    }
    if (Korzen->prawy != NULL)
    {
        InOrder(Korzen->prawy);
    }
}

void PostOrder(BST_Tree* Korzen)
{
    if (Korzen->lewy != NULL)
    {
        InOrder(Korzen->lewy);
    }
    if (Korzen->prawy != NULL)
    {
        InOrder(Korzen->prawy);
    }
    printf("%d\t", Korzen->dane);
}

void LevelOrder(BST_Tree* Korzen)
{
    int h = hBST(Korzen);
    for (int i = 0; i <= h; i++)
    {
        wypisz_poziom(Korzen, i);
    }
}

void RysujBST(BST_Tree* Korzen)
{
    int h = hBST(Korzen);
    int zamiennik = h;

    for (int i = 0; i <= h; i++)
    {

        for (int j = zamiennik; j >= 0; j--)
        {
            printf("     ");
        }
        wypisz_poziom2(Korzen, i);
        printf("\n");
        zamiennik--;
    }

}

void wypisz_poziom(BST_Tree* Korzen, int lev)
{
    if (Korzen == NULL)
    {
        return;
    }
    if (lev == 1)
    {
        printf("%d\t", Korzen->dane);
    }
    else if (lev > 1)
    {
        wypisz_poziom(Korzen->lewy, lev - 1);
        wypisz_poziom(Korzen->prawy, lev - 1);
    }

}

void wypisz_poziom2(BST_Tree* Korzen, int lev)
{
    if (Korzen == NULL)
    {
        printf("     ");
        return;
    }
    if (lev == 1)
    {
        printf("   %d   ", Korzen->dane);
    }
    else if (lev > 1)
    {
        wypisz_poziom2(Korzen->lewy, lev - 1);
        wypisz_poziom2(Korzen->prawy, lev - 1);
    }

}

int hBST(BST_Tree* Korzen)
{

    if (Korzen != NULL)
    {
        int L_hBST = hBST(Korzen->lewy);
        int P_hBST = hBST(Korzen->prawy);
        
        if (L_hBST > P_hBST)
        {
            return (L_hBST + 1);
        }
        else
        {
            return (P_hBST + 1);
        }
    }
    else
    {
        return 0;
    }
}

int countLevBST(BST_Tree* Korzen, int lev)
{

    if (Korzen == NULL)
    {
        return 0;
    }
    if ((lev == 1 && Korzen->ojciec != NULL)||(lev == 1 && Korzen->ojciec == NULL))
    {
        return 1;
    }
    else
    {
        return countLevBST(Korzen->lewy, lev - 1) + countLevBST(Korzen->prawy, lev - 1);
    }
}

void printBST(BST_Tree* Korzen, int sposob_wypisania)
{
    if (Korzen != NULL)
    {
        switch (sposob_wypisania)
        {
        case 1: //inorder
            printf("\nWypisanie InOrder:   \n");
            InOrder(Korzen);            
            break;
        case 2: //preorder
            printf("\nWypisanie PreOrder:  \n");
            PreOrder(Korzen);
            break;

        case 3: //postorder
            printf("\nWypisanie PostOrder: \n");
            PostOrder(Korzen);
            break;

        case 4: //level order
            printf("\nWypisanie LevelOrder: \n");
            LevelOrder(Korzen);
            break;

        case 5: //podglad struktury
            printf("\nWypisanie struktury drzewa: \n");
            RysujBST(Korzen);
            break;

        default:
            printf("\nPodano bledny sposob wypisania drzewa BST");
        }
    }
    else
    {
        printf("\nNie ma co wypisywac, drzewo BST nie istnieje");
    }

}

void removeBST(BST_Tree** Korzen, int dane)
{
    BST_Tree *do_usuniecia = Znajdz_Dane(*Korzen, dane);
    printf("Znalezione dane: %p", do_usuniecia);
    BST_Tree* pomocnik = do_usuniecia;
    BST_Tree* pomocnik2 = NULL;
    bool straznik = 1;
 //---------------------USUNIECIE LISCIA-----------------------------------------------   
    if (do_usuniecia != NULL)
    {
        if (do_usuniecia->prawy == NULL && do_usuniecia->lewy == NULL)
        {
            pomocnik = do_usuniecia->ojciec;
            if (dane >= pomocnik->dane)
            {
                pomocnik->prawy = NULL;
            }
            else
            {
                pomocnik->lewy = NULL;
            }
            do_usuniecia = NULL;
            free(do_usuniecia);
        }
//------------------JEDEN POTOMEK------------------------------------------------------
        else if (do_usuniecia->prawy == NULL || do_usuniecia->lewy == NULL)
        {
            pomocnik = do_usuniecia->ojciec;
            if (do_usuniecia->prawy != NULL)
            {
                pomocnik->prawy = do_usuniecia->prawy;
                do_usuniecia->prawy->ojciec = pomocnik;
            }
            else if (do_usuniecia->lewy != NULL)
            {
                pomocnik->lewy = do_usuniecia->lewy;
                do_usuniecia->lewy->ojciec = pomocnik;
            }
            free(do_usuniecia);
            do_usuniecia = NULL;
        }
        else if (do_usuniecia->prawy != NULL && do_usuniecia->lewy != NULL)
        {
            pomocnik = (*Korzen)->lewy;
            pomocnik2 = (*Korzen)->lewy;
            if (*Korzen != do_usuniecia)
            {
                while (pomocnik != NULL)
                {
                    pomocnik = pomocnik->lewy;
                    if (pomocnik != NULL)
                    {
                        pomocnik2 = pomocnik;
                    }
                }
                pomocnik = do_usuniecia->ojciec;
                pomocnik->prawy = pomocnik2;
                pomocnik2->ojciec = pomocnik;
                pomocnik2->prawy = do_usuniecia->prawy;
                pomocnik2->lewy = do_usuniecia->lewy;
                
                if (do_usuniecia->lewy->ojciec != NULL)
                {
                    do_usuniecia->lewy->ojciec = pomocnik2;
                }
                if (do_usuniecia->prawy->ojciec != NULL)
                {
                    do_usuniecia->prawy->ojciec = pomocnik2;
                }

                free(do_usuniecia);
                do_usuniecia = NULL;
            }
            else
            {
                BST_Tree* kopia = *Korzen;
                kopia->prawy = (*Korzen)->prawy;
                kopia->lewy = (*Korzen)->lewy;
                while (pomocnik != NULL)
                {
                    pomocnik = pomocnik->lewy;
                    if (pomocnik != NULL)
                    {
                        pomocnik2 = pomocnik;
                    }
                }
                (kopia)->lewy->ojciec = pomocnik2;
                (kopia)->prawy->ojciec = pomocnik2;
                *Korzen = pomocnik2;
                (*Korzen)->prawy = kopia->prawy;
                (*Korzen)->lewy = kopia->lewy;
                (*Korzen)->ojciec = NULL;
                free(kopia);
                kopia = NULL;
            }
        }
    }
    else
    {
        printf("\nElement o takiej wartosci nie istnieje.");
    }
}

void tableBST(BST_Tree* Korzen)
{
    int h = hBST(Korzen);
    printf("\nTEESTY TABLEBST %d", h);
    bool wykonac = 1;
    int test;
    for (int i = 1; i < h; i++)
    {
        test = countLevBST(Korzen, i);
            if (test != potegowanie(2, i-1))
            {
                wykonac = 0;
            }
    }

    if (wykonac)
    {
        printf("\nWypisuje reprezentacje tablicowa drzewa BST\n");
        LevelOrder(Korzen);
    }
    else
    {
        printf("\nNie mozna wypisac drzewa BST w reprezentacji tablicowej na podstawie przekazanych danych\n");
    }
}

int potegowanie(int liczba, int stopien)
{
    int pomocnik = liczba;
    if (stopien != 0)
    {
        for (int i = 1; i < stopien; i++)
        {
            liczba = liczba * pomocnik;
        }
        return liczba;
    }
    else
    {
        return 1;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file*/
