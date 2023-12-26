#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서
// 사용하세요.
char* solution(const char* X, const char* Y) {
  // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게
  // 변경해주세요.
  char* answer = (char*)malloc(3000001);
  int num1[10] = {0};
  int num2[10] = {0};

  for (int i = 0;; i++) {
    if (X[i] == '\0') break;
    num1[X[i] - '0']++;
  }
  for (int i = 0;; i++) {
    if (Y[i] == '\0') break;
    num2[Y[i] - '0']++;
  }

  int idx = 0;
  bool flag = true;
  for (int i = 9; i >= 0; i--) {
    int min = num1[i] < num2[i] ? num1[i] : num2[i];
    if (i != 0 && min > 0) flag = false;
    for (int j = 0; j < min; j++) {
      answer[idx++] = '0' + i;
    }
  }
  if (idx == 0)
    answer = "-1";
  else if (flag == true)
    answer = "0";
  else
    answer[idx] = '\0';

  return answer;
}