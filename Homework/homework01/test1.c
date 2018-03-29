#define N 10

int main(){
int arr[N] = {1,2,3,4,5,6,7,8,9};
int *ptr = arr;
free(ptr);

printf("Arr++: %d", *ptr);
}
