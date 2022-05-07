#include <iostream>
#include <string>
#include <time.h>
#include "addional.h"


//for the function stop for 5 second for excute program
// This is for walking function
#include <unistd.h>

using namespace std;



//What it does? It is used to provide paper_rock_scissors game to batte sence
//Input: NA
//Ouput: number of -1 to 1 the number indicate win,fair or lose for user
//       Which can tell system and system will generate different result
int paper_rock_scissors(){
    char your_choice,computer_choice;
    srand(time(0));
    int num = rand() % 3 + 1;
    
    cout << "Please select following option to fight"  << endl;
    cout << "(r) for rock   (p) for paper   (s) for scissors " << endl;
    cin >> your_choice;
    
    while (your_choice!='r' && your_choice!='p' && your_choice!='s' )
    {
        cout << "Invaild input. Please enter it again ! " << endl;
        cout << "(r) for rock   (p) for paper   (s) for scissors " << endl;
        cin >> your_choice;
    }
    
    
    if(num==1){
        computer_choice = 'r';}
    if(num==2) {
        computer_choice = 'p';}
    if(num==3) {
        computer_choice = 's';}
    
    
    cout<<"your choice is "<<your_choice<<" and monster choice is "<<computer_choice<<endl<<endl;


    if (computer_choice==your_choice){
        cout<<"There are no winner in this battle"<<endl<<endl;
        return 0;
    }
    else if(computer_choice=='r' && your_choice=='s'){
        cout<<"you lose in this battle"<<endl<<endl;
        return -1;
    }
     else if(computer_choice=='s' && your_choice=='p'){
        cout<<"you lose in this battle"<<endl<<endl;
        return -1;
    }
     else if(computer_choice=='p' && your_choice=='r'){
        cout<<"you lose in this battle"<<endl<<endl;
        return -1;
    }
    //user wins
    else if(your_choice=='r' && computer_choice=='s'){
        cout<<"you win in this battle"<<endl<<endl;
        return 1;
    }
     else if(your_choice=='s' && computer_choice=='p'){
        cout<<"you win in this battle"<<endl<<endl;
        return 1;
    }
     else if(your_choice=='p' && computer_choice=='r'){
        cout<<"you win in this battle"<<endl<<endl;
        return 1;
    }

}


//What it does? It is used for calculating harm either monsters or human lose

//Input: basic_harm_user : total basic harm that object can gernate /
//Input: human : let the this fuction know is human/monster is hurted
//Ouput: total harm casused 
int harm_calucation(int basic_harm_user, int human){
    srand(time(0));

    if (human==0){
        int ramdom_harm_upper = basic_harm_user / 3;
        int x= (rand() % (ramdom_harm_upper-0+1))+ 0;
        return basic_harm_user+x;
    }else{

        int ramdom_harm_upper = basic_harm_user / 3+ basic_harm_user;
        int x= (rand() % (ramdom_harm_upper-0+1))+ 0;
        return x + basic_harm_user;
    }

}

//What it does? print our the start menu and let user to select difficulty
//Input: NA (mode will not pass anything in this function)
//Ouput: difficulty selected by user and return it by reference
void start_menu(char &mode){
    cout<<endl;
    cout<<"Welcome to the menu !"<<endl<<endl;
    cout<<"We have two difficulties--esay and difficult"<<endl<<endl;
    cout<<"type (e) for easy mode and (d) for difficult mode"<<endl<<endl;
    cin>>mode;

    if (mode=='e'){
        cout<<endl;
        cout<<"you have selected easy mode"<<endl<<endl;
        
    }
    else{
        cout<<"you have selected difficult mode"<<endl<<endl;
    }
    cout<<"Let go to serach for treasure !!!!"<<endl<<endl;

}


