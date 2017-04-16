#include <vector>
#include <string>

using namespace std;

typedef long long LL;
long kRoundOff = stol("1000000007");

class Solution {
public:
    int checkRecord(int n) {
        vector<LL> C = {1, 2, 4};
        vector<LL> A = {0, 1, 4};
        
        if (n < 3) return A[n]+C[n];
        
        int i = 2;
        while(i < n)
        {
            ++i;
            C.push_back(C[0]+C[1]+C[2]);
            A.push_back(A[0]+A[1]+A[2] + C.back());
            C.erase(C.begin()); A.erase(A.begin());
            
            if (C.back() > kRoundOff) C.back() %= kRoundOff;
            if (A.back() > kRoundOff) A.back() %= kRoundOff;
            
            // printf("C[%d] %lld, A[%d] %lld",i, C.back(), i, A.back()); cout << endl;
        }
        
        return (A.back()+C.back())%kRoundOff;
    }
};

int main()
{
    int n = 200;
    Solution s;
    
    printf("Ans: %d\n", s.checkRecord(n));

    return 0;
}