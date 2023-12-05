#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
  vector<int> answer;

  int len = myString.length();
  int n = 0;
  for (int i = 0; i < len; i++) {
    if (myString[i] == 'x') {
      answer.push_back(n);
      n = 0;
    } else {
      n++;
    }
  }
  answer.push_back(n);

  return answer;
}