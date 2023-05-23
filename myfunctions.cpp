#include <iostream>
#include <iomanip>
#include <fstream>
#include "myfunctions.h"
using namespace std;

int nt = 0;

void title(int n, char abc, int len1, int len2, char ch)
{
	cout.flags(0);
	if (nt++ != 0)
		cout << endl;
	for (int i = 0; i < len1; i++)
		cout << ch;
	cout << " ������� " << n << abc << " ";
	for (int i = 0; i < len2; i++)
		cout << ch;
	cout << endl;
}

//������� �������� ������������� n
void binout(char n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned char m = n, k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

unsigned int myrnd()
{
	unsigned int res;
	char* p = (char*)&res;
	for (int i = 0; i < 4; i++)
	{
		*p = rand() % 256;
		p++;
	}
	return res;
}

int myrnd(int a, int b)
{
	if (a > b)
		return 0;
	return a + myrnd() % (b - a + 1);
}

double myrnd(double x, double y, int n)
{
	if (x > y || n < 0)
		return 0;
	double m = pow(10, n);
	int a = x * m, b = y * m;
	return myrnd(a, b) / m;
}

void myrnd(int* M, int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(a, b);
}

void myrnd(double* M, int size, double x, double y, int n)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(x, y, n);
}

void myout(int* M, int size, int nc, int nw)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(char* M, int size, int nc, int nw)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(double* M, int size, int nc, int nw, int nq)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setw(nw) << setprecision(nq) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(int** M, int nr, int* size, int nw)
{
	for (int i = 0; i < nr; i++)
		if (size[i])
			myout(M[i], size[i], size[i], nw);
		else
			cout << endl;
}

//���������� 2 ����� a,b � ������ ����������� e
bool realequal(float a, float b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

bool realequal(double a, double b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

void mysrt(int* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

void mysrt(double* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

void mysrt(int* X, int nx, bool inc, int* P[])
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] > X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] < X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

void mysrt(double* X, int nx, bool inc, double* P[])
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] > X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] < X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

void mysrt(char** X, int nx, bool inc, char** P)
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1]) > 0)
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1]) < 0)
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

void mysrt(char** X, int nx, bool inc)
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1]) > 0)
					swap(X[j], X[j + 1]);
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1]) < 0)
					swap(X[j], X[j + 1]);
	}
}

