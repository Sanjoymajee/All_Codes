vector<int> prime(10000000,1);
class Solution {
public:
    
    int countPrimes(int n) {
        for (int p = 2; p * p <= n; p++){
            if (prime[p] == 1)
                for (int i = p * p; i <= n; i += p){
                    prime[i] = 0;

                }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i])cnt++;
        }
        return cnt;
    }
};