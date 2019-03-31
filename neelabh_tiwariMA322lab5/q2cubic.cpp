//This is a program to implement cubic spline interpolation on f(t) = sqrt(t) ---- Neelabh Tiwari 160123024

#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<"\nThis is a program to implement cubic spline interpolation on f(t) = sqrt(t)\n\n";
	int n;
    cout<<"\nEnter the no. of original data points to be given (Eg. 10)   -   "; 
    cin>>n;
    //n=10;
    
    //Algorithm Given in Book - Pg. 353 Kincaid Ed. 3
    
	float t[n+1];
	float y[n+1];

	t[0]=0;
	y[0]=0;

	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+0.225;
		y[i]=sqrt(t[i]);
	}

	float h[n],b[n],u[n],v[n],z[n+1];

	for(int i=0;i<=n-1;i++){
		h[i]=t[i+1]-t[i];
		b[i]=6*(y[i+1]-y[i])/h[i];
	}

	u[1]=2*(h[0]+h[1]);
	v[1]=b[1]-b[0];
	
	for(int i=2;i<=n-1;i++){
		u[i]=2*(h[i]+h[i-1])-(h[i-1]*h[i-1])/u[i-1];
		v[i]=b[i]-b[i-1]-h[i-1]*v[i-1]/u[i-1];
	}
	
	z[n]=0;
	for(int i=n-1;i>0;i--){
		z[i]=v[i]-h[i]*z[i+1]/u[i];
	}
	z[0]=0;
	
	/*
	cout<<"\n\nThe values of Z are as following - \n";
	
	for(int i=0;i<=n;i++)	{
		cout<<z[i]<<"  ";
	}
	*/
	cout<<"\n\n";
	
	cout<<"Give number of Query Points - ";
	int yo; cin>>yo;
	cout<<"\n-----------------------------------------\n\n";

	for(int i=0;i<yo;i++){
		float xx;
		cout<<"Enter value of x - ";
		cin>>xx;
	
		double xd=xx/0.225;
		int index=floor(xd);
		double tid=0.225*(index);

		cout<<fixed<<setprecision(7);
		//cout<<tid<<endl;
	
		float A,B,C;
		A=(z[index+1]-z[index])/(6*h[index]);
		B=z[index]/2;
		C= ((-h[index]*z[index+1])/6)-1*((h[index]*z[index])/3)+(y[index+1]-y[index])/h[index]; 
		float ans=y[index]+(xx-tid)*(C+(xx-tid)*(B+(xx-tid)*A));
		cout<<"\nThe values at this point are - \n\n";
		cout<<"Original - "<<sqrt(xx)<<" \nCalculated by Cubic Spline - "<<ans<<endl;
		cout<<"\nThe Error is - "<<abs(ans-sqrt(xx))<<"\n\n";
		cout<<"-----------------------------------------\n\n";
	}
	
	return 0;

}
