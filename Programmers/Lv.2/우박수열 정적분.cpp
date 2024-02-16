#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
  vector<double> answer;
  vector<int> point;
  vector<double> area;

  while (k != 1) {
    point.push_back(k);
    if (k % 2 == 0)
      k /= 2;
    else
      k = k * 3 + 1;
  }
  point.push_back(1);

  for (int i = 0; i < point.size() - 1; i++) {
    area.push_back(double(point[i] + point[i + 1]) / 2.0);
  }

  for (vector<int> range : ranges) {
    int a = range[0];
    int b = point.size() - 1 + range[1];
    if (a > b)
      answer.push_back(-1.0);
    else if (a == b)
      answer.push_back(0.0);
    else {
      double sum = 0;
      for (int i = a; i < b; i++) sum += area[i];
      answer.push_back(sum);
    }
  }

  return answer;
}