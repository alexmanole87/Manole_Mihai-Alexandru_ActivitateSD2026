#define _CRT_SECURE_NO_WARNINGS
#include  <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct DosarPenal {
	int numar;
	char* nume;

}dp;

typedef struct NodDublu {
	dp info;
	struct NodDublu* next;
	struct NodDublu* prev;
}ND;

ND* creareNod(dp info) {
	ND* nn = (ND*)malloc(sizeof(ND));
	nn->info.numar = info.numar;
	nn->info.nume = (char*)malloc(strlen(info.nume) + 1);
	strcpy(nn->info.nume, info.nume);
	nn->next = NULL;
	nn->prev = NULL;
	return nn;
}

void inserareLaInceput(ND** cap, dp info) {
	ND* nn = creareNod(info);
	if (nn == NULL) { return; }
	if (*cap == NULL) {
		*cap = nn;
		return;
	}
	nn->next = *cap;
	(*cap)->prev = nn;
	*cap = nn;
}

void inserareLaSfarsit(ND** cap, dp info) {
	ND* nn = creareNod(info);
	if (nn == NULL) { return; }
	if (*cap == NULL) {
		*cap = nn;
		return;
	}

	ND* temp = *cap;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = nn;
	nn->prev = temp;

}

void afisare(ND* cap) {
	if (cap == NULL) {
		printf("Lista e goala");
		return;
	}
	
	while (cap != NULL) {
		printf("Dosarul nr %d, are ca inculpat pe %s\n", cap->info.numar, cap->info.nume);
		cap = cap->next;
	}

}

void afisareDeLaSfarsit(ND* cap) {
	if (cap == NULL) {
		printf("Lista e goala");
		return;
	}

	while (cap->next != NULL) {
		cap = cap->next;
	}

	while (cap != NULL) {
		printf("Dosarul nr %d, are ca inculpat pe %s\n", cap->info.numar, cap->info.nume);
		cap = cap->prev;
	}

}

void stergere(ND** cap) {
	if (*cap == NULL) {
		printf("Lista e goala");
		return;
	}

	ND* temp = *cap;

	while (*cap != NULL) {
		temp = (*cap)->next;
		free((*cap)->info.nume);
		free(*cap);
		*cap = temp;
	}

	*cap = NULL;
}

int nrElementLIsta(ND* cap) {
	int contor = 0;
	if (cap == NULL) {
		printf("Lista e goala");
		return;
	}

	while (cap != NULL) {
		contor++;
		cap = cap->next;
	}

	return contor;
}


dp* listaInVector(ND* cap, int* dim) {
	*dim = nrElementLIsta(cap);
	int i = 0;

	dp* vector = (dp*)malloc(sizeof(dp) * (*dim));

	while (cap != NULL) {
		
		vector[i].numar = cap->info.numar;
		vector[i].nume = (char*)malloc(strlen(cap->info.nume)+1);

		if (vector[i].nume == NULL) {
			for (int j = 0; j < i; j++) {
				free(vector[j].nume);
			}

			free(vector);
			return NULL;
		}
		
		strcpy(vector[i].nume, cap->info.nume);
		i++;
		cap = cap->next;
	}


	return vector;
}
void afisareVector(dp* vector, int dim) {

	if (vector == NULL || dim == 0) {
		printf("vector gol");
		return;
	}

	for (int i = 0; i < dim; i++) {
		printf("Dosarul nr %d, are ca inculpat pe %s\n", vector[i].numar, vector[i].nume);
	}

}

int main(){
	int n, dim;
	char buffer[100];
	ND* cap = NULL;
	dp info;
	FILE* f = fopen("dosare.txt", "r");
	if (f == NULL) {
		printf("eroare deschideere fisier");
		return 2;
	}

	fscanf(f, "%d", &n);

	printf("Numar total de dosar: %d\n", n);
	
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %s", &info.numar, buffer);
		info.nume = (char*)malloc(strlen(buffer) + 1);
		strcpy(info.nume, buffer);

		inserareLaInceput(&cap, info);

		free(info.nume);
	}


	dp* v = listaInVector(cap, &dim);

	afisare(cap);
	printf("\n---------------\n");
	afisareDeLaSfarsit(cap);
	printf("\n   VECTOR     :\n");
	afisareVector(v, dim);
	stergere(&cap);

	afisare(cap);


	fclose(f);

	return 0;


}
