#ifndef INIT_H
#define INIT_H

/**
* STD HEADERS
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
* DEFINES
*/
#define APP_NAME "Dijkstra Algorithm"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
* OPEN GL HEADERS
*/
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/**
* CUSTOM HEADERS
*/
#include "char_extension.h"
#include "dmatrix.h"
#include "parser.h"

#endif // INIT_H