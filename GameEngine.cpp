#include <GameEngine.h>

#undef SLOGPREFIX
#define SLOGPREFIX "{" << getName() << "} "

extern "C" void BEDROCK_PLUGIN_REGISTER_GAMEENGINE()
{
    new BedrockPlugin_GameEngine();
}

