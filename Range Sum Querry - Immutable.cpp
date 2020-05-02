static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class NumArray {
public:
    vector<int> reccSum;
    NumArray(vector<int>& nums) {
        if(nums.size()>0)
        {
            reccSum.push_back(nums[0]);
            for(int i=1;i<nums.size();i++)
                reccSum.push_back(reccSum[reccSum.size()-1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i==0)
            return reccSum[j];
        else
            return reccSum[j] - reccSum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
