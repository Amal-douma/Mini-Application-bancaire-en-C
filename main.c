#include <stdio.h>
#include <stdlib.h>
#define CMAX 10 // Constante

//structure
typedef struct SClient
{
    int Code_cli;
    char Nom [CMAX];
    char Prenom [CMAX];
}SClient;

 typedef struct Date
 {
     int Jour ;
     int Mois ;
     int Annee;
 }Date ;

 typedef struct SCompte
 {
     int code_cpt;
     int code_cli;  //forignkey
     struct Date d_compte ;
 }

// Tableau de compte et tableau de client
SClient clients[20];
SCompte comptes[20];

int main()
{
    printf("Hello world!\n");
    return 0;
}
