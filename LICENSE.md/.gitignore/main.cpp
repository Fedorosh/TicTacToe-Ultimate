# TicTacToe-Ultimate#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <time.h>

using namespace std;
void plansza(char plansz[9][9]);
char XO(char g);
char nine(char pp);
void reset(char plansz[9][9]);
void ruch1(char plansz[9][9]);
void ruch2(char plansz[9][9]);
void remis(char plansz[9][9],int plensz[9][9],int &rem, int &iks);
void check(char plansz[9][9],int &g);
void robot(char plansz[9][9]);
char gracz = ' ';
char p = ' ';
char c = ' ';
int plensz[9][9] = {};
char plansz[9][9];
int gie[9] = {};
char xd[2] = {};


int main()
{
	srand(time(NULL));
	int check_remis = 0;
	int x=0;
	char tryb = ' ';
	reset(plansz);
	plansza(plansz);
	cout << endl;
	cout << "Witamy w grze kolko i krzyzyk 3x3!" << endl;
	cout << endl;
	system("pause");
			do 
		{
			system("cls");
			plansza(plansz);
			cout << endl;
			cout << "1 Gracz vs gracz        2 Gracz vs Komputer" << endl;
			tryb = _getch();
			if (tryb != '1' && tryb != '2')
			{
				cout << endl << "Wybierz od 1 do 2!"; Sleep(1000);
			}
		}
		while (tryb != '1' && tryb != '2');
		gracz = XO(gracz);
		if (gracz == 'X' || gracz == 'x')
		{
			xd[0] = 'X';
			xd[1] = 'O';
		}
		else
		{
			xd[0] = 'O';
			xd[1] = 'X';
		}
		cout << endl;
		cout << endl << "Ruch gracza ("<< xd[0] << ")" << endl;
		cout << "Zaczynasz od planszy po srodku " << endl;
		ruch1(plansz);
		system("cls"); plansza(plansz);
		switch (tryb)
		{
		case '2': {while(x==0)
		{
			cout << endl <<"Ruch komputera (" << xd[1] << ") na planszy nr " << c << endl;
			robot(plansz); Sleep(500);
			system("cls"); plansza(plansz);
			check(plansz,x);
			if (x != 0)
			{
				break;
			}
			cout << endl << "Ruch gracza (" << xd[0] << ") na planszy nr " << c << endl;
			ruch2(plansz);
			system("cls"); plansza(plansz);
			remis(plansz,plensz,check_remis,x);
		    check(plansz,x);
		} }
		case '1':
		{
			while (x == 0)
		{
			cout << endl << "Ruch gracza (" << xd[1] << ") na planszy nr " << c << endl;
			ruch2(plansz); 
			system("cls"); plansza(plansz);
			check(plansz, x);
			if (x != 0)
			{
				break;
			}
			cout << endl << "Ruch gracza (" << xd[0] << ") na planszy nr " << c << endl;
			ruch2(plansz);
			system("cls"); plansza(plansz);
			remis(plansz, plensz, check_remis, x);
			check(plansz, x);
		}
		}
		}
		
		
		Sleep(1000);
		system("cls");
		plansza(plansz);
		if(check_remis==81) cout << endl << "Remis!" << endl;
		cout << "Jeszcze raz? (T: Tak) ";
		char jeszcze = ' ';
		jeszcze = _getch();
		if (jeszcze == 'T'||jeszcze == 't')
		{
			system("cls");
			main();
		}
	return 0;
}
void plansza(char plansz[9][9])
{
	int x=0, y = 0;
	for (int i = 0; i < 9 ; i++)
	{
		if(i ==2 || i == 5 || i == 8 )
		{
			cout << " " << plansz[x][y] << " | " << plansz[x][y+1] << " | " << plansz[x][y+2] << "    " << plansz[x + 1][y] << " | " << plansz[x + 1][y+1] << " | " << plansz[x + 1][y+2] << "    " << plansz[x + 2][y] << " | " << plansz[x + 2][y+1] << " | " << plansz[x + 2][y+2] << "  " << endl;
			cout << endl;
			x += 3;
			y = 0;
		}
		else
		{
			cout << " "<<plansz[x][y]<<" | " << plansz[x][y+1] << " | " << plansz[x][y+2] << "    " << plansz[x+1][y] << " | " << plansz[x+1][y+1] << " | " << plansz[x+1][y+2] << "    " << plansz[x+2][y] << " | " << plansz[x+2][y+1] << " | " << plansz[x+2][y+2] << "  " << endl;
			cout << " ---------    ---------    --------- " << endl;
			y += 3;


		}
	}
}
char XO(char g)
{
	do
	{
		cout << endl << "Czym chcesz grac, O czy X? ";
		g = _getch();
		if (g != 'o'&&g != 'O'&&g != 'x'&&g != 'X')
		{
			cout << "Wybierz O lub X!"; Sleep(1000);
		}
	} while (g != 'o'&&g != 'O'&&g != 'x'&&g != 'X');
	return g;
}
char nine(char pp)
{
	do
	{
		cout << "Wybierz numer pola od 1 do 9 (czytaj od lewej do prawej) " << endl;
		pp = _getch();
		if (pp != '1'&&pp != '2'&&pp != '3'&&pp != '4'&&pp != '5'&&pp != '6'&&pp != '7'&&pp != '8'&&pp != '9')
		{
			cout << "Wybierz numer od 1 do 9!" << endl; Sleep(1000);
		}
	} while (pp != '1'&&pp != '2'&&pp != '3'&&pp != '4'&&pp != '5'&&pp != '6'&&pp != '7'&&pp != '8'&&pp != '9');
	return pp;
}
void reset(char plansz[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			plansz[i][j] = ' ';
		}
	}
}
void ruch1(char plansz[9][9])
{
	p = '5';
	do
	{
		cout << endl;
		c = nine(c);
		cout << endl;
		if (plansz[(p - '0') - 1][(c - '0') - 1] == 'X' || plansz[(p - '0') - 1][(c - '0') - 1] == 'O')
		{
			cout << "To pole jest zajete!" << endl; Sleep(1000);
		}
	} while (plansz[(p - '0') - 1][(c - '0') - 1] == 'X' || plansz[(p - '0') - 1][(c - '0') - 1] == 'O');

	if (gracz == 'X' || gracz == 'x')
	{
		plansz[(p - '0') - 1][(c - '0') - 1] = 'X';
	}
	else
	{
		plansz[(p - '0') - 1][(c - '0') - 1] = 'O';
	}
}
void ruch2(char plansz[9][9])
{
		p = c;
	do
	{
		cout << endl;
		c = nine(c);
		cout << endl;
		if (plansz[(p - '0') - 1][(c - '0') - 1] == 'X' || plansz[(p - '0') - 1][(c - '0') - 1] == 'O')
		{
			cout << "To pole jest zajete!" << endl; Sleep(1000);
		}
	} while (plansz[(p - '0') - 1][(c - '0') - 1] == 'X' || plansz[(p - '0') - 1][(c - '0') - 1] == 'O');
	if (gracz == 'X' || gracz == 'x')
	{
		plansz[(p - '0') - 1][(c - '0') - 1] = 'O';
		gracz = 'o';
	}
	else
	{
		plansz[(p - '0') - 1][(c - '0') - 1] = 'X';
		gracz = 'x';
	}
}
void remis(char plansz[9][9], int plensz[9][9], int &rem, int &iks)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((plansz[i][j] == 'X' || plansz[i][j] == 'O') && plensz[i][j] == 0)
			{
				rem++;
				plensz[i][j] = 1;
			}
		}
	}
	if (rem == 81)
	{
		iks++;
	}
}
void check(char plansz[9][9],int &g)
{
	for (int i = 0; i < 9; i++)
	{
		for (int x = 0; x < 9; x += 3)
		{
			if (plansz[i][x] == 'X'&&plansz[i][x + 1] == 'X'&&plansz[i][x + 2] == 'X')
			{
				cout << "X wygrywa";
				g++;
			}
			if (plansz[i][x] == 'O'&&plansz[i][x + 1] == 'O'&&plansz[i][x + 2] == 'O')
			{
				cout << "O wygrywa";
				g++;
			}
		}
		for (int x = 0; x < 3; x++)
		{
			if (plansz[i][x] == 'X'&&plansz[i][x + 3] == 'X'&&plansz[i][x + 6] == 'X')
			{
				cout << "X wygrywa";
				g++;
			}
			if (plansz[i][x] == 'O'&&plansz[i][x + 3] == 'O'&&plansz[i][x + 6] == 'O')
			{
				cout << "O wygrywa";
				g++;
			}
		}
		if ((plansz[i][0] == 'X'&&plansz[i][4] == 'X'&&plansz[i][8] == 'X')|| (plansz[i][2] == 'X'&&plansz[i][4] == 'X'&&plansz[i][6] == 'X'))
		{
			cout << "X wygrywa";
			g++;
		}
		if ((plansz[i][0] == 'O'&&plansz[i][4] == 'O'&&plansz[i][8] == 'O') || (plansz[i][2] == 'O'&&plansz[i][4] == 'O'&&plansz[i][6] == 'O'))
		{
			cout << "O wygrywa";
			g++;
		}
	}
}
void robot(char plansz[9][9])
{
	p = c;
	int x;
	int i=0;
	do
	{
		x = rand() % 9;
		c = (x+1) + '0';
	} while (plansz[(p - '0') - 1][x] == 'X' || plansz[(p - '0') - 1][x] == 'O');
	if (gracz == 'X' || gracz == 'x')
	{
			for (int y = 0; y < 9; y += 3)
			{
				if ((plansz[(p - '0') - 1][y] == ' '||plansz[(p - '0') - 1][y + 1] == ' '||plansz[(p - '0') - 1][y + 2] == ' ' && i == 0))
				{
					if (plansz[(p - '0') - 1][y + 1] == 'O'&& plansz[(p - '0') - 1][y + 2] == 'O') { plansz[(p - '0') - 1][y] = 'O'; i++; }

					if (plansz[(p - '0') - 1][y] == 'O' && plansz[(p - '0') - 1][y + 2] == 'O') { plansz[(p - '0') - 1][y + 1] = 'O'; i++; }

					if (plansz[(p - '0') - 1][y + 1] == 'O' && plansz[(p - '0') - 1][y] == 'O') { plansz[(p - '0') - 1][y + 2] = 'O'; i++; }
				}
			}
			for (int y = 0; y < 3; y ++)
			{
				if ((plansz[(p - '0') - 1][y] == ' ' || plansz[(p - '0') - 1][y + 3] == ' ' || plansz[(p - '0') - 1][y + 6] == ' ') && i == 0)
				{
					if (plansz[(p - '0') - 1][y + 6] == 'O'&& plansz[(p - '0') - 1][y + 3] == 'O') { plansz[(p - '0') - 1][y] = 'O'; i++; }

					if (plansz[(p - '0') - 1][y] == 'O' && plansz[(p - '0') - 1][y + 6] == 'O') { plansz[(p - '0') - 1][y + 3] = 'O'; i++; }

					if (plansz[(p - '0') - 1][y + 3] == 'O' && plansz[(p - '0') - 1][y] == 'O') { plansz[(p - '0') - 1][y + 6] = 'O'; i++; }
				}
			}
			if ((plansz[(p - '0') - 1][0] == ' ' || plansz[(p - '0') - 1][5] == ' ' || plansz[(p - '0') - 1][9] == ' ' && i == 0))
			{
				if (plansz[(p - '0') - 1][5] == 'O'&& plansz[(p - '0') - 1][9] == 'O') { plansz[(p - '0') - 1][0] = 'O'; i++; }

				if (plansz[(p - '0') - 1][0] == 'O' && plansz[(p - '0') - 1][9] == 'O') { plansz[(p - '0') - 1][5] = 'O'; i++; }

				if (plansz[(p - '0') - 1][0] == 'O' && plansz[(p - '0') - 1][5] == 'O') { plansz[(p - '0') - 1][9] = 'O'; i++; }
			}
			if ((plansz[(p - '0') - 1][3] == ' ' || plansz[(p - '0') - 1][5] == ' ' || plansz[(p - '0') - 1][7] == ' ' && i == 0))
			{
				if (plansz[(p - '0') - 1][5] == 'O'&& plansz[(p - '0') - 1][7] == 'O') { plansz[(p - '0') - 1][3] = 'O'; i++; }

				if (plansz[(p - '0') - 1][3] == 'O' && plansz[(p - '0') - 1][7] == 'O') { plansz[(p - '0') - 1][5] = 'O'; i++; }

				if (plansz[(p - '0') - 1][3] == 'O' && plansz[(p - '0') - 1][5] == 'O') { plansz[(p - '0') - 1][7] = 'O'; i++;  }
			}
			if(i == 0) plansz[(p - '0') - 1][x] = 'O';
			gracz = 'o';
	}
	else
	{
		for (int y = 0; y < 9; y += 3)
		{
			if ((plansz[(p - '0') - 1][y] == ' ' || plansz[(p - '0') - 1][y + 1] == ' ' || plansz[(p - '0') - 1][y + 2] == ' ' && i == 0))
			{
				if (plansz[(p - '0') - 1][y + 1] == 'X'&& plansz[(p - '0') - 1][y + 2] == 'X') { plansz[(p - '0') - 1][y] = 'X'; i++; }

				if (plansz[(p - '0') - 1][y] == 'X' && plansz[(p - '0') - 1][y + 2] == 'X') { plansz[(p - '0') - 1][y + 1] = 'X'; i++; }

				if (plansz[(p - '0') - 1][y + 1] == 'X' && plansz[(p - '0') - 1][y] == 'X') { plansz[(p - '0') - 1][y + 2] = 'X'; i++; }
			}
		}
		for (int y = 0; y < 3; y++)
		{
			if ((plansz[(p - '0') - 1][y] == ' ' || plansz[(p - '0') - 1][y + 3] == ' ' || plansz[(p - '0') - 1][y + 6] == ' ') && i == 0)
			{
				if (plansz[(p - '0') - 1][y + 6] == 'X'&& plansz[(p - '0') - 1][y + 3] == 'X') { plansz[(p - '0') - 1][y] = 'X'; i++; }

				if (plansz[(p - '0') - 1][y] == 'X' && plansz[(p - '0') - 1][y + 6] == 'X') { plansz[(p - '0') - 1][y + 3] = 'X'; i++; }

				if (plansz[(p - '0') - 1][y + 3] == 'X' && plansz[(p - '0') - 1][y] == 'X') { plansz[(p - '0') - 1][y + 6] = 'X'; i++; }
			}
		}
		if ((plansz[(p - '0') - 1][0] == ' ' || plansz[(p - '0') - 1][5] == ' ' || plansz[(p - '0') - 1][9] == ' ' && i == 0))
		{
			if (plansz[(p - '0') - 1][5] == 'X'&& plansz[(p - '0') - 1][9] == 'X') { plansz[(p - '0') - 1][0] = 'X'; i++; }

			if (plansz[(p - '0') - 1][0] == 'X' && plansz[(p - '0') - 1][9] == 'X') { plansz[(p - '0') - 1][5] = 'X'; i++; }

			if (plansz[(p - '0') - 1][0] == 'X' && plansz[(p - '0') - 1][5] == 'X') { plansz[(p - '0') - 1][9] = 'X'; i++; }
		}
		if ((plansz[(p - '0') - 1][3] == ' ' || plansz[(p - '0') - 1][5] == ' ' || plansz[(p - '0') - 1][7] == ' ' && i == 0))
		{
			if (plansz[(p - '0') - 1][5] == 'X'&& plansz[(p - '0') - 1][7] == 'X') { plansz[(p - '0') - 1][3] = 'X'; i++; }

			if (plansz[(p - '0') - 1][3] == 'X' && plansz[(p - '0') - 1][7] == 'X') { plansz[(p - '0') - 1][5] = 'X'; i++; }

			if (plansz[(p - '0') - 1][3] == 'X' && plansz[(p - '0') - 1][5] == 'X') { plansz[(p - '0') - 1][7] = 'X'; i++; }
		}
		if(i == 0) plansz[(p - '0') - 1][x] = 'X';
		gracz = 'x';
	}

}
