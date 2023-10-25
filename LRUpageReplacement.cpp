#include<iostream>
using namespace std;
int findLRU(int time[],int n)
    {
        int i,minimum=time[0],pos=0;
        for(i=1;i<n;++i)
        {
            if(time[i]<minimum)
            {
                minimum=time[i];
                pos=i;
            }
        }
        return pos;
    }
int main()
{
    int no_ofFrames,no_ofPages,frame[10],pages[30],counter=0,time[10],flag1,flag2,i,j,pos,faults=0;
cout<<"Enter no. of frames =";
cin>>no_ofFrames;
cout<<"Enter no of pages =";
cin>>no_ofPages;
cout<<"Enter reference string = ";
for(i=0;i<no_ofPages;++i)
{
    cin>>pages[i];
}
for(i=0;i<no_ofFrames;++i)
{
    frame[i]=-1;
}
for(i=0;i<no_ofPages;++i)
{
    flag1=flag2=0;
    for(j=0;j<no_ofFrames;++j)
    {
        if(frame[j]==pages[i])
        {
            counter++;
            time[j]=counter;
            flag1=flag2=1;
            break;
        }
    }
    if(flag1==0)
    {
        for(j=0;j<no_ofFrames;++j)
        {
            if(frame[j]==-1){
                counter++;
                faults++;
                frame[j]=pages[i];
                time[j]=counter;
                flag2=1;
                break;
            }
        }
    }
    if(flag2==0)
    {
        pos=findLRU(time,no_ofFrames);
        counter++;
        faults++;
        frame[pos]=pages[i];
        time[pos]=counter;
    }
    cout<<"\n";
    for(j=0;j<no_ofFrames;++j){
        cout<<frame[j]<<"\t";
    }
}
cout<<"\n\nTotal Page faults = "<<faults;
return 0;
}

