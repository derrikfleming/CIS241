#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define N 20

struct product {
  char name[20];
  float quantityValue;
  char quantityUnit[N];
  float priceValue;
  char priceUnit[20];
  struct product *next;
};

struct product * create(char * name, float quantityValue, char * quantityUnit, int priceValue, char * priceUnit, struct product * next);

// insert a node to the list
struct product * insertProduct(char * name, float quantityValue, char * quantityUnit, int priceValue, char * priceUnit, struct product * head);

// remove a node from list
void rmItem();

// show list
void showList(struct product *l);

// load data from file if
int loadData(char inf[], struct product **l);

// save data to file outf
float purchase(struct product *l, char name[], float q);

// check out price of product p from list 1
void checkPrice(struct product *l, char p[]);

// find a product p from list l
void find(struct product *l, char p[]);

// the job starts here, shart with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt(char data[]);

int choice(int choice);

void printMenu();

#endif //OPERATIONS_H
