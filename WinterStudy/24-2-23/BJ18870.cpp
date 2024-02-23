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
	cin >> n;

	vector<int> nums; //모든 숫자를 저장
	vector<int> sequences; // 모든 '종류'의 숫자를 '순서'대로 저장

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		nums.push_back(t);
		sequences.push_back(t);
	}
	
	sort(sequences.begin(), sequences.end());
	sequences.erase(unique(sequences.begin(), sequences.end()), sequences.end());

	for (int i = 0; i < n; i++) {
		
		cout << lower_bound(sequences.begin(),sequences.end(),nums[i]) - sequences.begin() << " ";
	}
}
