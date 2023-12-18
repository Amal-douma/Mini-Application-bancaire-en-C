// gestionBanque.h

#ifndef GESTIONBANQUE_H
#define GESTIONBANQUE_H

#define CMAX 10

typedef struct SClient
{
    int Code_cli;
    char Nom[CMAX];
    char Prenom[CMAX];
} SClient;

typedef struct Date
{
    int Jour;
    int Mois;
    int Annee;
} Date;

typedef struct SCompte
{
    int code_cpt;
    int code_cli;
    int somme;
    struct Date d_compte;
} SCompte;

extern int nbClient;
extern SClient clients[20];
extern SCompte comptes[20];

void menu();
void sous_menu(int a);
void gere_client(int a);
void gere_compte(int a);
void gere_Operation(int a);
int comparer(const void *a, const void *b); //prend deux pointeur a et b de type sclient //Utilisée par la fonction de tri qsort pour trier le tableau de clients par ordre alphabétique du nom
int codeClientExisteDeja(int codeClient);
int codeCompteExisteDeja(int codeCompte);
int codeClientExisteDansTableau(int codeClient);
#endif
