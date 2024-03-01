#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  map<string, set<string>> reportList;
  map<string, set<string>> reportedList;

  for (const auto& id : id_list) {
    reportList[id] = set<string>();
    reportedList[id] = set<string>();
  }

  for (const auto& item : report) {
    size_t spacePos = item.find(' ');
    string reportUser = item.substr(0, spacePos);
    string reportedUser = item.substr(spacePos + 1);

    reportList[reportUser].insert(reportedUser);
    reportedList[reportedUser].insert(reportUser);
  }

  vector<string> blockedUserList;
  for (const auto& user : reportedList) {
    if (user.second.size() >= k) {
      blockedUserList.push_back(user.first);
    }
  }

  vector<int> answer;
  for (const auto& user : id_list) {
    int count = 0;
    for (const auto& blockedUser : blockedUserList) {
      if (reportList[user].find(blockedUser) != reportList[user].end()) {
        count++;
      }
    }
    answer.push_back(count);
  }

  return answer;
}
