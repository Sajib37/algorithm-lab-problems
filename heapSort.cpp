#include <bits/stdc++.h>
using namespace std;
void print_heap(vector <int> v){
   for(int val : v) cout<<val<<" ";
   cout<<endl;
}
void insert_maxHeap(vector<int>& v, int x){
   v.push_back(x);
   int cur_idx = v.size()-1;
   while(cur_idx != 0){
      int par_idx = (cur_idx -1)/2;
      if(v[par_idx]< v[cur_idx]) /* max be root*/
         swap(v[cur_idx], v[par_idx]);
      else break;
      cur_idx=par_idx;
   }
}

// delete ROOT, 
// for this 
void delete_heap(vector <int>& v, vector <int>& v2){
   // 1. replace root by lastNode
   v2.push_back(v[0]);
   v[0]=v[v.size()-1];
   v.pop_back();
   // 2. positioned newROOt
   int cur = 0;
   int last = v.size()-1;
   while(true){
      int left = cur*2 +1;
      int right = cur*2 +2;
      if(left<=last && right<=last){
         if(v[left]>=v[right] && v[left]> v[cur]){
            swap(v[left], v[cur]);
            cur=left;
         }
         else if(v[right]>=v[left] && v[right]> v[cur]){
            swap(v[right], v[cur]);
            cur=right;

         }
         else break;
      }
      else if(left<=last){
         if(v[left]>v[cur]){
            swap(v[left], v[cur]);
            cur=left;
         }
         else break;
      }
      else break;
   }
}

int main(){
   vector <int> v;
   vector <int> v2;
   int n; cin>>n;
   for(int i=0; i<n; i++){
      int x; cin>>x;
      insert_maxHeap(v, x);
   }
   cout<<"maxHeap : "; print_heap(v);
   for(int i=0; i<n; i++)delete_heap(v, v2);
   cout<<"sorted : "; print_heap(v2);
   return 0;
}