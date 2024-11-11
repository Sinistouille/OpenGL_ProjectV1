//
// Created by Maxence on 03/09/2024.
//

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <wtypes.h>
#include <stdio.h>

void programme(void);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
    VkInstance* instance = NULL;
    if (!glfwInit()) {
        return -1;
    }
    programme();
    glfwTerminate();
    free(instance);
    return 0;
}

void programme() {
    // Récupération des dimensions de l'écran

    int user = 0;

    // Récupération du mode de l'écran
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //cout << "Refresh rate : " << mode->refreshRate << endl;
    //cout << "Bits par pixel : " << mode->redBits << " " << mode->greenBits << " " << mode->blueBits << endl;
    if(!mode) {
        printf("Erreur lors de la récupération des dimensions de l'écran");
        return;
    }

    //initializing hints
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_RED_BITS, 16);
    glfwWindowHint(GLFW_REFRESH_RATE, 40);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

    //creating the window
    GLFWwindow *window = glfwCreateWindow(10, 10, "My Title", NULL, NULL);
    //making window fullscreen
    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, 40);
    //checking if the window is created
    if (!window){
        printf("Erreur lors de la creation de la fenetre");
        return;
    }
    //debug
    //cout << "RefreshRate : " << glfwGetWindowAttrib(window,GLFW_REFRESH_RATE) << endl;
    //cout << "RedBits : " << glfwGetWindowAttrib(window,GLFW_RED_BITS) << endl;
    //cout << "GreenBits : " << glfwGetWindowAttrib(window,GLFW_GREEN_BITS) << endl;
    //adding window to the thread
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, &user);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Vérifie si la touche "Q" est pressée
    if ( scancode == 30 && action == GLFW_PRESS) {
        // Indique à GLFW de fermer la fenêtre
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (scancode == 16 && action == GLFW_PRESS) {
        //glfwRequestWindowAttention(window);
    }
}