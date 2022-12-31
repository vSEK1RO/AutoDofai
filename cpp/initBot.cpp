#include <string>
#include <vector>
#include "../src/include/SFML/Graphics.hpp"
#include <iostream>

void initBot(std::string buttons, std::vector <int> angleData, float * offset, int * offsetAngle){
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
    if(key.size()==0){
        key.push_back(70);
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
    for(int i=0;i<key.size();i++){
        std::cout<<key[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=1;i<angleData.size();i++){
        std::cout<<currentKey[i]<<" ";
    }
    std::cin>>currentKey[0];
}