#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
  vector<int> answer;

  answer = arr;
  for (vector<int> query : queries) {
    int i = query[0];
    int j = query[1];
    int temp = answer[i];
    answer[i] = answer[j];
    answer[j] = temp;
  }

  return answer;
}