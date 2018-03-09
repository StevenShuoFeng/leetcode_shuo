#include <string>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        m.clear();

        for (int k = 0; k < S.size(); ++k)
        {
        	m[S[k]].push(k);
        }

        int res = 0; 

        for (string w : words)
        {
        	if (ifSubstring(w))
        		res++;
        }

        return res;
    }

    bool ifSubstring(string w)
    {
    	printf("checking string %s\n", w.c_str());
    	map<char, queue<int>> dic = m;

    	int ind = -1;

    	for (char c : w)
    	{
    		if (dic.find(c) == dic.end()) return false; // char not in orig sequence
    		if (dic[c].empty()) return false; // no more this letter after

    		if (dic[c].back() < ind) return false; // cannot construct next letter from orig sequence

    		while(dic[c].front() < ind) 
    			dic[c].pop();

    		ind = dic[c].front(); 
    		dic[c].pop();

    		printf("%d ", ind);
     	}

     	printf("Yes, sub-string \n");
     	return true;
    }

    map<char, queue<int>> m;

};

int main()
{
	Solution s;

	string S = "abcdef";

	vector<string> words = {,"a", "bb", "acd", "ace"};

	int res = s.numMatchingSubseq(S, words);

	printf("\nfinal count: %d\n", res);

}