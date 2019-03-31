#include<bits/stdc++.h>
using namespace std;

long double maxerror;
long double bisroot;

void print(){
	cout<<"x^3 + x + 1"<<endl;
}

long double f(long double x){
	return x*x*x+x+1;
}

long double derf(long double x){
	return 3*x*x+1;
}

int sign(long double u){
	if(u>=0) return 1;
	else return -1;
}

void bisection(){
	cout.precision(15);
	cout<<fixed;
	long double a=-1,b=0;
	long double u=f(a); 
	long double v=f(b);
	
	if( sign(u) == sign(v) ){
		cout<<"Starting points 'a' and 'b' are incorrect"<<endl;
		return; 
	}
	
	long double c=a;
	long double e=b-a;
	long double w;
	long double cnt=0;	
		
	while(1){
		cnt++;
		e=e/2;
		c=a+e;
		w=f(c);
		
		if(abs(w) <= maxerror) break;
		else if( sign(w) != sign(u) ){
			b=c;
			v=w;
		}
		else{
			a=c;
			u=w;
		}
	}
	
	cout<<"\nRoot Of the given function using Bisection method is "<<c<<endl;
	cout<<"The value of function at this point is "<<w<<endl;
	cout<<"The error is "<<abs(w)<<endl;
	cout.precision(0);
	cout<<"The number of iterations done are : "<<cnt<<endl; 
	bisroot=c;
	return;
}


void newton(){
	long double seed=1;
	cout<<"\nRoot Of the given function using Newton's method (seed = "<<seed<<")"<<" ";
	cout.precision(15);
	cout<<fixed;
	long double x,w,der;
	x=seed;
	int cnt=0;
	
	while(1){
		cnt++;
		w=f(x); der=derf(x);
		x=x-w/der;
		w=f(x);
		if(abs(w) <= maxerror) break;
	}
	
	cout<<"is "<<x<<endl;
	cout<<"The value of function at this point is "<<w<<endl;
	cout<<"The error is "<<abs(w)<<endl;
	cout.precision(0);
	cout<<"The number of iterations done are : "<<cnt<<endl; 
	return;
}


void secant(){
	cout.precision(15);
	cout<<fixed;
	long double x0=-1; long double x1=1;
	long double y0=f(x0); long double y1=f(x1);
	
	int cnt=0;
	
	while(1){
		cnt++;
				
		long double x = x1 - ((x1-x0) * y1) / (y1-y0);
		long double y = f(x);
		
		x0=x1;
		y0=y1;
		x1=x;
		y1=y;
		
		if(abs(f(x1))<=maxerror) break;			
	}
	
	long double w=f(x1);
	
	cout<<"\nRoot Of the given function using Secant method is "<<x1<<endl;
	cout<<"The value of function at this point is "<<w<<endl;
	cout<<"The error is "<<abs(w)<<endl;
	cout.precision(0);
	cout<<"The number of iterations done are : "<<cnt<<endl; 
	return;

}


void mfp(){
	cout.precision(15);
	cout<<fixed;
	long double x0=-1; long double x1=1;
	long double y0=f(x0); long double y1=f(x1);
	long double x,y;
	
	int cnt=0;
	
	while(1){
		cnt++;
				
		x = x1 - ((x1-x0) * y1) / (y1-y0);
		y = f(x);
		
		if(y==0) break;
		else if(abs(y)<=maxerror) break;
		
		if(sign(y)!=sign(y0)){
			x1=x;
			y1=y;
		}
		else{
			x0=x;
			y0=y;
		}	
	}
	
	long double w=f(x);
	
	cout<<"\nRoot Of the given function using Secant method is "<<x<<endl;
	cout<<"The value of function at this point is "<<w<<endl;
	cout<<"The error is "<<abs(w)<<endl;
	cout.precision(0);
	cout<<"The number of iterations done are : "<<cnt<<endl; 
	return;
}


int main(){
	cout<<"We're finding the roots for the following function : "<<endl;
	cout<<endl;
	print();
	
	cout<<"\nGive the maximum permissible error (Eg. - 0.00001) :   ";
	cin>>maxerror;

	cout<<"\nRoots will be calculated by following four methods : "<<endl;
	cout<<"\n1. Bisection Method\n2. Newton's Method\n3. Secant Method\n4. Method of false position\n\n";
	
	cout<<"Results and error analysis of each method :\n";
	
	cout<<"\nBy Bisection Method - \n";
	bisection();
	
	cout<<"\nBy Newton's Method - \n";
	newton();
	
	cout<<"\nBy Secant Method - \n";
	secant();
	
	cout<<"\nBy Method of False Position - \n";
	mfp();
	
	cout<<endl;
	return 0;
}

