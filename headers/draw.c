#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

