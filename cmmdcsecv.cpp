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
	int n, cmmdc, i, x, lg;
	fin >> n;
	fin >> cmmdc;
	lg = cmmdc > 1 ? 1 : 0;
	for (i = 1; i < n; i++)
	{
		fin >> x;
		cmmdc = celMaiMareDivizorComun(cmmdc, x);
		if (cmmdc > 1)
			lg++;
		else
		{
			if (lg > lgmax)
				lgmax = lg;
			lg = x > 1 ? 1 : 0;
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
