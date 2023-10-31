#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
  vector<string> answer;
  string tempStr;

  int len = strArr.size();
  for (int i = 0; i < len; i++) {
    tempStr = "";
    for (char c : strArr[i]) {
      if (i % 2 == 0) {
        tempStr.push_back(tolower(c));
      } else {
        tempStr.push_back(toupper(c));
      }
    }
    answer.push_back(tempStr);
  }

  return answer;
}