//Project_1: TreasureMap S.Wynne
#include <iostream>
using namespace std;
int main()
{
int row;
int newrow;
int col;
int newcol;
int dim;
int x;
char m;
int d;
cout<<"Treasure Map"<<endl;
cout<<"------------"<<endl;
//Requesting Map Values 1
do{
  cout<<"Enter a map size between 5 and 9 inclusive: ";
  cin>>dim;

  if(dim<5 ||dim>9)
    cout<<"Invalid map size."<<endl;
}while(dim<5 ||dim>9);

cout<<"\nMap size set to "<<dim<<endl<<endl;
//Requesting Map Values 2
do
{
  cout<<"Initial location of the treasure (row column): ";
  cin>>row>>col;

  if(col>=dim ||col<=0 ||row>=dim ||row<=0)
    cout<<"Coordinates must be between 0 and "<<dim-1<<endl;
}while(col>=dim ||col<0 ||row>=dim ||row<0);

cout<<"\nTreasure coordinates assigned to row "<<row<<" column "<<col<<" ."<<endl<<endl;

do{
  {
  for(int r=0; r<=dim;r++)
    {
    for(int c=0;c<=dim;c++)
      {
      if (c==0 && r<dim)
        cout<<r;
      else if(r==row && c==col+1)
          cout<<" X";
      else if (r==dim && c!=0)
          cout<<" "<<c-1;
      else if (c==0 && r==dim)
          cout<<" ";
      else
          cout<<" -";

      }
      cout<<endl;
    }
  }
//The Option Menu 1
    cout<<"\n1) Update treasure coordinates (row/column)"<<endl;
    cout<<"2) Shift X (N S E W)"<<endl;
    cout<<"3) Exit Program"<<endl<<endl;
    cout<<"Select: ";
    cin>>x;
    cout<<endl;
//Handling the Option Menu
    switch(x)
    {
      //The Treasure Map 1
      case 1:
          do
          {
            cout<<"Update location of X (row column): ";
            cin>>newrow>>newcol;
            if(newcol>=dim ||newcol<=0 ||newrow>=dim ||newrow<=0)
                cout<<"Coordinates must be between 0 and "<<dim-1<<endl;
          }while(newrow>dim || (newrow<0 && newcol<0) ||newcol>dim);
          row=newrow;
          col=newcol;
          cout<<endl;
          break;

          case 2:
          do{
          cout<<"Shift X (N,S,E,W) and unit number: ";
          cin>>m>>d;
          if (row-d<=0 || row-d>=dim ||row+d<=0 || row+d>=dim||col+d<=0 || col+d>=dim|| col-d<=0 || col-d>=dim)
                cout<<"Treasure cannot move beyond the map."<<endl;
          }while(row-d<=0 || row-d>=dim ||row+d<=0 || row+d>=dim||col+d<=0 || col+d>=dim|| col-d<=0 || col-d>=dim);

          switch(m)
          {
            case 'N':
              row=row-d;
              break;
            case 'S':
              row=row+d;
              break;
            case 'E':
              col=col+d;
              break;
            case 'W':
              col=col-d;
              break;
            default:
                cout<<"Invalid direction"<<endl;
          }
          cout<<endl;
          break;

          case 3:
          cout<<"Exiting Program."<<endl;
          break;

          default:
          cout<<"Invalid choose"<<endl<<endl;
          break;
          }
}while(x!=3);
return 0;
          }
