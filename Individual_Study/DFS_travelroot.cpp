#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// �Ƹ� bfs dfs ������...
int DFS(vector<bool>& visited, vector<string>& maps, int i, int j) {
    int result = maps[i][j] - '0';
    visited[i * maps[i].size() + j] = true;
    if (i - 1 >= 0 && maps[i - 1][j] != 'X' && !visited[(i - 1) * maps[i].size() + j]) { //��� ������ ö���ϰ� üũ�� ��
        /* 1. ��� ������ �迭, ���ڿ��� �ٱ����� �Ѿ�� �ʵ���
           2. 2���� �迭�� size�� ���簢���� �ƴ� ��찡 ����.(���簢���� ��� ���� �����Ƿ� ����ؾ��Ѵ�.
           3. char�� ��ȯ�� (int)���� �� �ƴ� ���� - '0' �̾���Ѵ�.*/
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