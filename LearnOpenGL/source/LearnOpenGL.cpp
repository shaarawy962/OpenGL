// LearnOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Application
{
private:
    unsigned int Width, Height;
    std::string Title;
    bool bAppIsRunning;
    GLFWwindow* m_Window;

protected:

    void SwapBuffers();
    void PollEvents();
    void Update();
	void Render();
	void Init();

public:

    Application();
    ~Application();

    void Run();

};

void Application::SwapBuffers()
{
    glfwSwapBuffers(m_Window);
}

void Application::PollEvents()
{
    glfwPollEvents();
}

void Application::Update()
{
    //Poll Input events
    PollEvents();

    //Render here
    Render();

    /*Swap Buffers*/
    SwapBuffers();
}

void Application::Render()
{
	glClearColor(0.2f, 0.4f, 0.4f, 0.4f);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, Width, Height);
}

Application::Application()
{
    Width = 800u;
    Height = 600u;
    Title = "Main Application";

    Init();
}

Application::~Application()
{

}

void Application::Run()
{
    while (bAppIsRunning)
    {
        Update();
    }
}

void Application::Init()
{
    bool bglfwInit = false;
    if (glfwInit())
    {
        bglfwInit = true;
    }
    if (bglfwInit)
    {
        m_Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, this);

    int gladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


}

int main()
{
    std::cout << "Hello World!\n";

    std::unique_ptr<Application> app = std::unique_ptr<Application>(new Application());
    app->Run();
}
