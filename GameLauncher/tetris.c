#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//Definitionen

#define COLS 11
#define ROWS 20

char Table[ROWS][COLS] = { 0 };
int score = 0;
char GameOn = 1;
int timer = 2000;
int msec = 0;

HANDLE hStdout;

HANDLE _output_handle;

typedef struct {
	char** array;
	int width, row, col;
} Shape;
Shape current;

void printGameTable();
void rotatePiece(Shape shape);
void GetNewShape();
void WriteToTable();
void deleteShape(Shape shape);
int CheckPosition(Shape shape);
void ManipulateCurrent(int action);
void CheckFullLine();
void cls();

void hidecursor() {
	_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(_output_handle, &info);
}

// Definition der Tetris-Steine
const Shape ShapesArray[7] = {
	{(char* []) { (char[]) { 0,1,1 },(char[]) { 1,1,0 }, (char[]) { 0,0,0 } }, 3},								// S
	{(char* []) { (char[]) { 1,1,0 },(char[]) { 0,1,1 }, (char[]) { 0,0,0 } }, 3},								// Z
	{(char* []) { (char[]) { 0,1,0 },(char[]) { 1,1,1 }, (char[]) { 0,0,0 } }, 3},								// T
	{(char* []) { (char[]) { 0,0,1 },(char[]) { 1,1,1 }, (char[]) { 0,0,0 } }, 3},								// L
	{(char* []) { (char[]) { 1,0,0 },(char[]) { 1,1,1 }, (char[]) { 0,0,0 } }, 3},								// J
	{(char* []) { (char[]) { 1,1 },(char[]) { 1,1 }}, 2},														// O
	{(char* []) { (char[]) { 0,0,0,0 },(char[]) { 1,1,1,1 }, (char[]) { 0,0,0,0 }, (char[]) { 0,0,0,0 } }, 4}	// I
};

Shape CopyShape(Shape shape) {
	Shape new_shape = shape;
	char** copyshape = shape.array;
	new_shape.array = (char**)malloc(new_shape.width * sizeof(char*));
	int i, j;
	for (i = 0; i < new_shape.width; i++) {
		new_shape.array[i] = (char*)malloc(new_shape.width * sizeof(char));
		for (j = 0; j < new_shape.width; j++) {
			new_shape.array[i][j] = copyshape[i][j];
		}
	}
	return new_shape;
}

// Hauptprogramm

int startTetris() {
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hidecursor();
	srand(time(NULL));
	
	char c;
	clock_t before, after, difference;

	char puffer;
	int auswahl;

	do {
		system("cls");
		print_image("tetrisImage.txt");
		printf("\n\nMen\x081: \n1) Start\n2) Beenden\nEingabe: ");
		scanf("%d%c", &auswahl, &puffer);

		switch (auswahl) {
		case 1:

			score = 0;
			GameOn = 1;
			before = clock();
			system("cls");
			GetNewShape();
			printGameTable();
			while (GameOn) {
				if (kbhit()) {
					c = getch();
					ManipulateCurrent(c);
				}
				after = clock();
				difference = after - before;
				if (difference > timer) {
					before = after;
					ManipulateCurrent('s');
				}
			}

			printf("\nGame Over!\n");
			deleteShape(current);
			break;
		case 2:
			system("cls");
			printf("\n\n-- Ende --\n");
			break;
		default:
			printf("Ungueltige Eingabe");
			auswahl = 0;
			break;
		}
	} while (auswahl < 2);

	return 0;
}

void printGameTable() {
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	char Buffer[ROWS][COLS] = { 0 };
	int i, j;
	for (i = 0; i < current.width; i++) {
		for (j = 0; j < current.width; j++) {
			if (current.array[i][j])
				Buffer[current.row + i][current.col + j] = current.array[i][j];
		}
	}
	cls(hStdout);
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("%c ", (Table[i][j] + Buffer[i][j]) ? 254 : '.');
		}
		printf("\n");
	}
	printf("\nScore: %d\n", score);
}

void GetNewShape() {
	Shape new_shape = CopyShape(ShapesArray[rand() % 7]);

	new_shape.col = rand() % (COLS - new_shape.width + 1);
	new_shape.row = 0;
	deleteShape(current);
	current = new_shape;
	if (!CheckPosition(current)) {
		GameOn = 0;
	}
}

void WriteToTable() {
	int i, j;
	for (i = 0; i < current.width; i++) {
		for (j = 0; j < current.width; j++) {
			if (current.array[i][j])
				Table[current.row + i][current.col + j] = current.array[i][j];
		}
	}
}

void rotatePiece(Shape shape) {
	Shape temp = CopyShape(shape);
	int i, j, k, width;
	width = shape.width;
	for (i = 0; i < width; i++) {
		for (j = 0, k = width - 1; j < width; j++, k--) {
			shape.array[i][j] = temp.array[k][i];
		}
	}
	deleteShape(temp);
}

void deleteShape(Shape shape) {
	int i;
	for (i = 0; i < shape.width; i++) {
		free(shape.array[i]);
	}
	free(shape.array);
}

int CheckPosition(Shape shape) {
	char** array = shape.array;
	int i, j;
	for (i = 0; i < shape.width; i++) {
		for (j = 0; j < shape.width; j++) {
			if ((shape.col + j < 0 || shape.col + j >= COLS || shape.row + i >= ROWS)) {
				if (array[i][j])
					return 0;
			}
			else if (Table[shape.row + i][shape.col + j] && array[i][j])
				return 0;
		}
	}
	return 1;
}

void CheckFullLine() {
	int i, j, sum, count = 0;
	for (i = 0; i < ROWS; i++) {
		sum = 0;
		for (j = 0; j < COLS; j++) {
			sum += Table[i][j];
		}
		if (sum == COLS) {
			count++;
			int l, k;
			for (k = i; k >= 1; k--)
				for (l = 0; l < COLS; l++)
					Table[k][l] = Table[k - 1][l];
			for (l = 0; l < COLS; l++)
				Table[k][l] = 0;
		}
	}
	timer -= 1, score += 100 * count;
}

void ManipulateCurrent(char action) {
	Shape temp = CopyShape(current);
	switch (action) {
	case 's':
		temp.row++;						//nach unten bewegen
		if (CheckPosition(temp))
			current.row++;
		else {
			WriteToTable();
			CheckFullLine();			//prüfen, ob volle Zeilen vorhanden sind
			GetNewShape();
		}
		break;
	case 'd':
		temp.col++;						//naxh rechts bewegen
		if (CheckPosition(temp))
			current.col++;
		break;
	case 'a':
		temp.col--;						//nach links bewegen
		if (CheckPosition(temp))
			current.col--;
		break;
	case 'w':
		rotatePiece(temp);				//Tetris-Stein drehen
		if (CheckPosition(temp))
			rotatePiece(current);
		break;
	}
	deleteShape(temp);
	printGameTable();
}


// Clear-Funktion aus der Dokumentation zum "Leeren" des Konsolenfensters von Micorosoft
void cls(HANDLE hConsole)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT scrollRect;
	COORD scrollTarget;
	CHAR_INFO fill;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}