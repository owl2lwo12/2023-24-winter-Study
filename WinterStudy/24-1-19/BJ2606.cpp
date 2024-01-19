#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> computer[101];
bool isAlready[101] = { false, };
vector<int> result;

void BFS(int num) {
	queue<int> q;
	q.push(num);
	isAlready[num] = true;
	while (!q.empty()) {
		int f = q.front();
		result.push_back(f);
		q.pop();
		for (int i = 0; i < computer[f].size(); i++) {
			if (!isAlready[computer[f][i]]) {
				q.push(computer[f][i]);
				isAlready[computer[f][i]] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//input
	int n; //num of computers
	cin >> n;
	int m; //num of connects
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	BFS(1);
	cout << result.size() - 1;
}
