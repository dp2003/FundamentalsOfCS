#include<iostream>
using namespace std;
int FCFS()
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
void SJF()
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

void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quantum)
{


	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0; // Current time
    while (1)
	{
		bool done = true;
		for (int i = 0 ; i < n; i++)
		{

			if (rem_bt[i] > 0)
			{
				done = false;

				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
		break;
	}
}


void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime(int processes[], int n, int bt[],
									int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;


	findWaitingTime(processes, n, bt, wt, quantum);


	findTurnAroundTime(processes, n, bt, wt, tat);

	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";



	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}
	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}
int RoundRobin()
{

	int processes[5];
	cout<<"Enter process id[5]:\n";
	for(int i=0;i<5;i++){
        cout<<"P["<<i+1<<"]:";
        cin>>processes[i];
	}
	int n = sizeof processes / sizeof processes[0];
	// Burst time of all processes
	int burst_time[5];
	cout<<"Enter burst time:";
	for(int i=0;i<5;i++){
        cout<<"Burst time for "<<i+1<<":";
        cin>>burst_time[i];
	}
	// Time quantum
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);

}

int StaticPartioning() {
   int blockNumber = 5, processesNumber = 3;
   int blockSize[5] = {4, 4, 4, 4, 4}, processSize[3] = {1, 2, 3};
   int flags[5], allocation[5];
   for(int i = 0; i < 5; i++) {
      flags[i] = 0;
      allocation[i] = -1;
   }

   for(int i = 0; i < processesNumber; i++) {
      for(int j = 0; j < blockNumber; j++) {
         if(flags[j] == 0 && blockSize[j] >= processSize[i]) {
            allocation[j] = i;
            flags[j] = 1;
            break;
         }
      }
   }
   for (int i = 0; i < blockNumber; i++) {
      if (flags[i] == 1) {
         cout << "Process " << processSize[allocation[i]] << " is allocated" << endl;
      }
   }
   return 0;
}

int DyanmicPartioning()
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
            cout<<"\t\t"<<allocation[i]+1<<"\t\t"<<process_size[allocation[i]];
        else
            cout<<"Not Allocated";
    }
}

int FIFO()
{
    int refstring[10],pagefaults=0,m,n,s,pages,frames;
    cout<<"Enter number of pages: ";
    cin>>pages;
    cout<<"Enter reference string values: "<<endl;
    for(m=0;m<pages;m++)
        {
           cout<<"Value No ["<<m+1<<"] : ";
           cin>>refstring[m];
        }
    cout<<"What are total number of frames: ";
    {
        cin>>frames;
    }
    int temp[frames];
    for(m=0;m<frames;m++){
        temp[m]=-1;
    }
    for(m=0;m<pages;m++)
    {
        s=0;
        for(n=0;n<frames;n++)
        {
            if(refstring[m]==temp[n]){
                s++;
                pagefaults--;
            }
        }
        pagefaults++;
        if((pagefaults<=frames)&&(s==0))
            {
                temp[m]=refstring[m];
            }
        else if(s==0)
        {
            temp[(pagefaults-1)%frames]=refstring[m];
        }
        cout<<"\n";
        for(n=0;n<frames;n++){
            cout<<temp[n]<<"\t";
        }
    }
    cout<<"\nTotal Page faults :"<<pagefaults;
    return 0;
}




int main(){
    int ch;
    cout<<"Enter the following\n1 : FCFS\n2 :SJF \n3 : Round Robin \n4 :Static Partitioning \n5: Dynamic Partitioning \n6: FIFO Page Replacement"<<endl;
    ch:
    cin>>ch;
    switch(ch){
    case 1 : FCFS();
       break;
    case 2 :SJF();
        break;
    case 3: RoundRobin();
       break;
    case 4: StaticPartioning();
       break;
    case 5:  DyanmicPartioning();
       break;
    case 6:
        FIFO();
        break;

    default:
        cout<<"Invalid Choice:";
        goto ch;
    }
}
