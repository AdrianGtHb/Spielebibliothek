#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

char Feld1[14][54];
char Feld2[14][54];
int gameFlipper = -1;
int gamePlayer = 0;
int beenden = 0;
char puffer;


#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESETCOLOUR   "\x1b[0m"

void createGame()
{
	strcpy(Feld1[0], "P1     Dein Feld\t\t  Gegnerisches Feld");
	strcpy(Feld2[0], "P2     Dein Feld\t\t  Gegnerisches Feld");

	for (int i = 3; i < 13; i++)
	{
		for (int k = 2; k < 23; k += 2)		//Füllen der Felder mit '~'
		{
			Feld1[i][k] = '~';
			Feld2[i][k] = '~';
		}
		for (int k = 33; k < 54; k += 2)
		{
			Feld1[i][k] = '~';
			Feld2[i][k] = '~';
		}
	}

	for (int i = 3; i < 13; i++)
	{
		for (int k = 1; k < 23; k += 2)		//Füllen der Felder mit '~'
		{
			Feld1[i][k] = '|';
			Feld2[i][k] = '|';
		}
		for (int k = 32; k < 54; k += 2)
		{
			Feld1[i][k] = '|';
			Feld2[i][k] = '|';
		}
	}
	int y = 48;
	for (int i = 2; i < 21; i += 2)		//Füllen der Felder mit 0 - 9
	{
		Feld1[2][i] = y;
		Feld1[13][i] = y;
		Feld2[2][i] = y;
		Feld2[13][i] = y;
		y++;
	}
	y = 48;
	for (int i = 33; i < 52; i += 2)
	{
		Feld1[2][i] = y;
		Feld1[13][i] = y;
		Feld2[2][i] = y;
		Feld2[13][i] = y;
		y++;
	}
	y = 65;
	for (int i = 3; i < 13; i++)		//Füllen der Felder mit 'A - J'
	{
		Feld1[i][0] = y;
		Feld1[i][22] = y;
		Feld1[i][31] = y;
		Feld1[i][53] = y;
		Feld2[i][0] = y;
		Feld2[i][22] = y;
		Feld2[i][31] = y;
		Feld2[i][53] = y;
		y++;
	}
}

void showGame()
{
	printf(CYAN);
	print_image("shipimage.txt");
	printf(RESETCOLOUR);
	printf("\n\n");
	if (gamePlayer == 0)		//Anzeige für Spieler 1
	{
		for (int i = 0; i < 14; i++)
		{
			for (int k = 0; k < 54; k++)
			{
				if (Feld1[i][k] == '#')
				{
					printf("%c", 254);
				}
				else if (Feld1[i][k] == 'X')
				{
					printf(RED);
					printf("X");
					printf(RESETCOLOUR);
				}
				else if (Feld1[i][k] == 'O')
				{
					printf(YELLOW);
					printf("O");
					printf(RESETCOLOUR);
				}
				else
					printf("%c", Feld1[i][k]);
			}
			printf("\n");
		}
	}
	else if (gamePlayer == 1)		//Anzeige für Spieler 2
	{
		for (int i = 0; i < 14; i++)
		{
			for (int k = 0; k < 54; k++)
			{
				if (Feld2[i][k] == '#')
				{
					printf("%c", 254);
				}
				else if (Feld2[i][k] == 'X')
				{
					printf(RED);
					printf("X");
					printf(RESETCOLOUR);
				}
				else if (Feld2[i][k] == 'O')
				{
					printf(YELLOW);
					printf("O");
					printf(RESETCOLOUR);
				}
				else
					printf("%c", Feld2[i][k]);
			}
			printf("\n");
		}
	}
}

void pchanger()		//Spielerwechsel
{
	gameFlipper++;
	if (gameFlipper % 2 == 0)
	{
		gamePlayer = 0;
	}
	else
	{
		gamePlayer = 1;
	}
}

