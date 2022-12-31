#include "../src/include/SFML/Graphics.hpp"
#include <iostream>

int isPressed(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){return 27;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){return 32;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){return 48;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){return 49;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){return 50;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){return 51;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){return 52;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)){return 53;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){return 54;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){return 55;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)){return 56;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)){return 57;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){return 65;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){return 66;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){return 67;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){return 68;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){return 69;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){return 70;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){return 71;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){return 72;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){return 73;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){return 74;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){return 75;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){return 76;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){return 77;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)){return 78;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){return 79;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){return 80;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){return 81;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){return 82;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){return 83;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){return 84;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)){return 85;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)){return 86;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){return 87;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){return 88;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){return 89;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){return 90;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){return 162;}
    
    return 0;
}

void whatPressed(int n){
    switch (n){
        case 27: std::cout<<"Escape"; break;
        case 32: std::cout<<"Space"; break;
        case 48: std::cout<<"Num0"; break;
        case 49: std::cout<<"Num1"; break;
        case 50: std::cout<<"Num2"; break;
        case 51: std::cout<<"Num3"; break;
        case 52: std::cout<<"Num4"; break;
        case 53: std::cout<<"Num5"; break;
        case 54: std::cout<<"Num6"; break;
        case 55: std::cout<<"Num7"; break;
        case 56: std::cout<<"Num8"; break;
        case 57: std::cout<<"Num9"; break;
        case 65: std::cout<<"A"; break;
        case 66: std::cout<<"B"; break;
        case 67: std::cout<<"C"; break;
        case 68: std::cout<<"D"; break;
        case 69: std::cout<<"E"; break;
        case 70: std::cout<<"F"; break;
        case 71: std::cout<<"G"; break;
        case 72: std::cout<<"H"; break;
        case 73: std::cout<<"I"; break;
        case 74: std::cout<<"J"; break;
        case 75: std::cout<<"K"; break;
        case 76: std::cout<<"L"; break;
        case 77: std::cout<<"M"; break;
        case 78: std::cout<<"N"; break;
        case 79: std::cout<<"O"; break;
        case 80: std::cout<<"P"; break;
        case 81: std::cout<<"Q"; break;
        case 82: std::cout<<"R"; break;
        case 83: std::cout<<"S"; break;
        case 84: std::cout<<"T"; break;
        case 85: std::cout<<"U"; break;
        case 86: std::cout<<"V"; break;
        case 87: std::cout<<"W"; break;
        case 88: std::cout<<"X"; break;
        case 89: std::cout<<"Y"; break;
        case 90: std::cout<<"Z"; break;
        case 162: std::cout<<"LControl"; break;
        default: break;
    }
}
