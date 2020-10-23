#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector < pair <int, int> > ret;
   static bool cmp(pair <int, int>& a, pair <int, int>& b){
      return a.first == b.first ? a.second < b.second : a.first < b.first;
   }
   int getTurn(int n){
      int ret = 0;
      while(n != 1){
         if(n & 1){
            n = n * 3 + 1;
         }
         else n >>= 1;
            ret ++;
      }
      return ret;
   }
   int getKth(int lo, int hi, int k) {
      for(int i = lo; i <= hi; i++){
         pair <int, int> temp;
         temp.first = getTurn(i);
         temp.second = i;
         ret.push_back(temp);
      }
      sort(ret.begin(), ret.end(), cmp);
      return ret[k - 1].second;
   }
};
main(){
   Solution ob;
   cout << (ob.getKth(12, 15, 2));
}