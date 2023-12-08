#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning,
                     vector<vector<string>> photo) {
  vector<int> answer;
  map<string, int> m;

  int len = name.size();
  for (int i = 0; i < len; i++) {
    m.insert({name[i], yearning[i]});
  }

  for (vector<string> peaple : photo) {
    int score = 0;
    for (string person : peaple) {
      int temp = m[person];
      score += temp;
    }
    answer.push_back(score);
  }

  return answer;
}