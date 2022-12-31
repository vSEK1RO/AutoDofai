<h1 align="center"> AutoDofai </h1>

Скачать текущую версию / Download: [__v0.5__](https://github.com/vSEK1RO/AutoDofai/releases/download/v0.5/AutoDofai_v0.5.rar)

#### Поддерживается для версии 2.3.0 / Supported for version 2.3.0

>Данный проект представляет собой бота для __адофаи__ с возможностью имитации паттернов нажатий.

>This project is a bot for __adofai__ with the ability to simulate click patterns.

#### На данный момент реализовано / Currently implemented

:white_check_mark: класс для сериализации данных уровня / class for serializing map data

:white_check_mark: метод для расчета оффсета между плитками / method for calculating offset between floors

:white_check_mark: возможность имитации паттернов нажатий / ability to simulate click patterns

<h1 align="center"> Документация / Documentation </h1>

### class SerializeData

Создайте объект класса SerializeData, после чего запустите в отдельном потоке метод setInputFile(string filePath), после чего обработайте полученные данные при помощи processMapData().
Далее используйте соответствующие методы геттеры и сеттеры для получения параметров карты (вектор angleData и указатели на массивы с bpm, offset, twirl).

Create an object of the SerializeData class, then run the setInputFile(string filePath) method in a separate thread, and then process the received data using processMapData().
Next, use the appropriate getter and setter methods to get the map parameters (angleData vector and pointers to arrays with bpm, offset, twirl).
     
```c#
     SerializeData adofai;
     adofai.setInputFile(adofaiPath);
     adofai.processMapData();
     angleData = adofai.getAngleData();
     bpm = adofai.getBPM();
```

### function initBot

Позволяет начать автоматическое прохождение уровня. Вызывается initBot(string buttons, vector angleData, float * offset), где buttons строка, состоящая из VK кодов клавиш, angleData и offset - вектор и указатель, полученные геттерами класса SerializeData.

Allows you to start the automatic passage of the level. Called by initBot(string buttons, vector angleData, float * offset), where buttons is a string consisting of VK key codes, angleData and offset are a vector and a pointer received by the getters of the SerializeData class.

```c#
     string buttons = "69 70 71 72";
     vector <int> angleData = adofai.getAngleData();
     int * offset = adofai.getOffset();
     initBot(buttons, angleData, offset); 
```

### class DialogMenu

Позволяет вызвать стандартное диалоговое меню с выводом в консоль. Для инициализации используется dialogConvert().

Allows you to call a standard dialog menu with output to the console. DialogConvert() is used for initialization.

```c#
     DialogMenu menu;
     menu.dialogConvert();
```
