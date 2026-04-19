#define _CRT_SECURE_NO_WARNIGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct DosarPenal {
	int nrDosar;
	char* numeInculpat;
} dp;

typedef struct NodDublu {
	dp info;
	struct NodDublu* prev;
	struct NodDublu* next;
}ND;

ND* creareNod(dp info) {
	ND* nn = (ND*)malloc(sizeof(ND));
	nn->info.nrDosar = info.nrDosar;
	nn->info.numeInculpat = (char*)malloc(strlen(info.numeInculpat) + 1);
	strcpy(nn->info.numeInculpat, info.numeInculpat);
	nn->prev = NULL;
	nn->next = NULL;
	return nn;
}

void inserareLaInceput(ND** cap, dp info) {

	ND* nn = creareNod(info);
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

void afisareLista(ND* cap) {
	
	if (cap == NULL) {
		printf("Lista goala");
		return;
	}

	ND* temp = cap;
	while (temp != NULL) {
		printf("In dosarul %d, inculpat este %s", temp->info.nrDosar, temp->info.numeInculpat);
		temp = temp->next;
	}
}

void afisareListaInvers(ND* cap) {
	if (cap == NULL) {
		printf("Lista goala");
		return;
	}
	ND* temp = cap;
	ND* tempInvers = NULL;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	tempInvers = temp;

	while (tempInvers!=NULL){
		printf("In dosarul %d, inculpat este %s", tempInvers->info.nrDosar, tempInvers->info.numeInculpat);
		tempInvers = tempInvers->prev;
	}
}

void stergereLista(ND** cap) {
	if (*cap == NULL) {
		printf("Lista goala");
		return;
	}

	ND* temp = *cap;
	ND* aux = NULL;

	while (temp != NULL) {
		aux = temp->next;
		free(temp->info.numeInculpat);
		free(temp);
		temp = aux;
	}
	*cap = NULL;
}

int main() {
	FILE* f = fopen("res.txt", "r");
	if (f == NULL) {
		printf("Nu s a deschis fisierul!");
		return;
	}




	
	return 0;
}