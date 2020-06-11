vector<int> Solution::solve(int a, int b, int c, int k) {
    vector<int> ans;
    ans.push_back(1);
    int idxa = 0, idxb = 0, idxc = 0;

    while(ans.size()!=k+1)
    {
        int next = min(ans[idxa]*a, min(ans[idxb]*b, ans[idxc]*c));
        if(next == ans[idxa]*a)
        idxa++;
        else if(next == ans[idxb]*b)
        idxb++;
        else
        idxc++;
        if(ans[ans.size()-1]<next)
        ans.push_back(next);
    }
    vector<int> res;
    for(int i=1;i<=k;i++)
    res.push_back(ans[i]);
    return res;
}

// jsut a genralization of ugly numbers problem
