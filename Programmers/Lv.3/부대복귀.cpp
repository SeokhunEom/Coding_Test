#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<int> dist(n + 1, -1);

    for(vector<int> road: roads) {
        v[road[0]].push_back(road[1]);
        v[road[1]].push_back(road[0]);
    }

    queue<pair<int, int>> q;
    q.push({destination, 0});
    dist[destination] = 0;

    while(!q.empty()){
        int curPos = q.front().first;
        int curCount = q.front().second;
        q.pop();

        for(int nextPos: v[curPos]){
            if(dist[nextPos] == -1 || dist[nextPos] > curCount + 1){
                q.push({nextPos, curCount + 1});
                dist[nextPos] = curCount + 1;
            }
        }
    }

    for(int source: sources) answer.push_back(dist[source]);

    return answer;
}