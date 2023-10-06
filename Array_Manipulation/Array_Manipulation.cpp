//Array Manipulation-S.Wynne
#include <iostream>
using namespace std;

void menu(int a[],int& numElements,const int& CAP);
bool isFull(int numElements,const int& CAP);
bool isEmpty(int numElements);
int getindex(int a[],int numElements,int number);
void append(int a[],int& numElements,const int& CAP, int number);
void insertAt(int a[], int& numElements,const int& CAP);
void removeElement(int a[], int& numElements,const int& CAP);
void removeFirst(int a[],int& numElements,const int& CAP);
void removeLast(int a[],int& numElements,const int& CAP);
void output(int a[],int& numElements,const int& CAP);

int main() {
    const int CAPACITY = 100;
    int numbers[CAPACITY];
    int numElements = 0;

    cout << "Array Manipulation: " << endl;
    cout << "-----------------" << endl;

    append(numbers, numElements, CAPACITY, 10);
    append(numbers, numElements, CAPACITY, 20);
    append(numbers, numElements, CAPACITY, 30);
    append(numbers, numElements, CAPACITY, 40);
    append(numbers, numElements, CAPACITY, 50);
    append(numbers, numElements, CAPACITY, 60);
    append(numbers, numElements, CAPACITY, 70);
    append(numbers, numElements, CAPACITY, 80);
    append(numbers, numElements, CAPACITY, 90);
    append(numbers, numElements, CAPACITY, 100);
    output(numbers,numElements,CAPACITY);
    menu(numbers,numElements,CAPACITY);
    return 0;
}

void menu(int a[],int& numElements,const int& CAP){
  int option;
  int number;
  int position;
    do{
      cout<<"Array Manipulation"<<endl;
      cout<<"------------------"<<endl;
      cout<<"1. Get Index"<<endl;
      cout<<"2. Append"<<endl;
      cout<<"3. Insert"<<endl;
      cout<<"4. Remove"<<endl;
      cout<<"5. Remove First"<<endl;
      cout<<"6. Remove Last"<<endl;
      cout<<"7. Output"<<endl;
      cout<<"8. Exit program"<<endl<<endl;
      cout<<"Select: ";
      cin>>option;
      cout<<endl;
      switch(option)
      {
        case 1:
          cout<<"What number are you looking for: ";
          cin>>number;
          cout<<number<<" is located in the array at "<<getindex(a,numElements,number)<<" spot"<<endl<<endl;
          break;
        case 2:
          cout<<"Enter a number you want to add ";
          cin>>number;
          cout<<endl;
          if(isFull(numElements,CAP)==true)
            cout<<"Array is Full"<<endl;
          else
            append(a,numElements,CAP,number);
            cout<<endl;
          break;
        case 3:
          if(isFull(numElements,CAP)==true)
            cout<<"\nArray is Full"<<endl;
          else
            insertAt(a,numElements,CAP);
          break;
        case 4:
          removeElement(a,numElements,CAP);
          break;
        case 5:
          if (isEmpty(numElements)==true)
            cout<<"Array is empty. "<<endl<<endl;
          else
            removeFirst(a,numElements,CAP);
          break;
        case 6:
          if (isEmpty(numElements)==true)
            cout<<"Array is empty. "<<endl<<endl;
          else
            removeLast(a,numElements,CAP);
          break;
        case 7:
          output(a,numElements,CAP);
          break;
        case 8:
          output(a,numElements,CAP);
          break;
        default:
          cout<<"Invalid opition. Pick agian!"<<endl;
      }
    }while(option!=8);
}
bool isFull(int numElements,const int& CAP){
    if(numElements>=CAP)
        return true;
    else
        return false;
}
bool isEmpty(int numElements){
    if(numElements<=0)
        return true;
    else
        return false;
}
int getindex(int a[],int numElements,int number){
    for(int i=0;i<=numElements;i++){
      if(a[i]==number)
          return i;
        }
          return -1;
}
void append(int a[],int& numElements,const int& CAP, int number){
    a[numElements]=number;
    numElements++;
}
void insertAt(int a[], int& numElements,const int& CAP){
  int number;
  int position;

    cout<<"Enter an integer value to insert: ";
    cin>>number;
    cout<<"Enter a position: ";
    cin>>position;

    for(int i=numElements;i>=position;i--){
      a[i+1]=a[i];
    }
      numElements++;
      a[position]=number;

}
void removeElement(int a[],int& numElements,const int& CAP){
  int number;

    cout<<"What element would you like to get rid of? ";
    cin>>number;
  if (getindex(a,numElements,number)==-1)
      cout<<"Element doesnt exist"<<endl;

  int position=getindex(a,numElements,number);
  for(int i=position;i<=numElements;i++){
      a[i]=a[i+1];
  }
  numElements--;
}
void removeFirst(int a[],int& numElements,const int& CAP){
      numElements--;
      for(int i=0;i<=numElements;i++){
      a[i]=a[i+1];
      }
}
void removeLast(int a[],int& numElements,const int& CAP){
      numElements--;
}
void output(int a[],int& numElements,const int& CAP){
    cout<<"Array: ";
    for(int i=0;i<numElements;i++){
        cout<<a[i]<<" ";
    }
    cout<<" Size: "<<numElements<<endl<<endl;;
}
