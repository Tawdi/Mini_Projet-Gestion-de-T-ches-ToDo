#include "head.h"

int int_dans_table(int y, int *temp_int, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (temp_int[i] == y)
        {
            return 1;
        }
    }
    return 0;
}

void Supprimer_tache_par_titre()
{

    printf("\n ****************************************************************** ");
    printf("\n      ======== Rechercher une tache par son titre. =========     \n");
    printf(" ****************************************************************** \n");
    char temp[100];
    int y = -1;
    int test = -1;
    printf(" entrer un titre d'une tache pour la suppression  : ");
    // getchar();
    scanf("%[^\n]", temp);
    getchar();
    printf("\n==================================================================================================\n");
    printf("   CODE |             titre            |             status           |       deadline    |  ");
    printf("\n==================================================================================================\n");
    fermer_fichier(todo_file);
    int op = ouvrir_fichier("./test.txt", "rb");
    int taille = nombre_des_taches();
    tache *tache_ = malloc(taille * sizeof(tache));
    // tache tache_temp;
    int temp_int[taille];
    int count = 0;
    if (op == 1)
    {

        if (fread((tache_), sizeof(tache), taille, todo_file))
        {

            for (int i = 0; i < taille; i++)
            {
                if (strncmp(temp, tache_[i].titre, strlen(temp)) == 0)
                {
                    test = 1;
                    temp_int[count++] = i;

                    affiche_seule_tache_sans_desc(&tache_[i],i);
                }
            }
        }
        if (test == 1)
        {
            do
            {
                printf(" si vous voulez annuler la suppression ecrire -1  ");
                printf("\n svp donne le CODE de tache pour comfirmier suppression : ");
                scanf("%d", &y);

                if (y == -1)
                    break;

            } while (int_dans_table(y, temp_int, count) == 0);

            if (y == -1)
            {
                printf(" la suppression est annule\n");
            }
            else
            {
                for (int i = y; i < taille - 1; i++)
                {

                    tache_[i] = tache_[i + 1];
                }
                fermer_fichier(todo_file);
                op = ouvrir_fichier("./test.txt", "wb");
                if (op == 1)
                {
                    fwrite(tache_, sizeof(tache), taille - 1, todo_file);
                    taille_moins_plus(-1);
                    printf("livre est supprime");
                }
                else
                {
                    printf("error en ouvrire (mode ecrire) fichier dans fonction  supprime");
                }
            }
        }
    }
    else
    {
        printf("error en ouvrire (mode lire) fichier dans fonction  supprime \n");
    }
    fermer_fichier(todo_file);
}
