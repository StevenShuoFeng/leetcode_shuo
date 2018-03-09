#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R);
    int count(int l, int r, queue<int>& q);
};

int main()
{
    vector<int> A{2,1, 2,4,3};

    int L = 2, R = 3;
    
    Solution s;
    int cnt = s.numSubarrayBoundedMax(A, L, R);


    printf("Final count %d\n", cnt);
    return 0;
}

int Solution::numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int res = 0;
    
    int str = 0;
    queue<int> gm; // index of good values that are in range of [L, R], that can be used as max

    for (int k = 0; k < A.size(); ++k)
    {
        if (A[k] <= R)
        {
            if (A[k] >= L)
                gm.push(k);
        }
        else
        {
            res += count(str, k-1, gm);
            str = k+1;
        }

        if (k == A.size() -1 && !gm.empty())
            res += count(str, k, gm);
    }
    
    return res;
}

int Solution::count(int l, int r, queue<int>& q)
{
    int res = 0;

    queue<int> x = q;
    while(!x.empty()) {printf("%d\n", x.front()); x.pop();}

    for (int k = l; k <= r; ++k)
    {
        while(!q.empty() && k > q.front()) q.pop();
        if (q.empty()) break;

        res += r - q.front() + 1;
    }

    printf("%d - %d cnt %d \n", l, r, res);

    return res;
}