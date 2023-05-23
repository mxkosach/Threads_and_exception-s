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
		cout << "�������� ������:\n";
		cout << setw(20) << left << "�����:" << setw(8) << "���-��:" << "��������:\n";
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
		cout << "������ �������� �����\n";
	}
	catch (bad_alloc x)
	{
		cout << "������ ��� ��������� ������\n";
	}
	catch (...)
	{
		cout << "������! ���-�� ����� �� ���...\n";
	}
	return 0;
}



void print_menu() {
	cout << "--------------------------------------------------------------\n";
	cout << "��� �� ������ �������?" << endl;
	cout << "1. ������� �����, ������� ����������� ����� ��� �� N ���������" << endl;
	cout << "2. ������� ����� � ���������� �������" << endl;
	cout << "3. ������� ��� ��������� ����� ������ �������, �� ������� ��� �����������" << endl;
	//cout << "4. ������� ���� ������ ����" << endl;
	cout << "4. �����" << endl;
	cout << ">";
}