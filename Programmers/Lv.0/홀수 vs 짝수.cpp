#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
  int even = 0, odd = 0;

  int len = num_list.size();
  for (int i = 0; i < len; i++) {
    if (i % 2 == 0) {
      even += num_list[i];
    } else {
      odd += num_list[i];
    }
  }

  return even > odd ? even : odd;
}