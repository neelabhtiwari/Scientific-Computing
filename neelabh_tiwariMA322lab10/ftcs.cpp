//This is the program to compute the solution of following Partial Differenctial Equation using Forward Time Central Space (FTCS) scheme.  ------ Neelabh Tiwari 160123024
// Uxx = Ut (t>=0, 0<=x<=pi), U(x,0) = sin(x), U(0,t) = 0 (t>=0), U(pi,t) = 0 (t>=0)  ---- One Dimensional Heat Equation                                                       

#include<bits/stdc++.h>
using namespace std;

float pi=3.14159;

float g(float x){
	return sin(x);
}
float a(float x){
	return 0;
}
float b(float x){
	return 0;
}

void ftcs(float n, float k, float m){
	
	float h=pi/(n+1);       //Number of mesh points on space axis = n+2
	float beta=(1*k)/(h*h);   //alpha = 1 (specific Heat)	
	
	float w[(int)n+2];
	float v[(int)n+2];
	
	for(int i=0;i<=n+1;i++){
		w[i]=g(i*h);
	}
	w[0]=0; w[(int)n+1]=0;
	float t=0;
	
	cout<<"\nTemperature at n+2 points (x0 = 0 to x(n+1) = 1) with spacing of "<<h<<" are as following -- \n\n";
	
	cout<<"At t = "<<t<<" --- ";
	for(int i=0;i<=n+1;i++){
		cout<<w[i]<<"  ";
	}
	cout<<endl;
	
	for(int j=1;j<=m;j++){
		v[0]=a(j*k);
		v[(int)n+1]=b(j*k);		
	
		for(int i=1;i<=n;i++){
			v[i]=beta*w[i-1]+(1-2*beta)*w[i]+beta*w[i+1];
		}
		t=j*k;
		cout.precision(3);
		cout<<"At t = "<<t<<" --- ";
		for(int i=0;i<=n+1;i++){
			cout<<w[i]<<"  ";
		}
		cout<<endl;
		
		for(int i=1;i<=n;i++){
			w[i]=v[i];
		}
	}
	
	return;	
	
}

int main(){
	
	float n=10,k=0.1,m=50;
	
	cout<<"\nProgram to solve Uxx = Ut (t>=0, 0<=x<=pi), U(x,0) = sin(x), U(0,t) = 0 (t>=0), U(pi,t) = 0 (t>=0) ---- One Dimensional Heat Equation\n\n";
	cout<<"Give value of n,k and m (Number of mesh points on space axis = n+2), (time axis spacing = k) and (Tmax = m*k)  :::::  (Eg - 5, 0.1, 20)  ";
	cin>>n>>k>>m;    
	
	ftcs(n,k,m);
	cout<<endl;
	return 0;
}
