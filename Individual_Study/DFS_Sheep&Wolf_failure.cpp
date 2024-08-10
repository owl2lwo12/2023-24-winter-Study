#include <string>
#include <vector>
#include <deque>

using namespace std;
//DFS
typedef struct {
    int info = 0;
    deque<Node> child;
}Node;

int DFS(deque<Node> nodes, int sheep, int wolf) {
    int result = sheep;
    Node node = nodes.back();
    nodes.pop_back();
    nodes.insert(nodes.end(), node.child.begin(), node.child.end());
    int count = 0;
    int rest = nodes.size();
    while (!nodes.empty()) {
        node = nodes.back();
        count++;
        if (node.info == 0) {
            nodes.pop_back();
            result = DFS(nodes, sheep + 1, wolf);
            break;
        }
        else if (node.info == 1 && sheep > wolf + 1) {
            nodes.pop_back();
            int p = DFS(nodes, sheep, wolf + 1);
            if (result == p)
                nodes.push_front(node);
            else {
                result = p;
                break;
            }
        }
        if (count == rest) break;
    }
    return result;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    deque<Node> nodes;
    for (int i = 0; i < info.size(); i++) {
        Node newNode;
        newNode.info = info[i];
        nodes.push_back(newNode);
    }
    for (int i = 0; i < edges.size(); i++) {
        nodes[edges[i][0]].child.push_back(nodes[edges[i][1]]);
    }
    deque<Node> index;
    index.push_back(nodes[0]);
    DFS(index, 1, 0);
    return answer;
}