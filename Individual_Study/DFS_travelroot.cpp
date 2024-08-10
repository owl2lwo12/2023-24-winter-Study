#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 아마 bfs dfs 문젠데...
int DFS(vector<bool>& visited, vector<string>& maps, int i, int j) {
    int result = maps[i][j] - '0';
    visited[i * maps[i].size() + j] = true;
    if (i - 1 >= 0 && maps[i - 1][j] != 'X' && !visited[(i - 1) * maps[i].size() + j]) { //모든 조건을 철저하게 체크할 것
        /* 1. 경계 선에서 배열, 문자열의 바깥으로 넘어가지 않도록
           2. 2차원 배열의 size가 정사각형이 아닌 경우가 많다.(직사각형의 경우 또한 많으므로 고려해야한다.
           3. char의 변환은 (int)변수 가 아닌 변수 - '0' 이어야한다.*/
        result += DFS(visited, maps, i - 1, j);
    }
    if (i + 1 < maps.size() && maps[i + 1][j] != 'X' && !visited[(i + 1) * maps[i].size() + j]) {
        result += DFS(visited, maps, i + 1, j);
    }
    if (j - 1 >= 0 && maps[i][j - 1] != 'X' && !visited[i * maps[i].size() + j - 1]) {
        result += DFS(visited, maps, i, j - 1);
    }
    if (j + 1 < maps[i].size() && maps[i][j + 1] != 'X' && !visited[i * maps[i].size() + j + 1]) {
        result += DFS(visited, maps, i, j + 1);
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<bool> visited(maps.size() * maps[0].size(), false);

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'X') visited[i * maps[i].size() + j] = true;
            else {
                if (visited[i * maps[i].size() + j] == false) {
                    answer.push_back(DFS(visited, maps, i, j));
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}