#include<iostream>
using namespace std;

int main(){
  int item = 0, wi = 0, vi = 0, maximum = 0, first = 0, second = 0;
  cin>>item;
  int profit[item];
  int weight[item];

  for(int i=0; i<item; i++){
    cin>>profit[i]>>weight[i];
  }
  int capacity;
  cin>>capacity;
  int row = item+1;
  int column = capacity+1;
  int arr[row][column];

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        arr[i][j] = 0;
    }
  }
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
        wi = weight[i-1];
        vi = profit[i-1];
        if(i==0 || j==0){
            arr[i][j] = 0;
       }
       else if(wi>j){
        arr[i][j] = arr[i-1][j];
       }
       else{
        first = vi+arr[i-1][j-wi];
        second = arr[i-1][j];
        if(first>second){
            maximum = first;
        }
        else{
            maximum = second;
        }
        arr[i][j] = maximum;
       }
    }
  }
  cout<<arr[item][capacity];
}
