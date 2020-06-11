class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> remOrder;

        for(int i=0;i<stones.size();i++)
        remOrder.push(stones[i]);

        int x , y;
        while(remOrder.size()>1)
        {
            y = remOrder.top();
            remOrder.pop();

            x = remOrder.top();
            remOrder.pop();

            remOrder.push(y-x);
        }

        return remOrder.top();
    }
};
