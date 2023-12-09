#include <stdio.h>
#include <stdlib.h>
#define CMAX 10 // Constante
int x, choix;
//structure
typedef struct SClient
{
    int Code_cli;
    char Nom [CMAX];
    char Prenom [CMAX];
}SClient;


int comparer (const void* a, const void* b)
{
    const SClient *c1 = a ;
    const SClient *c2 = b ;
    return strcmp(c1->Nom, c2->Nom); // comparer deux string et retourner les premiere en ordre alphabetique
}

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
     int somme ;
     struct Date d_compte ;
 }SCompte;

// Tableau de compte et tableau de client
SClient clients[20];
SCompte comptes[20];

// Menu
 void menu ()
{
    while(choix != 4){
        printf("\n");
        printf("1- Gestion des clients\n");
        printf("2- Gestion des comptes\n");
        printf("3- Gestion des operations\n");
        printf("4- Quitter le programme\n");
        printf("Choisir le menu : ");
        scanf("%d", &choix );
        sous_menu(choix);
    }


}

// SOus menu
/*void sous_menu(int a)
{
    if (a==1)
    {
        printf("1- Ajouter Client\n");
        printf("2- Modifier Client\n");
        printf("3- Supprimer Client\n");
        printf("4- Afficher Client\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d",&x);
        gere_client(x);
    }else if (a==2)
    {
        printf("1- Ajouter Compte\n");
        printf("2- Rechercher Compte\n");
        printf("3- Afficher la liste Compte\n");
        printf("4- Supprimer comptes\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d",&x);
        //gere_compte(x);

    }else if (a==3)
    {
        printf("1- Retrait d'argent\n");
        printf("2- Versement d'argent\n");
        printf("3- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d",&x);
        //gere_Operation(x);
    } else if (a==4)
    {
        printf("Au revoir");
        return 0;

    }else
    {
        printf("Mauvais choix\n ");
       printf("Choisir le menu : ");
        scanf("%d", &choix );
        sous_menu(choix);
    }
}
*/


