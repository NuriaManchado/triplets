#include <stdlib.h>
/**
* Triplets Game - VIOPE 2014
* @file main.c
*
* @creation date 2014-03-27
*
**/

/*=====================================
* System includes
*===================================*/
#include <stdio.h>

/*=====================================
* Local includes
*===================================*/
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
//#include "SP.h" //not compile!

/*=====================================
* main
*===================================*/
int main(void){
reset_data_structs();
system("cls");
welcome_screen();
show_menu();

int check=0;
if(G_current_game.game_mode==pvp){ //pvp mode

    if(G_current_game.player_first==1){  // who first start game,  first move
        cmp.current_player_move=G_players[0];
        cmp.previous_player_move=G_players[1];
    }
    else{
       cmp.current_player_move=G_players[1];
       cmp.previous_player_move=G_players[0];
    }

    while(1){   // in while add finish_game...
            system("cls");
            board_print_raw();
                do{
                        //
                    printf("%s your move! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
                    read_move(&pos);
                    check = function_validate_move(pos);
                    }while(check != 0);

            cmp.current_player_move.moves+=1;
            cmp.tmp=cmp.current_player_move;                   //swap current player
            cmp.current_player_move=cmp.previous_player_move;  //
            cmp.previous_player_move=cmp.tmp;                  //
    }//end while(1)
}// end pvp mode

if(G_current_game.game_mode==pvc){ //pvc mode

    if(G_current_game.player_first==1){  // who first start game,  first move
        cmp.current_player_move=G_players[0];
        cmp.previous_player_move=G_players[1];// G_players[1] is cpu player
    }
    else{
       cmp.current_player_move=G_players[1];
       cmp.previous_player_move=G_players[0];
    }
    while(1){
            system("cls");
            board_print_raw();
            do{
                printf("%s your move! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
                read_move(&pos);
                check = function_validate_move(pos);
                }while(check != 0);

            cmp.current_player_move.moves+=1;
            cmp.tmp=cmp.current_player_move;                   //swap current player
            cmp.current_player_move=cmp.previous_player_move;  //
            cmp.previous_player_move=cmp.tmp;                  //
    }//end while(1)
}// end pvc
return 0;
}
