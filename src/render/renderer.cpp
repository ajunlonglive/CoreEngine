#include "renderer.h"

Renderer::Renderer(): m_running(true) {
    m_window = std::make_unique<Window>();
}

void Renderer::run() {
    while (!glfwWindowShouldClose(m_window->get_window())) {
        m_window->update();
    }
}
