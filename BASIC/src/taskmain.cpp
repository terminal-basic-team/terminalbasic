/*
 * Terminal-BASIC is a lightweight BASIC-like language interpreter
 * 
 * Copyright (C) 2016-2018 Andrey V. Skvortsov <starling13@mail.ru>
 * Copyright (C) 2019,2021 Terminal-BASIC team
 *     <https://github.com/terminal-basic-team>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <signal.h>
#include <time.h>

#include "basic_config.hpp"
#include "basic.hpp"
#include "basic_task.hpp"

static Task* activeTask;

void
setup()
{
	HAL_initialize();
	
	activeTask->init();
}

void
loop()
{
	HAL_update();
	activeTask->step();
}


static BOOLEAN exitflag = FALSE;

static void
sighandler(int signum)
{
	exitflag = TRUE;
}

int
main(int argc, char **argv)
{
	signal(SIGINT, &sighandler);
	srand(time(NULL));
	
	const char *filePath = argc > 1 ? argv[1] : nullptr;
	activeTask = new BASIC::Task(filePath);
	
	setup();
	while (!exitflag)
		loop();
        
	return EXIT_SUCCESS;
}
