#include "raylib.h"
#include "app.h"
#include <print>

int main(void)
{    
    try {
        App app;
        app.Run();
    }
    catch (const std::runtime_error& e) {
        std::print("Runtime error: {}\n", e.what());
    }
    catch (...) {
        std::print("Unkown error occurred\n");
    }
    return 0;
}