#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define MAP_H 10
#define MAP_L 10
#define MAP_JOUEUR 2
#define MAP_JOUEUR1 0
#define MAP_JOUEUR2 1
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
#define JOUEUR_ITEM 2
#define JOUEUR_1 0
#define JOUEUR_2 1
#define IMPACT 2
#define PLOUF 0
#define TOUCHE 1


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
int menu;
int map[MAP_H][MAP_L][MAP_JOUEUR];
int player[PLAYER_STATS][JOUEUR_ITEM];

printf("BATTAILLE NAVALE\n");
printf("1: Commencer une nouvelle partie\n");
printf("2: Reprendre une partie sauvegardée\n");
scanf("%d", &menu);
fflush(stdin);
switch (menu){
    case 1:
        printf("Chosir le mode de jeu :\n");
        printf("1: Joueur contre joueur\n");
        printf("2: Joueur contre IA\n");
        printf("3: IA contre IA\n");
        scanf("%d", &menu);
        fflush(stdin);
            switch(menu){
                case 1:
                    player[PLAYER_STATS]=2;
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    PosCorvette(map[MAP_H][MAP_L][MAP_JOUEUR],player[PlayervsPlayer]);
                    PosDestroyer(map[MAP_H][MAP_L][MAP_JOUEUR],player[PlayervsPlayer]);
                    PosCroiseur(map[MAP_H][MAP_L][MAP_JOUEUR],player[PlayervsPlayer]);
                    PosPorteAvion(map[MAP_H][MAP_L][MAP_JOUEUR],player[PlayervsPlayer]);
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    Attaque(map[MAP_H][MAP_L][MAP_JOUEUR],player[PlayervsPlayer][0]);
                    if(map[MAP_H][MAP_L][MAP_JOUEUR2]!=CORVETTE_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=DESTROYER_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=CROISEUR_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=PORTEAVION_ID){
                        printf("Les bateaux du joueur 2 ont été détruits !\n");
                        printf("Le Joueur 1 remporte la partie !\n");
                    }
                    else{
                        printf("Les bateaux du Joueur 1 ont été détruits !\n");
                        printf("Le Joueur 2 remporte la partie !\n");
                    }
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    break;

                case 2:
                    player[PLAYER_STATS]=1;
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    PosCorvette(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    PosDestroyer(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    PosCroiseur(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    PosPorteAvion(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    Attaque(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsPlayer]);
                    if(map[MAP_H][MAP_L][MAP_JOUEUR2]!=CORVETTE_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=DESTROYER_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=CROISEUR_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=PORTEAVION_ID){
                        printf("Les bateaux du joueur 2 ont été détruits !\n");
                        printf("Le Joueur 1 remporte la partie !\n");
                    }
                    else{
                        printf("Les bateaux du Joueur 1 ont été détruits !\n");
                        printf("Le Joueur 2 remporte la partie !\n");
                    }
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    break;

                case 3:
                    player[PLAYER_STATS]=0;
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    PosCorvette(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    PosDestroyer(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    PosCroiseur(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    PosPorteAvion(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    Attaque(map[MAP_H][MAP_L][MAP_JOUEUR],player[IAvsIA]);
                    if(map[MAP_H][MAP_L][MAP_JOUEUR2]!=CORVETTE_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=DESTROYER_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=CROISEUR_ID && map[MAP_H][MAP_L][MAP_JOUEUR2]!=PORTEAVION_ID){
                        printf("Les bateaux du joueur 2 ont été détruits !\n");
                        printf("Le Joueur 1 remporte la partie !\n");
                    }
                    else{
                        printf("Les bateaux du Joueur 1 ont été détruits !\n");
                        printf("Le Joueur 2 remporte la partie !\n");
                    }
                    AffichagePlateau(map[MAP_H][MAP_L][MAP_JOUEUR],0);
                    break;


            }
    break;
    case 2:
        load(map[MAP_H][MAP_L][MAP_JOUEUR]);
    break;
    }


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

void PosCorvette(int map[MAP_H][MAP_L][MAP_JOUEUR],int orientation,int player[PLAYER_STATS][JOUEUR_ITEM]){
    if (player[PLAYER_STATS]==0){ //ici le mode IA contre IA
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] == CORVETTE_ID;
       }
    }
    else if(player[PLAYER_STATS]==1){ //ici le monde IA contre JOUEUR
        player[JOUEUR_ITEM]=0;
        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez des coordonnées x et y pour votre Corvette\n");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR1] == 0){
                    map[x][y][MAP_JOUEUR1] == CORVETTE_ID;
                    player[JOUEUR_ITEM] = 1;
                }
            }
        }
        if(player[JOUEUR_ITEM]==1){
            int x=doRand(0,MAP_H-1);
            int y=doRand(0,MAP_L-1);
            if(map[x][y][MAP_JOUEUR2] == 0){
                map[x][y][MAP_JOUEUR2] = CORVETTE_ID;
            }
        }
    }
    else if(player[PLAYER_STATS]==2){ //ici le mode JOUEUR contre JOUEUR
        player[JOUEUR_ITEM]=0;
        while(JOUEUR_ITEM==0){
            printf("saisissez les coordonnées x et y de votre Corvette");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR1]==0){
                    map[x][y][MAP_JOUEUR1]=CORVETTE_ID;
                    JOUEUR_ITEM=1;
                }
            }
        }
        if(player[JOUEUR_ITEM]==1){
            printf("Saisissez les coordronnées x et y de votre Corvette");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR2]==0){
                    map[x][y][MAP_JOUEUR2]==CORVETTE_ID;
                }
            }
        }
    }
}

