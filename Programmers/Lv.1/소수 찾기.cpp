#include <string>
#include <vector>

using namespace std;

bool arr[1000001];

int solution(int n) {
  int answer = 0;

  for (int i = 2; i <= n; i++) arr[i] = true;
  for (int i = 2; i <= n; i++) {
    if (arr[i] == false) continue;
    answer++;
    for (int j = i + i; j <= n; j += i) arr[j] = false;
  }

  return answer;
}