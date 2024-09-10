#include "head.h"

void Modifier_un_tache_par_titre()
{

    printf("\n ****************************************************************** ");
    printf("\n      ======== modification une tache par son titre. =========     \n");
    printf(" ****************************************************************** \n");
    char temp[100];
    int y = -1;
    int test = -1;
    printf(" entrer un titre d'une tache pour la modification  : ");
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
    int *temp_int = malloc(taille * sizeof(int));
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

                    affiche_seule_tache_sans_desc(&tache_[i], i);
                }
            }
        }
        if (test == 1)
        {
            do
            {
                printf(" si vous voulez annuler la modification ecrire -1  ");
                printf("\n svp donne le CODE de tache pour comfirmier modification : ");
                scanf("%d", &y);

                if (y == -1)
                    break;

            } while (int_dans_table(y, temp_int, count) == 0);

            if (y == -1)
            {
                printf(" la modification est annule\n");
            }
            else
            {

                char choix_md[4];
                printf("\n=====       choisir le type de modification       ===== \n");
                printf("\n**       1 : Modifier la description d'une tache.  **");
                printf("\n**       2 : Modifier le statut d'une tache.       **");
                printf("\n**       3 : Modifier le deadline d'une tache.     **");
                do
                {
                    printf(" \n\nvotre choix  :");
                    scanf(" %[^\n]", choix_md);
                    getchar();

                    switch (choix_md[0])
                    {
                    case '1':
                        modifier_la_desc_de_tache(&tache_[y]);
                        break;
                    case '2':
                        modifier_le_status_de_tache(&tache_[y]);
                        break;
                    case '3':
                         modifier_le_deadline_de_tache(&tache_[y]);
                        break;
                    }
                } while (choix_md[0] != '1' && choix_md[0] != '2' && choix_md[0] != '3');

                fermer_fichier(todo_file);
                op = ouvrir_fichier("./test.txt", "wb");
                if (op == 1)
                {
                    fwrite(tache_, sizeof(tache), taille, todo_file);
                    printf("livre est modifie");
                }
                else
                {
                    printf("error en ouvrire (mode ecrire) fichier dans fonction  modifie");
                }
            }
        }
    }
    else
    {
        printf("error en ouvrire (mode lire) fichier dans fonction  modifie \n");
    }
    fermer_fichier(todo_file);
}

void modifier_le_deadline_de_tache(tache *tmp)
{
    int test = 0;
    date deadline;
    printf("\n    dealine : ");
    date_au_char(tmp->deadline);

    do
    {
        printf("\n*****svp entrer le dealine sous cette forme HH:MM JJ/MM/YYY *****\n***********example 02:50 30/03/2030 ************************* \n  nouvelle deadline: ");
        test = scanf("%d:%d %d/%d/%d", &deadline.min, &deadline.heure, &deadline.jour, &deadline.mois, &deadline.anne);

        // getchar();

    } while (test != 5 || !date_est_valide(deadline));

    if (test == 5)
    {
        tmp->deadline = deadline;
    }
}

void modifier_la_desc_de_tache(tache *tmp)
{
    printf("\n    description : %s", tmp->desc);

    printf("\n    nouvelle description : ");

    // getchar();
    scanf("%[^\n]", tmp->desc);
    getchar();
}

void modifier_le_status_de_tache(tache *tmp)
{
    char choix_md[4];
    printf("\n    status : ");
    status_au_char(tmp->status);
    printf("\n    nouvelle status : ");
    printf("\n**       1 : a realiser                **");
    printf("\n**       2 : en cours de realisation   **");
    printf("\n**       3 : finalisee                 **");
    do
    {
        printf(" \n\nvotre choix  :");
        scanf(" %[^\n]", choix_md);
        getchar();

        switch (choix_md[0])
        {
        case '1':
            tmp->status = 1;
            break;
        case '2':
            tmp->status = 2;

            break;
        case '3':
            tmp->status = 3;

            break;
        }
    } while (choix_md[0] != '1' && choix_md[0] != '2' && choix_md[0] != '3');
}
