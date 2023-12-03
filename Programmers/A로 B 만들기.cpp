#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
  int answer = 1;
  int arr1[26] = {0};
  int arr2[26] = {0};

  for (char c : before) {
    arr1[c - 'a']++;
  }
  for (char c : after) {
    arr2[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (arr1[i] != arr2[i]) {
      answer = 0;
      break;
    }
  }

  return answer;
}