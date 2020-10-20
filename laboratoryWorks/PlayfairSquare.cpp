#include"PlayfairSquare.h"

string LAT = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
string RUS = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";


char** initMatrix(int numberOfRows, int numberOfColumns) {
	char** matrix = new char*[numberOfRows];
	for (int i = 0; i < numberOfRows; ++i)
		matrix[i] = new char[numberOfColumns];
	for (int i = 0; i < numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j)
			matrix[i][j] = ' ';
	return matrix;
}

void deleteMatrix(char** &matrix, int numberOfRows, int numberOfColumns) {
	for (int i = 0; i < numberOfRows; ++i)
		delete[]matrix[i];
	delete[]matrix;
	matrix = NULL;
}

string createCipherKey(string passphrase, char language) {
	string key;
	int lengthPassphrase = passphrase.length();
	key += passphrase[0];
	for (int i = 1; i < lengthPassphrase; ++i)
		if (key.find(passphrase[i]) == -1)key += passphrase[i];

	if (language == 'L') {
		int length = LAT.length();
		for (int i = 0; i < length; ++i)
			if (passphrase.find(LAT[i]) == -1)key += LAT[i];
	}
	else {
		if (language == 'K') {
			int length = RUS.length();
			for (int i = 0; i < length; ++i)
				if (passphrase.find(RUS[i]) == -1)key += RUS[i];
		}
		else key = "";
	}
	return key;
}

/*char** Matrix(string str, int numberOfRows, int numberOfColumns) {
	char** matrix = initMatrix(numberOfRows, numberOfColumns);
	//
	int numberChar = 0;
	int n = numberOfRows;
	for (int circle = 0; circle < n / 2; ++circle) {
		for (int j = circle; j < n - circle; ++j) {
			matrix[circle][j] = str[numberChar];
			++numberChar;
		}
		for (int i = circle + 1; i < n - circle - 1; ++i) {
			matrix[i][n - circle - 1] = str[numberChar];
			++numberChar;
		}
		for (int j = n - circle - 1; j >= circle; --j) {
			matrix[n - circle - 1][j] = str[numberChar];
			++numberChar;
		}
		for (int i = n - circle - 2; i >= circle + 1; --i) {
			matrix[i][circle] = str[numberChar];
			++numberChar;
		}
	}
	if (int lastChar = n / 2 != 0)matrix[lastChar + 1][lastChar + 1] = str[numberChar];
return matrix;
}*/

char** fillMatrixInSpiral(string str, int numberOfRows, int numberOfColumns) {
	char** matrix = initMatrix(numberOfRows, numberOfColumns);
	int numberChar = 0;
	int lengthStr = str.length();
	int n = (numberOfRows <= numberOfColumns) ? numberOfRows : numberOfColumns;

	for (int circle = 0; circle < n / 2+1; ++circle) {
		if (numberChar<lengthStr)
			for (int j = circle; j < numberOfColumns - circle; ++j) {
				matrix[circle][j] = str[numberChar];
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int i = circle + 1; i < numberOfRows - circle - 1; ++i) {
				matrix[i][numberOfColumns - circle - 1] = str[numberChar]; 
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int j = numberOfColumns - circle - 1; j >= circle; --j) {
				matrix[numberOfRows - circle - 1][j] = str[numberChar]; 
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int i = numberOfRows - circle - 2; i >= circle + 1; --i) {
				matrix[i][circle] = str[numberChar];
				++numberChar;
			}
	}

	/*for (int circle = 0; circle < n / 2; ++circle) {
		if(numberChar<lengthStr)
			for (int j = circle; j < numberOfColumns - circle; ++j) {
				matrix[circle][j] = str[numberChar];
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int i = circle + 1; i < numberOfRows - circle - 1; ++i) {
				matrix[i][numberOfColumns - circle - 1] = str[numberChar];
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int j = numberOfColumns - circle - 1; j >= circle; --j) {
				matrix[numberOfRows - circle - 1][j] = str[numberChar];
				++numberChar;
			}
		if (numberChar<lengthStr)
			for (int i = numberOfRows - circle - 2; i >= circle + 1; --i) {
				matrix[i][circle] = str[numberChar];
				++numberChar;
			}
	}
	if (numberOfRows == numberOfColumns && n / 2 != 0)matrix[n / 2 + 1][n / 2 + 1] = str[numberChar];*/
	return matrix;
}

void printMatrix(char**matrix, int numberOfRows, int numberOfColumns) {
	for (int i = 0; i < numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	cout << '\n';
}



//
/*string convert(string str, char** matrix, int numberOfRows, int numberOfColumns) {
	int a1, a2, b1, b2;
	//(a1, a2), (b1, b2)
	string str1;
	for (int i = 0; i < numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j) {
			if (str[0] == matrix[i][j]) {
				a1 = i;
				a2 = j;
			}
			if (str[1] == matrix[i][j]) {
				b1 = i;
				b2 = j;
			}
		}
	if(a1!=b1 && a2!=b2){
		str1 += matrix[a1][b2];
		str1 += matrix[b1][a2];
	}
	else {
		if (a1 == b1 && a2 != b2) {
			//?
			if (a2 == numberOfColumns - 1) {
				str1 += matrix[a1][0];
				str1 += matrix[b1][b2 + 1];
			}
			if (b2 == numberOfColumns - 1) {
				str1 += matrix[a1][a2 + 1];
				str1 += matrix[b1][0];
			}
			else {
				//

				str1 += matrix[a1][a2 + 1];//[a1 + 1][a2];
				str1 += matrix[b1][b2 + 1];//[b1 + 1][b2];
			}
		}
		else {
			//
			if (a1 == numberOfRows - 1) {
				str1 += matrix[0][a2];
				str1 += matrix[b1 + 1][b2];
			}
			if (b1 == numberOfRows - 1) {
				str1 += matrix[a1 + 1][a2];
				str1 += matrix[0][b2];
			}
			//
			else {
				str1 += matrix[a1 + 1][a2];//[a1][a2 + 1];//??
				str1 += matrix[b1 + 1][b2];//[b1][b2 + 1];
			}
		}
	}
	return str1;
}*/

string convert(string str, char** matrix, int numberOfRows, int numberOfColumns) {
	int Ax = 0;
	int Ay = 0;
	int Bx = 0;
	int By = 0;
	//(Ax, Ay), (Bx, By)
	string str1;
	for (int i = 0; i < numberOfRows; ++i)
		for (int j = 0; j < numberOfColumns; ++j) {
			if (matrix[i][j] == str[0]) {
				Ax = i;
				Ay = j;
			}
			if (matrix[i][j] == str[1]) {
				Bx = i;
				By = j;
			}
		}
	
	if (Ax != Bx && Ay != By) {
		str1 += matrix[Ax][By];
		str1 += matrix[Bx][Ay];
	}
	else {
		if (Ax == Bx) {
			if (Ay == numberOfColumns - 1) {
				str1 += matrix[Ax][0];
				str1 += matrix[Bx][By + 1]; 
			}
			else {
				if (By == numberOfColumns - 1) {
					str1 += matrix[Ax][Ay + 1];
					str1 += matrix[Bx][0];
				}
				else {
					str1 += matrix[Ax][Ay + 1];
					str1 += matrix[Bx][By + 1];
				}

			}

		}
		if (Ay == By) {
			if (Ax == numberOfRows - 1) {
				str1 += matrix[0][Ay];
				str1 += matrix[Bx + 1][By];
			}
			else {
				if (Bx == numberOfRows - 1) {
					str1 += matrix[Ax + 1][Ay];
					str1 += matrix[0][By];
				}
				else {
					str1 += matrix[Ax + 1][Ay];
					str1 += matrix[Bx + 1][By];
				}
			}
		}
	}

	return str1;
}

string prepareString(string originalString) {
	int length = originalString.length();
	string finalString;
	for (int i = 0; i < length; ++i) {
		if (originalString[i] != ' ')finalString += toupper(originalString[i]);
	}
	return finalString;
}

string* decomposeIntoBigrams(string str, int &size) {
	int length = str.length();
	bool haveEmptyElem = ((length % 2) != 0);
	size = (haveEmptyElem ? length / 2 + 1 : length / 2);
	string* arrayBigrams = new string[size];
	for (int i = 0; i < length-1; i+=2) {
		string elem;
		elem += str[i];
		elem += str[i + 1];
		arrayBigrams[i/2] = elem;
	}
	if (haveEmptyElem) {
		arrayBigrams[size - 1] += str[length - 1];
		arrayBigrams[size - 1] += 'Q';
	}

	for (int i = 0; i < size; ++i) {
		if (arrayBigrams[i][0] == arrayBigrams[i][1]) { 
			arrayBigrams[i] = arrayBigrams[i][0];
			arrayBigrams[i] += 'Q';
		}
	}

	return arrayBigrams;
}

char defineLanguage(string str) {
	int size = str.length();
	char language;
	if (int(str[0]) >= int('A') && int(str[0]) <= int('z')) language = 'L';
	else {
		if (int(str[0]) >= int('А') && int(str[0]) <= int('я')) language = 'K';
		else language = 'n';
	}
	for (int i = 1; i < size; ++i) {
		if (language == 'L' && int(str[i]) >= int('A') && int(str[i]) <= int('z')) language = 'L';
		else {
			if (language == 'K' && int(str[i]) >= int('А') && int(str[i]) <= int('я')) language = 'K';
			else language = 'n';
		}
	}
	return language;
}

string direct(string originalFileName) {
	string originalMessage = getString(originalFileName);
	string finalFileName = "en_" + originalFileName;
	//
	string phrase;
	cout << "\nPhrase is...\n";
	cin >> phrase;
	phrase = prepareString(phrase);//13.10
	cout << phrase;//13.10
	char languageOfMessage = defineLanguage(originalMessage);
	char languageOfPhrase = defineLanguage(phrase);
	if (languageOfMessage==languageOfPhrase) {
		string key = createCipherKey(phrase, languageOfPhrase);
		int numberOfRows;
		int numberOfColumns;
		if (languageOfMessage == 'e') {
			numberOfRows = 5;
			numberOfColumns = 5;
		}
		else {
			numberOfRows = 8;
			numberOfColumns = 4;
		}
		
		char** matrix = fillMatrixInSpiral(key, numberOfRows, numberOfColumns);
		cout << '\n';//13.10
		printMatrix(matrix, numberOfRows, numberOfColumns);//13.10
		int sizeOfArray;
		string* arrayOfOriginalBigrams = decomposeIntoBigrams(prepareString(originalMessage), sizeOfArray);//13.10
		/*Time*/
		for (int i = 0; i < sizeOfArray; ++i)cout << arrayOfOriginalBigrams[i] << ' ';//13.10
		cout << '\n';//13.10

		//1
		/*string* arrayOfFinalBigrams = new string[sizeOfArray];
		for (int i = 0; i < sizeOfArray; ++i)
			arrayOfFinalBigrams[i] = convert(arrayOfOriginalBigrams[i], matrix, numberOfRows, numberOfColumns);
		string finalMessage;
		for (int i = 0; i < sizeOfArray; ++i)
			finalMessage += arrayOfFinalBigrams[i];*/
		//delete 

		//2
		string finalMessage;
		for (int i = 0; i < sizeOfArray; ++i)
			finalMessage += convert(arrayOfOriginalBigrams[i], matrix, numberOfRows, numberOfColumns);
		cout << '\n' << finalMessage << '\n';//13.10

		//delete
		for (int i = 0; i < sizeOfArray; ++i)
			delete[]arrayOfOriginalBigrams;

		writeFile(finalFileName, finalMessage);

	}
	else {
		cout << "No!";
		finalFileName = "";
	}

	/*int lengthString = str.length();
	int size;
	string* arrayOfString = decomposeIntoBigrams(str, size);
	string* result = new string[size];

	string phrase;
	cout << "\nphrase...\n";
	cin >> phrase;

	string key = createCipherKey(phrase, 'e');
	//cin >> key;
	char** matrix = fillMatrixInSpiral(key, numberOfRows, numberOfColumns);
	for (int i = 0; i < size; ++i) {
		result[i] = convert(arrayOfString[i], matrix, numberOfRows, numberOfColumns);
	}

	/*int n = str.length();
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
	writeFile(finalFileName, str1);*/
	return finalFileName;
}

/*string inverse(string originalFileName, int &numberOfRows, int &numberOfColumns) {
	string originalMessage = getString(originalFileName);
	string finalFileName = "de_" + originalFileName;
	/*
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
	}//
	return finalFileName;

}*/