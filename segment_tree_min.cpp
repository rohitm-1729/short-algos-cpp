#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define repp(i,a,b) for(i=a,i<b;i++)
typedef long long int lli;
void update(lli *a,lli *tree,lli start,lli last,lli tnode,lli pos,lli val){
    if(start==last){
        tree[tnode]=val;
        a[pos]=val;
    }
    else{
            lli m=start+(last-start)/2;
        if(start<=pos&&pos<=m)
            update(a,tree,start,m,2*tnode+1,pos,val);
        else
            update(a,tree,m+1,last,2*tnode+2,pos,val);
        tree[tnode]=min(tree[2*tnode+1],tree[2*tnode+2]);
    }
}
void buildtree(lli *a,lli *tree,lli start,lli last,lli tnode){
    if(start==last)
        tree[tnode]=a[start];
    else{
        lli m=start+(last-start)/2;
        buildtree(a,tree,start,m,2*tnode+1);
        buildtree(a,tree,m+1,last,2*tnode+2);
        tree[tnode]=min(tree[2*tnode+1],tree[2*tnode+2]);
    }
}
lli query(lli *tree,lli start,lli last,lli l,lli r,lli tnode){
    if(r<start||l>last)
        return LLONG_MAX;
    if(l<=start&&r>=last)
        return tree[tnode];
    lli m,p,q;
    m=start+(last-start)/2;
    p=query(tree,start,m,l,r,2*tnode+1);
    q=query(tree,m+1,last,l,r,2*tnode+2);
    //cout<<"*"<<min(p,q)<<" "<<p<<2*tnode+1<<" "<<q<<2*tnode+2<<endl;
    return min(p,q);
}
int main(){
    lli t,n,q,i,j,l,r,x;
    char ch;
    cin>>n>>q;
    lli a[n];
    lli nn=2*pow(2,lli(ceil(log2(n))))-1;
    lli tree[nn];
    rep(i,n)cin>>a[i];
    rep(i,nn)tree[i]=LLONG_MAX;
    //cout<<"nn="<<nn<<endl;
    buildtree(a,tree,0,n-1,0);

    //rep(i,nn)cout<<tree[i]<<endl;
    while(q--){
        cin>>ch>>l>>r;
        if(ch=='u'){
            update(a,tree,0,n-1,0,l-1,r);
        }
        else{
            cout<<query(tree,0,n-1,l-1,r-1,0)<<endl;
        }
    }
    return 0;
}
