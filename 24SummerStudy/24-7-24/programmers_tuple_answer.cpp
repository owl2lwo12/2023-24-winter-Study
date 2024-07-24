#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*

    1.���� �Ľ� ���� ����:
    ��ǥ�� ������ ���Ӹ� �ƴ϶�, �߰�ȣ�� ���� ���� ���� ���ڸ� �󵵿� �߰��ؾ� �մϴ�.

    2.������ ���� ó��:
    ������ ���ڴ� ��ǥ�� ������ �����Ƿ�, ���ڿ��� ������ �о��� �� ������ ���ڸ� �󵵿� �߰��ؾ� �մϴ�.

    3.���ʿ��� �÷��� ���:
    isNumber �÷��״� ��� ���ʿ��մϴ�. �������� Ȯ���ϱ� ���� �߰�ȣ�� Ȯ���� �ʿ䰡 �����ϴ�.


    �������� ���θ� isdigit �Լ��� ����Ͽ� Ȯ���մϴ�.
    ��ǥ(,)�� �߰�ȣ(})�� ������ �� ���� ���ڸ� �� �ʿ� �߰��մϴ�.
    �󵵼� ���� ���ͷ� ��ȯ�� �� ������������ �����մϴ�.
    ���ĵ� ���Ϳ��� ���ڸ� �����Ͽ� answer ���Ϳ� �߰��մϴ�.

*/
bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> mem;
    string cur;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            cur += s[i];
        }
        else if (s[i] == ',' || s[i] == '}') {
            if (!cur.empty()) {
                int num = stoi(cur);
                mem[num]++;
                cur.clear();
            }
        }
    }

    vector<pair<int, int>> vec(mem.begin(), mem.end());
    sort(vec.begin(), vec.end(), compare);

    for (auto& i : vec) {
        answer.push_back(i.first);
    }

    return answer;
}
