#include <iostream>
#include <raylib.h>
#include<deque>

using namespace std;
Color Green = { 173, 204, 96, 255};
Color dark_Green = { 43, 51, 24, 255};

int cell_size = 30;
int cellCount = 25;

class Snake{
    
    
    public:
    deque<Vector2> body = {Vector2{6,9},Vector2{5,9}, Vector2{4,9}};


    void Draw(){
        for (unsigned int i=0; i < body.size(); i++){
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x*cell_size, y*cell_size, float(cell_size), float(cell_size)};
            DrawRectangleRounded(segment, 0.5, 6, dark_Green);
        }
    };

};

class Food{

    public:
    Vector2 position;
    Texture2D texture;

    Food(){
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = RandomPosition();
    }
    ~Food(){
        UnloadTexture(texture);
    }

    void Draw(){
        DrawTexture(texture, position.x * cell_size, position.y * cell_size, WHITE);

    }

    Vector2 RandomPosition(){
        float x = GetRandomValue(0, cellCount-1);
        float y = GetRandomValue(0, cellCount -1);
        return Vector2{x,y};
    }
};


int main(){

    cout<<"Starting Game....\n";
    InitWindow(cell_size * cellCount,  cell_size * cellCount, "Retro snake");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();

    while(WindowShouldClose() == false){
        BeginDrawing();


        
//drawing
        ClearBackground(Green);

        food.Draw();
        snake.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}