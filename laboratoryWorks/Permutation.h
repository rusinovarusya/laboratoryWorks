#pragma once
#include"Encryption.h"

int* permutation(int n);
char** initMatrix(int numberOfRows, int numberOfColumns);
void deleteMatrix(char** &matrix, int numberOfRows, int numberOfColumns);

string direct(string originalFileName, int &numberOfRows, int &numberOfColumns);
string inverse(string originalFileName, int &numberOfRows, int &numberOfColumns);
