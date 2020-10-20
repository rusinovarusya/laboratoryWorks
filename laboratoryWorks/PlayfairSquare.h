#pragma once
#include"Encryption.h"



char** initMatrix(int numberOfRows = 5, int numberOfColumns = 5);
string createCipherKey(string passphrase, char language);
char** fillMatrixInSpiral(string str, int numberOfRows, int numberOfColumns);
void printMatrix(char**matrix, int numberOfRows, int numberOfColumns);//


string convert(string str, char** matrix, int numberOfRows, int numberOfColumns);
string* decomposeIntoBigrams(string str, int &size);

string direct(string originalFileName);
char defineLanguage(string str);
string prepareString(string originalString);//