#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  for (vector<int> query : queries) {
    int s = query[0];
    int e = query[1];
    int k = query[2];
    int min = 1000001;

    for (int i = s; i <= e; i++) {
      if (arr[i] > k && min > arr[i]) {
        min = arr[i];
      }
    }
    answer.push_back(min == 1000001 ? -1 : min);
  }

  return answer;
}