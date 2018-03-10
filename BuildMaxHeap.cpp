#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(float* a,float* b) {
  float* temp;
  temp=a;
  a=b;
  b=temp;
}
void heapify(float a[],int n,int i) {
int l=(2*i)+1;
int r=(2*i)+2;
//largest is the index of the largest element
int largest=i;

if(l<n && a[l]>a[largest])
{
  largest=l;
}
if (r<n && a[r]>a[largest]) {
  largest=r;
}
if (largest!=i) {
swap(a[i],a[largest]);
heapify(a,n,largest);
}
}
void build_max_heap(float a[],int n);
int main(int argc, char **argv){
    int i,n=0;
    float a[25],k;
    ifstream f1;
    ofstream f2;
    f1.open(argv[1]);
    f2.open("out.txt");
    while(f1>>k){
        a[n]=k;
        n++;
    }
    f1.close();
    build_max_heap(a,n);
    for(i=0;i<n;i++){
        f2<<a[i]<<" ";
    }
    f2.close();
    return 0;
}
void build_max_heap(float a[],int n) {
for (int i = n/2-1; i >=0; i--) {
  heapify(a,n,i);
}
}
