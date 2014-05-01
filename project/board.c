/**
 * Triplets Game - VIOPE 2014
 * @file: board.c
 *
 * @creation	2014-03-30
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>

/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "data_structs.h"

/*=====================================
 * Public declarations
 *===================================*/

/*=====================================
 * Public functions
 *===================================*/

/**
 * Getter function for the board size
 *
 * @return	Current board size
 * @date	2014-03-31
 * @author	Triplet VIOPE 2014
 */
int board_get_size(void){
	return get_current_game_ptr()->board_rows;
}

/**
 * Function to set the board size
 *
 * @v board_size value to use for board size
 * @return	0 if the specified board size is invalid, otherwise it returns
 * 		the board size
 * @date	2014-03-31
 * @author	Triplet VIOPE 2014
 */
int board_set_size(const int board_size)
{
	if( ! board_is_valid_size(board_size) ){
		fprintf(stderr, "[Err] Invalid board size:%d\n", board_size);
		return 0;
	}

	/* Setting the board size */
	get_current_game_ptr()->board_rows = board_size;

	/* Clear board */
	board_set_empty();

	return board_size;
}

/**
 * Function that the **whole** board as empty (the whole matrix)
 *
 * @return None
 * @date 2014-03-31
 * @author		Triplet VIOPE 2014
 */
void board_set_empty(void){
	int i,j;
	int board_size = MAX_BOARDSIZE;

	for(i=0;i<board_size;i++){
		for(j=0;j<board_size;j++){
			get_current_game_ptr()->board[i][j] = EMPTY;
		}
	}
}


/**
 * Validate the board_size parameter checking whether board_size is
 * valid (i.e., is BOARD_SMALL, BOARD_MEDIUM or BOARD_LARGE) or not valid.
 *
 * @v	board_size	board size to validate
 * @return		1 if board size is valid
 * @date		2014-03-31
 * @author		Triplet VIOPE 2014
 */
int board_is_valid_size(const int board_size)
{
	if( board_size == BOARD_SMALL
	 || board_size == BOARD_MEDIUM
	 || board_size == BOARD_LARGE ){
	 	return 1;
	}

	/* Still here? Not valid... */
	return 0;
}

/**
 * Print the current board to stdout in a raw manner
 * (nofancy characters to draw the boarders)
 */
void board_print_raw(void){
	int i,j;

	int board_size = board_get_size();
	printf("[INFO] Board: %d x %d\n", board_size,board_size);
	printf("--[BOARD]--\n");

	for(i=0;i<board_size;i++){
        printf("|");
		for(j=0;j<board_size;j++){
			printf("%c", get_current_game_ptr()->board[i][j]);
		}
		printf("|\n");
	}
	printf("-----------\n");
}


/**
 * Converts the row obteined in the equivalent index
 * Of the row in the matrix
 *
 * @v	board_size	Converts the row in the index
 * @return		The index of the row
 * @date		2014-04-14
 * @author		Triplet VIOPE 2014 (PT TEAM)
 */
int board_row_to_matrix_idx(int row){
    row -= 1;
    return row;
}

/**
 * Converts the column obteined in the equivalent index
 * Of the column in the matrix (int)
 *
 * @v	board_size	Converts the column in the index
 * @return		The index of the column (int)
 * @date		2014-04-14
 * @author		Triplet VIOPE 2014 (PT TEAM)
 */
int board_col_to_matrix_idx(char col){
    int col_int;
    switch(col){
    case 'A':
        col_int = 0;
        break;
    case 'B':
        col_int = 1;
        break;
    case 'C':
        col_int = 2;
        break;
    case 'D':
        col_int = 3;
        break;
    case 'E':
        col_int = 4;
        break;
    case 'F':
        col_int = 5;
        break;
    case 'G':
        col_int = 6;
        break;
    case 'H':
        col_int = 7;
        break;
    case 'I':
        col_int = 8;
        break;
    case 'J':
        col_int = 9;
        break;
    case 'K':
        col_int = 10;
        break;
    case 'L':
        col_int = 11;
        break;
    default:
        col_int = -1;
        printf("Invalid column!");
    }

    return col_int;
}


/**
 * Gets the content of the board in a specific row and column
 * The content is a char
 *
 * @v	board_size	"piece_on" is the char in that position
 * @return		The char in that position
 * @date		2014-04-14
 * @author		Triplet VIOPE 2014 (PT TEAM)
 */
char board_get_content_row_col(int row, char col){

    char piece_on;
    //matrix -> get_current_game->board[i][j];
    position_t pos;
    pos.X = board_row_to_matrix_idx(row);

    pos.Y_int = board_col_to_matrix_idx(col);
    piece_on = get_current_game_ptr()->board[pos.X][pos.Y_int]; //get_current_game_ptr()->board[i][j]

    return piece_on;
}


/**
 * Sets the content of the board in a specific row and column
 * The content is a define, which is the piece
 *
 * @v	board_size	PIECE is the define of '#'
 * @return		void
 * @date		2014-04-14
 * @author		Triplet VIOPE 2014 (PT TEAM)
 */
void board_set_content_row_col(int row, char col){

    position_t pos;
    pos.X = board_row_to_matrix_idx(row);
    pos.Y_int = board_col_to_matrix_idx(col);
    get_current_game_ptr()->board[pos.X][pos.Y_int] = PIECE;

}

/*=====================================
 * Private functions
 *===================================*/
