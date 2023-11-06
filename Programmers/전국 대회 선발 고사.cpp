#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
  int answer = 0;
  int a = -1, b = -1, c = -1;

  int len = rank.size();
  for (int i = 0; i < len; i++) {
    if (attendance[i] == false)
      continue;

    else if (a == -1 || rank[i] < rank[a]) {
      c = b;
      b = a;
      a = i;
    } else if (b == -1 || rank[i] < rank[b]) {
      c = b;
      b = i;
    } else if (c == -1 || rank[i] < rank[c]) {
      c = i;
    }
  }
  answer = 10000 * a + 100 * b + c;

  return answer;
}