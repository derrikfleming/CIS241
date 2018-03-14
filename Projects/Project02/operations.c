#include "operations.h"

product * create(){
  product * node = (product *) malloc(sizeof(product));
  // add values to newNode
  if(node != NULL){
    char buf[N];

    printf("\n\nProduct name: ");
    scanf("%s", buf);
    strcpy(node->name, buf);

    printf("Product quantity: ");
    scanf("%f", &(node->quantityValue));

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
void rmItem(product ** head, product * node){
  product * cursor = *head;
  product * previous = NULL;

  while(previous == NULL){
    if(cursor == NULL){
      printf("\nItem '%s' not found in list!\n", node->name);
      break;
    }
    //product to remove is head
    if(strncmp(cursor->name, node->name, N) == 0){
      previous = cursor;
      // multiple products in list
      if(previous->next != NULL){
        *head = previous->next;
        free(node);
      }
      // one product
      else{
        *head = NULL;
        free(node);
      }
    }
    // product to remove is not head
    else if(strncmp((cursor->next)->name, node->name, N) == 0){
      previous = cursor;
      if((cursor->next)->next != NULL)
        previous->next = (cursor->next)->next;
      //product to remove is tail
      else
        previous->next = NULL;
    }
    else
      cursor = cursor->next;
  }
}

// show list
void showList(product * head){
  product * cursor = head;
  if(cursor != NULL){
    while(cursor != NULL){
      printItem(cursor);
      if(cursor->next == NULL)
        break;
      cursor = cursor->next;
    }
    printf("\nEnd of inventory list.\n\n");
  }
  else
    printf("Inventory is empty!\n\n");
}

// find item in list
product * findItem(product * head, char name[]){
  product * cursor = head;
  product * found = NULL;

  while(found == NULL){
    if(cursor == NULL){
      printf("\nItem '%s' not found!\n", name);
      break;
    }
    if(strncmp(cursor->name, name, N) == 0)
      found = cursor;
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
    printf("\n--Quantity: %.2f", item->quantityValue);
    printf("\n--Quantity Unit: %s", item->quantityUnit);
    printf("\n--Price: %.2f", item->priceValue);
    printf("\n--Price unit: %s\n", item->priceUnit);
    printf("---------------------------------------");
  }
}

void save(char outf[], product * head){
  FILE * fout = fopen(outf, "w");
  product * cursor = head;

  while(cursor != NULL){
    fprintf(fout,"%s,%.2f,%s,%.2f,%s\n",cursor->name,cursor->quantityValue,cursor->quantityUnit,cursor->priceValue,cursor->priceUnit);
    if(cursor->next != NULL)
      cursor = cursor->next;
    else
      cursor = NULL;
  }
  fclose(fout);
}

void load(char inf[], product **l){
  FILE * fp = fopen(inf,"r");
  product * node;
  char buf[100];

  if(fp != NULL){
    while(fscanf(fp, "%s\n", buf) != EOF){
      node = (product *) malloc(sizeof(product));
      strcpy(node->name, strtok(buf,","));
      node->quantityValue = atof(strtok(NULL,","));
      strcpy(node->quantityUnit,strtok(NULL,","));
      node->priceValue = atof(strtok(NULL,","));
      strcpy(node->priceUnit, strtok(NULL,","));
      insertProduct(&(*l), node);
    }
  }
  else{
    printf("\nFile could not be found. Proceeding with empty database.\n");
  }
  fclose(fp);
}

float purchase(product ** head, char name[], float quantity){
  product * item = findItem(*head, name);
  float total = 0.0;

  if(item != NULL){
    if(item->quantityValue >= quantity){
      item->quantityValue -= quantity;
      total = quantity * item->priceValue;
    }
    else
      printf("Quantity '%f' unavailable!", quantity);
  }
  return total;
}

// check out price of product p from list 1
void checkPrice(product *l, char name[]){
  product * node = findItem(l, name);
  if(node != NULL)
    printf("\n %s costs %.2f %s.\n", name, node->priceValue, node->priceUnit);
  else
    printf("Could not find a price for %s", name);
}

void userChoice(int choice, product ** l){
  product * node = NULL;
  char buf[N], name[N];
  float quantity, price;
  static float total = 0.0;

  switch(choice){
    case 0:
      node = create();
      insertProduct(&(*l), node);
      break;

    case 1:
      printf("\nEnter item name: ");
      scanf("%s", buf);
      strcpy(name, buf);
      printf("\nEnter quantity: ");
      scanf("%f", &quantity);
      total += purchase(&(*l), name, quantity);
      break;

    case 2:
      printf("\nEnter item name: ");
      scanf("%s", buf);
      strcpy(name, buf);
      checkPrice(*l, name);
      break;

    case 3:
      showList(*l);
      break;

    case 4:
      printf("\nEnter item name: ");
      scanf("%s", buf);
      strcpy(name, buf);
      rmItem(&(*l), findItem(*l, name));
      break;

    case 5:
      printf("\nEnter item name: ");
      scanf("%s", buf);
      strcpy(name, buf);
      printItem(findItem(*l, name));
      break;

    case 6:
      printf("Total sales: %.2f", total);
      showList(*l);
      break;

    case 7:
      printf("\nYou have chosen to exit. \nPlease enter a filename to save the data to: ");
      scanf("%s", buf);
      printf("Please standby while we save the data...\n");
      save(buf,*l);
      printf("\nSaving complete! Goodbye!");
      exit(0);
      break;

    default:
      printf("Error: Incorrect input received. Please try again, use digits 0-7.\n");
      break;
  }
}

// the job starts here, start with laoding data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data
int doIt(){
  product * head = NULL;
  char buf[N] = "";

  printf("Please enter an inventory data file name: ");
  scanf("%s", buf);
  load(buf, &head);

  while(1){
    printMenu();

    int choice;
    scanf("%i", &choice);
    userChoice(choice, &head);
  }
}
