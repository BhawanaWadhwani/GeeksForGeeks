void findMin(int V, int den[], int n)
{
	sort(deno, deno + n);

	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

//IMPORTANT
// The above approach may not work for all denominations. For example, it doesn’t work for denominations {9, 6, 5, 1} and V = 11. The above approach would print 9, 1 and 1. But we can use 2 denominations 5 and 6. 
// For general input, below dynamic programming approach can be used: 
