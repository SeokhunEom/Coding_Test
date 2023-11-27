#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
  int answer = 0;

  string s = to_string(num);
  answer = s.find(to_string(k)) + 1;
  if (answer == 0) answer = -1;

  return answer;
}