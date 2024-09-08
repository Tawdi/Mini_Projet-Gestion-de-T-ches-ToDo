#include"head.h"



// // affiche
// Afficher le nombre total des tâches.

// Afficher le nombre de tâches complètes et incomplètes.

// Afficher le nombre de jours restants jusqu'au délai de chaque tâche.
void Afficher_tous_taches_par_user_id(int id){
    
    tache tache_;
    printf("\n ****************************************************************** ");
    printf(" \n=============== ficher tous les livres disponibles =============== \n");
    printf(" ******************************************************************\n ");
     printf("\n=========================================================================================\n");
    printf("   id |             titre            |        description           |  team_nbr    |  ");
    printf("\n=========================================================================================\n");
    fermer_fichier(todo_file);
     int op = ouvrir_fichier("./test.txt","rb");
     if(op==1){

       while (fread(&tache_, sizeof(tache), 1, todo_file)) {

        printf("   %d  |%-30s|%-30s|%10.2f   \n", tache_.id, tache_.titre, tache_.desc, tache_.team_nbr);
        printf("---------------------------------------------------------------------------------------\n");
   
        }
     }else{
        printf("error affichage: ouvrir fichier \n");
     }
    fermer_fichier(todo_file);

     
   
    
    

}


void Afficher_le_nombre_total_des_taches();

void Afficher_le_nombre_des_taches_completes();

void Afficher_le_nombre_des_taches_incompletes();