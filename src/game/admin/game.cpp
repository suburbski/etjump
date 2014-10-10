#include "game.hpp"
#include "session.hpp"
#include "commands.hpp"
#include "../g_save.hpp"
#include "levels.hpp"
#include "database.hpp"
#include "../mapdata.h"
#include "../races.hpp"
#include "../custommapvotes.hpp"

Game::Game()
{
    levels = boost::shared_ptr<Levels>(new Levels());
    session = boost::shared_ptr<Session>(new Session());
    commands = boost::shared_ptr<Commands>(new Commands());
    saves = boost::shared_ptr<SaveSystem>(new SaveSystem(session.get()));
    database = boost::shared_ptr<Database>(new Database());
    mapData = boost::shared_ptr<MapData>(new MapData());
    races = boost::shared_ptr<Races>(new Races());
    customMapVotes = boost::shared_ptr<CustomMapVotes>(new CustomMapVotes());
}