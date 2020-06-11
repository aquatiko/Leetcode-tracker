int Solution::canCompleteCircuit(const vector<int> &a, const vector<int> &b) {
    int suma = 0;
    int sumb = 0;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        suma+=a[i];
        sumb+=b[i];
    }
    if(sumb>suma)
    return -1;
    int counter = 0;
    for(int i=0;i<n;)
    {   int gas = 0,j;
        for(j=0;j<n;j++)
        {
            gas+=a[(i+j)%n];
            if(gas < b[(i+j)%n])
            {
                i = (i+j+1)%n;
                break;
            }
            else
            gas -= b[(i+j)%n];
        }
        if(j==n)
        return i;
    }
    return n-1;
}

// The greedy intution of a O(n) approach is that if we start at least index(0th) and start checking and go till suppose an index
// kth, then we can resume our checking from that index only and need not start to check k-1th, k-2th, k-3th ..... 2nd.
