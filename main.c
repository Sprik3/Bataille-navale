#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>


int tp1(){
    int j1 = 5;
    char j1Name[20];
    int j2 = 7;
    char j2Name[20];
    int panierCommun;
    int scanResult = -1;

    printf("Nom personne 1\n");
    while(scanResult < 1){
        scanResult = scanf("%20[A-Za-z]",j1Name);
        //printf("scanResult = %d\nName = %s\n", scanResult,j1Name);
        fflush(stdin);
    }

    scanResult = -1;

    printf("Nom personne 2\n");
    while(scanResult < 1){
        scanResult = scanf("%20[A-Za-z]",j2Name);
        //printf("scanResult = %d\nName = %s\n", scanResult,j2Name);
        fflush(stdin);
    }

    printf("%s a %d pommes\n",j1Name,j1);
    printf("%s a %d pommes\n",j2Name,j2);
    panierCommun = j1 + j2;
    printf("Dans le panier commun il y a %d pommes\n",panierCommun);

    printf("Press Any Key to Continue\n");
    getchar();

    while(j1 != 0 && j2 != 0){
        system("cls");
        do{
            printf("Pommes pour %s? ",j1Name);
            if(scanf("%d[1234567890]",&j1)<=0){
                printf("Input error\n");
                j1 = -1;
            }
            fflush(stdin);
        }while(j1 < 0);
        printf("%s a %d pommes\n",j1Name,j1);

        do{
            printf("Pommes pour %s? ",j2Name);
            if(!scanf("%d[1234567890]",&j2)>0){
                printf("Input error\n");
                j2 = -1;
            }
            fflush(stdin);
        }while(j2 < 0);
        printf("%s a %d pommes\n",j2Name,j2);

        printf("\n");
        panierCommun = j1 + j2;
        printf("Dans le panier commun il y a %d pommes\n",panierCommun);

        printf("Press Any Key to Continue\n");
        getchar();
    }

    return 0;
}

int Variable(){
    float saisi;
    while(1){
        //scanf("%d[1234567890]",&saisi);
        scanf("%f",&saisi);

        printf("Affichage entier %d\n",saisi);
        printf("Affichage caractère %c\n",saisi);
        printf("Affichage hexa min %x\n",saisi);
        printf("Affichage hexa maj %X\n",saisi);
        printf("Affichage octal %o\n",saisi);
        printf("Affichage reel 1 %f\n",saisi);
        printf("Affichage reel 2 %g\n",saisi);
        fflush(stdin);
    }

    return 0;
}

int Bkp(){
    int ii;
    char saisi[20] = {0};
    scanf("%30[abcdefghijklmnopqrstuvwxyz]",saisi);
    printf("\n%s\n",saisi);


    saisi[10] = '\0';
    printf("\n%s\n",saisi);

    for(ii = 0; ii < 20; ii++){
        printf("%c",saisi[ii]);
    }
    printf("\n");

    for(ii = 0; ii < 31; ii++){
        printf("%c",saisi[ii]);
    }
    printf("\n");

    return 0;
}

int Randomer(){
    int result[13] = {0};
    int randed;
    srand(rand());

    int i;
    for(i = 0; i < 13; i++){
        randed = rand() % ((13 + 1 - 1) + 1);
        result[randed]++;
    }

    for(i = 0; i <13; i++){
        printf("Personne %d result %d\n",i,result[i]);
    }
}





int tp5(){
    int saisi1 = 0;
    int saisi2 = 0;
    int ii = 0;

    while(saisi1 != 1 && saisi1 != 2 && saisi1 != 3
        && saisi1 != 4 && saisi1 != 5){
        printf("Saisir soit 1 soit 2 soit 3 soit 4 soit 5\n");
        scanf("%d[0-9]",&saisi1);
        fflush(stdin);
    }

    for(ii = 0; ii < 3; ii++){
        printf("Saisir soit 13 soit 14 soit 15\n");
        scanf("%d[0-9]",&saisi2);
        fflush(stdin);
        if(saisi2 == 13 || saisi2 == 14 || saisi2 == 15){
            break;
        }else{
            saisi2 = 0;
        }
    }

    if(saisi2 != 0){
        printf("La somme est %d le produit est %d\n"
               ,saisi1+saisi2
               ,saisi1*saisi2);
    }else{
        printf("Le double est %d le carre est %d\n"
               ,saisi1*2
               ,saisi1*saisi1);
    }

    return 0;
}

