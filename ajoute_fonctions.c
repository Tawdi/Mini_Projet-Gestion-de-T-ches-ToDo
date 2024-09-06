#include"head.h"


// // ajoute
void ajoute_un_tache(){
    tache tmp;
    
    tmp.id=tache_count;
    tache_count++;
    
    printf("\n ******************************************************************\n ");
    printf("           ========= Ajouter un tache  ========= ");
    printf("\n ******************************************************************\n ");
    printf("   titre : ");

    getchar();
    scanf("%[^\n]", tmp.titre);
    getchar();

    printf("   description : ");

    // getchar();
    scanf("%[^\n]", tmp.desc);
    getchar();

    
   
}
