#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DosarPenal{
	int nrDosar;
	char* numeInculpat;
} dp;

typedef struct NodSimplu {
	dp info;
	struct NodSimplu* next;
}NS;

NS* creareNod(dp info) {
	NS* nodNou = (NS*)malloc(sizeof(NS));
	nodNou->next = NULL;
	nodNou->info.nrDosar = info.nrDosar;
	nodNou->info.numeInculpat = (char*)malloc(strlen(info.numeInculpat) + 1);
	strcpy(nodNou->info.numeInculpat, info.numeInculpat);
	return nodNou;
}

void inserareLaInceput(NS** cap, dp info) {
	NS* nn = creareNod(info);
	if (*cap == NULL) {
		*cap = nn;
		return;
	}

	NS* temp = *cap;

	
	nn->next = *cap;
	*cap = nn;

}

void inserareLaSfarsit(NS** cap, dp info) {
	NS* nn = creareNod(info);
	if (*cap == NULL) {
		*cap = nn;
		return;
	}

	NS* temp = *cap;

	while (temp->next != NULL) { temp = temp->next; }

	temp->next = nn;

}

void afisareLista(NS* cap) {
	if (cap == NULL) {
		printf("Lista e goala");
		return;
	}

	NS* temp = cap;

	while (temp != NULL) {
		printf("bla %d, bla %s", temp->info.nrDosar, temp->info.numeInculpat);
		temp = temp->next;
	}

}

void stergereLista(NS** cap) {
	if (*cap == NULL) {
		printf("Lista e goala");
		return;
	}

	NS* temp = *cap;
	NS* urm = NULL;
	while (temp != NULL) {
		urm = temp->next;
		free(temp->info.numeInculpat);
		free(temp);
		temp = urm;
	}

}