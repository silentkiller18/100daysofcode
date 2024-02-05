class MyQueue {
public:
stack<int>s1;
stack<int>s2;
MyQueue() {
    
}

void push(int x) {
    s1.push(x);
}

int pop() {
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int n=s2.top();
    s2.pop();
    
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
            
    }
    return n;
}

int peek() {
    int n;
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    n=s2.top();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return n;
    
}

bool empty() {
    if(s1.size()==0)
        return true;
    return false;
}
};