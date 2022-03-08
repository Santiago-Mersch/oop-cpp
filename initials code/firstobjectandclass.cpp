#include <iostream>

using namespace std;

class Car {       // The class
  public:             // Access specifier
    string model;
	int wheels ;        // Attribute (int variable)
    string color;
    int motor ;
    
    void show (){
    cout<<"Model : "<<model<<endl;
	cout<<"Wheels: "<<wheels<<endl;
	cout<<"Color : "<<color<<endl;
	cout<<"Motor : "<<motor<<endl;
	}
	
	void turnOn (){
	cout<<"The car is on ";
	}
	
};


int main (){

	Car fordFiesta;
	
	fordFiesta.model = "Ford Fiesta";
	fordFiesta.color= "blue";
	fordFiesta.wheels = 4;
	fordFiesta.motor = 1600;
	
	fordFiesta.show();
	
	
	string turn;
	cout<<"You want to turn on the car ? (Y/N) ";
	cin>>turn;
	
	if (turn == "y" || turn == "Y"  ){
	fordFiesta.turnOn();
	}
	
	
}






