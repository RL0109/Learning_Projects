

class Paddle {
    float xLoc;
    float yLoc;
    float width;
    float height;
    SDL_FRect player;

    Paddle(float x, float y, float w, float h) {
        player = {x, y, w, h};
        xLoc = x;
        yLoc = y;
        width = w;
        height = h;
    }

    float getCenter() {
        return yLoc + (height / 2.0f);
    }




};