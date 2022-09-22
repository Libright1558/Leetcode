class Solution {
    int arr[31];
public:
    Solution() {
        arr[0] = 0;
        arr[1] = 1;
    }
    int fib(int n) {
        if(n > 1) {
            for(int i = 2; i <= n; i++) {
                arr[i] = arr[i-1] + arr[i-2];
            }
        }
        return arr[n];
    }
};
