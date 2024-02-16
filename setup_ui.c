//
//  setup_ui.c
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#include "setup_ui.h"

// func to draw a mine, its a mock now
void draw_mine(void) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.3, 0.3);
    glEnd();
}

// Set a game field
void draw_gamefield(void) {
    
}

// MARK: - Scene

void display(void) {
    glClearColor(0.07f, 0.13f, 0.17f, 0.0f); // set background color
    glClear(GL_COLOR_BUFFER_BIT); //clear that color
    
//    float x,y;
//    float ctn = 10;
//    float l = 0.5;
//    float a = M_PI * 2 / ctn;
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(1, 0, 1);
//    glVertex2f(0, 0);
//    for (int i = -1; i < ctn; i++) {
//        x = sin(a * i) * l;
//        y = cos(a * i) * l;
//        glVertex2f(x, y);
//    }
    
//    draw_mine();
//    glEnd();
    
}

// func to resize
void reshape(int width, int height) {

}

void menu(int value) {
    switch (value) {
        case 1:
            glColor3f(1.0, 0.0, 0.0);
            break;
        case 2:
            glColor3f(0.0, 1.0, 0.0);
            break;
        case 3:
            glColor3f(0.0, 0.0, 1.0);
            break;
        case 4:
            exit(0);
            break;
    }
    glutPostRedisplay();
}


// MARK: - Функция создания окна

void create_window(void) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(325, 150);
    glutCreateWindow("MINESWEEPER GAME");
    
    int sub1 = glutCreateMenu(menu);
    
    glutAddMenuEntry("Test", 1);
    glutAddMenuEntry("Test", 2);
    glutAddMenuEntry("Test", 3);
    glutCreateMenu(menu);
    glutAddSubMenu("Start", 1);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutDisplayFunc(display);
    glutMainLoop();
}
