void sortColors(vector<int>& arr) {
    // 0 to lo - 1 : Zero's
    // l to m - 1 : One's
    // m to hi : Unknown
    // h+1 to n-1 : Two's
    int lo = 0, m = 0, hi = arr.size()-1;
    
    while(m <= hi) {
        if(arr[m] == 0) 
            swap(arr[lo++],arr[m++]);
        
        else if(arr[m] == 1)
            m++;
        
        else if(arr[m] == 2)
            swap(arr[m],arr[hi--]);
    }
    
}