// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1046527
#define NIL (-1)
#define L 14

typedef struct cc {
  char com[9];
  char str[L];
} C;

char H[M][L];

int getChar(char ch){
  if(ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for(i=0;i<strlen(str);i++){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M;}
int h2(int key){ return 1 + (key % (M-1));}

int find(char str[]){
  long long key, i, h;
  key = getKey(str);
  for(i=0;;i++){
    h = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[h],str) == 0) return 1;
    else if(strlen(H[h]) == 0) return 0;
  }
  return 0;
}

int insert(char str[]){
  long long key, i, h;
  key = getKey(str);
  for(i=0;;i++){
    h = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[h], str) == 0) return 1;
    else if(strlen(H[h]) == 0){
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

int main(){
  int i, n, h;
  char str[L], com[9];
  for(i=0;i<M;i++) H[i][0] = '\0';
  scanf("%d", &n);
  C *com_line = (C *)malloc(sizeof(C)*n);
  for(i=0;i<n;i++) scanf("%s %s", com_line[i].com, com_line[i].str);
  for(i=0;i<n;i++){
    if(com_line[i].com[0] == 'i'){
      insert(com_line[i].str);
    } else {
      if(find(com_line[i].str)){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}
