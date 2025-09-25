// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
  
  static bool comp(pair<int,int>&a, pair<int,int>&b) {
    if(a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  }

  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int,int>> v;
    
    for(int i=0 ; i<ranges.size() ; i++) {
      int ele = ranges[i];
      if(ele == 0) continue; 
      int l = max(0, i-ele);
      int r = min(n, i+ele);
      v.push_back({l,r}); 
    } 

    sort(v.begin(), v.end(), comp);

    int taps = 0;
    int reach = 0;
    int i = 0;
    int farthest = 0;

    // greedy coverage with intervals
    while(reach < n) {
      while(i < v.size() && v[i].first <= reach) {
        farthest = max(farthest, v[i].second);
        i++;
      }
      if(farthest == reach) return -1; // stuck, can't extend
      taps++;
      reach = farthest;
    }

    return taps;
  }
};
