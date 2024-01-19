#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//input
	int testcase;
	cin >> testcase;

	vector<int> triangles(101);
	triangles[0] = 0;
	triangles[1] = 1;
	triangles[2] = 1;
	triangles[3] = 1;
	for (int i = 4; i <= 100; i++) {
		triangles[i] = triangles[i - 3] + triangles[i - 2];
	}
	for (int i = 0; i < testcase; i++) {
		int n;
		cin >> n;
		cout << triangles[n] << "\n";
	}
}
