vector<int> repeatedNumber(const vector<int> &A) {
    int xorr = 0;
    for(int i = 1; i <= A.size(); ++i) xorr ^= i;
    for(int i = 0; i < A.size(); ++i) xorr ^= A[i];

    int x = 0, y = 0;
    int lsb = xorr & ~(xorr-1);

    for(int i = 1; i <= A.size(); ++i) {
        if((i & lsb)) x^=i;
        else y^=i;
    }

    for(int i = 0; i < A.size(); ++i) {
        if((A[i] & lsb)) x^=A[i];
        else y^=A[i];
    }

    for(int i = 0; i < A.size(); i++) {
        if(A[i]==x) return {x,y};
    }

    return {y,x};
}