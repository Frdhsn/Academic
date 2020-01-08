// If you get compile error in codeblocks
// goto settings->compiler-> toggle (c++11 or c++14) box on->click ok
// Round Robin
/*
TAT - Turn Around Time
WT  - Waiting Time
AT  - Arrival Time
BT  - Burst Time
CT  - Completion Time

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
    int AT , BT ,CT, priority , TAT , WT , ipos;
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

    int temp[N+5];
    process Array[N+5];


    for(int i=1;i<=N;i++){
            cout<<"Enter name , burst time , priority: ";
            cin >> Array[i].name >> Array[i].BT >> Array[i].priority;
            // if arrival time is given then use this
            // cin >> Array[i].name;
            // and add comment to previous line
            temp[i]=Array[i].BT;

    }
    int quantum=0;
    cout<<"Enter the time quantum : ";
    cin >> quantum;


    int time = 0,done=0;

    while(done<N){
        for(int i=1;i<=N;i++){
            //if(Array[i].AT>time)continue;


            if(temp[i]>0){
                if(temp[i]<=quantum){

                    time+=temp[i];
                    Array[i].CT = time;
                    Array[i].TAT = Array[i].CT - Array[i].AT;
                    Array[i].WT = Array[i].TAT - Array[i].BT;
                    done++;
                    temp[i]=0;
                }
                else{
                    time+=quantum;
                    temp[i]-=quantum;
                }
            }
        }
    }
    printWT(Array,N);
    printAverage_WT(Array,N);

    printTAT(Array,N);
    printAverage_TAT(Array,N);
    return 0;
}
/*
number of process
process_name burst_time priority
time quantum

5
P1 2 2
P2 1 1
P3 8 4
P4 4 2
P5 5 3
2

5
P1 7 2
P2 2 7
P3 8 4
P4 9 1
P5 5 5
3
*/
