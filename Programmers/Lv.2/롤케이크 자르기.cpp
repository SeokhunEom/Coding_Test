#include <set>
#include <string>
#include <vector>

using namespace std;

int arr[10001];
set<int> s1;
set<int> s2;

int solution(vector<int> topping) {
  int answer = 0;

  for (int i = 0; i < topping.size(); i++) {
    int n = topping[i];
    arr[n]++;
    s2.insert(n);
  }

  for (int i = 0; i < topping.size() - 1; i++) {
    int n = topping[i];
    arr[n]--;
    if (arr[n] == 0) s2.erase(n);
    s1.insert(n);
    if (s1.size() == s2.size()) answer++;
  }

  return answer;
}