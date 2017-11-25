#include <iostream>
#include <string>
#include <stack>
using namespace std;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
////// BEGIN OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////

//Please use `stack` class only
class Queue {
public:
    
    /*
     * Description:
     * Time complexity:
     * Space complexity:
     */
    // st1 : for enqueue, st2 : for dequeue.
    stack<int> st1, st2;
    
    void enqueue(int v) {
        // TODO implement your codes to here.
        
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(v);
    }
    
    /*
     * Description:
     * Time complexity:
     * Space complexity:
     */
    int dequeue() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        
        // TODO implement your codes to here.
        int ret = st2.top();
        st2.pop();
        return ret;
    }
};

/////////////////////////////////////////////////////////////////////////
////// END OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[]) {
    Queue queue;
    string command;
    int count, value;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cin >> command;
        if (command == "ENQUEUE") {
            cin >> value;
            queue.enqueue(value);
        } else if (command == "DEQUEUE") {
            cout << queue.dequeue() << endl;
        }
    }
}


