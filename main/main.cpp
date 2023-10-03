/*

    Code By Sun Hwang(DigiPen ID : sun.hwang)
    GAM100
    Weekly Homework Assignment #3


*/


#include <iostream>
#include <raylib.h>
#include "library.h"


constexpr int window_width{ 800 };
constexpr int window_height{ 400 };
constexpr int target_frame_rate{ 60 };
constexpr int donut_speed{ 2 };
constexpr int player_speed{ 5 };

int score = 0;
int donut_x[10] = { 0, };
int donut_y[10] = { 0, };
int player_x = window_width / 2;

int main() {
    srand(time(NULL));
    InitWindow(window_width, window_height, " NAME HERE");
    SetTargetFPS(target_frame_rate);


    for (int i = 0; i < 10; i++) {
        donut_x[i] = rand() % window_width;
    }

    while (WindowShouldClose() == false) {
        BeginDrawing();
        update();
        EndDrawing();  
    }

    CloseWindow();
    return 0;
}

void CreatDonut() {
    for (int i = 0; i < 10; i++) {
        if (donut_y[i] >= window_height) {
            donut_x[i] = rand() % window_width;
            donut_y[i] = 0;
        }
    }
}

void PlayerMove() {
    if (IsKeyDown(KEY_LEFT)) {
        player_x -= player_speed;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player_x += player_speed;
    }
}


void update() {
    for (int i = 0; i < 10; i++) {
        donut_y[i] += donut_speed;
    }

    PlayerMove();

    for (int i = 0; i < 10; i++) {
        Vector2 dount_point{ donut_x[i], donut_y[i]};
        Rectangle player{ player_x, 25, 50, 50 }; 
        if ((CheckCollisionCircleRec(dount_point, 20, player))) {
            donut_y[i] = window_height+100;
            score++;
        }
    }

    CreatDonut();
    DrawObject();
    
}

void DrawObject() {
    for (int i = 0; i < 10; i++) {
        draw_food(donut_x[i], donut_y[i]);
    }
    draw_player(player_x);
}