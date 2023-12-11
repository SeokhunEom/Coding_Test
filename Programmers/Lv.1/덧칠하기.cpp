#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
  int answer = 0;
  int arr[100001] = {0};

  for (int area : section) {
    arr[area] = 1;
  }

  while (1) {
    bool flag = 0;
    int start = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == 1) {
        flag = 1;
        start = i;
        break;
      }
    }
    if (flag == 0) break;
    for (int i = 0; i < m; i++) {
      if (start + i > n) break;
      arr[start + i] = 0;
    }
    answer++;
  }

  return answer;
}