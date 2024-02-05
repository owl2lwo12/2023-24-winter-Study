#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//input
	int n, m;//n, m이 주어진다.
	cin >> n >> m;
	
	vector<int> set;
	set.push_back(0);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		set.push_back(t);
		set[i + 1] += set[i]; //누적 합을 구해놓는다.
	}

	for (int p = 0; p < m; p++) {
		int i, j;
		cin >> i >> j;
		int result = set[j] - set[i - 1]; //누적 합을 이용해서 구간 합을 구한다.

		cout << result << "\n";
	}
}