//��������� ������ max ��������
int mymax(int* M, int size)
{
	int imax = 0;
	int max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

int mymax(double* M, int size)
{
	int imax = 0;
	double max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

//��������� ������ min ��������
int mymin(int* M, int size)
{
	int imin = 0;
	int min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}

int mymin(double* M, int size)
{
	int imin = 0;
	double min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}

float meanval(int* x, int nx)
{
	float sum = 0;
	for (int i = 0; i < nx; i++)
	{
		sum += x[i];
	}
	return sum / nx;
}

//��������� ����� ������ � ������ s
int mylen(const char* s)
{
	char* p = (char*)s;
	while (*p != 0)
		p++;
	return p - s;
}

//�������� ������ t � ������ s
char* mycpy(char* s, const char* t)
{
	char* p = s, * q = (char*)t;
	while (1)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	return s;
}

//�������� n ������ �������� ������ t � ������ s
char* mycpy(char* s, const char* t, int n, bool addNull)
{
	char* p = s, * q = (char*)t;
	for (int i = 0; i < n; i++)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	if (addNull)
		*p = '\0';
	return s;
}

//���������� ������ s � t
char* mycat(char* s, const char* t)
{
	char* p = s + mylen(s), * q = (char*)t;
	while (1)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	return s;
}

//���������� ������ n �������� ����� s, t
bool mycmp(const char* s, const char* t, int n)
{
	char* p = (char*)s, * q = (char*)t;
	int ns = mylen(s), nt = mylen(t);
	if (n <= 0)
		n = ns > nt ? ns : nt;
	for (int i = 0; i < n; i++, p++, q++)
		if (*p != *q)
			return true;
	return false;
}

//��������� ����� 1-�� ��������� ��������� t � ������ s
char* mystr(const char* s, const char* t, int n)
{
	if (n <= 0)
		n = mylen(t);
	char* end = (char*)s + mylen(s) - n;
	for (char* p = (char*)s; p <= end; p++)
		if (!mycmp(p, t, n))
			return p;
	return NULL;
}

//������� � ������ ������ s ndel ��������
void mydel(char* s, int ndel)
{
	if (ndel <= 0)
		return;
	mycpy(s, s + ndel);
}

//��������� � ������ ������ s ������ t
void myins(char* s, const char* t)
{
	int ns = mylen(s), nt = mylen(t);
	for (char* p = s + ns; p >= s; p--)
		*(p + nt) = *p;
	mycpy(s, t, nt);
}

//���������� ���������� ������ ������ ������������,
//������������� � ������ ������ s
int myspn(const char* s, const char* sep)
{
	char* p = (char*)s;
	while (mystr(sep, p, 1))
		p++;
	return p - s;
}

//���������� ���������� ������ ������ ��������� ��������,
//������������� � ������ ������ s
int mycspn(const char* s, const char* sep)
{
	char* p = (char*)s;
	while (*p && !mystr(sep, p, 1))
		p++;
	return p - s;
}

//������ ����� fname � ������ s
//���������� ���������� �����
int myinput(char* s, const char* fname, const char sep)
{
		ifstream fin;                   //��������� fin - ����� ������ �� �����
		fin.exceptions(ifstream::badbit | ifstream::failbit);
		cout << "������� ������� ����\n";
		fin.open(fname, ios_base::in);  //��������� ����� fin � ������ fname
		cout << "���� ������� ������\n";
		const int nt = 256; char t[nt];   //t - ��� ����� ����� ������ �����
		int nstr = 0;                     //������� ����� �����
		char* p = s;                    //��������� �� ������ ������ s
		while (!fin.eof())               //��������� ����, ���� �� ��������� ����� �����
		{
			fin.getline(t, nt);          //������ � t ������� ������ �����
			if (*t == '\0')          //���� t - ������ ������, ������� �� �����
				break;
			mycpy(p, t);                //�������� ������ t �� ������ ��������� p
			mycpy(p, t);                //�������� ������ t �� ������ ��������� p
			nstr++;                     //����������� ������� �����
			p += mylen(t) + 1;            //���������� p �� ����� ����� �������
			*(p - 1) = sep;               //��������� ����� �������� ����������� sep
		}
		*p = '\0';                      //��������� ������ s
		fin.close();                    //��������� ����� fin	
		return nstr;                    //���������� ���������� ��������� �����
	
}

//����������� ������������ ����� d � �������� ����������
//� �������� ��������� � �������� ������ str
//(nf - ����� ������� ����� d)
char* ftoa(double d, char* str, int nf)
{
	for (int i = 0; i < nf; i++)
		d *= 10;
	_itoa(d, str, 10);
	myins(str + mylen(str) - nf, ".");
	return str;
}

//��������� nw ���� ������ s � ����� �����
//� ����������� �� �������� ��������� ������� X
char* str2int(const char* s, int nw, int* X) {
	char* p = (char*)s;      //p -> � ������ ������ s
	p += myspn(s, " ");       //p -> �� ��������� ����� s
	for (int i = 0; i < nw; i++) { //���� �� ������ ������ s
		if (X) //���� ��� ������ ������� ������ ������ ��������,
			X[i] = atoi(p);  //������� ����� -> � X[]
		p += mycspn(p, " ");  //p -> �� ��������� �����
		p += myspn(p, " ");
	}
	return p;                //���������� ����� ����� �(nw+1)
}

//��������� nw ���� ������ s � ������������ �����
//� ����������� �� �������� ��������� ������� X
char* str2dbl(const char* s, int nw, double* X) {
	char* p = (char*)s;      //p -> � ������ ������ s
	p += myspn(s, " ");       //p -> �� ��������� ����� s
	for (int i = 0; i < nw; i++) { //���� �� ������ ������ s
		if (X) //���� ��� ������ ������� ������ ������ ��������,
			X[i] = atof(p);  //������� ����� -> � X[]
		p += mycspn(p, " ");  //p -> �� ��������� �����
		p += myspn(p, " ");
	}
	return p;                //���������� ����� ����� �(nw+1)
}