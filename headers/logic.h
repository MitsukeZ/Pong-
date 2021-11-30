void DoInput(App *app);
void DoKeyDown(App *app, SDL_KeyboardEvent *event);
void DoKeyUp(App *app, SDL_KeyboardEvent *event);
void DoPaddles(App *app, Entity *paddle1, Entity *paddle2);
int Collide(Entity *entity1, Entity *entity2);
void DoBall(App *app, Entity *ball, Entity *paddle1, Entity *paddle2);