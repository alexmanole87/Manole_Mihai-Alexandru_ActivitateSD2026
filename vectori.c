#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void citireVector(int v[], int* n) {
	printf("Numarul de elemente ele vevtorului: ");
	scanf("%d", n);
	for (int i = 0; i < *n; i++)
	{
		printf("Elementul %d: ", i + 1);
		scanf("%d", &v[i]);
		printf("\n");
	}
}

void afisareVector(int v[], int n) {
	for (int  i = 0; i < n; i++)
	{
		printf("%d,", v[i]);
	}

	printf("\n");

}

void stergereLaPoz(int v[], int* marimeVector) {
	int poz;
	printf("Ce pozitie doriti sã stergeti: ");
	scanf("%d", &poz);

	if (poz<0 || poz>*marimeVector - 1) { printf("Pozitie Invalida!"); return; }

	for (int i = poz; i < marimeVector-1; i++)
	{
		v[i] = v[i + 1];
	}

	(*marimeVector)--;
}

void adaugareLaPoz(int v[], int* marimeVector, int poz, int val) {
	if (poz < 0 || poz >= *marimeVector - 1) { printf("Pozitie Invalida!"); return; }
	
	for (int i = *marimeVector; i < poz; i--)
	{
		v[i] = v[i - 1];
	}

	v[poz] = val;

	(*marimeVector)++;

}

int main()
{
	int v[100], n, poz, val;
	citireVector(v, &n);
	afisareVector(v, n);
	

	stergereLaPoz(v, &n, poz);
	afisareVector(v, n);

	printf("La ce pozitie doriti sã inserati: ");
	scanf("%d", &poz);

	printf("Ce valoaree doriti sã inserati: ");
	scanf("%d", &val);

	adaugareLaPoz(v, &n, poz, val);

	afisareVector(v, n);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
