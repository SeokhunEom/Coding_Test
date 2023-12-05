#include <string>
#include <vector>

using namespace std;

vector<int> solution(string route) {
  int east = 0;
  int north = 0;
  vector<int> answer(2);
  for (int i = 0; i < route.length(); i++) {
    switch (route[i]) {
      case 'N':
        north++;
        break;
      case 'S':
        north--;  // 빈칸
        break;
      case 'E':
        east++;  // 빈칸
        break;
      case 'W':
        east--;  // 빈칸
        break;   // 빈칸
    }
  }
  answer[0] = east;
  answer[1] = north;
  return answer;
}