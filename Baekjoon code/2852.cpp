#include <iostream>
using namespace std;

int N, t1, t2, team, cur_time = 0, score1, score2;
string s;

int time_to_sec(string s) {
  return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 +
         (s[4] - '0');
}

string sec_to_time(int sec) {
  string ret = "";

  ret += (sec / 600) + '0';
  sec %= 600;
  ret += (sec / 60) + '0';
  sec %= 60;
  ret += ':';
  ret += (sec / 10) + '0';
  sec %= 10;
  ret += sec + '0';

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> team;
    cin >> s;
    int sec = time_to_sec(s);

    if (score1 > score2) {
      t1 += sec - cur_time;
    } else if (score1 < score2) {
      t2 += sec - cur_time;
    }

    if (team == 1) {
      score1++;
    } else {
      score2++;
    }

    cur_time = sec;
  }

  int sec = time_to_sec("48:00");
  if (score1 > score2) {
    t1 += sec - cur_time;
  } else if (score1 < score2) {
    t2 += sec - cur_time;
  }

  cout << sec_to_time(t1) << "\n";
  cout << sec_to_time(t2);

  return 0;
}