#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*

    1.숫자 파싱 로직 부족:
    쉼표가 등장할 때뿐만 아니라, 중괄호가 닫힐 때도 현재 숫자를 빈도에 추가해야 합니다.

    2.마지막 숫자 처리:
    마지막 숫자는 쉼표로 끝나지 않으므로, 문자열을 끝까지 읽었을 때 마지막 숫자를 빈도에 추가해야 합니다.

    3.불필요한 플래그 사용:
    isNumber 플래그는 사실 불필요합니다. 숫자인지 확인하기 위해 중괄호를 확인할 필요가 없습니다.


    숫자인지 여부를 isdigit 함수를 사용하여 확인합니다.
    쉼표(,)나 중괄호(})가 등장할 때 현재 숫자를 빈도 맵에 추가합니다.
    빈도수 맵을 벡터로 변환한 후 내림차순으로 정렬합니다.
    정렬된 벡터에서 숫자를 추출하여 answer 벡터에 추가합니다.

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
