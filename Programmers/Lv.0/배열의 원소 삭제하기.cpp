#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
  vector<int> answer;

  for (int a : arr) {
    int flag = 0;
    for (int d : delete_list) {
      if (a == d) {
        flag = 1;
        break;
      }
    }

    if (flag == 0) {
      answer.push_back(a);
    }
  }

  return answer;
}