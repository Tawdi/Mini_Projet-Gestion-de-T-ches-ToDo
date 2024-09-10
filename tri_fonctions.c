#include "head.h"
time_t date_seconds(date d)
{

    time_t result;
    struct tm time;

    time.tm_year = d.anne - 1900;
    time.tm_mon = d.mois - 1;
    time.tm_mday = d.jour;
    time.tm_hour = d.heure;
    time.tm_min = 0;
    time.tm_sec = 0;

    result = mktime(&time);
    return result;
}
void tri_alphabetique(tache *tache_)
{
    // challange 7

    int taille = nombre_des_taches();
    tache tmp;

    int valide;
    char temp1[100];
    char temp2[100];
    int j = 0;
    do
    {
        valide = 0;

        for (int i = 0; i < taille - (1 + j); i++)
        {
            strcpy(temp1, tache_[i].titre);
            strcpy(temp2, tache_[i].titre);
            strupr(temp1);
            strupr(temp2);

            if (strcmp(temp1, temp2) > 0)
            {

                valide = 1;
                tmp = tache_[i];
                tache_[i] = tache_[i + 1];
                tache_[i + 1] = tmp;
            }
        }
        j++;
    } while (valide);
}
void tri_par_deadline(tache *tache_)
{
    // challange 7

    int taille = nombre_des_taches();
    tache tmp;
 int j = 0;
    int valide;

    do
    {
        valide = 0;
        for (int i = 0; i < taille - (1+j); i++)
        {

            if (difftime(date_seconds(tache_[i].deadline), date_seconds(tache_[i + 1].deadline)) > 0)

            {
                valide = 1;
                tmp = tache_[i];
                tache_[i] = tache_[i + 1];
                tache_[i + 1] = tmp;
            }
        }
        j++;
    } while (valide);

    printf("affichage des Éléments apres triage :\n");
    for (int i = 0; i < taille; i++)
    {
        printf(" %s \n", tache_[i].titre);
    }
}