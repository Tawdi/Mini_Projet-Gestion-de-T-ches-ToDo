#include"head.h"

user creer_user(int id, char *nom, char *prenom){
    user u;
    strcpy(u.nom,nom);
    strcpy(u.prenom,prenom);
    u.id=id ;
    return u ;
}

tache creer_tache(int id,  char *titre,  char *desc, int status, date deadline ){
    tache tache;
    tache.team_nbr=0;

    strcpy(tache.titre,titre);
    strcpy(tache.desc,desc);
    tache.status = status;
    tache.deadline = deadline;

    return tache;
}