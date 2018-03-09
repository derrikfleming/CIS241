#include "operations.h"

product * create(){
  product * node = (product*)malloc(sizeof(product));

  // add values to newNode
  if(node != NULL){
    char buf[N];

    printf("\n\nProduct name: ");
    scanf("%s", buf);
    strcpy(node->name, buf);

    printf("Product quantity: ");
    scanf("%i", &(node->quantityValue));

    printf("Product quantity unit: ");
    scanf("%s", buf);
    strcpy(node->quantityUnit, buf);

    printf("Product price: ");
    scanf("%f", &(node->priceValue));

    printf("Product price unit: ");
    scanf("%s", buf);
    strcpy(node->priceUnit, buf);

    node->next = NULL;
  }
  else{
    printf("Node creation error! Memory could not be allocated.");
  }
  return node;
}

// insert a node to the linked list
int insertProduct(product ** head, product * node){
    node->next = *head;
    *head = node;
    return 0;
}

// remove a node from list
void rmItem(product * l, product * node){

}

// show list
void showList(product * head){
  product * cursor = head;
  while(cursor != NULL){
    printItem(cursor);
    if(cursor->next == NULL)
      break;
    cursor = cursor->next;
  }
  printf("\nEnd of inventory list.\n");
}

product * findItem(product * head){
  product * cursor = head;
  product * found = NULL;
  char buf[N];

  printf("\nEnter item name: ");
  scanf("%s", buf);

  while(found == NULL){
    if(strncmp(cursor->name, buf, N) == 0)
      found = cursor;

    if(cursor->next == NULL){
      printf("\nItem '%s' not found!\n", buf);
    }
    cursor = cursor->next;
  }
  return found;
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

void printItem(product * item){
  if(item != NULL){
    printf("\nProduct: %s", item->name);
    printf("\nQuantity: %i", item->quantityValue);
    printf("\nQuantity Unit: %s", item->quantityUnit);
    printf("\nPrice: %f", item->priceValue);
    printf("\nPrice unit: %s\n", item->priceUnit);
  }
}

int save(product * head){
  int success = 0;
  if(head != NULL){

    success = 1;
  }
  return success;
}

int open(){
  return 0;
}


void userChoice(int choice, product ** l){
  product * node = NULL;

  switch(choice){
    case 0:
      node = create();
      insertProduct(&(*l), node);
      break;

    case 1:
      break;

    case 2:
      break;

    case 3:
      showList(*l);
      break;

    case 4:
      break;

    case 5:
      printItem(findItem(*l));
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;
  }
}

// the job starts here, start with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt(){
  product * head = NULL;

  while(1){
    printMenu();

    int choice;
    scanf("%i", &choice);
    userChoice(choice, &head);
  }
}
