/*
    Author: Farhad
    ID: 2010
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 205;
int dp[MAX][MAX];
void initialization(int gap_penalty,string A,string B){
    int seq1_length = A.size();
    int seq2_length = B.size();
    for(int i=1;i<=seq1_length;i++){
        dp[i][0]=i*gap_penalty;
    }
    for(int i=1;i<=seq2_length;i++){
        dp[0][i]=i*gap_penalty;
    }
}
void solve(string A,string B,int gap_penalty,int match_score,int mismatch_score){

    int seq1_length = A.size();
    int seq2_length = B.size();

    for(int i=1;i<=seq1_length;i++){
        for(int j=1;j<=seq2_length;j++){
                if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1] + match_score;
                else {
                    dp[i][j]= max({ mismatch_score + dp[i-1][j-1] ,
                                  gap_penalty+dp[i-1][j],
                                  gap_penalty+dp[i][j-1]});
                }
        }
    }
}
void print(string A,string B){
    int seq1_length = A.size();
    int seq2_length = B.size();

    cout<<"\n\nFinal Scoring Matrix:\n\n";
    cout<<"\t\t";
    for(int i=0;i<seq2_length;i++)cout<<right<<setw(5)<<B[i]<<"\t";
    cout<<endl;
    for(int i=0;i<=seq1_length;i++){
        if(i)cout<<A[i-1]<<"\t";
        else cout<<"\t";
        for(int j=0;j<=seq2_length;j++){
            cout<<right<<setw(5)<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main (){
    int gap_penalty , match_score , mismatch_score;
    cout<<"Enter the match score: ";
    cin >> match_score;
    cout<<"Enter the mismatch score: ";
    cin >> mismatch_score;
    cout<<"Enter the gap penalty: ";
    cin >> gap_penalty;
    freopen("seq1.txt","r",stdin);
    string A,B;
    cin >> A;
    fclose(stdin);
    freopen("seq2.txt","r",stdin);
    cin >> B;
    fclose(stdin);

    initialization(gap_penalty , A , B);
    solve(A , B , gap_penalty , match_score , mismatch_score);
    print(A , B);
    return 0;
}
