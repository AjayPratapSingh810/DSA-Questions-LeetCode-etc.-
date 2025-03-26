class Solution {
public:
    const int MOD = 1000000007;

    long long modPow(long long x, long long n) {
        long long result = 1;
        x = x % MOD;  // Ensure x is within the modulo range
        
        while (n > 0) {
            if (n % 2 == 1) {  // If n is odd
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;  // Square x
            n /= 2;  // Reduce exponent by half
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPlaces = (n + 1) / 2;
        long long oddPlaces = n / 2;

        long long a = modPow(5, evenPlaces);
        long long b = modPow(4, oddPlaces);

        return (a * b) % MOD;
    }
};
