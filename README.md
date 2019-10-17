# bedrock-game-engine
Self-exercise in hacking on Expensify's Bedrock DB server

Little weird in that it's a plugin which is importing the primary app as a submodule. So, there's some setup that needed to happen.

need to add some packages, see the bedrockdb.com

command to start the prog:
/vagrant/bedrock-game-engine/Bedrock/bedrock         -live         -fork         -maxJournalSize 1000000         -pidFile /var/run/bedrock         -quorumCheckpoint 100         -plugins db,/vagrant/bedrock-game-engine/gameengine         -peerList          -db /tmp/bedrock.db         -serverHost localhost:4000         -nodeName localhost         -nodeHost localhost:8889         -priority 500          
