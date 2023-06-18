#pragma once

namespace DI {

    class Engine{
    public:
        Engine();
        virtual ~Engine();
        void Run();
    };

}

DI::Engine* CreateApp();