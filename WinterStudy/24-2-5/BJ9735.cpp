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
	int testcase; //첫째 줄에는 test case의 수가 주어진다.
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int n; //의상의 수
		cin >> n;
		vector<string> typelist; //타입의 종류를 저장
		vector<vector<string>> namelist; //의상의 이름을 저장

		for (int j = 0; j < n; j++) {
			string type, name;
			cin >> name >> type;

			int idx = -1;
			for (int k = 0; k < typelist.size(); k++) {
				if (typelist[k] == type) {
					idx = k; //같은 타입의 옷이 있는지 찾는다.
					break;
				}
			}

			if (idx == -1) {//같은 타입의 옷이 없으면
				typelist.push_back(type);
				vector<string> vs;
				vs.push_back(name);
				namelist.push_back(vs);
			}
			else { //같은 타입의 옷이 있을 경우
				namelist[idx].push_back(name);
			}
		}
		int result = 1;
		for (int j = 0; j < namelist.size(); j++) {
			result *= (namelist[j].size() + 1);
		}
		result--;
		cout << result << "\n";
	}
}
