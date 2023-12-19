#include <string>
#include <vector>

using namespace std;
int arr[100001];

int solution(int number, int limit, int power) {
  int answer = 0;

  for (int i = 1; i <= number; i++) {
    for (int j = 1; j * i <= number; j++) {
      arr[i * j]++;
    }
  }
  for (int i = 1; i <= number; i++) {
    if (arr[i] > limit)
      answer += power;
    else
      answer += arr[i];
  }

  return answer;
}