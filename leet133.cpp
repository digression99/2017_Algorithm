//
// map -> keeps element ordered by key.
// unordered_map -> literally, keeps element unordered, hence less lookup time.
//
//Don't forget the map's keep their elements ordered. If you can't give up that, obviously you can't use an unordered_map.
//
//Something else to keep in mind is that unordered_map's generally use more memory. A map just has a few house-keeping pointers then memory for each object. Contrarily, unordered_map's have a big array (these can get quite big in some implementations) and then additional memory for each object. If you need to be memory-aware, a map should prove better, because it lacks the large array.
//
//So, if you need pure lookup-retrieval, I'd say an unordered_map is the way to go. But there are always trade-offs, and if you can't afford them, then you can't use it.
//
//Just from personal experience, I found an enormous improvement in performance (measured, of course) when using an unordered_map instead of a map in a main entity look-up table.
//
//On the other hand, I found it was much slower at repeatedly inserting and removing elements. It's great for a relatively static collection of elements, but if you're doing tons of insertions and deletions the hashing + bucketing seems to add up. (Note, this was over many iterations.)



#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


//// not mine. dfs.
//class Solution {
//public:
//    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//        if (node==NULL) return NULL;
//        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> created;
//        return helper(node,created);
//    }
//    UndirectedGraphNode* helper(UndirectedGraphNode* node,unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& created){
//        UndirectedGraphNode* cur=new UndirectedGraphNode(node->label);
//        created[node]=cur;
//        for (auto nd:node->neighbors){
//            if (created.count(nd)==0) cur->neighbors.push_back(helper(nd,created));
//            else cur->neighbors.push_back(created[nd]);
//        }
//        return cur;
//    }
//};

// mine. bfs.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        
        unordered_map<int, UndirectedGraphNode *> hash;
        deque<UndirectedGraphNode *> q;
        unordered_map<int, bool> visited;
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        
        int tempSize = 0;
        UndirectedGraphNode * tempNode = nullptr;
        UndirectedGraphNode * nowRoot = root;
        
        hash[node->label] = root;
        visited[node->label] = true;
        
        q.push_back(node);
        
        while (!q.empty())
        {
            tempSize = (int)q.size();
            
            for (int i = 0; i < tempSize; ++i)
            {
                tempNode = q.front();
                q.pop_front();
                nowRoot = hash[tempNode->label];
                
                for (int j = 0; j < tempNode->neighbors.size(); ++j)
                {
                    int nowLabel = tempNode->neighbors[j]->label;
                    
                    if (hash.count(nowLabel) == 0)
                    //if (hash.find(nowLabel) == hash.end()) // node doesn't exists.
                    {
                        hash[nowLabel] = new UndirectedGraphNode(nowLabel);
                        visited[nowLabel] = false;
                    }
                    nowRoot->neighbors.push_back(hash[nowLabel]);
                    if (!visited[nowLabel])
                    {
                        visited[nowLabel] = true;
                        q.push_back(tempNode->neighbors[j]);
                    }
                }
            }
        }
        
        return root;
    }
};

// test code, runner
int main()
{
    UndirectedGraphNode n1(0);
    UndirectedGraphNode n2(1);
    UndirectedGraphNode n3(2);
    map<int, UndirectedGraphNode *> hash;
    
    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n1);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n3);
    //n1.neighbors.push_back(
    
    Solution s;
    UndirectedGraphNode * g = s.cloneGraph(&n1);
    deque<UndirectedGraphNode *> dq;
    
    dq.push_back(g);
    hash[g->label] = g;
    
    while (!dq.empty())
    {
        int tSize = (int)dq.size();
        
        for (int i = 0; i < tSize; ++i)
        {
            UndirectedGraphNode * t = dq.front();
            dq.pop_front();
            
            cout << "nowVisit : " << t->label << " " << endl;
            
            for (int j = 0; j < t->neighbors.size(); ++j)
            {
                int tLabel = t->neighbors[j]->label;
                auto itr = hash.find(tLabel);
                
                cout << tLabel << " ";
                
                if (itr == hash.end())
                { // it's the first time visiting.
                    hash[tLabel] = t->neighbors[j];
                    dq.push_back(t->neighbors[j]);
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
