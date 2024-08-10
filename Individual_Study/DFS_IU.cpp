// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include <iostream>
#include <cmath>
// 문제의 이해가 어렵다. 뭔 소린지 모르겠다.
// 이번 문제에서 어려웠던 점
/*
1. 문제 이해
2. 문제 해결 방향성
    언제나 시간 초과에 유의해야한다.(어느 방향이 리소스를 덜 잡아먹을 지 고민할 것)
*/
using namespace std;

int Singing(int cur, int sIdx, int pIdx, int idx, bool condition) {
    int result = 0;
    if (sIdx == 0) {
        if (sIdx > 0) return 0;
        else if (cur != 1) return 0;
        else return 1;
    }
    else if (pIdx == 0) {
        while (sIdx > 0) {
            if (cur % 3 != 0) return 0;
            else {
                sIdx--;
                cur /= 3;
            }
        }
        if (cur != 1) return 0;
        else return 1;
    }
    else {
        if (idx == 2) condition = true;
        result += Singing(cur - 1, sIdx, pIdx - 1, idx + 1, condition);
        if (cur % 3 == 0 && pIdx - sIdx <= sIdx - 2)
            result += Singing(cur / 3, sIdx - 1, pIdx, 0, condition);
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    int s = (int)(log(n) / log(3));
    answer = Singing(n, s, 2 * s, 0, false);
    return answer;
}