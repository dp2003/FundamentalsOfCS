#include<iostream>
using namespace std;
int main()
{
    int block_size[10],process_size[10],block_no,process_no,flags[10],allocation[10],i,j;
    for(i=0;i<10;i++)
    {
        flags[i]=0;
        allocation[i]-1;
    }
    cout<<"Enter no. of blocks:";
    cin>>block_no;

    cout<<"Enter size of each block:";
    for(i=0;i<block_no;i++)
    {
        cin>>block_size[i];
    }
    cout<<"Enter no. of processes";
    cin>>process_no;

    cout<<"Enter size of each process:";
    for(i=0;i<process_no;i++)
    {
        cin>>process_size[i];
    }

    for(i=0;i<process_no;i++)
    {
        for(j=0;j<block_no;j++)
        {
            if(flags[j]==0&&block_size[j]>=process_size[i])
            {
                allocation[j]=i;
                flags[j]=1;
                break;
            }
        }
    }
    cout<<"\n Block no. \t size \t\t process_no \t\t size"<<endl;
    for(i=0;i<block_no;i++)
    {
        cout<<i+1<<block_size[i];
        if(flags[i]==1)
            cout<<"\t\t\"<<allocation[i]+1<<"\t\t"<<process_size[allocation[i]];
        else
            cout<<"Not Allocated";
    }
}
