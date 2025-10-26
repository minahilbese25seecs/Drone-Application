#define _CRT_SECURE_NO_WARNINGS //this stops error time 
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
bool day();	//this function checks if time is between 8am and 8 pm almost 
void display(); //mission report with battery, total deliveries failed etc
bool weather(); //checks weather
bool weight(); // checks weight 
bool delivery();//checks all functions and gives gives 1 input to main
int current_time(); //gets current 
bool power();//charging if low will not move anymore
void charging();//going to base to charge battery 
string coupon();//generates a coupon that does 50 % off on your order
bool destination();

int battery = 100;
int total_delivery = 0;
int total_fails = 0;
double price=0;
int check=0;
bool givecoupon=true;
int main() {
	string option, begin, new_coupon, temp_coupon=";;;;;";
	int times=1; // for entering coupon 
	//int number = 1; // number of times order done 
	cout << "----------------------------------------" << endl;
	cout << setw(23) << "== Welcome to Drone Delivery Services == " << endl;
	cout << setw(24) << "Current battery: " << battery << " %" << endl;
	cout << setw(20) << "Time: " << current_time() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	if (current_time() < 18 && current_time() > 7) { // if || then available all the time if && then only available between the time 
		cout<< setw(23) << "Thank you for choosing Drone Delivery Services!"<<endl;
		cout << "Would you like to start the day? (yes/no)" << endl;
		cin >> begin; //begin case to lower case
		if (begin == "yes" || begin == "Yes" || begin == "YES") {
			do {
				cout << "Starting Delivery number " << 1+total_delivery << ".."<<endl; //number changed to total_delivery
				if (delivery() == true) {
					for (int i = 0; i < 10000000; i++) {} // to lag the screen 
					cout << "Delivery successful!" << endl;
					cout << "Your price is Rs." << price << "."<<endl;
					cout << "Do you wish to enter coupon? (yes/no)" << endl;
					cin >> option;
					if (option == "yes" || option=="YES" || option=="Yes") {
						times = 1;
						while (times <= 3) {
							//cin >> option;
							cout << "Please enter coupon." << endl;
							cin >> new_coupon;
							if (new_coupon == temp_coupon) {
								cout << "You have successfully received 10% off on your order!" << endl;
								cout << "Your new price is " << (float)price * 0.90 <<"."<< endl;
								break;
							}
							else {
								cout << "Invalid coupon. You have " << 3 - times << " entries left." << endl;
							}
							times++;
						}
					}
					total_delivery++;
				}
					else {
						cout << "Delivery Unsuccessful." << endl;
						if (givecoupon==true) {
						temp_coupon = coupon();
						cout << setw(20) << "Your coupon is " << temp_coupon << ". Enter it for 10% off on your next order" << endl;
					    } 
						total_fails++;
					} 
				cout << right << "Battery remaining : " << battery << " %" << endl;
				price = 0;
				cout << "Would you like to continue?" << endl;
				cin >> begin;
				//number++;
			} while (begin == "yes" || begin == "Yes" || begin == "YES" );
		}
		cout << "Summary of activities:" << endl;
		display();
		cout << "Shutting down..."<<endl;
		cout <<  endl;
		cout<<setw(77) << "* Thank you for choosing Drone Delivery Services! *\n";
		cout<<setw(90) << "== We truly value our customers and look forward to serving you again ==";
	    cout<<endl<<endl<<endl<<endl;
	}
	else {
		cout << "Please use program from 8am to 6pm.\n";
		cout<<"Drone operations are limited to daytime hours (8:00 AM to 6:00 PM) because flying at night is unsafe-\n";
		cout<<"due to low visibility and increased risk of obstacles.\n";
		cout<<"Thank you for your understanding!"; // if time is not in ranges then throws this else
	}
	return 0;
}
int current_time() {
	time_t now = time(0);         // get current time
	tm* ltm = localtime(&now);       // convert to local time
	return ltm->tm_hour;
}

