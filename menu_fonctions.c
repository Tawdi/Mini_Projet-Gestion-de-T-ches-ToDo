#include"head.h"
// #include"ajoute_fonctions.c"

void menu()
{
    char choix[20];
    printf(" \n******************************************************************** ");

    printf(" \n        ========= Systeme de Gestion de Tahes ToDo  =========         ");
    printf(" \n******************************************************************** ");

    printf("\n**       1 : Ajouter une nouvelle tache.                           **    ");
    printf("\n**       2 : Afficher la liste de toutes les taches.               **    ");
    printf("\n**       3 : Rechercher les taches.                                **    ");
    printf("\n**       4 : Modifier une tache.                                   **    ");
    printf("\n**       5 : Supprimer une tache.                                  **    ");
    printf("\n**       6 : Statistiques.                                         **    ");
    printf("\n**       0 : Exit.                                                 **    ");

    // do
    // {
        printf(" \n\nvotre choix  :");
    scanf(" %[^\n]", choix);
    getchar();
    // } while (choix<1 || choix>6);
    
    

    switch (choix[0])
    {
    case '1':
         system("cls");
        //   printf("\nAjouter une nouvelle tache.");
          ajoute_un_tache();
        break;
    case '2':
         system("cls");
        // printf("\n2 : Afficher la liste de toutes les taches.   ");
        // Afficher_tous_taches_par_user_id(1);
        Afficher_tous_taches();
        break;
    case '3':
         system("cls");
        // printf("\n3 : Rechercher les taches.    ");
        Rechercher_un_tache_par_titre();
        break;
    case '4':
         system("cls");
        // printf("\n4 : Modifier une tache.    ");
        Modifier_un_tache_par_titre();
    
        break;
    case '5':
         system("cls");
        // printf("\n5 : Supprimer une tache.    ");
        Supprimer_tache_par_titre();
    
        break;
    case '6':
         system("cls");
        printf("\n6 : Statistiques.    ");
        Affiche_statistique();
        break;
    case '0':
         printf("\n ***************  au revoir  :)  ********\n\n    ");
         exit(0);
        break;    

    default:
         system("cls");
         menu();
        break;
    }
}