class MyQueue {
public:
    stack<int> mainStack;
    stack<int> reverseStack;
    MyQueue() {

    }
    
    void push(int x) {
        if(!mainStack.empty()){
            mainStack.push(x);
        }
        else{
            while (!reverseStack.empty()){
                mainStack.push(reverseStack.top());
                reverseStack.pop();
            }
            mainStack.push(x);
        }
    }
    
    int pop() {
        int out;
        if (mainStack.empty()){
            out = reverseStack.top();
            reverseStack.pop();
        }
        else{
            while(!mainStack.empty()){
                reverseStack.push(mainStack.top());
                mainStack.pop();
            }
            out = reverseStack.top();
            reverseStack.pop();
        }
        return out;
    }
    
    int peek() {
        if(mainStack.empty()){
            return reverseStack.top();
        }
        else{
             while(!mainStack.empty()){
                reverseStack.push(mainStack.top());
                mainStack.pop();
            }
            return reverseStack.top();
        }
    }
    
    bool empty() {
        if (mainStack.empty() && reverseStack.empty()){
            return true;
        }
        return false;
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