/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    vector<int> dimensions;
    int ans, netLastColumn;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        dimensions = binaryMatrix.dimensions();
        ans = -1;
        netLastColumn = dimensions[1]-1;

        for(int i=0;i<dimensions[0];i++)
            binarySearch(i, binaryMatrix);

        return ans;
    }

    void binarySearch(int row, BinaryMatrix &binaryMatrix)
    {
        int start = 0, end = netLastColumn;

        while(start<=end)
        {
            int midPos = (start+end)/2;
            int midEle = binaryMatrix.get(row, midPos);

            if(midEle == 0)
                start = midPos+1;
            else
            {
                if(midPos<=netLastColumn)
                {
                    ans = midPos;
                    netLastColumn = midPos;
                }

                end = midPos-1;
            }
        }
    }
};

//Interesting modification of binary search. Fun to solve question.
