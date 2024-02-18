#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
  int answer = 0;
  vector<int> v;
  set<int> s;

  for (int n : elements) v.push_back(n);
  for (int n : elements) v.push_back(n);

  for (int len = 1; len <= elements.size(); len++) {
    for (int start = 0; start <= elements.size(); start++) {
      int end = start + len;
      int sum = 0;
      for (int i = start; i < end; i++) sum += v[i];
      s.insert(sum);
    }
  }

  answer = s.size();

  return answer;
}