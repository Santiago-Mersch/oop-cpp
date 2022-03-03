#include <iostream>

using namespace std; 

class MyClass {
	public:
		int myNum;
		string myString;
};


int main (){
	MyClass myObj;
	
	myObj.myNum = 10;
	myObj.myString = "Santiago";
	
	cout<<"The number of my object is : "<< myObj.myNum <<endl<< "The name of my object is : "<<myObj.myString;
	
	
	
}



