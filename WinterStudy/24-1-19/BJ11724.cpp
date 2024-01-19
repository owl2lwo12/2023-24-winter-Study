#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> lines[1001];
bool isAlready[1001] = { false, };

void BFS(int num) {
	queue<int> q;
	q.push(num);
	isAlready[num] = true;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int i = 0; i < lines[f].size(); i++) {
			if (!isAlready[lines[f][i]]) {
				q.push(lines[f][i]);
				isAlready[lines[f][i]] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//input
	int n, m; //num of vertexs, edges
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		lines[a].push_back(b);
		lines[b].push_back(a);
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (!isAlready[i]) {
			BFS(i);
			result++;
		}
	}
	cout << result;
}
