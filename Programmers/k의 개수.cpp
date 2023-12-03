#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
  int answer = 0;

  for (int n = i; n <= j; n++) {
    for (char c : to_string(n)) {
      if (c - '0' == k) {
        answer++;
      }
    }
  }

  return answer;
}