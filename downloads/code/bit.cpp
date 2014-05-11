struct binary_it{
    int bit[MAX+1];
    int N;

    binary_it(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }

    int sum(int i){ // sum [1,i]
        int ret = 0;
        while(i){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }

    int sum(int i, int j){ // sum (i,j]
        return sum(j) - sum(i);
    }

    void add(int i, int x){
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
};
