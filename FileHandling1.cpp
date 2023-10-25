#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

ofstream fout;
ifstream fin;
void openFile(){
fout.open("example.txt");
}
void writeFile(){
    char str[100];
    cout<<"Enter the text you want to enter:\n";
    gets(str);
    for(int i=0;i<strlen(str);i++){
        fout.put(str[i]);
    }
    fout.close();
}
void readFile(string name){
fin.open(name);
char data[100];
fin.getline(data,sizeof(data));
cout<<"\nData read from file\n";
cout<<data;
}
void closeFile(){
fin.close();
}
int main(){
openFile();
writeFile();
readFile("example.txt");
closeFile();
cout<<"\nCopying data from one file to another\n";
fin.open("file1.txt",ios::in);
char str[100];
fin.getline(str,sizeof(str));
fin.close();

fout.open("file2.txt",ios::out);
 for(int i=0;i<strlen(str);i++){
        fout.put(str[i]);
    }
    fout.close();
    cout<<"\nCopied successfully\n";
}