void shipinput()
{
	int Schiffe[2][4];
	int input = 0;
	int breite = 0;
	int laenge = 0;
	int ausrichtung = 0;
	int size = 0;
	char c_laenge = 'Q';
	for (int i = 0; i < 2; i++)		//Befüllung des Arrays um die Verbleibenden Schiffe zu tracken
	{
		for (int k = 0; k < 4; k++)
		{
			Schiffe[i][k] = k + 1;
		}
	}
	while (!(Schiffe[gamePlayer][0] == 0 && Schiffe[gamePlayer][1] == 0 && Schiffe[gamePlayer][2] == 0 && Schiffe[gamePlayer][3] == 0))		//Abfrage ob alle Schiffe gesetzt wurden
	{
		int nogo = 0;
		int constraint = 0;

		while (constraint == 0)
		{
			system("cls");
			showGame();
			printf("\n1)Schlachtschiff, 5 K\x084stchen (x%d)\n2)Kreuzer, 4 K\x084stchen (x%d)\n3)Zerst\x094rer, 3 K\x084stchen (x%d)\n4)U-Boot, 2 K\x084stchen (x%d)\n", Schiffe[gamePlayer][0], Schiffe[gamePlayer][1], Schiffe[gamePlayer][2], Schiffe[gamePlayer][3]);
			printf("W\x084hlen Sie ein Schiff, dass Sie stationieren m\x094\chten!\nEingabe: ");
			scanf("%d%c", &input, &puffer);
			if (Schiffe[gamePlayer][input - 1] == 0)		//Abfrage ob von einer Art Schiff schon alle gestzt wurden
			{
				printf(RED);
				printf("\nAchtung! Von dieser Art Schiff haben Sie keins mehr! W\x084hlen sie ein anderes!<ENTER>");
				printf(RESETCOLOUR);
				getchar();
			}
			else if (Schiffe[gamePlayer][input - 1] > 0)
			{
				constraint++;
			}
		}
		system("cls");
		showGame();
		printf("\nGeben Sie den gew\x081nschten Breitengrad ein!\nEingabe: ");
		scanf("%d%c", &breite, &puffer);
		system("cls");
		showGame();
		printf("\nGeben Sie den gew\x081nschten L\x084ngengrad ein!\nEingabe: ");
		scanf("%c%c", &c_laenge, &puffer);
		system("cls");
		showGame();

		if (c_laenge == 'a' || c_laenge == 'A')		//Umwandlung von a - j in 0 - 9
			laenge = 0;
		else if (c_laenge == 'b' || c_laenge == 'B')
			laenge = 1;
		else if (c_laenge == 'c' || c_laenge == 'C')
			laenge = 2;
		else if (c_laenge == 'd' || c_laenge == 'D')
			laenge = 3;
		else if (c_laenge == 'e' || c_laenge == 'E')
			laenge = 4;
		else if (c_laenge == 'f' || c_laenge == 'F')
			laenge = 5;
		else if (c_laenge == 'g' || c_laenge == 'G')
			laenge = 6;
		else if (c_laenge == 'h' || c_laenge == 'H')
			laenge = 7;
		else if (c_laenge == 'i' || c_laenge == 'I')
			laenge = 8;
		else if (c_laenge == 'j' || c_laenge == 'J')
			laenge = 9;

		printf("\n1)Horizontal\n2)Vertikal\nEingabe: ");
		scanf("%d%c", &ausrichtung, &puffer);


		switch (input)		//Länge des eingegebenen Schiffes
		{
		case 1:
			size = 5;
			break;
		case 2:
			size = 4;
			break;
		case 3:
			size = 3;
			break;
		case 4:
			size = 2;
			break;
		default:
			break;
		}
		//Test ob Schiff an der Stelle gesetzt werden darf

		if (gamePlayer == 0)		//Spieler 1
		{
			if (ausrichtung == 1)		
			{
				for (int i = 0; i < size; i++)
				{
					if (Feld1[laenge + 3][((breite * 2) + 2) + 2 * i] != '~' || Feld1[laenge + 2][((breite * 2) + 2) + 2 * i] == '#' || Feld1[laenge + 4][((breite * 2) + 2) + 2 * i] == '#')
					{
						nogo++;
					}
				}
				if (Feld1[laenge + 3][((breite * 2) + 2) - 2] == '#')
				{
					nogo++;
				}
				if (Feld1[laenge + 3][((breite * 2) + 2) + 2 * size] == '#')
				{
					nogo++;
				}
			}

			if (ausrichtung == 2)
			{
				for (int i = 0; i < size; i++)
				{
					if (Feld1[laenge + 3 + i][((breite * 2) + 2)] != '~' || Feld1[laenge + 3 + i][((breite * 2) + 4)] == '#' || Feld1[laenge + 3 + i][(breite * 2) + 2] == '#')
					{
						nogo++;
					}
				}
				if (Feld1[laenge + 2][(breite * 2) + 2] == '#')
				{
					nogo++;
				}
				if (Feld1[laenge + 3 + size][(breite * 2) + 2] == '#')
				{
					nogo++;
				}
			}
			if (nogo == 0)
			{
				Schiffe[gamePlayer][input - 1]--;
				if (ausrichtung == 1)
				{
					for (int i = 0; i < size; i++)
					{
						Feld1[laenge + 3][((breite * 2) + 2) + 2 * i] = '#';
					}
				}
				if (ausrichtung == 2)
				{
					for (int i = 0; i < size; i++)
					{
						Feld1[laenge + 3 + i][((breite * 2) + 2)] = '#';
					}
				}
			}
			else if (nogo != 0)
			{
				printf(RED);
				printf("\nBitte beachten Sie, dass Schiffe auf dem Spielfeld Platz haben m\x081ssen und keine anderen Schiffe ber\x081hren d\x081rfen!\n<ENTER> dr\x081\cken um fortzufahren");
				printf(RESETCOLOUR);
				getchar();
			}
		}


		if (gamePlayer == 1)		//Spieler 2
		{
			if (ausrichtung == 1)
			{
				for (int i = 0; i < size; i++)
				{
					if (Feld2[laenge + 3][((breite * 2) + 2) + 2 * i] != '~' || Feld2[laenge + 2][((breite * 2) + 2) + 2 * i] == '#' || Feld2[laenge + 4][((breite * 2) + 2) + 2 * i] == '#')
					{
						nogo++;
					}
				}
				if (Feld2[laenge + 3][((breite * 2) + 2) - 2] == '#')
				{
					nogo++;
				}
				if (Feld2[laenge + 3][((breite * 2) + 2) + 2 * size] == '#')
				{
					nogo++;
				}
			}

			if (ausrichtung == 2)
			{
				for (int i = 0; i < size; i++)
				{
					if (Feld2[laenge + 3 + i][((breite * 2) + 2)] != '~' || Feld2[laenge + 3 + i][((breite * 2) + 4)] == '#' || Feld2[laenge + 3 + i][(breite * 2) + 2] == '#')
					{
						nogo++;
					}
				}
				if (Feld2[laenge + 2][(breite * 2) + 2] == '#')
				{
					nogo++;
				}
				if (Feld2[laenge + 3 + size][(breite * 2) + 2] == '#')
				{
					nogo++;
				}
			}
			if (nogo == 0)
			{
				Schiffe[gamePlayer][input - 1]--;
				if (ausrichtung == 1)
				{
					for (int i = 0; i < size; i++)
					{
						Feld2[laenge + 3][((breite * 2) + 2) + 2 * i] = '#';
					}
				}
				if (ausrichtung == 2)
				{
					for (int i = 0; i < size; i++)
					{
						Feld2[laenge + 3 + i][((breite * 2) + 2)] = '#';
					}
				}
			}
			else if (nogo != 0)
			{
				printf(RED);
				printf("\nBitte beachten Sie, dass Schiffe auf dem Spielfeld Platz haben m\x081\en und keine anderen Schiffe ber\x081hren d\x081rfen!\n<ENTER> dr\x081\cken um fortzufahren");
				printf(RESETCOLOUR);
				getchar();
			}
		}
	}
}

