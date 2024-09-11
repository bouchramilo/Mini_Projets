#include<stdio.h>
#include<stdlib.h>
#include<String.h>

int main(){
    // declaration 
    char noms[100][100], prenoms[100][100], prenom[50], nom[50];
    int notes[100] ;
    float somme = 0 , moyenne, note, note_max = 0, note_min = 100; 
    int i_max=0 , i_min=0 , compt_sup = 0 , option, compteur=0;

    printf("\nChoisissez un option parmi Les 5 options :  \n");

    do{
        printf("\n========= le menu :=========== \n");
        printf("\n1..Ajouter des etudiants :  \n");
        printf("\n2..Afficher la moyenne:  ");
        printf("\n3..Afficher les meilleures et moins bonnes notes : \n");
        printf("\n4..Voir le nombre d'etudiants ayant une note superieure a la moyenne :\n");
        printf("\n5..Quitter le programme : \n");
        printf("\n==============================\n");
        
        scanf("%d",&option);

        switch(option){
            case 1 :    // ajouter des etudiant
                {
                    if( compteur >=100 ){
                        printf("\n---->Vous avez depasser le nombre max d'etudiants : "); 
                    }
                    printf("\nEntrez le nom d'etudiant : ");
                    scanf("%s",nom);
                    printf("\nEntrez le prenom d'etudiant : ");
                    scanf("%s",prenom);
                    printf("\nEntrez la note d'etudiant : ");
                    scanf("%f",&note);

                    strcpy(prenoms[compteur], prenom);
                    strcpy(noms[compteur], nom);
                    notes[compteur] = note ;

                    if( notes[compteur] > note_max ){
                        i_max = compteur ;
                        note_max = notes[compteur];
                    }
                    if( notes[compteur] < note_min ){
                        i_min = compteur ;
                        note_min = notes[compteur];
                    } 

                    compteur++ ;
                    printf("\nbravo,  vous avez ajoutez un etudiant .");
                }
                break;

            case 2 :    // Calcule et affiche la moyenne si des étudiants ont été ajoutés.
                {
                    if( compteur == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }
                    for(int i=0 ; i<compteur ; i++){
                        somme = somme + notes[i];
                    }

                    moyenne = somme / compteur ;
                    printf("\n===> La moyenne des notes saisi juasqu'a maintenant est moy = %f ",moyenne);
                }
                break;
            case 3 :    // Affiche l'étudiant avec la meilleure et la pire note.      
                {
                    if( compteur == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }
                    
                        printf("\nla meilleur note est de %s %s est %.2f:",noms[i_max], prenoms[i_max], note_max);
                        printf("\nla pire note est de %s %s est %.2f:",noms[i_min], prenoms[i_min], note_min);

                }
                break;
            case 4 :    //  vérifier combien d'étudiants ont une note supérieure à la moyenne (après l'avoir calculée).
                {
                    if( compteur == 0 ){
                        printf("\n---->La liste des etudiant est vide !! ");
                    }

                    for(int i=0 ; i<compteur ; i++){
                        somme = somme + notes[i];
                    }
                    moyenne = somme / compteur ;

                    for(int i=0 ; i<compteur ; i++){
                        if( notes[i] > moyenne ){
                            compt_sup++;
                        }
                    } 
                    printf("\n====>Le nombre d'etudiants ont une note superieure e la moyenne est : %d ",compt_sup);
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
