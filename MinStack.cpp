struct Node {
    int data;
    Node* next;
};

class MinStack {
private:
    Node* last;
    Node* min;

public:
    MinStack() {
        last = nullptr;
        min = nullptr;
    }
    
    void push(int val) {
        Node* tmp = new Node();
        tmp->data = val;
        tmp->next = last;
        last = tmp;

        Node* m = new Node();
        m->data = val;
        m->next = min;

        if (min == nullptr || tmp->data <= min->data) {
            min = m;
        }
    }
    
    void pop() {
        Node* tmp = last;
        last = last->next;

        if (tmp->data == min->data) {
            Node* m = min;
            min = min->next;
            delete m;
        }

        delete tmp;
    }
    
    int top() {
        return last->data;
    }
    
    int getMin() {
        return min->data;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */