#include "head.h"

// // affiche
// Afficher le nombre total des tâches.

// Afficher le nombre de tâches complètes et incomplètes.

// Afficher le nombre de jours restants jusqu'au délai de chaque tâche.
void date_au_char(date deadline)
{
   printf("| %02d:%02d %02d/%02d/%4d  |", deadline.min, deadline.heure, deadline.jour, deadline.mois, deadline.anne);
}

void status_au_char(int status)
{
   char tmpchar[30];
   if (status == 1)
   {
      strcpy(tmpchar, "a realiser");
   }
   else if (status == 2)
   {
      strcpy(tmpchar, "en cours de realisation");
   }
   else
   {
      strcpy(tmpchar, "finalisee");
   }
   printf("|%-30s", tmpchar);
}

// supprime affichage
void affiche_seule_tache_sans_desc(tache *tache_, int code)
{
   printf("   %4d |", code);

   printf("%-30s", tache_->titre);

   //   à réaliser : 1  en cours de réalisation : 2  finalisée: 3
   status_au_char(tache_->status);

   date_au_char(tache_->deadline);
   printf("\n==================================================================================================\n");
}

void affiche_seule_tache(tache *tache_)
{

   printf("               |%-30s", tache_->titre);

   //   à réaliser : 1  en cours de réalisation : 2  finalisée: 3
   status_au_char(tache_->status);

   date_au_char(tache_->deadline);

   printf("\n               ----------------------------------------------------------------------------------\n");
   printf("   %d  |  description :                                                                  |  \n", tache_->id);
   // printf("\n               ===================================================================================\n");
   printf("               | %-80s|  ", tache_->desc);

   printf("\n==================================================================================================\n");
   // printf("\n--------------------------------------------------------------------------------------------------\n");
}

void Afficher_tous_taches_par_user_id(int id)
{

   tache *tache_ = malloc(sizeof(tache));
   printf("\n ****************************************************************** ");
   printf(" \n=============== ficher tous les livres disponibles =============== \n");
   printf(" ******************************************************************\n ");
   printf("\n==================================================================================================\n");
   printf("     id        |             titre            |             status           |       deadline    |  ");
   printf("\n==================================================================================================\n");
   fermer_fichier(todo_file);
   int op = ouvrir_fichier("./test.txt", "rb");

   if (op == 1)
   {

      while (fread(tache_, sizeof(tache), 1, todo_file))
      {
         affiche_seule_tache(tache_);
      }
   }
   else
   {
      printf("error affichage: ouvrir fichier \n");
   }
   fermer_fichier(todo_file);
}

void Afficher_le_nombre_total_des_taches();

void Afficher_le_nombre_des_taches_completes();

void Afficher_le_nombre_des_taches_incompletes();