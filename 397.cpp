#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <functional> 

using namespace std;

/*
397. Integer Replacement
https://leetcode.com/problems/integer-replacement/#/description

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

*/
void printv(vector<int> v)
{
	for (auto i : v) printf("%d ", i);
	printf("\n");
}

int solver1(int n)
{	
	vector<int> v(n+2, -1);
	v[1] = 0; v[2] = 1;

	for(int i = 2; i < v.size()+1; i++)
	{
		if (i%2 == 1) v[i] = min(v[i+1], v[i-1])+1;

		int j = i;
		while(j*2 < n+2 && v[j*2] == -1)
		{
			j *= 2;
			v[j] = v[j/2]+1;
		}

		// printf("i %d\n", i);
		// printv(v);
	}

	return v[n];
}

int solver2(int n)
{
	if (n == 1) return 0;
	if (n == INT_MAX) return solver2(n-1);

	if (n%2 == 0) 
		return solver2(n/2)+1;
	else 
		return min(solver2(n-1), solver2(n+1)) +1;
}

int main ()
{
	int n = 2147483647;
	printf("n %d, n+1 %d\n", n, n+1);

	// printf("Final result %d\n", solver1(n));
	printf("Final result %d\n", solver2(n));

  	return 0;
}