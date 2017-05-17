class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> forward(n, 0), backward(n, 0);

		int minSoFar = prices[0], maxSoFar = prices[n-1];
		for(int i = 1; i < n; ++i)
		{
			minSoFar = min(minSoFar, prices[i]);
			forward[i] = max(forward[i-1], prices[i]-minSoFar);

			maxSoFar = max(maxSoFar, prices[n-1-i]);
			backward[i] = max(backward[i-1], maxSoFar - prices[n-1-i]);
		}

		int res = INT_MIN;
		for (int i = 0; i < n; ++i)
			res = max(res, forward[i]+backward[i]);
		return res;
};
