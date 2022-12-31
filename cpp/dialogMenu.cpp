#include "consoleColor.h"
#include "isPressed.h"
#include "serializeData.h"
#include "getFileName.h"
#include "initBot.h"
#include <string>
#include <vector>
#include <fstream>
#include "../src/include/SFML/Graphics.hpp"
#include <iostream>

class DialogMenu{

private:

    std::vector <int> angleData;
    int * midspinNumber;
    float * bpm;
    float * offset;
    int * offsetAngle;
    int * twirl;
    int lng;

public:

    void dialogConvert(){
        consoleColor(0,10);
        std::cout<<"Choose language:"<<std::endl;
        consoleColor(0,2);
        std::cout<<"Ru - 0"<<std::endl<<"Eng - 1"<<std::endl<<std::endl;
        consoleColor(0,10);
        while(true){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
                lng=0;
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
                lng=1;
                break;
            }
        }    
        system("cls");
        if(lng==1){
            std::cout<<"Language selected successfully!"<<std::endl<<std::endl<<"Adofai Bot developed by ";
            consoleColor(0,13);
            std::cout<<"SEK1RO";
        }else{
            std::cout<<"Язык успешно выбран!"<<std::endl<<std::endl<<"Adofai Бот, разработан ";
            consoleColor(0,13);
            std::cout<<"SEK1RO";
        }

