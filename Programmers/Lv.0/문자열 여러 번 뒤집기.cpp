#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
  string answer = "";

  answer = my_string;
  for (vector<int> query : queries) {
    int s = query[0];
    int e = query[1];

    reverse(&answer[s], &answer[e + 1]);
  }

  return answer;
}