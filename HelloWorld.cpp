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
int main() {
	string option, begin, new_coupon, temp_coupon=";;;;;";
	int times=1; // for entering coupon 
	//int number = 1; // number of times order done 
	cout << "-------------------------------------" << endl;
	cout << setw(23) << "Welcome" << endl;
	cout << setw(23) << "current battery " << battery << " %" << endl;
	cout << setw(23) << "Time: " << current_time() << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
	if (current_time() < 20 && current_time() > 7) { // if || then available all the time if && then only available between the time 
		cout << "Would you like to start the day? (yes/no)" << endl;
		cin >> begin; //begin case to lower case
		if (begin == "yes" || begin == "Yes" || begin == "YES") {
			do {
				cout << "Delivery number: " << 1+total_delivery << endl; //number changed to total_delivery
				//cout <<setw(20) << "Your coupon is " << temp_coupon <<endl;
				//cout << "enter the coupon at the end for 15% off " << endl;
				//destination();
				if (delivery() == true) {
					for (int i = 0; i < 10000000; i++) {} // to lag the screen 
					cout << "delivery successful" << endl;
					cout << "Your price is " << price << endl;
					cout << "Do you wish to enter coupon (yes/no)" << endl;
					cin >> option;
					if (option == "yes") {
						times = 1;
						while (times <= 3) {
							//cin >> option;
							cout << "enter coupon" << endl;
							cin >> new_coupon;
							if (new_coupon == temp_coupon) {
								cout << "you have received 10% off on your order" << endl;
								cout << "Your new price is " << (float)price * 0.90 << endl;
								break;
							}
							else {
								cout << "wrong try. You have " << 3 - times << " tries left" << endl;
							}
							times++;
						}
					}
					total_delivery++;
				}
					else {
						cout << "delivery unsuccessful" << endl;
						temp_coupon = coupon();
						if (check == 0) {
							cout << setw(20) << "Your coupon is " << temp_coupon << ". Enter it for 10% off on your next order" << endl;
						}
						check = 0;
						total_fails++;
					}
				cout << right << "Battery remaining : " << battery << " %" << endl;
				price = 0;
				cout << "Would you like to continue?" << endl;
				cin >> begin;
				//number++;
			} while (begin == "yes" || begin == "Yes" || begin == "YES" );
		}
		cout << "Here is the summary of the day" << endl;
		display();
		cout << "Shutting down...";
	}
	else {
		cout << "Please use program from 8am to 6pm."; // if time is not in ranges then throws this else
	}
}
int current_time() {
	time_t now = time(0);         // get current time
	tm* ltm = localtime(&now);       // convert to local time
	return ltm->tm_hour;
}

/*bool day() {
	int hour = current_time();
	bool available;
	if (hour > 8 && hour<18) {
		available = true;
	}
	else
		available = false;
	return available;
}
*/
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

bool weight() { //here we can change weight since it is a user influenced variable while temp is not
	double num;
	cout << "What is the weight of items transported in kgs" << endl;
	cin >> num;
	if (num > 1 && num < 39) {
		if (num < 10) {
			battery -= (float)((float)num * 0.25);
			price += 10;
		}
		else if (num < 20) {
			battery -= (float)((float)num * 0.5);
			price += 20;
		}
		else if (num < 30) {
			battery -= (float)((float)num * 0.75);
			price += 30;
		}
		else if (num < 40) {
			battery -= (float)((float)num * 1.0);
			price += 40;
		}
		return true;
	}
	else {
		check = 1;
		return false;
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
	if (weight() == false) {
		cout << "Please enter weight within range 1-39" << endl;
		return false;
	}
	if (power() == false) {
		return false;
	}
	if (destination() == false) {
		return false;
	}
	if (weather() == false) {
		cout << "weather is unfavorable right now, Please try later" << endl;
		return false;
	}
	else
		return true;
}

bool power() {
	bool fly = true;
	if (battery < 30) {
		cout << "low battery. Returning to base" << endl;
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
	cout << "enter destination of drone" << endl;
	cout << "1. Lahore \n2. Islamabad \n3. Peshawar \n4. Karachi \n5. Faisalabad " << endl;
	cin >> city;
	switch (city) {
	case 1: {
		cout << "Drone is going to Lahore." << endl;
		//destination = "Lahore";
		battery -= 0.25;
		price += 20;
		break;
	}
	case 2: {
		cout << "Drone is going to Islamabad." << endl;
		battery -= 0.25;
		//destination = "Islamabad";
		price += 10;
		break;
	}
	case 3: {
		cout << "Drone is going to Peshawar." << endl;
		battery -= 0.35;
		//destination = "Peshawar";
		price += 15;
		break;
	}
	case 4: {
		cout << "Drone is going to Karachi . " << endl;
		battery -= 0.30;
		//destination = "Karachi";
		price += 50;
		break;
	}
	case 5: {
		cout << "Drone is going to Faisalabad." << endl;
		battery -= 0.78;
		//destination = "Faisalabad";
		price += 30;
		break;
	}
	default: {
		result = false;
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
