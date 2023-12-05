#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
  int answer = 0;

  int len = myString.length();
  for (int i = 0; i < len; i++) {
    myString[i] = tolower(myString[i]);
  }
  len = pat.length();
  for (int i = 0; i < len; i++) {
    pat[i] = tolower(pat[i]);
  }

  answer = myString.find(pat) == -1 ? 0 : 1;

  return answer;
}