#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
  int answer = 0;
  vector<int> v;

  for (int x : ingredient) {
    v.push_back(x);
    int len = v.size();
    if (len >= 4) {
      if (v[len - 1] == 1 && v[len - 2] == 3 && v[len - 3] == 2 &&
          v[len - 4] == 1) {
        answer++;
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
      }
    }
  }

  return answer;
}