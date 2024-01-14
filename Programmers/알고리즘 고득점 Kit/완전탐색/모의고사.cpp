#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  int len = answers.size();
  int a = 0, b = 0, c = 0;
  int idx1 = 0, idx2 = 0, idx3 = 0;
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
  int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

  for (int answer : answers) {
    if (arr1[idx1] == answer) a++;
    if (arr2[idx2] == answer) b++;
    if (arr3[idx3] == answer) c++;
    idx1 = (idx1 + 1) % 5;
    idx2 = (idx2 + 1) % 8;
    idx3 = (idx3 + 1) % 10;
  }

  int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
  if (a == max) answer.push_back(1);
  if (b == max) answer.push_back(2);
  if (c == max) answer.push_back(3);

  return answer;
}