//Integrating exp(-x^2)cos(x) over [-1,1] using Gauss Legendre, Gauss-Chebyshev, Gauss-Hermite integration, Simpson rule and Romberg integration ----- Neelabh Tiwari 160123024

#include<bits/stdc++.h>
using namespace std;

void decrep(){
	cout.precision(8);
	cout<<fixed;
	return;
}

double pi = M_PI;

//Gauss Legendre ---------------------------------------------------------------------------------

double fgl(double x){
	return exp(-x*x)*cos(x);
}
void gl(){
	//n=3 (3 Point Gauss Legendre)
	
	double x0 = -0.77459666924;
	double x1 = 0;
	double x2 = 0.77459666924;
	
	double ans = (5.0/9)*fgl(x0) + (8.0/9)*fgl(x1) + (5.0/9)*fgl(x2);
	
	cout<<"The answer calculated using Gauss Legendre (3 Point) is  ------  "<<ans<<endl<<endl; 
	return;
}

//Gauss Chebyshev --------------------------------------------------------------------------------

double fgc(double x){
	return exp(-x*x)*cos(x)*sqrt(1-x*x);
}
void gc(){
	//n=3 (3 Point Gauss Chebyshev)
	
	double x0 = -0.86602540378;
	double x1 = 0;
	double x2 = 0.86602540378;
	
	double ans = (pi/3)*fgc(x0) + (pi/3)*fgc(x1) + (pi/3)*fgc(x2);
	
	cout<<"The answer calculated using Gauss Chebyshev (3 Point) is  ------  "<<ans<<endl<<endl; 
	return;
}

//Gauss Hermite ---------------------------------------------------------------------------------

double fgh(double t){
    double ret = (2/pi) * (1/(1+t*t)) * cos((2/pi)*atan(t)) * exp(t*t-pow(((2/pi)*atan(t)),2));
    return ret;    
}
void gh(){
	double ans = (sqrt(pi)/6.0)*( fgh(-sqrt(6.0)/2.0) + 4*fgh(0) + fgh(sqrt(6)/2.0) ); 	
	cout<<"The answer calculated using Gauss Hermite Method is  ------  "<<ans<<endl<<endl; 
	return;
}

//Simpson ----------------------------------------------------------------------------------------

void simpson(){ 
	
	//n=17 (18 Points)
	double a = -1.0; double b = 1.0; double n=17;
    double h=(b-a)/n;
     
    double x[(int)n+1],fx[(int)n+1]; 
  

    for (int i=0;i<=n;i++){ 
        x[i]=a+i*h; 
        fx[i]=fgl(x[i]); 
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
  
	cout<<"The answer calculated using Simpson's 1/3rd rule (n = 17) is  ------  "<<sum<<endl<<endl; 
	return;

}

//Romberg ---------------------------------------------------------------------------------------

void romberg() {
	
	//n=5 point 
	int N = 5;
	double a = -1; double b = 1;
    double h[N+1],r[N+1][N+1];
    for(int i=1;i<N+1;i++){
        h[i]=(b-a)/pow(2,i-1);
    }
    r[1][1]=h[1]/2*(fgl(a)+fgl(b));
    
    for(int i=2;i<N+1;i++){
        double coeff = 0;
        for(int k=1;k<=pow(2,i-2);k++){
            coeff+=fgl(a+(2*k-1)*h[i]);
        }
        r[i][1]=0.5*(r[i-1][1]+h[i-1]*coeff);
    }
    
    for(int i=2;i<N+1;i++){
        for(int j=2;j<=i;j++){
            r[i][j]=r[i][j-1]+(r[i][j-1]-r[i-1][j-1])/(pow(4,j-1)-1);
        }
    }
    
    cout<<"The answer calculated using Romberg Method is  ------  "<<r[N][N]<<endl<<endl; 
	return;
}

int main(){
	
	cout<<"\nThis is program to integrate exp(-x^2)cos(x) over [-1,1] using Gauss Legendre, Gauss-Chebyshev, Gauss-Hermite integration, Simpson's rule and Romberg integration"<<endl<<endl<<endl;
	
	decrep();
	gl();
	gc();
	gh();
	simpson();
	romberg();
		
	return 0;
}
