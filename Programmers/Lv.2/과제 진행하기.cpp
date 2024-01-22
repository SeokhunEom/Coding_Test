#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(vector<string> v1, vector<string> v2) {
  return stoi(v1[1]) < stoi(v2[1]);
}

vector<string> solution(vector<vector<string>> plans) {
  vector<string> answer;
  vector<vector<string>> myPlans;
  vector<vector<string>> paused;
  vector<string> going;
  int idx = 0;

  for (vector<string> plan : plans) {
    vector<string> v;
    v.push_back(plan[0]);
    int minutes = (plan[1][0] - '0') * 600 + (plan[1][1] - '0') * 60 +
                  (plan[1][3] - '0') * 10 + (plan[1][4] - '0');
    v.push_back(to_string(minutes));
    v.push_back(plan[2]);
    myPlans.push_back(v);
  }
  sort(myPlans.begin(), myPlans.end(), compare);

  int time = 0;
  while (answer.size() < plans.size()) {
    if (idx < myPlans.size() && stoi(myPlans[idx][1]) == time) {
      if (!going.empty()) paused.push_back(going);
      going = myPlans[idx++];
      continue;
    }
    if (going.empty() && !paused.empty()) {
      going = paused.back();
      paused.pop_back();
    }
    if (!going.empty()) {
      going[2] = to_string(stoi(going[2]) - 1);
      if (stoi(going[2]) == 0) {
        answer.push_back(going[0]);
        going.clear();
      }
    }
    time++;
  }

  return answer;
}