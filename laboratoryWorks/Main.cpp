#include"PlayfairSquare.h"

int main() {
	setlocale(LC_CTYPE, "rus");

	/*string fileName = "fileForL.txt";
	readFile(fileName);
	int nr, nc;

	string file1 = direct(fileName, nr, nc);
	readFile(file1);

	system("pause");
	system("cls");
	string file2 = inverse(file1, nr, nc);
	readFile(file2);*/

	string str = "A";//string str = "PLAYFAIREXAMPLE";
	char**M = fillMatrixInSpiral(createCipherKey(str, 'e'), 5, 5);

	printMatrix(M, 5, 5);
	cout << M[3][3] << '!' << '\n';

	string s[] = { "HI", "DE", "TH", "EG", "OL", "DI", "NT", "HE", "TR", "EX", "ES", "TU", "MP" };
	for (int i = 0; i < 13; ++i)cout << s[i] << ' ';
	cout << '\n';
	for (int i = 0; i < 13; ++i) {
		cout << convert(s[i], M, 5, 5) << ' ';
	}
	cout << "\n\n\n***\n\n\n";
	//
	string file1 = "fileForL2.txt";
	readFile(file1);
	string file2 = direct(file1);
	readFile(file2);



	//string fileName = "fileForL2.txt";
	//cout << "\n\n\n" << direct(fileName) << "\n\n\n";
	//string ff = direct(fileName);
	//readFile(ff);

	/*int size;
	string* s = decomposeIntoBigrams(str, size);
	for (int ii = 0; ii < size; ++ii)cout << s[ii] << ' ';
	
	string str1 = "àùúûüýþÿ";
	//cout << createCipherKey(str1, 'r');
	char**R = fillMatrixInSpiral(createCipherKey(str1, 'r'), 8,4);
	printMatrix(R, 8, 4);*/

	system("pause");
	return 0;
}