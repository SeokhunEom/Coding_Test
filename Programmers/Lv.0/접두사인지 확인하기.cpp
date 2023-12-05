#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
  int len = my_string.length();
  for (int i = 0; i < len; i++) {
    if (my_string.substr(0, i) == is_prefix) {
      return 1;
    }
  }

  return 0;
}