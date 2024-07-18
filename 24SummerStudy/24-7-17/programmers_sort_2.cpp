#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a; //�������� ���� ���� ����̴� ������ �� �غ���
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sortable;
    for (int i = 0; i < numbers.size(); i++) {
        sortable.push_back(to_string(numbers[i]));
    }
    sort(sortable.begin(), sortable.end(), compare);
    if (sortable[0] == "0") { //���� ó���� Ȯ���ϰ� �� ��
        answer = "0";
        return answer;
    }
    for (int i = 0; i < sortable.size(); i++) {
        answer += sortable[i];
    }
    return answer;
}