void sieg()
{
	//Sind alle Schiffe einer Seite zerstört?
	beenden = 1;
	if (gamePlayer == 0)
		for (int k = 3; k < 13; k++)
		{
			for (int i = 2; i < 23; i += 2)
			{
				if (Feld2[k][i] == '#')
					beenden = 0;
			}
		}
	if (gamePlayer == 1)
		for (int k = 3; k < 13; k++)
		{
			for (int i = 2; i < 23; i += 2)
			{
				if (Feld1[k][i] == '#')
					beenden = 0;
			}
		}
	if (beenden == 1)
	{
		printf("Spieler %d hat die Schlacht gewonnen!", gamePlayer + 1);
	}
}

void schuss()
{
	system("cls");
	
	int sBreite = 0;
	int sLaenge = 0;
	int fehlversuch = 0;
	int countersize = 1;
	char c_sLaenge = 0;
	while (fehlversuch == 0)
	{
		int direction = 0;
		system("cls");
		showGame();
		printf("\nSpieler %d, geben Sie den Breitengrad zum Beschuss an!\nEingabe: ", gamePlayer + 1);
		scanf("%d%c", &sBreite, &puffer);
		system("cls");
		showGame();
		printf("\nSpieler %d, geben Sie den L\x084ngengrad zum Beschuss an!\nEingabe: ", gamePlayer + 1);
		scanf("%c%c", &c_sLaenge, &puffer);
		if (c_sLaenge == 'a' || c_sLaenge == 'A')
			sLaenge = 0;
		else if (c_sLaenge == 'b' || c_sLaenge == 'B')
			sLaenge = 1;
		else if (c_sLaenge == 'c' || c_sLaenge == 'C')
			sLaenge = 2;
		else if (c_sLaenge == 'd' || c_sLaenge == 'D')
			sLaenge = 3;
		else if (c_sLaenge == 'e' || c_sLaenge == 'E')
			sLaenge = 4;
		else if (c_sLaenge == 'f' || c_sLaenge == 'F')
			sLaenge = 5;
		else if (c_sLaenge == 'g' || c_sLaenge == 'G')
			sLaenge = 6;
		else if (c_sLaenge == 'h' || c_sLaenge == 'H')
			sLaenge = 7;
		else if (c_sLaenge == 'i' || c_sLaenge == 'I')
			sLaenge = 8;
		else if (c_sLaenge == 'j' || c_sLaenge == 'J')
			sLaenge = 9;
		if (gamePlayer == 0)
		{
			if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == '#')
			{
				Feld1[sLaenge + 3][(sBreite * 2) + 33] = 'X';
				Feld2[sLaenge + 3][(sBreite * 2) + 2] = 'X';

				if (Feld2[sLaenge + 3][(sBreite * 2) + 2 + 2] == 'X')
					direction = 1;
				if (Feld2[sLaenge + 3][(sBreite * 2)] == 'X')
					direction = 1;
				if (Feld2[sLaenge + 4][(sBreite * 2) + 2] == 'X')
					direction = 2;
				if (Feld2[sLaenge + 2][(sBreite * 2) + 2] == 'X')
					direction = 2;

				switch (direction)
				{
				case 1:		//Horizontal
					for (int i = 2; Feld2[sLaenge + 3][(sBreite * 2) + 2 * i] == 'X'; i++) //zeigt auf eins nach rechts, wenn laenge 1 ist, dann zeigt es auf 2 und geht immer weiter bis es kein X mehr ist
					{
						countersize++;
						if (Feld2[sLaenge + 3][(sBreite * 2) + 2 * (i + 1)] == '#') //zeigt auf zwei nach rechts, wenn laenge 1 ist, dann zeigt es auf 3 und geht immer weiter
							countersize = 0;
					}
					for (int i = 0; Feld2[sLaenge + 3][(sBreite * 2) - 2 * i] == 'X'; i++) //zeigt auf eins nach links, wenn laenge 3 ist, dan zeigt es auf 2 und geht immer weiter bis kein x mehr ist
					{
						countersize++;
						if (Feld2[sLaenge + 3][(sBreite * 2) - 2 * (i + 1)] == '#') //zeigt auf zwei nach links, wenn laenge 3 ist, dann zeigt es auf 1 und geht immer weiter
							countersize = 0;
					}
					if (Feld2[sLaenge + 3][(sBreite * 2) + 4] == '#' || Feld2[sLaenge + 3][(sBreite * 2)] == '#')
						countersize = 0;
					break;
				case 2:		//Vertikal
					for (int i = 0; Feld2[sLaenge + 2 - i][(sBreite * 2) + 2] == 'X'; i++)
					{
						countersize++;
						if (Feld2[sLaenge + 1 - i][(sBreite * 2) + 2] == '#')
							countersize = 0;
					}
					for (int i = 0; Feld2[sLaenge + 4 + i][(sBreite * 2) + 2] == 'X'; i++)
					{
						countersize++;
						if (Feld2[sLaenge + 5 + i][(sBreite * 2) + 2] == '#')
							countersize = 0;
					}
					if (Feld2[sLaenge + 4][(sBreite * 2) + 2] == '#' || Feld2[sLaenge + 2][(sBreite * 2) + 2] == '#')
						countersize = 0;
					break;
				default:
					break;
				}


				system("cls");
				showGame();
				printf(YELLOW);
				if (countersize == 5)		//Welche Art Schiff wurde zerstört?
					printf("\nSie haben das gegnerische Schlachtschiff zerst\x094rt! Weiter so!\n");
				if (countersize == 4)
					printf("\nSie haben einen gegnerischen Kreuzer zerst\x094rt! Gute Arbeit!\n");
				if (countersize == 3)
					printf("\nSie haben einen gegnerischen Zerst\x094rer demoliert! Sehr gut!\n");
				if (countersize == 2)
					printf("\nSie haben ein gegnerisches U-Boot zerst\x094rt! Sehr sch\x094n!\n");
				printf("\nTreffer bei %d/%c <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
				fehlversuch++;
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == '~')
			{
				Feld1[sLaenge + 3][(sBreite * 2) + 33] = 'O';
				Feld2[sLaenge + 3][(sBreite * 2) + 2] = 'O';
				system("cls");
				showGame();
				printf(YELLOW);
				printf("\nDer ging ins Leere! Bei %d/%c <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
				fehlversuch++;
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == 'X')
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nSie haben doch schon bei %d/%c getroffen! Versuchen Sie es nochmal!<ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == 'O')
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nDas haben wir doch schon probiert! Bei %d/%c war nichts! Versuchen Sie es nochmal!<ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
			}
			else
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nBitte in den markierten Bereich schießen!<ENTER>");
				printf(RESETCOLOUR);
				getchar();
			}
		}
		if (gamePlayer == 1)
		{
			if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == '#')
			{
				Feld2[sLaenge + 3][(sBreite * 2) + 33] = 'X';
				Feld1[sLaenge + 3][(sBreite * 2) + 2] = 'X';

				if (Feld1[sLaenge + 3][(sBreite * 2) + 2 + 2] == 'X')
					direction = 1;
				if (Feld1[sLaenge + 3][(sBreite * 2)] == 'X')
					direction = 1;
				if (Feld1[sLaenge + 4][(sBreite * 2) + 2] == 'X')
					direction = 2;
				if (Feld1[sLaenge + 2][(sBreite * 2) + 2] == 'X')
					direction = 2;

				switch (direction)
				{
				case 1:
					for (int i = 2; Feld1[sLaenge + 3][(sBreite * 2) + 2 * i] == 'X'; i++) //zeigt auf eins nach rechts, wenn laenge 1 ist, dann zeigt es auf 2 und geht immer weiter bis es kein X mehr ist
					{
						countersize++;
						if (Feld1[sLaenge + 3][(sBreite * 2) + 2 * (i + 1)] == '#') //zeigt auf zwei nach rechts, wenn laenge 1 ist, dann zeigt es auf 3 und geht immer weiter
							countersize = 0;
					}
					for (int i = 0; Feld1[sLaenge + 3][(sBreite * 2) - 2 * i] == 'X'; i++) //zeigt auf eins nach links, wenn laenge 3 ist, dan zeigt es auf 2 und geht immer weiter bis kein x mehr ist
					{
						countersize++;
						if (Feld1[sLaenge + 3][(sBreite * 2) - 2 * (i + 1)] == '#') //zeigt auf zwei nach links, wenn laenge 3 ist, dann zeigt es auf 1 und geht immer weiter
							countersize = 0;
					}
					if (Feld1[sLaenge + 3][(sBreite * 2) + 4] == '#' || Feld1[sLaenge + 3][(sBreite * 2)] == '#')
						countersize = 0;
					break;
				case 2:
					for (int i = 0; Feld1[sLaenge + 2 - i][(sBreite * 2) + 2] == 'X'; i++)
					{
						countersize++;
						if (Feld1[sLaenge + 1 - i][(sBreite * 2) + 2] == '#')
							countersize = 0;
					}
					for (int i = 0; Feld1[sLaenge + 4 + i][(sBreite * 2) + 2] == 'X'; i++)
					{
						countersize++;
						if (Feld1[sLaenge + 5 + i][(sBreite * 2) + 2] == '#')
							countersize = 0;
					}
					if (Feld1[sLaenge + 4][(sBreite * 2) + 2] == '#' || Feld1[sLaenge + 2][(sBreite * 2) + 2] == '#')
						countersize = 0;
					break;
				default:
					break;
				}


				system("cls");
				showGame();
				printf(YELLOW);
				if (countersize == 5)
					printf("\nSie haben das gegnerische Schlachtschiff zerst\x094rt! Weiter so!\n");
				if (countersize == 4)
					printf("\nSie haben einen gegnerischen Kreuzer zerst\x094rt! Gute Arbeit!\n");
				if (countersize == 3)
					printf("\nSie haben einen gegnerischen Zerst\x094rer demoliert! Sehr gut!\n");
				if (countersize == 2)
					printf("\nSie haben ein gegnerisches U-Boot zerst\x094rt! Sehr sch\x094n!\n");
				printf("\nTreffer bei %d/%c! Spielerwechsel... <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
				fehlversuch++;
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == '~')
			{
				Feld2[sLaenge + 3][(sBreite * 2) + 33] = 'O';
				Feld1[sLaenge + 3][(sBreite * 2) + 2] = 'O';
				system("cls");
				showGame();
				printf(YELLOW);
				printf("\nDer ging ins Leere! Bei %d/%c! Spielerwechsel... <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
				fehlversuch++;
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == 'X')
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nSie haben doch schon bei %d/%c getroffen! Versuchen Sie es nochmal! <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == 'O')
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nDas haben wir doch schon probiert! Bei %d/%c war nichts! Versuchen Sie es nochmal! <ENTER>", sBreite, c_sLaenge);
				printf(RESETCOLOUR);
				getchar();
			}
			else
			{
				system("cls");
				showGame();
				printf(RED);
				printf("\nBitte in den markierten Bereich schießen! <ENTER>");
				printf(RESETCOLOUR);
				getchar();
			}
		}
	}
	sieg();
}

