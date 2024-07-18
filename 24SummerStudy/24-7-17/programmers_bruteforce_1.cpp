#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h = 0;
    int w = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int a = sizes[i][0];
        int b = sizes[i][1];
        if (a > b) {
            if (h < a) h = a;
            if (w < b) w = b;
        }
        else {
            if (h < b) h = b;
            if (w < a) w = a;
        }
    }
    answer = h * w;
    return answer;
}