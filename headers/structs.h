typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int keys[300];
} App;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int dx;
    int dy;

    SDL_Texture *texture;
} Entity;

typedef struct {
    int p1score;
    int p2score;
    int coins;
    
} Stage;