void sous_menu(int a)
{
    switch (a)
    {
    case 1:
        printf("1- Ajouter Client\n");
        printf("2- Modifier Client\n");
        printf("3- Supprimer Client\n");
        printf("4- Afficher Client\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gere_client(x);
        break;
    case 2:
        printf("1- Ajouter Compte\n");
        printf("2- Rechercher Compte\n");
        printf("3- Afficher la liste Compte\n");
        printf("4- Supprimer comptes\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
         gere_compte(x);
        break;
    case 3:
        printf("1- Retrait d'argent\n");
        printf("2- Versement d'argent\n");
        printf("3- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gere_Operation(x);
        break;
    case 4:
        printf("Au revoir\n");
        exit(0); // Quitter le programme
        break;
    default:
        printf("Mauvais choix\n");
        printf("Choisir le menu : ");
        scanf("%d", &choix);
        sous_menu(choix);
    }
}

// Gestion de client
void gere_client(int a )
{
    //Ajoute Client
    /*if (a==1)
    {
      struct SClient client;
      FILE *file ;

      printf("Code Client :" );
      scanf("%d",&client.Code_cli);
      printf("Nom Client :" );
      scanf("%s",&client.Nom);
      printf("Prenom Client :" );
      scanf("%s",&client.Prenom);

      file =fopen("client.txt","a");
      fwrite(&client,sizeof(client),1,file);
      if (fwrite !=0)
          printf("Client ajouter avec succes");
      else
          printf("erreur");
      fclose(file);
    }
*/
int codeClientExisteDeja(int codeClient)
{
    FILE *file = fopen("client.txt", "r");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 0; // Considérons qu'il n'existe pas de code client s'il y a une erreur lors de l'ouverture du fichier
    }

    struct SClient client;

    while (fread(&client, sizeof(client), 1, file) == 1)
    {
        if (client.Code_cli == codeClient)
        {
            fclose(file);
            return 1; // Code client trouvé
        }
    }

    fclose(file);
    return 0; // Code client non trouvé
}

if (a == 1)
     {
        struct SClient *client = malloc(sizeof(struct SClient)); // Allouer de la mémoire pour le client
        FILE *file;

        // Vérifier si le code client existe déjà
        do
        {
            printf("Code Client : ");
            scanf("%d", &client->Code_cli);

            if (codeClientExisteDeja(client->Code_cli))
            {
                printf("Le code client existe deja. Veuillez en choisir un autre.\n");
            }

        } while (codeClientExisteDeja(client->Code_cli));

        printf("Nom Client : ");
        scanf("%s", client->Nom);
        printf("Prenom Client : ");
        scanf("%s", client->Prenom);

        file = fopen("client.txt", "a");
        if (file != NULL)
        {
            fwrite(client, sizeof(struct SClient), 1, file);
            printf("Client ajoute avec succes\n");
            fclose(file);
        }
        else
        {
            printf("Erreur lors de l'ouverture du fichier\n");
        }

        free(client); // Libérer la mémoire allouée pour le client
    }

//MoDIFICATION CLIENT
      else if (a==2)
      {
          struct SClient client;
          struct SClient nvClient;
          FILE *file;

          printf("Code client a modifier : "); //identifier du client qui modifier
          scanf("%d",&nvClient.Code_cli);
          printf("Nouveau  Nom Client ");
          scanf("%s",&nvClient.Nom);
          printf("Nouveau  Prenom Client ");
          scanf("%s",&nvClient.Prenom);

          file=fopen("client.txt","r");

            int nbClient=0;

            while(fread(&client,sizeof(struct SClient),1,file))
            {
            clients[nbClient]=client;
            nbClient++;
             }
            fclose(file);
            remove("client.txt"); // supprimer tableau et toute les information dans un tableau

            FILE * nf;
            nf=fopen("nv.txt","a"); // new fichier a pour existe nv fichier
            for(int i=0 ; i<nbClient;i++)
            {
                if(clients[i].Code_cli==nvClient.Code_cli)
                     fwrite(&nvClient,sizeof(clients[i]),1,nf);
                else
                     fwrite(&clients[i],sizeof(clients[i]),1,nf);
            }
            fclose(nf);
            rename("nv.txt","client.txt");


      }
      //Suprimmer client


    /*  else if (a==3)
      {
          struct SClient client;
          int code;
          FILE *file;

          printf("Code client a supprimer : "); //identifier du client qui modifier
          scanf("%d",&code);

          file=fopen("client.txt","r");

            int nbClient=0;

            while(fread(&client,sizeof(struct SClient),1,file))
            {
            clients[nbClient]=client;
            nbClient++;
             }

            fclose(file);
            remove("client.txt"); // supprimer tableau et toute les information dans un tableau

            FILE * nf;
            nf=fopen("nv.txt","a"); // new fichier a pour existe nv fichier
            for(int i=0 ; i<nbClient;i++)
            {
                if(clients[i].Code_cli!= code)
                     fwrite(&clients[i],sizeof(clients[i]),1,nf);
                     printf("Suprimer avec succes");
            }
            fclose(nf);
            rename("nv.txt","client.txt");
      }
*/

else if (a == 3)
{
    FILE *file;
    struct SClient client;
    int code;

    printf("Code client a supprimer : ");
    scanf("%d", &code);

    file = fopen("client.txt", "r");

    int nbClient = 0;

    while (fread(&client, sizeof(struct SClient), 1, file))
    {
        clients[nbClient] = client;
        nbClient++;
    }
    fclose(file);
    remove("client.txt");

    FILE *nf;
    nf = fopen("nv.txt", "a");
    struct SClient *ptrClient = clients;   // pointeur pour parcourir tableau client
    for (int i = 0; i < nbClient; i++, ptrClient++)
    {
        if (ptrClient->Code_cli != code)
        {
            fwrite(ptrClient, sizeof(struct SClient), 1, nf);
            printf("Supprimer avec succes\n");
        }
    }
    fclose(nf);
    rename("nv.txt", "client.txt");
}
    //Affichage des Client
    else if (a==4)
    {
        FILE *file;
        struct SClient client;
        file=fopen("client.txt","r"); //only read

        int nbClient=0; // remplissage fichier dans un tableau
        while(fread(&client,sizeof(struct SClient),1,file)){
            clients[nbClient]=client;
            nbClient++;
        }
        fclose(file);

        //sizeof struct eli mkhazna f table atheka
        qsort(clients,nbClient,sizeof(SClient),comparer);
        for (int c=0; c<nbClient; c++)
        {
            printf("\nCode Client : %d", clients[c].Code_cli);
            printf("\nNom Client : %s", clients[c].Nom);
            printf("\nPrenom Client : %s", clients[c].Prenom);
            printf("\n");
        }
    }
    else if (a==5)
    {
        menu();
    }
}


void gere_compte(int a)
{
    // Ajouter Compte
    if (a==1)
    {
        struct SCompte compte;
        FILE *file;

        printf("Code Compte : ");
        scanf("%d", &compte.code_cpt);
        printf("Code Client : ");
        scanf("%d", &compte.code_cli);
        printf("Somme Compte : ");
        scanf("%d", &compte.somme);

        do
        {
            printf("Jour (entre 1 et 30) : ");
            scanf("%d", &compte.d_compte.Jour);
        } while (compte.d_compte.Jour < 1 || compte.d_compte.Jour > 30);

        do
        {
            printf("Mois (entre 1 et 12) : ");
            scanf("%d", &compte.d_compte.Mois);
        } while (compte.d_compte.Mois < 1 || compte.d_compte.Mois > 12);

        do
        {
            printf("Annee (4 chiffres) : ");
            scanf("%d", &compte.d_compte.Annee);
        } while (compte.d_compte.Annee < 1000 || compte.d_compte.Annee > 9999);

        file = fopen("compte.txt", "a");
        fwrite(&compte, sizeof(compte), 1, file);

        if(fwrite != 0)
            printf("compte ajoute avec succes");
        else
            printf("erreur");
        fclose(file);
    }
    // Rechercher  un Compte
    else if (a==2)
    {
        struct SCompte compte;
        int code;
        FILE *file;

        printf("Code compte : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");
        int found = 0;
        while(fread(&compte, sizeof(struct SCompte), 1, file) && found == 0) {
            if (compte.code_cpt == code)
               {
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code client : %d", compte.code_cli);
                    printf("\n Somme Compte: %d", compte.somme);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    //printf("\n Somme %d", compte.somme);
                    found = 1 ;
               }
        }
        if(found == 0)
            printf("code non existant\n");
        fclose(file);
    }

    //AFFFICHAGE DES COMPTES

    else if (a==3)
    {

        {
        struct SCompte compte;
        FILE *file;

        file = fopen("compte.txt", "r");

        while(fread(&compte, sizeof(struct SCompte), 1, file)) {
               {
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code client : %d", compte.code_cli);
                    printf("\n Somme Compte: %d", compte.somme);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    printf("\n---------------------------------------");
               }
        }
        fclose(file);
    }
    }

    //SUprrimer compte
    if (a==4)
    /*{ {
        struct SCompte compte;
        int code;
        FILE *file;

        printf("Code Compte a supprimer : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte, sizeof(struct SCompte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt != code)
                fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }*/

    {
    FILE *file;
    struct SCompte compte;
    int code;

    printf("Code compte a supprimer : ");
    scanf("%d", &code);

    file = fopen("compte.txt", "r");

    int nb = 0;

    while (fread(&compte, sizeof(struct SCompte), 1, file))
    {
        comptes[nb] = compte;
        nb++;
    }
    fclose(file);
    remove("compte.txt");

    FILE *nf;
    nf = fopen("nv.txt", "a");
    struct SCompte *ptrCompte = comptes;   // pointeur pour parcourir tableau client
    for (int i = 0; i < nb; i++, ptrCompte++)
    {
        if (ptrCompte->code_cpt != code)
        {
            fwrite(ptrCompte, sizeof(struct SCompte), 1, nf);
            printf("Supprimer avec succes\n");
        }
    }
    fclose(nf);
    rename("nv.txt", "compte.txt");
}
//Retour
else if (a==5)
    {
        menu();
    }
}

// gestion des operation
 gere_Operation(int a)
 {
     // Retrait d'argent
        if (a==1)
    {
        struct SCompte compte;
        int code,m,solde;
        FILE *file;

        printf("Code Compte : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte, sizeof(struct SCompte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt == code)
            {
                        do{
                            printf("\n montant : ");
                            scanf("%d", &m);
                            if (m>500)
                                printf("\n le montant ne doit pas depasser 500 DT");
                            solde = comptes[i].somme - m;
                            if (solde<250)
                                printf("\n le solde ne doit pas etre inferieur a 250 DT");
                        }while(m>500 || solde<250);
                comptes[i].somme = comptes[i].somme - m;
                printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }
    //Versement d'argent
    else if (a==2)
    {
       struct SCompte compte;
        int code1,code2,m,solde;
        FILE *file;

        printf("Code Compte de depart : ");
        scanf("%d", &code1);

        printf("Code compte d'arrivee : ");
        scanf("%d", &code2);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte, sizeof(struct SCompte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt == code1)
            {
                        do{
                            printf("\n montant : ");
                            scanf("%d", &m);
                            if (m>500)
                                printf("\n le montant ne doit pas depasser 500 DT");
                            solde = comptes[i].somme - m;
                            if (solde<250)
                                printf("\n le solde ne doit pas etre inferieur a 250 DT");
                        }while(m>500 || solde<250);
                comptes[i].somme = comptes[i].somme - m;
                printf(" compte depart : ");
                printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            else if (comptes[i].code_cpt == code2)
            {
                comptes[i].somme = comptes[i].somme + m;

                printf(" compte d'arrivée :");
                 printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");

    }


     //RETOUR
     else if (a==3)
    {
        menu();
    }

 }


int main()
{
   menu() ;
   return 0;
}
