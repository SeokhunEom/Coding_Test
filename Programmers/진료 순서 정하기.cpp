#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
  vector<int> answer;

  for (int myEmer : emergency) {
    int rank = 1;
    for (int yourEmer : emergency) {
      if (myEmer < yourEmer) rank++;
    }
    answer.push_back(rank);
  }

  return answer;
}