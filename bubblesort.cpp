
#include<bits/stdc++.h>
using namespace std;
int bubble(float a[],int n);
void swap(float* a,float* b);
int main(int argc, char **argv){
    int i,n=0;
    float a[25],k,b,q,l;
    ifstream f1;
    ofstream f2;
    f1.open(argv[1]);
    f2.open("out.txt");
    while(f1>>k){
        a[n]=k;
        n++;
    }
    f1.close();
    bubble(a,n);
    for(i=0;i<n;i++){
        f2<<a[i]<<" ";
    }
    f2.close();
    return 0;
}
void swap(float* a,float* b) {
  float* tmp;
  tmp=a;
  a=b;
  b=tmp;
}
int bubble(float a[],int n){
    int i,j,w,e,r,t;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
