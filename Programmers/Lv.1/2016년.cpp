#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
  string answer = "";
  string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day = 5;

  for (int i = 0; i < a - 1; i++) {
    day += month[i];
  }
  day += (b - 1);

  answer = week[day % 7];

  return answer;
}