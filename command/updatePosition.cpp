
namespace updatePosition {
    void peek(BedrockCommand& command) {
        string accountID = command.request["accountID"];
        if (accountID.empty()) {
            STHROW("401 Invalid request");
        }

        list<string> coordinates;
        SINFO("command.request[\"coordinates\"]: " << command.request["coordinates"]);
        coordinates = SParseJSONArray(command.request["coordinates"]);
        if (coordinates.empty()) {
            STHROW("401 Invalid JSON");
        } else if (coordinates.size() != 2) {
            STHROW("402 Invalid coordinate list");
        } else {
            string x = coordinates.front();
            coordinates.pop_front();
            SINFO("coordinates now x=" << x);
            string y = coordinates.front();
            coordinates.pop_front();
            SINFO("coordinates now x=" << x << " y=" << y );
        };
    };
};

