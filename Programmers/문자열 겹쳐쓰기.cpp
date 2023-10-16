#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
  string answer = my_string;

  for (int i = 0; i < my_string.length(); i++)
  {
    if (i >= s && i < s + overwrite_string.length())
    {
      answer[i] = overwrite_string[i - s];
    }
  }

  return answer;
}