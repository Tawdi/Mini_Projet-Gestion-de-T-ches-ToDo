#ifndef MINI_PROJET_LIB_H
#define MINI_PROJET_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
    int min, heure, jour, mois, anne;

}date;

FILE * todo_file;
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
int ouvrir_fichier(const char* file,const char* mode);

void ecrire_un_tache_au_fichier(tache * tache,FILE* file);

void lire_un_tache_au_fichier(tache * tache,FILE* file);

void fermer_fichier(FILE * file);



// ajoute
void ajoute_un_tache();
void ajoute_tache_au_fichier(tache * tache ,const char* file,const char* mode );

void ajoute_tache_au_fichier(tache * tache ,const char* file,const char* mode );

// void ajoute();

// // affiche
// Afficher le nombre total des tâches.

// Afficher le nombre de tâches complètes et incomplètes.

// Afficher le nombre de jours restants jusqu'au délai de chaque tâche.
void Afficher_tous_taches_par_user_id(int id);

void Afficher_le_nombre_total_des_taches();

void Afficher_le_nombre_des_taches_completes();

void Afficher_le_nombre_des_taches_incompletes();


void Afficher_le_nombre_de_jours_restants_par_tache_id(int id);

// // recherche
// Rechercher les Tâches :

// Rechercher une tâche par son Identifiant.

// Rechercher une tâche par son Titre
void Rechercher_un_tache_par_titre();

void Rechercher_un_tache_par_id(int id);

// modifie
void modifier_la_desc_de_tache();

void modifier_le_deadline_de_tache();

void modifier_le_status_de_tache();

// supprime
void Supprimer_tache_par_id(int id);

// menu
void menu();

#endif