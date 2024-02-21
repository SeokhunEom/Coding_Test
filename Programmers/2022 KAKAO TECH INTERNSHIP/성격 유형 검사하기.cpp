#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> m;

string solution(vector<string> survey, vector<int> choices) {
  string answer = "";

  for (int i = 0; i < survey.size(); i++) {
    m[survey[i][0]] += max(4 - choices[i], 0);
    m[survey[i][1]] += max(choices[i] - 4, 0);
  }

  answer += m['R'] >= m['T'] ? "R" : "T";
  answer += m['C'] >= m['F'] ? "C" : "F";
  answer += m['J'] >= m['M'] ? "J" : "M";
  answer += m['A'] >= m['N'] ? "A" : "N";

  return answer;
}