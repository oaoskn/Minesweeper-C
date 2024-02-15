//
//  setup_ui.h
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#ifndef setup_ui_h
#define setup_ui_h

#include <stdio.h>
#include <stdlib.h>
#define GLFW_INCLUDE_NONE
#import <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#import <GLFW/glfw3native.h>

// MARK: - Создание интерфейса

void create_window(GLFWwindow*);

#endif /* setup_ui_h */
