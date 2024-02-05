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
	int n;
	cin >> n; // 1이상 n 이하의 수를 저장하기 위함.

	vector<int> lifo; //수가 직접 들어갔다 나왔다 할 vector
	queue<int> target; // 수의 순서를 저장할 queue

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		target.push(t);
	}

	int p = target.front(); //target의 첫번째 값 = 가장 먼저 pop 되어야 하는 값.
	int q = 0;
	vector<char> result;
	bool isWrong = false; //순서대로 출력이 불가능할 때 true로 전환 될 것
	while (!target.empty()) { //target에 값이 남아있지 않을 때 종료
		p = target.front();
		while (q < p) { // q가 p보다 작을 때에는 값이 계속 push되는 것이 맞다.
			q++;
			lifo.push_back(q);
			result.push_back('+');
		}
		if (q >= p) {
			int t = lifo.back();
			if (t == p) { //목표값이 stack의 마지막 즉, 바로 빠져 나갈 수 있으면 pop해준다.
				lifo.pop_back();
				result.push_back('-');
				target.pop();
			}
			else {
				isWrong = true;
				break;
			}
		}
	}

	if (isWrong) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
}
