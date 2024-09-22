#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr1[5] = {1, 2, 3, 4, 5};
int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int score1, score2, score3, maximum = 0;

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  int len = answers.size();

  for (int i = 0; i < len; i++) {
    if (answers[i] == arr1[i % 5]) score1++;
    if (answers[i] == arr2[i % 8]) score2++;
    if (answers[i] == arr3[i % 10]) score3++;
  }

  maximum = max(max(score1, score2), score3);
  if (maximum == score1) answer.push_back(1);
  if (maximum == score2) answer.push_back(2);
  if (maximum == score3) answer.push_back(3);

  return answer;
}