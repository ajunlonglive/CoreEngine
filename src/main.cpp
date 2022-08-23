#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../src/render/renderer.h"
#include "../src/window/window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // glfw: initialize and configure 
    Window window(SCR_WIDTH, SCR_HEIGHT, "Core");
    if (!window.check()) {
        std::cout << "window init failed!\n";
        return -1;
    }
    // set call back function
    window.set_framebuffersize_callback(framebuffer_size_callback);
    // render loop
    while (!glfwWindowShouldClose(window.get_window())) {
        window.update();
    }
    return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}