#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
  string answer = "";

  for (int i = 0; i < str1.length() * 2; i++) {
    answer += i % 2 == 0 ? str1[i / 2] : str2[i / 2];
  }

  return answer;
}