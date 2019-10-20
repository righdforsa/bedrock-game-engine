# bedrock-game-engine
Self-exercise in hacking on Expensify's Bedrock DB server

Little weird in that it's a plugin which is importing the primary app as a submodule. So, there's some setup that needed to happen.

need to add some packages, see the bedrockdb.com

Past objectives:
create a makefile
get code to compile
get plugin to load

Current objective:
update position (store across repeat requests)

Future objectives:
multiple users
require authentication
add collision detection
add momentum
add projectiles
add 3 dimensions
performance test against 10 users
performance test against 100 users
performance test against 1000 users

command to start the prog:
```
/vagrant/bedrock-game-engine/Bedrock/bedrock         -live         -fork         -maxJournalSize 1000000         -pidFile /var/run/bedrock         -quorumCheckpoint 100         -plugins db,/vagrant/bedrock-game-engine/gameengine         -peerList          -db /tmp/gameengine.db         -serverHost localhost:4000         -nodeName localhost         -nodeHost localhost:8889         -priority 500          
```
