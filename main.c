#include<stdio.h>
#include"head.h"
// #include"menu_fonctions.c"
// #include"fichier_fonctions.c"
// #include"ajoute_fonctions.c"





int tache_count = 0;

int main(){
    system("cls");

// FILE *todo_file;

// todo_file = fopen("tache_list.txt", "a"); 

// fclose(todo_file);

char reponce[11];

do
{
    system("cls");
    menu();
   do
   {
    printf("\nest ce que vous voulez continuer utilisation de ce programme ? (y/n) ");
    scanf(" %[^\n]", reponce);
    getchar();
   } while (reponce[0] != 'y' && reponce[0] != 'Y' && reponce[0] != 'n' && reponce[0] != 'N' );
    
} while (reponce[0] == 'y' || reponce[0] == 'Y');


return 0;
}