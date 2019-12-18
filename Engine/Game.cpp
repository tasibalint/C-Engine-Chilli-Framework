/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd)
{
    box = Box{};
    player = Player{};
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (wnd.kbd.KeyIsPressed(VK_UP)) {
        if ((player.coords.y - player.speed) > 0) {
            player.coords.y -= player.speed;
        }
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
        if ((player.coords.y + player.sizeY + player.speed) < gfx.ScreenHeight) {
            player.coords.y += player.speed;
        }
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
        if ((player.coords.x - player.speed) > 0) {
            player.coords.x -= player.speed;
        }
    }
    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        if ((player.coords.x + player.sizeX + player.speed) < gfx.ScreenWidth) {
            player.coords.x += player.speed;
        }
    }

    if (checkForOverlap()){
        box.color = Colors::Red;
    }
    else {
        box.color = Colors::Green;
    }
}

bool Game::checkForOverlap()
{
    for (int px = player.coords.x; px < player.coords.x +player.sizeX; ++px) {
        for (int py = player.coords.y; py < player.coords.y +player.sizeY; ++py) {
            for (int bx = box.coords.x; bx < box.coords.x + box.length; ++bx) {
                for (int by = box.coords.y; by < box.coords.y + box.length; ++by) {
                    if (px == bx && py == by)
                        return true;
                }
            }
        }
    }
    return false;
}

void Game::ComposeFrame()
{
        //Player
        int xPos, yPos;
        for (int i = 0; i < player.sizeX; ++i) {
            for (int j = 0; j < player.sizeY; ++j) {
                xPos = player.coords.x + i;
                yPos = player.coords.y + j;
                if (xPos < gfx.ScreenWidth  && xPos > 0
                 && yPos < gfx.ScreenHeight && yPos > 0)
                    gfx.PutPixel(xPos, yPos, player.color);
            }
        }

        //Box
        for (int i = 0; i < box.length; ++i) {
            for (int j = 0; j < box.length; ++j) {
                xPos = box.coords.x + i;
                yPos = box.coords.y + j;
                if (xPos < gfx.ScreenWidth && xPos > 0
                    && yPos < gfx.ScreenHeight && yPos > 0)
                    gfx.PutPixel(xPos, yPos, box.color);
            }
        }
}

