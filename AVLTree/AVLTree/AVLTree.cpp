#include <stdio.h>
#include <iostream>

using namespace std;

class AVL_Tree
{
public:
    int t1;
    int t2;
    AVL_Tree* lewy;
    AVL_Tree* prawy;
    int wysokosc;
    int bf;
    int max;
};

void InOrder(AVL_Tree* Korzen);
void PreOrder(AVL_Tree* Korzen);
void PostOrder(AVL_Tree* Korzen);
void RysujAVL(AVL_Tree* Korzen);
void printAVL(AVL_Tree* Korzen, int sposob_wypisania);
void wypisz_poziom2(AVL_Tree* Korzen, int lev);
void remALL(AVL_Tree* Korzen);

int max(int a, int b);
int wysokosc_AVL(AVL_Tree* N);
int hAVL(AVL_Tree* Korzen);
int bfAVL(AVL_Tree* Korzen);

AVL_Tree* insertAVL(AVL_Tree* Korzen, int key, int key2);
AVL_Tree* Nowa_Galaz(int key, int key2);
AVL_Tree* RRotation(AVL_Tree* Korzen);
AVL_Tree* LLRotation(AVL_Tree* Korzen);
AVL_Tree* minValueNode(AVL_Tree* Korzen);
AVL_Tree* remAVL(AVL_Tree* Korzen, int key);
AVL_Tree* findAVL(AVL_Tree* Korzen, int dane_do_wyszukania);
AVL_Tree* Znajdz_Przedzial(AVL_Tree* Korzen, int dane_do_wyszukania);
AVL_Tree* Wstawbezrotacji(AVL_Tree* Korzen, int key, int key2);



