#pragma hdrstop

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

typedef struct Element_Listy
{
	struct Element_Listy* next;
	struct Element_Listy* prev;
	int dane; // dane
	int priorytet;
	int licznik = 0;
}T_ListaD;


void addQuel(T_ListaD** head, int key, int priority);
int sizeQuel(T_ListaD* head);
void printQuel(T_ListaD* head);
int isEmptyQ1(T_ListaD* head);
int isEmptyQ2(T_ListaD* head);
void fromQuel(T_ListaD** head);
void wypisanie_out(T_ListaD* head);

int _tmain(int argc, _TCHAR* argv[])
{
	int ile_kolejek; // ilosc kolejek priorytetowych
	int dl_kolejki; // dlugosc kolejki
	int ile; //losowa ilosc elementow do wpisania przy pierwszej inicjalizacji tabveli
	int priorytet;
	int dana;
	int tabela_wej[3];
	int tabela_pr[3];
	int skad_usunac;
	int out_pr;
	int out_liczba;
	int gdzie, pomocnik;
	bool straznik = 1;
	int licznik;

	printf("Podaj ilosc kolejek priorytetowych: ");
	scanf_s("%i", &ile_kolejek);
	dl_kolejki = 3 * ile_kolejek;

	T_ListaD** tab_list = (T_ListaD**)malloc(sizeof(T_ListaD*) * ile_kolejek); //alokacja tablicy wskaznikow na listy

	int* ile_jest_elementow = (int*)malloc(sizeof(int) * ile_kolejek);
	int* obsluga_elementu = (int*)malloc(sizeof(int) * ile_kolejek);
	int* obsluga_wyjscia_elementu_pr = (int*)malloc(sizeof(int) * ile_kolejek);

	for (int i = 0; i < ile_kolejek; i++)
	{
		tab_list[i] = NULL;
	}
	//wstepna inicjalizacja tabeli:
	printf("Wstepna inicjalizacja tabeli: \n");
	for (int i = 0; i < ile_kolejek; i++)
	{
		ile = rand() % (dl_kolejki + 1);
		for (int j = 0; j < ile; j++)
		{
			dana = 1 + rand() % 99;
			priorytet = 1 + rand() % dl_kolejki;
			addQuel(&tab_list[i], dana, priorytet);
		}
	}

	//-------pierwsze wyswietlenie tabeli---------------
	for (int i = 0; i < ile_kolejek; i++)
	{
		ile_jest_elementow[i] = sizeQuel(tab_list[i]);

		for (int j = 0; j < dl_kolejki - ile_jest_elementow[i]; j++)
		{
			printf("-\t");
		}
		printQuel(tab_list[i]);
		if (ile_jest_elementow[i] == 0)
		{
			printf("\tEMPTY\n");
		}
		else if (ile_jest_elementow[i] < dl_kolejki)
		{
			printf("\tOK\n");
		}
		else
		{
			printf("\tWAIT\n");
		}
		obsluga_elementu[i] = isEmptyQ1(tab_list[i]);
	}
	//------------------------------------------------------------------
	while (straznik)
	{

		printf("\nin:\t");
		for (int i = 0; i < 3; i++)
		{
			tabela_wej[i] = 1 + rand() % 99;
			tabela_pr[i] = 1 + rand() % dl_kolejki;
			printf("%d(%d), ", tabela_wej[i], tabela_pr[i]);
		}

		out_pr = 0;
		skad_usunac = 0;
		licznik = 0;
		for (int i = 0; i < ile_kolejek; i++)
		{

			if (out_pr < obsluga_elementu[i])
			{
				out_pr = obsluga_elementu[i];
				skad_usunac = i;
			}
		}

		for (int i = 0; i < ile_kolejek; i++)
		{
			if (out_pr == obsluga_elementu[i])
			{
				obsluga_wyjscia_elementu_pr[licznik] = i;
				licznik++;
			}
		}
//----------------------------randomizacja wyjscia---------------------------------------------------
		if (licznik == 1)									
		{
			wypisanie_out(tab_list[skad_usunac]);
			printf("\n");
			fromQuel(&tab_list[skad_usunac]);
		}
		else
		{
			out_pr = rand()%licznik;
			skad_usunac = obsluga_wyjscia_elementu_pr[out_pr];
			wypisanie_out(tab_list[skad_usunac]);
			printf("\n");
			fromQuel(&tab_list[skad_usunac]);
		}
//----------------------------------------------------------------------------------------------------
		for (int i = 0; i < 3; i++)
		{
			gdzie = 0;
			pomocnik = ile_jest_elementow[0];
			for (int j = 0; j < ile_kolejek; j++)
			{
				if (pomocnik > ile_jest_elementow[j])
				{
					pomocnik = ile_jest_elementow[j];
					gdzie = j;
				}
			}
		
			if (ile_jest_elementow[gdzie] < dl_kolejki)
			{
				addQuel(&tab_list[gdzie], tabela_wej[i], tabela_pr[i]);
			}
			ile_jest_elementow[gdzie] = sizeQuel(tab_list[gdzie]);
		}
			
		//-------druga wyswietlenie tabeli---------------
			for (int i = 0; i < ile_kolejek; i++)
			{
				ile_jest_elementow[i] = sizeQuel(tab_list[i]);

				obsluga_elementu[i] = isEmptyQ1(tab_list[i]);
				for (int j = 0; j < dl_kolejki - ile_jest_elementow[i]; j++)
				{
					printf("-\t");
				}
				printQuel(tab_list[i]);
				if (ile_jest_elementow[i] == 0)
				{
					printf("\tEMPTY\n");
				}
				else if (ile_jest_elementow[i] < dl_kolejki)
				{
					printf("\tOK\n");
				}
				else
				{
					printf("\tWAIT\n");
				}
			}
			//------------------------------------------------------------------
		printf("\nJezeli chcesz zakonczyc dzialanie wpisz 0 na klawiaturze: ");
		scanf_s("%d", &straznik);
		}

	free(ile_jest_elementow);
	free(tab_list);
	free(obsluga_elementu);
	free(obsluga_wyjscia_elementu_pr);

	tab_list = NULL;
	ile_jest_elementow = NULL;
	obsluga_elementu = NULL;
	obsluga_wyjscia_elementu_pr = NULL;
	return 0;
}


