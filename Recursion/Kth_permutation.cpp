string getPermutation(int n, int k) {
    string res;
    vector<int> vec;
    
    int fact = 1;
    for(int i = 1; i < n; ++i) {
        fact *= i;
        vec.push_back(i);
    }
    
    vec.push_back(n);
    k--;
    
    while(true) {
        res += to_string(vec[k/fact]);
        vec.erase(vec.begin() + k/fact);
        
        if(vec.size() == 0) break;
        k = k%fact;
        fact /= vec.size();
    }
    
    return res;
}