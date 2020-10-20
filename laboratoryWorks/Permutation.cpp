#include"Permutation.h"

int* permutation(int n) {
	int* buff = new int[n];
	cout << "Введите числа от 0 до " << n - 1 << " без повтора\n";
	int elem;
	cin >> elem;
	while (elem < 0 || elem > n - 1) {
		cout << "No\n";
		cin >> elem;
	}
	buff[0] = elem;

	for (int i = 1; i < n; ++i) {
		cin >> elem;
		for (int j = 0; j < i; ++j) {
			while (elem < 0 || elem > n - 1 || elem == buff[j]) {
				cout << "No\n";
				cin >> elem;
			}
		}
		buff[i] = elem;
	}
	return buff;
}

char** initMatrix(int numberOfRows, int numberOfColumns) {
	char** matrix = new char*[numberOfRows];
	for (int i = 0; i < numberOfRows; ++i)matrix[i] = new char[numberOfColumns];
	for (int i = 0; i < numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j)matrix[i][j] = ' ';
	return matrix;
}

void deleteMatrix(char** &matrix, int numberOfRows, int numberOfColumns) {
	for (int i = 0; i < numberOfRows; ++i)
		delete[]matrix[i];
	delete[]matrix;
}

string direct(string originalFileName, int &numberOfRows, int &numberOfColumns) {
	string str = getString(originalFileName);
	string finalFileName = "en_" + originalFileName;
	int n = str.length();
	numberOfRows = numberOfColumns = int(sqrt(n));
	while (numberOfRows*numberOfColumns < n) {
		if (numberOfRows > numberOfColumns)++numberOfColumns;
		else ++numberOfRows;
	}
	cout << "Количество строк: " << numberOfRows << ", количество столбцов: " << numberOfColumns << '\n';
	int numberAdditionalCharacters = numberOfRows * numberOfColumns - n;
	string strForMatrix = str.insert(str.length(), numberAdditionalCharacters, ' ');
	char** matrix = initMatrix(numberOfRows, numberOfColumns);
	int* permutationOfRows = permutation(numberOfRows);
	int* permutationOfColumns = permutation(numberOfColumns);
	int k = 0;
	for (int i = 0; i<numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j) {
			matrix[permutationOfRows[i]][j] = strForMatrix[k];
			++k;
		}
	string str1;
	for (int j = 0; j < numberOfColumns; ++j)
		for (int i = 0; i < numberOfRows; ++i) {
			str1 += matrix[i][permutationOfColumns[j]];
		}
	deleteMatrix(matrix, numberOfRows, numberOfColumns);
	writeFile(finalFileName, str1);
	return finalFileName;
}

string inverse(string originalFileName, int &numberOfRows, int &numberOfColumns) {
	string str1 = getString(originalFileName);
	string finalFileName = "de_" + originalFileName;

	if (numberOfRows*numberOfColumns != str1.length()) {
		cout << "Файл невозможно расшифровать!\n";
		writeFile(finalFileName, "");
	}
	else {

		int rows, columns;
		cout << "Введите число строк и столбцов\n";
		cout << "Количество строк: ", cin >> rows;
		cout << "Количество столбцов: ", cin >> columns;
		if (rows != numberOfRows || columns != numberOfColumns) {
			cout << "Неверно!";
			inverse(originalFileName, numberOfRows, numberOfColumns);
		}
		else {
			char** matrix = initMatrix(numberOfRows, numberOfColumns);
			int* permutationOfRows = permutation(numberOfRows);
			int* permutationOfColumns = permutation(numberOfColumns);
			int k = 0;
			for (int j = 0; j < numberOfColumns; ++j)
				for (int i = 0; i < numberOfRows; ++i) {
					matrix[i][permutationOfColumns[j]] = str1[k];
					++k;
				}
			string str2;
			for (int i = 0; i < numberOfRows; ++i)
				for (int j = 0; j < numberOfColumns; ++j) {
					str2 += matrix[permutationOfRows[i]][j];
				}
			deleteMatrix(matrix, numberOfRows, numberOfColumns);
			writeFile(finalFileName, str2);
		}
	}
	return finalFileName;

}