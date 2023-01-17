# console_panel_software

This is an small device that allow record an voltage and current in two modes. The simplest mode is when the device is connected to PC and it sends data throught UART over USB. 
The second mode is when device is connected to power supply and just records data in internal memory.
The all software and hardware is open sources and avabile there, currently some manuals and software comments are in Russian and later when we will found some time we will translate them.


# Many thanks to:
@misha-dig


# PCB making in home
Used toner techology not perfect,but ok with skills
https://user-images.githubusercontent.com/20460747/213031487-345124f8-0b84-45e8-b4c8-0aedab619b45.mp4

# Project demo 
<iframe width="1280" height="720" src="https://www.youtube.com/embed/LSznjLQJUaE" title="Демонстрация console_panel_software" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


# Software 
## Firmware

The firmware is based on arduino core and use an libires.  
list is:  
1. Adafruit_GFX
2. Adafruit_SSD1306
3. Wire
4. Eeprom24C32_64
5. EEPROM

The code is messy and needs to cleanup,sorting and comments adding. Also docs building will be great using doxygen.


## Desktop
Developed on C# and requries .Net Framework 4.7.2 for work. Based on WinForms. 
Big sorry to MacOS and Linux users. The app is not support this OS-es...  (tried Wine ... seems working ... ,but still not native)  
Used libs: 
1. RibbonWinForms 
2. Putty as alternative way to see data from com port
3. drivinst64 for driver install
And bunch of plain C# code. 

# Screenshots(under wine):

![image](https://user-images.githubusercontent.com/20460747/213033275-50029745-ca9d-47a0-a804-3d557caf3678.png)
![image](https://user-images.githubusercontent.com/20460747/213033336-c12f3ade-f977-402f-a9a8-17f290535ae3.png)
![image](https://user-images.githubusercontent.com/20460747/213033353-3ad43fad-018c-4c6a-b69b-43fcacf0130d.png)
![image](https://user-images.githubusercontent.com/20460747/213033380-b30d2f0b-bd7e-4367-8f14-4b14dba43363.png)

# Screenshots under Windows 10
![image](https://user-images.githubusercontent.com/20460747/213033761-9282c3cd-b759-4cac-a0e8-004345bad981.png)
![image](https://user-images.githubusercontent.com/20460747/213033774-fe3f46a7-33e5-4eb2-b12d-922b0416b124.png)
![image](https://user-images.githubusercontent.com/20460747/213033786-c4bbbadc-c628-4dcd-8ce0-65e2542e3932.png)


All is lagging and unstabile,but will developed more and more.


# Yup we told that ur language is Russian... we not blind and know what is going on in world.
But before we continue... I wanna talk about our world. In 24/02/2022 many of my friends, relatives and people matters a lot for me faced an war in Ukraine... The Russian army is killing people in Ukraine,destroy an cities an kill thousands of civils. Is time to help if we want so see modern world not like in 1984 novel. Is not time to discuss. Is a war is a pain and hell. https://saveua.in.ua/en And many others. Stay strong Ukraine yellow_heartblue_heart




