#include "head.h"

// // recherche
// void Rechercher_un_tache_par_titre();

// void Rechercher_un_tache_par_id(int id);
 
void Rechercher_un_tache_par_titre()
{

    printf("\n ****************************************************************** ");
    printf("\n      ======== Rechercher une tache par son titre. =========     \n");
    printf(" ****************************************************************** \n");
    char temp[100];
    int y = -1;
    int test = -1;
    printf(" entrer un titre pour recherche  : ");

    // getchar();
    scanf("%[^\n]", temp);
    getchar();
    printf("\n==================================================================================================\n");
    printf("     id        |             titre            |             status           |       deadline    |  ");
    printf("\n==================================================================================================\n");
    fermer_fichier(todo_file);
    int op = ouvrir_fichier("./test.txt", "rb");
    int taille = nombre_des_taches();
    tache *tache_ = malloc(taille * sizeof(tache));
    if (op == 1)
    {

        for (int i = 0; i < taille; i++)
        {
            if (fread(tache_, sizeof(tache), taille, todo_file) && strncmp(temp, tache_[i].titre, strlen(temp)) == 0)
            {
                test = 1;
                affiche_seule_tache(&tache_[i]);
            }
        }
        if (test == -1)
        {
            printf("aucun tache avec ce titre : %s", temp);
        }
    }
    else
    {
        printf("error affichage: ouvrir fichier \n");
    }
    fermer_fichier(todo_file);
}

