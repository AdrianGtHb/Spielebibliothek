#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

char Feld1[14][54];
char Feld2[14][54];
int gameFlipper = -1;
int gamePlayer = 0;
int beenden = 0;
char puffer;

void createGame()
{
	strcpy(Feld1[0], "P1     Dein Feld\t\t  Gegnerisches Feld");
	strcpy(Feld2[0], "P2     Dein Feld\t\t  Gegnerisches Feld");

	for (int i = 3; i < 13; i++)
	{
		for (int k = 2; k < 23; k += 2)
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
		for (int k = 1; k < 23; k += 2)
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
	for (int i = 2; i < 21; i += 2)
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
	for (int i = 3; i < 13; i++)
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
	if (gamePlayer == 0)
	{
		for (int i = 0; i < 14; i++)
		{
			for (int k = 0; k < 54; k++)
			{
				printf("%c", Feld1[i][k]);
			}
			printf("\n");
		}
	}
	else if (gamePlayer == 1)
	{
		for (int i = 0; i < 14; i++)
		{
			for (int k = 0; k < 54; k++)
			{
				printf("%c", Feld2[i][k]);
			}
			printf("\n");
		}
	}
}

void pchanger()
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
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			Schiffe[i][k] = k + 1;
		}
	}
	while (!(Schiffe[gamePlayer][0] == 0 && Schiffe[gamePlayer][1] == 0 && Schiffe[gamePlayer][2] == 0 && Schiffe[gamePlayer][3] == 0))
	{
		int nogo = 0;
		int constraint = 0;

		while (constraint == 0)
		{
			system("cls");
			showGame();
			printf("\n1)Schlachtschiff, 5 Kaestchen (x%d)\n2)Kreuzer, 4 Kaestchen (x%d)\n3)Zerstoerer, 3 Kaestchen (x%d)\n4)U-Boot, 2 Kaestchen (x%d)\n", Schiffe[gamePlayer][0], Schiffe[gamePlayer][1], Schiffe[gamePlayer][2], Schiffe[gamePlayer][3]);
			printf("Waehlen Sie ein Schiff, dass Sie stationieren moechten!\nEingabe: ");
			scanf("%d%c", &input, &puffer);
			if (Schiffe[gamePlayer][input - 1] == 0)
			{
				printf("\nAchtung! Von dieser Art Schiff haben Sie keins mehr! Waehlen sie ein anderes!<ENTER>");
				getchar();
			}
			else if (Schiffe[gamePlayer][input - 1] > 0)
			{
				constraint++;
			}
		}
		system("cls");
		showGame();
		printf("\nGeben Sie den gewuenschten Breitengrad ein!\nEingabe: ");
		scanf("%d%c", &breite, &puffer);
		system("cls");
		showGame();
		printf("\nGeben Sie den gewuenschten Laengengrad ein!\nEingabe: ");
		scanf("%c%c", &c_laenge, &puffer);
		system("cls");
		showGame();

		if (c_laenge == 'a' || c_laenge == 'A')
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


		switch (input)
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

		if (gamePlayer == 0)
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
				printf("\nBitte beachten Sie, dass Schiffe auf dem Spielfeld Platz haben muessen und keine anderen Schiffe beruehren duerfen!\n<ENTER> druecken um fortzufahren");
				getchar();
			}
		}


		if (gamePlayer == 1)
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
				printf("\nBitte beachten Sie, dass Schiffe auf dem Spielfeld Platz haben muessen und keine anderen Schiffe beruehren duerfen!\n<ENTER> druecken um fortzufahren");
				getchar();
			}
		}
	}
}

void sieg()
{
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
	printf("SPIELERWECHSEL!");
	getchar();
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
		printf("\nSpieler %d, geben Sie den Laengengrad zum Beschuss an!\nEingabe: ", gamePlayer + 1);
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
				case 1:
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
				case 2:
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
				if (countersize == 5)
					printf("\nSie haben das gegnerische Schlachtschiff zerstoert! Weiter so!\n");
				if (countersize == 4)
					printf("\nSie haben einen gegnerischen Kreuzer zerstoert! Gute Arbeit!\n");
				if (countersize == 3)
					printf("\nSie haben einen gegnerischen Zerstoerer demoliert! Sehr gut!\n");
				if (countersize == 2)
					printf("\nSie haben ein gegnerisches U-Boot zerstoert! Sehr schoen!\n");
				printf("\nTreffer bei %d/%c <ENTER>", sBreite, c_sLaenge);
				getchar();
				fehlversuch++;
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == '~')
			{
				Feld1[sLaenge + 3][(sBreite * 2) + 33] = 'O';
				Feld2[sLaenge + 3][(sBreite * 2) + 2] = 'O';
				system("cls");
				showGame();
				printf("\nDer ging ins Leere! Bei %d/%c <ENTER>", sBreite, c_sLaenge);
				getchar();
				fehlversuch++;
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == 'X')
			{
				system("cls");
				showGame();
				printf("\nSie haben doch schon bei %d/%c getroffen! Versuchen Sie es nochmal!<ENTER>", sBreite, c_sLaenge);
				getchar();
			}
			else if (Feld2[sLaenge + 3][(sBreite * 2) + 2] == 'O')
			{
				system("cls");
				showGame();
				printf("\nDas haben wir doch schon probiert! Bei %d/%c war nichts! Versuchen Sie es nochmal!<ENTER>", sBreite, c_sLaenge);
				getchar();
			}
			else
			{
				system("cls");
				showGame();
				printf("\nBitte in den markierten Bereich schieﬂen!<ENTER>");
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
				if (countersize == 5)
					printf("\nSie haben das gegnerische Schlachtschiff zerstoert! Weiter so!\n");
				if (countersize == 4)
					printf("\nSie haben einen gegnerischen Kreuzer zerstoert! Gute Arbeit!\n");
				if (countersize == 3)
					printf("\nSie haben einen gegnerischen Zerstoerer demoliert! Sehr gut!\n");
				if (countersize == 2)
					printf("\nSie haben ein gegnerisches U-Boot zerstoert! Sehr schoen!\n");
				printf("\nTreffer bei %d/%c! Spielerwechsel... <ENTER>", sBreite, c_sLaenge);
				getchar();
				fehlversuch++;
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == '~')
			{
				Feld2[sLaenge + 3][(sBreite * 2) + 33] = 'O';
				Feld1[sLaenge + 3][(sBreite * 2) + 2] = 'O';
				system("cls");
				showGame();
				printf("\nDer ging ins Leere! Bei %d/%c! Spielerwechsel... <ENTER>", sBreite, c_sLaenge);
				getchar();
				fehlversuch++;
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == 'X')
			{
				system("cls");
				showGame();
				printf("\nSie haben doch schon bei %d/%c getroffen! Versuchen Sie es nochmal! <ENTER>", sBreite, c_sLaenge);
				getchar();
			}
			else if (Feld1[sLaenge + 3][(sBreite * 2) + 2] == 'O')
			{
				system("cls");
				showGame();
				printf("\nDas haben wir doch schon probiert! Bei %d/%c war nichts! Versuchen Sie es nochmal! <ENTER>", sBreite, c_sLaenge);
				getchar();
			}
			else
			{
				system("cls");
				showGame();
				printf("\nBitte in den markierten Bereich schieﬂen! <ENTER>");
				getchar();
			}
		}
	}
	sieg();
}



void gameSchiffeVersenken()
{
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
		schuss();
	}
}