#include <iostream>
#include <windows.h>
#include <conio.h>
#include "graph.h"

extern HANDLE hConsole;
extern COORD zero;

void Select_Theme()
{
	int ch = 0;
	int i = 0, j = 0;
	while(ch != 13){
	 	if((i == 0) && (j == 0)){
	 		SetConsoleCursorPosition(hConsole, zero);
	 		Intro();
			Theme_Menu_1();
		}	
		if((i == 1) && (j == 0)){
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_2();
		}
		if((i == 0) && (j == 1)){
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_3();
		}
		if((i == 1) && (j == 1)){
			SetConsoleCursorPosition(hConsole, zero);
			Intro();
			Theme_Menu_4();
		}
		ch = getch();
		if(ch == 72){
			i--;
		}
		if(i < 0){
			i = 1;
		}
		if(ch == 80){
			i++;
		}
		if(i > 1){
			i = 0;
		}
		if(ch == 77){
			j++;
		}
		if(j > 1){
			j = 0;
		}
		if(ch == 75){
			j--;
		}
		if(j < 0){
			j = 1;
		}
	}
}