#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
  int answer = 0, len = arr.size(), flag = 1;
  vector<int> arr1, arr2 = arr;

  while (1) {
    for (int num : arr2) {
      if (num >= 50 && num % 2 == 0) {
        arr1.push_back(num / 2);
      } else if (num < 50 && num % 2 == 1) {
        arr1.push_back(num * 2 + 1);
      } else {
        arr1.push_back(num);
      }
    }

    flag = 1;
    for (int i = 0; i < len; i++) {
      if (arr1[i] != arr2[i]) {
        flag = 0;
        break;
      }
    }

    if (flag == 1) {
      break;
    } else {
      arr2 = arr1;
      answer++;
      arr1.clear();
    }
  }

  return answer;
}