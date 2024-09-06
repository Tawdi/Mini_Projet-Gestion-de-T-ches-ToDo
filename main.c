#include<stdio.h>
#include"head.h"




int main(){
    system("cls");

// FILE *todo_file;

// todo_file = fopen("tache_list.txt", "a"); 

// fclose(todo_file);

char reponce='y';

do
{
    system("cls");
    menu( );
   do
   {
    printf("\nest ce que vous voulez continuer utilisation de ce programme ? (y/n) ");
    scanf(" %c", &reponce);
   } while (reponce != 'y' && reponce != 'Y' && reponce != 'n' && reponce != 'N' );
    
} while (reponce == 'y' || reponce == 'Y');


return 0;
}