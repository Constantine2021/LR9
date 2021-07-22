#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
void srt1(int, int, int);
void srt2(int&, int&, int&);
void norm(float&, float&);
void fun1(char [], int, char[], int, int );
int fun12a(int[]);
int fun12b(int[], int);

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	{cout << "===Задание 1========"<<endl; 
	int n;
	int *p = &n;
	*p = 12;
	cout << "2) Значение n = " << n << ", адрес n = " << &n<<endl;
	cout << "3) Значение n = " << *p << ", адрес n = " << p << endl;
	cout << "4) Адрес p = " << &p<<endl;
	}
	cout << endl;
	{cout << "===Задание 2========" << endl;
	double f1 = 0.7; int n1 = 171; char c1 = 'A';
	double *F1, *F2; int *N1, *N2; char *C1, *C2;
	/*double *F3 = -47.5;//инициализация указателю неадресным значением
	int *N3 = &c1; //инициализация указателя адресом другого типа
	F1 = F2;
	N2 = 0x0016D2B8;//присваивание указателю адреса другого типа
	C1 = &f1;//присваивание указателю адреса другого типа
	F2 = N1;//в присваивании используется указатели разных типов
	C2 = c1;//присваивание указателю неадресного значения*/
	}
	cout << endl;
	{cout << "===Задание 3========" << endl; 
	double d;
	cout << "d = "<<(d= 629672911.29160953) << endl;
	char *p;
	p = (char*)&d + 6;
	cout << "байт №6 = ";
	dec2bin(*p);
	}
	cout << endl;
	{cout << "===Задание 4a========" << endl;
	int a = 3, b = 2, c = 1;
	cout << "Ввод начальных данных: " << a << " " << b << " " << c << endl;
	srt1(a, b, c);
	cout << "Результат сортировки: " << a << " " << b << " " << c << endl;
	}
	{cout << "===Задание 4b========" << endl;
	int a = 6, b = 5, c = 4;
	cout << "Ввод начальных данных: " << a << " " << b << " " << c << endl;
	srt2(a, b, c);
	cout << "Результат сортировки: " << a << " " << b << " " << c << endl;
	}
	cout << endl;
	{cout << "====Задание 5====" << endl;
	float x = 8, y = 17;
	cout << "Исходный вектор:        (" << x << ", " << y <<")"<< endl;
	norm(x, y);
	cout << "Нормализованный вектор: (" << x << ", " << y << ")" << endl;
	}
	cout << endl;
	{cout << "===Задание 6======" << endl;
	double *q, *p;
	p = new double(1.25);
	q = new double(2.75);
	if (!p) {
		cout << "\nОшибка! недостаточно памяти!\n";
		system("pause");
		exit(1);
	}
	cout << "Указателю p выделена ячейка " << p << ", содержащая число " << *p<<endl;
	cout << "Указателю q выделена ячейка " << q << ", содержащая число " << *q<<endl;
	delete p, q;
	}
	cout << endl;
	{cout << "====Задание 7======" << endl;
	const int nz = 100;
	char C[nz];
	cout << "Массив С:" << endl;
	myrnd(C, nz, 'a', 'z');
	myout(C, nz, 5, 3, 20);
	char *q;
	q = C;
	//C=q; ошибка
	q = &C[42];
	cout << "C[64..79]:";
	myout(&C[64], 16, 1, 2, 1);
	}
	cout << endl;
	{cout << "===Задание 8========" << endl;
	cout << "Исходная строка:" << endl;
	char A[] = "Оценки группы №  за        сессию     /     учебного года:";
	char B[] = "123456789";
	char D[] = "зимнюю летнюю";
	char E[] = "2017 2018 2019 2020";
	cout << A<< endl;
	fun1(B, 1, A, 5, 15);
	fun1(D, 6, A, 0, 20);
	//cout << A << endl;
	fun1(E, 4, A, 5, 34);
	fun1(E, 4, A, 10, 39);
	cout << A << endl;
	}

	cout << endl;
	{cout << "====Задание 9=========" << endl;
	const int nrows = 6, ncols = 6;
	int M[nrows][ncols];

	myrnd(&M[0][0], ncols*nrows, 0, 19);
	cout << "До упорядочивания:" << endl;
	myout(M[0], ncols*nrows, nrows);
	int s = 0;
	for (int i = 0; i < nrows; i++) {
		if (s % 2)
			myord(&M[i][0], 6, 1);
		else
			myord(&M[i][0], 6, 0);
		s++;
	}
	cout << "После упорядочивания:" << endl;
		myout(M[0], ncols*nrows, 6);
	}
	cout << endl;
	{cout << "====Задание 10=========" << endl;
	cout << "Исходный массив: " << endl;
	const int nrows = 6, ncols = 6;
	int M[nrows][ncols];
	int A[nrows],H[ncols/2];
	myrnd(M[0], ncols*nrows, 0, 99);
	myout(M[0], ncols*nrows, nrows);
	cout << endl;
	cout << "Максимумы в первой строке: " << endl;
	for (int i = 0; i < ncols; i++) {
		for (int j = 0; j < ncols; j++)
			A[j] = M[j][i];
		myord(A, nrows / 2, true);
		for (int p = 0; p < nrows / 2; p++) H[p] = A[nrows / 2 + p];
		myord(H, nrows / 2, false);
		for (int k = nrows / 2; k < nrows; k++) A[k] = H[k - nrows / 2];
		for (int l = 0; l < nrows; l++) M[l][i] = A[l];
	}
	myout(*M, ncols*nrows, 6, 4);
	}
	cout << endl;
	{cout << "====Задание 11=========" << endl;
	float nd=5;
	float *D = new float[nd];
	if (!D) {
		cout << "Массив не может быть создан!" << endl;
		
	}
	cout << "Введите размер динамического массива: "<<nd << endl;
	cout << "Адреса элементов динамического массива: " << endl;
	for (int i = 0; i < nd; i++) {
		cout << "Адрес элемента D[" << i << "] = " << D + i << endl;
	}
	delete[]D;
	cout << "Память, выделенная динамическому массиву, освобождена." << endl;
	}
	cout << endl;
	{cout << "====Задание 12=========" << endl;
	const int nc=10;
	int C[nc];
	myrnd(C, nc, 0, 99);
	cout << "Массив С: ";
	myout(C, nc);
	fun12a(C);
	int nd = 15;
	int *D = new int[nd];
	cout << endl;
	cout << "Введите размер динамического массива: " << nd << endl;
	myrnd(D, nd, 0, 99);
	cout << "Массив D: ";
	myout(D, nd);
	fun12a(D);
	cout << endl;
	cout << "После изменения функции: "<<endl;
	fun12b(C,nc);
	fun12b(D, nd);
	}
	cout << endl;
	{cout << "====Задание 13=========" << endl;
	int nx = 10, s1=0, s2=0, s3=0;
	int *X = new int[nx];
	cout << "Массив Х: ";
	myrnd(X, nx, -99, 99);
	myout(X, nx);
	for (int i = 0; i < nx; i++) {
		s1 += X[i];	
	}
	cout << "s1 = " << s1 << endl;
	for (int i = 0; i < nx; i++) {
		s2 += *(X + i);
	}
	cout << "s2 = " << s2 << endl;
	for (int *p = X, *end = X + nx; p < end; p++) {
		s3 += *p;
	}
	cout << "s3 = "<<s3 << endl;
	cout << "Номера элементов >10:";
	for (int *p = X, *end = X + nx, i = 0; p < end; p++, i++)
		if (*p > 10) cout << setw(3) << i + 1;
	cout << endl;
	}
	cout << endl;
	{cout << "====Задание 14=========" << endl;
	int nm = 25;
	int *Mx = new int[nm];
	int *My = new int[nm];
	cout << "Размер множества М = " << nm << endl;
	myrnd(Mx, nm, -90, 90);
	myrnd(My, nm, -90, 90);
	cout << "Точки множества М:";
	}



