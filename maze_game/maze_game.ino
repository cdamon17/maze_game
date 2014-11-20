/*
  moving_dot.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 move a dot
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h> // Required code, line 1 of 2.
// Global variables go here
int xcoord = 0;
int ycoord = 0;
void setup() // run once, when the sketch starts
{
MeggyJrSimpleSetup(); // Required code, line 2 of 2.
}
void loop() // run over and over again
{
  shift();  // Johnathan Nakagawa helped with how shift code works
  DrawPx(xcoord,ycoord,Red); // Draws Dot
  DisplaySlate();
  delay(50);
  ClearSlate();
}
// collisoin dectection simple
// if (readPx(xcoord+1,ycoord)==0);
// xcoord++;

void shift()
{
  CheckButtonsPress();
  if (Button_Up)
    {
      if (ycoord < 7)
        ycoord = ycoord + 1;
    //else ycoord = 0;   should make dot go to bottom after reacing top,
    //                   but it still does any way, not sure why
    //if (ycoord>7)   code examened from other students,
   // {               but can not move dot from edge of screen
   //   ycoord=7;
  //  }
    }
  
  if (Button_Right)
  {
    if (xcoord < 7)
      xcoord = xcoord + 1; //also xcoord++
   // else xcoord = 0;
  //  if (xcoord>7)
  //  {
   //   xcoord=7;
  //  }
  }
  if (Button_Left)
  {
     if (xcoord>0) 
       xcoord = xcoord - 1;
    // else xcoord = 7;
  }
  if (Button_Down)
  {
    if (ycoord > 0)
    ycoord = ycoord - 1;
  //  else ycoord = 7;
  }
}
