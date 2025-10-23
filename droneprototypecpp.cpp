#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
bool day ();	//this function checks if time is between 8am and 8 pm almost 
void display(); //mission report with battery, total deliveries failed etc
bool weather(); //checks weather
bool weight();
bool delivery();//checks all functions and gives gives 1 input to main
int current_time();
bool power();//charging if low will not move anymore
void charging();//going to base to charge battery 


int battery=100;
int total_delivery=0;
int total_fails=0;
int main(){
	string begin;
	int number=1;
	cout<<"-------------------------------------"<<endl;
	cout<<setw(23)<<"Welcome"<<endl;
	cout<<setw(23)<<"current battery "<<battery<<" %"<<endl;
	cout<<setw(23)<<"Time: "<<current_time()<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<endl;
	if (current_time()<20 || current_time()>7){
		cout<<"Would you like to start the day? (yes/no)"<<endl;
		cin>>begin;
		if (begin=="yes"){
			do {
				cout<<"Delivery number: "<<number<<endl;
				if (delivery() == true){
					cout<<"delivery successful"<<endl;
					cout<<right<<"Battery remaining : "<<battery<<" %"<<endl;
					total_delivery++;
				}
				else{
					cout<<"delivery unsuccessful"<<endl;
					total_fails++;
				}
				cout<<"Would you like to continue?" <<endl;
				cin>>begin;
				number++;
			}
			while(begin=="yes");
		}
	cout<<"Here is the summary of the day"<<endl;
	display();
	cout<<"Shutting down...";
}
else{
	cout<<"Please use program from 7am to 8 pm.";
}
}
int current_time(){
	time_t now = time(0);         // get current time
    tm* ltm = localtime(&now);       // convert to local time
    return ltm->tm_hour;
}

bool day(){
	int hour=current_time();
	bool available;
	if(hour<8 || hour>18)
    	available=false;
	else 
		available=true;
	return available;
}
	
bool weather(){
	bool available=true;
	srand(time(0));
	int random= (rand()%100);
	while (random<20 || random>75){
		cout<<"current weather is too severe for any flight. please wait"<<endl;
		system("pause");
		random= (rand()%100);
	}
	cout<<"good weather conditions. "<<endl;
	available=true;		
	return available;
}

bool weight(){ //here we can change weight since it is a user influenced variable while temp is not
	int num;
	cout<<"What is the weight of items transported"<<endl;
	cin>>num;
	while(num>70 || num<1){
		if (num >70){
			cout<<"too heavy load. Decrease load"<<endl;
			cin>>num;
		}
		else if (num<1){
			cout<<"too light. Increase load"<<endl;
			cin>>num;
		}
	}
	battery=battery-(float)((float)num*0.5);
	return true;
}

void display(){
	cout<<"-------------------------------------"<<endl;
	cout<<setw(20)<<"Battery remaining : "<<battery<<" %"<<endl;
	cout<<setw(20)<<"Total deliveries : "<<total_delivery<<endl;
	cout<<setw(20)<<"Total fails : "<<total_fails<<endl;
	cout<<"-------------------------------------"<<endl;
}

bool delivery(){
	bool y_n;
	if (weather()== false || day()==false){
		y_n=false;
	}
	else if ( weight()==false || power()==false)
		y_n=false;
	else
		y_n=true;
	return y_n;
}

bool power(){
	bool fly=true;
	if (battery<30){
		cout<<"low battery. Returning to base"<<endl;
		charging();
		fly=false;
	}
	return fly;
}

void charging (){
	battery=100;
}

/*bool destination (){
	cout<<"enter destination of drone"<<endl;
	cout<<"1. Lahore \n 2. Islamabad \n 3. Peshawar \n 4. Karachi \n 5. Faisalabad "<<endl;
	cin>>city;
	switch (city){
		case 1:{
			cout<<"Drone is going to Lahore. ETA is "<<
			break;
		}
			case 1:{
			cout<<"Drone is going to Lahore. ETA is "<<
			break;
		}
			case 2:{
			cout<<"Drone is going to Lahore. ETA is "<<
			break;
		}
			case 3:{
			cout<<"Drone is going to Lahore. ETA is "<<
			break;
		}
			case 4:{
			cout<<"Drone is going to . ETA is "<<
			break;
		}
			case 5:{
			cout<<"Drone is going to Faisalabad. ETA is "<<
			break;
		}
	}
}
*/
