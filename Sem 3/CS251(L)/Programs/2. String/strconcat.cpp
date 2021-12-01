//Aneesh Panchal
//2K20/MC/21

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str1[101],str2[101];
    cout<<"Enter 1st string: ";
    gets(str1);
    cout<<endl<<"Enter 2nd string: ";
    gets(str2);
    int i=0,j=0;
    while(str1[i]!='\0')
        ++i;
     
    while(str2[j]!='\0')
    {
        str1[i]=str2[j];
        ++i;++j;
    }
    str1[i]='\0';

    cout<<endl<<"String after concatenation: "<<str1<<endl<<endl;
    return 0;
}
