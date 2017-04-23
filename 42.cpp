/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/#/description

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/


class Solution {
public:
    int trap(vector<int>& v) {
        const int N = v.size();
        
        int sum = 0;
        
        for (int l = 0; l < N-1; ++l)
        {
            if (v[l] <= v[l+1])
                continue;
                
            int r = l+1;
            int height = v[l];
            while(height > 0)
            {
                if (v[r] >= height)
                {
                    sum += count(v, l, r);
                    l = r-1;
                    break;
                }
                
                
                if (r < N-1)
                    ++r;
                else
                {
                    r = l+1; --height;
                }
            }
        }
        
        return sum;
    }
    
    int count(const vector<int>& v, int l, int r)
    {
        int h = min(v[l], v[r]);
        int out = 0;
        for (int i = l; i <= r; ++i)
            if (v[i] < h)
            {
                out += h-v[i];
            }
            
        return out;
    }
};