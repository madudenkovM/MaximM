#include <fstream>
#include <iostream>
using namespace std;

void NV(int n, int mass[20][20])
{
ifstream fin("input.txt");
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		fin >> mass[i][j];
	}
}
}
void S1(int n, int mass[20][20])
{
ofstream fout("output.txt");
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		fout << mass[i][j] << "\t";
	}
	fout << endl;
}
fout << endl;
}
bool TS(int x)
{
if (x == 2 || x == 3)
{
	return true;
}
if (x == 1)
{
	return false;
}
for (int i = 2; i < sqrt(x); i++)
{
	if (x % i == 0)
	{
		return false;
	}
	return true;
}
}
bool B1(int n, int mass[20][20])
{
bool flag = false;
int stroke_sum = 0;
int index = 0;
for (int i = 0; i < n; i++)
{
	flag = false;
	stroke_sum = 0;
	for (int j = 0; j < n; j++)
	{
		stroke_sum += mass[i][j];
		if (TS(mass[i][j]) == true)
		{
			flag = true;
		}
	}
	if (stroke_sum == 0 && flag == true)
	{
		return true;
	}
}
}
void EL(int n, int mass[20][20])
{
for (int i = 0; i < n; i++)
{
	int stolb_sum1 = 0;
	int stolb_sum2 = 0;
	for (int j = 0; j < n; j++)
	{
		stolb_sum1 += abs(mass[j][i]);
		stolb_sum2 += abs(mass[j][i + 1]);
	}
	if (stolb_sum1 < stolb_sum2)
	{
		for (int j = 0; j < n; j++)
		{
			swap(mass[j][i], mass[j][i + 1]);
		}
	}
}
}

int main()
{
int n;
cin >> n;
int m[20][20];
NV(n, m);
if (B1(n, m) == true)
{
	EL(n, m);
}
S1(n, m);
}