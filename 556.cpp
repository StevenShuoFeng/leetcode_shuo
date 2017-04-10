#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

/*
556. Next Greater Element III
https://leetcode.com/problems/next-greater-element-iii/#/description

Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1

*/
// ---------------------------------------------------
// ---------------------------------------------------

void printV(const vector<int>& v)
{
	for (auto i : v) printf("%d ", i);
    printf("\n");
}

class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string ns = to_string(n);
        
        vector<int> v;
        for (auto c : ns) v.push_back(c-'0');
        
    	int a = nextPermutation(v);
        printV(v);
        
        string sout = "";
        for (auto i : v) sout += (i + '0');
        
        if (a == 0 && stol(sout) <= INT_MAX && stol(sout) >= INT_MIN)
            return stoi(sout);
        else 
            return -1;
    }

    int nextPermutation(vector<int>& v)
    {
    	const int N = v.size();

    	int l = -1;
    	for (int i = N-2; i >= 0; --i)
    	{
    		if (v[i] < v[i+1]) {l = i; break;}
    	}

    	if (l == -1) return -1; // all desending
    	
    	// flip last pair 
    	if (l == N-2) 
    	{
    		swap(v[N-1], v[N-2]); 
    		return 0;
    	}

    	sort(v.begin()+l+1, v.end());
    	for (int i = l+1; i < N; ++i)
    	{
    		if (v[i] > v[l])
    		{
    			swap((v[i] > v[l]));
    			break;
    		}
    	}
    	sort(v.begin()+l+1, v.end());

    	return 0;
    }
};

int main()
{
	Solution s;

	int n = 1234;
	s.nextGreaterElement(n);

	return 0;
}