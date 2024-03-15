#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  int r = -1;
  while (n != 0) {
    r = n % 3;
    n /= 3;

    if (r == 0) {
      answer = "4" + answer;
      n--;
    } else if (r == 1)
      answer = "1" + answer;
    else if (r == 2)
      answer = "2" + answer;
  }

  return answer;
}