        std::string adofaiPath="";
        while(true){
            if(lng==1){
                consoleColor(0,10);
                std::cout<<std::endl<<"Input path to .adofai file:"<<std::endl;
            }else{
                consoleColor(0,10);
                std::cout<<std::endl<<"Введите путь к .adofai файлу:"<<std::endl;
            }

            adofaiPath = getFileName();
            std::ifstream adofaiFile(adofaiPath);
            if(adofaiFile.is_open()!=1){
                if(lng==1){
                    system("cls");
                    consoleColor(0,12);
                    std::cout<<std::endl<<"file not found.";
                    consoleColor(0,10);
                    std::cout<<std::endl<<"Try again."<<std::endl;
                }else{
                    system("cls");
                    consoleColor(0,12);
                    std::cout<<std::endl<<"Файл не найден.";
                    consoleColor(0,10);
                    std::cout<<std::endl<<"Попробуйте снова."<<std::endl;
                }
            }else{
                consoleColor(0,10);
                if(lng==1){
                    std::cout<<std::endl<<"Reading selected file..."<<std::endl<<"Processing selected data..."<<std::endl;
                }else{
                    std::cout<<std::endl<<"Чтение выбранного файла..."<<std::endl<<"Обработка полученных данных..."<<std::endl;
                }
                SerializeData adofai;
                adofai.setInputFile(adofaiPath);
                adofai.processMapData();
                angleData = adofai.getAngleData();
                bpm = adofai.getBPM();
                midspinNumber = adofai.getMidspinNumber();
                offset = adofai.getOffset();
                offsetAngle = adofai.getOffsetAngle();
                twirl = adofai.getTwirl();
                dialogAutoplay();
            }
        }    
    }

    void printMapData(){
        consoleColor(0,13);
        if(lng==1){
            std::cout<<std::endl<<"Floor";
            consoleColor(0,10);
            std::cout<<" - angle,\tbpm,\ttwirl,\toffsetAngle,\toffset"<<std::endl<<std::endl;
        }else{
            std::cout<<std::endl<<"Плитка";
            consoleColor(0,10);
            std::cout<<" - угол,\tбпм,\tвихрь,\tуголОффсета,\tоффсет"<<std::endl<<std::endl;
        }
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout<<"0"<<" -\t"<<angleData[0]<<",\t"<<bpm[0]<<",\t"<<twirl[0]<<",\t"<<offsetAngle[0]<<",\t"<<offset[0]<<std::endl;
        for(int i=1;i<angleData.size();i++){
            std::cout<<i+midspinNumber[i-1]<<" -\t"<<angleData[i]<<",\t"<<bpm[i]<<",\t"<<twirl[i]<<",\t"<<offsetAngle[i]<<",\t"<<offset[i]<<std::endl;
        }
        consoleColor(0,13);
        if(lng==1){
            std::cout<<std::endl<<"Floor";
            consoleColor(0,10);
            std::cout<<" - angle,\tbpm,\ttwirl,\toffsetAngle,\toffsetAngle"<<std::endl;
        }else{
            std::cout<<std::endl<<"Плитка";
            consoleColor(0,10);
            std::cout<<" - угол,\tбпм,\tвихрь,\tуголОффсета,\tоффсет"<<std::endl;
        }
    }

    void dialogAutoplay(){
        if(lng==1){
            int inputDialog=3;
            std::string buttons="";
            while(inputDialog!=0){
                inputDialog=3;
                std::cout<<std::endl<<"To continue, go to one of the following sub-items:"<<std::endl;
                std::cout<<std::endl<<"Press 0 to select another file";
                std::cout<<std::endl<<"Press 1 to select simulated keys";
                std::cout<<std::endl<<"Press 2 to show received map data";
                std::cout<<std::endl<<"Press ";
                consoleColor(0,13);
                std::cout<<"space";
                consoleColor(0,10);
                std::cout<<" to start the bot"<<std::endl;
                while(true){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        inputDialog=32;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
                        inputDialog=0;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
                        inputDialog=1;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
                        inputDialog=2;
                        break;
                    }
                }
                if(inputDialog==1){
                    std::cout<<std::endl<<"Enter keys, press to finish ";
                    consoleColor(0,13);
                    std::cout<<"Escape"<<std::endl;
                    consoleColor(0,10);
                    Sleep(150);
                    while(buttons.find("27")==-1){
                        if(isPressed()!=0){
                            buttons+=std::to_string(isPressed());
                            buttons+=" ";
                            whatPressed(isPressed());
                            std::cout<<", ";
                            Sleep(150);
                        }
                    }
                    buttons=buttons.substr(0,buttons.size()-4);
                    system("cls");
                }
                if(inputDialog==2){
                    printMapData();
                }
                if(inputDialog==32){
                    if(buttons==""){
                        buttons="32";
                    }
                    initBot(buttons, angleData, offset, offsetAngle); 
                    system("cls");
                }
                Sleep(150);
            }
            system("cls");
        }else{
            int inputDialog=3;
            std::string buttons="";
            while(inputDialog!=0){
                inputDialog=3;
                std::cout<<std::endl<<"Для продолжения перейдите по одному из следующих подпунктов:"<<std::endl;
                std::cout<<std::endl<<"Нажмите 0 чтобы выбрать другой файл";
                std::cout<<std::endl<<"Нажмите 1 чтобы выбрать имитируемые клавиши";
                std::cout<<std::endl<<"Нажмите 2 чтобы показать полученные данные карты";
                std::cout<<std::endl<<"Нажмите ";
                consoleColor(0,13);
                std::cout<<"пробел";
                consoleColor(0,10);
                std::cout<<" чтобы запустить бота"<<std::endl;
                while(true){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        inputDialog=32;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
                        inputDialog=0;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
                        inputDialog=1;
                        break;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
                        inputDialog=2;
                        break;
                    }
                }
                if(inputDialog==1){
                    buttons="";
                    std::cout<<std::endl<<"Введите клавиши, для завершения нажмите ";
                    consoleColor(0,13);
                    std::cout<<"Escape"<<std::endl;
                    consoleColor(0,10);
                    Sleep(150);
                    while(buttons.find("27")==-1){
                        if(isPressed()!=0){
                            buttons+=std::to_string(isPressed());
                            buttons+=" ";
                            whatPressed(isPressed());
                            std::cout<<", ";
                            Sleep(150);
                        }
                    }
                    buttons=buttons.substr(0,buttons.size()-4);
                    system("cls");
                }
                if(inputDialog==2){
                    printMapData();
                }
                if(inputDialog==32){
                    if(buttons==""){
                        buttons="32";
                    }
                    initBot(buttons, angleData, offset, offsetAngle); 
                    system("cls");
                }
                Sleep(150);
            }
            system("cls");
        }
    }

};