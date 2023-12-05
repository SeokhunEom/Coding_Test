#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  answer = arr;
  for (vector<int> query : queries) {
    int s = query[0];
    int e = query[1];
    int k = query[2];

    for (int i = s; i <= e; i++) {
      if (i % k == 0) {
        answer[i]++;
      }
    }
  }

  return answer;
}