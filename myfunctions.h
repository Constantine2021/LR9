#pragma once

//====================================================================
//   заголовочный файл создан студентом группы №6 Павловым Константином
//====================================================================

//---------------------------------------------------------------------------
//вывод целого числа n в двоичном виде, bi - места пробелов
//---------------------------------------------------------------------------
void dec2bin(int n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(short n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(char n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(long long n, int b1 = -1, int b2 = -1, int b3 = -1,
	int b4 = -1, int b5 = -1, int b6 = -1, int b7 = -1);
//---------------------------------------------------------------------------
//вывод nx элементов массива X в nr строк, setw(nw)
//если nr=0, вывод в одну строку без endl
//asChar задает вывод char: true - вывод символов, false - вывод чисел
//nf - параметр манипулятора setprecision
//---------------------------------------------------------------------------
void myout(int *X,const int nx, int nr = 1, int nw = 4);
void myout(short *X, const int nx, int nr = 1, int nw = 4);
void myout(char *X, const int nx, int nr = 1, int nw = 1, bool asChar = true);
void myout(double *X, const int nx, int nr = 1, int nw = 9, int nf = 3);
//---------------------------------------------------------------------------
//присваивает nx элементам массива X случайные числа из диапазона от n0 до n1
//---------------------------------------------------------------------------
void myrnd(int *X, const int nx, int n0, int n1);
void myrnd(short *X, const int nx, int n0, int n1);
void myrnd(char *X, const int nx, char c0, char c1);
//диапазон от n0/10^nf до n1/10^nf
void myrnd(double *X, const int nx, double n0, double n1, int nf = 2);
//---------------------------------------------------------------------------
//myord сортирует nx элементов массива X 
//inc: true - сортировка по возрастанию, false - сортировка по убыванию
//meth: 't' - метод перестановок, 's' - метод выбора, 'i' - метод вставок
//---------------------------------------------------------------------------
int mytransp(int *X, int nx, bool inc = true);
void mysel(int *X, int nx, bool inc = true);
void myins(int *X, int nx, bool inc = true, int newval = 0);
void myord(int *X, int nx, bool inc = true, char meth = 't');
//перегрузка для double-массива  
int mytransp(double *X, int nx, bool inc = true);
void mysel(double *X, int nx, bool inc = true);
void myins(double *X, int nx, bool inc = true, double newval = 0);
void myord(double *X, int nx, bool inc = true, char meth = 't');

