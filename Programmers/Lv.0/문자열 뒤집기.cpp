#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
  string answer = "";

  answer = my_string;
  reverse(&answer[0] + s, &answer[0] + e + 1);

  return answer;
}