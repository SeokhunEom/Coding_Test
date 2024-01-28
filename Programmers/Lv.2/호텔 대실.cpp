#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
pair<int, int> arr[1000];
pair<int, int> book[1000];

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
  int answer = 0;

  n = book_time.size();
  for (int i = 0; i < n; i++) {
    arr[i].first = (book_time[i][0][0] - '0') * 600 +
                   (book_time[i][0][1] - '0') * 60 +
                   (book_time[i][0][3] - '0') * 10 + (book_time[i][0][4] - '0');
    arr[i].second =
        (book_time[i][1][0] - '0') * 600 + (book_time[i][1][1] - '0') * 60 +
        (book_time[i][1][3] - '0') * 10 + (book_time[i][1][4] - '0') + 10;
  }
  sort(arr, arr + n, compare);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (book[j].second > arr[i].first) continue;
      book[j].first = arr[i].first;
      book[j].second = arr[i].second;
      if (j + 1 > answer) answer = j + 1;
      break;
    }
  }

  return answer;
}