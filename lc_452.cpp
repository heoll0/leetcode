#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [] (vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
        );

        int n = points.size();
        int result = n;
        for(int i = 0; i < n; ++i){
            int max = points[i][1];
            while( max >= points[i+1][0] )
                {
                    --result;
                    ++i;
                    if(i+1 == n)
                        break;                
                }
        }
        return result;

    }
};

int main()
{
    Solution test;
    vector<vector<int>> a = {{1,2},{3,4},{5,6},{7,8}};
    test.findMinArrowShots(a);

    return 0;
}