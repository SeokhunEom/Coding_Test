#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
  int answer = 0;

  int strlen = myString.length();
  int patLen = pat.length();
  for (int i = 0; i < strlen; i++) {
    if (myString.substr(i, patLen) == pat) {
      answer++;
    }
  }

  return answer;
}