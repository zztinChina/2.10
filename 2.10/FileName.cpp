#include <stdio.h>  
#include<stdlib.h>
#define BOARD_SIZE 10  

// 定义棋子类型  
enum PieceType {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

// 定义棋盘  
enum PieceType board[BOARD_SIZE][BOARD_SIZE];

// 初始化棋盘  
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // 设置初始棋子位置  
    board[1][0] = board[6][0] = PAWN;
    board[1][7] = board[6][7] = PAWN;
    board[0][4] = KING;
    board[0][3] = QUEEN;
    board[0][5] = BISHOP;
    board[0][6] = KNIGHT;
    board[0][7] = ROOK;
    board[7][4] = KING;
    board[7][3] = QUEEN;
    board[7][5] = BISHOP;
    board[7][6] = KNIGHT;
    board[7][7] = ROOK;
}

// 打印棋盘  
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
            case EMPTY:
                printf(".");
                break;
            case PAWN:
                printf("P");
                break;
            case KNIGHT:
                printf("N");
                break;
            case BISHOP:
                printf("B");
                break;
            case ROOK:
                printf("R");
                break;
            case QUEEN:
                printf("Q");
                break;
            case KING:
                printf("K");
                break;
            }
            if (j < BOARD_SIZE - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// 检查移动是否合法  
int isMoveValid(int fromX, int fromY, int toX, int toY) {
    // 这里仅做简单的示例，没有实现完整的移动规则  
    // 实际中需要根据象棋规则来判断移动是否合法  
    return (fromX == toX || fromY == toY) && abs(fromX - toX) == abs(fromY - toY);
}

int main() {
    initBoard();

    int fromX, fromY, toX, toY;

    while (1) {
        printBoard();

        printf("Enter move (fromX fromY toX toY): ");
        scanf_s("%d %d %d %d", &fromX, &fromY, &toX, &toY);

        if (isMoveValid(fromX, fromY, toX, toY)) {
            board[toX][toY] = board[fromX][fromY];
            board[fromX][fromY] = EMPTY;
        }
        else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}