#include<stdio.h>
#include<stdlib.h>
#include<String.h>

    char titre[50], auteur[50], Titres[100][100], Auteurs[100][100]; 
    int Quantite_stock[100], id_livre = 0;
    float Prix[100];

    // les fonctions
    void ajouter_livre();
    void afficher_livres();
    void rechercher_livre();
    void mise_a_jour();
    void supprimer_livre();
    void afficher_stock();

int main(){
    int n; 

    do{
        printf("\n\n=================================Le menu :=================================");
        printf("\n1).Ajouter un livre au stock. ");
        printf("\n2).Afficher tous les livres disponibles.");
        printf("\n3).Rechercher un livre par son titre.");
        printf("\n4).Mettre a jour la quantite d'un livre.");
        printf("\n5).Supprimer un livre du stock.");
        printf("\n6).Afficher le nombre total de livres en stock.");
        printf("\n7).Quitter le programme . ");
        printf("\n===========================================================================");
        
        printf("\n============> Votre choix : ");
        scanf("%d",&n);
        getchar();

        switch(n){
            case 1 : {
                ajouter_livre();
                break;
            }
            case 2 : {
                afficher_livres();
                break;
            }
            case 3 : {
                rechercher_livre();
                break;
            }
            case 4 : {
                mise_a_jour();
                break;
            }
            case 5 : {
                supprimer_livre();
                break;
            }
            case 6 : {
                afficher_stock();
                break;
            }
            case 7 : {
                printf("\nQuitter le programme . ");
                break;
            }
            default : printf("\nOption not found, please try again !!");
        }

    }while( n != 7);

    return 0 ;
}
//=======================================================================

// La fonction ajouter_livre() qui ajout un livre au stock

void ajouter_livre(){
    float prix_liv;
    int quantite_liv;

    printf("\nAjouter un livre : ");
    printf("\n\tTitre de livre : ");
    //scanf("%s",titre);
    fgets(titre, sizeof(titre), stdin);
    titre[strcspn(titre, "\n")] = 0; // Supprimer le '\n' à la fin
    
    printf("\n\tAuteur de livre : ");
    //scanf("%s",auteur);
    fgets(auteur, sizeof(auteur), stdin);
    auteur[strcspn(auteur, "\n")] = 0; // Supprimer le '\n' à la fin
    
    printf("\n\tPrix de livre : ");
    scanf("%f",&prix_liv);

    printf("\n\tQuantite de livre en stock : ");
    scanf("%d",&quantite_liv);
    getchar(); // Pour consommer le '\n' restant dans le buffer

    strcpy(Titres[id_livre], titre);
    strcpy(Auteurs[id_livre], auteur);
    Prix[id_livre] = prix_liv ; 
    Quantite_stock[id_livre] = quantite_liv ;

    id_livre++ ;
    printf("\n-------->Vous avez ajoutez un livre avec succes .");
}

// La fonction afficher_livres() permet d'afficher des livre disponible en stock

void afficher_livres() {
    if (id_livre == 0) {
        printf("\n-------->Aucun livre disponible pour le moment.");
        return;
    }

    printf("\n-------->Liste des livres disponibles :\n");
    for (int i = 0; i < id_livre; i++) {
        printf("Livre %d :\n", i + 1);
        printf("\tTitre : %s\n", Titres[i]);
        printf("\tAuteur : %s\n", Auteurs[i]);
        printf("\tPrix : %.2f\n", Prix[i]);
        printf("\tQuantite en stock : %d\n", Quantite_stock[i]);
    }
}

// La fonction rechercher_livre(); permet de rechercher un livre par son titre.

void rechercher_livre(){
    char search_title[50] ;
    int trouver=0 ;

    printf("\n-------->Entrez le titre du livre a rechercher : ");
    //scanf("%s",search_title);
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Supprimer le '\n'

    
    for(int i=0 ; i<id_livre ; i++ ){
        if( strcmp(search_title , Titres[i] ) == 0 ){
            printf("\nLivre trouve : \n");
            printf("\tTitre : %s\n", Titres[i]);
            printf("\tAuteur : %s\n", Auteurs[i]);
            printf("\tPrix : %.2f\n", Prix[i]);
            printf("\tQuantite en stock : %d\n", Quantite_stock[i]);
            trouver = 1;
            break;
        }
    }
    if( !trouver )
        printf("\n-------->Aucun livre trouve avec ce titre . ");
}

// Mettre a jour la quantite d'un livre specifique

void mise_a_jour(){
    char search_title[50] ;
    int trouver=0 , q;

    printf("\n-------->Entrez le titre du livre à modifier sa quantite : ");
    //scanf("%s",search_title);
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Supprimer le '\n'


    printf("\n-------->Entrez la nouvelle quantite du livre : ");
    scanf("%d",&q);
    getchar(); // Pour consommer le '\n' restant

    
    for(int i=0 ; i<id_livre ; i++ ){
        if( strcmp(search_title , Titres[i] ) == 0 ){
            printf("\n-------->La quantite du livre du titre %s est modifier (%d devient %d) . ",Titres[i] , Quantite_stock[i] , q );
            Quantite_stock[i] = q ;
            trouver = 1;
            break;
        }
    }
    if( !trouver )
        printf("\n-------->Aucun livre trouve avec ce titre . ");
}

// Supprimer un livre du stock 
void supprimer_livre(){
    char delete_title[50] ;
    int delete=0 ;

    printf("\n-------->Entrez le titre du livre a supprimer : ");
    //scanf("%s",delete_title);
    fgets(delete_title, sizeof(delete_title), stdin);
    delete_title[strcspn(delete_title, "\n")] = 0; // Supprimer le '\n'

    
    for(int i=0 ; i<id_livre ; i++ ){
        if( strcmp(delete_title , Titres[i] ) == 0 ){
            for(int j=i ; j<(id_livre - 1) ; j++ ){
                printf("\n-------->suppression de livre %s dans la case %d est reussi. ",Titres[j] ,i );
                strcpy(Titres[j], Titres[j+1]);
                strcpy(Auteurs[j], Auteurs[j+1]);
                Prix[j] = Prix[j+1] ; 
                Quantite_stock[j] = Quantite_stock[j+1] ;
            }
                id_livre--; // Décrémente id_livre après avoir effectué la suppression
                delete = 1; // Livre supprimé avec succès.
                break; 
        }
    }
    if( !delete )
        printf("\n-------->Aucun livre trouve avec ce titre, alors aucun suppression fait. ");
}

// Afficher le nombre total de livres en stock
void afficher_stock(){
    int somme_stock = 0 ;
    if (id_livre == 0) {
        printf("\n-------->Aucun livre disponible pour le moment dans le stock.");
        return;
    }

    for (int i = 0; i < id_livre; i++) {
        somme_stock = somme_stock + Quantite_stock[i] ;
    }
    printf("-------->Le nombre total de livres en stock est %d .",somme_stock);
}