int main()
{
    AVL_Tree* korzen_glowny = NULL;
    AVL_Tree* znaleziony_wierzcholek = NULL;
    AVL_Tree* znaleziony_przedzial = NULL;
    int tab[200], liczba, sukces = 1;
    int n; //liczba przedzialow

    for (int i = 0; i < 200; i++)
    {
        tab[i] = 0;
    }
    printf("Podaj liczbe n przedzialow: ");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) //do dopisania wpisywanie liczb i zrobienie braku powtorzen dla t1
    {
        liczba = 1 + rand() % 200;
        if (i == 0)
        {
            tab[i] = liczba;
        }
        else
        {
            sukces = 1;
            while (sukces)
            {
                for (int j = 0; j < i; j++)
                {
                    if (liczba == tab[j])
                    {
                        liczba = 1 + rand() % 200;
                        sukces = 1;
                        break;
                    }
                    else
                    {
                        sukces = 0;
                    }
                }
            }
            tab[i] = liczba;
        }
        liczba = 1 + rand() % 200;
        while (tab[i] > liczba)
        {
            liczba = 1 + rand() % 200;
        }
        korzen_glowny = insertAVL(korzen_glowny, tab[i], liczba);
    }

    for (int i = 1; i <= 4; i++)
    {
        printAVL(korzen_glowny, i);
    }

    sukces = 1;
    while (sukces)
    {
        printf("\nKtorzy elemen mam usunac? Podaj wartosc key: ");
        scanf_s("%d", &liczba);
        remAVL(korzen_glowny, liczba);
        for (int i = 1; i <= 4; i++)
        {
            printAVL(korzen_glowny, i);
        }
        printf("\nAby przejsc do dalszej czesci programu podaj wartosc : 0\n");
        scanf_s("%d", &sukces);
    }

    sukces = 1;
    while (sukces)
    {
        printf("\nElement o jakiej wartosci mam znalezc? Podaj key: ");
        scanf_s("%d", &liczba);
        znaleziony_wierzcholek = findAVL(korzen_glowny, liczba);
        printf("\nAby przejsc do dalszej czesci programu podaj wartosc : 0\n");
        scanf_s("%d", &sukces);
    }

    sukces = 1;
    while (sukces)
    {
        printf("\nPodaj liczbe, aby sprawdzic czy moglaby sie znalezc w jednym z przedzialow. Podaj key: ");
        scanf_s("%d", &liczba);
        znaleziony_przedzial = Znajdz_Przedzial(korzen_glowny, liczba);
        printf("\nAby przejsc do dalszej czesci programu podaj wartosc : 0\n");
        scanf_s("%d", &sukces);
    }

    remALL(korzen_glowny); //usuniecie calego drzewa
    korzen_glowny = NULL;
    free(korzen_glowny);

    for (int i = 1; i <= 4; i++)
    {
        printAVL(korzen_glowny, i);
    }

    printf("\nPrezentacja LL rotation. Drzewo poczatkowe:");
    AVL_Tree* prezentacja1 = NULL;
    AVL_Tree* prezentacja2 = NULL;

    for (int i = 1; i <= 3; i++)
    {
        prezentacja1 = Wstawbezrotacji(prezentacja1, i, 0);
    }
    printAVL(prezentacja1, 4);
    printf("\nDrzewo po rotacji LL:");
    for (int i = 1; i <= 3; i++)
    {
        prezentacja2 = insertAVL(prezentacja2, i, 0);
    }
    printAVL(prezentacja2, 4);
    remALL(prezentacja1);
    remALL(prezentacja2);
    prezentacja1 = NULL;
    prezentacja2 = NULL;
    system("PAUSE");

    printf("\nPrezentacja RR rotation. Drzewo poczatkowe:");
    for (int i = 3; i >= 1; i--)
    {
        prezentacja1 = Wstawbezrotacji(prezentacja1, i, 0);
    }
    printAVL(prezentacja1, 4);
    printf("\nDrzewo po rotacji RR:");
    for (int i = 3; i >= 1; i--)
    {
        prezentacja2 = insertAVL(prezentacja2, i, 0);
    }
    printAVL(prezentacja2, 4);
    remALL(prezentacja1);
    remALL(prezentacja2);
    prezentacja1 = NULL;
    prezentacja2 = NULL;
    system("PAUSE");

    printf("\nPrezentacja RL rotation. Drzewo poczatkowe:");
    prezentacja1 = Wstawbezrotacji(prezentacja1, 5, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 3, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 8, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 10, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 9, 0);
    printAVL(prezentacja1, 4);
    printf("\nDrzewo po rotacji RL:");
    prezentacja2 = insertAVL(prezentacja2, 5, 0);
    prezentacja2 = insertAVL(prezentacja2, 3, 0);
    prezentacja2 = insertAVL(prezentacja2, 8, 0);
    prezentacja2 = insertAVL(prezentacja2, 10, 0);
    prezentacja2 = insertAVL(prezentacja2, 9, 0);
    printAVL(prezentacja2, 4);
    remALL(prezentacja1);
    remALL(prezentacja2);
    prezentacja1 = NULL;
    prezentacja2 = NULL;
    system("PAUSE");

    printf("\nPrezentacja LR rotation. Drzewo poczatkowe:");
    prezentacja1 = Wstawbezrotacji(prezentacja1, 10, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 5, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 11, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 3, 0);
    prezentacja1 = Wstawbezrotacji(prezentacja1, 4, 0);
    printAVL(prezentacja1, 4);
    printf("\nDrzewo po rotacji RL:");
    prezentacja2 = insertAVL(prezentacja2, 10, 0);
    prezentacja2 = insertAVL(prezentacja2, 5, 0);
    prezentacja2 = insertAVL(prezentacja2, 11, 0);
    prezentacja2 = insertAVL(prezentacja2, 3, 0);
    prezentacja2 = insertAVL(prezentacja2, 4, 0);
    printAVL(prezentacja2, 4);
    remALL(prezentacja1);
    remALL(prezentacja2);
    prezentacja1 = NULL;
    prezentacja2 = NULL;

    return 0;
}

