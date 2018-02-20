#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define N 20

struct product{
  char name[N];
  float quantity_value;
  char quantity_unit[N];
  float price_value;
  char price_unit[N];
  struct product *next;
};

// insert a node to the list
int insert(product **l, product node);

// remove a node from list
void rmItem(product *l, product *node);

// show list
void showList(product *l);

// load data from file if
int loadData(char inf[], product **l);

// save data to file outf
float purchase(product *l, char product[], float q);

// check out price of product p from list 1
void check_price(product *l, char p[]);

// find a product p from list l
void findItem(product *l, char p[]);

// the job starts here, shart with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt(char data[]);

#endif //OPERATIONS_H
