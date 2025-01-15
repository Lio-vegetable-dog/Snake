#include"snake.h"
#include"game_setup.h"

int score = 0;
int kx = 0;
int ky = 0;

void playGame() {
    char key = 'd';
    while (snake.body[0].x >= 0 && snake.body[0].x < LENGTH &&
        snake.body[0].y >= 0 && snake.body[0].y < WIDE) {
        Sleep(100);  // �����ߵ��ƶ��ٶ�
        if (_kbhit()) {
            key = _getch();
        }
        switch (key) {
        case 'w': kx = 0; ky = -1; break;
        case 's': kx = 0; ky = +1; break;
        case 'd': kx = +1; ky = 0; break;
        case 'a': kx = -1; ky = 0; break;
        default: break;
        }

        // ����ɵ���βλ��
        int oldTailX = snake.body[snake.curSize - 1].x;
        int oldTailY = snake.body[snake.curSize - 1].y;

        for (size_t i = snake.curSize - 1; i > 0; i--) {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }

        snake.body[0].x += kx;
        snake.body[0].y += ky;

        // ����Ƿ�Ե�ʳ��
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            snake.curSize++;
            initFood();
            score += 10;
            // ����µ���βλ��
            snake.body[snake.curSize - 1].x = oldTailX;
            snake.body[snake.curSize - 1].y = oldTailY;
        }
        else {
            // �ÿո񸲸Ǿɵ���βλ��
            COORD oldTailCoord = { oldTailX, oldTailY };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), oldTailCoord);
            putchar(' ');
        }

        // �����µ���ͷ��ʳ��
        initUI();

        // ����Ƿ�ײ���Լ�
        for (size_t i = 1; i < snake.curSize; i++) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                return;
            }
        }

        // ����Ƿ�ײ���߽�
        if (snake.body[0].x < 0 || snake.body[0].x >= LENGTH || snake.body[0].y < 0 || snake.body[0].y >= WIDE) {
            return;
        }
    }
}


void gameOver() {
    system("cls");
    printf
       ("             ____   \n"
        "Game over!  / . .\\ \n"
        "            \\  ---<\n"
        "             \\  /  \n"
        "   __________/ /    \n"
        "-=:___________/\n");
    printf("\nYour scores:%d\n", score);
     
}