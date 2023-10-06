//Sailing the Seas - S.Wynne
#include <iostream>
using namespace std;
const int cap=10;
void initMap(string a[][cap],const int& cap);
void displayMap(string a[][cap],const int& cap);
void validate(char &m);
void menu(string map[][cap],const int& cap);
void moveShip(string a[][cap],const int& cap,bool& isLost,bool& isSunk,int direction,int& ship_x,int& ship_y);

int main(){
    string map[cap][cap];
    int ship_x=5;
    int ship_y=5;
    cout<<"Sailing the Seas"<<endl;
    cout<<"---------------"<<endl;
    initMap(map,cap);
    menu(map,cap);
    return 0;
}

void initMap(string a[][cap],const int& cap){
  for(int i=0;i<cap;i++) {
      for(int y=0;y<cap;y++) {
        if (i>=y && (i!=5 || y!=5))
          a[i][y]= " ~";
        else if (y>i)
          a[i][y]= " .";
        else if (i==5 && y==5)
          a[i][y]=" S";
      }
  }
}
void displayMap(string a[][cap],const int& cap){
  for(int i=0;i<=cap;i++) {
    for(int y=0;y<=cap;y++) {
      if (y==0 && i!=cap)
        cout<<i;
     else if (i==cap && y!=0)
          cout<<" "<<y-1;
    else if (i==cap && y==0)
         cout<<" ";
    else
      cout<<a[i][y-1];
    }
  cout<<endl;
  }
}
void validate(char &m){

    int num=static_cast<int>(m);
      if (num<=90)
        m=static_cast<char>(num+32);

}
void menu(string map[][cap],const int& cap){
  bool isSunk=false;
  bool isLost=false;
  int ship_x=5;
  int ship_y=5;
  do{
    char d;
    displayMap(map,cap);
    cout<<"\n(n)orth"<<endl;
    cout<<"(s)outh"<<endl;
    cout<<"(e)ast"<<endl;
    cout<<"(w)est"<<endl<<endl<<endl;;
    cout<<"Which way, Captain? ";
    cin>>d;
    cout<<endl;
    validate(d);
    switch(d)
    {
      case 'n':
        moveShip( map,cap,isLost,isSunk,d,ship_x,ship_y);
        break;
      case 's':
        moveShip( map,cap,isLost,isSunk,d,ship_x,ship_y);
        break;
      case 'e':
        moveShip( map,cap,isLost,isSunk,d,ship_x,ship_y);
        break;
      case 'w':
        moveShip( map,cap,isLost,isSunk,d,ship_x,ship_y);
        break;
      default:
          cout<<"Pick a direction"<<endl;
    }
  }while(isSunk==false || isLost==false);
    if (isLost==true)
      cout<<"ARGGGH!!! ...you have been lost at sea!!!"<<endl<<endl;
    else if (isSunk==true)
      cout<<"CRASH!!! You boat begins to sink!"<<endl<<endl;
}
void moveShip(string a[][cap],const int& cap,bool& isLost,bool& isSunk,int direction,int& ship_x,int& ship_y){
    string ship;
  switch(direction)
  {
  case 'n':
  ship=a[ship_x][ship_y];
  a[ship_x][ship_y]=a[ship_x-1][ship_y];
  a[ship_x-1][ship_y]=ship;
  ship_x-=1;
  if (ship_x<0)
    isLost=true;
  else if (ship_x<ship_y)
    isSunk=true;
  break;
  case 's':
  ship=a[ship_x][ship_y];
  a[ship_x][ship_y]=a[ship_x+1][ship_y];
  a[ship_x+1][ship_y]=ship;
  ship_x+=1;
  if (ship_x>9)
    isLost=true;
    break;
  case 'e':
  ship=a[ship_x][ship_y];
  a[ship_x][ship_y]=a[ship_x][ship_y+1];
  a[ship_x][ship_y+1]=ship;
  ship_y+=1;
  if (ship_y>=cap)
    isLost=true;
  else if (ship_x<ship_y)
    isSunk=true;
    break;
  case 'w':
  ship=a[ship_x][ship_y];
  a[ship_x][ship_y]=a[ship_x][ship_y-1];
  a[ship_x][ship_y-1]=ship;
  ship_y-=1;
  if (ship_y<0)
    isLost=true;
    break;
  default:
    cout<<"Pick a direction!";
  }
}
