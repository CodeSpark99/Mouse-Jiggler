Mouse-Jiggler
=============
A mouse jiggler is a hardware device that simulates random mouse movement to prevent your computer from going into sleep mode or screensaver. 
It's useful for avoiding screensavers and inactivity detection.
Inspired by Work From Home.

Setup Instructions
============

I'm assuming that you already know how to use the Arduino IDE and can upload code and reset your Arduino device. This also requires you to have already installed FLIP on your computer.

Uploading to the Arduino
------------------------

Donwload the project file (Mouse_Jiggler.ino) and upload the code as you normally would. Keep settings as per normal. I'm using a Uno R3 and it works just fine. No need for any libraries too. 
In case of any issues, do let me know so that I may rectify them as soon as possible.

Flashing the firmware
---------------------

1. Download FLIP from this link (on Windows). Use the version with Java Runtime Environment included:
https://www.microchip.com/en-us/development-tool/flip
2. Follow the wizard and do a standard FLIP install.
3. Make Arduino go into DFU mode by connecting these two pins (with a wire or any other means you have) and removing it after a few seconds:
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/55e9d55c-5fcc-4385-a544-118cf081b862)
Note: This could vary based on your Arduino. I'm using the Uno R3 so this is how I do it. Otherwise, a quick google search on "arduino <model name> DFU mode" will help you out.
4. Run FLIP and select your EEPROM by pressing 'Select a Target Device':
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/a96a923c-56c6-4c4a-93e4-112750dec4c4)
If you have an UNO R3 like I do, select 'ATmega16U2'. Else, look up your model name and EEPROM and select accordingly.
5. Press Ctrl+U or press this button and select 'USB':
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/83e96794-8aa8-4e37-861a-a20327d0ee02)
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/60e2ec4c-322d-4368-88c4-ff855d13c754)
6. Press 'Open' in the dialog box:
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/bb015968-97cc-4084-98a3-fa1cb0fdbdbd)
If done correctly, the result will look something like this (all the options will no longer be grayed out):
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/eb950cfd-4654-4c6d-b026-ae63b6112f9a)
Ignore the numerical values on the right hand side, it varies from user to user.
7. Download the hex file in the repo (Arduino-mouse-0.1.hex) 
8. Press Ctrl+L or File>Load HEX file...
9. Select the downloaded hex file.
Note : Keep a backup hex file containing the firmware of your Arduino Model in case things don't go as planned. It's found on the Arduino website. You can follow these instructions (step 3-11) to flash you Arduino's firmware and use it normally again.
10. Select 'Run' and then 'Start Application':
![image](https://github.com/CodeSpark99/Mouse-Jiggler/assets/90392920/91415da6-6c81-42cf-823d-e45dfcdb6012)
11. Unplug your Arduino, close FLIP and plug your Arduino in again

Wait for about 5 seconds and you will start to see your cursor move on its own periodically.
Congrats, you have made your very own mouse jiggler.

FAQ
===

1. How to make the cursor move more/less frequently?
   Change this line in the code to whateber number you like (1500 = 1.5 seconds):
   delay(1500);
2. FLIP giving the error 'AtLibUsbDfu.dll not found'.
   Lookup the .dll file on the internet and install it (I used dll-files.com). It is recommended to use the same site as I did, as the wrong .dlls can cause big problems. Copy the file into your install folder. If you 
   have done a default install, go to C:>Program Files (x86)> Atmel> FLIP x.x.x (the version number)> usb. Then restart FLIP.
3. How to change the resolution of the screen in the code?
   The code was written for my monitor (1024x768). For a 1080p monitor (1920x1080), replace lines 21-24 with this code instead:
   
   int xr_val = random(-1920, 1919);
   int yr_val = random(-1080, 1079);
   mouseReport.x = map(xr_val, -1920, 1919, -10, 10);
   mouseReport.y = map(yr_val, -1080, 1079, -10, 10);

   And this code for a 4K monitor (3840x2160):

    int xr_val = random(-3840, 3839);
    int yr_val = random(-2160, 2159);
    mouseReport.x = map(xr_val, -3840, 3839, -10, 10);
    mouseReport.y = map(yr_val, -2160, 2159, -10, 10);

   

