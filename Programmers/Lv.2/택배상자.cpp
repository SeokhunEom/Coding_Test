#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
  int answer = 0;
  vector<int> v;

  for (int i = 1; i <= order.size(); i++) {
    v.push_back(i);
    while (v.size() != 0 && v.back() == order[answer]) {
      v.pop_back();
      answer++;
    }
  }

  return answer;
}