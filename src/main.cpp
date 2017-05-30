#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "graph.h"
#include "otherfunc.h"

using namespace std;

COORD zero = { 0,0 };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	srand(time(0));
	system("color 1f");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	system("mode con cols=145 lines=50");
	int sel = 0, ch = 0;
	while (sel != 2) {
		while(ch != 13){
			if(sel == 0){
				SetConsoleCursorPosition(hConsole, zero);
				//Intro();
				Main_Menu_1();
			}
			if(sel == 1){
				SetConsoleCursorPosition(hConsole, zero);
				//Intro();
				Main_Menu_2();
			}
			if(sel == 2){
				SetConsoleCursorPosition(hConsole, zero);
				//Intro();
				Main_Menu_3();
			}
			ch = getch();
			if(ch == 72){
				sel--;
			}
			if(sel < 0){
				sel = 2;
			}
			if(ch == 80){
				sel++;
			}
			if(sel > 2){
				sel = 0;
			}
		}
	}
	return 0;
}
