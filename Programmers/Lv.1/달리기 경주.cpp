#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
  vector<string> answer = players;
  map<string, int> m;

  int len = players.size();
  for (int i = 0; i < len; i++) {
    m.insert({players[i], i});
  }

  for (string player : callings) {
    int idx = m[player];
    string temp = answer[idx - 1];
    answer[idx - 1] = answer[idx];
    answer[idx] = temp;
    m[player] = idx - 1;
    m[temp] = idx;
  }

  return answer;
}