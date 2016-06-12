#include<stdio.h>

void print(int array[], int n){
  int j;
  for(j = 0; j < n; j++){
    if(j > 0) printf(" ");
    printf("%d", array[j]);
  }
  printf("\n");
}

void insertionSort(int array[], int n){
  int i,k,v;
  for(i = 1; i < n; i++) {
    v = array[i];
    k = i - 1;
    while(k >= 0 && array[k] > v) {
      array[k + 1] = array[k];
      k--;
    }
    array[k + 1] = v;
    print(array, n);
  }
}

int main(){
  int array[2000],n = 200,i = 0,j = 0;
  scanf("%d", &n);
  for(i = 0;i < n; i++)scanf("%d", &array[i]);

  print(array, n);
  insertionSort(array, n);
  return 0;
}
