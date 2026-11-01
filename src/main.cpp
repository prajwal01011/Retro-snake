#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;
Color Green = { 173, 204, 96, 255};
Color dark_Green = { 43, 51, 24, 255};

int cell_size = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double Interval){
    double CurrentTime = GetTime();
    if (CurrentTime - lastUpdateTime >= Interval){
        lastUpdateTime = CurrentTime;
        return true;
    }
    return false;
}

class Snake{
    
    
    public:
    deque<Vector2> body = {Vector2{6,9},Vector2{5,9}, Vector2{4,9}};
    Vector2 direction = {1, 0};



    void Draw(){
        for (unsigned int i=0; i < body.size(); i++){
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x*cell_size, y*cell_size, float(cell_size), float(cell_size)};
            DrawRectangleRounded(segment, 0.5, 6, dark_Green);
        }
    }
    
    void update(){
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));

    }

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

class Game{


    public:

    Snake snake = Snake();
    Food food = Food();


    void Draw(){
        food.Draw();
        snake.Draw();
    }

    void update(){

        snake.update();
    }




};


int main(){

    cout<<"Starting Game....\n";
    InitWindow(cell_size * cellCount,  cell_size * cellCount, "Retro snake");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false){
        BeginDrawing();
         if (eventTriggered(0.2)){
            game.update();
         }       
        
        
         if(IsKeyPressed(KEY_UP ) && game.snake.direction.y != 1){
            game.snake.direction = {0, -1};
            
         }
         if(IsKeyPressed(KEY_DOWN ) && game.snake.direction.y != -1){
            game.snake.direction = {0, 1};
         }
         if(IsKeyPressed(KEY_LEFT ) && game.snake.direction.x != 1){
            game.snake.direction = {-1, 0};
         }
         if(IsKeyPressed(KEY_RIGHT)  && game.snake.direction.x != -1){
            game.snake.direction = {1, 0};
         }


        
//drawing
        ClearBackground(Green);

        game.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}