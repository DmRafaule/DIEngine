#include "engine.hpp"

using namespace DI;

int main(){

    Engine* engine = CreateApp();
    engine->Run();
    delete engine;

    return 0;
}