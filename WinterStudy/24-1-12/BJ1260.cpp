#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

struct node {
	vector<int> line;
	void Connect(int v) {
		bool isFound = false;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == v) {
				isFound = true;
			}
		}
		if (!isFound) line.push_back(v);
	}
	vector<int> Get_Neighborhoods() {
		return line;
	}
};

struct graph {
	vector<node> nodes;
	graph(int t) : nodes(t) {}
	void ConnectTwoNodes(int a, int b) {
		nodes[a].Connect(b);
		nodes[b].Connect(a);
	}
	void SortAll(int p) {
		switch (p) {
		case 0:
			for (int i = 0; i < nodes.size(); i++) {
				sort(nodes[i].line.begin(), nodes[i].line.end(), compare);
			}
			break;
		case 1:
			for (int i = 0; i < nodes.size(); i++) {
				sort(nodes[i].line.begin(), nodes[i].line.end());
			}
			break;
		}
	}

};

void dfs(graph G, vector<int>& v, vector<int>& result);
void bfs(graph G, queue<int>& q, vector<int>& result);

int main() {
	// input
	int n, m, v;
	cin >> n >> m >> v;
	graph G(n + 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		G.ConnectTwoNodes(a, b);
	}
	G.SortAll(0);
	vector<int> vi, vresult;
	vi.push_back(v);
	dfs(G, vi, vresult);
	cout << "\n";
	vresult.clear();
	G.SortAll(1);
	queue<int> qi;
	qi.push(v);
	bfs(G, qi, vresult);

}
//depth first search -> using lifo -> vector
void dfs(graph G, vector<int>& v, vector<int>& result) {
	int i;
	for (int j = 0; j < v.size(); v.pop_back()) {
		bool isFound = false;
		for (int k = 0; k < result.size(); k++) {
			if (result[k] == v.back()) {
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			i = v.back();
			v.pop_back();
			break;
		}
		else isFound = false;
	}
	bool isRepeat = false;
	result.push_back(i);
	for (int j : G.nodes[i].line) {
		for (int k = 0; k < result.size(); k++) {
			if (j == result[k]) {
				isRepeat = true;
				break;
			}
		}
		if (!isRepeat) v.push_back(j);
		else isRepeat = false;
	}
	if (result.size() < G.nodes.size() - 1 && !v.empty()) {
		dfs(G, v, result);
	}
	else {
		cout << result[0];
		for (int j = 1; j < result.size(); j++) {
			cout << " " << result[j];
		}
	}
}

//breath first search -> using fifo -> queue
void bfs(graph G, queue<int>& q, vector<int>& result) {
	int i;
	for (int j = 0; j < q.size(); q.pop()) {
		bool isFound = false;
		for (int k = 0; k < result.size(); k++) {
			if (result[k] == q.front()) {
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			i = q.front();
			q.pop();
			break;
		}
		else isFound = false;
	}
	bool isRepeat = false;
	result.push_back(i);
	for (int j : G.nodes[i].line) {
		for (int k = 0; k < result.size(); k++) {
			if (j == result[k]) {
				isRepeat = true;
				break;
			}
		}
		if (!isRepeat) q.push(j);
		else isRepeat = false;
	}
	if (result.size() < G.nodes.size() - 1 && !q.empty()) {
		bfs(G, q, result);
	}
	else {
		cout << result[0];
		for (int j = 1; j < result.size(); j++) {
			cout << " " << result[j];
		}
	}
}