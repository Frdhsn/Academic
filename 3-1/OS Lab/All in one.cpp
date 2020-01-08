// If you get compile error in codeblocks
// goto settings->compiler-> toggle (c++11 or c++14) box on->click ok
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

bool cmp1(process A , process B){ // priority wise sort korar jonno
    if(A.priority<B.priority)return 1;
    if(A.priority>B.priority)return 0;
    return A.ipos<B.ipos;
}
bool cmp2(process A , process B){ // priority wise sort korar jonno
    if(A.priority<B.priority)return 0;
    if(A.priority>B.priority)return 1;
    return A.ipos<B.ipos;
}
bool cmp3(process A , process B){ // input order a sort korar jonno
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
void roundrobin(process Array[],int N){
    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];

    int temp[N+5];
    for(int i=1;i<=N;i++){
            temp[i] = Barray[i].BT;
    }
    int quantum=0;
    cout<<"Enter the time quantum : ";
    cin >> quantum;
    int time = 0,done=0;
    while(done<N){
        for(int i=1;i<=N;i++){
            //if(Barray[i].AT>time)continue;
            if(temp[i]>0){
                if(temp[i]<=quantum){

                    time+=temp[i];
                    Barray[i].CT = time;
                    Barray[i].TAT = Barray[i].CT - Barray[i].AT;
                    Barray[i].WT = Barray[i].TAT - Barray[i].BT;
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
    printWT(Barray,N);
    printAverage_WT(Barray,N);
    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void FCFS1(process Array[],int N){ // With A. time


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];

    priority_queue<pii , vector<pii> , greater<pii> > PQ;

    for(int i=1;i<=N;i++){
             PQ.push({Barray[i].AT , i});
    }
    int time = 0 ;
    // if time start at 1 sec
    // time = 1
    while(!PQ.empty()){
            pii u = PQ.top();
            PQ.pop();
            int id = u.ss;
            time+=Barray[id].BT;
            Barray[id].TAT = time - Barray[id].AT;
            Barray[id].WT    = Barray[id].TAT - Barray[id].BT;
    }

    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void FCFS2(process Array[],int N){ // without A.time


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];


    int time = 0 ;
    for(int i=1;i<=N;i++){
            time+=Barray[i].BT;
            Barray[i].TAT = time - Barray[i].AT;
            Barray[i].WT    = Barray[i].TAT - Barray[i].BT;
    }

    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void preemptivePriority(process Array[],int N){


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];


    int temp[N+5];
    for(int i=1;i<=N;i++){
            temp[i] = Barray[i].BT;
    }
    bool taken[N+5];
    memset(taken,0,sizeof taken);
    int time=0,done=0;

    // when small number implies higher priority
    priority_queue< pii ,vector<pii> , greater<pii> > PQ;
    // when large number implies higher priority

    //priority_queue< pii> PQ;
    while(done<N){

            for(int i=1;i<=N;i++){
                if(taken[i]==0){
                    if(Barray[i].AT<=time){
                        PQ.push({Barray[i].priority , i});
                        taken[i]=1;
                    }
                }
            }

            time++;
            if(PQ.empty())continue;
            pii u = PQ.top();
            temp[u.ss]--;
            if(temp[u.ss]==0){
                Barray[u.ss].TAT = time - Barray[u.ss].AT;
                Barray[u.ss].WT  = Barray[u.ss].TAT - Barray[u.ss].BT;
                PQ.pop();
                done++;
            }
    }
    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void NonPreemptivePriority(process Array[],int N){


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];


    // when small number implies higher priority
    //sort(Array+1 , Array+1+N , cmp1);
    // when large number implies higher priority
    sort(Barray+1 , Barray+1+N , cmp2);
    //for(int i=1;i<=N;i++)cout<<Barray[i].name<<" "<<Barray[i].BT<<" "<<Barray[i].priority<<endl;

    int time = 0 ;
    for(int i=1;i<=N;i++){
            time+=Barray[i].BT;
            Barray[i].TAT = time - Barray[i].AT;
            Barray[i].WT    = Barray[i].TAT - Barray[i].BT;
    }
    sort(Barray+1,Barray+1+N,cmp3);
    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void SJFPreemptive(process Array[],int N){


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];


    bool taken[N+5];
    memset(taken,0,sizeof taken);

    priority_queue<pii,vector<pii>,greater<pii>>PQ;
    int time = 0 , done = 0;
    while(1){
        for(int i=1;i<=N;i++){
            if(taken[i]==0){

                if(Barray[i].AT<=time){
                    PQ.push({Barray[i].BT , i});
                    taken[i]=1;
                }
            }
        }
        if(PQ.empty()){
            time++;
            continue;
        }
        pii u = PQ.top();
        PQ.pop();
        time++;
        if(u.ff==1){
                int id = u.ss;
                Barray[id].CT = time;
                Barray[id].TAT = Barray[id].CT - Barray[id].AT;
                Barray[id].WT = Barray[id].TAT - Barray[id].BT;
                done++;
        }
        else{
            u.ff--;
            PQ.push({u.ff , u.ss});
        }
        if(done==N)break;

    }

    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
void SJFNonpreemptive(process Array[],int N){


    process Barray[N+5];
    for(int i=1;i<=N;i++)Barray[i]=Array[i];


    priority_queue< pii , vector<pii> , greater<pii> > PQ;
    bool taken[N+5];
    memset(taken,0,sizeof taken);
    int time = 0 , done = 0;
    while(done<N){
            for(int i=1;i<=N;i++){
                if(taken[i])continue;


                if(Barray[i].AT<=time){

                        PQ.push({Barray[i].BT , i});
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
            Barray[u.ss].TAT = time - Barray[u.ss].AT;
            Barray[u.ss].WT    = Barray[u.ss].TAT - Barray[u.ss].BT;
            done++;
    }

    printWT(Barray,N);
    printAverage_WT(Barray,N);

    printTAT(Barray,N);
    printAverage_TAT(Barray,N);
}
int main (){
    int N;
    cout<<"Enter the number of processes: ";
    cin >> N;
    process Array[N+5];
    for(int i=1;i<=N;i++){
            cout<<"Enter name , arrival time , burst time , priority: ";
            cin >> Array[i].name >> Array[i].AT >> Array[i].BT >> Array[i].priority;
            Array[i].ipos = i;
    }
    while(1){
        int type ;
        cout<<"Type 1 for Round Robin algo.\n";
        cout<<"Type 2 for FCFS with Arrival time algo.\n";
        cout<<"Type 3 for FCFS without Arrival time algo.\n";
        cout<<"Type 4 for Preemptive priority algo.\n";
        cout<<"Type 5 for NonPreemptive priority algo.\n";
        cout<<"Type 6 for SJFPreemptive algo.\n";
        cout<<"Type 7 for SJF NonPreemptive algo.\n";
        cout<<"Type 8 to exit.\n";
        cin >> type;
        if(type==1)roundrobin(Array,N);
        else if(type==2)FCFS1(Array,N);
        else if(type==3)FCFS2(Array,N);
        else if(type==4)preemptivePriority(Array,N);
        else if(type==5)NonPreemptivePriority(Array,N);
        else if(type==6)SJFPreemptive(Array,N);
        else if(type==7)SJFNonpreemptive(Array,N);
        else break;
    }
    return 0;
}
/*
5
P1 0 2 2
P2 0 1 1
P3 0 8 4
P4 0 4 2
P5 0 5 3

*/
