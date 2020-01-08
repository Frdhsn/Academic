// If you get compile error in codeblocks
// goto settings->compiler-> toggle (c++11 or c++14) box on->click ok
// FCFS with Arrival Time
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
#define ff first
#define ss second
typedef pair<int,int> pii;
struct process{
    string name;
    int AT , BT , priority , TAT , WT;
    process(){
        name="";
        AT=0;
        BT=0;
        priority=0;
        TAT=0;
        WT=0;
    }
};
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

    priority_queue<pii , vector<pii> , greater<pii> > PQ;

    for(int i=1;i<=N;i++){
             cout<<"Enter name , arrival time , burst time: ";
             cin >> Array[i].name >> Array[i].AT >> Array[i].BT;
             PQ.push({Array[i].AT , i});
    }

    int time = 0 ;
    // if time start at 1 sec
    // time = 1
    while(!PQ.empty()){
            pii u = PQ.top();
            PQ.pop();
            int id = u.ss;
            time+=Array[id].BT;
            Array[id].TAT = time - Array[id].AT;
            Array[id].WT    = Array[id].TAT - Array[id].BT;
    }

    printWT(Array,N);
    printAverage_WT(Array,N);

    printTAT(Array,N);
    printAverage_TAT(Array,N);
    return 0;
}
/*
N
processname,arrival time , burst time
5
P1 1 6
P2 3 8
P3 5 1
P4 6 3
P5 7 6
*/
