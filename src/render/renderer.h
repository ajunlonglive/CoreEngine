#pragma once

#include <memory>

#include "../window/window.h"

class Renderer {
private:
    std::unique_ptr<Window> m_window;
    bool m_running;
public:
    Renderer();
    void run();
};