system("pause"); 
return 0;
}
void srt1(int x, int y, int z) {
	int n;
	if (x > y) {
		n = y;
		y = x;
		x = n;
	}
	if (x > z) {
		n = z;
		z = x;
		x = n;
	}
	if (y > z) {
		
		n = z;
		z = y;
		y = n;
	}
	
}
void srt2(int &x, int &y, int &z) {
	int n;
	if (x > y) {
		n = y;
		y = x;
		x = n;
	}
	if (x > z) {
		n = z;
		z = x;
		x = n;
	}
	if (y > z) {

		n = z;
		z = y;
		y = n;
	}

}
void norm(float&x, float&y) {
	float x1, y1, a;
	a = sqrt(x*x + y*y);
	x1 = x / a;
	y1 = y / a;
	x = x1;
	y = y1;
}
void fun1(char X[], int size, char B[], int n, int a) {
	for (int i = n; i < size + n; i++)
		B[i+a-n] = X[i];
}
int fun12a(int X[]) {
	int n = sizeof(X) / sizeof(X[0]);
	cout << "Массив содержит " << n;
	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < X[i]) max = X[i];
	
	cout << " элемент. Максимум = " << max << endl;
	return max;
}
int fun12b(int X[], int n) {
	cout << "Массив содержит " << n;
	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < X[i]) max = X[i];

	cout << " элемент. Максимум = " << max << endl;
	return max;
}