#include<stdio.h>
#include<stdlib.h>
#include<String.h>

int main(){
    // declaration 
    char prenom[50], nom[50],meilleur_p[50] = "", meilleur_n[50] = "";
    char pire_p[50] = "", pire_n[50] = "";
    int nbr_etudiants = 0, compt_sup = 0, option;
    float somme = 0, meilleure_note = 0, pire_note = 100 , n1, n2, moyenne;    

    do{
        printf("\n\n========= le menu :=========== \n");
        printf("\nChoisissez un option parmi Les 5 options :  \n");
        printf("\n1..Ajouter des etudiants :  \n");
        printf("\n2..Afficher la moyenne:  ");
        printf("\n3..Afficher les meilleures et moins bonnes notes : \n");
        printf("\n4..Voir le nombre d'etudiants ayant une note superieure à la moyenne :\n");
        printf("\n5..Quitter le programme : \n");
        printf("\n==============================\n");
        printf("le choix : ");
        scanf("%d",&option);

        switch(option){
            case 1 :    // ajouter des etudiant
                {
                    float note ; 

                    if( nbr_etudiants >=100 ){
                        printf("\n---->Vous avez depasser le nombre max d'etudiants : "); 
                    }
                    printf("\nEntrez le nom d'etudiant : ");
                    scanf("%s",nom);
                    printf("\nEntrez le prenom d'etudiant : ");
                    scanf("%s",prenom);
                    printf("\nEntrez la note d'etudiant : ");
                    scanf("%f",&note);

                    somme = somme + note ;
                    nbr_etudiants++ ;

                    if( note > meilleure_note ){
                        meilleure_note = note ; 
                        strcpy(meilleur_p, prenom);
                        strcpy(meilleur_n, nom);
                    }
                    if( note < pire_note ){
                        pire_note = note ; 
                        strcpy(pire_p, prenom);
                        strcpy(pire_n, nom);
                    }
                    printf("\n=========>Bravo,  vous avez ajoutez un etudiant ...............................................");
                }
                break;

            case 2 :    // Calcule et affiche la moyenne si des étudiants ont été ajoutés.
                {
                    if( nbr_etudiants == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }
                    moyenne = somme / nbr_etudiants ;
                    printf("\n=========> La moyenne des notes saisi juasqu'a maintenant est moy = %f ..........................",moyenne);
                }
                break;
            case 3 :    // Affiche l'étudiant avec la meilleure et la pire note.      
                {
                    if( nbr_etudiants == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }
                    printf("\n=========>L'etudiant %s %s a la meilleur note = %.2f ......................", meilleur_n, meilleur_p ,meilleure_note );
                    printf("\n=========>L'etudiant %s %s a la pire note = %.2f ........................", pire_n, pire_p ,pire_note );

                }
                break;
            case 4 :    //  vérifier combien d'étudiants ont une note supérieure à la moyenne (après l'avoir calculée).
                {
                    if( nbr_etudiants == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }
                    moyenne = somme / nbr_etudiants ;
                    printf("\nentrez la note 1 : ");
                    scanf("%f",&n1);
                    printf("\nentrez la note 2 : ");
                    scanf("%f",&n2);
                    if( n1 > moyenne )
                        compt_sup++ ;
                    if( n2 > moyenne )
                        compt_sup++ ;
                    
                    printf("\n=========>Le nombre d'etudiants ont une note superieure a la moyenne %f est : %d ................", moyenne, compt_sup);
                }
                break;

            case 5 :    //  Quitter le programme.
                printf("\nQuitter le programme . ");
                break;
            default : 
                printf("\nOption non trouvee !!! ressayer une autre fois !");
            
        }

    }while( option != 5 );

    return 0 ;
}