void gameSpeichern() {
	const char DATEINAMEP1[] = "schiffeVP1.data";
	const char DATEINAMEP2[] = "schiffeVP2.data";
	const char DATEINAMETP[] = "playerTurn.txt";

	FILE* meineDatei1 = fopen(DATEINAMEP1, "wb");

	if (meineDatei1 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMEP1);
		fclose(meineDatei1);
		return;
	}

	fwrite(Feld1, sizeof(char), sizeof(Feld1), meineDatei1);
	fclose(meineDatei1);

	FILE* meineDatei2 = fopen(DATEINAMEP2, "wb");

	if (meineDatei2 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMEP2);
		fclose(meineDatei2);
		return;
	}

	fwrite(Feld2, sizeof(char), sizeof(Feld2), meineDatei2);
	fclose(meineDatei2);

	FILE* meineDatei3 = fopen(DATEINAMETP, "w+");
	if (meineDatei3 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMETP);
		fclose(meineDatei3);
		return;
	}
	gameFlipper--;
	fprintf(meineDatei3, "%d", gameFlipper);
	fclose(meineDatei3);

	printf("\nSpiel wurde gespeichert!\n");
}

void spielladen() {
	const char DATEINAMEP1[] = "schiffeVP1.data";
	const char DATEINAMEP2[] = "schiffeVP2.data";
	const char DATEINAMETP[] = "playerTurn.txt";

	FILE* meineDatei1 = fopen(DATEINAMEP1, "rb");

	if (meineDatei1 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMEP1);
		fclose(meineDatei1);
		return;
	}

	fread(Feld1, sizeof(char), sizeof(Feld1), meineDatei1);
	fclose(meineDatei1);

	FILE* meineDatei2 = fopen(DATEINAMEP2, "rb");

	if (meineDatei2 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMEP2);
		fclose(meineDatei2);
		return;
	}

	fread(Feld2, sizeof(char), sizeof(Feld2), meineDatei2);
	fclose(meineDatei2);

	FILE* meineDatei3 = fopen(DATEINAMETP, "r");
	if (meineDatei3 == NULL) {
		printf("Datei %s konnte nicht geoeffnet werden!", DATEINAMETP);
		fclose(meineDatei3);
		return;
	}
	char buffer[80];
	fgets(buffer, 80, meineDatei3);

	gameFlipper = atoi(buffer);

	printf("\n\nSpiel wurde geladen!\n");

}

