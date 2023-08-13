#include<iostream>
using namespace std;

int main(){

    char route[] = "NNSSEEWWWNSEWNNS";
    char res[100];
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    while(route[i]!='\0'){
        if(route[i]=='S'){
            y--;
        }else if(route[i]=='N'){
            y++;
        }else if(route[i]=='W'){
            x--;
        }else if(route[i]=='E'){
            x++;
        }
        i++;
    }
    
    while(y!=0){
        if(y>0){
          res[j++] = 'N';
          y--;
        }else{
          res[j++] = 'S';
          y++; 
        }
    }

    while(x!=0){
        if(x>0){
          res[j++] = 'E';
          x--;
        }else{
          res[j++] = 'W';
          x++; 
        }
    }

    

    cout<<"Result : "<<res<<endl;
}