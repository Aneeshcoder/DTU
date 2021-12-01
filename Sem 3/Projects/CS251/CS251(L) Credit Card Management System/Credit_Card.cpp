/*************************************
 * Credit Card Management System
 * Aneesh Panchal (2K20/MC/21)
 * Data Structures Lab
*************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//Function declarations
string card(string str);
bool isValid(string inputstr);
int int_age(string str);
string* splitdelim(string str, char delimiter);
string* split(string str);
string lower(string str);

class Node {
public:
    string data = " ";
	string name = " ";
    string age = " ";
    Node* next=NULL;
};

class Linkedlist {
    Node* head;
  
    public:
        Linkedlist(){head = NULL;}

    //Read the input csv file and store the data in linked list
	void read(string data_,string name_,string age_){
        Node* newNode = new Node();
        newNode->data = data_;
		newNode->name = name_;
        newNode->age = age_;
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

    //Check the valididty of the name
    bool valid_name(string str){
        for(int i=0;i<str.length();++i){
            if(str[i]>=65 && str[i]<=90){
                continue;
            }
            else if(str[i]>=97 && str[i]<=122){
                continue;
            }
            else if(str[i]==' '){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    //Insert the data in the linked list
    void insert(string data_,string name_,string age_){
        data_ = card(data_);
        int length = data_.length();
        if(length<13 || length>16){
		    cout<<"Invalid card number !!!"<<endl<<endl;
            return;
	    }
        else if(!isValid(data_)){
            cout<<"Invalid card number !!!"<<endl<<endl;
            return;
        }
        else if(int_age(age_)<18){
            cout<<"Age must be greater than 18 !!!"<<endl<<endl;
            return;
        }
        else if(!valid_name(name_)){
            cout<<"Invalid Name !!!"<<endl<<endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data_;
        newNode->name = name_;
        newNode->age = age_;
        Node* temp = head;
        if(head==NULL){
            head = newNode;
            return;
        }
        else if(temp->data == data_){
            cout<<"Card already exists !!!"<<endl<<endl;
            return;
        }
        else{
            while(temp->next != NULL){
                if(temp->data==data_ || temp->name==name_){
                    cout<<"Already present in the list !!!"<<endl<<endl;
                    return;
                }
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //Delete the node containing the data
    void delete_card(string str){
        Node* temp = head;
        Node* prev = NULL;
        while(temp!=NULL){
            if(temp->data==str){
                if(prev==NULL){
                    head = temp->next;
                    delete temp;
                    return;
                }
                else{
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        cout<<"Not found !!!"<<endl<<endl;
    }

    //Clear the linked list
    void delete_all(){
        Node* temp = head;
        while(temp!=NULL){
            head = temp->next;
            delete temp;
            temp = head;
        }
    }

    //Update name of the node containing the data
    void update_name(string card, string new_){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==card){
                temp->name = new_;
                return;
            }
            temp = temp->next;
        }
        cout<<"Not found !!!"<<endl<<endl;
    }

    //Update age of the node containing the data
    void update_age(string card, string new_){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==card){
                temp->age = new_;
                return;
            }
            temp = temp->next;
        }
        cout<<"Not found !!!"<<endl<<endl;
    }

    //Save the linked list to the output file
    void save(string name){
        name = name + ".csv";
        ofstream MyFile(name);
        MyFile<<"Card Number,Name,Age"<<endl;
	    if (MyFile.is_open())
	    {
		    for (Node* tmp = head; tmp != NULL; tmp = tmp->next){
			    tmp->data = card(tmp->data);
                MyFile << tmp->data + "," +  tmp->name<< "," << tmp->age << " " << endl;
            }
		    MyFile.close();
	    }
    }

    //Save only the valid cards to the output file
    void save_valid(string name){
        name = splitdelim(name,'.')[0]+"_valid.csv";
        ofstream MyFile(name);
        MyFile<<"Card Number,Name,Age"<<endl;
	    if (MyFile.is_open())
	    {
		    for (Node* tmp = head; tmp != NULL; tmp = tmp->next){
            if(isValid(tmp->data)){
                tmp->data = card(tmp->data);
			    MyFile << tmp->data + "," +  tmp->name<< "," << tmp->age << " " << endl;
                }
            }
		    MyFile.close();
	    }
    }

    //Save only the invalid cards to the output file
    void save_invalid(string name){
        name = splitdelim(name,'.')[0]+"_invalid.csv";
        ofstream MyFile(name);
        MyFile<<"Card Number,Name,Age"<<endl;
        if (MyFile.is_open())
        {
            for (Node* tmp = head; tmp != NULL; tmp = tmp->next){
            if(!isValid(tmp->data)){
                tmp->data = card(tmp->data);
                MyFile << tmp->data + "," +  tmp->name<< "," << tmp->age << " " << endl;
                }
            }
            MyFile.close();
        }
    }

    //Get name and age of the node containing the data
    string get_data(string data_){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == data_){
                return "Name -> " + temp->name + " and Age -> " + temp->age;
            }
            temp = temp->next;
        }
        return "Not found !!!";
    }

    //Total number of cards in the linked list
	int totalCreditCards(){
		Node* temp = head;
		int count = 0;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
		return count;
	}

    //Show all the cards in the linked list
	void show(){
        Node* temp=head;
        if(head==NULL){
            cout<<"No Credit Card details available !!!"<<endl<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->data<<" -- "<<temp->name<<" -- "<<temp->age<<endl;
            temp = temp->next;
        }
        cout<<endl<<"----- "<<totalCreditCards()<<" Credit Cards found -----"<<endl<<endl;
    }

    //Show only the valid cards in the linked list
    void show_valid(){
        Node* temp=head;
        int count = 0;
        if(head==NULL){
            cout<<"No Credit Card details available !!!"<<endl<<endl;
            return;
        }
        while(temp!=NULL){
            if(isValid(temp->data)){
                cout<<temp->data<<" -- "<<temp->name<<" -- "<<temp->age<<endl;
                ++count;
            }
            temp = temp->next;
        }
        cout<<endl<<"----- "<<count<<" Valid Credit Cards found -----"<<endl<<endl;
    }

    //Show only the invalid cards in the linked list 
    void show_invalid(){
        Node* temp=head;
        int count=0;
        if(head==NULL){
            cout<<"No Credit Card details available !!!"<<endl<<endl;
            return;
        }
        while(temp!=NULL){
            if(!isValid(temp->data)){
                cout<<temp->data<<" -- "<<temp->name<<" -- "<<temp->age<<endl;
                ++count;
            }
            temp = temp->next;
        }
        cout<<endl<<"----- "<<count<<" Invalid Credit Cards found -----"<<endl<<endl;
    }

    //Count number of valid credit cards
    int cValid(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            if(isValid(temp->data)){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

/**************************************************************************************************************************************************************/
//Convert the age from string to int
int int_age(string str){
    int age = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            age = age*10 + (str[i]-'0');
        }
    }
    return age;
}

