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
int tache_count=0;
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
    char *titre;
    char *desc;
    int status; //   à réaliser : 0  en cours de réalisation : 1   finalisée: 2
    date deadline;
    int id_user[20];
    int team_nbr;

} tache;
// ajoute
void ajoute_un_tache();

void ajoute();

// affiche
void Afficher_tous_taches_par_user_id(int id);

void Afficher_le_nombre_total_des_taches();

void Afficher_le_nombre_de_jours_restants_par_tache_id(int id);

// recherche
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