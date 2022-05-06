#include <iostream>
#include <string>
#include <time.h>
#include "addional.h"


//for the function stop for 5 second for excute program
// This is for walking function
#include <unistd.h>
//end 

using namespace std; 


string beast[10] ={"Zombie","Mummy","Hades","Darth Vader","Voldemort","Joker","Bowser","Wolverine","Frankenstein","Dracula"};
int beast_blood[10]={10,20,29,40,48,52,63,70,80,90};
int beast_kill[10]={5,6,6,6,8,8,9,9,11,13};



struct player
{
   string player;
   int  hp;
   string wepon_name;
   int weapon_harm;
};


//What it does? provide an animation when user transfer to other sence
//Input: user_name: user name
//Input: arrive_place: the place to arrive
//Input: second: how fast does the user walk
//Ouput: walking animation
void walking(string user_name,string arrive_place, int second){
    int cout=1;

    while (cout < 5){
        for (int i=1;i<=5; i++){
            if (cout==i && cout!=5){
                std::cout<<user_name;
            }
            else{
                std::cout<<"__________________";
            }
            //std::cout<<endl;
            
        }
        std::cout<<arrive_place;
        std::cout<<endl;
        std::cout<<endl;
        cout++;
        sleep(second);
    }
    for (int i=1;i<5; i++){
        std::cout<<"__________________";
    }
    for (int i=0; i<arrive_place.length();i++){
        std::cout<<"_";
    }
    std::cout<<arrive_place;
    std::cout<<endl;

}




//What it does?  battle sence is used for all battle support matter and return whether user win or not. For example, hp reduced and win determination
//Input: player: provide user information such as name,HP,weapon that user carried, weapon harm.....
//Input: level : what level user in
//Input: beast : an array of beast name
//Input: beast_blood : an array of beast HP
//Input: beast_kill : an array of beast basic kill
//Ouput: -1 equal to the user have deduced all HP / 0 equal to user win in this level and defeat all the monster

int battle_sence(player*player,int level,string beast[],int beast_blood[],int beast_kill[]){
    
    string beast_name = beast[level];
    int beast_hp = beast_blood[level];
    int beast_basic_kill = beast_kill[level];


    cout<<"you meet a "<<beast[level]<<endl<<endl;

    while(player->hp >0 && beast_hp >0){
        cout<<"your HP : "<<player->hp<<"  Wepon : "<<player->wepon_name<<endl<<endl;
        cout<<beast_name<<"'s HP : "<<beast_hp<<endl<<endl;

        int determine = paper_rock_scissors();

        if (determine==1){
            int basic_harm_user = 4;
            basic_harm_user += player->weapon_harm;
            int total_harm = harm_calucation(basic_harm_user,0);
            cout<<beast_name<<" receives "<<total_harm<<" deamge(s)."<<endl<<endl;
            beast_hp = beast_hp -total_harm;
            
        }
        else if(determine==-1){
            int total_harm = harm_calucation(beast_basic_kill,1);
            cout<<"You receives "<<total_harm<<" deamge(s)."<<endl<<endl;
            player->hp = player->hp-total_harm;
        }
        cout<<"----------------------------------------------------"<<endl;
        sleep(1);
        
    }
    if (player->hp <= 0){
        return -1;
    }else{
        return 0;
    }

}

