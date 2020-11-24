#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

char disp[7][18];
char puffer;
int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0;
int player = 1;
int flipper = 0;
char coin;
char p1[20];
char p2[20];

void erstellen()
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 16; k++)
		{
			disp[i][k] = ' ';
		}
	}

	for (int k = 1; k < 16; k += 2)
	{
		for (int i = 0; i < 7; i++)
		{
			disp[i][k] = '|';
		}
	}

	disp[0][2] = '1';
	disp[0][4] = '2';
	disp[0][6] = '3';
	disp[0][8] = '4';
	disp[0][10] = '5';
	disp[0][12] = '6';
	disp[0][14] = '7';
}

void abspeichern() {

	const char DATEINAMEARR[] = "vgGame.data";
	const char DATEINAMEPLA[] = "vgplayers.txt";

	FILE* fp1 = fopen(DATEINAMEARR, "wb");
	if (fp1 == NULL) {
		printf("\nDatei %s konnte nicht geoeffnet werden!\n", DATEINAMEARR);
		fclose(fp1);
		return;
	}
	fwrite(disp, sizeof(char), sizeof(disp), fp1);
	fclose(fp1);

	FILE* fp2 = fopen(DATEINAMEPLA, "w+");
	if (fp2 == NULL) {
		printf("\nDatei %s konnte nicht geoeffnet werden!\n", DATEINAMEPLA);
		fclose(fp2);
		return;
	}
	fprintf(fp2, "%s;%s", p1, p2);
	fclose(fp2);

	printf("\nSpiel wurde gespeichert!");
}

void gameLoad() {
	
	const char DATEINAMEARR[] = "vgGame.data";
	const char DATEINAMEPLA[] = "vgplayers.txt";

	FILE* fp1 = fopen(DATEINAMEARR, "rb");
	if (fp1 == NULL) {
		printf("\nDatei konnte nicht geoeffnet werden!\n");
		fclose(fp1);
		return;
	}
	fread(disp, sizeof(char), sizeof(disp), fp1);
	fclose(fp1);

	FILE* fp2 = fopen(DATEINAMEPLA, "r");
	if (fp2 == NULL) {
		printf("\nDatei %s konnte nicht geoeffnet werden!\n", DATEINAMEPLA);
		fclose(fp2);
		return;
	}
	char buffer[80];
	char seps[] = { ";" };
	char* token1 = NULL;
	char* next_token1 = NULL;
	char* next_token2 = NULL;
	if (fgets(buffer, 80, fp2) != NULL) {
		token1 = strtok_s(buffer, seps, &next_token1, seps, &next_token2);

		char* _bezTempOne = token1;
		token1 = strtok_s(NULL, seps, &next_token1);
		char* _bezTeampTwo = token1;

		strcpy(p1, _bezTempOne);
		strcpy(p2, _bezTeampTwo);
	}
	fclose(fp2);

	printf("\nSpiel wurde geladen!");
}

void anzeigen()
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 16; k++)
		{
			printf("%c", disp[i][k]);
		}
		printf("\n");
	}
}

