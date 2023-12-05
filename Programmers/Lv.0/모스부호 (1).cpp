#include <string>
#include <vector>

using namespace std;

char findMorse(string str);

string solution(string letter) {
  string answer = "";
  string str = "";

  for (char c : letter) {
    if (c == ' ') {
      answer += findMorse(str);
      str = "";
      continue;
    }
    str += c;
  }
  answer += findMorse(str);

  return answer;
}

char findMorse(string str) {
  string morse[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};

  for (int i = 0; i < 26; i++) {
    if (morse[i] == str) {
      return i + 'a';
    }
  }
}