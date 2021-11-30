#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"
#include "defines.h"
#include "logic.h"
#include "init.h"

void DoKeyDown(App *app, SDL_KeyboardEvent *event) {
    if (event->keysym.scancode < 300) {
        app->keys[event->keysym.scancode] = 1;
    }
}

void DoKeyUp(App *app, SDL_KeyboardEvent *event) {
    if (event->keysym.scancode < 300) {
        app->keys[event->keysym.scancode] = 0;
    }
}

void DoInput(App *app) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                QuitSDL(app);
                break;
            case SDL_KEYDOWN:
                DoKeyDown(app, &event.key);
                break;
            case SDL_KEYUP:
                DoKeyUp(app, &event.key);
                break;
        }
    }
}

void DoPaddles(App *app, Entity *paddle1, Entity *paddle2) {
    
    if (app->keys[SDL_SCANCODE_W] == 1) {
        paddle1->dy = -PADDLE_SPEED;
    }

    if (app->keys[SDL_SCANCODE_S] == 1) {
        paddle1->dy = PADDLE_SPEED;
    } 

    if (app->keys[SDL_SCANCODE_UP] == 1) {
        paddle2->dy = -PADDLE_SPEED;
    }

    if (app->keys[SDL_SCANCODE_DOWN] == 1) {
        paddle2->dy = PADDLE_SPEED;
    }

    paddle1->y += paddle1->dy;
    paddle2->y += paddle2->dy;

    if (paddle1->y < 0) {
        paddle1->y = 0;
    }

    if (paddle1->y + paddle1->h > 720) {
        paddle1->y = 720 - paddle1->h;
    }

    if (paddle2->y < 0) {
        paddle2->y = 0;
    }

    if (paddle2->y + paddle1->h > 720) {
        paddle2->y = 720 - paddle1->h;
    }

    paddle1->dy = 0;
    paddle2->dy = 0;
}

int Collide(Entity *entity1, Entity *entity2) {
    if ((entity1->x < entity2->x + entity2->w && entity1->x + entity1->w > entity2->x) && (entity1->y < entity2->y + entity2->h && entity1->y + entity1->h > entity2->y)) {
        return 1;
    }
    return 0;
}

void DoBall(App *app, Entity *ball, Entity *paddle1, Entity *paddle2) {
    if (Collide(ball, paddle1) == 1) {
        
        
        ball->dx = -ball->dx;
        ball->x = paddle1->x + paddle1->w + 1;
    }

    if (Collide(ball, paddle2) == 1) {
        
        
        ball->dx = -ball->dx;
        ball->x = paddle2->x-paddle2->w-1;
    }

    if (ball->y < 0) {
        
        ball->dy = -ball->dy;
    } 

    if (ball->y + ball->h > 720) {
        
        ball->dy = -ball->dy;
    }

    if (ball->x < 0 || ball->x+ball->w > 1280) {
        ball->x = 1280/2;
        ball->y = 720/2;
    }

    ball->x += ball->dx;
    ball->y += ball->dy;
}