void wypisanie_out(T_ListaD* head)
{
	printf("\nout: %d(%d)\t", head->dane, head->priorytet);
}

int sizeQuel(T_ListaD* head)
{
	int ilosc_elem = 0;
	if (head != NULL) {
		while (head != NULL)
		{
			ilosc_elem++;
			head = head->next;
		}
		return ilosc_elem;
	}
	else
	{
		return ilosc_elem;
	}
}

void printQuel(T_ListaD* head)
{	
	T_ListaD* straznik = head;
	while (head != NULL)
	{	
		straznik = head;
		head = head->next;	
	}
	while (straznik != NULL)
	{
		printf("%d(%d)\t", straznik->dane, straznik->priorytet);
		straznik = straznik->prev;
	}
}

int isEmptyQ1(T_ListaD* head)
{
	if (head != NULL)
	{
		return head->priorytet;
	}
	else
	{
		return 0;
	}
}

int isEmptyQ2(T_ListaD* head)
{
	if (head != NULL)
	{
		return head->dane;
	}
	else
	{
		return 0;
	}
}

void fromQuel(T_ListaD** head)
{
	T_ListaD* pomocnik = *head;
	if ((*head)->next == NULL)
	{
		pomocnik = *head;
		*head = NULL;
		free(pomocnik);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(pomocnik);
	}
}

void addQuel(T_ListaD** head, int key, int priority)
{
	T_ListaD* nowa = (T_ListaD*)malloc(sizeof(T_ListaD));
	if (*head == NULL)
	{
		(*head) = nowa;
		nowa->dane = key;
		nowa->priorytet = priority;
		nowa->next = NULL;
		nowa->prev = NULL;

	}
	else
	{
		T_ListaD* straznik = *head;
		while ((*head)->next != NULL)
		{
			*head = (*head)->next;
		}
		nowa->prev = *head;
		nowa->dane = key;
		nowa->priorytet = priority;
		nowa->next = NULL;
		(*head)->next = nowa;
		*head = straznik;
	}
}