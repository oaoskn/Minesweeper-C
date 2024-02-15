//
//  setup_ui.c
//  Minesweeper
//
//  Created by Kirill Gusev on 15.02.2024.
//

#include "setup_ui.h"

// MARK: - Функция создания окна

void create_window(GLFWwindow* window) {
    
    glfwInit();
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(800, 600, "Minesweeper", NULL, NULL);
    
    if (window == NULL) {
        printf("Fatal error with creating window!\n");
        glfwTerminate();
        exit(-1);
    }
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
}
