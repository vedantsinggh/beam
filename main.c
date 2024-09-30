#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define HEIGHT 80
#define WIDTH 600
#define MAX_LEN 20

int main(){
	InitWindow(WIDTH, HEIGHT, "BEAM");
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
	SetTargetFPS(60); 

    Rectangle textBox = { 10, 10 , WIDTH - 20, HEIGHT  - 20};

	int length = 1;
	char input[MAX_LEN] = ">";
    while (!WindowShouldClose())
    {
		if (IsKeyPressed(KEY_BACKSPACE)) {
            if (length > 0) {
                input[--length] = '\0';
            }
        }else if (IsKeyPressed(KEY_ENTER)) {
            if (length > 0) {
				char command[MAX_LEN];
				strncpy(command, input+1, length-1);
				command[length] = '\0';

				int res = system(command);

				memset(input, 0, sizeof(input[0]) * MAX_LEN);
				input[0] = '>';
				input[1] = '\0';
				length = 1;
            }
        }else {
            int key = GetCharPressed();
            if (key > 31 && key < 127 && length < 19) {  
                input[length++] = (char)key;
                input[length] = '\0';
            }
        }

		ClearBackground((Color){230, 230, 230, 50});
        BeginDrawing();
			DrawText(input, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
        EndDrawing();
    }

    CloseWindow();
	return 0;
}
