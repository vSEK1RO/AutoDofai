#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "serializeData.h"

class SerializeData{

private:

    std::string convertionType;
    std::vector <int> angleData;
    int midspinNumber[80000];
    int midspin[80000];
    float bpm[80000];
    float offset[80000];
    int offsetAngle[80000];
    int twirl[80000];
    std::string mapData="";

    int mod(int aMod, int bMod){
        while(aMod<0){
            aMod+=bMod;
        }
        return aMod%bMod;
    } 

    std::string convertAngleData(std::string angle, std::string type){
        std::string outputString="";
        if(type=="old pathData"){
            while(angle!=""){
                outputString+=std::to_string(pathData(angle[0]));
                outputString+=",";
                angle.erase(0,1);
            }
            outputString.erase(outputString.size()-1,1);
        }
        return outputString;
    }

    int pathData(char letter){
        switch(letter){
            case 'R': return 0;
            case 'p': return 15;
            case 'J': return 30;
            case 'E': return 45;
            case 'T': return 60;
            case 'U': return 90;
            case 'G': return 120;
            case 'Q': return 135;
            case 'H': return 150;
            case 'W': return 165;
            case 'L': return 180;
            case 'x': return 195;
            case 'N': return 210;
            case 'Z': return 225;
            case 'F': return 240;
            case 'D': return 270;
            case 'B': return 300;
            case 'C': return 315;
            case 'M': return 330;
            case 'A': return 345;
            default: return 0;
        }
    }

public:  

    void setInputFile(std::string filePath){
        std::string bufferString="";
        std::ifstream inputFile(filePath);
        while(!inputFile.eof()){
            getline(inputFile,bufferString);
            while(bufferString.find(" ")!=-1){
                bufferString.erase(bufferString.find(" "),1);
            }
            mapData+=bufferString;
        }
    }

    void processMapData(){
        if(mapData.find("angleData")==-1){
            convertionType="old pathData";
        }else{
            convertionType="new angleData";
        }
        if(convertionType=="old pathData"){
            mapData.erase(0, mapData.find("pathData")+11);
            std::string angle=mapData.substr(0,mapData.find("\""));
            mapData.erase(0, mapData.find("\"")+1);
            mapData.insert(0,convertAngleData(angle,convertionType)+"]");
        }
        if(convertionType=="new angleData"){
            mapData.erase(0, mapData.find("angleData")+12);
        }
        mapData.insert(0,",");
        angleData.push_back(0);
        int midspinCounter=0;
        while(mapData[0]!=']'){
            mapData.erase(0,1);
            if(mapData.find(",")<mapData.find("]")){
                if(mapData.substr(0,mapData.find(","))!="999"){
                    angleData.push_back(stoi(mapData.substr(0,mapData.find(","))));
                }else{
                    midspin[angleData.size()-1]=1;
                    midspinCounter++;
                }
                mapData.erase(0,mapData.find(","));
            }else{
                if(mapData.substr(0,mapData.find("]"))!="999"){
                    angleData.push_back(stoi(mapData.substr(0,mapData.find("]"))));
                }else{
                    midspin[angleData.size()-1]=1;
                    midspinCounter++;
                }
                mapData.erase(0,mapData.find("]"));
            }
            midspinNumber[angleData.size()-1]=midspinCounter;
        }
        for(int i=angleData.size();i<80000;i++){
            midspinNumber[i]=midspinNumber[angleData.size()-1];
        }
        mapData.erase(0,mapData.find("bpm")+5);
        bpm[0]=stof(mapData.substr(0,mapData.find(",")));
        mapData.erase(0,mapData.find("offset")+8);
        offset[0]=stoi(mapData.substr(0,mapData.find(",")));
        mapData.erase(0,mapData.find("countdownTicks")+16);
        offset[0]+=(stoi(mapData.substr(0,mapData.find(",")))*180)*1000/(3*bpm[0])+850.0;
        mapData.erase(0,mapData.find("actions")+9);
        mapData=mapData.substr(0,mapData.find("decorations"));
        int currentFloorPos=0;
        std::string buffer="";
        for(int i=0;i<80000;i++){
            twirl[i]=1;
        }
        while(mapData.find("floor")!=-1){
            mapData.erase(0,mapData.find("floor")+7);
            currentFloorPos=stoi(mapData.substr(0,mapData.find(",")));
            buffer=mapData.substr(0,mapData.find("floor"));
            if(buffer.find("speedType")!=-1){
                buffer.erase(0,buffer.find("speedType")+12);
                if(buffer.substr(0,buffer.find(",")-1)=="Multiplier"){
                    buffer.erase(0,buffer.find("bpmMultiplier")+15);
                    bpm[currentFloorPos-midspinNumber[currentFloorPos]]=(-1.0)*stof(buffer.substr(0,buffer.find(",")-1));
                }else{
                    buffer.erase(0,buffer.find("beatsPerMinute")+16);
                    bpm[currentFloorPos-midspinNumber[currentFloorPos]]=stof(buffer.substr(0,buffer.find(",")));
                }
            }
            if(mapData.substr(0,mapData.find("floor")).find("Twirl")!=-1){
                twirl[currentFloorPos-midspinNumber[currentFloorPos]]=-1;
            }
        }
        float currentBPM=bpm[0];
        int currentTwirl=twirl[0];
        for(int i=1;i<angleData.size();i++){
            if(midspin[i-1]==0){
                if(currentTwirl==1){
                    offsetAngle[i]=mod(180+angleData[i-1]-angleData[i],360);
                    offset[i]=(1000*mod(180+angleData[i-1]-angleData[i],360))/(3*currentBPM);
                }else{
                    offsetAngle[i]=mod(180-angleData[i-1]+angleData[i],360);
                    offset[i]=(1000*mod(180-angleData[i-1]+angleData[i],360))/(3*currentBPM);
                }
            }
            if(midspin[i-1]==1){
                if(currentTwirl==1){
                    offsetAngle[i]=mod(angleData[i-1]-angleData[i],360);
                    offset[i]=(1000*mod(angleData[i-1]-angleData[i],360))/(3*currentBPM);
                }else{
                    offsetAngle[i]=mod(-angleData[i-1]+angleData[i],360);
                    offset[i]=(1000*mod(-angleData[i-1]+angleData[i],360))/(3*currentBPM);
                }
            }
            if(offset[i]==0){
                offsetAngle[i]=360;
                offset[i]=(1000*360)/(3*currentBPM);;
            }
            currentTwirl*=twirl[i];
            if(bpm[i]!=0){
                if(bpm[i]>=0){
                    currentBPM=bpm[i];
                }
                if(bpm[i]<0){
                    currentBPM*=(-1)*bpm[i];
                }
            }
        }
    }

    std::vector <int> getAngleData(){
        return angleData;
    }

    int * getMidspinNumber(){
        return midspinNumber;
    }

    float * getBPM(){
        return bpm;
    }

    float * getOffset(){
        return offset;
    }

    int * getOffsetAngle(){
        return offsetAngle;
    }

    int * getTwirl(){
        return twirl;
    }

};