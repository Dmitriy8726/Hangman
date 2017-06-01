#include "graph.h"
#include "otherfunc.h"

using namespace std;

COORD zero = { 0,0 };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int vibor = 0;

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	system("mode con cols=120 lines=30");
	int sel = 0, ch = 0, h = 0;
	while (sel != 2) {
		system("color 0f");
		while (ch != 13) {
			if (sel == 0) {
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
				Main_Menu_1();
			}
			if (sel == 1) {
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
				Main_Menu_2();
			}
			if (sel == 2) {
				SetConsoleCursorPosition(hConsole, zero);
				Intro();
				Main_Menu_3();
			}
			ch = getch();
			if (ch == 72) {
				sel--;
			}
			if (sel < 0) {
				sel = 2;
			}
			if (ch == 80) {
				sel++;
			}
			if (sel > 2) {
				sel = 0;
			}
		}
		ch = 0;
		if (sel == 0) {
			Testing_main(Select_Theme());
		}
		if (sel == 1) {
			h = 0;
			system("cls");
			while(h != 13) {
				Intro();
				Help();
				h = getch();
			}
		}
		if (sel == 2) {
			return 0;
		}
		sel = 0;
	}
}