#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



typedef struct
{
    int min, heure, jour, mois, anne;

}date;

FILE * todo_file;
FILE * statistique_file;

extern int tache_count;
typedef struct
{
    int id;
    char *nom;
    char *prenom;
    // char * email;

}user;

typedef struct
{
    int id;
    char titre[100];
    char desc[400];
    int status; //   à réaliser : 1  en cours de réalisation : 2  finalisée: 3
    date deadline;
    int id_user;
    int team_ids[20];
    int team_nbr;

} tache;

// fichier
int ouvrir_fichier(const char* file,const char* mode); //done

void ecrire_un_tache_au_fichier(tache * tache,FILE* file); //done

// void lire_un_tache_au_fichier(tache * tache,FILE* file); 

void fermer_fichier(FILE * file); //done



// ajoute
void ajoute_un_tache(); //done
void ajoute_tache_au_fichier(tache * tache ,const char* file,const char* mode ); //done


// // affiche
// Afficher le nombre total des tâches.

// Afficher le nombre de tâches complètes et incomplètes.

// Afficher le nombre de jours restants jusqu'au délai de chaque tâche.
void affiche_seule_tache(tache* tache_); //done

void affiche_seule_tache_sans_desc(tache* tache_,int code); //done

void status_au_char(int status); //done

void date_au_char(date deadline); //need wooork
int choisir_le_type_de_affichage();

// void Afficher_tous_taches_par_user_id(int id); 
void Afficher_tous_taches(); //done

void Afficher_le_nombre_total_des_taches();

void Afficher_le_nombre_des_taches_completes_incompletes();//done

void Affiche_statistique();



void Afficher_le_nombre_de_jours_restants_par_tache_id(int id);

// // recherche
// Rechercher les Tâches :

// Rechercher une tâche par son Identifiant.

// Rechercher une tâche par son Titre
void Rechercher_un_tache_par_titre();//done

void Rechercher_un_tache_par_id(int id); // ???????
//tri
//Trier les tâches par ordre alphabétique.
void tri_alphabetique(tache *tache_);
void tri_par_deadline(tache *tache_);

//Trier les tâches par deadline.
// modifie
void Modifier_un_tache_par_titre();
void modifier_la_desc_de_tache(tache *tmp); //need wooork

void modifier_le_deadline_de_tache(tache *tmp); //need wooork

void modifier_le_status_de_tache(tache *tmp); //need wooork

// supprime
void Supprimer_tache_par_id(int id); // ????????? 

void Supprimer_tache_par_titre(); //done

// menu
void menu(); //done 

// statistique
int taille_moins_plus(int a ); //done
int nombre_des_taches(); //done
int int_dans_table(int indice, int *temp_int, int taille);//done
int date_est_valide(date deadline);//done
tache * tous_les_taches_dans_fichier();

#endif