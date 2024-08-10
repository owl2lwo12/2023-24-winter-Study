// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
#include <iostream>
#include <cmath>
// ������ ���ذ� ��ƴ�. �� �Ҹ��� �𸣰ڴ�.
// �̹� �������� ������� ��
/*
1. ���� ����
2. ���� �ذ� ���⼺
    ������ �ð� �ʰ��� �����ؾ��Ѵ�.(��� ������ ���ҽ��� �� ��Ƹ��� �� ����� ��)
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