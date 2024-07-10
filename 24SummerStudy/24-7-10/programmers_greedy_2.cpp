#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = name.size() - 1;
    bool start = false;
    int dummy_idx = -1;
    for (int i = 1; i < name.size(); i++) {
        if (start) {
            if (name[i] == 'A' && i == name.size() - 1) {
                if (answer > dummy_idx) {
                    answer = dummy_idx;
                }
            }
            else if (name[i] != 'A') {
                start = false;
                if (dummy_idx > name.size() - i) {
                    if (answer > (name.size() - i) * 2 + dummy_idx)
                        answer = (name.size() - i) * 2 + dummy_idx;
                }
                else {
                    if (answer > name.size() - i + dummy_idx * 2)
                        answer = name.size() - i + dummy_idx * 2;
                }
            }
        }
        else {
            if (name[i] == 'A') {
                start = true;
                dummy_idx = i - 1;
                if (i == name.size() - 1) {//마지막 글자만 A
                    if (answer > dummy_idx)
                        answer = dummy_idx;
                }
            }
        }
    }
    for (int i = 0; i < name.size(); i++) {
        int p = name[i] - 'A';
        if (p <= 13) answer += p;
        else {
            answer += 26 - p;
        }
    }
    return answer;
}