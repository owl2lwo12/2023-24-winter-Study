#include <string>
#include <vector>
#include <deque>

// queue�� subscript ������ �Ұ��ϴ�. ex> queue[i]�� ���� ����
// deque�� ��ɾ �ͼ�������
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<int> _queue;
    for (int i = 0; i < priorities.size(); i++) {
        _queue.push_back(priorities[i]);
    }
    while (true) {
        int p = _queue.front();
        _queue.pop_front();
        bool isBig = true;
        for (int i = 0; i < _queue.size(); i++) {
            if (_queue[i] > p) {
                isBig = false;
                break;
            }
        }
        if (isBig) {
            answer++;
            if (location == 0) {
                break;
            }
            else {
                location--;
            }
        }
        else {
            _queue.push_back(p);
            if (location == 0) {
                location = _queue.size() - 1;
            }
            else {
                location--;
            }
        }
    }
    return answer;
}