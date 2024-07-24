#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = brown;
    width -= 4; // �𼭸� 4��
    width /= 2; // ���� ���ΰ� ���� 2�� �� �����Ƿ�
    int height = 1;
    width -= 1;
    for (; width > height;) {
        if (height * width == yellow) {
            break;
        }
        width--;
        height++;
    }
    answer.push_back(width + 2);
    answer.push_back(height + 2);
    return answer;
}