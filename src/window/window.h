#pragma once

#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW\glfw3.h>

class Window {
private:
    int m_window_width;
    int m_window_height;
    std::string m_title;
    GLFWwindow* m_window;
public:
    ~Window();
    Window(int window_width = 600, int window_height = 600, std::string title = "Core");
    void init();
    void close();
    bool check();
    void update();
    void process_input();
    inline int get_window_height() const { return m_window_height; }
    inline int get_window_width() const { return m_window_width; }
    GLFWwindow* get_window() const { return m_window; }
    inline void set_framebuffersize_callback(GLFWframebuffersizefun callback) { glfwSetFramebufferSizeCallback(m_window, callback); }
};

