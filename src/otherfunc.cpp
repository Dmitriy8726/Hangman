#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "graph.h"

extern HANDLE hConsole;
extern COORD zero;

using namespace std;

int Select_Theme()
{
	int ch = 0, theme = 0;;
	int i = 0, j = 0;
	while (ch != 13) {
	 	if ((i == 0) && (j == 0)) {
	 		SetConsoleCursorPosition(hConsole, zero);
	 		Intro();
			Theme_Menu_1();
		}	
		if ((i == 1) && (j == 0)) {
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_2();
		}
		if ((i == 0) && (j == 1)) {
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_3();
		}
		if ((i == 1) && (j == 1)) {
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_4();
		}
		ch = getch();
		if (ch == 72) {
			i--;
		}
		if (i < 0) {
			i = 1;
		}
		if (ch == 80) {
			i++;
		}
		if (i > 1) {
			i = 0;
		}
		if (ch == 77) {
			j++;
		}
		if (j > 1) {
			j = 0;
		}
		if (ch == 75) {
			j--;
		}
		if (j < 0) {
			j = 1;
		}
	}
	if ((i == 0) && (j == 0)) {
		theme = 1;
	}
	if ((i == 0) && (j == 1)) {
		theme = 2;
	}
	if ((i == 1) && (j == 0)) {
		theme = 3;
	}
	if ((i == 1) && (j == 1)) {
		theme = 4;
	}
	return theme;
}

void PrintSuares(int dl)
{
	int i = 0;
	cout << "                  Amazing word:" << endl;
	cout << "                  ";
	for (i = 0; i < dl; i++) {
		cout << "_____  ";
	}
	cout << endl;
	cout << "                  ";
	for (i = 0; i < dl; i++) {
		cout << "| _ |  ";
	}
	cout << endl;
	cout << "                  ";
	for (i = 0; i < dl; i++) {
		cout << "|___|  ";
	}
	cout << endl << endl;
	
}

void Game(char slovo[], int dl)
{
	int i, chelov = 0;
	SHORT x_cons;
	int flag = 0;
	char letter;
	SetConsoleCursorPosition(hConsole, zero);
	Man_0();
	PrintSuares(dl);
	while (1) {
		flag = 0;
		x_cons = 20;
		letter = getch();
		for (i = 0; i < dl; i++) {
			if (letter == slovo[i]) {
				COORD position = { x_cons,14 };
				SetConsoleCursorPosition(hConsole, position);
				cout << letter;
				slovo[i] = 0;
				x_cons += 7;
				flag = 1;
			}
			else {
				COORD position = { x_cons,14 };
				SetConsoleCursorPosition(hConsole, position);
				x_cons += 7;
			}		
		}
	
		if (flag == 0) {
			++chelov;
		}
		switch (chelov) {
			case 0:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_0();
				break;
			}
			case 1:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_1();
				break;
			}
			case 2:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_2();
				break;
			}
			case 3:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_3();
				break;
			}
			case 4:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_4();
				break;
			}
			case 5:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_5();
				break;
			}
			case 6:{
				SetConsoleCursorPosition(hConsole, zero);
				Man_6();
				break;
			}	
		}	
	
	
	
	
	
	}
	
}

void Testing_main(int theme)
{
	srand(time(0));
	switch (theme) {
		case 1: {
		char slovo[10];
		ifstream fin("Programm.txt");
		if (!fin.is_open()) {
			return;
		}
		for (int i = 1 + rand()%5;i>0;i--) {
		fin >> slovo;
		}
		fin.close();
		Game(slovo, strlen(slovo));
		break;
		}
		case 2: {
		char slovo[10];
		ifstream fin("Chasti.txt");
		if (!fin.is_open()) {
			return;
		}
		for (int i = 1 + rand()%5;i>0;i--) {
		fin >> slovo;
		}
		fin.close();
		Game(slovo, strlen(slovo));
		break;
		}
		case 3: {
		char slovo[10];
		ifstream fin("Sort.txt");
		if (!fin.is_open()) {
			return;
		}
		for (int i = 1 + rand()%5;i>0;i--) {
		fin >> slovo;
		}
		fin.close();
		Game(slovo, strlen(slovo));
		break;
		}
		case 4: {
		char slovo[10];
		ifstream fin("Discretka.txt");
		if (!fin.is_open()) {
			return;
		}
		for (int i = 1 + rand()%5;i>0;i--) {
		fin >> slovo;
		}
		fin.close();
		Game(slovo, strlen(slovo));
		break;
		}
	}
}
