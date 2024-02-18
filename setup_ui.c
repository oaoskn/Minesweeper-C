//
//  setup_ui.c
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#include "setup_ui.h"

extern const int map_width, map_height;
extern mine_cell map[MAP_WIDTH][MAP_HEIGHT];
extern int mines;

game_difficult difficult;

// MARK: - Func to show mines count

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

// MARK: - Draw a mine

void draw_mine(void) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.7, 0.3);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.3, 0.7);
    glEnd();
}

// MARK: - Draw a flag

void draw_flag(void) {
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.85, 0.5);
    glVertex2f(0.25, 0.25);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.25, 0);
    glEnd();
}

// MARK: - Draw a gamefield

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

// MARK: - Open a single cell

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

// MARK: - Get mouse click to open a cell

void touch_to_open_cell(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to cell coordinates (assuming each cell is 10x10 pixels)
        int cell_x = x / (float)glutGet(GLUT_WINDOW_WIDTH) * MAP_WIDTH;
        int cell_y = MAP_HEIGHT - y / (float)glutGet(GLUT_WINDOW_HEIGHT) * MAP_HEIGHT; // Invert y-coordinate because OpenGL origin is at bottom-left
        
        
        if (cell_in_map(cell_x, cell_y)) {
            map[cell_x][cell_y].open = true;
            printf("cell (%d, %d) is open ", cell_x, cell_y);
        }
        // Print out the cell coordinates
        printf("Clicked on cell (%d, %d)\n", cell_x, cell_y);
        
        glutPostRedisplay(); // request for refresh screen
    }
}

// MARK: - Open a cell

void opening_cells(void) {
    glutMouseFunc(touch_to_open_cell);
}

// MARK: - Show a game

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

// MARK: - Scene lifecycle

void display(void) {
    glClearColor(0.07f, 0.13f, 0.17f, 0.0f); // set background colora
    glClear(GL_COLOR_BUFFER_BIT); //clear that color
    show_game();
    glFlush();
    glutSwapBuffers();
}
    
// MARK: - Resize window

void reshape(int width, int height) {

}

// MARK: - Menu characterictics

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


// MARK: - Create a OpenGL window

void create_window(void) {
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    size_from_difficult game_size;
    difficult = HARD;
    
    switch (difficult) { // TODO: Need to create how to resize map size
        case EASY:
            game_size.width = 400;
            game_size.height = 300;
            // map_width = 10;
            // map_height = 10;
            mines = 10;
            break;
        case MEDIUM:
            game_size.width = 600;
            game_size.height = 400;
            mines = 20;
            break;
        case HARD:
            game_size.width = 800;
            game_size.height = 600;
            mines = 30;
            break;
        case HARDCORE:
            game_size.width = 1000;
            game_size.height = 800;
            mines = 100;
            break;
    }
   
    glutInitWindowSize(game_size.width, game_size.height); //TODO: change to game_size in future
    glutInitWindowPosition(325, 150);
    glutCreateWindow("MINESWEEPER GAME");
   
    create_menu();
    new_game();
    opening_cells();
    glutDisplayFunc(display);
    glutMainLoop();
}
