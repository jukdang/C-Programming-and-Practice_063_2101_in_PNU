#pragma once

#include "Block.h"
#include "Board.h"
#include "Score.h"
#include "Pause.h"
#include <iostream>

class Tetris
{
private:
	
	Block block;
	Block keep_block;
	Block next_block;

	Board board;

	Score score;

	Pause pause;

	bool running;
	bool is_keeped;
	bool can_use_keep;
	
	int speed;
	int line; //추가
	int level; //추가

	clock_t start_time;

public:

	Tetris() : board(&score, &line, &level), block(&board), next_block(&board), keep_block(&board), score(&speed, &line, &level), pause(&running) {
		running = true;
		is_keeped = false;
		can_use_keep = false;
		speed = 5;
		start_time = clock();
		line = 0; //추가
		level = 1; //추가
	};

	void run(int challenge);

	double time_difference();

	void process_key(char c);

	void print_screen();

	void keep(Block* now, Block* keep, Block* next);


};

