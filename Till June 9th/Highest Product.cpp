int Solution::maxp3(vector<int> &a) {
    sort(a.begin(),a.end());
    int n = a.size();
    if(a.size()>=3)
    {
        int p1 = a[n-1]*a[n-2]*a[n-3],p2;
        if(a[0]<0 && a[1]<0)
        p2 = a[n-1]*a[0]*a[1];
        else
        p2 = INT_MIN;
        return max(p1,p2);
    }
    return 0;
}
