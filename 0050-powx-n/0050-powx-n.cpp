class Solution {
public:
    double power(double x, long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0)
            return power(x * x, n / 2);
        else
            return x * power(x * x, (n - 1) / 2);
    }
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
            long n1 = (long)n;
            n1 = -n1;
            return power(x , n1);
        }
        else
        {
            return power(x, long(n));
        }
    }
};