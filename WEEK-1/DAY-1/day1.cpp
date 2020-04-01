/* Given a non-empty array of integers, every element appears twice except for one.
 Find that single one . note: Your algorithm should have a linear runtime complexity. 
  Could you implement it without using extra memory? */

#include<bits/stdc++.h>
using namespace std;
int n;

int find(int a[], int n){
   int res = a[0];
   for(int j=1 ;j<n;j++)
     res = res ^ a[j];
    return res;
}

int main(){
  int n;
  cout << "enter the array size";
  cin>>n;
  int a[n];
  cout<<"enter the array elements";
    for(int i=0;i<n;i++)
     cin>>a[i];
  cout<<"\n element occuring once is :"<<find(a , n);
}