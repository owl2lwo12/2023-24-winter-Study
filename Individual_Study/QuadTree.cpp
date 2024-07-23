#include <string>
#include <vector>

using namespace std;
//const aa& bb로 함수에서 선언한다면 속도의 향상(but 값을 변경할 수 없다.)
vector<int> quadTree(const vector<vector<int>>& arr, int block_size, int start_x, int start_y) {
    vector<int> result(2, 0);
    bool isDiff = false;
    int start_block = arr[start_x][start_y];
    for (int i = start_x; i < start_x + block_size; i++) {
        for (int j = start_y; j < start_y + block_size; j++) {
            if (start_block != arr[i][j]) {
                isDiff = true;
                break;
            }
        }
        if (isDiff) break;
    }

    if (isDiff) {
        vector<int> spare = quadTree(arr, block_size / 2, start_x, start_y);
        result[0] += spare[0];
        result[1] += spare[1];
        spare = quadTree(arr, block_size / 2, start_x + block_size / 2, start_y);
        result[0] += spare[0];
        result[1] += spare[1];
        spare = quadTree(arr, block_size / 2, start_x + block_size / 2, start_y + block_size / 2);
        result[0] += spare[0];
        result[1] += spare[1];
        spare = quadTree(arr, block_size / 2, start_x, start_y + block_size / 2);
        result[0] += spare[0];
        result[1] += spare[1];
    }
    else {
        result[start_block]++;
    }
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer = quadTree(arr, arr.size(), 0, 0);
    return answer;
}