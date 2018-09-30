    //to print all subsets of set {1,2,3}
    #include<bits/stdc++.h>
    using namespace std;
    int n;
    vector<int> v;
    void backtracking(int k){
        if(k==n){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        else{
            backtracking(k+1);
            v.push_back(k);
            backtracking(k+1);
            v.pop_back();
        }
    }
    int main(){
       //ios_base::sync_with_stdio(false);
       //cin.tie(NULL);
       n=4;
       backtracking(1);

        return 0;
    }
