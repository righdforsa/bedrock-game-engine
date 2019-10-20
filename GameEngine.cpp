#include <GameEngine.h>

#undef SLOGPREFIX
#define SLOGPREFIX "{" << getName() << "} "

extern "C" void BEDROCK_PLUGIN_REGISTER_GAMEENGINE()
{
    new BedrockPlugin_GameEngine();
}

bool BedrockPlugin_GameEngine::peekCommand(SQLite& db, BedrockCommand& command) {
    SData& request = command.request;
    const string& requestVerb = request.getVerb();
    SINFO("got request: " << requestVerb);

    // TODO replace with a map of names->functions, or something
    if (SIEquals(requestVerb,"updatePosition")) {
        SINFO("yay, we did it");
        updatePosition::peek(command);
    } else {
        STHROW("404 no such command ");
    }
    return true;
}
