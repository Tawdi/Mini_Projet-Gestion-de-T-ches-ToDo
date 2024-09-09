#include"head.h"



int ouvrir_fichier(const char* file,const char* mode){

    todo_file= fopen(file,mode);
    if(todo_file==NULL){
        printf("error. de ouvrir ficher");
        return 0;
    }else{
        return 1;
    }
}

void ecrire_un_tache_au_fichier(tache * tache_,FILE* file){

    fwrite(tache_,sizeof(tache),1,file);
    taille_moins_plus(1);

}

void lire_un_tache_au_fichier(tache * tache_,FILE* file){

    fread(tache_,sizeof(tache),1,file);

}

void fermer_fichier(FILE * file){

    fclose(file);
}