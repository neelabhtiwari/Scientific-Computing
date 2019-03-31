//This assignment is done on a colloaborative arrangement by Harshit Singh (160123010), Neelabh Tiwari (160123024), Kshitiz Nayar (160123016) 
#include<iostream>
#include<vector>
using namespace std;
vector<long double> add(vector<long double> A,vector<long double> B)
{
	vector<long double> sum;
	for(int i = 0 ; i < A.size() ; i++)
	{
		sum.push_back(A[i]+B[i]); 
	}
	return sum;
}
vector<long double> mul(vector<vector<long double> > A,vector<long double> B)
{
	vector<long double> ans;
	for(int i = 0; i < A.size() ; i++)
	{
		long double temp = 0;
		for(int j = 0 ; j < B.size() ; j++)
		{
			temp += A[i][j]*B[j];
		}
		ans.push_back(temp);
	}
	return ans;
}
long double sub(vector<long double> A,vector<long double> B)
{
	long double sub = 0;
	for(int i = 0 ; i < A.size() ; i++)
	{
		sub += (A[i]-B[i]); 
	}
	return sub;
}
long double mod(long double a)
{
	if(a < 0)
	{
		return -1*a;
	}
	return a;
}
int main()
{
	
	// Jacobi method
	vector<vector<long double> >H;
	vector<long double>h1,h2,h3,C;
	h1.push_back(0);h1.push_back(-0.4);h1.push_back(0.2);H.push_back(h1);
	h2.push_back(0.1);h2.push_back(0);h2.push_back(-0.1);H.push_back(h2);
	h3.push_back(0.5);h3.push_back(0.2);h3.push_back(0);H.push_back(h3);
	C.push_back(1.2);C.push_back(1);C.push_back(0.3);

	vector<long double>X;
	X.push_back(10000);
	X.push_back(20000);
	X.push_back(30000);
	long double e = 0.0001;
	e = e*3;
	int count = 0;
	vector<long double> temp;
	do
	{
		temp = X;
		X = add(mul(H,X),C);
		count++;
	}while(mod(sub(X,temp)) > e);
	cout << X[0] << " " << X[1] << " " << X[2] << " " << count << endl;


	vector<vector<long double> >Hg;
	vector<long double>hg1,hg2,hg3,Cg;	
	hg1.push_back(0);hg1.push_back(-0.4);hg1.push_back(0.2);Hg.push_back(hg1);
	hg2.push_back(0);hg2.push_back(-0.04);hg2.push_back(0.08);Hg.push_back(hg2);
	hg3.push_back(0);hg3.push_back(-0.208);hg3.push_back(-0.084);Hg.push_back(hg3);
	Cg.push_back(1.2);Cg.push_back(1.12);Cg.push_back(1.124);

	vector<long double>Xg;
	Xg.push_back(10000);
	Xg.push_back(20000);
	Xg.push_back(30000);
	long double eg = 0.0001;
	eg = eg*3;
	int countg = 0;
	vector<long double> tempg;
	do
	{
		tempg = Xg;
		Xg = add(mul(Hg,Xg),Cg);
		countg++;
	}while(mod(sub(Xg,tempg)) > eg);
	cout << Xg[0] << " " << Xg[1] << " " << Xg[2] << " " << countg << endl;

return 0;
}
