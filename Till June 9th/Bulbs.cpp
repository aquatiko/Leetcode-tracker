int Solution::bulbs(vector<int> &a) {
    int count = 0;
    for(int i=0;i<a.size();i++)
    {
        if((a[i]+count)%2 == 0)
            count++;
    }
    return count;
}
