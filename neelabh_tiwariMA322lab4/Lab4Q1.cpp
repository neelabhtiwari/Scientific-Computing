//This is a program for comparison of Newton's Forward, Backward and Center (Stirling & Bessel) Interpolation ------- Neelabh Tiwari (160123024)

#include<bits/stdc++.h>
using namespace std;

//factorial function
int fact(int n){
    int f=1;
    for(int i=2;i<=n;i++)
        f*=i;
    return f;
}

//forward
float fcal(float u,int n){
    float temp=u;
    for(int i=1;i<n;i++)
        temp=temp*(u-i);
    return temp;
}

//centralbessel
float cbcal(float u,int n){
    if(n==0)  return 1;
    float temp=u;
    for(int i=1;i<=n/2;i++)
        temp=temp*(u-i);
    for(int i=1;i<n/2;i++)
        temp=temp*(u+i);
    return temp;
}

//centralsterling
void cs(float x[],float fx[],float x1,int n){
    float h,a,u,y1=0,N1=1,d=1,N2=1,d2=1,temp1=1,temp2=1,k=1,l=1,delta[n][n];
    int i,j,s;
    
    h=x[1]-x[0];
    s=floor(n/2);
    a=x[s];
    u=(x1-a)/h;
 
    for(i=0;i<n-1;++i){
        delta[i][0]=fx[i+1]-fx[i];
    }
    
    for(i=1;i<n-1;++i){
        for(j=0;j<n-i-1;++j){
            delta[j][i]=delta[j+1][i-1]-delta[j][i-1];
        }
    }
 
    y1=fx[s];
 
    for(i=1;i<=n-1;++i){
        if(i%2!=0){
            if(k!=2){
                temp1*=(pow(u,k)-pow((k-1),2));
            } 
            else{
                temp1*=(pow(u, 2)-pow((k-1),2));
            }
            ++k;
            d*=i;
            s=floor((n-i)/2);
            y1+=(temp1/(2*d))*(delta[s][i-1]+delta[s-1][i-1]);
        } 
        else{
            temp2*=(pow(u,2)-pow((l-1),2));
            ++l;
            d*=i;
            s=floor((n-i)/2);
            y1+=(temp2/(d))*(delta[s][i-1]);
        }
    }
 
    
    cout<<"The Sterling Method (Central) is best interpolation method for the given x as it lies in the middle of the interval.\n\nThe results are  -  \n\n";
    cout<<"The value of Sine function at "<<x<<" degrees is "<<y1<<endl;
    cout<<endl;
    
    return;
}

//backward
float bcal(float u,int n){
    float temp=u;
    for (int i=1;i<n;i++)
        temp=temp*(u+i);
    return temp;
}

int main(){

	float xe[]={45,50,55,60,65,70,75,85};
	float xo[]={45,50,55,60,65,70,75,85,90};

	cout<<"\nGive Number of floating Values of Function (Either 8 (Even) or 9 (Odd) )  -  ";
	int yo; cin>>yo;	
	int n;
	int method=0;
	
	float x;	
	
	if(yo==8){
		n=8;
		cout<<"\nGive a values of x (from 45 to 85) in degrees where you want to find the value of Sine function   -  ";
		cin>>x;
		if(x>=45 && x<60) method=1;
		else if(x>=60 && x<75) method=2;
		else method=3; 
		cout<<endl;
		}
	else{
		n=9;
		cout<<"\nGive a values of x (from 45 to 90) in degrees where you want to find the value of Sine function   -   ";
		cin>>x;
		if(x>=45 && x<60) method=1;
		else if(x>=60 && x<75) method=2;
		else method=3;
		cout<<endl;
		}
	
	float y[n][n];
	
	for(int i=0;i<n;i++){
		y[i][0]=sin(xo[i]*(3.14/180));
	}

	//Forward
	if(method==1){
	
		for(int i=1;i<n;i++){
		    for(int j=0;j<n-i;j++){
		        y[j][i]=y[j+1][i-1]-y[j][i-1];
			}
		}
		
		float sum=y[0][0];
    	float u=(x-xo[0])/(xo[1]-xo[0]);
    	for(int i=1;i<n;i++){
        	sum=sum+(fcal(u,i)*y[0][i])/fact(i);
    	}
    
    	cout<<"The Newton's Forward Method is best interpolation method for the given x as it lies in the right side of the interval.\n\nThe results are  -  \n\n";
    	cout<<"The value of Sine function at "<<x<<" degrees is "<<sum<<endl;
    	cout<<endl;
    	
    }
    
    //Central
    else if(method==2){
    	
    	//Bessel
    	if(n==8){
    		int k;
    		for(int i=1;i<n;i++)
        		for(int j=0;j<n-i;j++)
            		y[j][i]=y[j+1][i-1]-y[j][i-1];
            
            
    		float sum=(y[2][0]+y[3][0])/2;
    		
    		k=n/2-1;
    		
    		float u=(x-xo[k])/(xo[1]-xo[0]);
    		
    		for(int i=1;i<n;i++){
        		if(i%2)
            		sum=sum+((u-0.5)*cbcal(u,i-1)*y[k][i])/fact(i);
        		else
            		sum=sum+(cbcal(u,i)*(y[k][i]+y[--k][i])/(fact(i)*2));
    		}
    	
    	cout<<"The Bessel's Method (Central) is best interpolation method for the given x as it lies in the middle of the interval.\n\nThe results are  -  \n\n";
    	cout<<"The value of Sine function at "<<x<<" degrees is "<<sum<<endl;
    	cout<<endl;
    		
    	}	
    	
    	//Stirling	
    	if(n==9){
    		float fx[n];
    		for(int i=0;i<n;i++){
    			fx[i]=y[i][0];
    		}
    		cs(xo,fx,x,n);  	    	
    	}   
        
    }
        
    //Backward
    else{
    	
    	for(int i=1;i<n;i++){
        	for(int j=n-1;j>=i;j--){
            	y[j][i]=y[j][i-1]-y[j-1][i-1];
           	}
    	}
    	
    	float sum=y[n-1][0];
    	float u=(x-xo[n-1])/(xo[1]-xo[0]);
    	for(int i=1;i<n;i++){
        	sum=sum+(bcal(u,i)*y[n-1][i])/fact(i);
    	}
    	
    	cout<<"The Newton's Backward Method is best interpolation method for the given x as it lies in the left side of the interval.\n\nThe results are  -  \n\n";
    	cout<<"The value of Sine function at "<<x<<" degrees is "<<sum<<endl;
    	cout<<endl;
 
    }


	return 0;
}
