#include <iostream>
#include <iomanip>
#include "myfunctions.h"
using namespace std;

//=== dec2bin ====================================================
void dec2bin(int n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(short n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(char n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(long long n, int b1, int b2, int b3, int b4, int b5, int b6, int b7) {
	const int nd = sizeof(n) * 8; unsigned long long m = n, k = 1;
	for (int i = nd - 1; i >= 0; i--) {
		cout << (m&(k << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 || i == b4 || i == b5 || i == b6 || i == b7 ? " " : "");
	}
}
//=== myout ====================================================
void myout(int *X, int nx, int nr, int nw) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << setw(nw) << X[i]; if ((i + 1) % nc == 0) cout << endl;
	}
}
void myout(short *X, int nx, int nr, int nw) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << setw(nw) << X[i]; if ((i + 1) % nc == 0) cout << endl;
	}
}
void myout(char *X, int nx, int nr, int nw, bool asChar) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	if (asChar) for (int i = 0; i<nx; i++) cout << setw(nw) << X[i] << ((i + 1) % nc ? "" : "\n");
	else       for (int i = 0; i<nx; i++) cout << setw(nw) << X[i] + 0 << ((i + 1) % nc ? "" : "\n");
}
void myout(double *X, int nx, int nr, int nw, int nf) {
	ios init(NULL); init.copyfmt(cout); //сохраняем текущий формат cout
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << fixed << setw(nw) << setprecision(nf) << X[i];
		if ((i + 1) % nc == 0) cout << endl;
	}
	cout.copyfmt(init); //восстанавливаем текущий формат cout
}
//=== myrnd ====================================================
void myrnd(int *X, const int nx, int n0, int n1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (n1 - n0 + 1) + n0;
}
void myrnd(short *X, const int nx, int n0, int n1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (n1 - n0 + 1) + n0;
}
void myrnd(char *X, const int nx, char c0, char c1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (c1 - c0 + 1) + c0;
}
void myrnd(double *X, const int nx, double n0, double n1, int nf) {
	double p = pow(10, nf);
	for (int i = 0; i<nx; i++) X[i] = (rand() % (int)(n1 - n0 + 1) + n0) / p;
}
//=== myord, ... =================================================
int mytransp(int *X, int nx, bool inc) {
	int n = 0, t;
	if (inc)
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]>X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	else
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]<X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	return n;
}
void mysel(int *X, int nx, bool inc) {
	int mx = X[0], imx = 0;
	if (inc) for (int i = 1; i<nx; i++) { if (X[i]>mx) { mx = X[i]; imx = i; } }
	else  for (int i = 1; i<nx; i++) { if (X[i]<mx) { mx = X[i]; imx = i; } }
	if (imx != nx - 1) { int t = X[imx]; X[imx] = X[nx - 1]; X[nx - 1] = t; }
}
void myins(int *X, int nx, bool inc, int newval) {
	int i;
	if (inc) for (i = nx - 1; i >= 0 && X[i]>newval; i--) X[i + 1] = X[i];
	else  for (i = nx - 1; i >= 0 && X[i]<newval; i--) X[i + 1] = X[i];
	X[i + 1] = newval;
}
void myord(int *X, int nx, bool inc, char meth) {
	if (meth == 't') for (int i = nx; i>1 && mytransp(X, i, inc); i--);
	else if (meth == 's') for (int i = nx; i>1; i--) mysel(X, i, inc);
	else if (meth == 'i') for (int i = 1; i<nx; i++) myins(X, i, inc, X[i]);
}
//--- перегрузка дл¤ double -----
int mytransp(double *X, int nx, bool inc) {
	int n = 0; double t;
	if (inc)
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]>X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	else
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]<X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	return n;
}
void mysel(double *X, int nx, bool inc) {
	int  imx = 0; double mx = X[0];
	if (inc) for (int i = 1; i<nx; i++) { if (X[i]>mx) { mx = X[i]; imx = i; } }
	else  for (int i = 1; i<nx; i++) { if (X[i]<mx) { mx = X[i]; imx = i; } }
	if (imx != nx - 1) { int t = X[imx]; X[imx] = X[nx - 1]; X[nx - 1] = t; }
}
void myins(double *X, int nx, bool inc, double newval) {
	int i;
	if (inc) for (i = nx - 1; i >= 0 && X[i]>newval; i--) X[i + 1] = X[i];
	else  for (i = nx - 1; i >= 0 && X[i]<newval; i--) X[i + 1] = X[i];
	X[i + 1] = newval;
}
void myord(double *X, int nx, bool inc, char meth) {
	if (meth == 't') for (int i = nx; i>1 && mytransp(X, i, inc); i--);
	else if (meth == 's') for (int i = nx; i>1; i--) mysel(X, i, inc);
	else if (meth == 'i') for (int i = 1; i<nx; i++) myins(X, i, inc, X[i]);
}