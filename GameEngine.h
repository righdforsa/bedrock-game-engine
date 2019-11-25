#include <Bedrock/libstuff/libstuff.h>
#include <Bedrock/BedrockPlugin.h>
#include <command/CommandList.h>

static map<string, string> _gameState;

class BedrockPlugin_GameEngine : public BedrockPlugin {

  public:
    BedrockPlugin_GameEngine(BedrockServer& s);

    virtual string getName() { return "GameEngine"; }
    virtual bool peekCommand(SQLite& db, BedrockCommand& command);
    virtual void initialize(const SData& args, BedrockServer& server);

  private:
};
