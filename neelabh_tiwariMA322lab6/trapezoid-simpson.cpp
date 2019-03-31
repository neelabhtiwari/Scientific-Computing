//Composite Trapezoidal and Simpson's Rule ------- Neelabh Tiwari 160123024

#include<bits/stdc++.h> 
using namespace std;

double f(double x){ 
    return (x*x)/(1+x*x*x); 
} 

double ans(double x){ 
	double prod=log(1+x*x*x);
    return prod/3; 
} 

void comp_trapezoid(double a,double b,double n){ 
   
    double h=(b-a)/n; 
    double sum=0; 
  
    
    for(int i=1;i<n;i++){
    	sum+=2*f(a+i*h);
    } 
         
  	sum+=f(a)+f(b);
  	
    sum=(h/2)*sum;

    double exact=ans(1)-ans(0);
    
    cout<<"\nBy Composite Trapezoid Rule : \n";
    
    cout<<"\nThe result obtained from numerical integration of ( x*x / (1 + x*x*x) ) from 0 to 1 is    -     "<<sum<<"\n\n";
	cout<<"The result obtained from mathematical integration of ( x*x / (1 + x*x*x) ) from 0 to 1 is    -     "<<exact<<"\n\n";
	cout<<"The absolute error is   -   "<<abs(sum-exact)<<endl<<endl;
	cout<<"The relative error is   -   "<<abs(sum-exact)/(abs(exact))<<endl<<endl;
	
	cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
	
	return;
       
} 
  
  
void comp_simpson(double a,double b,double n){ 

    double h=(b-a)/n; 
    double x[(int)n+1],fx[(int)n+1]; 
  

    for (int i=0;i<=n;i++){ 
        x[i]=a+i*h; 
        fx[i]=f(x[i]); 
    } 
  

    double sum=0; 
    
    for(int i=0;i<=n;i++){ 
        if(i==0||i==n) 
            sum+=fx[i]; 
        else if(i%2!=0) 
            sum+=4*fx[i]; 
        else
            sum+=2*fx[i]; 
    } 
    
    sum=sum*(h/3); 
  
 	double exact=ans(1)-ans(0); 
 	 
	cout<<"\nBy Composite Simpson's Rule : \n";
    
    cout<<"\nThe result obtained from numerical integration of ( x*x / (1 + x*x*x) ) from 0 to 1 is    -     "<<sum<<"\n\n";
	cout<<"The result obtained from mathematical integration of ( x*x / (1 + x*x*x) ) from 0 to 1 is    -     "<<exact<<"\n\n";
	cout<<"The absolute error is   -   "<<abs(sum-exact)<<endl<<endl;
	cout<<"The relative error is   -   "<<abs(sum-exact)/(abs(exact))<<endl<<endl;

	return;

} 

int main(){ 

    float a = 0; 
    float b = 1; 
    int n = 10; 
  
  	cout.precision(8);
  	cout<<fixed;
  	
    comp_trapezoid(a,b,n);
    comp_simpson(a,b,n);
     
    return 0; 
} 