int tp6()
{
    int user = 10;
    while(user){
        system("cls");
        int i = 0;

        char myTab[20] = {0};

        printf("Choix menu :\n1:espace\n2:inverse\n3:demi\n0 pour arrêter\n");
        scanf("%d", &user);
        fflush(stdin);

        if(user == 1){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=0; i<20; i++){
                if(myTab[i]!=0){
                    printf("%c ", myTab[i]);
                }
            }
            fflush(stdin);
            getchar();
        }else if(user == 2){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=19; i>=0; i--){
                if(myTab[i]!=0){
                    printf("%c", myTab[i]);
                }
            }

            fflush(stdin);
            getchar();
        }else if(user == 3){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=0; i<20; i++){
                if(i % 2 == 0 && myTab[i]!=0){
                    printf("%c", myTab[i]);
                }
            }
            fflush(stdin);
            getchar();
        }else{
        }
    }
}

int Square(){
    while(1){
        int a = 0;
        int b = 0;
        int i,j;
        printf("Saisir a\n");
        scanf("%d[0-9]", &a);
        fflush(stdin);
        printf("Saisir b\n");

        scanf("%d[0-9]", &b);
        fflush(stdin);

        if(a < 2 && b < 2){
            a = 2;
            b = 2;
        }
        for(i = 0; i<a; i++){
            printf("# ");
        }
        printf("\n");
        for(i=0;i<b-2;i++){
            for(j=0;j<a;j++){
                if(j==0 || j==a-1){
                    printf("# ");
                }else{
                    printf("  ");
                }
            }
            printf("\n");
        }
        for(i = 0; i<a; i++){
            printf("# ");
        }
        printf("\n");
    }
}

