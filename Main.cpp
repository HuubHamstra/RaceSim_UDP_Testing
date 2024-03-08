// Libraries
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Constants
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Test"
#define BACKGROUND_COLOR 0.88f, 0.64f, 0.32f, 1.00f

// Prototype methods
GLFWwindow* initializeWindow();
void renderWindow(GLFWwindow* window);

// Main thread
int main()
{
    // Initialize GLFW
    glfwInit();

    // Set configurations for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialize a window
    GLFWwindow* window = initializeWindow();
    if (window == NULL)
    {
        // No window was created, return -1
        return -1;
    }

    // Apply window to GLFW and hook to GL
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Loop until window closes
    while (!glfwWindowShouldClose(window))
    {
        // Handle poll events
        glfwPollEvents();

        // Render the window
        renderWindow(window);
    }

    // Clear GLFW window and terminate
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

// Initializes the GLFW Window according to constants
GLFWwindow* initializeWindow()
{
    // Initialize GLFW Window with constants
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);

    // Check if window creation was unsuccessful
    if (window == NULL)
    {
        // Log the error and terminate GLFW
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    // Return the created window if it was successful
    return window;
}

// Renders the given window according to constants
void renderWindow(GLFWwindow* window)
{
    // Fill the background
    glClearColor(BACKGROUND_COLOR);

    // Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the buffer for the given window
    glfwSwapBuffers(window);
}