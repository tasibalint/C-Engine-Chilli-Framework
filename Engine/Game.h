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
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
    bool checkForOverlap();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
    struct Coords {
        int x;
        int y;
        Coords(int x, int y) : x(x), y(y) {}
    };
    //Player
    struct Player {
        int speed;
        int sizeX;
        int sizeY;
        Coords coords ;
        Color color;
        Player(): speed(2), sizeX(50), sizeY(50), coords(Coords{400, 300}), color(Colors::Blue) {}
    };
    Player player;
    //Box
    struct Box {
        int length;
        Coords coords;
        Color color;
        Box() : length(50), coords(Coords{200,200}), color(Colors::Green) {};
    };
    Box box;

    int gb = 255;
	/********************************/
	/*  User Variables              */
	/********************************/
};