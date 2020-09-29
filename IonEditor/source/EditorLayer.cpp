#include "EditorLayer.h"
#include <imgui.h>
#include <examples/imgui_impl_opengl3.h>
#include <examples/imgui_impl_glfw.h>

EditorLayer::EditorLayer()
{
	std::string vertexSource = R"glsl(
		#version 330 core
		layout (location = 0) in vec3 in_Position;
		layout (location = 1) in vec4 in_Color;

        out VS_OUT
        {
            vec4 color;
        } vs_out;

		void main()
		{
            vs_out.color = in_Color;
			gl_Position = vec4(in_Position, 1.0);
		}
	)glsl";
	std::string fragmentSource = R"glsl(
		#version 330 core
		out vec4 out_Color;

        in VS_OUT
        {
            vec4 color;
        } fs_in;

		void main()
		{
			out_Color = fs_in.color;
		}
	)glsl";
    m_shader = IonEngine::Graphics::Shader::create(vertexSource, fragmentSource);

    auto layout = std::shared_ptr(IonEngine::BufferLayout::create({
        { IonEngine::BufferDataType::Float3, "in_Position" },
        { IonEngine::BufferDataType::Float4, "in_Color" }
        }));
    
    struct vertex
    {
        glm::vec3 position;
        glm::vec4 color;
    };

    vertex vertices[] = {
        { glm::vec3{ -0.5, -0.5, 0.0 }, glm::vec4{ 1.0, 0.0, 0.0, 1.0 } },
        { glm::vec3{  0.5, -0.5, 0.0 }, glm::vec4{ 0.0, 1.0, 0.0, 1.0 } },
        { glm::vec3{ -0.5,  0.5, 0.0 }, glm::vec4{ 0.0, 0.0, 1.0, 1.0 } },
        { glm::vec3{  0.5,  0.5, 0.0 }, glm::vec4{ 1.0, 1.0, 1.0, 1.0 } }
    };
    auto vbo = std::shared_ptr(IonEngine::VertexBuffer::create(vertices, sizeof(vertices), layout));

    std::vector<uint32_t> indices = {
        0, 1, 2,
        1, 3, 2
    };
    auto ibo = std::shared_ptr(IonEngine::IndexBuffer::create(indices));

    m_vao = IonEngine::VertexArray::create(vbo, ibo);
}

void EditorLayer::onAttach()
{}

void EditorLayer::onEvent(IonEngine::Event& e)
{
    if(e.isInCategory(IonEngine::EventCategory::Input)) {
        ION_LOG_INFO("{}", e);
    }
}

void EditorLayer::onUpdate()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void EditorLayer::onRender()
{
    m_shader->bind();
    m_vao->bind();
    glDrawElements(GL_TRIANGLES, m_vao->getIndices()->getCount(), GL_UNSIGNED_INT, nullptr);
}

void EditorLayer::onImGuiRender()
{
    ImGui::Begin("Vao handle");
    ImGui::Text(fmt::format("handle value {}", m_vao).c_str());
    static char buf[256] = {};
    ImGui::InputText("input", buf, 256);
    ImGui::End();
}
