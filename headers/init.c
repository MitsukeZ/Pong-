#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"
#include "defines.h"
#include "init.h"

void QuitSDL(App *app) {
    if (app->renderer != NULL) {
        SDL_DestroyRenderer(app->renderer);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    IMG_Quit();
    SDL_Quit();
    exit(0);
}

void InitSDL(App *app) {
    //Initializing app to avoid memory leaks
    app->window = NULL;
    app->renderer = NULL;
    
    //Initializing SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("\nError initializing SDL : %s", SDL_GetError());
        QuitSDL(app);
    } else {
        printf("\nSuccessfully initialized SDL !");
    }

    //Initializing SDL_image
    if (IMG_Init(IMGFLAGS) != IMGFLAGS) {
        printf("\nError initializing SDL image : %s", SDL_GetError());
        QuitSDL(app);
    } else {
        printf("\nSuccessfully initialized SDL image!");
    }

    //Creating Window
    app->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if (app->window == NULL) {
        printf("\nError creating window : %s", SDL_GetError());
        QuitSDL(app);
    }
    //Creating Renderer
    app->renderer = SDL_CreateRenderer(app->window, -1, 0);
    if (app->renderer == NULL) {
        printf("\nError creating renderer : %s", SDL_GetError());
        QuitSDL(app);
    }

    for (int i = 0; i < 300; i++) {
        app->keys[i] = 0;
    }
}

void InitEntity(App *app, Entity *entity, int x, int y, int w, int h, int dx, int dy, char *filename) {
    entity->x = x;
    entity->y = y;
    entity->w = w;
    entity->h = h;
    entity->dx = dx;
    entity->dy = dy;
    entity->texture = IMG_LoadTexture(app->renderer, filename);
}

