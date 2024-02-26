#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
  int answer = 0;

  int max = arr[0];
  for (int n : arr) {
    if (n > max) max = n;
  }

  for (int i = max;; i += max) {
    bool flag = true;
    for (int n : arr) {
      if (i % n != 0) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      answer = i;
      break;
    }
  }

  return answer;
}