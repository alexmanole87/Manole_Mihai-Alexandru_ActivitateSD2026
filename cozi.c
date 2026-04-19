#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dosar {
	int numar;
	char* nume;
} Ds;


typedef struct NodSimplu {
	Ds data;
	struct NodSimplu* next;
}NS;

typedef struct Coada {
	NS* front;
	NS* rear;
}c;

Ds creeareDosar(int numar, const char* nume) {
	Ds d;
	d.numar = numar;
	d.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(d.nume, nume);
	return d;
}

NS* creareNod(Ds ds){
	NS* nou = (NS*)malloc(sizeof(NS));
	nou->data = creeareDosar(ds.numar, ds.nume);
	nou->next=NULL;
	return nou;
}

void enque(c* c, Ds ds) {
	NS* nou = creareNod(ds);

	if (c->rear == NULL) {
		c->front = c->rear = nou;
	}

	c->rear->next = nou;
	c->rear = nou;

}


Ds deque(c* c) {
	if (c->rear == NULL) { return; }

	NS* temp = c->front;
	Ds rezultat = temp->data;

	c->front = temp->next;

	if (c->front == NULL) { c->rear = NULL; }

	free(temp);
	return rezultat;
}

void dequeAndDelete(c* c) {
	Ds d = deque(c);
	free(d.nume);
}
