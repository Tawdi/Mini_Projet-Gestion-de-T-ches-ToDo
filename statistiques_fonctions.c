#include "head.h"

int nombre_des_taches()
{
    int nbr;
    fermer_fichier(statistique_file);
    statistique_file = fopen("./statistiques.txt", "r");

    if (statistique_file != NULL && fscanf(statistique_file, "|count: %d |", &nbr) == 1)
    {
        fermer_fichier(statistique_file);
        return nbr;
    }
    else
    {
        fermer_fichier(statistique_file);
        printf("error  de lire  fichier.\n");
        return -1;
    }
}
int taille_moins_plus(int a )
{
    int nbr;
    fermer_fichier(statistique_file);
    statistique_file = fopen("./statistiques.txt", "r");

    if (statistique_file != NULL && fscanf(statistique_file, "|count: %d |", &nbr) == 1)
    {
        nbr=nbr+a;
        fermer_fichier(statistique_file);

        statistique_file = fopen("./statistiques.txt", "w");

        if (statistique_file != NULL)
        {
            fprintf(statistique_file, "|count: %d |\n", nbr);
            fermer_fichier(statistique_file);
        }
        else
        {
            printf("error  de lire  fichier.\n");
            return -1;
        }

        return 1;
    }
    else
    {
        printf("error  de lire  fichier.\n");
        return -1;
    }
}