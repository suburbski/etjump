#ifndef SESSION_HPP
#define SESSION_HPP

#include <string>
#include <bitset>
#include "../g_local.hpp"
#include "levels.hpp"
#include "database.hpp"


class Session
{
public:
    static const unsigned MAX_COMMANDS = 256;
    Session();
    void ResetClient(int clientNum);

    struct Client
    {
        Client();
        std::string guid;
        std::string hwid;
        std::bitset<MAX_COMMANDS> permissions;
        std::string ip;
        const Database::User_s *user;
        const Levels::Level *level;
    };

    void Init(int clientNum);
    void ReadSessionData(int clientNum);
    void WriteSessionData(int clientNum);
    void GetUserAndLevelData(int clientNum);
    bool GuidReceived(gentity_t *ent);
    void PrintGuid(gentity_t* ent);
    void PrintSessionData();
    void PrintGreeting(gentity_t* ent);
    void OnClientDisconnect(int clientNum);
    std::string Guid(gentity_t *ent) const;
    std::bitset<256> Permissions(gentity_t *ent) const;
    int GetLevel(gentity_t *ent) const;
    bool SetLevel(gentity_t* target, int level);
    bool SetLevel(unsigned id, int level);
    int GetLevelById(unsigned id) const;
    bool UserExists(unsigned id);
    std::string GetMessage() const;
    void PrintAdmintest(gentity_t* ent);
    void PrintFinger(gentity_t* ent, gentity_t* target);
    bool Ban(gentity_t *ent, gentity_t *player, unsigned expires, std::string reason);
    bool IsIpBanned(int clientNum);
    void ParsePermissions(int clientNum);
private:
    

    void UpdateLastSeen(int clientNum);
    Client clients_[MAX_CLIENTS];
    std::string message_;


    
};

#endif