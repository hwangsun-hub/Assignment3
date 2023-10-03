
/*

	Code By Sun Hwang(DigiPen ID : sun.hwang)
	GAM100
	Weekly Homework Assignment #3


*/

#include <raylib.h>
#include "library.h"

constexpr Color bread_Color{ 197,150,94, 255 };

constexpr int donutSize{ 20 };
constexpr int glazePolynum{ 10 };
constexpr int glazeSize{ 18 };
constexpr int donutHolesize{ 10 };




void draw_food(int x, int y) {
	DrawCircle(x, y, donutSize, bread_Color); //bread
	DrawPoly({float(x), float(y)}, glazePolynum, glazeSize, 0, PINK);
	DrawCircle(x, y, donutHolesize, WHITE); //hole

	DrawCircleLines(x, y, donutSize, BLACK);
	DrawCircleLines(x, y, donutHolesize, BLACK);

}

void draw_player(int playerx) {
	DrawRectangle(playerx, 350, 50, 50, BLACK);

}