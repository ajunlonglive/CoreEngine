#include "window.h"

Window::Window(int window_width, int window_height, const std::string title) :m_window_width(window_width), m_window_height(window_height) {
    init();   
}

Window::~Window() {
    close();
}

void Window::init() {
    //GLFW init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Create window
    m_window = glfwCreateWindow(m_window_width, m_window_height, m_title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
    //GLAD init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

void Window::close() {
    glfwTerminate();
    glfwDestroyWindow(m_window);
}

bool Window::check() {
    if (m_window == nullptr) {
        return false;
    }
    return true;
}

void Window::update() {
    //updata event
    process_input();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::process_input() {
    //process the input event
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window, true);
    }
}
