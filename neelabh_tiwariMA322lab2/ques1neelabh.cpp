// Inverse of a Matrix by Gauss-Jordan method  ------- Neelabh Tiwari - 160123024

#include<bits/stdc++.h>
using namespace std;

int poss=0;

void printresult(vector<vector<double> > mat){
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout<<mat[i][j]<<" ";
        }
      cout<<endl;
    }
    cout<<endl;
    return;
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
            		poss=1;
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
			poss=1;
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



int main(){
    vector<vector<double> > def;

    int cnt=0;

    double arr[9]={3,2,-4,2,3,3,5,-3,1};

    for(int i=0;i<3;i++){
      vector<double> row; def.push_back(row);
      for(int j=0;j<3;j++){
          def[i].push_back(arr[cnt]);
          cnt++;
      }
  }


    int input=-1;
    cout<<"\nThis is a program to compute inverse of a Matrix.\n\n";

    while(input!=0 && input!=1){

        cout<<"Give 0 as input to find inverse of a default harcoded matrix or 1 to input a new sqaure matrix : ";

        cin>>input;

        if(input==0){
          cout<<"\nThe input Matrix is : \n\n";
          printresult(def);
          vector<vector<double> > ret = inverse(def);
          cout<<"The inverted Matrix is\n\n";
          printresult(ret);
          break;
        }

        else if(input==1){
            cout<<"\nGive size of matrix in the form of two space seperated integers denoting rows and columns of the Matrix :  ";
            int n,m;  cin>>n>>m;
            if(n!=m){
              cout<<"\nPlease Give Correct Inpu.t\n\n";
              input=-1;
            }
            else{
              cout<<"\nGive "<<n<<" X "<<n<<" elements of the matrix seperated by space - \n\n";
              vector<vector<double> > mat;
              for(int i=0;i<n;i++){
                vector<double> row; mat.push_back(row);
                for(int j=0;j<n;j++){
                  int x; cin>>x; mat[i].push_back(x);
                }
            }
              vector<vector<double> > ret=inverse(mat);
              if(poss!=1) {
                cout<<"\nThe inverted Matrix is : \n\n";
                printresult(ret);
              }
              break;
          }
      }

        else{
          cout<<"\nPlease Give Correct Input.\n\n";
      }

  }

  return 0;

}

