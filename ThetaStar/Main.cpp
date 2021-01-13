#include <GLFW/glfw3.h>
#include "Program.h"
#include <chrono>



int main(void)
{
    GLFWwindow* window;
 
    srand((unsigned)time(0));
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    Program* LProgram = nullptr;
    LProgram = new Program{};
    
       /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(LProgram->getWidth(), LProgram->getHeight(), "MultiAgent path finding", NULL, NULL);
    if (!window)
    {
        
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(0);

   

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glOrtho(0, LProgram->getWidth() , LProgram->getHeight(), 0.0f, 0.0f, 1000.0f);
    /* Loop until the user closes the window */

    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    float maxTime{ 0.1f };
    while (!glfwWindowShouldClose(window))
    {

        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();

        // Calculate elapsed time
        float elapsedSeconds = std::chrono::duration<float>(t2 - t1).count();

        // Update current time
        t1 = t2;

        // Prevent jumps in time caused by break points
        elapsedSeconds = std::min(elapsedSeconds, maxTime);

        glClear(GL_COLOR_BUFFER_BIT );
       
        LProgram->Draw();

        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
        LProgram->Update(elapsedSeconds);
    }

    glfwTerminate();
    return 0;
}





