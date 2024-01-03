#include<bits/stdc++.h>
using namespace std;

int main(){
  cout<<"How many Vertix do you want:"<<endl;
  int N;
  cin>>N;
  int a[N][N],d[N][N];
  cout<<"Enter the cost Matrix:"<<endl;
  for(int i=0; i<N; i++){
     for(int j=0; j<N; j++){
        cin>>a[i][j];
        d[i][j]=a[i][j];
     }

  }


  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }
  }

for(int i=0; i<N; i++){
     for(int j=0; j<N; j++){
        cout<<d[i][j]<<" ";
     }
    cout<<endl;
  }
}
