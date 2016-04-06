class MinStack {
    stack<int> stack1, stack2;
public:
    void push(int x) {
        stack1.push(x);
        if(stack2.empty()) {
            stack2.push(x);
        }
        else if(stack2.top()>=x) {
            stack2.push(x);
        }
    }

    void pop() {
        if(stack1.top()==stack2.top()) {
            stack2.pop();
        }
        stack1.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return stack2.top();
    }
};
/*
ʹ��O(1)���㷨�õ�ջ����С��Ԫ�ء�
����һ������ջ�ṹ������⡣ 
*/
