#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <exception>
#include "myfunctions.h"
#include "Word.h"
#include <string>
#include <sstream>

using namespace std;

void print_menu();

int main()
{
	setlocale(LC_ALL, "rus");

	int n = 15, variant = 1, i = 0;

	char* s = new char[512];
	try {
		string str;
		string inFile = "words.txt";
		ifstream fin;
		Word* words = new Word[n];
		fin.open(inFile);

		while (!fin.eof()) {
			fin >> words[i];
			i++;
		}
		fin.close();
		cout << "Исходный список:\n";
		cout << setw(20) << left << "Слово:" << setw(8) << "Кол-во:" << "Страницы:\n";
		for (int i = 0; i < n; i++)
			cout << words[i];

		ofstream fout;
		fout.open("all_words.txt");
		for (int i = 0; i < n; i++)
			fout << words[i];
		fout.close();

		while (variant != 4)
		{
			print_menu();
			cin >> s;
			variant = atoi(s);
			switch (variant)
			{
			case 1:
				words_grater_n(words, n);
				system("pause");
				break;
			case 2:
				words_srt(words, n);
				system("pause");
				break;
			case 3:
				pages_cin(words, n);
				system("pause");
				break;
			case 4:
				break;
			default:
				cout << "Error! Incorrect number.\n";
				system("pause");
				break;
			}
		}
		delete[] words;
	}
	catch (const ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Ошибка открытия файла\n";
	}
	catch (bad_alloc x)
	{
		cout << "Ошибка при выделении памяти\n";
	}
	catch (...)
	{
		cout << "Ошибка! Что-то пошло не так...\n";
	}
	return 0;
}



void print_menu() {
	cout << "--------------------------------------------------------------\n";
	cout << "Что вы хотите сделать?" << endl;
	cout << "1. Вывести слова, которые встречаются более чем на N страницах" << endl;
	cout << "2. Вывести слова в алфавитном порядке" << endl;
	cout << "3. Вывести для заданного слова номера страниц, на которых оно встреча­ется" << endl;
	//cout << "4. Вывести весь список слов" << endl;
	cout << "4. Выйти" << endl;
	cout << ">";
}