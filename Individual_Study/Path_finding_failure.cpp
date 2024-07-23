#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
    int nodeNum = 0;
    vector<int> myVec;
    node parent = NULL;
    node left = NULL;
    node right = NULL;

    node(vector<int> vec, int num) {
        nodeNum = num;
        myVec = vec;
    }
};

bool compare(node a, node b) {
    if (a.myVec[1] == b.myVec[1]) return a.myVec[0] < b.myVec[0];
    return a.myVec[1] > b.myVec[1];
}

vector<node> MakeNodes(const vector<vector<int>>& vec) {
    vector<node> result;
    for (int i = 0; i < vec.size(); i++) {
        node _node(vec[i], i);
        result.push_back(_node);
    }
    return result;
}

void MakeTree(vector<node> nodes) {
    sort(nodes.begin(), nodes.end(), compare);

    for (int i = 1; i < nodes.size(); i++) {
        node curPos = nodes[0];
        while (true) {
            if (curPos.myVec[0] > nodes[i].myVec[0]) {
                if (curPos.left == NULL) {
                    curPos.left = nodes[i];
                    nodes[i].parent = curPos;
                    break;
                }
                else {
                    curPos = curPos.left;
                }
            }
            else {
                if (curPos.right == NULL) {
                    curPos.right = nodes[i];
                    nodes[i].parent = curPos;
                    break;
                }
                else {
                    curPos = curPos.right;
                }
            }
        }
    }
}

vector<int> Preorder(node _node) {
    vector<int> result;
    result.push_back(_node.nodeNum);
    vector<int> a;
    if (_node.left != NULL) {
        a = Preorder(_node.left);
        result.insert(result.end(), a.begin(), a.end());
    }
    if (_node.right != NULL) {
        a = Preorder(_node.right);
        result.insert(result.end(), a.begin(), a.end());
    }
    return result;
}
vector<int> Postorder(node _node) {
    vector<int> result;
    result.push_back(_node.nodeNum);
    vector<int> a;
    if (_node.left != NULL) {
        a = Preorder(_node.left);
        result.insert(result.end(), a.begin(), a.end());
    }
    if (_node.right != NULL) {
        a = Preorder(_node.right);
        result.insert(result.end(), a.begin(), a.end());
    }
    result.push_back(_node.nodeNum);
    return result;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<node> nodes = MakeNodes(nodeinfo);
    vector<node> tree = MakeTree(nodes);
    answer.push_back(Preorder(tree[0]));
    answer.push_back(Postorder(tree[0]));
    return answer;
}