#include<stdio.h>

typedef struct Card{
  char mark;
  int number;
} card;

int main(){
  int num,i,j,min,flag,check=0;
  card CA_1[36],CA_2[36],tmp;
  scanf("%d",&num);
  for(i=0;i<num;i++)scanf(" %c%d",&CA_1[i].mark,&CA_1[i].number);
  for(i=0;i<num;i++)CA_2[i]=CA_1[i];

  /*BubbleSort*/
  flag=1;
  while(flag){
    flag=0;
    for(j=num-1;j>=1;j--){
      if(CA_1[j].number<CA_1[j-1].number){
        tmp=CA_1[j];
        CA_1[j]=CA_1[j-1];
        CA_1[j-1]=tmp;
        flag=1;
      }
    }
  }

  /*BubblePrint*/
  for(i=0;i<num-1;i++)printf("%c%d ",CA_1[i].mark,CA_1[i].number);
  printf("%c%d\n",CA_1[i].mark,CA_1[i].number);
  puts("Stable");

  /*SelectionSort*/
  for(i=0;i<num-1;i++){
    min=i;
    for(j=i;j<num;j++){
      if(CA_2[j].number<CA_2[min].number){
        min=j;
      }
    }
    if(CA_2[i].number!=CA_2[min].number){
      tmp=CA_2[i];
      CA_2[i]=CA_2[min];
      CA_2[min]=tmp;
    }
  }

  /*SelectionPrint*/
  for(i=0;i<num-1;i++)printf("%c%d ",CA_2[i].mark,CA_2[i].number);
  printf("%c%d\n",CA_2[i].mark,CA_2[i].number);
  for(i=0;i<=num-1;i++){
    if(CA_2[i].number==CA_1[i].number&&CA_2[i].mark!=CA_1[i].mark){
      check=1;
    }
  }
  if(check==1)puts("Not stable");
  else puts("Stable");
  return 0;
}
