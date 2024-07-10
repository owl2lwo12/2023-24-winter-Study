#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {

            if (lost[i] == reserve[j]) { //잃어버렸는데 스페어 있으면
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
    answer -= lost.size();
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            int p = lost[i] - reserve[j];
            if (p == 1 || p == -1) {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }
    return answer;
}