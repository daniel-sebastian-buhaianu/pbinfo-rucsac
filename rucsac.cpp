#include <iostream>
#include <algorithm>

#define NMAX 1000

using namespace std;

struct Obiect
{
	int greutate, valoare;
};

bool raport_descrescator(Obiect a, Obiect b)
{
	return a.valoare*b.greutate > b.valoare*a.greutate;
}

int main()
{
	int n, gmax, i, gasit;
	float cmax;
	Obiect obiect[NMAX];

	cin >> n >> gmax;

	for (i = 0; i < n; i++)
	{
		cin >> obiect[i].greutate >> obiect[i].valoare;
	}

	sort(obiect, obiect+n, raport_descrescator);

	for (cmax = gasit = i = 0; i < n && !gasit; i++)
	{
		if (obiect[i].greutate <= gmax)
		{
			cmax += obiect[i].valoare;
			gmax -= obiect[i].greutate;
		}
		else
		{
			cmax = cmax + (float)gmax*obiect[i].valoare/obiect[i].greutate;
			gmax = 0;
		}

		if (gmax == 0)
		{
			gasit = 1;
		}
	}

	cout << cmax;

	return 0;
}
// scor 100
