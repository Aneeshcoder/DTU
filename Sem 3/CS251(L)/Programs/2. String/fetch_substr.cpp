//Aneesh Panchal
//2K20/MC/21

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[101],str1[101];
    cout<<"Enter the string: ";
    gets(str);

    cout<<"Enter the substring: ";
    gets(str1);

    int strlen=0,str1len=0;
    while(str[strlen]!='\0'){
        ++strlen;
    }

    while(str1[str1len]!='\0'){
        ++str1len;
    }
    
    int count=0,index=0;
    for(int i=0;str[i]!='\0';++i)
    {
        count=0;
        index=i;
        if(str[i]==str1[0])
        {
            for(int j=0;j<str1len;++j)
            {
                if(str1[j]==str[i+j]){
                    count=count+1;
                }
            }
            if(count==str1len){
                break;
            }
        }
    }

    if(count==str1len)
        cout<<"Substring present at index "<<index<<endl<<endl;
    else{
        cout<<"Substring not present"<<endl<<endl;
        return 0;
    }

    char replace[101];
    cout<<"Enter replacement string: ";
    gets(replace);

    int replen=0;
    while(replace[replen]!='\0'){
        ++replen;
    }

    if(replen==count)
    {
        for(int i=0;i<replen;++i)
        {
            str[index+i]=replace[i];
        }
        cout<<"After Replacement: "<<str<<endl<<endl;
    }
    else
        cout<<"Error: String is of different length !!!"<<endl<<endl;
    
    return 0;
}
