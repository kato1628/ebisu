#include<stdio.h>

void print(int array[], int n){
  int i;
  for(i=0;i<=n-1;i++){
    if(i>0)printf(" ");
    printf("%d", array[i]);
  }
  printf("\n");
}

void bubbleSort(int array[], int n){
  int flag=1,j,tmp,count=0;
  while(flag==1){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(array[j]<array[j-1]){
        tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
        count++;
        flag = 1;
      }
    }
  }
  print(array, n);
  printf("%d\n", count);
}

int main(){
  int n,i,array[100];
  scanf("%d", &n);
  for(i=0;i<=n-1;i++)scanf("%d", &array[i]);
  bubbleSort(array, n);
  return 0;
}
