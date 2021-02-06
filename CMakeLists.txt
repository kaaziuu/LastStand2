cmake_minimum_required(VERSION 3.17)
project(LastStand2)

set(CMAKE_CXX_STANDARD 20)

add_executable(LastStand2 main.cpp Game.cpp Game.h  Object/Item/Item.cpp Object/Item/Item.cpp Object/Item/Item.h Object/Tile/Tile.cpp Object/Tile/Tile.h Object/GameObject.cpp Object/GameObject.h Object/Person.cpp Object/Person.h Object/Player/Player.cpp Object/Player/Player.h Object/Item/PlayerItem/Gun.cpp Object/Item/PlayerItem/Gun.h Object/Item/PlayerItem/Bullet.cpp Object/Item/PlayerItem/Bullet.h Object/Sound/Sound.cpp Object/Sound/Sound.h Stucture/List.h Object/Map/Map.cpp Object/Map/Map.h Object/Physics.cpp Object/Physics.h Object/Enemy/Enemy.cpp Object/Enemy/Enemy.h Stucture/Queue.h Object/Enemy/Spawner.cpp Object/Enemy/Spawner.h Object/Menu/Menu.cpp Object/Menu/Menu.h Object/Enemy/Dijkstra.cpp Object/Enemy/Dijkstra.h)
target_link_libraries(LastStand2 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
