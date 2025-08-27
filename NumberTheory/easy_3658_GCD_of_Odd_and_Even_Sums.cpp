
// 3658. GCD of Odd and Even Sums
// https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/


//sumOdd = पहले n odd numbers का sum = n^2
//sumOdd = पहले n odd numbers का sum = 𝑛(𝑛+1 )
// n is common factor in both
// gcd(n^2,n(n+1))= n⋅gcd(n,n+1) // e two consecutive numbers are always coprime. For example, 4 and 5, 10 and 11, 99 and 100… their only common divisor is 1
//final  gcd(n^2, n(n+1))  = n⋅1 =n


class Solution {
public:
    int gcdOfOddAndEvenSums(int n) {
        // Math derivation:
        // sumOdd = n^2
        // sumEven = n(n+1)
        // gcd(sumOdd, sumEven) = n
        return n;
    }
};
