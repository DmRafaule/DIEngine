#include <iostream>

#include "engine.hpp"

#include "DIEditor/editor.hpp"
#include "DIWindow/win.hpp"
#include "DIGUI/interfacer.hpp"
#include "DIRenderer/renderer.hpp"
#include "DIEvents/event.hpp"
#include "DIThreads/thread.hpp"
#include "DITime/time.hpp"
#include "DIDebuger/debuger.hpp"
#include "DIDebuger/log.hpp"

namespace DI {

extern WinData* eg_winData;

Engine::Engine(){
   std::cout << "Init Engine." << std::endl; 
   LogHandler::Init();
   TimeHandler::Init();
   DebugHandler::Init();
   ThreadHandler::Init();
   WinHandler::Init();
   ViewportHandler::Init();
   EventHandler::Init();
   RendererSingleton::Init();
   InterfacerSingleton::Init();
   Editor::Init(); 
}
Engine::~Engine(){
   std::cout << "Kill Engine." << std::endl; 
   ThreadHandler::JoinCall(ThreadData::JoinPoint::END_APP);
   Editor::Kill();
   InterfacerSingleton::Kill();
   RendererSingleton::Kill();
   EventHandler::Kill();
   ViewportHandler::Kill();
   WinHandler::Kill();
   ThreadHandler::Kill();
   TimeHandler::Kill();
   DebugHandler::Kill();
   LogHandler::Kill();
}
void Engine::Run(){
   TimeHandler::Start("SessionTime");
   while(eg_winData->isOpen){
     TimeHandler::Start("CoreTime");
     WinHandler::Update();
     EventHandler::Update();
     TimeHandler::Stop("CoreTime");
   }
   TimeHandler::Stop("SessionTime");
}

}