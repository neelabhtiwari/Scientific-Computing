//This is a program to solve an ODE using Euler's Forward method and Runge-Kutta 4th Order methrod  --------- Neelabh Tiwari  160123024

#include<bits/stdc++.h>
using namespace std;


double f(double t,double x){
	return (t*x-x*x)/(t*t);
}
double u(double t){
	return t/(0.5 + log(t));
}

void rungekutta(){
	double n=20;
	double h=2/n;	//Mesh spacing
	double t=1.0;  	//initial conditions
	double x=2.0;	//initial conditions
	//Solving for values from t=1.o to t=3.0
	cout<<"-----------------------------------------Runge Kutta Fourth Order Results---------------------------------------------\n\n";
	for(int i=1;i<=(int)n;i++){
		double f1=h*f(t,x);
		double f2=h*f(t+h/2,x+f1/2);
		double f3=h*f(t+h/2,x+f2/2);
		double f4=h*f(t+h,x+f3);
		x=x+(f1+2*f2+2*f3+f4)/6;
		t=t+h;
		double e=fabs(u(t)-x);
		cout.precision(1);
		cout<<fixed;
		cout<<"Exact Value at t = "<<t;
		cout.precision(8);
		cout<<fixed;
		cout<<" is u("<<t<<") = "<<u(t)<<" ---- Computed Value at t = "<<t<<" is u["<<i<<"] = "<<x<<" and absolute error is ";
		cout<<e<<endl;
	}
	return;
}

void eulerforward(){
	double t=1.0;	//Initial conditions
	double x=2.0;		//Initial conditions
	double n=20;
	double h=2/n;    //Mesh Spacing
	//Solving for values from t=1.o to t=3.0
	cout<<"\n-----------------------------------------Euler's Explicit (Forward) Method---------------------------------------------\n\n";
	for(int i=1;i<=(int)n;i++){
		x=x+h*f(t,x);		
		t=t+h;
		double e=fabs(u(t)-x);
		cout.precision(1);
		cout<<fixed;
		cout<<"Exact Value at t = "<<t;
		cout.precision(8);
		cout<<fixed;
		cout<<" is u("<<t<<") = "<<u(t)<<" ---- Computed Value at t = "<<t<<" is u["<<i<<"] = "<<x<<" and absolute error is ";
		cout<<e<<endl;	
	}
	cout<<"\n";
	return;
}

int main(){
	
	cout<<"\nGiven ---- x' = (t*x-x*x)/(t*t) Initial Conditions :: x(1)=2\n\n";
	cout<<"Solving for values from t=1.0 to t=3.0 with 20 nodal points :: mesh spacing (h) = 0.1\n\n";
	
	rungekutta();
	eulerforward();
	
	return 0;
}
