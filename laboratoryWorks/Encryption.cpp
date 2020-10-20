#include"Encryption.h"

string getString(string filename) {
	ifstream fin(filename);
	string str;
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
		}
	}
	else cout << "Файл не найден\n";
	fin.close();
	return str;
}

void readFile(string filename) {
	string str = getString(filename);
	cout << '\n' << filename << " :\n" << str << "\n\n";
}

void writeFile(string filename, string str) {
	ofstream fout(filename);
	fout << str;
	fout.close();
}