//split the command line input with delimiter to read csv file
string* splitdelim(string str, char delimiter){
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

//make a string of credit card number without spaces
string card(string str){
	string number = "";
	for(int i=0;i<str.length();i++){
		if(str[i]!=' '){
			number += str[i];
		}
	}
	return number;
}

//checking if the credit card number is valid
bool isValid(string inputstr){
	string str = card(inputstr);
    int length = str.length();
	if(length<13 || length>16){
		return false;
	}
	
    int sum = 0;
	bool isSecond = false;
    for (int i = length-1;i>=0;i--){
        int d = str[i]-'0';
        if (isSecond == true)
            d = d*2;
	
        sum += d/10;
        sum += d%10; 
        isSecond=!isSecond;
    }
    return (sum%10==0);
}

//split the command line input with space as delimiter
string* split(string str){
    string* arr = new string[3];
    int count=0;
    int start=0;
    int num=0;

    for(int i=0;num<3;i++){
        if(str[i]==' ' || str[i]=='\0'){
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

//make input string into lower case letters
string lower(string str){
    string temp = str;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return temp;
}

/**************************************************************************************************************************************************************/
int main(){
    system("cls");
    cout<<"-------------------- Credit Card Management System --------------------"<<endl;
    cout<<"-------------------- Data Structure CS251 2K20MC21 --------------------"<<endl<<endl;
	Linkedlist LL;
	int count_invalid = 0,count_valid =0;
    string command, line, argument1, argument2, fileName;
    bool fileopen = false;
	while(!fileopen){
		cout<<endl<<"Open or create file (open test.csv || create test.csv) :"<<endl;
        getline(cin,command);
        string* arrfile = split(command);
        fileName = arrfile[1];
        command = lower(arrfile[0]);
        //Open the csv file present in the same directory
        if(arrfile[0]=="open"){
            ifstream MyFile(fileName);
            if (MyFile.is_open()){
                int lineNum = 1;
                while (getline(MyFile, line)){
                    if(lineNum==1 && line=="Card Number,Name,Age"){
                        lineNum++;
                        continue;
                    }
					string* splitdata = splitdelim(line,',');
					LL.read(splitdata[0],splitdata[1],splitdata[2]);					
					if(isValid(splitdata[0]))
						++count_valid;
					else
						++count_invalid;
				}
				MyFile.close();
				fileopen = true;
			}
			else{
				cout<<"File not found !!!"<<endl;
			}
		}
        //Create the empty csv file 
        else if(arrfile[0]=="create"){
            ofstream MyFile(fileName);
            if (MyFile.is_open()){
                MyFile.close();
                fileopen = true;
            }
            else{
                cout<<"File not found !!!"<<endl;
            }
        }
        else{
            cout<<"Invalid command !!!"<<endl;
        }
	}

    //Infinite loop to read commands from the user
	while(true){
        cout<<endl<<"Enter the Command: "<<endl;
        getline(cin,command);
        string* arr = split(command);
        command = lower(arr[0]);
        argument1 = arr[1];
        argument2 = arr[2];

        if(command=="show"){
            argument1 = lower(argument1);
            //Print the valid credit cards ---> show valid
            if(argument1=="valid"){
                LL.show_valid();
            }

            //Print the invalid credit cards ---> show invalid
            else if(argument1=="invalid"){
                LL.show_invalid();
            }

            //Print all of the credit cards ---> show
            else{
                LL.show();
            }
        }

        //show all of the commands
        else if(command=="help"){
            cout<<"1.  show\n2.  show valid\n3.  show invalid\n4.  insert 1100110011001100 Aneesh Panchal\n5.  delete card 1100110011001100"<<endl;
            cout<<"6.  delete all\n7.  update name 1100110011001100\n8.  update age 1100110011001100\n9.  valid\n10. Invalid"<<endl;
            cout<<"11. total\n12. getdata 1100110011001100\n13. save\n14. save valid\n15. save invalid\n16. help\n17. exit"<<endl<<endl;
        }

        //insert the data ---> insert 1100110011001100 Aneesh Panchal  
        else if(command=="insert"){
            cout<<"Please specify the age of the card owner: ";
            string age = "";
            getline(cin,age);
            LL.insert(argument1,argument2,age);
        }

        //delete the data ---> delete card 1100110011001100 || delete all
        else if(command=="delete"){
            argument1 = lower(argument1);
            if(argument1=="card"){
                LL.delete_card(argument2);
            }
            else if(argument1=="all"){
                LL.delete_all();
            }
            else{
                cout<<"Invalid command !!!"<<endl;
            }
        }

        //update the data ---> update (name || age) 1100110011001100
        else if(command=="update"){
            argument1 = lower(argument1);
            if(argument1=="name"){
                string newname;
                cout<<"Enter the new name: "<<endl;
                getline(cin,newname);
                LL.update_name(argument2,newname);
            }
            else if(argument1=="age"){
                string newage;
                while(1){
                    cout<<"Enter the new age: "<<endl;
                    getline(cin,newage);
                    if(int_age(newage)>18){
                        break;
                    }
                    else{
                        cout<<"Invalid age !!!"<<endl;
                    }
                }
                LL.update_age(argument2,newage);
            }
            else{
                cout<<"Invalid command !!!"<<endl;
            }
        }

        //Number of valid cards ---> valid
        else if(command=="valid"){
            count_valid = LL.cValid();
            cout<<"Valid card: "<<count_valid<<endl;
        
        }

        //Number of valid cards ---> invalid
        else if(command=="invalid"){
            if(count_invalid==0){
                cout<<"No invalid card !!!"<<endl;
            }
            else{
                cout<<"Invalid card: "<<count_invalid<<endl;
            }
        }

        //Data of the credit card ---> getdata 1100110011001100
        else if(command=="getdata"){
            cout<<LL.get_data(argument1)<<endl;
        }

        //Total number of credit cards ---> total
        else if(command=="total"){
            cout<<"Total Credit Cards: "<<LL.totalCreditCards()<<endl;
        }

        //Save the data into csv file ---> save 
        else if(command=="save"){
            argument1 = lower(argument1);

            //Save the valid data into csv file ---> save valid
            if(argument1=="valid"){
                LL.save_valid(fileName);
            }

            //Save the valid data into csv file ---> save invalid
            else if(argument1=="invalid"){
                LL.save_invalid(fileName);
            }

            else{
                cout<<"Please specify the file name: "<<endl;
                getline(cin,fileName);
                LL.save(fileName);
            }
        }

        else if(command=="exit"){
			cout<<endl<<endl;
            break;
        }

        else{
            cout<<"Invalid command !!!"<<endl<<endl;
        }
        cout<<endl;
    }
    return 0;
}
