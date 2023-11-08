#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
  int len = arr[0].size();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (arr[i][j] != arr[j][i]) return 0;
    }
  }

  return 1;
}