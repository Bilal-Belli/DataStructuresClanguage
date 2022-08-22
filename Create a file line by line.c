#include <stdio.h>

struct Tenreg
    {
        char ligne[256];  // variable enregistrement
    } e;
    
int main()
{   
    FILE *f;
    char nom_fichier[200];
    
    printf("\nConstruction du fichier\n");   // instruction a l'utilisateur
    
    printf("Donnez nom_fichier : ");         //scanner le nom du fichier meme si il ya des espaces
    
    gets(nom_fichier);                       // creation du nouveau fichier
    
    f = fopen( nom_fichier, "w" );           // insertion des enregistrements lus à la console
    
    printf("donnez un ligne ( 0 pour terminer ) : ");   
    
    gets(e.ligne);                           // scanner la ligne donneé par utilisateur
    while ( e.ligne[0] != '0' )
    {
                                            
        fprintf(f, "%s\n", e.ligne );        // chaque ligne est un variable existe dans l'enregistrement
        
        printf("donnez un ligne ( 0 pour terminer ) : ");
        
        gets(e.ligne);                      // scanner la ligne donneé par utilisateur (boucle)
    }
    
    fclose( f );
    
    return 0;
    
}
