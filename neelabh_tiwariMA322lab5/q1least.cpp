//This is a program to linear fit a set of data points ----- Neelabh Tiwari 160123024

#include<bits/stdc++.h>
using namespace std;

int main(){

	cout<<"\n\nThis is a program to linear fit a set of data points.\n\n";
	
    int n;
    cout<<"\nEnter the no. of data points to be given   -    "; 
    cin>>n;
    
    double x[n],y[n];
    
    cout<<"\nEnter the "<<" "<<n<<" X-axis values - \n\n";                
    for(int i=0;i<n;i++)	cin>>x[i];
        
	cout<<"\nEnter the corresponding"<<" "<<n<<" Y-axis values - \n\n";
    for(int i=0;i<n;i++)	cin>>y[i];
    
    double xs=0,x2s=0,ys=0,xys=0; 
                  
    for (int i=0;i<n;i++){
        xs=xs+x[i];                        
        ys=ys+y[i];                        
        x2s=x2s+pow(x[i],2);                
        xys=xys+x[i]*y[i];                
    }
    
    double a,b;
    
    a=(n*xys-xs*ys)/(n*x2s-xs*xs);            
    b=(x2s*ys-xs*xys)/(x2s*n-xs*xs);    
            
    double FittedY[n];                         
    for (int i=0;i<n;i++)   FittedY[i]=a*x[i]+b;
                        
    cout<<"\nS.No."<<setw(5)<<"X"<<setw(19)<<"Y(observed)"<<setw(19)<<"  Y(fitted)"<<endl;
    cout<<"-------------------------------------------------------------\n";
    for (int i=0;i<n;i++){
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(18)<<" "<<FittedY[i]<<endl;
        }
        
    cout<<"\nThe linear fit line is of the form:\n\nY = "<<a<<"X + ("<<b<<")"<<endl<<endl;  
    return 0;
} 
