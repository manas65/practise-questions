class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>tempSt;
        while(!st.empty()){
            tempSt.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!tempSt.empty()){
            st.push(tempSt.top());
            tempSt.pop();
        }
        
    }
    
    int pop() {
        int val=st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */