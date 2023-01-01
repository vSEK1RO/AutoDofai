#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../src/include/SFML/Graphics.hpp"

int GetRandomNumber(int min, int max)
{
  srand(time(NULL));
  int num = min + rand() % (max - min + 1);
  return num;
}

void initBot(std::string buttons, std::vector <int> angleData, float * offset, int * offsetAngle, int floor, float speed){
    sf::Clock clock;
    clock.restart();
    std::vector <int> key;
    while(buttons!=""){
        key.push_back(stoi(buttons.substr(0,buttons.find(" "))));
        if(buttons.find(" ")==-1){
            break;
        }
        buttons.erase(0,buttons.find(" ")+1);
    }
    if(key.size()%2!=0 && key.size()>1){
        key.pop_back();
    }
    int currentKey[angleData.size()];
    int counter=1;
    int currentHand=1; //"1"-rightHand   "-1"-leftHand
    for(int i=1;i<angleData.size();i++){
        if(counter>0){
            currentKey[i]=key[key.size()/2+counter-1];
            if((key.size()/2+counter-1)<0){
                currentKey[i]=key[0];
            }
            if((key.size()/2+counter-1)>(key.size()-1)){
                currentKey[i]=key[key.size()-1];
            }
        }else{
            currentKey[i]=key[key.size()/2+counter];
            if((key.size()/2+counter)<0){
                currentKey[i]=key[0];
            }
            if((key.size()/2+counter)>(key.size()-1)){
                currentKey[i]=key[key.size()-1];
            }
        }
        if(offsetAngle[i+1]<40){
            if(counter>0){
                counter++;
            }
            if(counter<0){
                counter--;
            }
        }else{
            currentHand*=(-1);
            counter=1;
            counter*=currentHand;
        }
    }
    //while(clock.getElapsedTime().asMilliseconds()<offset[0]){
    //}
    clock.restart();
    for(int i=floor+1;i<angleData.size();i++){
        while(clock.getElapsedTime().asMilliseconds()<(offset[i]/speed)){
        }
        clock.restart();
        keybd_event(currentKey[i], 0,0,0);
        while(clock.getElapsedTime().asMilliseconds()<(offset[i+1]/speed-10)){
        }
        keybd_event(currentKey[i], 0,KEYEVENTF_KEYUP,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            break;
        }
    }
}