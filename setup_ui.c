//
//  setup_ui.c
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#include "setup_ui.h"

extern mine_cell map[map_width][map_height];

void show_mines_count(int a) {
    glLineWidth(3);
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    // работает по принципу семисегментного индикатора
    if ((a != 1) && (a != 4)) {
        glVertex2f(0.3, 0.85);
        glVertex2f(0.7, 0.85);
    }
    if ((a != 0) && (a != 1) && (a != 7)) {
        glVertex2f(0.3, 0.5);
        glVertex2f(0.7, 0.5);
    }
    if ((a != 1) && (a != 4) && (a != 7)) {
        glVertex2f(0.3, 0.15);
        glVertex2f(0.7, 0.15);
    }
    
    if ((a != 5) && (a != 6)) {
        glVertex2f(0.7, 0.5);
        glVertex2f(0.7, 0.85);
    }
    if (a != 2) {
        glVertex2f(0.7, 0.5);
        glVertex2f(0.7, 0.15);
    }
    
    if ((a != 1) && (a != 2) && (a != 3) && (a != 7)) {
        glVertex2f(0.3, 0.5);
        glVertex2f(0.3, 0.85);
    }
    if ((a == 0) || (a == 2) || (a == 6) || (a == 8)) {
        glVertex2f(0.3, 0.5);
        glVertex2f(0.3, 0.15);
    }
    glEnd();
}

// func to draw a mine, its a mock now
void draw_mine(void) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.7, 0.3);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.3, 0.7);
    glEnd();
}

// Set a game field
void draw_gamefield(void) {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(0, 1);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(1, 1);
    glVertex2f(0, 0);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(1, 0);
    glEnd();
}

void draw_open_gamefield(void) {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.3, 0.7, 0.3);
    glVertex2f(0, 1);
    glColor3f(0.3, 0.6, 0.3);
    glVertex2f(1, 1);
    glVertex2f(0, 0);
    glColor3f(0.3, 0.5, 0.3);
    glVertex2f(1, 0);
    glEnd();
}

void show_game(void) {
    glLoadIdentity();
    glScalef(2.0 / map_width, 2.0 / map_height, 1); // scale of cell
    glTranslatef(-map_width * 0.5, -map_height * 0.5, 0); // set to bottom left anchor
    
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            glPushMatrix();
            glTranslated(i, j, 0);
            
            if (map[i][j].open == true) {
                draw_open_gamefield();
                if (map[i][j].mine == true) {
                    draw_mine();
                } else if (map[i][j].count_near_mines > 0) {
                    show_mines_count(map[i][j].count_near_mines);
                }
            } else {
                draw_gamefield();
            }
            
            glPopMatrix();
        }
    }
}

// MARK: - Scene

void display(void) {
    glClearColor(0.07f, 0.13f, 0.17f, 0.0f); // set background colora
    glClear(GL_COLOR_BUFFER_BIT); //clear that color
    show_game();
    glFlush();
}
    
// func to resize
void reshape(int width, int height) {

}

void menu(int value) {
    switch (value) {
        case 1:
            printf("Start button tapped\n");
            glColor3f(1.0, 1.0, 1.0);
            break;
        case 2:
            printf("Continue button tapped\n");
            glColor3f(0.0, 1.0, 0.0);
            break;
        case 3:
            printf("Records button tapped\n");
            glColor3f(0.0, 0.0, 1.0);
            break;
        case 4:
            printf("Exit button tapped\n");
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// MARK: - Create menu

void create_menu(void) {
    glutCreateMenu(menu);
    glutAddMenuEntry("New Game", 1);
    glutAddMenuEntry("Continue Game", 2);
    glutAddMenuEntry("Records", 3);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// MARK: - Функция создания окна

void create_window(void) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(325, 150);
    glutCreateWindow("MINESWEEPER GAME");
   
    create_menu();
    new_game();
    
    glutDisplayFunc(display);
    
    glutMainLoop();
}
