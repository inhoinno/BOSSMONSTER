
#ifndef _POLY_
#define _POLY_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define _UNIT 0.001
/*32152332 송인호 32152332@dankook.ac.kr*/
void boot_poly();
void printfile(double, double);
double calc(struct List *, double x);
struct List * myList();
struct Term * make_node(double c, int degree);
#define MIN_X -10;
#define MAX_X 10;
double func_MIN_x(struct List *, int, int);

double ** func_zero_find_x(struct List *);
void realloc_mat(int*, double ***);
bool meet_zero(double, double);


void addTerm_First(struct List* List, double c, int d);
void addTerm_Last(struct List *, double, int);
void rmAll(struct List * L);
void rm(struct Term * t);
void showList(struct List * L);
int isEmpty(struct List * L);
typedef struct List {
	struct Term * head;
	int count;
}List;
typedef struct Term{
	int cha; //차수, expon
	double gge; //계수, 
	struct Term * next;
}Term;
#endif