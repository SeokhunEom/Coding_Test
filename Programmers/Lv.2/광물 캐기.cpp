#include <cmath>
#include <string>
#include <vector>

using namespace std;

int tool, res = 10000;
int pick[3];
int arr[10];
int table[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};

void func(int idx, vector<string>& minerals);

int solution(vector<int> picks, vector<string> minerals) {
  int answer = 0;

  tool = ceil((minerals.size() / 5.0));
  pick[0] = picks[0] < tool ? picks[0] : tool;
  tool -= pick[0];
  pick[1] = picks[1] < tool ? picks[1] : tool;
  tool -= pick[1];
  pick[2] = picks[2] < tool ? picks[2] : tool;
  tool = pick[0] + pick[1] + pick[2];

  func(0, minerals);
  answer = res;

  return answer;
}

void func(int idx, vector<string>& minerals) {
  if (idx == tool) {
    int sum = 0;
    for (int i = 0; i < tool; i++) {
      for (int j = 5 * i; j < 5 * (i + 1) && j < minerals.size(); j++) {
        int t;
        if (minerals[j] == "diamond")
          t = 0;
        else if (minerals[j] == "iron")
          t = 1;
        else
          t = 2;
        sum += table[arr[i]][t];
      }
    }
    if (sum < res) res = sum;
    return;
  }
  for (int i = 0; i < 3; i++) {
    if (pick[i] == 0) continue;
    pick[i]--;
    arr[idx] = i;
    func(idx + 1, minerals);
    pick[i]++;
  }
  return;
}