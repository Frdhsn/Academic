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
    // when small number implies higher priority
    //sort(Array+1 , Array+1+N , cmp1);
    // when large number implies higher priority
    sort(Array+1 , Array+1+N , cmp2);
    //for(int i=1;i<=N;i++)cout<<Array[i].name<<" "<<Array[i].BT<<" "<<Array[i].priority<<endl;

    int time = 0 ;
    for(int i=1;i<=N;i++){
            time+=Array[i].BT;
            Array[i].TAT = time - Array[i].AT;
            Array[i].WT    = Array[i].TAT - Array[i].BT;
    }
    sort(Array+1,Array+1+N,cmp3);
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
