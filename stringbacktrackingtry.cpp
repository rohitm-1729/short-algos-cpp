    //to print all substring of length 3 (all permutations) of a given string
    #include<bits/stdc++.h>
    using namespace std;

    int n=6;
    string s="abcdef";
    vector<char> v;
    int l=3;
    void backtracking(int k){
        if(k>n){
            return ;
        }
        if(v.size()==l){
            sort(v.begin(),v.end());
            do{
                for(int i=0;i<v.size();i++){
                    cout<<v[i];
                }
                cout<<endl;
            }while(next_permutation(v.begin(),v.end()));
        }
        else{
            backtracking(k+1);
            v.push_back(s[k]);
            backtracking(k+1);
            v.pop_back();
        }
    }
    int main(){
       //ios_base::sync_with_stdio(false);
       //cin.tie(NULL);
       backtracking(0);

        return 0;
    }
