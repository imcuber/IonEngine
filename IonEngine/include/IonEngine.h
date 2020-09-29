#ifndef IONENGINE_IONENGINE_H
#define IONENGINE_IONENGINE_H

#include <IonEngine/Core.h>
#include <IonEngine/Application.h>
#include <IonEngine/Utility.h>
#include <IonEngine/Events.h>
#include <IonEngine/Input.h>
#include <IonEngine/Window.h>
#include <IonEngine/LayerStack.h>
#include <IonEngine/ImGuiLayer.h>
#include <IonEngine/Grapics.h>
#include <IonEngine/Platform.h>

// Entry Point
extern std::unique_ptr<IonEngine::Application> getApplication(int argc, char* argv[]);
int main(int argc, char* argv[]);

#endif // IONENGINE_IONENGINE_H
