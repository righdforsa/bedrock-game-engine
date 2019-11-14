
namespace updatePosition {
    //void peek(map<string, string> _gameState, BedrockCommand& command) {
    void peek(map<string, string>* _gameState, BedrockCommand& command) {
        string accountID = command.request["accountID"];
        if (accountID.empty()) {
            STHROW("401 Invalid request");
        }

        list<string> coordinates;
        coordinates = SParseJSONArray(command.request["coordinates"]);
        if (coordinates.empty()) {
            STHROW("401 Invalid JSON");
        } else if (coordinates.size() != 2) {
            SDEBUG("received invalid coordinates: command.request[\"coordinates\"]: " << command.request["coordinates"]);
            STHROW("402 Invalid coordinate list");
        } else {
            string index = accountID;
            SDEBUG("previous _gameState for " << index << ": " << (*_gameState)[index]);

            // Assign coordinates
            string x = coordinates.front();
            coordinates.pop_front();
            string y = coordinates.front();
            coordinates.pop_front();
            string coordinatesObj = "{" + x + "," + y + "}";
            (*_gameState)[index] = coordinatesObj;
            if (_gameState->empty()) {
                SDEBUG("_gameState is empty");
            } else {
                map<string, string>::iterator it;
                for ( it = _gameState->begin(); it != _gameState->end(); it++ )
                {
                    SDEBUG("_gameState: "
                              << it->first  // string (key)
                              << ':'
                              << it->second   // string's value 
                              );
                }
            }
            SINFO("_gameState for accountID: " << accountID << " coordinates now " << (*_gameState)[accountID]);
        };
    };
};

