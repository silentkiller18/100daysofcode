class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
       q2.push(x); // push elements to q2
        while(!q1.empty()){ // push all the elements of q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        //swap queues names q1<-->q2
        queue<int> temp = q2;
        q2=q1;
        q1=temp;       
    }
    
    int pop() {
        if(q1.empty()) return 0;
        int x = q1.front();  
        q1.pop();
        return x;      
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();         
    }
    
    bool empty() {
        if(q1.empty()) return 1;
        else return 0 ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */