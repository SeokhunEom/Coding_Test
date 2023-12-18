#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
  vector<int> answer;
  vector<int> rank;

  for (int num : score) {
    int min = 3000;
    int minIdx = -1;
    if (rank.size() < k) {
      rank.push_back(num);
      for (int n : rank) {
        if (min > n) {
          min = n;
        }
      }
      answer.push_back(min);
    } else {
      for (int i = 0; i < k; i++) {
        if (min > rank[i]) {
          min = rank[i];
          minIdx = i;
        }
      }
      if (num > min) {
        rank[minIdx] = num;
      }
      min = 3000;
      for (int i = 0; i < k; i++) {
        if (min > rank[i]) {
          min = rank[i];
        }
      }
      answer.push_back(min);
    }
  }

  return answer;
}