/*******************************
CS 251 – Data Structures Project

1. Aneesh Panchal 2K20/MC/21
2. Ayushi Sagar 2K20/MC/35
*******************************/

#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

stack<string> undo;

class Node {
public:
    string data = " ";
    Node* next=NULL;
};

class Linkedlist {
    Node* head;
  
    public:
        Linkedlist(){head = NULL;}
    
    int totalLine(){
        int count = 0;
        Node* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void read(string data_) {
        Node* newNode = new Node();
        newNode->data = data_;
        Node* temp = head;

        if(head == NULL){
            head = newNode;
            return;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insert(int pos, string data_) {
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=head;
        int numLines = totalLine();

        if(head==NULL){
            if(pos!=1){
                cout<<"Invalid Position !!!"<<endl;
                return;
            }
            head = newNode;
            return;
        }

        else if(pos-numLines>1){
            int count=1;
            while (true) {
                if(temp == NULL){
                    cout<<"Line not present !!!"<<endl<<endl;
                    return;
                }
                if (count == totalLine())
                    break;
                count++;
                temp = temp->next;
            }
            
            for(int i=0;i<(pos-numLines-1);++i){
                temp->next = new Node();
                temp = temp->next;
            }
            temp->next = newNode;
        }

        else{
            while((--pos)>1){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleted(int pos){
        Node* temp=head;

        if(head==NULL){
            cout<<"File empty !!!"<<endl<<endl;
            return;
        }

        int count = 1;

        if(pos==1){
            head = head->next;
            return;
        }

        while (true) {
            if(temp == NULL){
                cout<<"Line not present !!!"<<endl<<endl;
                return;
            }
            if (count == pos-1)
                break;
            count++;
            temp = temp->next;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void replace(int pos, string data_){
        Node* temp=head;

        if(head==NULL){
            cout<<"Page is empty !!!"<<endl<<endl;
            return;
        }

        int count = 1;
        while (true) {
            if(temp == NULL){
                cout<<"File present !!!"<<endl<<endl;
                return;
            }
            if (count == pos)
                break;
            count++;
            temp = temp->next;
        }

        temp->data = data_;
    }

    void move(int line1, int line2){
        string test = "";
        Node* temp=head;

        if(head==NULL){
            cout<<"File empty !!!"<<endl<<endl;
            return;
        }

        int count = 1;
        while (true) {
            if(temp == NULL){
                cout<<"Line not present !!!"<<endl<<endl;
                return;
            }
            if (count == line1)
                break;
            count++;
            temp = temp->next;
        }

        test = temp->data;

        count = 1;
        Node* temp2=head;
        while (true) {
            if(temp2 == NULL){
                cout<<"Line not present !!!"<<endl<<endl;
                return;
            }
            if (count == line2)
                break;
            count++;
            temp2 = temp2->next;
        }

        temp->data = temp2->data;
        temp2->data = test;
    }

    void show(){
        Node* temp=head;
        if(head==NULL){
            cout<<"Page empty !!!"<<endl<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<endl<<"----- "<<totalLine()<<" lines -----"<<endl<<endl;
    }

    void save(string name){
        ofstream MyFile(name);
	    if (MyFile.is_open())
	    {
		    for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
			MyFile << tmp->data << " " << endl;
		    MyFile.close();
	    }
    }
};

string* split(string str, char delimiter){
    string* arr = new string[3];
    
    int count=0;
    int start=0;
    int num=0;

    for(int i=0;num<3;i++){
        if(str[i]==delimiter || str[i]=='\0'){
            if (num==2){
                arr[num] = str.substr(start);
                break;
            }
            arr[count]=str.substr(start,i-start);
            ++count;
            ++num;
            start = i+1;
            if(str[i]=='\0'){
                break;
            }
        }
    }
    return arr;
}

string lower(string str){
    string temp = str;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return temp;
}

int main()
{
    while(!undo.empty()){
        undo.pop();
    }

    Linkedlist LL;
    string command, line, argument1, argument2, fileName;
    bool fileopen = false;
    while(!fileopen){
        try
        {
            cout<<endl<<"Open or Create file: "<<endl;
            getline(cin,command);
            string* arrfile = split(command,' ');
            if(arrfile[0]=="open"){
                ifstream MyFile(arrfile[1]);
                if (MyFile.is_open())
                {
                    int lineNum = 1;
                    while (getline(MyFile, line))
                    {
                        LL.read(line);
                    }
                    fileopen = true;
                    fileName = arrfile[1];
                    MyFile.close();
                }
                else{
                    cout<<"File not found !!!"<<endl<<endl;
                }
            }
            else if(arrfile[0]=="create"){
                ofstream newFile(arrfile[1]);
                newFile.open(arrfile[1]);
			    //newFile << "Please Enter your Texts here !";
			    newFile.close();

                ifstream MyFile(arrfile[1]);
                int lineNum = 1;
                while (getline(MyFile, line))
                {
                    LL.read(line);
                }
                fileopen = true;
                fileName = arrfile[1];
                MyFile.close();
            }
            else{
                cout<<"Invalid command !!!"<<endl<<endl;
            }   
        }
        catch (exception ex)
		{
			cout <<"Error"<< "!!!\n";
		}
    }
    cout<<endl;

    int autosave = 0;
    while(true){
        cout<<"Do you want to autosave your progress ? (yes/no)"<<endl;
        getline(cin,command);
        command = lower(command);
        if(command=="yes"){
            autosave = 1;
            break;
        }
        else if(command=="no"){
            autosave = 0;
            break;
        }
        else{
            cout<<"Invalid command !!!"<<endl<<endl;
        }
    }
    cout<<endl;

    while(true){
        cout<<"Enter the Command: "<<endl;
        getline(cin,command);
        string* arr = split(command,' ');
        command = lower(arr[0]);
        argument1 = arr[1];
        argument2 = arr[2];
        if(command=="undo"){
            if(undo.empty()){
                cout<<"No undo commands !!!"<<endl<<endl;
            }
            else{
                string undoargument1, undoargument2;
                string undocommand = undo.top();
                undo.pop();
                string* undoarr = split(undocommand,'#');
                undocommand = lower(undoarr[0]);
                undoargument1 = undoarr[1];
                undoargument2 = undoarr[2];
                if(undocommand=="insert"){
                    LL.deleted(stoi(undoargument1));
                }
                else if(undocommand=="delete"){
                    LL.insert(stoi(undoargument1),undoargument2);
                }
                else if(undocommand=="replace"){
                    LL.replace(stoi(undoargument1),undoargument2);
                }
                else if(undocommand=="move"){
                    LL.move(stoi(undoargument1),stoi(undoargument2));
                }
                else{
                    cout<<"Invalid command !!!"<<endl<<endl;
                }
            }
        }

        else if(command=="insert"){
            try
            {
                LL.insert(stoi(argument1),argument2);
                undo.push(command+"#"+argument1+"#"+argument2);
            }
            catch (exception ex)
		    {
			    cout <<"Error"<< "!!!\n";
		    }
        }
        
        else if(command=="delete"){
            try
            {
                LL.deleted(stoi(argument1));
                undo.push(command+"#"+argument1+"#"+argument2);
            }
            catch (exception ex)
		    {
			    cout <<"Error"<< "!!!\n";
		    }
        }
        
        else if(command=="replace"){
            try
            {
                LL.replace(stoi(argument1),argument2);
                undo.push(command+"#"+argument1+"#"+argument2);
            }
            catch (exception ex)
		    {
			    cout <<"Error"<< "!!!\n";
		    }
        }
        
        else if(command=="move"){
            try
            {
                LL.move(stoi(argument1),stoi(argument2));
                undo.push(command+"#"+argument1+"#"+argument2);
            }
            catch (exception ex)
            {
                cout<<"Error"<< "!!!\n";
            }
        }
        
        else if(command=="show"){
            try
            {
                LL.show();
            }
            catch (exception ex)
            {
                cout<<"Error"<< "!!!\n";
            }
        }
        
        else if(command=="save"){
            LL.save(fileName);
        }
        
        else if(command=="rename"){
            fileName = argument1 + ".txt";
            LL.save(fileName);
            cout<<endl<<"New file named "<<fileName<<" created !!!"<<endl<<endl;
        }
        
        else if(command=="exit"){
            if(autosave==1){
                LL.save(fileName);
                cout<<endl;
            }

            break;
        }
        
        else{
            cout<<"Invalid command !!!"<<endl<<endl;
        }
        cout<<endl;
    }
    return 0;
}
