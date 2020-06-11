class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> holder;
    MinStack() {
    }

    void push(int x) {
        if(holder.size()==0)
            holder.push({x,x});
        else
        {
            if(holder.top().second < x)
                holder.push({x,holder.top().second});
            else
                holder.push({x,x});
        }
    }

    void pop() {
        holder.pop();
    }

    int top() {
        return holder.top().dirst;
    }

    int getMin() {

        return holder.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
