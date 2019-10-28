/*
    Problem link: http://webpages.ursinus.edu/adhawan/os/hw6s.txt
    Author: Farhad
    Date  : 28.10.19
*/
#include<bits/stdc++.h>
using namespace std;
bool FirstFit(int Process[],int Partition[],int p,int m){
    bool efficient = true;

    int temp[m+5];
    for(int i=1;i<=m;i++)temp[i]=Partition[i];

    cout<<"First Fit:\n";
    for(int i=1;i<=p;i++){
        int current_process = Process[i];
        bool good = 0;
        for(int j=1;j<=m;j++){
            if(temp[j]>=current_process){
                cout<<current_process<<"Kb is put in "<<temp[j]<<"Kb partition\n";
                good = 1;
                temp[j]-=current_process;
                break;
            }
        }
        if(good==0){
            cout<<current_process<<"Kb Must Wait!\n";
            efficient=false;
        }
    }
    return efficient;
}
bool BestFit(int Process[],int Partition[],int p,int m){
    bool efficient = true;

    int temp[m+5];
    for(int i=1;i<=m;i++)temp[i]=Partition[i];

    cout<<"Best Fit:\n";
    for(int i=1;i<=p;i++){
        sort(temp+1,temp+1+m);
        int current_process = Process[i];
        bool good = 0;
        for(int j=1;j<=m;j++){
            if(temp[j]>=current_process){
                cout<<current_process<<"Kb is put in "<<temp[j]<<"Kb partition\n";
                good = 1;
                temp[j]-=current_process;
                break;
            }
        }
        if(good==0){
            cout<<current_process<<"Kb Must Wait!\n";
            efficient = false;
        }
    }
    return efficient;
}
bool WorstFit(int Process[],int Partition[],int p,int m){
    bool efficient = true;
    int temp[m+5];
    for(int i=1;i<=m;i++)temp[i]=Partition[i];

    cout<<"Worst Fit:\n";
    for(int i=1;i<=p;i++){
        sort(temp+1,temp+1+m,greater<int>());

        int current_process = Process[i];
        bool good = 0;
        for(int j=1;j<=m;j++){
            if(temp[j]>=current_process){
                cout<<current_process<<"Kb is put in "<<temp[j]<<"Kb partition\n";
                good = 1;
                temp[j]-=current_process;
                break;
            }
        }
        if(good==0){
            cout<<current_process<<"Kb Must Wait!\n";
            efficient = false;
        }
    }
    return efficient;
}
int main (){
    cout<<"Enter the Number of memory partitions: ";
    int m;cin>>m;
    int Partition[m+5];
    cout<<"Enter the sizes of the partitions: ";
    for(int i=1;i<=m;i++){
            string kb;
            cin >> Partition[i] >> kb;
    }
    cout<<"Enter the Number of processes: ";
    int p;cin>>p;
    int Process[p+5];
    cout<<"Enter the sizes of the processes: ";
    for(int i=1;i<=p;i++){
            string kb;
            cin >> Process[i] >> kb;
    }
    int ff = FirstFit(Process , Partition,p,m);
    int bf = BestFit(Process  , Partition,p,m);
    int wf = WorstFit(Process , Partition,p,m);
    if(ff&&!bf&&!wf)cout<<"In this example, first-fit turns out to be the best.\n";
    else if(!ff&&bf&&!wf)cout<<"In this example, best-fit turns out to be the best.\n";
    else if(!ff&&!bf&&wf)cout<<"In this example, worst-fit turns out to be the best.\n";
    else if(ff&&bf&&!wf)cout<<"In this example, both first-fit and best-fit are efficient.\n";
    else if(ff&&!bf&&wf)cout<<"In this example, both first-fit and worst-fit are efficient.\n";
    else if(!ff&&bf&&wf)cout<<"In this example, both best-fit and worst-fit are efficient.\n";
    else if(!ff&&!bf&&!wf)cout<<"In this example, none of them are efficient.\n";
    return 0;
}
/*
5
100kb 500kb 200kb 300kb 600kb
4
212kb 417kb 112kb 426kb
*/
