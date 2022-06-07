#include <iostream>

using namespace std;

class Fraction {
	private:
		int whole_number;
		int numerator;
		int denominator;
	public:	
		Fraction (int, int);
		Fraction (int, int,int);
		static const char symbol = '-';
		void enterFractionValue ();
		void reduceFraction();
		void displayFraction();
		bool checkFraction();
		friend int gcd(int, int);
		friend Fraction operator*(const Fraction& , const Fraction&);
		friend Fraction operator+(const Fraction& , const Fraction&);
		friend void askUserForAnswer();

};

class MathProblem {
	private:
		Fraction f1;
		Fraction f2;
		Fraction user_ans;
		Fraction ans;
		char operation ;
		bool isAnswerCorrect;
	public:	
		void setProblem(Fraction, char , Fraction);
		void displayProblem();
		friend void askUserForAnswer();
		void checkAns ();
		friend Fraction operator*(const Fraction& , const Fraction&);
		friend Fraction operator+(const Fraction& , const Fraction&);	
};


void askUserForAnswer(){
	cout<<"Enter the numerator : ";
	cin>>MathProblem::user_ans.numerator;
	cout<<"Enter the denominator : ";
	cin>>user_ans.denominator;
	
}

bool MathProblem :: checkAns(){
	
	if(user_ans == ans)
		isAnswerCorrect = true;
	else 
		isAnswerCorrect = false;
	return isAnswerCorrect;
}

Fraction operator*(const Fraction& a , const Fraction& b ){
	Fraction extra(0,0,0);
	
	extra.numerator = a.numerator * b.numerator;
	extra.denominator = a.denominator * b.denominator;
	
	return extra;
}
Fraction operator+(const Fraction& a, const Fraction& b){
	Fraction extra(0,0,0);
	
}


void MathProblem::displayProblem(){
	f1.displayFraction(); 
	cout<<"  + "<<endl<<endl;
	f2.displayFraction();
	cout<<" = ";
} 



void MathProblem::setProblem(Fraction a, char op , Fraction b){
	f1 = a;
	f2 = b;
	
	operation = op;

	if(operation == '*'){
		ans = f1 * f2;
	}
	else
		ans = f1 + f2;
}



Fraction::Fraction(int n=0, int d=1){
	whole_number = 0;
	numerator = n;
	if(d == 0)
		denominator = 1;
	else
		denominator = d;
}

Fraction::Fraction(int a, int b , int w ){
	whole_number = w;
	numerator = a;
	if(b == 0)
		denominator = 1;
	else
		denominator = b;
}

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
		
		while(whole_number*denominator <= numerator){
			whole_number++;
		}
		whole_number--;
		numerator = numerator - (whole_number * denominator);	 
	}
}

void Fraction::displayFraction(){
	if(whole_number != 0)
		cout<<"  "<<numerator<<endl<< whole_number<<" "<<symbol<<endl<<"  "<<denominator<<endl<<endl; //print the fraction
	else
		cout<<"  "<<numerator<<endl<<"  "<<symbol<<endl<<"  "<<denominator<<endl<<endl;
}


int main (){
	bool answer = false;
	
	Fraction f1(1,2,0);
	Fraction f2(1,4,0);
	
	MathProblem ex1;
	
	ex1.setProblem(f1,'*',f2);
	ex1.displayProblem();
	ex1.askUserForAnswer();
	answer = ex1.checkAns();
	
	cout<<answer;

	
}
