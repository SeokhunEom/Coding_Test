#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
  vector<int> answer(52);

  int len = my_string.length();
  for (int i = 0; i < len; i++) {
    if (my_string[i] >= 'A' && my_string[i] <= 'Z') {
      int temp = answer[my_string[i] - 'A'];
      answer[my_string[i] - 'A'] = temp + 1;
    } else {
      int temp = answer[my_string[i] - 'a' + 26];
      answer[my_string[i] - 'a' + 26] = temp + 1;
    }
  }

  return answer;
}