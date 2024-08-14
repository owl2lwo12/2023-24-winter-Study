#include <string>
#include <vector>
#include <queue>
#include <algorithm>

//첫 시도 실패
//힌트를 보았을 때 방법은 BFS 판단력을 길러보자....
using namespace std;

void BFS(queue<int> q, vector<int>& v, const vector<vector<int>>& n) {
    int f;
    while (!q.empty()) {
        f = q.front();
        q.pop();
        for (int i = 0; i < n[f].size(); i++) {
            if (v[n[f][i]] == -1 || v[n[f][i]] > v[f] + 1) {
                v[n[f][i]] = v[f] + 1;
                q.push(n[f][i]); //결과값 실수하지 말자 좀 잘 적어서
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> v(n + 1, -1);
    vector<vector<int>> nodes(n + 1);
    queue<int> q;
    for (int i = 0; i < edge.size(); i++) {
        nodes[edge[i][0]].push_back(edge[i][1]);
        nodes[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    v[1] = 0;
    BFS(q, v, nodes);
    int dist = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == dist) answer++;
        else if (v[i] > dist) {
            answer = 1;
            dist = v[i];
        }
    }
    return answer;
}