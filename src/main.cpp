#include <iostream>
#include <raylib.h>

using namespace std;
Color Green = { 173, 204, 96, 255};
Color dark_Green = { 43, 51, 24, 255};

int cell_size = 30;
int cellCount = 25;

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

    while(WindowShouldClose() == false){
        BeginDrawing();


        
//drawing
        ClearBackground(Green);

        food.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}