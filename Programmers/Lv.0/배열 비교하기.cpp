#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
  int sum1 = 0, sum2 = 0;
  if (arr1.size() > arr2.size()) {
    return 1;
  } else if (arr1.size() < arr2.size()) {
    return -1;
  } else {
    for (int a : arr1) {
      sum1 += a;
    }
    for (int b : arr2) {
      sum2 += b;
    }
    if (sum1 > sum2) {
      return 1;
    } else if (sum1 < sum2) {
      return -1;
    } else {
      return 0;
    }
  }
}