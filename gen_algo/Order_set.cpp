// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using pbds = tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update>;

// less<int> if array elements are distinct, or
// less_equal<int> if duplicates are possible (but then handle counts carefully).

// TC -> O(n log n) , SC -> O(n); 

//  i < j ,  arr[i] > arr[j]  ; 

class Solution {
  public:

    int inversionCount(vector<int> &arr) {
      pbds os;
      
      int n = arr.size();
      vector<int>nums;
      int ans = 0 ; 
      
      for(int i=n-1; i>=0 ; i--) {
       ans+=os.order_of_key(arr[i]);
       os.insert(arr[i]);
      }
     
     return ans;    
    }
};

/*
In an ordered set (PBDS), 
*os.find_by_order(k) returns the k-th smallest element (0-indexed), and if k ≥ size, it returns end().
os.order_of_key(x) gives the count of elements strictly less than x, effectively representing the rank where x would be inserted.
Both operations run in O(log n) time, enabling efficient order-statistics queries.
*/