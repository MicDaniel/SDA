#pragma once

#include<iostream>
#include<conio.h>

#define empty 0
#define N 9

using namespace std;

bool findEmptyCells(int matrix[N][N], int &x, int &y); // cauta prima celula goala

bool isSafe(int matrix[N][N], int x, int y, int number);

bool checkRow(int matrix[N][N], int x, int number);

bool checkCol(int matrix[N][N], int y, int number);

bool checkBox(int matrix[N][N], int boxX, int boxY, int number); // patratul incepe la boxX, boxY. orice pozitie din patrat %3 rezulta boxX, boxY

bool solveSudoku(int matrix[N][N]);

void print(int matrix[N][N]);