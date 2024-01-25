#include <climits>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY,
                     vector<vector<int>> balls) {
  vector<int> answer;

  for (vector<int> ball : balls) {
    int endX = ball[0];
    int endY = ball[1];

    int a = (2 * n - startY - endY) * (2 * n - startY - endY) +
            (startX - endX) * (startX - endX);
    if (startX == endX && startY < endY) a = INT_MAX;
    int b =
        (startY + endY) * (startY + endY) + (startX - endX) * (startX - endX);
    if (startX == endX && startY > endY) b = INT_MAX;
    int c = (2 * m - startX - endX) * (2 * m - startX - endX) +
            (startY - endY) * (startY - endY);
    if (startY == endY && startX < endX) c = INT_MAX;
    int d =
        (startX + endX) * (startX + endX) + (startY - endY) * (startY - endY);
    if (startY == endY && startX > endX) d = INT_MAX;

    int min_distance = min(min(a, b), min(c, d));
    answer.push_back(min_distance);
  }

  return answer;
}