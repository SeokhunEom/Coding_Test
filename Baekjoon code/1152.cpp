#include <stdio.h>
#include <string.h>


int main(void){
  char arr[1000000]; 
  int a = 0, len;
  scanf("%[^\n]", arr);
  len = strlen(arr);

  if (len == 1){
    if(arr[0] == ' '){
      printf("0");
      return 0;
    }
  }
  for(int i = 1; i < len - 1; i++){
    if( arr[i] == ' '){
      a++;
    }
  }

  printf("%d", a + 1);

  return 0;
}