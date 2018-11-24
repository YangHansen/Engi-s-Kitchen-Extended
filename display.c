#include <curses.h>
#include "display.h"

/* Kelompok Tampilan */
/* Kamus Tampilan*/
    /* Pointer display */
    WINDOW *name_disp, *money_disp, *life_disp, *time_disp, *waitcust_disp, *order_disp, *map_disp, *food_disp, *hand_disp, *command_disp;

    /* Ukuran display */
    int disp_height, disp_width;
    int name_height, name_width, money_height, money_width, life_height, life_width, time_height, time_width;
    int waitcust_height, waitcust_width, order_height, order_width, map_height, map_width, food_height, food_width, hand_height, hand_width;
    int command_height, command_width;

    /* Cursor */
    int start_y, start_x;
    int player_y, player_x;

    char user_input[10];

void initLayout(){
    /* CURSES START */
    initscr();
    // cbreak();
    // raw();
    // noecho();
    setLayout();
    refresh();
    printLayout();
    updateLayout();
}

void setLayout(){
    /* Set Ukuran Display */
        name_height = 3;
        name_width = 25;
        money_height = name_height;
        money_width = 25;
        life_height = name_height;
        life_width = 25;
        time_height = name_height;
        time_width = 25;
        waitcust_height = 8;
        waitcust_width = name_width;
        order_height = 8;
        order_width = name_width;
        map_height = waitcust_height + order_height;
        map_width = 50;
        food_height = waitcust_height;
        food_width = 25;
        hand_height = order_height;
        hand_width = food_width;
        command_height = 3;
        command_width = order_width + map_width + hand_width;

        disp_height = 10;
        disp_width = 40;

        start_y = 0;
        start_x = 0;
}

void printLayout(){
    /* Print Layout */
        start_y = 0;
        start_x = 0;

        name_disp = newwin(name_height, name_width, start_y, start_x);
        box(name_disp,0,0);
        wrefresh(name_disp);

        start_x += name_width;
        money_disp = newwin(money_height, money_width, start_y, start_x);
        box(money_disp,0,0);
        wrefresh(money_disp);

        start_x += money_width;
        life_disp = newwin(life_height, life_width, start_y, start_x);
        box(life_disp,0,0);
        wrefresh(life_disp);

        start_x += life_width;
        time_disp = newwin(time_height, time_width, start_y, start_x);
        box(time_disp,0,0);
        wrefresh(time_disp);

        start_x = 0;
        start_y += name_height;
        waitcust_disp = newwin(waitcust_height, waitcust_width, start_y, start_x);
        box(waitcust_disp,0,0);
        wrefresh(waitcust_disp);

        start_x += waitcust_width;
        map_disp = newwin(map_height, map_width, start_y, start_x);
        box(map_disp,0,0);
        wrefresh(map_disp);

        start_x += map_width;
        food_disp = newwin(food_height, food_width, start_y, start_x);
        box(food_disp,0,0);
        wrefresh(food_disp);

        start_x = 0;
        start_y += waitcust_height;
        order_disp = newwin(order_height, order_width, start_y, start_x);
        box(order_disp,0,0);
        wrefresh(order_disp);

        start_x += order_width + map_width;
        hand_disp = newwin(hand_height, hand_width, start_y, start_x);
        box(hand_disp,0,0);
        wrefresh(hand_disp);

        start_x = 0;
        start_y += order_height;
        command_disp = newwin(command_height, command_width, start_y, start_x);
        box(command_disp,0,0);
        wrefresh(command_disp);
}

void CurseTulisMatriks (Matriks M, int y, int x)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS LOKAL */
    matriksIndeks i, j;

    /* ALGORITMA */
    wmove(map_disp, y,x);
    // printw("Haha");
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){

        for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
            wprintw(map_disp, "%c ", ElmtMat(M,i,j));
        }

        if(i==GetLastIdxBrs(M)){
            wprintw(map_disp, "%c", ElmtMat(M,i,GetLastIdxKol(M)));
        }
        else{
            wprintw(map_disp, "%c", ElmtMat(M,i,GetLastIdxKol(M)));
        }
        y++;
        wmove(map_disp, y,x);
    }
}

// void CursePrintStack(Stack S, WINDOW *disp) {
//     int x,y;
//     char Z;
//     x = 1;
//     y = 1;

//     while (!IsEmptyStck(S)) {
//         wmove(*disp, y, x);
//         wprintw(*disp, "%s", InfoTop(S));
//         y++;
//         Pop(&S, &Z);
//     }
// }

void updateLayout(){
    /* Print data */
        wmove(name_disp, 1, 1);
        wprintw(name_disp, "<Name>");
        wrefresh(name_disp);

        wmove(money_disp, 1, 1);
        wprintw(money_disp, "Money: %ld", Money(GameData));
        wrefresh(money_disp);

        wmove(life_disp, 1, 1);
        wprintw(life_disp, "Life: %ld", Life(GameData));
        wrefresh(life_disp);

        wmove(time_disp, 1, 1);
        wprintw(time_disp, "Waktu: %ld", Waktu(GameData));
        wrefresh(time_disp);

        wmove(waitcust_disp, 1, 1);
        wprintw(waitcust_disp, "Waiting Customer");
        wrefresh(waitcust_disp);

        wmove(map_disp, 1, 1);
        // wprintw(map_disp, "");
        CurseTulisMatriks(Room[1].Map,1,1);
        wrefresh(map_disp);

        wmove(food_disp, 1, 1);
        wprintw(food_disp, "Food Stack");
        wrefresh(food_disp);

        wmove(order_disp, 1, 1);
        wprintw(order_disp, "Order");
        wrefresh(order_disp);

        wmove(hand_disp, 1, 1);
        wprintw(hand_disp, "Hand");
        wrefresh(hand_disp);

        start_x = 0;
        start_y = name_height + waitcust_height + order_height;
        // delwin(command_disp);
        command_disp = newwin(command_height, command_width, start_y, start_x);
        box(command_disp,0,0);

        mvprintw(25,0,"Type EXIT to stop");
        refresh();

        wmove(command_disp, 1, 1);
        wprintw(command_disp, "Command: ");
        wrefresh(command_disp);
}

void GetCommand(){
    CursorCommand();
    CurseBacaCommand();
    
    if (!EqualKata(Command,"EXIT")){
        updateLayout();
        GetCommand();
    }
    else
        endLayout();
}

void CursorCommand(){
    // wmove(command_disp, 1, 10); // memindah cursor ke posisi (10,1) relatif terhadap command_disp
    move(20, 10);
    wrefresh(command_disp);
}

void endLayout(){
    endwin();
    /* Terminate curses */
}