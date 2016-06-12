#include<stdio.h>
int n, quon_time, S[100000], now=0, tmp;
char process[100000][10];
int main(){
  int i=1,done=0;
  scanf("%d%d", &n, &quon_time);
  while(scanf("%s%d", process[i], &S[i]) != EOF)i++;
  while(done!=n){
    if(i>n)i=1;
    if(S[i]>0){
      tmp=S[i];
      S[i] = S[i] - quon_time;
      if(S[i]<=0){
        now = now + tmp;
        printf("%s %d\n", process[i], now);
        done++;
      }else{
        now = now + quon_time;
      }
    }
    i++;
  }
  return 0;
}
