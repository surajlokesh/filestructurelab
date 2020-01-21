#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ch;
    cout<<"enter 1) for standard output \n 2) user specified output"<<endl;
    cin>>ch;
    string name[10],str;
    int n;
    switch (ch)
    {
        case 1:{
    cout<<"enter the number of names: ";
    cin>>n;
    cout<<"enter the names: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
    }
    cout<<"name in order: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<name[i]<<endl;
    }
    cout<<"name in reversed order"<<endl;
    for(int i=0;i<n;i++)
    {
        str=name[i];
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }}

    case 2:
    {

        fstream f1,f2;
        f1.open("file1.txt",ios::in|ios::out);
       while(f1)
        {
            getline(cin,str);
            if(str== "-1")
            break;

            f1<<str<<endl;
        }
        f1.close();
        f1.open("file1.txt",ios::app);
        int p=f1.tellp();
        f1.close();
        f1.open("file1.txt");
        f2.open("file2.txt",ios::trunc|ios::out);
        char ch;
        for(int i=p-1;i>=0;i--)
        {
                f1.seekg(i);
                ch=f1.get();
                f2<<ch;
        }
        f2.close();
        f1.close();

    }

    }

    return 0;
}