void PreOrder(AVL_Tree* Korzen)
{
    if (Korzen != NULL)
    {
        printf("<%d;%d> bf: %d ", Korzen->t1, Korzen->t2, Korzen->bf);
        PreOrder(Korzen->lewy);
        PreOrder(Korzen->prawy);
    }
}

void PostOrder(AVL_Tree* Korzen)
{
    if (Korzen != NULL)
    {
        PostOrder(Korzen->lewy);
        PostOrder(Korzen->prawy);
        printf("<%d;%d>  ", Korzen->t1, Korzen->t2);
    }
}

void InOrder(AVL_Tree* Korzen)
{
    if (Korzen != NULL)
    {
        InOrder(Korzen->lewy);
        printf("<%d;%d>  ", Korzen->t1, Korzen->t2);
        InOrder(Korzen->prawy);
    }
}

int wysokosc_AVL(AVL_Tree* N)
{
    if (N == NULL)
        return 0;
    return N->wysokosc;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void printAVL(AVL_Tree* Korzen, int sposob_wypisania)
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

        case 4: //podglad struktury
            printf("\nWypisanie struktury drzewa: \n");
            RysujAVL(Korzen);
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

void RysujAVL(AVL_Tree* Korzen)
{
    int h = hAVL(Korzen);
    int zamiennik = h;

    for (int i = 0; i <= h; i++)
    {

        for (int j = zamiennik; j >= 0; j--)
        {
            printf("     ");
        }
        wypisz_poziom2(Korzen, i);
        printf("\n\n");
        zamiennik--;
    }

}

int hAVL(AVL_Tree* Korzen)
{

    if (Korzen != NULL)
    {
        int L_AVL = hAVL(Korzen->lewy);
        int P_hAVL = hAVL(Korzen->prawy);

        if (L_AVL > P_hAVL)
        {
            return (L_AVL + 1);
        }
        else
        {
            return (P_hAVL + 1);
        }
    }
    else
    {
        return 0;
    }
}


void wypisz_poziom2(AVL_Tree* Korzen, int lev)
{
    if (Korzen == NULL)
    {
        printf("     ");
        return;
    }
    if (lev == 1)
    {
        printf("   <%d;%d>   ", Korzen->t1, Korzen->t2);
    }
    else if (lev > 1)
    {
        wypisz_poziom2(Korzen->lewy, lev - 1);
        wypisz_poziom2(Korzen->prawy, lev - 1);
    }

}

AVL_Tree* Nowa_Galaz(int key, int key2)
{
    AVL_Tree* wierzcholek = new AVL_Tree();
    wierzcholek->t1 = key;
    wierzcholek->t2 = key2;
    wierzcholek->lewy = NULL;
    wierzcholek->prawy = NULL;
    wierzcholek->wysokosc = 1;

    return(wierzcholek);
}

AVL_Tree* RRotation(AVL_Tree* Korzen)
{
    AVL_Tree* dziecko = Korzen->lewy;
    AVL_Tree* dziecko2 = dziecko->prawy;

    dziecko->prawy = Korzen;
    Korzen->lewy = dziecko2;

    Korzen->wysokosc = max(wysokosc_AVL(Korzen->lewy), wysokosc_AVL(Korzen->prawy)) + 1;
    dziecko->wysokosc = max(wysokosc_AVL(dziecko->lewy), wysokosc_AVL(dziecko->prawy)) + 1;

    return dziecko;
}

AVL_Tree* LLRotation(AVL_Tree* Korzen)
{
    AVL_Tree* dziecko = Korzen->prawy;
    AVL_Tree* dziecko2 = dziecko->lewy;

    dziecko->lewy = Korzen;
    Korzen->prawy = dziecko2;

    Korzen->wysokosc = max(wysokosc_AVL(Korzen->lewy), wysokosc_AVL(Korzen->prawy)) + 1;
    dziecko->wysokosc = max(wysokosc_AVL(dziecko->lewy), wysokosc_AVL(dziecko->prawy)) + 1;

    return dziecko;
}

AVL_Tree* minValueNode(AVL_Tree* Korzen)
{
    AVL_Tree* obecny_wierzcholek = Korzen;

    while (obecny_wierzcholek->lewy != NULL)
        obecny_wierzcholek = obecny_wierzcholek->lewy;

    return obecny_wierzcholek;
}


AVL_Tree* remAVL(AVL_Tree* Korzen, int key)
{

    if (Korzen == NULL)
    {
        return Korzen;
    }

    if (key < Korzen->t1)
    {
        Korzen->lewy = remAVL(Korzen->lewy, key);
    }
    else if (key > Korzen->t1)
    {
        Korzen->prawy = remAVL(Korzen->prawy, key);
    }
    else
    {
        if ((Korzen->lewy == NULL) ||
            (Korzen->prawy == NULL))
        {
            AVL_Tree* temp = Korzen->lewy ?
                Korzen->lewy :
                Korzen->prawy;

            if (temp == NULL)
            {
                temp = Korzen;
                Korzen = NULL;
            }
            else
            {
                *Korzen = *temp;
            }
            free(temp);
        }
        else
        {
            AVL_Tree* temp = minValueNode(Korzen->prawy);
            Korzen->t1 = temp->t1;
            Korzen->prawy = remAVL(Korzen->prawy, temp->t1);
        }
    }
    if (Korzen == NULL)
    {
        return Korzen;
    }

    Korzen->wysokosc = 1 + max(wysokosc_AVL(Korzen->lewy), wysokosc_AVL(Korzen->prawy));
    int wsp_zbalansowania = bfAVL(Korzen);

    if (wsp_zbalansowania > 1 && bfAVL(Korzen->lewy) >= 0)
    {
        return RRotation(Korzen);
    }

    if (wsp_zbalansowania > 1 && bfAVL(Korzen->lewy) < 0)
    {
        Korzen->lewy = LLRotation(Korzen->lewy);
        return RRotation(Korzen);
    }

    if (wsp_zbalansowania < -1 && bfAVL(Korzen->prawy) <= 0)
    {
        return LLRotation(Korzen);
    }

    if (wsp_zbalansowania < -1 && bfAVL(Korzen->prawy) > 0)
    {
        Korzen->prawy = RRotation(Korzen->prawy);
        return LLRotation(Korzen);
    }
    Korzen->bf = bfAVL(Korzen);
    return Korzen;
}

AVL_Tree* insertAVL(AVL_Tree* Korzen, int key, int key2)
{

    if (Korzen == NULL)
    {
        return(Nowa_Galaz(key, key2));
    }

    if (key < Korzen->t1)
    {
        Korzen->lewy = insertAVL(Korzen->lewy, key, key2);
    }
    else if (key > Korzen->t1)
    {
        Korzen->prawy = insertAVL(Korzen->prawy, key, key2);
    }
    else
    {
        return Korzen;
    }

    Korzen->wysokosc = 1 + max(wysokosc_AVL(Korzen->lewy),
        wysokosc_AVL(Korzen->prawy));

    int wsp_zbalansowania = bfAVL(Korzen);

    if (wsp_zbalansowania > 1 && key < Korzen->lewy->t1)
    {
        return RRotation(Korzen);
    }
    if (wsp_zbalansowania < -1 && key > Korzen->prawy->t1)
    {
        return LLRotation(Korzen);
    }
    if (wsp_zbalansowania > 1 && key > Korzen->lewy->t1)
    {
        Korzen->lewy = LLRotation(Korzen->lewy);
        return RRotation(Korzen);
    }
    if (wsp_zbalansowania < -1 && key < Korzen->prawy->t1)
    {
        Korzen->prawy = RRotation(Korzen->prawy);
        return LLRotation(Korzen);
    }

    Korzen->bf = bfAVL(Korzen);
    return Korzen;
}

int bfAVL(AVL_Tree* N)
{
    if (N == NULL)
        return 0;
    return wysokosc_AVL(N->lewy) - wysokosc_AVL(N->prawy);
}

AVL_Tree* findAVL(AVL_Tree* Korzen, int dane_do_wyszukania)
{
    AVL_Tree* pomocnik = Korzen;
    int wartosc_liscia = Korzen->t1;

    while (Korzen != NULL)
    {
        if (dane_do_wyszukania == wartosc_liscia)
        {
            printf("\nWypisuje parametry odnalezionego wezla:\n");
            printf("Przedzial: <%d;%d>\tmax el: %d\t wspolczynnik bf: %d", Korzen->t1, Korzen->t2, Korzen->max, Korzen->bf);
            if (Korzen->lewy == NULL)
            {
                printf("\nWyszukany element nie ma lewego brata");
            }
            else
            {
                printf("\nWypisuje parametry lewego brata:\t");
                printf("Przedzial: <%d;%d>\tmax el: %d\t wspolczynnik bf: %d", Korzen->lewy->t1, Korzen->lewy->t2, Korzen->lewy->max, Korzen->lewy->bf);
            }
            if (Korzen->prawy == NULL)
            {
                printf("\nWyszukany element nie ma prawego brata");
            }
            else
            {
                printf("\nWypisuje parametry prawego brata:\t");
                printf("Przedzial: <%d;%d>\tmax el: %d\t wspolczynnik bf: %d", Korzen->prawy->t1, Korzen->prawy->t2, Korzen->prawy->max, Korzen->prawy->bf);
            }
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
                wartosc_liscia = Korzen->t1;
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
                wartosc_liscia = Korzen->t1;
            }
        }
    }

    if (pomocnik->t1 != dane_do_wyszukania)
    {
        printf("\nNie odnaleziono szukanej wartosci. Funkcja zwroci NULL\n");
        return NULL;
    }
}

