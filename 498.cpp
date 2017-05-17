#include <cstdio>
#include <vector>

// https://leetcode.com/problems/diagonal-traverse/#/description

using namespace std;

void printv(vector<int> v)
{
	for(int k : v) printf("%d, ", k);
	printf("\n");
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int M = matrix.size(); if (M == 0) return res;
        int N = matrix[0].size(); if  (N == 0) return res;
        
        if (M == 1) return matrix[0];
        if (N == 1) {for (int i = 0; i < M; ++i) res.push_back(matrix[i][0]); return res;}

        vector<vector<int>> dirsBound = {{0, 1}, {1, 0}}; // right, down
        vector<vector<int>> dirsDiag = {{1, -1} , {-1, 1}}; // diag_left_down, diag_right_up
    	vector<int> dirB, dirD;

        int r = 0, c = 0;
        while(r+c < M+N-2)
        {
        	res.push_back(matrix[r][c]);

        	if (r == 0 || c == N-1)
        	{
        		dirD = dirsDiag[0];

	        	if (r == 0) // at top, move right
	        		dirB = dirsBound[0];
	        	if (c == N-1) // at right, move down
	        		dirB = dirsBound[1];

	        	r += dirB[0]; c += dirB[1]; res.push_back(matrix[r][c]);
	        	if (r == M-1 && c == N-1) return res;

				// printf("Top or right: r %d c %d \n", r, c);

	        }

        	if (c == 0 || r == M-1)
        	{
        		dirD = dirsDiag[1];

	        	if (c == 0)
	        		dirB = dirsBound[1];
	        	if (r == M-1)
	        		dirB = dirsBound[0];

	        	r += dirB[0]; c += dirB[1]; res.push_back(matrix[r][c]);
	        	if (r == M-1 && c == N-1) return res;

				// printf("Left or botm: r %d c %d \n", r, c);
			}

    		r += dirD[0]; c += dirD[1];
			// printf("r %d c %d \n", r, c);
        }

        return res;
    }
};

int main()
{
	vector<vector<int>> d = {{1,2,3,4,5,6,7,8,9}, {1,2,3,4,5,6,7,8,9}};

	Solution s;
	vector<int> res = s.findDiagonalOrder(d);
	printv(res);
	
	return 0;
}