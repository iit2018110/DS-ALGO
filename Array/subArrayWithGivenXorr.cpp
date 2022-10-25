int Solution::solve(vector<int> &vec, int B) {
    unordered_map<int,int> ump; ump[0] = 1;
    int xorr = 0, count = 0;
    for(int i = 0; i < vec.size(); ++i) {
        xorr ^= vec[i];
        count += ump[xorr^B];
        ump[xorr]++;
    }

    return count;
}