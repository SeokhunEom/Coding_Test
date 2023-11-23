#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
  long long answer = 0;

  int len = numbers.length();
  for (int i = 0; i < len;) {
    string temp = "";
    temp = temp + numbers[i] + numbers[i + 1];
    if (temp == "ze") {
      i += 4;
      answer = answer * 10 + 0;
    } else if (temp == "on") {
      i += 3;
      answer = answer * 10 + 1;
    } else if (temp == "tw") {
      i += 3;
      answer = answer * 10 + 2;
    } else if (temp == "th") {
      i += 5;
      answer = answer * 10 + 3;
    } else if (temp == "fo") {
      i += 4;
      answer = answer * 10 + 4;
    } else if (temp == "fi") {
      i += 4;
      answer = answer * 10 + 5;
    } else if (temp == "si") {
      i += 3;
      answer = answer * 10 + 6;
    } else if (temp == "se") {
      i += 5;
      answer = answer * 10 + 7;
    } else if (temp == "ei") {
      i += 5;
      answer = answer * 10 + 8;
    } else if (temp == "ni") {
      i += 4;
      answer = answer * 10 + 9;
    }
  }

  return answer;
}