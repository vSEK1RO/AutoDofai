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
    int lenght=0;
    int counter=0;
    for(int i=1;i<angleData.size();i++){
        currentKey[i]=key[key.size()/2+counter];
        if(offsetAngle[i+1]<30){
            counter++;
            lenght=1;
        }else{
            lenght=0;
            counter=-1;
        }

    }
}