#include "operations.h"

struct product * create(char * name, float quantityValue, char * quantityUnit, int priceValue, char * priceUnit, struct product * next){
  struct product* newNode = (struct product*)malloc(sizeof(struct product));

  // add values to newNode
  if(newNode != NULL){
    strcpy(newNode->name, name);
    newNode->quantityValue = quantityValue;
    strcpy(newNode->quantityUnit, quantityUnit);
    newNode->priceValue = priceValue;
    strcpy(newNode->priceUnit, priceUnit);
    newNode->next = next;
  }
  else{
    printf("Node creation error! Memory could not be allocated.");
  }

  return newNode;
}

// insert a node to the list
struct product * insertProduct(char * name, float quantityValue, char * quantityUnit, int priceValue, char * priceUnit, struct product * head){
  //newNode created, newnode->next is set to current head
  struct product * newNode = create(name, quantityValue, quantityUnit, priceValue, priceUnit, head);
  //set head to newNode
  head = newNode;

  return head;
}

// remove a node from list
void rmItem(){

}

// show list
void showList(struct product *l){

}

int saveData(){

}

// load data from file if
int loadData(char inf[], struct product **l){

}


float purchase(struct product *l, char name[], float q){

}

// check out price of product p from list 1
void checkPrice(struct product *l, char p[]){

}

// find a product p from list l
void find(struct product *l, char p[]){

}

// the job starts here, start with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt(char data[]){

}

void printMenu(){
  printf("Welcome to Derrik Fleming's Grocery Store\n");
  printf("Please let me know what you what you want to do by typing one of the numbers\n");
  printf("============================================================================\n");
  printf("0: Add product to store                  1: Purchase product from store\n");
  printf("2: Check price of a product              3: Show products in store\n");
  printf("4: Remove a product from a store         5: Find product\n");
  printf("6: Inventory                             7: Done for today\n");
  printf("What do you want to do?\n\n");
}

int save(struct product *l, struct product * head){

  if(head != NULL){

  }
  else{

  }
}

int open(){

}

int choice(int choice){
  switch(choice){
    case 0:

      insert();
      break;

    case 1:
      printf("Enter item name: ");
      break;

    case 2:
      printf("Enter item name: ");
      break;

    case 3:
      break;

    case 4:
      printf("Enter item name: ");
      break;

    case 5:
      printf("Enter item name: ");
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;
  }
}
