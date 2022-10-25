bool cmp(PII p1, PII p2) {
	return (p1.second > p2.second);
}

void solve(int n, int dl[], int profit[]) {
	vector<PII> v(n,{0,0});
	
	int m = *max_element(profit, profit+n);

	for (int i = 0; i < n; ++i)
	{
		v[i].first = dl[i];
		v[i].second = profit[i];
	}

	sort(v.begin(), v.end(), cmp);
	
	bool alloted[n+1] = {false};
	int jobCount = 0;
	int total_profit = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = min(n,v[i].first); j > 0; --j) {
			if(!alloted[j]) {
				jobCount++;
				total_profit += v[i].second;
				alloted[j] = true;
				break;
			}
		}
	}

	cout<<jobCount<<" "<<total_profit<<endl;
}