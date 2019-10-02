#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int MAX;

/**
 * Count Sort.
 *
 * Sorts a vector using a counting
 * approach.
 *
 * It can only applied in vectors
 * which integers are non-negative
 * up to MAX.
 *
 * Time Complexity: O(MAX+n).
 * Where n is the size of the graph.
 */
inline void count_sort(vector<int> &v, bool inc = true){
    int n = v.size();
    int cnt[MAX] = {};
    for(int i=0; i<n; ++i)
        cnt[v[i]]++;

    int k = (inc? 0 : v.size()-1);
    for(int i=0; i<MAX; ++i){
        for(int j=0; j<cnt[i]; ++j, k += (inc? 1 : -1))
            v[k] = i;
    }
}

/**
 * Erdos Gallai.
 *
 * Provides a graph realization check,
 * based on its vertices degrees.
 *
 * Time Complexity: O(n).
 * Where n is the size of the graph.
 */
inline bool erdos(vector<int> &dseq){
    // dseq = degree sequence.
    int n = dseq.size();

    count_sort(dseq, false);
    if(dseq[0] >= n)
        return false;
    // if it's not possible to use count-sort
    // use the O(n*log(n)) sort:
    // sort(dseq.rbegin(), dseq.rend());

    vector<long long> psum(n);
    for(int i=0; i<n; ++i){
        psum[i] = dseq[i];
        if(i)
            psum[i] += psum[i-1];
    }
    if(psum[n-1]%2)
        return false;

    for(int k=1, i=n-1; k<=n; ++k){
        while(i>=0 and dseq[i] < k)
            i--;

        long long minsum = (long long)k*max(0, i+1-k) + (psum[n-1] - psum[max(k-1, i)]);
        if(psum[k-1] > (long long)k*(k - 1) + minsum)
            return false;
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        MAX = 0;

        vector<int> v(n);
        for(int i=0; i<n; ++i){
            scanf("%d", &v[i]);
            MAX = max(v[i]+1, MAX);
        }
        printf("%s\n", (erdos(v)? "possivel" : "impossivel"));
    }
    return 0;
}
