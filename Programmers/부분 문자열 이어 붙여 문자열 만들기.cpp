#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
  string answer = "";

  int len = parts.size();
  for (int i = 0; i < len; i++) {
    answer += my_strings[i].substr(parts[i][0], parts[i][1] - parts[i][0] + 1);
  }

  return answer;
}