void gameSchiffeVersenken()
{
	int auswahl = 0;
	

	do {
		int auswahlGame = 0;
		beenden = 0;
		system("cls");
		printf(CYAN);
		print_image("shipimage.txt");
		printf(RESETCOLOUR);
		printf("\nMen\x081:\n1)Spielen\n2)Spiel laden\n3)Beenden\nEingabe: ");
		scanf("%d%c", &auswahl, &puffer);

		switch (auswahl) {
		case 1:
			system("cls");
			createGame();
			pchanger();
			shipinput();
			system("cls");
			showGame();
			printf("\nSPIELERWECHSEL...");
			getchar();
			system("cls");
			printf("\nSPIELERWECHSEL...");
			getchar();
			pchanger();
			shipinput();
			system("cls");
			showGame();
			printf("\nSPIELERWECHSEL...");
			getchar();

			while (beenden == 0)
			{
				
				pchanger();
				system("cls");
				printf("SPIELERWECHSEL!");
				getchar();
				system("cls");
				printf("Men\x081:\n1)Schuss\n2)Speichern\n3)Beenden\nEingabe: ");
				scanf("%d%c", &auswahlGame, &puffer);

				switch (auswahlGame) {
				case 1:
					schuss();
					break;
				case 2:
					gameSpeichern();
					getchar();
					beenden++;
					break;
				case 3:
					printf("-- Spiel wurde beendet! --");
					getchar();
					beenden++;
					break;
				default:
					printf("Falsche Eingabe!");
					break;
				}
			}
			break;
		case 2:
			spielladen();

			while (beenden == 0)
			{
				pchanger();
				printf("SPIELERWECHSEL!");
				getchar();

				system("cls");
				printf("Men\x081:\n1)Schuss\n2)Speichern\n3)Beenden\nEingabe: ");
				scanf("%d%c", &auswahlGame, &puffer);

				switch (auswahlGame) {
				case 1:
					schuss();
					break;
				case 2:
					gameSpeichern();
					getchar();
					beenden++;
					break;
				case 3:
					printf("-- Spiel wurde beendet! --");
					getchar();
					beenden++;
					break;
				default:
					printf("Falsche Eingabe!");
					break;
				}
			}

			break;
		case 3:
			printf("\n-- Ende --");
			break;
		}

	} while (auswahl < 3);
}