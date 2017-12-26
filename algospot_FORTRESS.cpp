/*
 
 algospot_FORTRESS
 
 */

// test cases
//2
//3
//5 5 15
//5 5 10
//5 5 5
//8
//21 15 20
//15 15 10
//13 12 5
//12 12 3
//19 19 2
//30 24 5
//32 10 7
//32 9 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    vector<TreeNode *> children;
};

int longest;
int n, y[100], x[100], radius[100];

int height(TreeNode * root) {
    vector<int> heights;
    
    for (int i = 0; i < root->children.size(); ++i) {
        heights.push_back(height(root->children[i]));
    }
    if (heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    
    if (heights.size() >= 2) {
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
    }
    return heights.back() + 1;
}

int solve(TreeNode * root) {
    longest = 0;
    int h = height(root);
    return max(longest, h);
}

int sqr(int x) {
    return x * x;
}

int sqrdist(int a, int b) {
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b) {
    // check if a encloses b.
    return radius[a] > radius[b] &&
    sqrdist(a, b) < sqr(radius[a]);
    // why radius[a] - radius[b]?
    // 중점 간의 차가 반지름 간의 차보다 작아야.
    //sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
    if (!encloses(parent, child)) return false;
    // check if it's the direct child of the parent.
    // no child node between them.
    for (int i = 0; i < n; ++i) {
        if (i != parent && i != child &&
            encloses(parent, i) && encloses(i, child)) {
            return false;
        }
    }
    return true;
}

TreeNode * getTree(int root) {
    // make tree with the root.
    
    TreeNode * ret = new TreeNode();
    for (int ch = 0; ch < n; ++ch) {
        if (isChild(root, ch)) {
            ret->children.push_back(getTree(ch));
        }
    }
    return ret;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n;
        
        for (int j = 0; j < n; ++j) {
            cin >> x[j] >> y[j] >> radius[j];
        }
        
        TreeNode * r = getTree(0);
        cout << solve(r) << endl;
    }
    
    return 0;
}










