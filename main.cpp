#include <windows.h>
#include "cpp/dialogMenu.h"
#include "cpp/update.h"

int main(){
    update("v0.7");
    SetConsoleCP(21866); 
    SetConsoleOutputCP(21866);
    DialogMenu menu;
    menu.dialogConvert();
}