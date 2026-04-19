#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	nn->prev = NULL;
	nn->next = NULL;
	return nn;
}

void adaugareLaInceput(ND** cap, dp info) {
	ND* nn = creareNod(info);
	
	if (nn==NULL){
		printf("Eroare nod");
		return;
	}

	if (*cap == NULL) {
		*cap = nn;
	}

	nn->next = *cap;
	(*cap)->prev = nn;
	*cap = nn;
}

void adaugareLaSfarsit(ND** cap, dp info) {
	ND* nn = creareNod(info);

	if (nn == NULL) {
		printf("Eroare nod");
		return;
	}

	if (*cap == NULL) {
		*cap = nn;
		return;
	}

	ND* aux = *cap;

	while (aux->next != NULL) {
		aux = aux->next;
	}

	aux->next = nn;
	nn->prev = aux;

}

void afisare(ND* cap) {
	if (cap == NULL) {
		printf("Lista e goala");
	}

	while (cap != NULL) {
		printf("Dosarul nr %d, are ca inculpat pe %s.\n", cap->info.numar, cap->info.nume);
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
		printf("Dosarul nr %d, are ca inculpat pe %s.\n", cap->info.numar, cap->info.nume);
		cap = cap->prev;
	}

}


void stergere(ND** cap) {
	if (*cap == NULL) {
		printf("Lista e goala");
		return;
	}

	ND* temp = *cap;
	ND* aux = NULL;
	
	while (temp!= NULL) {
		aux = temp->next;
		free(temp->info.nume);
		free(temp);
		temp = aux;
	}

	*cap = NULL;

}

int main() {
	FILE* f = fopen("dosare.txt", "r");
	if (f == NULL) { 
		printf("Eroare dosar"); 
		return 2; }
	int n;
	char buffer[100];
	dp info;
	ND* cap = NULL;


	fscanf(f, "%d", &n);


	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %s", &info.numar, buffer);

		info.nume = (char*)malloc(strlen(buffer) + 1);
		strcpy(info.nume, buffer);
		adaugareLaSfarsit(&cap, info);
		free(info.nume);
	}

	fclose(f);
	afisare(cap);
	printf("---------------");
	afisareDeLaSfarsit(cap);
	stergere(&cap);
	afisare(cap);
	
	return 0;
	
}