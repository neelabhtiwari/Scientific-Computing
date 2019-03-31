//This is the program to compute the solution of following Partial Differenctial Equation using Weighted average (theta) method ------ Neelabh Tiwari 160123024
// Uxx = Ut (t>=0, 0<=x<=pi), U(x,0) = sin(x), U(0,t) = 0 (t>=0), U(pi,t) = 0 (t>=0)  ---- One Dimensional Heat Equation                                                       

#include <bits/stdc++.h>
using namespace std;

vector<double> tridi_thoalg(vector <vector <double> > &A, vector <double> &B, double n){
	
	vector<double> alpha(n-1, 0);
	alpha[0] = A[0][1]/A[0][0];
	vector<double> r(n-1, 0);
	r[0] = B[0]/A[0][0];
	for(int i=1;i<n-1;i++){
		alpha[i] = A[i][i+1]/(A[i][i] - A[i][i-1]*alpha[i-1]);
		r[i] = (B[i] - A[i][i-1]*r[i-1])/(A[i][i] - A[i][i-1]*alpha[i-1]);
	}
	
	vector<double> U(n-1, 0);
	U[n-2] = r[n-2];
	for(int i=n-3;i>=0;i--){
		U[i] = r[i] - alpha[i]*U[i+1];
	}


	return U;

}

int main(){
	cout<<"\nProgram to solve Uxx = Ut (t>=0, 0<=x<=pi), U(x,0) = sin(x), U(0,t) = 0 (t>=0), U(pi,t) = 0 (t>=0) ---- One Dimensional Heat Equation\n\n";
	cout<<"Enter the value of theta ------- ";
	double q;
	cin>>q;
	
	double h=(atan(1)*4)/10;
	int n=(atan(1)*4)/h;
	cout<<"\n\nThe value of n is "<<n<<endl<<endl;
	
	double k;
	if(q<=0.5){
	k=h*h/(2*(1-2*q));
	}
	else{
		k=0.2;
	}
	
	cout<<"The value of h is "<<h<<endl<<endl;
	cout<<"The value of k is "<<k<<endl<<endl;
	
	vector<double> arr(n+1,0),brr(n+1,0);
	int i,j;
	double x=h;

	for(i=1;i<n;i++){
		arr[i]=sin(x);
		x+=h;
	}
	
	double b=k/(h*h);
	int z=100;
	
	while(z--){
		vector<vector<double> > A(n-1,vector <double>(n-1,0));
		vector<double> B(n-1,0);

		for(i=1;i<=n-1;i++){
				B[i-1]=(-(1-q)*2*b+1)*arr[i]+((1-q)*b)*arr[i-1]+((1-q)*b)*arr[i+1];
		}

		for(i=0;i<n-1;i++){
			A[i][i]=1+2*q*b;
		}
	
		for(i=0;i<n-2;i++){
			A[i][i+1]=-b*q;
		}
	
		for(i=1;i<n-1;i++){
			A[i][i-1]=-b*q;
		}

		vector <double> U=tridi_thoalg(A,B,n);

		for(i=1;i<n;i++){
			arr[i]=U[i-1];
		}
	}
	
	cout<<"\nTemperature at n+2 points (x0 = 0 to x(n+1) = 1) with spacing of "<<h<<" are as following -- \n\n";
	
	for(i=0;i<=n;i++){
		cout<<arr[i]<<"  ";
	}
	
	cout<<endl<<endl;
	
	return 0;
}
