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
	if ((i == 1) && (j == 0)) {
		theme = 2;
	}
	if ((i == 0) && (j == 1)) {
		theme = 3;
	}
	if ((i == 1) && (j == 1)) {
		theme = 4;
	}
	return theme;
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
		break;
		}
	}
}