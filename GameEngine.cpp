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
        updatePosition::peek(&_gameState, command);
        map<string, string>::iterator it;
        for ( it = _gameState.begin(); it != _gameState.end(); it++ )
        {
            SDEBUG( "_gameState: "
                      << it->first  // string (key)
                      << ':'
                      << it->second   // string's value 
                      );
        }
    } else {
        STHROW("404 no such command ");
    }
    return true;
}

void BedrockPlugin_GameEngine::initialize(const SData& args, BedrockServer& server) {
}

