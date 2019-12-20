/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <tgmath.h>

class Game
{
private:
	MainWindow& wnd;
	Graphics gfx;
    struct Coords {
        int x;
        int y;
        Coords(int x, int y) : x(x), y(y) {}
    };
    struct Element {
        Coords coords;
        int length;
        int height;
        Color color;
        Element() : length(0), height(0), coords(Coords(0,0)), color(Colors::White) {};
        //Element(int x, int y, int length, int height, Color color) : coords(Coords{ x,y }), length(length), height(height), color(color) {};
    };
    //Player
    struct Player : Element {
        int speed;
        Player(int x, int y, int l, int h, Color c, int speed) : speed(speed) { 
            coords.x = x;
            coords.y = y;
            length = l;
            height = h;
            color = c;
        };
        Player() : speed(2) {
            coords.x = 0;
            coords.y = 0;
            length = 10;
            height = 10;
            color = Colors::White;
        }
    };

    Player player;
    //Field
    struct Field {
        Coords coords;
        int length;
        int height;
        Color color;
        Field() : coords(Coords{ 0,0 }), length(600), height(800), color(Colors::Cyan) {};
    };
    Field field;
    //Box
    struct Box {
        int length;
        int height;
        Coords coords;
        Color color;
        Box() : length(50), height(50), coords(Coords{200,200}), color(Colors::Green) {};
    };
    Box box;
public:
    Game(class MainWindow& wnd);
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void Go();
private:
    void ComposeFrame();
    void UpdateModel();
    bool checkForOverlap();
    void DrawElement(Element element);
};