#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
  string answer = "";

  int index = myString.rfind(pat);
  answer = myString.substr(0, index) + pat;

  return answer;
}