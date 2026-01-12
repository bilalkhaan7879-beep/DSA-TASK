#include<iostream>
using namespace std;

struct node{
	int patientID;
	node*next;
};

node*head= NULL;
void insertatfirst(int id){
	node*newnode=new node();
	newnode->patientID= id;
	newnode->next= head;
	head= newnode;
	cout<<"Emergency patient added!!"<<endl;
}

void insertatend(int id){
	node*newnode= new node();
	newnode->patientID= id;
	newnode->next= NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	cout<<"Patient added!!"<<endl;
}


void display(){
	if(head==NULL){
		cout<<"No patient in the list"<<endl;
		return;
	}
	node*temp=head;
	cout<<"current patients"<<endl;
	while(temp !=NULL){
		cout<<"Patient id:"<<temp->patientID<<endl;
		temp=temp->next;
	}
}


int main()
{
	int choice, id;
	do{
		cout<<"Patient Managment System"<<endl;
		cout<<"1.Add Emergency Patient"<<endl;
			cout<<"2.Add normal Patient"<<endl;
				cout<<"3.Display All Patient"<<endl;
					cout<<"4.Exit! "<<endl;
						cout<<"Enter Your choice:"<<endl;
						cin>>choice;
						switch (choice){
							case 1:
								cout<<"Enter Patient Id"<<endl;
								cin>>id;
								insertatfirst(id);
								break;
								
								case 2:
								cout<<"Enter Patient Id"<<endl;
								cin>>id;
								insertatend(id);
								break;
								case 3:
								display();
								break;
								case 4:
									cout<<"Program Exited"<<endl;
									break;
									default:
										cout<<"Invalid choice!!!"<<endl;
										
								
								
						}
	}
	while(choice != 4);
	return 0;
}
