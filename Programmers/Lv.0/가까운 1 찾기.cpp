#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
  int len = arr.size();
  for (int i = idx; i < len; i++) {
    if (arr[i] == 1) {
      return i;
    }
  }

  return -1;
}