#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                triangle[i][j] += triangle[i - 1][0];
            }
            else if (j == triangle[i].size() - 1) {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else {
                triangle[i][j] += (triangle[i - 1][j - 1] > triangle[i - 1][j]) ? triangle[i - 1][j - 1] : triangle[i - 1][j];
            }
        }
    }
    sort(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    answer = triangle[triangle.size() - 1][triangle.size() - 1];
    return answer;
}