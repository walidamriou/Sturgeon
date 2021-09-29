# Sturgeon
Embedded project for beginners to control DC Motor speed via Display (based 4xLED and 1xbutton with buzzer)

### Project name 
I like to name the projects using names that give motivation and meaning. Sturgeon project name comes from William Sturgeon invented the first DC motor that could provide enough power to drive machinery but it wasn't until 1886 that the first practical DC motor that could run at a constant speed under variable weight, was produced.

### System block diagram

- fan
- main board
- display

```
 ____________                                 _________________________________                ___________________________________________
|            | <=== motor attack signal ==== |                                 |              |                                           |    
|    FAN     |                               |  Main board                     | <=========== |  Display board                            |         
|____________| ==== motor speed signal ====> | (Buck converter DC/DC with MCU) |              |  (MCU, 1x Button, 4x LEDs, and !x buzzer) |
                                             |_________________________________|              |___________________________________________|

```


