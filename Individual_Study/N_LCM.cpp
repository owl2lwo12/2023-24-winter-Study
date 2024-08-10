#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int p = arr[i];
        int temp = answer;
        //유클리드 호제법 기억할 것(최대공약수)
        // 최소공배수 = 두 수의 곱 / 최대공약수
        while (p != 0) {
            int q = p;
            p = temp % p;
            temp = q;
        }
        answer = answer * arr[i] / temp;
    }

    return answer;
}