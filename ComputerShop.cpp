#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class ComputerShop
{
	public:
		string generation[4];//computer type based on generation and 
		float price[4];//computers price based on thier generation
		string Shopname;
		int stored;
		ComputerShop(){
		Shopname="Bright Computers";
		generation[0]="3rd Generation";
		generation[1]="2nd Generation";
		generation[2]="4th Generation";
		generation[3]="5th Generation";
		price[0]=19500;
		price[1]=17000;
		price[2]=25000;
		price[3]=43500;
		stored=250;//250 computers are availiable in the store
		}
};
class contents
{
	public:
	int soldC;//used to store the sold computers number
	int gen_tracker[];
	float priceSaver;
	virtual void print()=0;//func to override
	
};
class treding:public ComputerShop,public contents
{
	public:
		int record()
		{
			cout<<"<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->\n\n";
			cout<<"\t\tThis Program Calculates Daily Computers sell \n\n";
			cout<<"<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->\n\n";
			cout<<"Enter How many Computers did You sell\n";
			cin>>soldC;
			cout<<">->->->->->->->->->->->->->->\n";
			cout<<"Enter Their Generation\n";
			cout<<"If it is Generation 2 enter 2 \nif it is 3 Enter 3\n if it is 4 Enter 4 and also Enter 5 for 5th generations\n";
			cout<<"The program will terminate if you Enter any other number\n";
			cout<<">->->->->->->->->->->->->->->\n";
			for(int i=0;i<soldC;i++)
			{
			cout<<"Enter for Computer  "<<i+1<<endl;
			cin>>gen_tracker[i];
			if(gen_tracker[i]!=2 && gen_tracker[i]!=3 && gen_tracker[i]!=4 && gen_tracker[i]!=5)
			{
				cout<<"There is no Such Generation in the store\n";
				break;
			}
		}
			for(int i=0;i<soldC;i++)
			{
				if(gen_tracker[i]==2)
					priceSaver=priceSaver+price[1];
				else if(gen_tracker[i]==3)
					priceSaver=priceSaver+price[0];
				else if(gen_tracker[i]==4)
					priceSaver=priceSaver+price[2];
				else if(gen_tracker[i]==5)
					priceSaver=priceSaver+price[3];
			}
			
			
		}
		void Saver()
		{
			fstream myfile;
			
			myfile.open("History.txt",ios::out);
			
			if(myfile.is_open())
			{
				myfile<<"<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->"<<endl<<endl;
				myfile<<"Daily computer Selling History \n"<<endl;
				myfile<<"Today's Computer on the store Before sold"<<endl;
				myfile<<stored<<endl;
				myfile<<"Today's sold Computer"<<endl;
				myfile<<soldC<<endl;
				myfile<<"Remaining Computers"<<endl;
				myfile<<stored-soldC<<endl;
				myfile<<"Todays Profit From Selling"<<endl;
				myfile<<priceSaver<<endl;
				myfile<<"\n\n<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->";
				myfile.close();
			}
			
		}
	void print()
    {
	fstream myfile;
 myfile.open("History.txt",ios::in);
if(myfile.is_open())
{  
	string line;
    while(getline(myfile,line))
     {
            cout<<line<<endl;


     }
     myfile.close();
}

   }
};
int main()
{
	treding tr;
	tr.record();
	tr.Saver();
	tr.print();
	
	return 0;
}
