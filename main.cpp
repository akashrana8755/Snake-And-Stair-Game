#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int dice()
{
    int diceValue=0;
    while(diceValue==0)
        diceValue=rand()%6;
    return diceValue;
}
int main(int argc, const char * argv[]) {
    srand(time(0));
    string name[4];
    int c[4]={0,0,0,0},winner,n;
    bool max=false;
    int temp,temp2;
    int rule[101]={0,1,18,3,4,5,6,7,8,9,10,31,28,13,14,15,16,17,18,19,20,15,40,6,24,25,26,27,28,15,30,31,32,
        33,34,18,62,37,38,39,40,59,42,43,44,45,55,32,48,49,50,51,38,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,94,34,72,73,74,75,76,84,78,79,80,81,59,83,84,97,86,87,88,89,90,91,92,93,94,78,96,97,98,31,100};
    while(n>4 || n<0)
    {
        cout<<"Enter the no of players between 1 to 4:";
        cin>>n;
        if(n>4 || n<0) cout<<"Error occured :Enter players between 1 to 4."<<endl;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of "<<i+1<<" player:";
        cin>>name[i];
    }
    while(!max)
    {   for(int i=0;i<n;i++)
        {
            cout<<name[i]<<" @ "<<c[i]<<"  Get ";
            temp2=dice();
            c[i]=c[i]+temp2;
            if(c[i]>=100) {max=true; c[i]=100; winner=i;}
            cout<<temp2;
            temp=c[i];
            c[i]=rule[c[i]];
            if(c[i]<temp) cout<<"  Ohh its Snake <~~~~~-  @ "<<c[i]<<endl;
            else if(c[i]>temp) cout<<"  Hurray Stairs  ######  @ "<<c[i]<<endl;
            else cout<<"  Nothing Special  @"<<c[i]<<endl;
            cin.ignore();
            
        }
        for(int i=0;i<n;i++)
        {
            cout<<name[i]<<" @ "<<c[i]<<endl;
        }
        cin.ignore();
        
    }
    cout<<"<<<<<  "<<name[winner]<<" win the game.  >>>>>"<<endl<<endl;
    return 0;
}