int eingabe()
{
	int eingabe = 0;
	int z = 0;
	flipper++;
	if (flipper % 2 == 0)
	{
		player = 2;
		coin = 'X';
		printf("\n%s, Sie sind an der Reihe.[%c]", p2, coin);
	}
	else
	{
		player = 1;
		coin = '0';
		printf("\n%s, Sie sind an der Reihe.[%c]", p1, coin);
	}

	while (z == 0)
	{
		printf("\nEingabe: ");
		scanf("%d%c", &eingabe, &puffer);

		switch (eingabe)
		{
		case 1:
			if (count1 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 2:
			if (count2 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 3:
			if (count3 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 4:
			if (count4 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 5:
			if (count5 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 6:
			if (count6 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 7:
			if (count7 == 6)
			{
				printf("Bitte eine Reihe mit freien Plaetzen waehlen.");
			}
			else
			{
				z++;
			}
			break;
		case 9:
			printf("Spiel wird gespeichert...");
			abspeichern();
			break;
		default:
			break;
		}
	}
	return eingabe;
}

void change(input)
{
	switch (input)
	{
	case 1:
		disp[6 - count1][2] = coin;
		count1++;
		break;
	case 2:
		disp[6 - count2][4] = coin;
		count2++;
		break;
	case 3:
		disp[6 - count3][6] = coin;
		count3++;
		break;
	case 4:
		disp[6 - count4][8] = coin;
		count4++;
		break;
	case 5:
		disp[6 - count5][10] = coin;
		count5++;
		break;
	case 6:
		disp[6 - count6][12] = coin;
		count6++;
		break;
	case 7:
		disp[6 - count7][14] = coin;
		count7++;
		break;
	default:
		break;
	}
}

int check()
{
	int score;
	int winner = 0;

	for (int k = 1; k < 8; k++)
	{
		for (int i = 2; i < 15; i += 2)
		{
			if (disp[k][i] == coin)
			{
				score = 0;
				for (int y = 1; y < 4; y++)
				{
					if (disp[k][i + y * 2] == coin)
					{
						score++;
						if (score >= 3)
						{
							winner++;
						}
					}
				}
			}
		}
	}

	for (int k = 1; k < 8; k++)
	{
		for (int i = 2; i < 15; i += 2)
		{
			if (disp[k][i] == coin)
			{
				score = 0;
				for (int y = 1; y < 4; y++)
				{
					if (disp[k + y][i] == coin)
					{
						score++;
						if (score >= 3)
						{
							winner++;
						}
					}
				}
			}
		}
	}

	for (int k = 1; k < 8; k++)
	{
		for (int i = 2; i < 15; i += 2)
		{
			if (disp[k][i] == coin)
			{
				score = 0;
				for (int y = 1; y < 4; y++)
				{
					if (disp[k + y][i + 2 * y] == coin)
					{
						score++;
						if (score >= 3)
						{
							winner++;
						}
					}
				}
			}
		}
	}

	for (int k = 1; k < 8; k++)
	{
		for (int i = 2; i < 15; i += 2)
		{
			if (disp[k][i] == coin)
			{
				score = 0;
				for (int y = 1; y < 4; y++)
				{
					if (disp[k + y][i - 2 * y] == coin)
					{
						score++;
						if (score >= 3)
						{
							winner++;
						}
					}
				}
			}
		}
	}

	return winner;
}

int unentschieden()
{
	int full = 0;
	if (count1 == 6 && count2 == 6 && count3 == 6 && count4 == 6 && count5 == 6 && count6 == 6 && count7 == 6)
	{
		full++;
	}
	return full;
}

int gameLoop(int score1, int score2, int loadVar) {
	int x = 0;
	int c = 0;
	int tries = 0;

	if (loadVar == 0) {
		count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0;
	}
	else {
		for (int j = 1; j < 7; j++) {
			if (disp[j][2] != ' ') {
				count1++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][4] != ' ') {
				count2++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][6] != ' ') {
				count3++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][8] != ' ') {
				count4++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][10] != ' ') {
				count5++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][12] != ' ') {
				count6++;
			}
		}
		for (int j = 1; j < 7; j++) {
			if (disp[j][14] != ' ') {
				count7++;
			}
		}
	}
	
	while (x == 0 && c == 0)
	{
		system("cls");
		printf("-------------------------------------------\n   4 Gewinnt\tScore: %s[%d] %s[%d]\n-------------------------------------------\n\n", p1, score1, p2, score2);
		anzeigen();
		int input = eingabe();
		change(input);
		c = unentschieden();
		x = check();
		tries++;
	}
	system("cls");
	printf("-------------------------------------------\n   4 Gewinnt\tScore: %s[%d] %s[%d]\n-------------------------------------------\n\n", p1, score1, p2, score2);
	anzeigen();
	if (x >= 1)
	{
		if (player == 1)
		{
			printf("\n%s hat nach %d Zuegen gewonnen![%c]", p1, tries, coin);
			score1++;
		}
		else if (player == 2)
		{
			printf("\n%s hat nach %d Zuegen gewonnen![%c]", p2, tries, coin);
			score2++;
		}
	}
	else if (c >= 1)
	{
		printf("\nUnentschieden!");
	}

	return score1, score2;
}

void gameVierGewinnt()
{
	system("cls");

	int y = 0;
	int auswahl = 0;
	int score1 = 0;
	int score2 = 0;
	
	printf("-------------------------------------------\n   4 Gewinnt\n-------------------------------------------\n\n1)Spielen\n2)Spiel laden\n3)Beenden\n");
	scanf("%d%c", &auswahl, &puffer);

	if (auswahl == 1)
	{
		printf("\n Spieler 1, geben Sie Ihren Namen ein: ");
		scanf("%s", p1);
		printf("\n Spieler 2, geben Sie Ihren Namen ein: ");
		scanf("%s", p2);
	}

	while (y == 0)
	{
		switch (auswahl)
		{
		case 1:
			erstellen();
			score1, score2 = gameLoop(score1, score2, 0);
			printf("\n\n1)Nochmal\n2)Spiel laden\n3)Beenden\nEingabe: ");
			scanf("%d%c", &auswahl, &puffer);
			break;
		case 2:
			printf("Spiel wird geladen...");
			gameLoad();
			score1, score2 = gameLoop(score1, score2, 1);
			printf("\n\n1)Nochmal\n2)Spiel laden\n3)Beenden\nEingabe: ");
			scanf("%d%c", &auswahl, &puffer);
			break;
		case 3:
			y++;
			break;
		}
	}
}