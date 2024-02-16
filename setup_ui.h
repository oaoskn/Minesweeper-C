//
//  setup_ui.h
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#ifndef setup_ui_h
#define setup_ui_h


// Standart libraries for C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Libraries for interface
#define GL_SILENCE_DEPRECATION
#include <OPENGL/gl.h>
#include <OPENGL/glu.h>
#include <GLUT/glut.h>

// MARK: - Создание интерфейса

void draw_mine(void);
void draw_gamefield(void);
void display(void);
void reshape(int, int);
void menu(int);
void create_window(void);

#endif /* setup_ui_h */
