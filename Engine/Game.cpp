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
    player = Player{ 300,300,50,50,Colors::Blue,2 };
    field = Field{};
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
        if ((player.coords.y + player.height + player.speed) < gfx.ScreenHeight) {
            player.coords.y += player.speed;
        }
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
        if ((player.coords.x - player.speed) > 0) {
            player.coords.x -= player.speed;
        }
    }
    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        if ((player.coords.x + player.length + player.speed) < gfx.ScreenWidth) {
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
    if ((player.coords.x <= box.coords.x + box.length)
     && (player.coords.x + player.length >= box.coords.x)
     && (player.coords.y <= box.coords.y + box.height)
     && (player.coords.y + player.height >= box.coords.y))
        return true;
    return false;
}

void Game::DrawElement(Element element)
{
    int xPos, yPos;
    for (int i = 0; i < element.length; ++i) {
        for (int j = 0; j < element.height; ++j) {
            xPos = element.coords.x + i;
            yPos = element.coords.y + j;
            if (xPos < gfx.ScreenWidth && xPos > 0
                && yPos < gfx.ScreenHeight && yPos > 0)
                gfx.PutPixel(xPos, yPos, element.color);
        }
    }
}

void Game::ComposeFrame()
{
        //Player
        DrawElement((Element)player);
        //Box
        int xPos, yPos;
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

