#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool isConnected[100001];
vector<int> arr[100001];

void func(int node, int parent) {
  for (int i = 0; i < arr[node].size(); i++) {
    if (arr[node][i] != parent) {
      func(arr[node][i], node);

      if (!isConnected[arr[node][i]] && !isConnected[node]) {
        isConnected[node] = true;
        answer++;
      }
    }
  }
}

int solution(int n, vector<vector<int>> lighthouse) {
  for (vector<int> v : lighthouse) {
    arr[v[0]].push_back(v[1]);
    arr[v[1]].push_back(v[0]);
  }

  func(1, 1);

  return answer;
}