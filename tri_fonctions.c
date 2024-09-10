#include"head.h"

void tri_alphabetique(tache* tache_){
    // challange 7

    int taille =nombre_des_taches();
    tache tmp;

    int valide;
    
    
    do{
        valide = 0;
        for (int i = 0; i < taille -1; i++)
        {
            if (strcmp(tache_[i].titre , tache_[i+1].titre)>0)
            {
                valide = 1;
                tmp = tache_[i];
                tache_[i] = tache_[i + 1];
                tache_[i + 1] = tmp;
                
            }

        }
    }while (valide);

    printf("affichage des Éléments apres triage :\n");
    for (int i = 0; i < taille; i++)
    {
        printf(" %s \n",tache_[i].titre);
    }



}