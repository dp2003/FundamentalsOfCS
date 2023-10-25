#include<iostream>
using namespace std;
int main()
{
    int n,burst[10],waiting[10],turn_around[10],avg_wt=0,avg_tat=0,i,j;

    cout<<"Enter the number of processes:";
    cin>>n;

    cout<<"Enter the Burst time for the processes\n";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"=";
        cin>>burst[i];
    }

    waiting[0]=0;

    for( i=1;i<n;i++)
    {
        waiting[i]=0;
        for( j=0;j<i;j++)
            waiting[i]+=burst[j];
    }
    cout<<"\nProcess"<<"   "<<"Burst Time"<<"   "<<"Waiting Time"<<"    "<<"Turnaround Time"<<endl;
    for( i=0;i<n;i++)
    {
       turn_around[i]=burst[i]+waiting[i];
       avg_wt+=waiting[i];
       avg_tat+=turn_around[i];
       cout<<i+1<<"             "<<burst[i]<<"              "<<waiting[i]<<"                "<<turn_around[i]<<endl;
    }
    avg_wt/=i;
    avg_tat/=i;
    cout<<"Average waiting time = "<<avg_wt<<endl;
    cout<<"Average turnaround time = "<<avg_tat;

    return 0;



}
