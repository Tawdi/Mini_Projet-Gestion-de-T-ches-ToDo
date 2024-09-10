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
   printf("%-30s", tmpchar);
}

// supprime affichage
void affiche_seule_tache_sans_desc(tache *tache_, int code)
{
   printf("   %4d |", code);

   printf("%-30s", tache_->titre);

   //   à réaliser : 1  en cours de réalisation : 2  finalisée: 3
   printf("|");
   status_au_char(tache_->status);

   date_au_char(tache_->deadline);
   printf("\n==================================================================================================\n");
}

void affiche_seule_tache(tache *tache_)
{

   printf("               |%-30s", tache_->titre);

   //   à réaliser : 1  en cours de réalisation : 2  finalisée: 3
   printf("|");
   status_au_char(tache_->status);

   date_au_char(tache_->deadline);

   printf("\n               ----------------------------------------------------------------------------------\n");
   printf("   %d  |  description :                                                                  |  \n", tache_->id);
   // printf("\n               ===================================================================================\n");
   printf("               | %-80s|  ", tache_->desc);

   printf("\n==================================================================================================\n");
   // printf("\n--------------------------------------------------------------------------------------------------\n");
}

void Afficher_tous_taches()
{

   tache *tache_ = malloc(sizeof(tache));
   tache *list;
   int choix_affichage=choisir_le_type_de_affichage();
   int cout = nombre_des_taches();

    

   printf("\n ************************************************************************************************* ");
   printf("\n             ===============    affichage de tous les taches    =============== \n");
   printf(" *************************************************************************************************\n ");
   printf("\n==================================================================================================\n");
   printf("     id        |             titre            |             status           |       deadline    |  ");
   printf("\n==================================================================================================\n");
   fermer_fichier(todo_file);
   int op = ouvrir_fichier("./test.txt", "rb");

   if (op == 1)
   {
      // affiche_seule_tache(tache_);
      // while (fread(tache_, sizeof(tache), 1, todo_file))
      // {
      //    list = realloc(list, cout * sizeof(tache));
      //    list[cout] = *tache_;
      //    cout++;
      // }
      list = tous_les_taches_dans_fichier();
      if (choix_affichage == 2)
      {
         tri_alphabetique(list);
      }
      if (choix_affichage == 3)
      {
         tri_par_deadline(list);
      }
      for (int i = 0; i < cout; i++)
      {
         affiche_seule_tache(list+i);
      }
      


   }
   else
   {
      printf("error affichage: ouvrir fichier \n");
   }
   fermer_fichier(todo_file);
}

void Afficher_le_nombre_total_des_taches()
{
   int nbr = nombre_des_taches();
   printf("\nle nombre total des taches : %d \n", nbr);
}

void Afficher_le_nombre_des_taches_completes_incompletes()
{

   tache *tache_ = malloc(sizeof(tache));
   fermer_fichier(todo_file);
   int op = ouvrir_fichier("./test.txt", "rb");
   int count_complete = 0, count_incomplete = 0;
   if (op == 1)
   {

      while (fread(tache_, sizeof(tache), 1, todo_file))
      {
         if (tache_->status == 3)
         {
            count_complete++;
         }
         else
         {
            count_incomplete++;
         }
      }
      printf("\nle nombre de taches completes   : %d \n", count_complete);
      printf("\nle nombre de taches incompletes : %d \n", count_incomplete);
   }
   else
   {
      printf("error affichage: ouvrir fichier \n");
   }
   fermer_fichier(todo_file);
}
void Afficher_le_nombre_de_jours_restants_pour_les_taches()
{
   Afficher_tous_taches();
};

void Affiche_statistique()
{
   printf(" \n******************************************************************************** ");
   printf(" \n           ===============  statistique de TODO-list  ===============           ");
   // printf(" *******************************************************************\n ");
   printf(" \n******************************************************************************** ");

   printf("\n**   1 : Afficher le nombre total des taches.                                 **    ");
   printf("\n**   2 : Afficher le nombre de taches completes et incompletes.               **    ");
   printf("\n**   3 : Afficher le nombre de jours restants jusqu'au delai de chaque tache. **    ");
   char choix_md[4];
   do
   {
      printf(" \n\nvotre choix  :");
      scanf(" %[^\n]", choix_md);
      getchar();

      switch (choix_md[0])
      {
      case '1':
         Afficher_le_nombre_total_des_taches();
         break;
      case '2':
         Afficher_le_nombre_des_taches_completes_incompletes();
         break;
      case '3':
         Afficher_le_nombre_de_jours_restants_pour_les_taches();
         break;
      }
   } while (choix_md[0] != '1' && choix_md[0] != '2' && choix_md[0] != '3');
}
int choisir_le_type_de_affichage()
{  
   printf(" \n******************************************************************************** ");
   printf(" \n           ===============  choisir le type de affichage  ===============           ");
   // printf(" *******************************************************************\n ");
   printf(" \n******************************************************************************** ");

   printf("\n**   1 : Affichage simple .                                                    **    ");
   printf("\n**   2 : Afficher Trier  par ordre alphabétique.                               **    ");
   printf("\n**   3 : Afficher Trier  par deadline.                                         **    ");
   char choix_md[4];
   int a=1;
   do
   {
      printf(" \n\nvotre choix de affichage  :");
      scanf(" %[^\n]", choix_md);
      getchar();

      switch (choix_md[0])
      {
      case '1':
         a = 1;
         break;
      case '2':
         a = 2;
         break;
      case '3':
         a = 3;
         break;
      }
   } while (choix_md[0] != '1' && choix_md[0] != '2' && choix_md[0] != '3');
   return a;
}