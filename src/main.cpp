#include <iostream>
#include <raylib.h>

using namespace std;
Color Green = { 173, 204, 96, 255};
Color dark_Green = { 43, 51, 24, 255};

int main(){

    InitWindow(1200, 800, "Retro snake");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();


        
//drawing
        ClearBackground(Green);



        EndDrawing();
    }

    CloseWindow();

    return 0;
}