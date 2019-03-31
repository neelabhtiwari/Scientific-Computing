// Newton's Method to find solution of the system of equations ------- Neelabh Tiwari - 160123024

#include<bits/stdc++.h>
using namespace std;

double f(vector<vector<double> > point){
	double x = point[0][0];
	double y = point[1][0];
	double z = point[2][0];	
	return x*x*x + y*y*y - 53;
}

double g(vector<vector<double> > point){
	double x = point[0][0];
	double y = point[1][0];
	double z = point[2][0];	
	return 2*y*y*y + z*z*z*z - 69;
}

double h(vector<vector<double> > point){
	double x = point[0][0];
	double y = point[1][0];
	double z = point[2][0];	
	return 3*x*x*x*x*x + 10*z*z - 770;
}

vector<vector<double> > makejac(vector<vector<double> > point){
	double x = point[0][0];
	double y = point[1][0];
	double z = point[2][0];	
	
	vector<vector<double> > jac;
	
	jac.resize(3);
	for(int i=0;i<3;i++) jac[i].resize(3);
	
	jac[0][0]=3*x*x;
	jac[0][1]=3*y*y;
	jac[0][2]=0;
	jac[1][0]=0;
	jac[1][1]=6*y*y;
	jac[1][2]=4*z*z*z;
	jac[2][0]=15*x*x*x*x;
	jac[2][1]=0;
	jac[2][2]=20*z;
	
	return jac;	
}

vector<vector<double> > inverse(vector<vector<double> > mat){
    int n=mat.size();
    vector<vector<double> > ret;

    for(int i=0;i<n;i++){
      for(int j=n;j<2*n;j++){
        if(j==(i+n))  mat[i].push_back(1);
        else mat[i].push_back(0);
        }
    }
    
    for(int i=n-1;i>0;i--){
        if(mat[i-1][0]<mat[i][0]){
            for(int j=0;j<2*n;j++){
                double d=mat[i][j];
                mat[i][j]=mat[i-1][j];
                mat[i-1][j]=d;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
            	if(mat[i][i]==0){
      				cout<<"This Matrix is non-invertible as it is a singular matrix.\n\n";
      				return ret;
            	}
                double d=mat[j][i]/mat[i][i];
                for(int k=0;k<2*n;k++){
                    mat[j][k]-=mat[i][k]*d;
                  }
              }
          }
      }

    for(int i=0;i<n;i++){
        double d=mat[i][i];
        if(d==0){
      		cout<<"\nThis Matrix is non-invertible as it is a singular matrix.\n\n";
      		return ret;        
		}
        for(int j=0;j<2*n;j++){
            mat[i][j]=mat[i][j]/d;
        }
    }

   for(int i=0;i<n;i++){
     vector<double> row; ret.push_back(row);
     for(int j=n;j<2*n;j++){
        ret[i].push_back(mat[i][j]);
     }
  }

  return ret;

}


vector<vector<double> > product(vector<vector<double> > a,vector<vector<double> > b){
	vector<vector<double> > ret;
	
	ret.resize(3);
	for(int i=0;i<3;i++) ret[i].resize(1);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<1;j++){
			ret[i][j]=0;
			for(int k=0;k<3;k++){
				ret[i][j]+=a[i][k]*b[k][0];
			}			
		}
	}
	
	return ret;
}

vector<vector<double> > subtract(vector<vector<double> > a,vector<vector<double> > b){
	vector<vector<double> > ret;
	ret.resize(3);
	
	for(int i=0;i<3;i++){
		ret[i].push_back(a[i][0]-b[i][0]);
	}

	return ret;
}

int main(){
	
	vector<vector<double> > fval;
	long double error;
	cout<<"\nThis is a program to use Newton’s method calculate the solution of the system of non-linear equaions.\n\n";
	cout<<"Give maximum permissible error : ";
	cin>>error;
	
	fval.resize(3);
	for(int i=0;i<3;i++) fval[i].resize(1);
	
	vector<vector<double> > jac;
	
	jac.resize(3);
	for(int i=0;i<3;i++) jac[i].resize(3);

	vector<vector<double> > jacinv;
	
	vector<vector<double> > xa;

	xa.resize(3); 
	double start[3]={3,3,2};
	
	for(int i=0;i<3;i++){
		xa[i].push_back(start[i]);
	}

	int cnt=0;
	vector<vector<double> > newx;
	
	while(1){
	
		cnt++;
		
		fval[0][0]=f(xa);
		fval[1][0]=g(xa);
		fval[2][0]=h(xa);
	
		jac=makejac(xa);
		
		jacinv=inverse(jac);
		
		vector<vector<double> > prod = product(jacinv,fval);
	
		newx = subtract(xa,prod);
		
		if(abs(newx[0][0]-xa[0][0])<error && abs(newx[1][0]-xa[1][0])<error && abs(newx[2][0]-xa[2][0])<error) break;
		
		xa = newx;
		
		//for(int i=0;i<3;i++) {cout<<xa[i][0]; if(i!=2) cout<<","; }
		//cout<<"\n\n";
		
	}
	
	
	cout<<"\nThe Solution for the System of equations is - \n\n(";
	for(int i=0;i<3;i++) {cout<<newx[i][0]; if(i!=2) cout<<","; }
	cout<<")\n\n";
	cout<<"The number of iterations done are "<<cnt<<endl;
	cout<<"The maximum permissible error is "<<error<<endl;
	cout<<"\n";

	return 0;
}
