# 俄罗斯方块小游戏

这是使用raylib用C++编写的俄罗斯方块小游戏

## 项目模板

使用Raylib-CPP-Starter-Template模板进行开发

https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2

## 参考

[(2248) Creating Tetris in C++ with raylib - Beginner Tutorial (OOP) - YouTube](https://www.youtube.com/watch?v=wVYKG_ch4yM)

https://www.youtube.com/watch?v=wVYKG_ch4yM

## 改进之处

* 对成员变量进行了大量的封装，将许多功能整理到不同的文件。
* 新增了功能可以使用户可以根据config文件直接修改程序部分的界面，而不用担心兼容性问题。

* 提高了程序的安全性、可读性和易修改性。

## 不足之处

当前方块直接在网格中显示，造成了游戏结束时最后的方块不显示或者与倒数第一个方块发生重叠。

在编程的过程中才创建config文件想让用户可以直接修改config而不用担心兼容性问题，但仍有部分内容需要手动修改，如UI的y轴位置。

# Tetris Game

This a Tetris game wiritten by C++ with raylib

## Project Template

Developed using the Raylib-CPP-Starter-Template.

https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2

## reference

[(2248) Creating Tetris in C++ with raylib - Beginner Tutorial (OOP) - YouTube](https://www.youtube.com/watch?v=wVYKG_ch4yM)

https://www.youtube.com/watch?v=wVYKG_ch4yM

## Improvements

* Extensively encapsulated member variables and organized many functions into different files.
* Added a feature allowing users to directly modify parts of the program's interface via a config file without compatibility issues.
* Enhanced the program's security, readability, and ease of modification.

## Limitations

* the current square is displayed directly in the grid, causing the last square not to be displayed or to overlap with the penultimate square when the game end.
* The config file was created only during the programming process to allow the user to modify the config directly without having to worry about compatibility issues, but some elements still require manual adjustment, such as the y-axis position of the UI.
