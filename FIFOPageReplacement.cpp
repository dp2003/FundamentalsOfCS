#include<iostream>
using namespace std;
int main()
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
