// If you get compile error in codeblocks
// goto settings->compiler-> toggle (c++11 or c++14) box on->click ok
// SJF(Non-preemptive With Arrival Time)
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
    int AT , BT , priority , TAT , WT , ipos;
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


    for(int i=1;i<=N;i++){
            //cout<<"Enter name , arrival time , burst time , priority: ";
            cin >> Array[i].name >>  Array[i].AT >> Array[i].BT >> Array[i].priority;
            Array[i].ipos = i;
    }
    priority_queue< pii , vector<pii> , greater<pii> > PQ;
    bool taken[N+5];
    memset(taken,0,sizeof taken);
    int time = 0 , done = 0;
    while(done<N){
            for(int i=1;i<=N;i++){
                if(taken[i])continue;


                if(Array[i].AT<=time){

                        PQ.push({Array[i].BT , i});
                        taken[i] = 1;
                }
            }

            if(PQ.empty()){
                time++;
                continue;
            }

            pii u = PQ.top();
            PQ.pop();


            time+=u.ff;
            Array[u.ss].TAT = time - Array[u.ss].AT;
            Array[u.ss].WT    = Array[u.ss].TAT - Array[u.ss].BT;
            done++;
    }

    printWT(Array,N);
    printAverage_WT(Array,N);

    printTAT(Array,N);
    printAverage_TAT(Array,N);
    return 0;
}
/*
2
p1 0 7 1
p2 0 3 2
*/
