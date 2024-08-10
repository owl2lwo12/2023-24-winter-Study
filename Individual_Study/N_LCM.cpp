#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int p = arr[i];
        int temp = answer;
        //��Ŭ���� ȣ���� ����� ��(�ִ�����)
        // �ּҰ���� = �� ���� �� / �ִ�����
        while (p != 0) {
            int q = p;
            p = temp % p;
            temp = q;
        }
        answer = answer * arr[i] / temp;
    }

    return answer;
}