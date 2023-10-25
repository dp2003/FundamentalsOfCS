#include<iostream>
using namespace std;
int main()
{
    int burst[20],p[20],wait[20],turn[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    cout<<"Enter number of process:";
    cin>>n;

    cout<<"\nEnter Burst Time:\n";
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<":";
        cin>>burst[i];
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos])
                pos=j;
        }

        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wait[0]=0;


    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=burst[j];

        total+=wait[i];
    }

    avg_wt=(float)total/n;
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time"<<endl;
    for(i=0;i<n;i++)
    {
        turn[i]=burst[i]+wait[i];
        total+=turn[i];
       cout<<"p"<<p[i]<<"               "<<burst[i]<<"                  "<<wait[i]<<"               "<<turn[i]<<endl;
    }

    avg_tat=(float)total/n;
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;

}
