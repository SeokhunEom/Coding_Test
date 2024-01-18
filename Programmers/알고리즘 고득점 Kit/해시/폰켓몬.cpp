#include <map>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;

  int n = nums.size();
  map<int, int> m;

  for (int n : nums) {
    if (m.find(n) != m.end())
      m[n]++;
    else
      m.insert({n, 1});
  }

  answer = m.size() > n / 2 ? n / 2 : m.size();

  return answer;
}