/*

    Code By Seung Oh Hong(DigiPen ID : seungoh.hong), Sun Hwang(DigiPen ID : sun.hwang)
    GAM100
    Weekly Homework Assignment #3


*/

/*

instructions

This game is controlled using the left and right arrow keys.
Try donuts falling from the sky!

*/


#include <iostream>
#include <raylib.h>
#include "library.h"


constexpr int window_width{ 800 };
constexpr int window_height{ 400 };
constexpr int target_frame_rate{ 60 };
constexpr int player_speed{ 5 };
constexpr int donut_num{ 5 };
constexpr int player_y{ 350 };
constexpr int player_size{ 50 };

char score_text[] = "score : ";
int score = 0;
int player_x = window_width / 2;
struct Donut {
    int x[donut_num] = { 0, };
    int y[donut_num] = { 0, };
    int speed[donut_num] = { 0, };
};

struct Donut donut;

void ResetDonut() {
    for (int i = 0; i < donut_num; i++) {
        donut.x[i] = rand() % window_width;
        donut.y[i] = 0;
        donut.speed[i] = (rand() % 4) + 1;
    }
}

void CreatDonut() {
    for (int i = 0; i < donut_num; i++) {
        if (donut.y[i] >= window_height) {
            donut.x[i] = rand() % window_width;
            donut.y[i] = 0;
            donut.speed[i] = (rand() % 4) + 1;
        }
    }
}

void PlayerMove() {
    if (IsKeyDown(KEY_LEFT)) {
        player_x -= player_speed;
        if (player_x < 0) {
            player_x = 0;
        }
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player_x += player_speed;
        if (player_x > window_width - player_size) {
            player_x = window_width - player_size;
        }
    }
        
}

void DrawObject() {
    for (int i = 0; i < donut_num; i++) {
        draw_food(donut.x[i], donut.y[i]);
    }

    draw_player(player_x);
    DrawText(TextFormat("Score: %03i", score), 0, 0, 50, PINK);
}

void update() {
    for (int i = 0; i < donut_num; i++) {
        donut.y[i] += donut.speed[i];
    }

    PlayerMove();

    for (int i = 0; i < donut_num; i++) {
        Vector2 dount_point{ donut.x[i], donut.y[i] };
        Rectangle player{ player_x, player_y, player_size, player_size };
        if ((CheckCollisionCircleRec(dount_point, 20, player))) {
            donut.y[i] = window_height + 100;
            score++;
        }
    }

    CreatDonut();
    DrawObject();

}



int main() {
    srand(time(NULL));
    InitWindow(window_width, window_height, "EAT DOUNT!");
    SetTargetFPS(target_frame_rate);


    ResetDonut();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);
        update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

