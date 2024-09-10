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
tache * tous_les_taches_dans_fichier(){
    int taille= nombre_des_taches();
    tache* tache_=malloc(taille*sizeof(tache));
    ouvrir_fichier("./test.txt","rb");
    fread(tache_,sizeof(tache),taille,todo_file);
    return tache_;
}
// void lire_un_tache_au_fichier(tache * tache_,FILE* file){

//     fread(tache_,sizeof(tache),1,file);

// }
void ajoute_tache_au_fichier(tache * tache_ ,const char* file,const char* mode ){
    int op = ouvrir_fichier(file,mode);
    if(op==1){

        ecrire_un_tache_au_fichier(tache_, todo_file);
        // fwrite(tache_,sizeof(tache),1,todo_file);
    }
    fermer_fichier(todo_file);
    
}
void fermer_fichier(FILE * file){

    fclose(file);
}