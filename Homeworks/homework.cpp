#include <iostream>

using namespace std;

class Fraction {
	private:
		int whole_number;
		int numerator;
		int denominator;
		static const char symbol = '-';
	public:	
		void enterFractionValue ();
		void reduceFraction();
		void displayFraction();
		bool checkFraction();
		friend int gcd(int, int);

};

bool Fraction::checkFraction(){
	if(numerator == 0  && whole_number == 0){
		return false;
	}
	else {
		return true;
	}
}

int gcd(int a, int b){
	if (a == 0)
        return b;
    return gcd(b % a, a);
}

void Fraction::enterFractionValue(){
	cout<<"Enter the value for the whole number : ";
	cin>>whole_number;
	cout<<"Enter the valued for the numerator : ";
	cin>>numerator;
	
	do{	
	cout<<"Enter the value for the denominator (the denominator cant be 0) : ";
	cin>>denominator;
	}while(denominator == 0);
}

void Fraction::reduceFraction (){
	if(whole_number == 0){
		int d = gcd(numerator,denominator);
		numerator = numerator / d;
		denominator = denominator / d;
	}
	else{
		numerator = whole_number*denominator + numerator;
		whole_number = 0;
		
		int d = gcd(numerator,denominator);
		numerator = numerator / d;
		denominator = denominator / d;
		
		while(whole_number*denominator < numerator){
			whole_number++;
		}
		whole_number--;
		numerator = numerator - (whole_number * denominator);	 
	}
}

void Fraction::displayFraction(){
	cout<<"  "<<numerator<<endl<< whole_number<<" "<<symbol<<endl<<"  "<<denominator<<endl<<endl; //print the fraction
}

int main (){
	Fraction user_fraction;
	bool fraction_cancel = false;
	do{	
	user_fraction.enterFractionValue();
	cout<<"The Fraction : "<<endl;
	user_fraction.displayFraction();
	user_fraction.reduceFraction();
	cout<<"The reduced Fraction : "<<endl;
	user_fraction.displayFraction();
	fraction_cancel = user_fraction.checkFraction();
	}while(fraction_cancel);
}
