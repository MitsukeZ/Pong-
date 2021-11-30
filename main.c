#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "headers/structs.h"
#include "headers/init.h"
#include "headers/logic.h"
#include "headers/draw.h"
#include "headers/defines.h"

int main(int argc, char *argv[]) {
    App app;
    Stage stage;
    Entity paddle1, paddle2, ball;

    InitSDL(&app);
    InitStage(&stage);
    InitEntity(&app, &paddle1, 100, 370-64, 8, 64, 0, 0, "sprites/paddle.png");
    InitEntity(&app, &paddle2, 1180, 370-64, 8, 64, 0, 0, "sprites/paddle.png");
    InitEntity(&app, &ball, 1280/2, 720/2, 8, 8, 5, 5, "sprites/ball.png");

    while (1) {
        //logic
        DoInput(&app);
        DoCoins(&app, &stage);
        if (stage.coins > 0) {
            CheckPoints(&stage);
            
            DoPaddles(&app, &paddle1, &paddle2);
            DoBall(&app, &ball, &paddle1, &paddle2, &stage);
            //draw
            DrawPaddles(&app, &paddle1, &paddle2);
            DrawEntity(&app, &ball);
            DrawScore(&app, &stage);
            DrawLine(&app);

            
        } else {
            DrawMenu(&app);
        }
        Update(&app);
        SDL_Delay(16);
        Clear(&app);
    }

    return 0;


}