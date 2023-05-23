#pragma once
#include <fstream>


class Word
{
	char* word;
	int* pages, npages;
public:
	Word();
	void set();
	void set(const char* s);

	void show();
	void show_word();
	void show_number();
	char* getword();
	int* getpages();
	int getnpages();
	void setword(char sword);
	void setpages(int* araay, int n);
	void setnpages(int snpages);
	friend std::ostream& operator<< (std::ostream& out, const Word& wrd);
	friend std::istream& operator>> (std::istream& in, Word& wrd);
};

void words_out(Word* words, int n);
void words_grater_n(Word* array, int nwords);
void words_srt(Word* X, int n);
void pages_cin(Word* array, int n);