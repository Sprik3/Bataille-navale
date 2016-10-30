#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define MAP_H 10
#define MAP_L 10
#define MAP_JOUEUR 2
#define TAILLECORVETTE 1
#define CORVETTE_ID 1
#define TAILLEDESTROYER 2
#define DESTROYER_ID 2
#define TAILLEPORTEAVION 4
#define PORTEAVION_ID 4
#define TAILLECROISEUR 3
#define CROISEUR_ID 3
#define PLAYER_STATS 3
#define IAvsIA 0
#define IAvsPlayer 1
#define PlayervsPlayer 2
#define JOUEUR_ITEM
#define


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

int main (){
/*printf("BATTAILLE NAVALE\n");
printf("1: Commencer une nouvelle partie\n");
printf("2: Reprendre une partie sauvegardée\n");
switch (choix){
    case 1:
        printf("Chosir le mode de jeu :\n");
        printf("1: Joueur contre joueur\n");
        printf("2: Joueur contre IA\n");
        printf("3: IA contre IA\n");
    break;
    case 2://mettre le menu load
    break;

    switch(choix2){
        case 1://Mettre le deroulement d'une partie avec en plus le fait de pouvoir definir deux joueurs
        break;
        case 2://Mettre la possibilité de jouer pour 1 joeuur et mettre ne place une IA pouvant jouer
        break;
        case 3://Mettre en place deux IA pouvant jouer l'une contre l'autre
        break;


    }


}*/
int player[PLAYER_STATS][JOUEUR_ITEM]={0};
int grille(map[MAP_H][MAP_L][MAP_JOUEUR])={0};
AffichagePlateau(grille,0);

}


//void DeroulementPartieIAvIA(){
//}

//void DeroulementPartieJvIA(){
//

//void DeroulementPartieJvJ(){
//}

void AffichagePlateau(int map[MAP_H][MAP_L][MAP_JOUEUR],int item){
    int i,j;
    printf("Y/X.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.X/Y");
    for(i=-1;i<MAP_H+1;i++){
            if(i<10){
                printf(" %d |",i);
            }
            else {
                printf("%d |",i);
            }
        for(j=-1;j<MAP_L+1;j++){
            printf(" %d ",map[i][j][item]);
            }
        }
         printf("\n");

    }


}

void PosCorvette (int map[MAP_H][MAP_L][MAP_JOUEUR],int niveau, int player[PLAYER_STATS]){
    int choix;
    scanf("%d",&choix);
    fflush(stdin);
    if (choix=player[IAvsIA]){
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] == CORVETTE_ID;
       }
    }
}

void PosPorte-Avion(int map[MAP_H][MAP_L][MAP_JOUEUR],int niveau){

}

void PosDestroyer(int map[MAP_H][MAP_L][MAP_JOUEUR],int niveau){
    int choix;
    scanf("%d",&choix);
    fflush(stdin);
    if (choix=player[IAvsIA]){
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] == DESTROYER_ID;
       }
    }
}

void PosCroiseur(int map[MAP_H][MAP_L][MAP_JOUEUR],int niveau){

}

void iAvsiA (){

}

void Save (int map[MAP_H][MAP_L][MAP_JOUEUR]){
FILE * fp;
    fp=fopen("./file.txt","w+");
    int i,j,k;
    for(i = 0; i<MAP_H ; i++){
        for(j = 0; j<MAP_L; j++){
            for(k = 0; j<MAP_JOUEUR; k++){
                fprintf(fp, "%c", (char)map[i][j][k]);
            }
        }
    }
    fclose(fp);
}

void load (int map[MAP_H][MAP_L][MAP_JOUEUR]){
    FILE * fp;
    int i,j,k;
    char c;

    fp=fopen("./file.txt","r");
    for(i=0;i<MAP_H;i++){
        for(j=0;j<MAP_L;j++){
            for(k=0;k<MAP_JOUEUR;k++){
                c=fgetc(fp);
                    if( feof(fp)){
                        break;
                    }
                    map[i][j][k]=(int)c;
            }
        }
    }
    fclose(fp);

}





























