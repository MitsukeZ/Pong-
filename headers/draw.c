#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "structs.h"
#include "defines.h"
#include "init.h"
#include "draw.h"

void Update(App *app) {
    SDL_RenderPresent(app->renderer);
}

void Clear(App *app) {
    SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
    SDL_RenderClear(app->renderer);
}

void DrawEntity(App *app, Entity *entity) {
    SDL_Rect rect;
    rect.x = entity->x;
    rect.y = entity->y;
    SDL_QueryTexture(entity->texture, NULL, NULL, &rect.w, &rect.h);
    rect.w = entity->w;
    rect.h = entity->h;
    SDL_RenderCopy(app->renderer, entity->texture, NULL, &rect);
}

void DrawPaddles(App *app, Entity *paddle1, Entity *paddle2) {
    DrawEntity(app, paddle1);
    DrawEntity(app, paddle2); 
}

void DrawScore(App *app, Stage *stage) {
    //printf("dro score");
    SDL_Texture *tex1, *tex2;
    
    SDL_Rect rect1, rect2;

    rect1.x = 1280/2 + 150;
    rect1.y = 35;

    rect2.x = 1280/2 - 150;
    rect2.y = 35;
    
    tex1 = IMG_LoadTexture(app->renderer, stage->scorefiles[stage->p1score]);
    tex2 = IMG_LoadTexture(app->renderer, stage->scorefiles[stage->p2score]);

    
    SDL_QueryTexture(tex1, NULL, NULL, &rect1.w, &rect1.h);
    SDL_QueryTexture(tex2, NULL, NULL, &rect2.w, &rect2.h);

    rect1.w *= 4;
    rect1.h *= 4;

    rect2.w *= 4;
    rect2.h *= 4;
    
    SDL_RenderCopy(app->renderer, tex1, NULL, &rect1);
    SDL_RenderCopy(app->renderer, tex2, NULL, &rect2);

    
}   

void DrawLine(App *app) {
    SDL_Rect rect;
    SDL_Texture *tex;
    rect.x = 1280/2;
    tex = IMG_LoadTexture(app->renderer, "sprites/ball.png");
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.w *= 2;
    rect.h *= 2;

    for (int i = 0; i < 720; i += 20) {
        rect.y = i; 
        SDL_RenderCopy(app->renderer, tex, NULL, &rect);
    }
}

void DrawMenu(App *app) {
    SDL_Rect rect;
    SDL_Texture *tex;
    
    tex = IMG_LoadTexture(app->renderer, "sprites/insertcoin.png");
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.w *= 4;
    rect.h *= 4;
    rect.x = 1280/2 - rect.w/2;
    rect.y = 720/2 - rect.h/2;

    
    SDL_RenderCopy(app->renderer, tex, NULL, &rect);
    
}