# miniGame
- A small single player game based on Asteroids. It uses the raylib library which is open source and be found here: https://github.com/raysan5/raylib .  

# Installation Ubuntu Linux as of 20/11/2025

- Install cmake using: 
  
  ```
  sudo apt install cmake
  ```

- in the terminal navigate to the project's root directory 

- to create the build folder run the command: 
  
  ```
  cmake -B build
  ```

- navigate to the build folder you just created using: 

  ```
  cd build
  ```
- now run the command while inside the build folder: 

  ```
  cmake --build . --parallel
  ```

- now navigate back to the root directory using: 
  
  ```
  cd ../
  ```

- finally to run the application use: 
  
   ```
   ./build/game
   ```

# Installation Windows 10 as of 20/11/2025

- Install cmake. There are many ways to do this on windows but a simple GUI based way is as follows. Go to: https://cmake.org/download/ 

- Select "Windows x64 Installer" option for x64 systems. 

- Once you've downloaded the cmake installer run it and follow the prompts. 

- Now that you have cmake navigate to the project's root folder using powershell. You can achieve this by right-clicking on the  root folder and selecting "open in terminal".

- Now create the build folder using: 

  ```
  mkdir build
  ```

- Run this command to generate a visual studio project: 

  ```
  cmake -S . -B build
  ```
- Now build the project using: 

  ```
  cmake --build build --config Release
  ```
- Finally run the application using: 
  
  ```
  .\build\Release\game.exe
  ```
## Gameplay Footage

![Gameplay Footage GIF](https://github.com/stavvos/miniGame/raw/main/assets/video/demo.gif)
