#include "Word.h"
#include "myfunctions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
using namespace std;


Word::Word()
{
	word = 0;
	npages = 0;
	pages = 0;
}

void Word::set()
{
	cout << "¬ведите слово: ";
	cin >> word;
	char s[32];
	while (true)
	{
		cout << "¬ведите количесво страниц, на которых слово встречаетс€ (от 1 до 10): ";
		cin >> s;
		npages = atoi(s);
		if (npages >= 1 && npages < 10)
			break;
		else
			cout << "Error! Incorrect number.\n";
	}
	cout << "¬ведите номера страниц: ";
	for (int i = 0; i < npages; i++) {
		while (true)
		{
			cin >> s;
			pages[i] = atoi(s);
			if (pages[i] >= 1)
				break;
			else
				cout << "Error! Incorrect number.\n";
		}

	}
	cout << "=====================================\n";
}

void Word::set(const char* s) {
	char* p = str2int(s, 1) - 1;
	word = new char[p - s + 1];
	mycpy(word, s, p - s, 1);
	p = str2int(p, 1, &npages);
	pages = new int[npages];
	str2int(p, npages, pages);
}

char* Word::getword()
{
	return word;
}
int* Word::getpages()
{
	return pages;
}

int Word::getnpages()
{
	return npages;
}

void Word::setword(char sword)
{
	*word = sword;
}
void Word::setpages(int* array, int n)
{
	npages = n;
	for (int i = 0; i < n; i++)
		pages[i] = array[i];
}

void Word::setnpages(int snpages)
{
	npages = snpages;
}

void Word::show()
{

	cout << setw(20) << left << word << setw(8) << left << npages;
	for (int i = 0; i < npages; i++)
		cout << pages[i] << ' ';
	cout << endl;
}

void Word::show_word()
{
	cout << word << endl;
}

void Word::show_number()
{
	for (int i = 0; i < npages; i++)
		cout << pages[i] << ' ';
	cout << endl;
}

void words_out(Word* words, int n) {
	for (int i = 0; i < n; i++)
		words[i].show();
}

//слова, которые встречаютс€ более чем на N страницах
void words_grater_n(Word* array, int nwords) {
	int n;
	char s[32];
	while (true) {
		cout << "¬ведите N:";
		cin >> s;
		n = atoi(s);
		if (n >= 1)
			break;
		else
			cout << "Error! Incorrect number.\n";
	}

	ofstream fout;
	string fname = "words_grater_" + to_string(n) + "_pages.txt";
	fout.open(fname);

	cout << "—лова, которые встречаютс€ более чем на " << n << " страниц" << (n > 1 ? "ах: " : "е: ") << endl;
	fout << "—лова, которые встречаютс€ более чем на " << n << " страниц" << (n > 1 ? "ах: " : "е: ") << endl;
	for (int i = 0; i < nwords; i++)
		if (array[i].getnpages() > n) {
			cout << array[i];
			fout << array[i];
		}
	fout.close();
};

void words_srt(Word* X, int n) {
	// слова в алфавитном пор€дке
	for (int i = n; i > 1; i--)
		for (int j = 0; j < i - 1; j++)
			if (strcmp(X[j].getword(), X[j + 1].getword()) > 0)
			{
				swap(X[j], X[j + 1]);
			}
	cout << "—лова в алфавитном пор€дке:\n";

	ofstream fout;
	string fname = "ABC_order.txt";
	fout.open(fname);
	fout << "—лова в алфавитном пор€дке:\n";
	for (int i = 0; i < n; i++) {
		cout << X[i];
		fout << X[i];
	}
	fout.close();
}

//дл€ заданного слова номера страниц, на которых оно встреча≠етс€
void pages_cin(Word* array, int n) {
	char word_cin[32];
	int k = 0;
	cout << "¬ведите слово: ";
	cin >> word_cin;
	for (int i = 0; i < n; i++)
		if (!mycmp(array[i].getword(), word_cin))
		{
			array[i].show_number();
			k++;
		}
	if (k == 0)
		cout << "”пс... —лово не найдено.\n";
}

std::ostream& operator<<(std::ostream& out, const Word& wrd)
{
	out << setw(20) << left << wrd.word << setw(8) << left << wrd.npages;
	//out << wrd.word << ' ' << wrd.npages;
	for (int i = 0; i < wrd.npages; i++)
		out << ' ' << wrd.pages[i];
	out << "\n";
	return out;
}


std::istream& operator>> (std::istream& in, Word& wrd)
{
	char* word_new = new char[32];
	int* npages_new = new int();
	in >> word_new;
	in >> *npages_new;
	wrd.word = word_new;
	wrd.npages = *npages_new;
	int* pages_new = new int[wrd.npages];
	for (int i = 0; i < wrd.npages; i++)
		in >> pages_new[i];
	wrd.pages = pages_new;
	return in;
}