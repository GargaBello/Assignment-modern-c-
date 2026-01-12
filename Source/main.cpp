#include "raylib.h"
#include "app.h"

int main(void)
{    
    //TODO: 
    // remove all comments
    // window should probably take arguments. 
    // window should be an RAII type, meaning it should be able to throw, meaning, it will crash us if we're not inside a try/catch. (recommendation: move it into game. make it  a member)
    //while (!WindowShouldClose())    //TODO: consider moving the core loop inside game, that should also own the window

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