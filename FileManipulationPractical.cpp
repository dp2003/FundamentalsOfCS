#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fs;
    ofstream ft;
    string str;
    fstream f;
    char source_file[50],destination_file[50];

    f.open("original.txt",ios::out);
    if(!f)
    {
        cout<<"File not created";
    }
    else
    {
        cout<<"File created!!"<<endl;
        f<<"Hii this is the original file";
        cout<<"Write operation successful"<<endl;
        f.close();
    }

    cout<<"Enter source file with extension:";
    gets(source_file);
    fs.open(source_file);
    if(!fs)
    {
        cout<<"Error in opening file!";
    }
    cout<<"Enter destination file with extension:";
    gets(destination_file);
    ft.open(destination_file);
    if(!ft)
    {
        cout<<"Error in opening destination file";
        fs.close();
    }
    if(fs && ft)
        while(getline(fs,str))
        {
            ft<<str<<"\n";
            cout<<"Source file data successfully copied into destination!!";
        }
    else
        {
                cout<<"Cannot open file";
        }
        fs.close();
        ft.close();
}
