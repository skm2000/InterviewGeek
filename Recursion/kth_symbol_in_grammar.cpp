// https://leetcode.com/problems/k-th-symbol-in-grammar/
// base : the smallest condition for which the function is valid
// hypothesis: the condition which will be recursive or recursion body
// induction: the last step after all recursion has been done

#include<bits/stdc++.h>
using namespace std;

// based on observation skills

class Solution {
public:
    int kthGrammar(int N, int K) {
        // base condition
        if(N==1 || K==1) {
            return 0;
        }
        // hypothesis + induction(the not symbol part)
        int mid = pow(2,N-1)/2;
        if(K <= mid) {
            return kthGrammar(N-1,K);
        }
        else {
            return !kthGrammar(N-1,K-mid);
        }
    }
};