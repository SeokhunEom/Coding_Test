#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
  set<int> s = {a, b, c, d};
  int num_arr[4] = {a, b, c, d};

  sort(num_arr, num_arr + 4);
  if (s.size() == 1) {
    return 1111 * num_arr[0];
  } else if (s.size() == 2) {
    if (num_arr[1] == num_arr[2]) {
      if (num_arr[0] == num_arr[1]) {
        return pow(10 * num_arr[0] + num_arr[3], 2);
      } else {
        return pow(10 * num_arr[3] + num_arr[0], 2);
      }
    } else {
      return (num_arr[0] + num_arr[3]) * abs(num_arr[0] - num_arr[3]);
    }
  } else if (s.size() == 3) {
    if (num_arr[0] == num_arr[1]) {
      return num_arr[2] * num_arr[3];
    } else if (num_arr[1] == num_arr[2]) {
      return num_arr[0] * num_arr[3];
    } else {
      return num_arr[0] * num_arr[1];
    }
  } else {
    return num_arr[0];
  }

  return 1;
}