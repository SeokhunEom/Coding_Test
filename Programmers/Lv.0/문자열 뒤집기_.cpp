#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = my_string;

  reverse(&answer[0], &answer[0] + answer.length());

  return answer;
}