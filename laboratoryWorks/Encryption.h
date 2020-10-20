#pragma once
#include"iostream"
#include<fstream>
#include<string>
#include"clocale"
using namespace std;

string getString(string filename);
void readFile(string filename);
void writeFile(string filename, string str);
