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
	int n, m, b; //첫째 줄에 n, m, b가 주어진다
	cin >> n >> m >> b; // n : 세로줄 m : 가로줄 b : 소지하고 있는 블럭의 개수
	vector<int> ground; //ground : 각 좌표에 들어갈 땅의 높이

	int max = 0; //가장 높은 블럭의 높이
	int min = 500; //가장 낮은 블럭의 높이
	for (int i = 0; i < n * m; i++) {
		int t;
		cin >> t;
		if (t > max) max = t;//최대 높이와 최소 높이는 값을 찾을 범위를 설정하는데 사용된다.
		if (t < min) min = t;
		ground.push_back(t);
	}
	//브루트 포스
	int result = -1; //결과 시간
	int high = -1; //결과 높이
	for (int i = max; i >= min; i--) {
		int _result = 0;
		int _b = b;
		for (int j = 0; j < m * n; j++) {
			if (ground[j] >= i) { //블록이 목표 높이보다 높으면
				_result = _result + 2 * (ground[j] - i);
				_b = _b + ground[j] - i;
			}
			else if (ground[j] < i) { //낮으면
				_result = _result + i - ground[j];
				_b = _b - i + ground[j];
			}
		}
		if (_b >= 0 && (_result < result || result == -1)) { // 오답 발생 지점!: 잔여 블록의 개수는 마지막에 판별해야한다. 그렇지 않으면 음수일 때 틀리게 되버리기 때문
			result = _result;
			high = i;
		}
	}
	cout << result << " " << high;
}
