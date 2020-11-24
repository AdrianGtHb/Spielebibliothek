#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define LEER ' '


char field[3][3] = { {' ',' ', ' '},
					{' ',' ', ' '},
					{' ',' ', ' '} };
char nickname1[20];
char nickname2[20];
int winner = 0;
int tries = 0;

unsigned int felder = 9;

char print_field() {

	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			printf("|%c|", field[i][x]);
		}
		printf("\n");
		if (i < 2)
			printf("---------\n");
	}

}

char player1() {

	unsigned int column = 0;
	unsigned int row = 0;


	printf("%s bitte gib deine gew\x081nschte Position ein: \n", nickname1);
	print_field();
	printf("\nZeile(1-3): ");
	scanf("%d", &row);
	if (row < 1 || row >3) {
		printf("ung\x081ltige Eingabe!\nBitte versuchen Sie es erneut!\n");
		printf("Zeile(1-3): ");
		scanf("%d", &row);
	}
	printf("Spalte(1-3): ");
	scanf("%d", &column);

	if (column < 1 || column >3) {
		printf("ung\x081ltige Eingabe!\n Bitte versuchen Sie es erneut!\n");
		printf("Spalte(1-3): ");
		scanf("%d", &column);
	}


	if (field[row - 1][column - 1] == LEER)
	{
		field[row - 1][column - 1] = 'X';
		print_field();
	}
	else {
		while (field[row - 1][column - 1] == 'X' || field[row - 1][column - 1] == 'O') {
			printf("Feld bereits besetzt!\n");
			printf("Auf ein neues Spieler 1\n");

			printf("\nZeile(1-3): ");
			scanf("%d", &row);
			if (row < 1 || row >3) {
				printf("ung\x081ltige Eingabe!\nBitte versuchen Sie es erneut!\n");
				printf("Zeile(1-3): ");
				scanf("%d", &row);
			}
			printf("Spalte(1-3): ");
			scanf("%d", &column);

			if (column < 1 || column >3) {
				printf("ung\x081ltige Eingabe!\n Bitte versuchen Sie es erneut!\n");
				printf("Spalte(1-3): ");
				scanf("%d", &column);
			}

		}

	}
	if (field[row - 1][column - 1] == LEER)
	{
		field[row - 1][column - 1] = 'O';
		print_field();
	}
	printf("press <ENTER>");
	getchar();
	system("cls");

}

void player2() {



	unsigned int column = 0;
	unsigned int row = 0;


	printf("%s bitte gib deine gew\x081nschte Position ein: \n", nickname2);
	print_field();
	printf("\nZeile(1-3): ");
	scanf("%d", &row);

	if (row < 1 || row >3) {
		printf("ung\x081ltige Eingabe!\nBitte versuchen Sie es erneut!\n");
		printf("Zeile(1-3): ");
		scanf("%d", &row);
	}
	printf("Spalte(1-3): ");
	scanf("%d", &column);

	if (column < 1 || column >3) {
		printf("ung\x081ltige Eingabe!\n Bitte versuchen Sie es erneut!\n");
		printf("Spalte(1-3): ");
		scanf("%d", &column);
	}


	if (field[row - 1][column - 1] == LEER)
	{
		field[row - 1][column - 1] = 'O';
		print_field();
	}
	else {
		while (field[row - 1][column - 1] == 'X' || field[row - 1][column - 1] == 'O') {
			printf("Feld bereits besetzt!\n");
			printf("Auf ein neues Spieler 2\n");

			printf("\nZeile(1-3): ");
			scanf("%d", &row);
			if (row < 1 || row >3) {
				printf("ung\x081ltige Eingabe!\nBitte versuchen Sie es erneut!\n");
				printf("Zeile(1-3): ");
				scanf("%d", &row);
			}
			printf("Spalte(1-3): ");
			scanf("%d", &column);

			if (column < 1 || column >3) {
				printf("ung\x081ltige Eingabe!\n Bitte versuchen Sie es erneut!\n");
				printf("Spalte(1-3): ");
				scanf("%d", &column);
			}

		}
	}
	if (field[row - 1][column - 1] == LEER)
	{
		field[row - 1][column - 1] = 'O';
		print_field();
	}
	printf("press <ENTER>");
	getchar();
	system("cls");
}

void win() {

	if (field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][1] == 'X' && field[1][1] == 'X' && field[2][1] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X') {
		printf("SPIELER 1 hat GEWONNEN!!");
		winner++;
	}


	if (field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][1] == 'O' && field[1][1] == 'O' && field[2][1] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}
	if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O') {
		printf("SPIELER 2 hat GEWONNEN!!");
		winner++;
	}


}

void gameTTT() {
	system("cls");

	printf("Spieler1 gib dein Nickname ein: ");
	gets(nickname1);

	system("cls");
	printf("Spieler2 gib dein Nickname ein: ");
	gets(nickname2);

	system("cls");
	for (int i = 0; i < 5; i++) {
		player1();
		tries++;
		win();
		if (winner == 1) {
			printf("\n%d Z\x081ge bis zum SIEG!!", 1 + tries / 2);
			printf("\n---Ende---");
			getchar();
			exit(0);
		}
		if (tries == 9) {
			printf("\nUnentschieden");
			printf("\n---Ende---");
			getchar();
			exit(0);
		}

		player2();
		tries++;
		win();
		if (winner == 1) {
			printf("\n%d Z\x081ge bis zum SIEG!!", tries / 2);
			printf("\n---Ende---");
			getchar();
			exit(0);
		}
		if (tries == 9) {
			printf("\nUnentschieden");
			printf("\n---Ende---");
			getchar();
			exit(0);
		}

	}
}