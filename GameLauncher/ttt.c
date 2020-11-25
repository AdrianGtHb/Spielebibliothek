#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
//#include<Windows.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESETCOLOR   "\x1b[0m"
char field[3][3], nickname1[20], nickname2[20], puffer;
int win = 0;

void clear() {
    getchar();
    system("cls");
}
void fill() {
    int h = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            field[i][k] = h;
            h++;
        }
    }
}
void print() {
    for (int i = 0; i < 3; i++)
    {
        printf("\t");
        for (int k = 0; k < 3; k++)
        {
            printf(" %c ", field[i][k]);
            if (k < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2) {
            printf("\t");
            for (int r = 0; r < 12; r++)
            {
                printf("%c", 196);
            }
            printf("\n");
        }
    }
}
void winning() {
    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] || field[0][i] == field[1][i] && field[1][i]  == field[2][i])//Prüfen der Gewinnmöglichkeiten vertikal und horizontal
            win = 1;
        if (field[0][0] == field[1][1]&& field[1][1] == field[2][2] || field[0][2] == field[1][1]&& field[1][1] == field[2][0])//Prüfen der Gewinnmöglichkeiten diagonal
            win = 1;
    }
}
void header() {
    printf(CYAN);
    printf(".-----. _         .-----.             .-----.            \n");
    printf("`-. .-':_;        `-. .-'             `-. .-'            \n");
    printf("  : :  .-. .--.     : : .--.   .--.     : : .--.  .--.   \n");
    printf("  : :  : :'  ..'    : :' .; ; '  ..'    : :' .; :' '_.'  \n");
    printf("  :_;  :_;`.__.'    :_;`.__,_;`.__.'    :_;`.__.'`.__.'  \n");
    printf("=========================================================\n\n");
    printf(RESETCOLOR);
}
void menu() {
    header();
    printf("1)Spielen\n2)Namen speichern\n3)Namen laden\n4)Neue Namen festlegen\n5)Beenden\nBitte geben Sie die gewuenschte Option ein: ");
}
void name() {
    header();
    printf("Spieler1, bitte geben Sie Ihren Namen ein: ");
    gets(nickname1);
    printf("Spieler2, bitte geben Sie Ihren Namen ein: ");
    gets(nickname2);
    system("cls");
}
void maingame(int *option) {
    char temp[20], tempposition;
    int counter = 0, player = 0, position = 0, tempoption=0;
    fill();
    if (nickname1[1]=='\0'&& nickname2[1] == '\0')
    {
         name();
    }
    win = 0;
    while (win < 1 && counter < 10) {
        header();
        if (counter % 2 == 0) {
            memcpy(temp, nickname1, sizeof(nickname1));
            player = 1;
        }
        else {
            memcpy(temp, nickname2, sizeof(nickname2));
            player = 2;
        }
        print();
        printf("\n==============================\n%s bitte geben Sie das Feld(1-9) ein, auf das Sie ", temp);
        printf("setzen moechten : ");
        scanf("%d%c", &position, &puffer);
        tempposition = position + '0';
        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (field[i][k] == tempposition && player == 1) {
                    field[i][k] = '0';
                    counter++;
                }
                if (field[i][k] == tempposition && player == 2) {
                    field[i][k] = 'X';
                    counter++;
                }
                if (counter > 4)
                {
                    winning();
                }
            }
        }
        system("cls");
    }
    if (counter == 9) {
        printf("\nUNENTSCHIEDEN!");
    }
    if (win > 0) {
        header();
        print();
        printf(GREEN);
        print_image("winner.txt");
        printf(RESETCOLOR);
        
    }
    printf("%s, Sie haben nach %d Zuegen gewonnen!\n\n1)Nochmal spielen\n2)Zurueck zum TicTacToe Menu\nBitte geben Sie die gewuenschte Option ein: ", temp, counter);
    scanf("%d%c", &tempoption, &puffer);
    *option = tempoption;
    system("cls");
    counter = 0;
}

void tttspeichern(){
    system("cls");
const char DATEINAMEPLATTT[] = "tttplayers.txt";

FILE* fp = fopen(DATEINAMEPLATTT, "w+");
if (fp == NULL) {
		printf("\nDatei %s konnte nicht geoeffnet werden!\n", DATEINAMEPLATTT);
		fclose(fp);
		return;
	}
	fprintf(fp, "%s;%s", nickname1, nickname2);
	fclose(fp);
    printf(GREEN);
    print_image("saved_succesful.txt");
    printf(RESETCOLOR);
	printf("\nSpiel wurde gespeichert!");
    getchar();
    system("cls");
}
void tttgameLoad() {
	

	const char DATEINAMEPLATTT[] = "tttplayers.txt";
    char temp;
	
	FILE* fp = fopen(DATEINAMEPLATTT, "r");
	if (fp == NULL) {
		printf("\nDatei %s konnte nicht geoeffnet werden!\n", DATEINAMEPLATTT);
		fclose(fp);
		return;
	}
    temp = fgetc(fp);
    printf("%s", temp);
	/*char buffer[80];
	char seps[] = { ";" };
	char* token1 = NULL;
	char* next_token1 = NULL;
	char* next_token2 = NULL;
	if (fgets(buffer, 80, fp) != NULL) {

		token1 = strtok_s(buffer, seps, &next_token1, seps, &next_token2);
		char* _bezTempOne = token1;

		token1 = strtok_s(NULL, seps, &next_token1);
		char* _bezTempTwo = token1;

		strcpy(nickname1, _bezTempOne);
		strcpy(nickname2, _bezTempTwo);
	}*/
	fclose(fp);
    printf(GREEN);
    print_image("load_succesful.txt");
    printf(RESETCOLOR);
	printf("\nSpiel wurde geladen!\n");
    getchar();
    system("cls");
}


void gameTTT() {
    int menuoption = 0;
    int gameoption = 1;
    system("cls");
    while (menuoption != 5) {
        menu();
        scanf("%d%c", &menuoption, &puffer);
        system("cls");
        switch (menuoption)
        {
        case 1://Spielen
            fill();
            while (menuoption == 1)
                maingame(&menuoption);
            break;
        case 2:
            tttspeichern();
            break;
        case 3:
            tttgameLoad();
            break;
        case 4:name();
            system("cls");
            break;
        case 5: clear();
            break;
        default:
            break;
        }
    }
}