void remALL(AVL_Tree* Korzen)
{
    if (Korzen != NULL)
    {
        remALL(Korzen->lewy);
        remALL(Korzen->prawy);
        Korzen->lewy = NULL;
        Korzen->prawy = NULL;
        Korzen = NULL;
        free(Korzen);
    }
}

AVL_Tree* Znajdz_Przedzial(AVL_Tree* Korzen, int dane_do_wyszukania)
{
    AVL_Tree* pomocnik = Korzen;
    int wartosc_liscia = Korzen->t1;

    while (Korzen != NULL)
    {
        if (Korzen->t1 <= dane_do_wyszukania && Korzen->t2 >= dane_do_wyszukania)
        {
            printf("\nWypisuje parametry odnalezionego wezla:\n");
            printf("Przedzial: <%d;%d>\tmax el: %d\t wspolczynnik bf: %d", Korzen->t1, Korzen->t2, Korzen->max, Korzen->bf);
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
                wartosc_liscia = Korzen->t1;
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
                wartosc_liscia = Korzen->t1;
            }
        }
    }

    if (pomocnik->t1 != dane_do_wyszukania)
    {
        printf("\nNie odnaleziono szukanej wartosci. Funkcja zwroci NULL\n");
        return NULL;
    }
}

AVL_Tree* Wstawbezrotacji(AVL_Tree* Korzen, int key, int key2)
{

    if (Korzen == NULL)
    {
        return(Nowa_Galaz(key, key2));
    }

    if (key < Korzen->t1)
    {
        Korzen->lewy = Wstawbezrotacji(Korzen->lewy, key, key2);
    }
    else if (key > Korzen->t1)
    {
        Korzen->prawy = Wstawbezrotacji(Korzen->prawy, key, key2);
    }
    else
    {
        return Korzen;
    }

    Korzen->wysokosc = 1 + max(wysokosc_AVL(Korzen->lewy),
        wysokosc_AVL(Korzen->prawy));
    Korzen->bf = bfAVL(Korzen);

    return Korzen;
}