/*
TAT - Turn Around Time
WT  - Waiting Time
AT  - Arrival Time
BT  - Burst Time

Formula:

Turn Around Time = Completion Time  – Arrival Time
Waiting Time     = Turn Around Time – Burst Time

*/
#include<bits/stdc++.h>
using namespace std;
struct process{
    string name;
    int AT , BT , priority , TAT , WT , ipos;
    process(){
        name="";
        AT=0;
        BT=0;
        priority=0;
        TAT=0;
        WT=0;
    }
    bool operator < (process A){ // burst time sort korar jonno
        if(A.BT<BT)return 0;
        if(A.BT>BT)return 1;
        return A.name>name;
    }
};
bool cmp(process A , process B){ // input order a sort korar jonno
    if(A.ipos<B.ipos)return 1;
    if(A.ipos>B.ipos)return 0;
}
void printAverage_WT(process Array[],int N){
    double sum=0.0 , avg=0.0;

    for(int i=1;i<=N;i++){
            sum+=Array[i].WT;
    }
    avg = sum/(N*1.0);
    cout<<"\nAverage waiting time = "<<fixed<<setprecision(10)<<avg<<endl;
}
void printAverage_TAT(process Array[],int N){
    double sum=0.0 , avg=0.0;

    for(int i=1;i<=N;i++){
            sum+=Array[i].TAT;
    }
    avg = sum/(N*1.0);
    cout<<"\nAverage TurnAround time = "<<fixed<<setprecision(10)<<avg<<endl;
}
void printWT(process Array[],int N){
    cout<<"\nProcess----Waiting Time\n";

    for(int i=1;i<=N;i++){
            cout<<"  "<<Array[i].name<<"\t\t"<<Array[i].WT<<endl;
    }
}
void printTAT(process Array[],int N){
    cout<<"\nProcess----TurnAround Time\n";
    for(int i=1;i<=N;i++){
            cout<<"  "<<Array[i].name<<"\t\t"<<Array[i].TAT<<endl;
    }
}
int main (){
    int N;
    cout<<"Enter the number of processes: ";
    cin >> N;

    process Array[N+5];


    for(int i=1;i<=N;i++){
            //cout<<"Enter name , burst time , priority: ";
            cin >> Array[i].name >> Array[i].BT >> Array[i].priority;
            Array[i].ipos = i;
            // If arrival time is given
            // cin >> Array[i].AT;
    }
    sort(Array+1 , Array+1+N);

    int time = 0 ;
    for(int i=1;i<=N;i++){
            time+=Array[i].BT;
            Array[i].TAT = time - Array[i].AT;
            Array[i].WT    = Array[i].TAT - Array[i].BT;
    }
    sort(Array+1,Array+1+N,cmp);
    printWT(Array,N);
    printAverage_WT(Array,N);

    printTAT(Array,N);
    printAverage_TAT(Array,N);
    return 0;
}
/*
5
P1 2 2
P2 1 1
P3 8 4
P4 4 2
P5 5 3

5
P1 8 4
P2 6 1
P3 1 2
P4 9 2
P5 3 3
*/
