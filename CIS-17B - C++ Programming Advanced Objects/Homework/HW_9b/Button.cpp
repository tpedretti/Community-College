#include "Button.h"


//The button states in the sprite sheet
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

//The surfaces
SDL_Surface *buttonSheet = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The clip regions of the sprite sheet
SDL_Rect clips[ 4 ];

Button::Button(int x, int y, int w, int h) {
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //Set the default sprite
    clip = &clips[ CLIP_MOUSEOUT ];
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void Button::handle_events() {
    //The mouse offsets
    int x = 0, y = 0;

    //If the mouse moved
    if( event.type == SDL_MOUSEMOTION ) {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;

        //If the mouse is over the button
        if((x > box.x) && (x < box.x + box.w) && ( y > box.y ) && (y < box.y + box.h)) {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOVER ];
        }
        //If not
        else
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOUT ];
        }
    }
    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEDOWN ];
            }
        }
    }
    //If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEUP ];
            }
        }
    }
}

void Button::show() {
    //Show the button
    apply_surface( box.x, box.y, buttonSheet, screen, clip );
}