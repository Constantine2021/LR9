#pragma once

//====================================================================
//   ������������ ���� ������ ��������� ������ �6 �������� ������������
//====================================================================

//---------------------------------------------------------------------------
//����� ������ ����� n � �������� ����, bi - ����� ��������
//---------------------------------------------------------------------------
void dec2bin(int n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(short n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(char n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(long long n, int b1 = -1, int b2 = -1, int b3 = -1,
	int b4 = -1, int b5 = -1, int b6 = -1, int b7 = -1);
//---------------------------------------------------------------------------
//����� nx ��������� ������� X � nr �����, setw(nw)
//���� nr=0, ����� � ���� ������ ��� endl
//asChar ������ ����� char: true - ����� ��������, false - ����� �����
//nf - �������� ������������ setprecision
//---------------------------------------------------------------------------
void myout(int *X,const int nx, int nr = 1, int nw = 4);
void myout(short *X, const int nx, int nr = 1, int nw = 4);
void myout(char *X, const int nx, int nr = 1, int nw = 1, bool asChar = true);
void myout(double *X, const int nx, int nr = 1, int nw = 9, int nf = 3);
//---------------------------------------------------------------------------
//����������� nx ��������� ������� X ��������� ����� �� ��������� �� n0 �� n1
//---------------------------------------------------------------------------
void myrnd(int *X, const int nx, int n0, int n1);
void myrnd(short *X, const int nx, int n0, int n1);
void myrnd(char *X, const int nx, char c0, char c1);
//�������� �� n0/10^nf �� n1/10^nf
void myrnd(double *X, const int nx, double n0, double n1, int nf = 2);
//---------------------------------------------------------------------------
//myord ��������� nx ��������� ������� X 
//inc: true - ���������� �� �����������, false - ���������� �� ��������
//meth: 't' - ����� ������������, 's' - ����� ������, 'i' - ����� �������
//---------------------------------------------------------------------------
int mytransp(int *X, int nx, bool inc = true);
void mysel(int *X, int nx, bool inc = true);
void myins(int *X, int nx, bool inc = true, int newval = 0);
void myord(int *X, int nx, bool inc = true, char meth = 't');
//���������� ��� double-�������  
int mytransp(double *X, int nx, bool inc = true);
void mysel(double *X, int nx, bool inc = true);
void myins(double *X, int nx, bool inc = true, double newval = 0);
void myord(double *X, int nx, bool inc = true, char meth = 't');

