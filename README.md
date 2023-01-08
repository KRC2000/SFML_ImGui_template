# SFML_ImGui_template

## How to get started
1. Install sfml library on your linux machine: ```sudo apt install libsfml-dev```
2. Download this repo
3. Open downloaded repo folder with VS Code(with c/c++ plugin installed) and click run button\
OR \
if you don't use VS Code - open terminal, cd into the project folder, build it with the command: 
```
g++ -fdiagnostics-color=always -g -I ./include/ ./*.cpp -lGL -lsfml-graphics -lsfml-window -lsfml-system -o ./executable
```
You can also remove .vscode folder from the project if you don't use VS Code to build the solution\
ImGui library version used: 1.89.2\
![image](https://user-images.githubusercontent.com/47914319/211198969-737bcad8-a858-4916-a13c-0549f2188421.png)