void PosPorteAvion(int map[MAP_H][MAP_L][MAP_JOUEUR],int orientation,int player[PLAYER_STATS][JOUEUR_ITEM]){
    if (player[PLAYER_STATS]=0){
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
            while(map[x][y][MAP_JOUEUR]=0){
                int orientation=doRand(0,1);
                if(orientation = 1){
                    int i;
                    for(i=0; i<PORTEAVION_ID ;i++){
                        x==x+1;
                        if(x+i=>1 && x+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                        }
                        else{
                            int x=doRand(0,MAP_H-1);
                        }
                    }
                }
                else if(orientation=0){
                    int j;
                    for(j=0; j<PORTEAVION_ID; j++){
                        y==y+1;
                        if(y+i=>1 && y+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                            printf("la position est valide");
                        }
                        else{
                            int y=doRand(0,MAP_L-1);
                        }
                    }
                }
            }
       }
    }else if(player[PLAYER_STATS]==1){
        player[JOUEUR_ITEM]=0;
        printf("Veuillez indiquer la valeur de l'orientation\n");
        scanf("%d",&orientation);
        fflush(stdin);
        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Porte-Avion");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<PORTEAVION_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<PORTEAVION_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{


                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
            int x=doRand(0,MAP_H-1);
            int y=doRand(0,MAP_L-1);
            if(map[x][y][MAP_JOUEUR] == 0){
                while(map[x][y][MAP_JOUEUR]=0){
                    int orientation=doRand(0,1);
                    if(orientation = 1){
                        int i;
                        for(i=0; i<PORTEAVION_ID ;i++){
                            x==x+1;
                            if(x+i=>1 && x+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                            }
                            else{
                                int x=doRand(0,MAP_H-1);
                            }
                        }
                    }
                    else if(orientation=0){
                        int j;
                        for(j=0; j<PORTEAVION_ID; j++){
                            y==y+1;
                            if(y+i=>1 && y+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                printf("la position est valide");
                            }
                            else{
                                int y=doRand(0,MAP_L-1);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(player[PLAYER_STATS]==2){
        player[JOUEUR_ITEM]=0;

        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Porte-Avion");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<PORTEAVION_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<PORTEAVION_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
             printf("Saisissez les coordonnées x et y de votre Porte-Avion");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<PORTEAVION_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<PORTEAVION_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=PORTEAVION_ID;
                                    printf("la position est valide");
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }
        }
    }


}

void PosDestroyer(int map[MAP_H][MAP_L][MAP_JOUEUR],int orientation,int player[PLAYER_STATS][JOUEUR_ITEM]){
    if (player[PLAYER_STATS]=0){
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
            while(map[x][y][MAP_JOUEUR]=0){
                int orientation=doRand(0,1);
                if(orientation = 1){
                    int i;
                    for(i=0; i<DESTROYER_ID ;i++){
                        x==x+1;
                        if(x+i=>1 && x+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]==DESTROYER_ID;
                        }
                        else{
                            int x=doRand(0,MAP_H-1);
                        }
                    }
                }
                else if(orientation=0){
                    int j;
                    for(j=0; j<DESTROYER_ID; j++){
                        y==y+1;
                        if(y+i=>1 && y+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]==DESTROYER_ID
                            printf("la position est valide");
                        }
                        else{
                            int y=doRand(0,MAP_L-1);
                        }
                    }
                }
            }
       }
    }else if(player[PLAYER_STATS]==1){
        player[JOUEUR_ITEM]=0;
        printf("Veuillez indiquer la valeur de l'orientation\n");
        scanf("%d",&orientation);
        fflush(stdin);
        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Destroyer");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<DESTROYER_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<DESTROYER_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
            int x=doRand(0,MAP_H-1);
            int y=doRand(0,MAP_L-1);
            if(map[x][y][MAP_JOUEUR] == 0){
                while(map[x][y][MAP_JOUEUR]=0){
                    int orientation=doRand(0,1);
                    if(orientation = 1){
                        int i;
                        for(i=0; i<DESTROYER_ID ;i++){
                            x==x+1;
                            if(x+i=>1 && x+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]==DESTROYER_ID;
                            }
                            else{
                                int x=doRand(0,MAP_H-1);
                            }
                        }
                    }
                    else if(orientation=0){
                        int j;
                        for(j=0; j<DESTROYER_ID; j++){
                            y==y+1;
                            if(y+i=>1 && y+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]==DESTROYER_ID
                                printf("la position est valide");
                            }
                            else{
                                int y=doRand(0,MAP_L-1);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(player[PLAYER_STATS]==2){
        player[JOUEUR_ITEM]=0;

        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Destroyer");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<DESTROYER_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<DESTROYER_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
             printf("Saisissez les coordonnées x et y de votre Destroyer");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<DESTROYER_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<DESTROYER_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==DESTROYER_ID
                                    printf("la position est valide");
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void PosCroiseur(int map[MAP_H][MAP_L][MAP_JOUEUR],int orientation,int player[PLAYER_STATS][JOUEUR_ITEM]){
    if (player[PLAYER_STATS]=0){ // IA VS IA
       int x=doRand(0,MAP_H-1);
       int y=doRand(0,MAP_L-1);
       if(map[x][y][MAP_JOUEUR] == 0){
            while(map[x][y][MAP_JOUEUR]=0){
                int orientation=doRand(0,1);
                if(orientation = 1){
                    int i;
                    for(i=0; i<CROISEUR_ID ;i++){
                        x==x+1;
                        if(x+i=>1 && x+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]==CROISEUR_ID;
                        }
                        else{
                            int x=doRand(0,MAP_H-1);
                        }
                    }
                }
                else if(orientation=0){
                    int j;
                    for(j=0; j<CROISEUR_ID; j++){
                        y==y+1;
                        if(y+i=>1 && y+i<=MAP_H-1){
                            map[x][y][MAP_JOUEUR]==CROISEUR_ID;
                            printf("la position est valide");
                        }
                        else{
                            int y=doRand(0,MAP_L-1);
                        }
                    }
                }
            }
       }
    }else if(player[PLAYER_STATS]==1){//Ici IA vs Player
        player[JOUEUR_ITEM]=0;
        printf("Veuillez indiquer la valeur de l'orientation\n");
        scanf("%d",&orientation);
        fflush(stdin);
        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Croiseur");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<CROISEUR_ID ;i++){
                                x=x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=CROISEUR_ID;
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<CROISEUR_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]==CROISEUR_ID;
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM]=1;
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
            int x=doRand(0,MAP_H-1);
            int y=doRand(0,MAP_L-1);
            if(map[x][y][MAP_JOUEUR] == 0){
                while(map[x][y][MAP_JOUEUR]=0){
                    int orientation=doRand(0,1);
                    if(orientation = 1){
                        int i;
                        for(i=0; i<CROISEUR_ID ;i++){
                            x==x+1;
                            if(x+i=>1 && x+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]==CROISEUR_ID;
                            }
                            else{
                                int x=doRand(0,MAP_H-1);
                            }
                        }
                    }
                    else if(orientation=0){
                        int j;
                        for(j=0; j<CROISEUR_ID; j++){
                            y==y+1;
                            if(y+i=>1 && y+i<=MAP_H-1){
                                map[x][y][MAP_JOUEUR]==CROISEUR_ID;
                                printf("la position est valide");
                            }
                            else{
                                int y=doRand(0,MAP_L-1);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(player[PLAYER_STATS]==2){
        player[JOUEUR_ITEM=*=0;

        while(player[JOUEUR_ITEM]==0){
            printf("Saisissez les coordonnées x et y de votre Croiseur");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<CROISEUR_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=CROISEUR_ID;
                                    player[JOUEUR_ITEM=1];
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<CROISEUR_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=CROISEUR_ID;
                                    printf("la position est valide");
                                    player[JOUEUR_ITEM=1];
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }

        }
        if(player[JOUEUR_ITEM]==1){
             printf("Saisissez les coordonnées x et y de votre Croiseur");
            scanf("%d",&x);
            fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            printf("Veuillez indiquer la valeur de l'orientation\n");
            scanf("%d",&orientation);
            fflush(stdin);
            if(x=>0 && x<=MAP_H-1 && y=>0 && y<=MAP_L-1){
                if(map[x][y][MAP_JOUEUR] == 0){
                    while(map[x][y][MAP_JOUEUR]=0){
                        if(orientation = 1){
                            int i;
                            for(i=0; i<CROISEUR_ID ;i++){
                                x==x+1;
                                if(x+i=>1 && x+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=CROISEUR_ID;
                                    player[JOUEUR_ITEM=1;
                                }
                                else{
                                    scanf("%d",&x);
                                    fflush(stdin);
                                }
                            }
                        }
                        else if(orientation=0){
                            int j;
                            for(j=0; j<CROISEUR_ID; j++){
                                y==y+1;
                                if(y+i=>1 && y+i<=MAP_H-1){
                                    map[x][y][MAP_JOUEUR]=CROISEUR_ID;
                                    printf("la position est valide");
                                }
                                else{
                                    scanf("%d",&y);
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Attaque(int map[MAP_H][MAP_L][MAP_JOUEUR], int impact,int player[PLAYER_STATS][JOUEUR_ITEM]){
    int choix;
    if(choix=player[IAvsIA]){
        while(player[JOUEUR_ITEM]!=1){
            while(map[x][y][MAP_JOUEUR1]=CORVETTE_ID || map[x][y][MAP_JOUEUR1]=DESTROYER_ID || map[x][y][MAP_JOUEUR1]=CROISEUR_ID || map[x][y][MAP_JOUEUR1]=PORTEAVION_ID){
                int x=doRand(0,MAP_H-1);
                int y=doRand(0,MAP_L-1);
                    if(map[x][y][MAP_JOUEUR1]=CORVETTE_ID || map[x][y][MAP_JOUEUR1]=DESTROYER_ID || map[x][y][MAP_JOUEUR1]=CROISEUR_ID || map[x][y][MAP_JOUEUR1]=PORTEAVION_ID){
                        map[x][y][MAP_JOUEUR1]=TOUCHE;
                        printf("Contact, Bateau touché");
                        Save;
                        player[JOUEUR_ITEM]=1;


                    }
                    else{
                        map[x][y][MAP_JOUEUR1]=PLOUF;
                        printf("C'est à la flotte");
                        Save;
                        player[JOUEUR_ITEM]=1;

                    }
                }
            }
        }
        while(player[JOUEUR_ITEM]!=0){
            while(map[x][y][MAP_JOUEUR2]=CORVETTE_ID || map[x][y][MAP_JOUEUR2]=DESTROYER_ID || map[x][y][MAP_JOUEUR2]=CROISEUR_ID || map[x][y][MAP_JOUEUR2]=PORTEAVION_ID){
                int x=doRand(0,MAP_H-1);
                int y=doRand(0,MAP_L-1);
                    if(map[x][y][MAP_JOUEUR2]=CORVETTE_ID || map[x][y][MAP_JOUEUR2]=DESTROYER_ID || map[x][y][MAP_JOUEUR2]=CROISEUR_ID || map[x][y][MAP_JOUEUR2]=PORTEAVION_ID){
                        map[x][y][MAP_JOUEUR2]=TOUCHE;
                        printf("Contact, Bateau touché");
                        Save;
                        player[JOUEUR_ITEM]=0;
                    }
                    else{
                        map[x][y][MAP_JOUEUR1]=PLOUF;
                        printf("C'est à la flotte");
                        Save;
                        player[JOUEUR_ITEM]=0;
                    }
            }
        }
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
















