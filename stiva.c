#define _CRT_NO_SECURE_WARNING
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Dosar {
	int numar;
	char* nume;
} Ds;

typedef struct Nod {
	Ds data;
	struct Nod* next;
} NS;

NS* creeareNod(Ds ds) {
	NS* nou = (NS*)malloc(sizeof(NS));
	nou->data.numar = ds.numar;
	nou->data.nume = (char*)malloc(sizeof(ds.nume) + 1);
	strcpy(nou->data.nume, ds.nume);
	nou->next = NULL;
	return nou;
}

void push (NS** top, Ds ds){
	
	NS* nou = creeareNod(ds);

	nou->next = *top;
	*top = nou;
}

void pop(NS** top) {
	if (*top == NULL) { exit(1); }

	NS* temp = *top;

	Ds rez = temp->data;

	*top = temp->next;

	//free(temp->data.nume);
	free(temp);

	return rez;
}