#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fs;
    ofstream ft;
    string str;
    fstream sample;
    char sourcefile[50], destinationfile[50];

    	sample.open("sample.txt", ios::out);
	if (!sample) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!"<<endl;
		cout<<"Write operation successful"<<endl;
		sample<<"Hello\n This is Sample File";
		sample.close();

	}

    cout << "Enter Source File with Extension: ";
    gets(sourcefile);
    fs.open(sourcefile);
    if (!fs)
    {
        cout << "Error in Opening Source File...!!!";
    }
    cout << "Enter Destination File with Extension: ";
    gets(destinationfile);
    ft.open(destinationfile);

    if (!ft)
    {
        cout << "Error in Opening Destination File...!!!";
        fs.close();
    }
    if (fs && ft)
    {
        while (getline(fs, str))
        {
            ft << str << "\n";
        }
        cout << "\n\n Source File Data Successfully Copied to Destination File...!!!";
    }
    else
    {
        cout << "File Cannot Open...!!!";
    }
    cout << "\n\n Open Destination File and Check!!!\n";
    fs.close();
    ft.close();
}
