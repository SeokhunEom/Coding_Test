#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
  int answer = 0;
  vector<int> num(31, 0);

  for (string str : strArr) {
    num[str.length()]++;
  }

  for (int n : num) {
    if (n > answer) {
      answer = n;
    }
  }

  return answer;
}