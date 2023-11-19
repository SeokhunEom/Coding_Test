#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  vector<int> arr(101, 1);

  for (int i = 2; i * i <= n; i++) {
    if (arr[i] == 1) {
      for (int j = i * i; j <= n; j += i) arr[j] = 0;
    }
  }

  for (int i = 3; i <= n; i++) {
    if (arr[i] == 0) {
      answer++;
    }
  }

  return answer;
}