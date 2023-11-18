#include <fstream>
using namespace std;
int lgmax;
void citesteDateleDeIntrare();
void afiseazaDateleDeIesire();
int main()
{
	citesteDateleDeIntrare();
	afiseazaDateleDeIesire();
	return 0;
}
int celMaiMareDivizorComun(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void citesteDateleDeIntrare()
{
	ifstream fin("cmmdcsecv.in");
	int n, cmmdc, lg, i, x;
	fin >> n;
	cmmdc = 1;
	for (lg = i = 0; i < n; i++)
	{
		fin >> x;
		cmmdc = celMaiMareDivizorComun(cmmdc, x);
		if (cmmdc > 1)
			lg++;
		else
		{
			if (lg > lgmax)
				lgmax = lg;
			lg = 1;
			cmmdc = x;
		}
	}
	if (lg > lgmax)
		lgmax = lg;
	fin.close();
}
void afiseazaDateleDeIesire()
{
	ofstream fout("cmmdcsecv.out");
	fout << lgmax;
	fout.close();
}
