bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>> arr;
    for(int i = 0; i < n; ++i) arr.push_back({start[i],end[i]});
    sort(arr.begin(),arr.end(),cmp);
    
    int idx = 0;
    int count = 1;
    
    for(int i = 1; i < n; ++i) {
        if(arr[i].first > arr[idx].second) {
            count++;
            idx = i;
        } 
    }
    
    
    return count;
}