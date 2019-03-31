//Solving u''=u+x ( u(0)=0, u(1)=1 ) using finite difference method and Shooting Method ---- Neelabh Tiwari 160123024

#include<bits/stdc++.h>
using namespace std;

void fdm(long double m){
	
	long double h=(1-0)/(m+1);
	
	int n=(int)m;
	
	long double A[n];
	long double B[n];
	long double C[n];

	for(int i=0;i<n;i++){
		A[i]=-0.5;
		B[i]=1+(h*h)/(2.0);
		C[i]=-0.5;
	}
	
	long double a[n][n];
	long double u[n][1];
	long double b[n][1];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) a[i][j]=B[i];
			else if(j==i-1) a[i][j]=A[i];
			else if(j==i+1) a[i][j]=C[j];
			else a[i][j]=0;
		}		
	}
	
	long double u0=0; long double u1=1;
	
	for(int i=0;i<n;i++){
		long double x=(-1)*(h)*(i+1);
		if(i==0)	b[i][0]=x;
		else if(i==n-1)	b[i][0]=x+(1.0/(h*h));
		else b[i][0]=x;
		b[i][0]=((h*h)/(2.0))*b[i][0];
	}	
	
	long double alp[n-1];
	
	for(int i=0;i<n-1;i++){
		if(i==0) alp[i]=a[i][i+1]/a[i][i];
		else alp[i]=a[i][i+1]/(a[i][i]-a[i][i-1]*alp[i-1]);
	}
	
	long double d[n];
	
	for(int i=0;i<n;i++){
		if(i==0)	d[i]=b[i][0]/a[i][i];
		else d[i] = ( b[i][0] - a[i][i-1]*d[i-1] ) / (a[i][i] - a[i][i-1]*alp[i-1]);
	}
	
	u[n-1][0]=d[n-1];
	
	for(int i=n-2;i>=0;i--){
		u[i][0] = d[i] - alp[i]*u[i+1][0];
	}
	
	cout<<"\nSolving u'' = u + x ( u(0)=0, u(1)=1 ) using finite difference method for n = "<<m<<endl;
	cout<<"\nFollowing values are obtained - \n\n";	
	
	cout<<"For x = 0 :: "<<u0<<endl;
	for(int i=0;i<n;i++){
		cout<<"For x = "<<(i+1)*h<<" :: "<<u[i][0]<<endl;
	}
	cout<<"For x = 1 :: "<<u1<<endl<<endl;
	return;
}


int main(){
	cout<<"\nEnter the value of n (number of node points = n+2)  :  "; 
	long double n=9.0; //number of nodes = n+2
	cin>>n;
	//mesh size = (1-0)/(n+1)
	fdm(n);
	//shooting(); 
	return 0;
}
