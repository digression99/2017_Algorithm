//
// algospot_traversal
// inorder, preorder, postorder
//
//
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int> & v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

vector<int> & printPostOrder(const vector<int> & preorder, const vector<int> & inorder, vector<int> & res) {
    const int N = (int)preorder.size();
    if (preorder.empty()) return res;
    const int root = preorder[0];
    const int L = int(find(inorder.begin(), inorder.end(), root) - inorder.begin());
    //const int R = N - 1 - L;
    
    // left
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L), res);
    // right
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N), res);
    //cout << root << ' ';
    res.push_back(root);
    return res;
}

vector<int> inputVec1 = {
    1
}; // test case num

vector<int> inputVec2 = {
    7
}; // N

vector<vector<int>> inputVec3 = {
    {27, 16, 9, 12, 54, 36, 72}
}; // preorder.

vector<vector<int>> inputVec4 = {
    {9, 12, 16, 27, 36, 54, 72}
}; // inorder.

vector<vector<int>> resVec = {
    {12, 9, 16, 36, 72, 54, 27}
};


void test(vector<int> & iv1, vector<int> & iv2,
          vector<vector<int>> & iv3,
          vector<vector<int>> & iv4,
          vector<vector<int>> & res,
          function<vector<int> &(const vector<int> &, const vector<int> &, vector<int> &)> f) {
    cout << "TEST START" << endl;
    for_each(iv1.begin(), iv1.end(), [&](int tc) {
        cout << "TC : " << tc << endl;
        
        auto ivIt1 = iv2.begin();
        auto ivIt2 = iv3.begin();
        auto ivIt3 = iv4.begin();
        auto resIt = res.begin();
        vector<int> res;
        
        while (ivIt1++ != iv2.end()) {
            if (f(*ivIt2++, *ivIt3++, res) == *resIt++) break;
        }
        //while (ivIt1++ != iv2.end() && f(*ivIt2++, *ivIt3++, res) == *resIt++) ;
        
        if (ivIt1 == iv2.end()) cout << "TEST FINISHED" << endl;
        else {
            cout << "TEST ERROR IN : " << ivIt1 - iv2.begin() - 1 << " TH CASE." << endl;
            return;
        }
    });
}

int main() {
    test(inputVec1, inputVec2, inputVec3, inputVec4, resVec, printPostOrder);
    
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> v3 = {1, 2, 3, 4, 6};
    
    cout << (v1 == v2) << endl;
    cout << (v1 == v3) << endl;
    
    return 0;
}