int Square1(){
    while(1){
        int a = 0;
        int b = 0;
        int i,j;
        printf("Saisir a\n");
        scanf("%d[0-9]", &a);
        fflush(stdin);
        printf("Saisir b\n");

        scanf("%d[0-9]", &b);
        fflush(stdin);

        if(a < 2 && b < 2){
            a = 2;
            b = 2;
        }

        for(i=0;i<b;i++){
            for(j=0;j<a;j++){
                if(i==0 || i==b-1 || j == 0 || j == a - 1){
                    printf("# ");
                }else{
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

int Square2(){
    while(1){
        int a = 0;
        int b = 0;
        int i,j;
        //11//10
        printf("Saisir a\n");
        scanf("%d[0-9]", &a);
        fflush(stdin);
        printf("Saisir b\n");

        scanf("%d[0-9]", &b);
        fflush(stdin);

        /*Damié
                if(i==0 || i == b-1 || j == 0 || j == a-1
                    || ((i%2==0 && j%2 == 0)
                    ||  ((j%2 == 1 || i%2==0) && (j%2 == 0 || i%2==1)))){
                    printf("# ");
                }else{
                    printf("  ");
                }
        */
        //i%2==0 || (i%(b-1))%2 == 0 || j%2 == 0 || (j%(a-1))%2 == 0
        /*
                if(i==0 || i == b-1 || j == 0 || j == a-1){
                    printf("# ");
                }else if((i==2 && j != 1 && j != a-2)
                         || (i == b-3 && j != a-2 && j != 1)
                         || (j == 2 && i != 1 && i != b-2)
                         || (j == a-3 && i != b-2 && i != 1)){
                    printf("# ");
                }else{
                    printf("  ");
                }
        */

        int loopI = 0;
        int loopJ = 0;
        for(i=0;i<b;i++){
            for(j=0;j<a;j++){
                if(i==loopI || i == b-1 || j == loopJ || j == a-1){
                    printf("# ");
                }/*else if((i==2 && j != 1 && j != a-2)
                         || (i == b-3 && j != a-2 && j != 1)
                         || (j == 2 && i != 1 && i != b-2)
                         || (j == a-3 && i != b-2 && i != 1)){
                    printf("# ");
                }else if((i==4 && j != 3 && j != a-4 && j != a-2 && j != 1)
                         || (i == b-5 && j != a-4 && j != 3 && j != a-2 && j!=1)
                         || (j == 4 && i != 3 && i != b-4 && i != b-2 && i != 1)
                         || (j == a-5 && i != b-4 && i != 3 && i != 1 && i != b-2)){
                    printf("# ");
                }*/else{
                    printf("  ");
                }
            }
            loopJ += 2;
            loopI += 2;
            printf("\n");
        }
        printf("\n");
    }
}

int Multiplication(){
    int table = 10;
    int nombre = 10;
    int ii, jj;
    for(ii = 0; ii <11; ii++){
        for(jj = 0; jj <11; jj++){
            if(ii == 0){
                if(jj != 0){
                    if(jj > 9){
                        printf("%d    ",jj);
                    }else if(jj > 99){
                        printf("%d   ",jj);
                    }else{
                        printf("%d     ",jj);
                    }
                }else{
                    printf("\\     ");
                }
            }else if(jj == 0){
                if(ii != 0){
                    if(ii > 9){
                        printf("%d    ",ii);
                    }else if(ii > 99){
                        printf("%d   ",ii);
                    }else{
                        printf("%d     ",ii);
                    }
                }
            }else if(ii * jj > 9){
                printf("%d    ",ii*jj);
            }else if(ii * jj > 99){
                printf("%d   ",ii*jj);
            }else if(ii * jj > 999){
                printf("%d  ",ii*jj);
            }else{
                printf("%d     ",ii*jj);
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    printf("Saisir la table souhaité\n");
    scanf("%d[0-9]", &table);
    fflush(stdin);
    printf("Saisir le nombre maximal d'éléments souhaité\n");
    scanf("%d[0-9]", &nombre);
    fflush(stdin);

    for(jj = 0; jj < nombre; jj++){
        printf("%d ",table*jj);
    }
    printf("\n");
}

int Secret(int boucle){

    while(boucle){
        system("cls");
        char saisi[100] = {0};
        int result[100] = {0};
        int clef = 10;
        int i;

        printf("Saisir votre text\n");
        scanf("%100[ -~]",saisi);
        fflush(stdin);

        printf("Saisir votre clef\n");
        scanf("%d[0-9]",&clef);
        fflush(stdin);

        for(i = 0; i < 100; i++){
            if((int)saisi[i] != 0){
                result[i] = (int)saisi[i]*(int)saisi[i]-(int)saisi[i]+clef;
            }
        }

        for(i = 0; i < 100; i++){
            if(result[i] != 0){
                printf("%d ",result[i]);
            }
        }

        printf("\n");
        getchar();
        boucle--;
    }
}

int SecretReverse(int boucle){
    while(boucle){
        char saisi[100] = {0};
        int result[100] = {0};
        int clef = 10;

        int j = 0;
        int valeur = 1;
        int correspond[93][2];

        int i = 0;
        while(valeur != 0){
            printf("Saisir les codes 1 a 1 utiliser 0 pour arreter\n");
            scanf("%d[0-9]",&valeur);
            result[i] = valeur;
            fflush(stdin);
            i++;
        }

        printf("Saisir la clef\n");
        scanf("%d[0-9]",&clef);
        fflush(stdin);

        for(i = 0; i < 93; i++){
            correspond[i][0] = i+33;
            correspond[i][1] = ((i+33)*(i+33))-(i+33)+clef;
        }

        for(i = 0; i < 100; i++){
            for(j = 0; j < 93; j++){
                if(result[i] == correspond[j][1]){
                    saisi[i] = (char)correspond[j][0];
                }
            }
        }

        printf("Votre code vaut : ");
        for(i = 0; i < 100; i++){
            if(saisi[i] != 0){
                printf("%c",saisi[i]);
            }
        }
        printf("\n");
        getchar();
        boucle--;
    }
}

int SecretAndUnsecret(){
    while(1){
        Secret(1);
        printf("\n");
        SecretReverse(1);
    }
}


#define MAP_H 10
#define MAP_W 20
#define MAP_ITEMS 3
#define MAP_SOL 0
#define MAP_MOVE_TO_PAID 1
#define MAP_PLAYER 2
#define PLAYER_MOVE_POINT 10
#define ID_J1 1
#define ID_J2 2
#define ID_J3 3
#define ID_J4 4
#define HERBE 1
#define MOVE_HERBE 1
#define SABLE 2
#define MOVE_SABLE 3
#define ROCHER 3
#define MOVE_ROCHER 5
#define PLAYER_STATS 4
#define X 0
#define Y 1
#define MP 2
#define ID 3

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

void PrintTableau(int map[MAP_H][MAP_W][MAP_ITEMS],int item){
    int i,j;
    for(i = -1;i < MAP_H+1; i++){
        for(j = -1;j < MAP_W+1; j++){
            if(i == -1 || i == MAP_H || j == -1 || j == MAP_W){
                printf("#");
            }else{
                if(map[i][j][item]!=0){
                    printf("%d",map[i][j][item]);
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void JeuRencontreInit(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int i,j;
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            map[i][j][MAP_SOL] = doRand(1,3);
            switch(map[i][j][MAP_SOL]){
                case HERBE:
                    map[i][j][MAP_MOVE_TO_PAID] = MOVE_HERBE;
                    break;
                case SABLE:
                    map[i][j][MAP_MOVE_TO_PAID] = MOVE_SABLE;
                    break;
                case ROCHER:
                    map[i][j][MAP_MOVE_TO_PAID] = MOVE_ROCHER;
                    break;
            }
        }
    }
}

void JeuRencontrePlacementJoueur(int player[PLAYER_STATS],int map[MAP_H][MAP_W][MAP_ITEMS]){
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
    if(map[x][y][MAP_PLAYER] == 0){
        map[x][y][MAP_PLAYER] = player[ID];
        player[X] = x;
        player[Y] = y;
    }else{
        JeuRencontrePlacementJoueur(player,map);
    }
}

void JeuRencontreDeplacement(int player[PLAYER_STATS],int destination[PLAYER_STATS],int map[MAP_H][MAP_W][MAP_ITEMS]){
    //printf("deplacement\n");
    while(player[MP]>0 && (player[X] != destination[X] || player[Y] != destination[Y])){
        //waitFor(1.5);
        system("cls");
        MessageBeep(MB_ICONWARNING);
        //printf("MP = %d\n", player[MP]);
        if(destination[X]>player[X] && map[player[X]+1][player[Y]][MAP_MOVE_TO_PAID] <= player[MP]){
            map[player[X]][player[Y]][MAP_PLAYER] = 0;
            map[player[X]+1][player[Y]][MAP_PLAYER] = player[ID];
            player[MP] -= map[player[X]+1][player[Y]][MAP_MOVE_TO_PAID];
            player[X]++;
        }else if(destination[X]<player[X] && map[player[X]-1][player[Y]][MAP_MOVE_TO_PAID] <= player[MP]){
            map[player[X]][player[Y]][MAP_PLAYER] = 0;
            map[player[X]-1][player[Y]][MAP_PLAYER] = player[ID];
            player[MP] -= map[player[X]-1][player[Y]][MAP_MOVE_TO_PAID];
            player[X]--;
        }else if(destination[Y]>player[Y] && map[player[X]][player[Y]+1][MAP_MOVE_TO_PAID] <= player[MP]){
            map[player[X]][player[Y]][MAP_PLAYER] = 0;
            map[player[X]][player[Y]+1][MAP_PLAYER] = player[ID];
            player[MP] -= map[player[X]][player[Y]+1][MAP_MOVE_TO_PAID];
            player[Y]++;
        }else if(destination[Y]<player[Y] && map[player[X]][player[Y]-1][MAP_MOVE_TO_PAID] <= player[MP]){
            map[player[X]][player[Y]][MAP_PLAYER] = 0;
            map[player[X]][player[Y]-1][MAP_PLAYER] = player[ID];
            player[MP] -= map[player[X]][player[Y]-1][MAP_MOVE_TO_PAID];
            player[Y]--;
        }else{
            player[MP] = 0;
        }
        PrintTableau(map,MAP_PLAYER);
    }
    //printf("MP = %d\n", player[MP]);
}

void JeuRencontreSave(int map[MAP_H][MAP_W][MAP_ITEMS]){
    /*FILE *fptr=fopen("./save.txt","wb");
    fwrite(map , sizeof(int) , MAP_H*MAP_W*MAP_ITEMS , fptr);
    fclose(fptr);*/
    FILE * fp;

    fp = fopen ("./file.txt", "w+");
    int i,j,k;
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            for(k = 0;k < MAP_ITEMS; k++){
                fprintf(fp, "%c", (char)map[i][j][k]);
            }
        }
    }

    fclose(fp);
}

void JeuRencontreLoad(int map[MAP_H][MAP_W][MAP_ITEMS]){
    /*FILE *ifp = fopen("/save.txt", "rb");
    fread(map, sizeof(int), MAP_H*MAP_W*MAP_ITEMS, ifp);*/
    FILE *fp;
    int i,j,k;
    char c;

    fp = fopen("./file.txt","r");
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            for(k = 0;k < MAP_ITEMS; k++){
                c = fgetc(fp);
                if( feof(fp) )
                {
                    break;
                }
                map[i][j][k]=(int)c;
            }
        }
    }
    fclose(fp);

    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            map[i][j][MAP_PLAYER]=0;
        }
    }


    /*fp = fopen("./file.txt","r");
    while(1)
    {
        c = fgetc(fp);
        if( feof(fp) )
        {
            break;
        }
        printf("%c ", c);
    }
    fclose(fp);*/
}

void JeuRencontre(){
    int save = 1;
    int player1[PLAYER_STATS];
    player1[ID] = ID_J1;
    int player2[PLAYER_STATS];
    player2[ID] = ID_J2;
    /*int player3[PLAYER_STATS];
    player3[ID] = ID_J3;
    int player4[PLAYER_STATS];
    player4[ID] = ID_J4;*/
    int map[MAP_H][MAP_W][MAP_ITEMS] = {0};

    JeuRencontreInit(map);
    // JeuRencontreLoad(map);
    PrintTableau(map,MAP_SOL);
    printf("////////////////////////////////////////\n");
    PrintTableau(map,MAP_MOVE_TO_PAID);
    printf("////////////////////////////////////////\n");
    getchar();
    JeuRencontrePlacementJoueur(player1,map);
    JeuRencontrePlacementJoueur(player2,map);
/*    JeuRencontrePlacementJoueur(player3,map);
    JeuRencontrePlacementJoueur(player4,map);*/
    PrintTableau(map,MAP_PLAYER);
    printf("////////////////////////////////////////\n");
    getchar();

    while((player1[X] != player2[X] || player1[Y] != player2[Y])
          /*|| (player1[X] != player3[X] && player1[Y] != player3[Y])
          || (player1[X] != player4[X] && player4[Y] != player4[Y])*/){
        if(save){
            printf("saving\n");
            JeuRencontreSave(map);
        }
        player1[MP] = PLAYER_MOVE_POINT;//*2;
        player2[MP] = PLAYER_MOVE_POINT;
        /*player3[MP] = PLAYER_MOVE_POINT;
        player4[MP] = PLAYER_MOVE_POINT;*/
        JeuRencontreDeplacement(player1,player2,map);
        JeuRencontreDeplacement(player2,player1,map);
        /*JeuRencontreDeplacement(player3,player1,map);
        JeuRencontreDeplacement(player4,player1,map);*/

        /*int destination[PLAYER_STATS];
        destination[X]=doRand(0,MAP_H-1);
        destination[Y]=doRand(0,MAP_W-1);

        JeuRencontreDeplacement(player1,destination,map);*/

        //PrintTableau(map,MAP_PLAYER);
        //printf("////////////////////////////////////////\n");
        //getchar();
    }
    //PrintTableau(map,MAP_PLAYER);
    //printf("////////////////////////////////////////\n");
    MessageBeep(MB_OK);
    printf("Gagne\n");
}

int calcul(int entier1, int entier2){
    int a = 6;
    entier1 -= 2;
    entier2 -= 2;
    return (entier1 + entier2)*6;
}

void useFonction(){
    int a = 10;
    int b = 6;
    int r =  0;
    r = calcul(a,b);
    printf("a = %d b = %d r = %d\n",a,b,r);
}

int main()
{
    //Square2();
    //useFonction();
    //tp6();
    //tp5();
    //Multiplication();
    //SecretAndUnsecret();
    //JeuRencontre();
    main();
    return 0;
}

#include <conio.h> #include <math.h> #include <stdlib.h>
/* Dessine le plateau de jeu */ void plateau () { int i=0,j=0;
clrscr (); gotoxy (3,1); for (i=0; i<10; i++) printf ("%d ",i);
for (i=0; i<10; i++) { gotoxy (1,2+i); printf ("%d ",i); for (j=0; j<10; j++) printf (". "); }
gotoxy (1,12); printf ("Ligne : "); gotoxy (11,12); printf ("Colonne : "); gotoxy (1,13); printf ("Distance : ");
}
/* Saisie un chiffre en position x y */ int saisie_chiffre (int x, int y) { char car; char chaine [2]; int sortie = 1; /* Ok on peut sortir */
do {
/* On efface la précédente case */ gotoxy (x,y); printf (" ");
/* On se repositionne pour la saisie */ gotoxy (x,y); car = getch (); if ((car<'0') || (car>'9')) { /* Saisie incorrect : beep */ sound (1000); delay (10); nosound (); /* On doit recommencer */ sortie = 0; } else sortie = 1;
}
Initiation au  langage C. Travaux Pratiques.
M. Berthomier Eric Page 3/3 06/09/00
while (!sortie);
/* Affichage du caractère saisi */ gotoxy (x,y); printf ("%c",car);
/* atoi transforme une chaîne de caractère en nombre */ /* transformation de notre caractère en chaîne */ chaine [0] = car; chaine [1] = 0; return (atoi (chaine));
}
void main () { int posx_bat=0, posy_bat=0; /* Position du bateau */ int x,y; /* Position du tir */ int nb_coups=0; /* Nombre de coups */ int d=0; /* Distance */
randomize (); posx_bat = random (10); /* 0 … 9 */ posy_bat = random (10);
plateau (); do { /* Saisie de la colonne */ x=saisie_chiffre (9,12);
/* Saisie de la ligne */ y=saisie_chiffre (21,12);
/* Nombre de coups */ nb_coups ++;
/* Affichage du coup */ gotoxy ((x+1)*2+1, y+2); printf ("*");
/* Effacement des coordonnées */ gotoxy (9,12); printf (" "); gotoxy (21,12); printf (" ");
/* Calcul de la distance */ d = (int) (sqrt (((x-posx_bat)*(x-posx_bat))+((y-posy_bat)*(yposy_bat))));
/* Affichage de la distance */ gotoxy (12,13); printf ("%d",d);
} while (!((x==posx_bat) && (y==posy_bat))); /* On recommence tant que la position saisie n'est pas celle du navire */
gotoxy (1,15); printf ("Nombre de coups : %d",nb_coups); getch ();
}
