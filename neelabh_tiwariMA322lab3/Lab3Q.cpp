//This assignment is done on a colloaborative arrangement by Harshit Singh (160123010), Neelabh Tiwari (160123024), Kshitiz Nayar (160123016) 


#include<bits/stdc++.h>
using namespace std;

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
float newton_interpolation(float y[][10],int n,float x[],float value)
{
	float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) 
    {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }
    return sum;
}
float lanrange(float y[][10],int n,float x[],float value)
{
	float mult;
	float sum=0;
	for(int i=0;i<=n-1;i++)
    {
    mult=1;
        for(int j=0;j<=n-1;j++)
        {
            if(j!=i)
            mult*=(value-x[j])/(x[i]-x[j]);
        }
        sum+=mult*y[i][0];
    }
    return sum;
}
int main()
{
	float x[] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
	int n=10;
	float y[10][10];
	float k=0.1;
	int i=0;
	while(k<=1.0)
	{
		y[i][0]=sin(k)/(k*k);
		i++;
		k=k+0.1;
	}
	for (int i = 1; i < n; i++) 
	{
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }

    float value = 0.12;
    cout << "\n Value at " << value << " using Newton interpolation method is "
         << newton_interpolation(y,n,x,value) << endl;

    cout << "\n Value at " << value << " using lanrange interpolation method is "
    	<< lanrange(y,n,x,value) << endl;

    float value1=0.92;

    cout << "\n Value at " << value1 << " using Newton interpolation method is "
         << newton_interpolation(y,n,x,value1) << endl;

    cout << "\n Value at " << value1 << " using lanrange interpolation method is "
    	<< lanrange(y,n,x,value1) << endl;

    float value3=0.52;

    cout << "\n Value at " << value3 << " using Newton interpolation method is "
         << newton_interpolation(y,n,x,value3) << endl;

    cout << "\n Value at " << value3 << " using lanrange interpolation method is "
    	<< lanrange(y,n,x,value3) << endl;
}
