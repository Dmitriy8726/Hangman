#ifndef OTHERFUNC_H
#define OTHERFUNC_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype> 
#include <ctime>

int Select_Theme();

void Testing_main(int theme);

void Game(char slovo[], int dl);

void PrintSuares(int dl);

int Proverka(char &letter);

int Povtor(char letter, int *&C, int kol, char *A);

void WinMenu();

void LoseMenu();

#endif