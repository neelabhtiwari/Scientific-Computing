//This is the code to solve following BVP using shooting method ---  Neelabh Tiwari 160123024
//u'' = 2uu', u(0)=0 and u(1)=1

#include<bits/stdc++.h>
using namespace std;

float f1(float x,float y,float z){
    return z;
}

float f2(float x,float y,float z){
    return x+y;
}

float shoot(float x0,float y0,float z0,float xn,float h,int p, int t){
    float x,y,z,k1,k2,k3,k4,l1,l2,l3,l4,k,l,x1,y1,z1;
    x=x0;
    y=y0;
    z=z0;
    while(x<xn)
    {
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);
        k2=h*f1(x+h/2.0,y+k1/2.0,z+l1/2.0);
        l2=h*f2(x+h/2.0,y+k1/2.0,z+l1/2.0);
        k3=h*f1(x+h/2.0,y+k2/2.0,z+l2/2.0);
        l3=h*f2(x+h/2.0,y+k2/2.0,z+l2/2.0);
        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);
        l=1/6.0*(l1+2*l2+2*l3+l4);
        k=1/6.0*(k1+2*k2+2*k3+k4);
        y1=y+k;
        x1=x+h;
        z1=z+l;
        x=x1;
        y=y1;
        z=z1;
        if(p==1 && t)
        {
            printf("\n%f\t%f",x,y);
        }
    }   
    return(y);
}

int main(){
    float x0,y0,h,xn,yn,z0,m1,m2,m3,b,b1,b2,b3,e;
    int p=0;
    
    int n;
    cout<<"\nProgram to solve BVP ::: u'' = 2uu', u(0)=0 and u(1)=1\n\n";
    cout<<"Give the value of n (Number of mesh points = n+1) ---- ";
    cin>>n;
    
    h = 1.0/n;
    x0 = 0;
    y0 = 0;
    xn = 1;
    yn = 1;
    
    m1 = 0;
    b=yn;
    z0=m1;
    b1=shoot(x0,y0,z0,xn,h,p=1,0);
 
    if(fabs(b1-b)<0.00005){
        e=shoot(x0,y0,z0,xn,h,p=1,0);
        cout<<endl;
        return 0;
    }
    else{
    m2 = 1;
    z0=m2;
    b2=shoot(x0,y0,z0,xn,h,p=1,0);
    }
    
    if(fabs(b2-b)<0.00005){
         e= shoot(x0,y0,z0,xn,h,p=1,0);
         cout<<endl;
         return 0;
    }
    else{
        m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
        if(b1-b2==0)
        exit(0);
        z0=m3;
        b3=shoot(x0,y0,z0,xn,h,p=0,0);
    }
    
    if(fabs(b3-b)<0.000005){
        cout<<"\nThe Solution of the given BVP are as following :\n"<<endl;
        cout<<"At  x       --    U(x)"<<endl;
        e=shoot(x0,y0,z0,xn,h,p=1,1);
        cout<<endl;
        cout<<endl;
        exit(0);
    }

    while(fabs(b3-b)<0.0005){
       m1=m2;
       m2=m3;
       b1=b2;
       b2=b3;
       m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
       z0=m3;
       b3=shoot(x0,y0,z0,xn,h,p=0,0);

    }
    
    z0=m3;
    e=shoot(x0,y0,z0,xn,h,p=1,0);
    cout<<endl;
    return 0;
}
