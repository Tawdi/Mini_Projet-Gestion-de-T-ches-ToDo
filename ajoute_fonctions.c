#include"head.h"

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


// // ajoute
void ajoute_un_tache(){
    tache* tmp=malloc(sizeof(tache));

    tmp->id=tache_count;
    tache_count++;
    date deadline={22,12,11,9,2024};
    tmp->deadline=deadline;
    tmp->id_user =11;
    tmp->team_nbr=2;
    tmp->team_ids[0]= 21;
    tmp->team_ids[1]= 31;



    
    printf("\n ******************************************************************\n ");
    printf("           ========= Ajouter un tache  ========= ");
    printf("\n ******************************************************************\n ");
    printf("   titre : ");

    getchar();
    scanf("%[^\n]", tmp->titre);
    getchar();

    printf("   description : ");

    // getchar();
    scanf("%[^\n]", tmp->desc);
    getchar();

    ajoute_tache_au_fichier(tmp,"./test.txt","wb");
//    create
}
