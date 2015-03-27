/* Include headers*//*{{{*/
#include <iostream>

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include <fstream>
#include <vector>
#include "game.hpp"

int main(void)/*{{{*/
{
	Game game;
	game.init();
	game.run();
}/*}}}*/




// vim: ft=cpp foldmethod=marker:
