#include <string>
#include <vector>

using namespace std;

int arr[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;

  for (int i = 1; i <= n; i++) arr[i] = 1;
  for (int l : lost) arr[l] = 0;
  for (int r : reserve) arr[r] += 1;

  for (int i = 1; i <= n; i++) {
    if (arr[i] != 0) continue;
    if (arr[i - 1] > 1) {
      arr[i - 1]--;
      arr[i]++;
    } else if (arr[i + 1] > 1) {
      arr[i + 1]--;
      arr[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (arr[i] > 0) answer++;
  }

  return answer;
}