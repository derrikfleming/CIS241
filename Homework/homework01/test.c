#include <stdio.h>
#include <string.h>

typedef struct{
  int num;
  char code[10];
}ITEM;

void set(ITEM * item, char s[]){
  item->num = strlen(s);
  strcpy(item->code, s);
}

void display(ITEM * item){
  printf("num: %d, code: %s\n", item->num, item->code);
}

void initialize(ITEM * item){
  item->num = 0;
  strcpy(item->code, "code");
}

int main(){
  ITEM i;

  initialize(&i);
  display(&i);
  set(&i, "some code");
  display(&i);

}
