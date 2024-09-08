#include"head.h"
// #include"fichier_fonctions.c"




void ajoute_tache_au_fichier(tache * tache_ ,const char* file,const char* mode ){
    int op = ouvrir_fichier(file,mode);
    if(op==1){

        ecrire_un_tache_au_fichier(tache_, todo_file);
        // fwrite(tache_,sizeof(tache),1,todo_file);
    }
    fermer_fichier(todo_file);
    
}