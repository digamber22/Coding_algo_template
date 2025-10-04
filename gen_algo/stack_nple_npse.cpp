//  https://leetcode.com/problems/sum-of-subarray-ranges/

 // TC,SC -> O(N);
 
class Solution {
public:
#define ll long long 
    long long subArrayRanges(vector<int>& a) {
     int n = a.size();
     stack<int> st1, st2, st3, st4;
    vector<int> nse(n), nle(n), pse(n), ple(n);

    // prevouse smallest element ;
    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && a[st1.top()] >= a[i])
        {
            st1.pop();
        }
        pse[i] = st1.empty() ? -1 : st1.top();
        st1.push(i);
    }

    // next smallest element ;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st2.empty() && a[st2.top()] > a[i])
        {
            st2.pop();
        }
        nse[i] = st2.empty() ? n : st2.top();
        st2.push(i);
    }

    // prevous largest element
    for (int i = 0; i < n; i++)
    {
        while (!st3.empty() && a[st3.top()] <= a[i])
        {
            st3.pop();
        }
        ple[i] = st3.empty() ? -1 : st3.top();
        st3.push(i);
    }

    // next largest element ;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st4.empty() && a[st4.top()] < a[i])
        {
            st4.pop();
        }
        nle[i] = st4.empty() ? n : st4.top();
        st4.push(i);
    }

    ll smins = 0, smaxi = 0;
    for (int i = 0; i < n; i++)
    {
        ll l = i - pse[i];
        ll r = nse[i] - i;
        smins = (smins + a[i] * l * r);
    }

    for (int i = 0; i < n; i++)
    {
        ll l = i - ple[i];
        ll r = nle[i] - i;
        smaxi = (smaxi + a[i] * l * r);
    }

   return  (smaxi - smins);

    }
};