#include <Bedrock/libstuff/libstuff.h>
#include <Bedrock/BedrockPlugin.h>
#include <command/CommandList.h>

class BedrockPlugin_GameEngine : public BedrockPlugin {
  public:
    virtual string getName() { return "GameEngine"; }
    virtual bool peekCommand(SQLite& db, BedrockCommand& command);

  private:
};
