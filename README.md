# AutoDofai

### ������� ������� ������ / Download: [__v0.1__](https://github.com/vSEK1RO/3D_Engine/releases/download/v0.1/src.rar)

>������ ������ ������������ ����� ���� ��� ������ � ������������ �������� ��������� �������.

>This project is a bot for adofai with the ability to simulate click patterns.

�� ������ ������ ����������� / Currently implemented

:white_check_mark: ����� ��� ������������ ������ ������ / class for serializing map data

:white_check_mark: ����� ��� ������� ������� ����� �������� / method for calculating offset between floors

:black_square_button: ����������� �������� ��������� ������� / ability to simulate click patterns

# ������������ / Documentation

### class SerializeData

�������� ������ ������ SerializeData, ����� ���� ��������� � ��������� ������ ����� setInputFile(string filePath), ����� ���� ����������� ���������� ������ ��� ������ processMapData().
����� ����������� ��������������� ������ ������� � ������� ��� ��������� ���������� ����� (������ angleData � ��������� �� ������� � bpm, offset, twirl).

Create an object of the SerializeData class, then run the setInputFile(string filePath) method in a separate thread, and then process the received data using processMapData().
Next, use the appropriate getter and setter methods to get the map parameters (angleData vector and pointers to arrays with bpm, offset, twirl).
     
     SerializeData adofai;
     adofai.setInputFile(adofaiPath);
     adofai.processMapData();
     angleData = adofai.getAngleData();
     bpm = adofai.getBPM();

### function initBot

��������� ������ �������������� ����������� ������. ���������� initBot(string buttons, vector angleData, float * offset), ��� buttons ������, ��������� �� VK ����� ������, angleData � offset - ������ � ���������, ���������� ��������� ������ SerializeData.
Allows you to start the automatic passage of the level. Called by initBot(string buttons, vector angleData, float * offset), where buttons is a string consisting of VK key codes, angleData and offset are a vector and a pointer received by the getters of the SerializeData class.

     string buttons = "69 70 71 72";
     vector <int> angleData = adofai.getAngleData();
     int * offset = adofai.getOffset();
     initBot(buttons, angleData, offset); 

### class DialogMenu

��������� ������� ����������� ���������� ���� � ������� � �������. ��� ������������� ������������ dialogConvert().
Allows you to call a standard dialog menu with output to the console. DialogConvert() is used for initialization.

     DialogMenu menu;
     menu.dialogConvert();
