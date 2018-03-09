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
  int quantityValue;
  char quantityUnit[N];
  float priceValue;
  char priceUnit[20];
  struct product *next;
};

typedef struct product product;

product * create();

// insert a node to the list
int insertProduct(product ** head, product * node);

// remove a node from list
void rmItem(product * l, product * node);

// show list
void showList(product * head);

// load data from file if
int loadData(char inf[], product **l);

// save data to file outf
int saveData(char outf[], product * l);

// purchase product
float purchase(product *l, char product[], float q);

// check out price of product p from list 1
void checkPrice(product *l, char product[]);

// find a product p from list l
void find(product *l, char product[]);

// the job starts here, shart with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt();

void userChoice(int choice, product ** l);

void menu();

#endif //OPERATIONS_H
