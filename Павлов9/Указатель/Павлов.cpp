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
	{cout << "===������� 1========"<<endl; 
	int n;
	int *p = &n;
	*p = 12;
	cout << "2) �������� n = " << n << ", ����� n = " << &n<<endl;
	cout << "3) �������� n = " << *p << ", ����� n = " << p << endl;
	cout << "4) ����� p = " << &p<<endl;
	}
	cout << endl;
	{cout << "===������� 2========" << endl;
	double f1 = 0.7; int n1 = 171; char c1 = 'A';
	double *F1, *F2; int *N1, *N2; char *C1, *C2;
	/*double *F3 = -47.5;//������������� ��������� ���������� ���������
	int *N3 = &c1; //������������� ��������� ������� ������� ����
	F1 = F2;
	N2 = 0x0016D2B8;//������������ ��������� ������ ������� ����
	C1 = &f1;//������������ ��������� ������ ������� ����
	F2 = N1;//� ������������ ������������ ��������� ������ �����
	C2 = c1;//������������ ��������� ����������� ��������*/
	}
	cout << endl;
	{cout << "===������� 3========" << endl; 
	double d;
	cout << "d = "<<(d= 629672911.29160953) << endl;
	char *p;
	p = (char*)&d + 6;
	cout << "���� �6 = ";
	dec2bin(*p);
	}
	cout << endl;
	{cout << "===������� 4a========" << endl;
	int a = 3, b = 2, c = 1;
	cout << "���� ��������� ������: " << a << " " << b << " " << c << endl;
	srt1(a, b, c);
	cout << "��������� ����������: " << a << " " << b << " " << c << endl;
	}
	{cout << "===������� 4b========" << endl;
	int a = 6, b = 5, c = 4;
	cout << "���� ��������� ������: " << a << " " << b << " " << c << endl;
	srt2(a, b, c);
	cout << "��������� ����������: " << a << " " << b << " " << c << endl;
	}
	cout << endl;
	{cout << "====������� 5====" << endl;
	float x = 8, y = 17;
	cout << "�������� ������:        (" << x << ", " << y <<")"<< endl;
	norm(x, y);
	cout << "��������������� ������: (" << x << ", " << y << ")" << endl;
	}
	cout << endl;
	{cout << "===������� 6======" << endl;
	double *q, *p;
	p = new double(1.25);
	q = new double(2.75);
	if (!p) {
		cout << "\n������! ������������ ������!\n";
		system("pause");
		exit(1);
	}
	cout << "��������� p �������� ������ " << p << ", ���������� ����� " << *p<<endl;
	cout << "��������� q �������� ������ " << q << ", ���������� ����� " << *q<<endl;
	delete p, q;
	}
	cout << endl;
	{cout << "====������� 7======" << endl;
	const int nz = 100;
	char C[nz];
	cout << "������ �:" << endl;
	myrnd(C, nz, 'a', 'z');
	myout(C, nz, 5, 3, 20);
	char *q;
	q = C;
	//C=q; ������
	q = &C[42];
	cout << "C[64..79]:";
	myout(&C[64], 16, 1, 2, 1);
	}
	cout << endl;
	{cout << "===������� 8========" << endl;
	cout << "�������� ������:" << endl;
	char A[] = "������ ������ �  ��        ������     /     �������� ����:";
	char B[] = "123456789";
	char D[] = "������ ������";
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
	{cout << "====������� 9=========" << endl;
	const int nrows = 6, ncols = 6;
	int M[nrows][ncols];

	myrnd(&M[0][0], ncols*nrows, 0, 19);
	cout << "�� ��������������:" << endl;
	myout(M[0], ncols*nrows, nrows);
	int s = 0;
	for (int i = 0; i < nrows; i++) {
		if (s % 2)
			myord(&M[i][0], 6, 1);
		else
			myord(&M[i][0], 6, 0);
		s++;
	}
	cout << "����� ��������������:" << endl;
		myout(M[0], ncols*nrows, 6);
	}
	cout << endl;
	{cout << "====������� 10=========" << endl;
	cout << "�������� ������: " << endl;
	const int nrows = 6, ncols = 6;
	int M[nrows][ncols];
	int A[nrows],H[ncols/2];
	myrnd(M[0], ncols*nrows, 0, 99);
	myout(M[0], ncols*nrows, nrows);
	cout << endl;
	cout << "��������� � ������ ������: " << endl;
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
	{cout << "====������� 11=========" << endl;
	float nd=5;
	float *D = new float[nd];
	if (!D) {
		cout << "������ �� ����� ���� ������!" << endl;
		
	}
	cout << "������� ������ ������������� �������: "<<nd << endl;
	cout << "������ ��������� ������������� �������: " << endl;
	for (int i = 0; i < nd; i++) {
		cout << "����� �������� D[" << i << "] = " << D + i << endl;
	}
	delete[]D;
	cout << "������, ���������� ������������� �������, �����������." << endl;
	}
	cout << endl;
	{cout << "====������� 12=========" << endl;
	const int nc=10;
	int C[nc];
	myrnd(C, nc, 0, 99);
	cout << "������ �: ";
	myout(C, nc);
	fun12a(C);
	int nd = 15;
	int *D = new int[nd];
	cout << endl;
	cout << "������� ������ ������������� �������: " << nd << endl;
	myrnd(D, nd, 0, 99);
	cout << "������ D: ";
	myout(D, nd);
	fun12a(D);
	cout << endl;
	cout << "����� ��������� �������: "<<endl;
	fun12b(C,nc);
	fun12b(D, nd);
	}
	cout << endl;
	{cout << "====������� 13=========" << endl;
	int nx = 10, s1=0, s2=0, s3=0;
	int *X = new int[nx];
	cout << "������ �: ";
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
	cout << "������ ��������� >10:";
	for (int *p = X, *end = X + nx, i = 0; p < end; p++, i++)
		if (*p > 10) cout << setw(3) << i + 1;
	cout << endl;
	}
	cout << endl;
	{cout << "====������� 14=========" << endl;
	int nm = 25;
	int *Mx = new int[nm];
	int *My = new int[nm];
	cout << "������ ��������� � = " << nm << endl;
	myrnd(Mx, nm, -90, 90);
	myrnd(My, nm, -90, 90);
	cout << "����� ��������� �:";
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
	cout << "������ �������� " << n;
	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < X[i]) max = X[i];
	
	cout << " �������. �������� = " << max << endl;
	return max;
}
int fun12b(int X[], int n) {
	cout << "������ �������� " << n;
	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < X[i]) max = X[i];

	cout << " �������. �������� = " << max << endl;
	return max;
}