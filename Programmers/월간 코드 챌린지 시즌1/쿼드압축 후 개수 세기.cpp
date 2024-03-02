#include <string>
#include <vector>

using namespace std;

int a, b;
int arr[1024][1024];

void abstract(int x1, int x2, int y1, int y2, vector<vector<int>>& arr);

vector<int> solution(vector<vector<int>> arr) {
  vector<int> answer(2);

  int n = arr.size();
  abstract(0, n, 0, n, arr);
  answer[0] = a;
  answer[1] = b;

  return answer;
}

void abstract(int x1, int x2, int y1, int y2, vector<vector<int>>& arr) {
  bool flag = true;
  int first = arr[x1][y1];
  for (int i = x1; i < x2; i++) {
    for (int j = y1; j < y2; j++) {
      if (first != arr[i][j]) {
        flag = false;
        break;
      }
    }
    if (flag == false) break;
  }
  if (flag == true) {
    if (first == 0)
      a++;
    else
      b++;
  } else {
    int size = (x2 - x1) / 2;
    abstract(x1, x1 + size, y1, y1 + size, arr);
    abstract(x1, x1 + size, y1 + size, y2, arr);
    abstract(x1 + size, x2, y1, y1 + size, arr);
    abstract(x1 + size, x2, y1 + size, y2, arr);
  }
}