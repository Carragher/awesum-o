# Known Bugs #

  * Leaderboard not displaying individual scores accurately
    * Only displays the initial score of each player
  * For server and client window, if user does not click disconnect and only clicks the 'X' button to close the window, neither server nor client sockets are disconnected resulting in errors when opening up server or client again
  * Increase of difficulty is hard-coded but not implementing
  * Save does not save score
  * Load is not loading correctly

# How To Play #

  * Click Initialize
  * Click Start Level > Enemies will begin spawning
  * Click Add Tower > click on clickable tiles to create a tower
  * Creating a new tower decrements score by 125 (choose placement wisely)
  * Death of an enemy results in player gaining 25 points
  * Player has 20 lives, lives are lost for every enemy that reaches the end of the map
  * Game ends when all 20 lives are lost> Game Over screen displays > infinite amounts of enemies begin spawning and populating the whole screen.

# Features #

  * Player can save game state by clicking "Save"
  * Player can load previously saved game state by clicking "Load" (Can only load LAST save)
  * Chat functionality
    * User creates a Chat Server by clicking "Create Server"
    * User and other users click "Connect Server" then enter IP address of host, input username, and password (12345) to connect to the server
    * Users can all send messages to each other
  * Leaderboard displayed on Chat Server window and Chat Server clients
    * Leaderboard displays scores of each player (supposed to, see bug above)

# Hours worked #

  * Johnny: 20 hours
  * Daniel:
  * Jon: