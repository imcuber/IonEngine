#include <IonEngine.h>

#include <glad/glad.h>
#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

void GLDebugOutputCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    switch(severity) {
    case GL_DEBUG_SEVERITY_HIGH:
    {
        ION_CORE_LOG_ERROR("[OpenGL Debug HIGH] {}", message);
        break;
    }
    case GL_DEBUG_SEVERITY_MEDIUM:
    {
        ION_CORE_LOG_WARN("[OpenGL Debug MEDIUM] {}", message);
        break;
    }
    case GL_DEBUG_SEVERITY_LOW:
    {
        ION_CORE_LOG_INFO("[OpenGL Debug LOW] {}", message);
        break;
    }
    case GL_DEBUG_SEVERITY_NOTIFICATION:
    {
        //ION_CORE_LOG_TRACE("[OpenGL Debug NOTIFY] {}", message);
        break;
    }
    }
}

void enableGLDebugOutput()
{
    glDebugMessageCallback(GLDebugOutputCallback, nullptr);
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}

namespace IonEngine::Platform {

    OpenGLContext::OpenGLContext(IonEngine::Window& window):
        Context{ window },
        m_handle{ (GLFWwindow*)m_window.getNativeHandler() },
        m_info{}
    {
        glfwMakeContextCurrent(m_handle);
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            ION_CORE_ASSERT(false, "Couldn't load glad");
        }

        glGetIntegerv(GL_MAJOR_VERSION, &m_info.major);
        glGetIntegerv(GL_MINOR_VERSION, &m_info.minor);
        m_info.vendor = (char*)glGetString(GL_VENDOR);
        m_info.renderer = (char*)glGetString(GL_RENDERER);
        m_info.glslVersion = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

        ION_CORE_LOG_INFO("Initialized OpenGL context:");
        ION_CORE_LOG_INFO("\tVendor: {}", m_info.vendor);
        ION_CORE_LOG_INFO("\tRenderer: {}", m_info.renderer);
        ION_CORE_LOG_INFO("\tVersion: {}.{}", m_info.major, m_info.minor);
        ION_CORE_LOG_INFO("\tGLSL: {}", m_info.glslVersion);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        
        struct {
            union {
                float x = 0.0f;
                float value;
            };
            float y = 0.0f;
        } scale;

        glfwGetWindowContentScale(m_handle, &scale.x, &scale.y);
        ION_CORE_ASSERT(scale.x == scale.y, "Non-uniform window content scale");

        ImGui::GetStyle().ScaleAllSizes(scale.value);
        io.FontGlobalScale = scale.value;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(m_handle, true);
        ImGui_ImplOpenGL3_Init("#version 330 core");

        enableGLDebugOutput();
    }

    void OpenGLContext::swapBuffers() 
    {
        glfwSwapBuffers(m_handle);
    }

}
