#include <string>
#include <vector>
#include <algorithm>

// �� �����ߴ����� �� ����غ���
// ���� ���� Ǯ�� �ɷ��� �����ϴ�
// ���� ������� �÷��̵� �ͼ��� �� �� ������ Ǯ �� ����Ͽ����� ����� ��
using namespace std;

typedef struct Boxer {
    int rate = 0;
    int rivals;
    vector<int> winner;
    vector<int> loser;

    Boxer(int r) : rivals(r) {}

    void SetLoser(int l) {
        loser.push_back(l);
    }
    void SetWinner(int w) {
        winner.push_back(w);
    }
    int isRate() {
        if (rivals == winner.size() + loser.size()) {
            rate = rivals - loser.size();
            return rate;
        }
        else return 0;
    }
    int isRateWin(int w) {
        if ()
    }

}Boxer;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<Boxer> boxers;
    for (int i = 0; i <= n; i++) {
        boxers.push_back(Boxer(n));
    }
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        boxers[win].SetLoser(lose);
        boxers[lose].SetWinner(win);
    }
    for (int i = 1; i <= n; i++) {
        if (Boxer.rate == 0) {
            int p = Boxer.isRate();

        }
    }

    return answer;
}