/*first, find the ((m+n)/2)th element,
 then find the ((m+n)/2 + 1)th element if neccessary*/
#include <bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int half, left, right, middle;
        if (m < n) {
            std::swap(A, B);
            std::swap(m, n);
        }
        half = (m + n + 1) / 2 - 1;
        left = std::max(-1, half - n - 1);
        right = std::min(m, half + 1);
        while (left + 1 < right) {
            middle = (left + right) / 2;
            if (middle == half || A[middle] > B[half - middle - 1]) {
                if (middle == half - n || A[middle] < B[half - middle]) {  //A[middle] is at the half
                    return findMedianGivenHalf(A, m, middle, B, n);
                } else {
                    right = middle;
                }
            } else {
                left = middle;
            }
        }
        /*half is not in A, it is B[half - left]*/
        return findMedianGivenHalf(B, n, half - left - 1, A, m);
    }
    double findMedianGivenHalf(int A[], int m, int halfIndex, int B[], int n) {
        if ((m + n) % 2 == 1) {
            return A[halfIndex];
        } else {
            int another, half = (m + n) / 2 - 1;
            if (halfIndex == m - 1 || (half - halfIndex < n && A[halfIndex + 1] > B[half - halfIndex]))
                another = B[half - halfIndex];
            else
                another = A[halfIndex + 1];
            return (double)(A[halfIndex] + another) / 2.0;
        }
    }
};

int main(void) {
    Solution x;
    int A[] = {2}, B[] = {1};
    printf("%lf\n", x.findMedianSortedArrays(A, 0, B, 1));
    return 0;
}

