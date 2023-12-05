#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
  int answer = -1;

  int len = A.length();
  for (int i = 0; i < len; i++) {
    if (A == B) {
      answer = i;
      break;
    }
    char t = A[len - 1];
    string temp = "";
    temp += t;
    for (int j = 0; j < len - 1; j++) {
      temp += A[j];
    }
    A = temp;
  }
  if (answer == -1 && A == B) {
    answer = len - 1;
  }

  return answer;
}