//What it does? when users win, there are some posibility on will have treasure box and provide HP restore or weapon
//Input: player: provide a record and change HP or replace weapon
//Input: level:  level that user wins, it will make for HP restore calculation
//Input: total_of_level: It is how many level will user faced, and it will determine when user can pick up the weapon
//Ouput: HP restore and weapon collected 
void luckey_box(player*player,int& level,int total_of_level){
    string weapon_list[5]={"Sword","Grenade","M1911","AK47","AWM"};
    string weapon_Description[5]={"Sword is an edged, bladed weapon intended for manual cutting or thrusting.",
    "Grenade is an explosive weapon typically thrown by hand. It is a small explosive, chemical, or gas bomb used at short range.","M1911 is a single-action, recoil-operated pistol chambered for the .45 ACP cartridge.",
    "AK47 is an assault rifle chambered for the 7.62x39mm catridge. It is developed in the Soviet Union by Russian small-arms designer Mikhail Kalashnikov.","AWM is a bolt-action sniper rifle manufactured by Accuracy International designed for magnum rifle cartridges."};
    int weapon_harm[5] ={5,10,18,20,25};

    int sum_of =0;

    srand(time(0));

    //int hp_restore_trigger = ;
    if ((rand() % (5-1+1))+ 1>1){     // 4/5 change can trigger HP restore
        int hp_restore =  (rand() % ((150-(player->hp)+30)-1+1))+ 1;
        cout<<"You found a green heart and add "<<hp_restore<<" HP"<<endl;
        player->hp += hp_restore;
        cout<<"Your HP in Now is "<<player->hp<<endl<<endl<<endl;
    }

    if((rand() % (3-1+1))+ 1>1){   // 2/3 change can trigger weapon
        //cout<<"trigger"<<endl;
        int upper_range_for_wepon = level / 2; // this setting is avoid player can get advanced wepon in early stage 
        int draw_wepon_index = (rand() % (upper_range_for_wepon-0+1))+ 0;
        cout<<"Great!!!! your found "<<weapon_list[draw_wepon_index]<<endl<<endl;
        cout<<"Description : "<<weapon_Description[draw_wepon_index]<<endl<<endl;
        cout<<"Basic Harm casused : "<<weapon_harm[draw_wepon_index]<<endl<<endl;

        cout<<"your weapon now is "<<player->wepon_name<<" and basic harm casused : "<<player->weapon_harm<<endl;
        cout<<"Do you want to change? (y/n)"<<endl;
        char x;
        cin>>x;

        if (x=='y'){
            player->wepon_name = weapon_list[draw_wepon_index];
            player->weapon_harm = weapon_harm[draw_wepon_index];
            cout<<"your weapon has been changed"<<endl;
        }

    }


    

}

//What it does? It will user to different level and conduct battle and print sentence if user win or lose
//Input: player:  provide a record such  HP or weapon
//Input: mode: mode is difficulty that user selected
//Input: beast : an array of beast name
//Input: beast_blood : an array of beast HP
//Input: beast_kill : an array of beast basic kill
//Ouput: NA
void level(player*player,char mode,string beast[],int beast_blood[],int beast_kill[]){

    int level = 0; // level represents the level number that user faced
    if (mode =='e'){
        level = 5;
    }else{
        level = 10;
    }

    int conut= 1;//for the loop of battle
    int win_determine = 0; //print win sentence in below

    while(conut != (level+1)){
        walking(player->player,"Level "+to_string(conut)+" castle",2);
        cout<<endl;
        cout<<"Level "+to_string(conut)<<endl<<endl;
        int win = battle_sence(player,conut-1,beast,beast_blood,beast_kill);
        conut++; // warning, change to position from bottom !!!!!!
       
        if (win== -1){
            cout<<"you lose the game, please restart the game"<<endl<<endl;
            win_determine +=1;
            break;

        }else{
            cout<<"Congrats !!! You defeat "<<beast[conut-1]<<" successfully"<<endl<<endl;
            srand(time(0));
            int treasure_box = (rand() % (4-0+1))+ 0; // 4/5 chance get a box

            if (conut!=level+1){
                if (treasure_box >0){
              cout<<"Wow !!! you find a treasure box"<<endl<<endl;
              luckey_box(player,conut,level);
              }
                else{
                    cout<<"Ohhh !! Nothing here,Let's go to next castle"<<endl<<endl;
              }
            }
            
        }
        
        
    }

    if (win_determine ==0){
        cout<<"You win !!!!"<<endl<<endl;
        cout<<"You get treasure as you wish !!!"<<endl<<endl;
    }
}



int main(){
    player person;
    player *player = &person;
    
    //cout<<harm_calucation(4);
    cout<<"Hi user, what is your name ?"<<endl;  
    cin>>player->player;
    cout<<endl;
    cout<<"Hi "<<player->player<<", let start our adventure !"<<endl<<endl;


    //start menu part
    // choose mode for difficuly in here
    char mode;
    walking(player->player,"menu",1);
    start_menu(mode);

    //battle part
    
     player->hp = 150; //initize palyer HP
     player->hp = 150; 
     player->wepon_name = "Nothing";
     player->weapon_harm = 0;
     level(player,mode,beast,beast_blood,beast_kill);

     delete player;

    


    return 0;  
}