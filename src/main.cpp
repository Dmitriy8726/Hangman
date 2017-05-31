#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "graph.h"
#include "otherfunc.h"
#include <clocale>

using namespace std;

COORD zero = { 0,0 };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	system("color 1f");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	system("mode con cols=120 lines=30");
	int sel = 0, ch = 0;
	while (sel != 2) {
		while(ch != 13){
			if(sel == 0){
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
				Main_Menu_1();
			}
			if(sel == 1){
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
				Main_Menu_2();
			}
			if(sel == 2){
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
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
		if(sel == 0){
			Testing_main(Select_Theme());
		}
	}
	return 0;
}