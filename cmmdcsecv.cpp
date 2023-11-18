#include <fstream>
#define MAX_N 100000
#define MAX_NR_PRIME 200
using namespace std;
int a[MAX_N], prim[MAX_NR_PRIME];
int n, vmax, nrPrime, lgmax;
void citesteDateleDeIntrare();
void determinaNumerelePrimeMaiMiciDecat(int nrMax);
void calculeazaLungimeaMaxima();
void afiseazaDateleDeIesire();
int main()
{
	citesteDateleDeIntrare();
	determinaNumerelePrimeMaiMiciDecat(vmax+1);
	calculeazaLungimeaMaxima();
	afiseazaDateleDeIesire();
	return 0;
}
void calculeazaLungimeaMaxima()
{
	int i, j, lg;
	for (i = 0; i < nrPrime; i++)
	{
		for (lg = j = 0; j < n; j++)
			if (a[j] % prim[i] == 0)
				lg++;
			else
			{
				if (lg > lgmax)
					lgmax = lg;
				lg = 0;
			}
		if (lg > lgmax)
			lgmax = lg;
	}
}
void determinaNumerelePrimeMaiMiciDecat(int nrMax)
{
	int ciur[nrMax], i, j;
	for (i = 0; i < nrMax; i++) ciur[i] = 0;
	ciur[0] = ciur[1] = 1;
	for (i = 2; i*i < nrMax; i++)
		if (ciur[i] == 0)
			for (j = i*i; j < nrMax; j += i)
				ciur[j] = 1;
	for (i = 2; i < nrMax; i++)
		if (ciur[i] == 0)
			prim[nrPrime++] = i;
}
void citesteDateleDeIntrare()
{
	ifstream fin("cmmdcsecv.in");
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		if (a[i] > vmax)
			vmax = a[i];
	}
	fin.close();
}
void afiseazaDateleDeIesire()
{
	ofstream fout("cmmdcsecv.out");
	fout << lgmax;
	fout.close();
}
