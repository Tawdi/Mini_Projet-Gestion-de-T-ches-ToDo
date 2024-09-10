#include "head.h"

// typedef struct
// {
//     int id;
//     char *titre;
//     char *desc;
//     int status; //   à réaliser : 0  en cours de réalisation : 1   finalisée: 2
//     date deadline;
//     int id_user;
//     int team_ids[20];
//     int team_nbr;

// } tache;
int date_est_valide(date deadline)
{
    return 1;
}
// // ajoute

void ajoute_seule_tache(tache *tmp)
{
    int test = 0;
    tmp->id = time(NULL);
    date deadline;
    tmp->id_user = 100;
    tmp->team_nbr = 0;
    tmp->status = rand()%3+1;

    printf("   titre : ");

    // getchar();
    scanf("%[^\n]", tmp->titre);
    getchar();

    printf("   description : ");

    // getchar();
    scanf("%[^\n]", tmp->desc);
    getchar();
    do
    {
        printf("*****svp entrer le dealine sous cette forme HH:MM JJ/MM/YYY *****\n**********example 02:50 30/03/2030 ************************* \n   deadline: ");
        test = scanf("%d:%d %d/%d/%d", &deadline.min, &deadline.heure, &deadline.jour, &deadline.mois, &deadline.anne);

        // getchar();

    } while (test != 5 || !date_est_valide(deadline));

    if (test == 5)
    {
        tmp->deadline = deadline;
    }

    ajoute_tache_au_fichier(tmp, "./test.txt", "ab");
}

void ajoute_un_tache()
{
    tache *tmp = malloc(sizeof(tache));

    // tmp->team_ids[0]= 21;
    // tmp->team_ids[1]= 31;

    printf("\n ******************************************************************\n ");
    printf("             ========= Ajouter un tache  ========= ");
    printf("\n ******************************************************************\n ");
    char reponce[5];
    do
    {
        // system("cls");
       ajoute_seule_tache(tmp);
        do
        {
             printf("voulez vous ajouter autre livre ? (y/n) ");
            scanf(" %[^\n]", reponce);
            getchar();
        } while (reponce[0] != 'y' && reponce[0] != 'Y' && reponce[0] != 'n' && reponce[0] != 'N');

    } while (reponce[0] == 'y' || reponce[0] == 'Y');
    
    
}