bool weather() {
		bool available=false;
		int W = (rand() % 6) + 1;
		if (W == 1) {
			cout << "Weather:  Rainy " << endl;
			available = false;
		}
		else if (W == 2) {
			cout << "Weather:  Windy " << endl;
			//srand(time(NULL));
			int chance = (rand() % 100) + 1;
			if (chance >= 90) {
				available = true;
			}
			else {
				available = false;
			}
		}
		else {
			cout << "Weather:  Sunny " << endl;
			available = true;
		}
		return available;
	}

bool weight(bool commence) { //here we can change weight since it is a user influenced variable while temp is not
	if (commence==true) {
	double num;
	cout << "What is the weight of package to be transported?(in kg) " << endl;
	cin >> num;
	if (num > 1 && num <= 40) {
		if (num <= 10) {
			battery -= (float)((float)num * 0.25);
			price += 10;
		}
		else if (num <= 20 && num>10) {
			battery -= (float)((float)num * 0.5);
			price += 20;
		}
		else if (num <= 30 && num>20) {
			battery -= (float)((float)num * 0.75);
			price += 30;
		}
		else if (num <= 40 && num>30) {
			battery -= (float)((float)num * 1.0);
			price += 40;
		}
		return true;
	    }
    else {
		givecoupon=false;
		return false;
	     }
	
	}
}

void display() {
	cout << "-------------------------------------" << endl;
	cout << setw(30) << "Battery remaining : " << battery << " %" << endl;
	cout << setw(30) << "Total deliveries : " << total_delivery << endl;
	cout << setw(30) << "Total fails : " << total_fails << endl;
	cout << "-------------------------------------" << endl;
}

bool delivery() {
	//bool y_n;
	if (destination() == false) {
		cout<<"Destination not found."<<endl;
		return false;
	}
	if (weight(destination) == false) {
		cout << "Please enter weight within the range 1-40 kg." << endl;
		return false;
	}
	if (power() == false) {
		return false;
	}
	if (weather() == false) {
		cout << "Weather is unfavorable right now, please try later.\nWe apologize for the inconvenience!" << endl;
		return false;
	}
	else
		return true;
}

bool power() {
	bool fly = true;
	if (battery < 30) {
		cout << "Battery is low --> Returning to base" << endl;
		charging();
		fly = false;
	}
	return fly;
}

void charging() {
	battery = 100;
}

bool destination() {
	int city;
	bool result=true;
	cout << "Choose your package destination: (Choose 1-5) " << endl;
	cout << "1. Lahore \n2. Islamabad \n3. Peshawar \n4. Karachi \n5. Faisalabad " << endl;
	cin >> city;
	switch (city) {
	case 1: {
		cout << "=> Routing to Lahore.." << endl;
		//destination = "Lahore";
		battery -= 0.25;
		price += 20;
		break;
	}
	case 2: {
		cout << "=> Routing to Islamabad.." << endl;
		battery -= 0.25;
		//destination = "Islamabad";
		price += 10;
		break;
	}
	case 3: {
		cout << "=> Routing to Peshawar.." << endl;
		battery -= 0.35;
		//destination = "Peshawar";
		price += 15;
		break;
	}
	case 4: {
		cout << "=> Routing to Karachi.. " << endl;
		battery -= 0.30;
		//destination = "Karachi";
		price += 50;
		break;
	}
	case 5: {
		cout << "=> Routing to Faisalabad.." << endl;
		battery -= 0.78;
		//destination = "Faisalabad";
		price += 30;
		break;
	}
	default: {
		result = false;
		givecoupon=false;
		  }
	}
	return result;
	//cout << "Your destination selected is " << destination;
}

string coupon() {
	string coupon;
	char random;
	//srand(time(NULL));
	for (int k = 0; k < 6; k++) {
		random = ((rand() % 74) + 48);
		while ((random >= 58 && random <= 64) || (random >= 91 && random <= 96)) {
			random = ((rand() % 74) + 48);
		}
		coupon += random;
	}
	return coupon;
}
