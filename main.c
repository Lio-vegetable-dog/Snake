#include"snake.h"
#include"game_setup.h"

int main() {
    srand(time(NULL));
    gameStart();
    initWall();
    initSnake();
    initFood();
    playGame();
    Sleep(1000);
    gameOver();
    
    
}

//�������ж��û�����kbhit   ������getch





