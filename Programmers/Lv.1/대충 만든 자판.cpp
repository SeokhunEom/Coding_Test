#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
  vector<int> answer;
  int arr[26];

  for (int i = 0; i < 26; i++) arr[i] = -1;

  for (string key : keymap) {
    int len = key.length();
    for (int i = 0; i < len; i++) {
      int idx = key[i] - 'A';
      if (arr[idx] == -1 || arr[idx] > i + 1) {
        arr[idx] = i + 1;
      }
    }
  }

  for (string target : targets) {
    int sum = 0;
    for (char c : target) {
      int idx = c - 'A';
      if (arr[idx] == -1) {
        sum = -1;
        break;
      }
      sum += arr[idx];
    }
    answer.push_back(sum);
  }

  return answer;
}