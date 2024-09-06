#include"head.h"

void menu(tache *Librairie, int *taille)
{
    char choix;
    printf(" \n****************************************************************** ");

    printf(" \n========= Systeme de Gestion de Stock dans une Librairie ========= ");
    printf(" \n******************************************************************\n ");

    printf("\n1 : Ajouter un livre au stock.");
    printf("\n2 : Afficher tous les livres disponibles.   ");
    printf("\n3 : Rechercher un livre par son titre.    ");
    printf("\n4 : Mettre a jour la quantite d'un livre.    ");
    printf("\n5 : Supprimer un livre du stock.    ");
    printf("\n6 : Afficher le nombre total de livres en stock.    ");
    // do
    // {
        printf(" \n\nvotre choix  :");
    scanf(" %c", &choix);
    // } while (choix<1 || choix>6);
    
    

    switch (choix)
    {
    case '1':
         system("cls");
        // ajoute(Librairie, taille);
        break;
    case '2':
         system("cls");
        // Afficher_tous_les_livres(Librairie, taille);
        break;
    case '3':
         system("cls");
        // Rechercher_un_livre_par_so_titre(Librairie, taille);
        break;
    case '4':
         system("cls");
        // Mettre_a_jour_la_quantite_un_livre(Librairie, taille);
        break;
    case '5':
         system("cls");
        // Supprimer_un_livre_du_stock(Librairie, taille);
        break;
    case '6':
         system("cls");
        // Afficher_le_nombre_total_de_livres_en_stock(Librairie, taille);
        break;

    default:
        // menu(Librairie, taille);
        break;
    }
}