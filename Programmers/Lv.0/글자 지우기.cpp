#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
  string answer = "";

  int len = my_string.length();
  for (int i = 0; i < len; i++) {
    if (find(indices.begin(), indices.end(), i) == indices.end()) {
      answer += my_string[i];
    }
  }

  return answer;
}