/**
  * RealBot : Artificial Intelligence
  * Version : Work In Progress
  * Author  : Stefan Hendriks
  * Url     : http://realbot.bots-united.com
  **
  * DISCLAIMER
  *
  * History, Information & Credits: 
  * RealBot is based partially upon the HPB-Bot Template #3 by Botman
  * Thanks to Ditlew (NNBot), Pierre Marie Baty (RACCBOT), Tub (RB AI PR1/2/3)
  * Greg Slocum & Shivan (RB V1.0), Botman (HPB-Bot) and Aspirin (JOEBOT). And
  * everybody else who helped me with this project.
  * Storage of Visibility Table using BITS by Cheesemonster.
  *
  * Some portions of code are from other bots, special thanks (and credits) go
  * to (in no specific order):
  *
  * Pierre Marie Baty
  * Count-Floyd
  *  
  * !! BOTS-UNITED FOREVER !!
  *  
  * This project is open-source, it is protected under the GPL license;
  * By using this source-code you agree that you will ALWAYS release the
  * source-code with your project.
  *
  **/

#ifndef BOT_FUNC_H
#define BOT_FUNC_H

//prototypes of bot functions...
void BotThink(cBot * pBot);

float fixAngle(float angle);

void botFixIdealPitch(edict_t * pEdict);
void botFixIdealYaw(edict_t * pEdict);
bool traceLine(const Vector& v_source, const Vector& v_dest, const edict_t* pEdict, TraceResult& tr);
bool BotCanJumpUp(const cBot * pBot);
bool BotCanDuckUnder(const cBot * pBot);

bool isBotNearby(const cBot* pBot, float radius);
void adjustBotAngle(const cBot* pBot, float angle);
void avoidClustering(const cBot* pBot);
bool isPathBlocked(const cBot* pBot, const Vector& v_dest);
void adjustPathIfBlocked(const cBot* pBot);
bool performTrace(const Vector& v_source, const Vector& v_dest, edict_t* pEntity, TraceResult& tr);
bool isPathClear(const cBot* pBot, const Vector& v_dest);
void BotNavigate(const cBot* pBot);

bool EntityIsVisible(edict_t * pEntity, const Vector& dest);

// bot_func.cpp
bool VectorIsVisible(const Vector& start, const Vector& dest, char *checkname);
float func_distance(Vector v1, Vector v2);

void DrawBeam(edict_t * visibleForWho, const Vector& start, const Vector& end);
void DrawBeam(edict_t * visibleForWho, const Vector& start, const Vector& end, int red, int green, int blue);
void DrawBeam(edict_t * visibleForWho, const Vector& start, const Vector& end,
              int width, int noise, int red, int green, int blue,
              int brightness, int speed);

cBot *getCloseFellowBot(cBot * pBot);
edict_t * getPlayerNearbyBotInFOV(cBot * pBot);
edict_t * getEntityNearbyBotInFOV(cBot * pBot);

bool isAnyPlayerNearbyBot(cBot* pBot);
bool BotShouldJump(cBot * pBot);
bool BotShouldJumpIfStuck(cBot * pBot);
bool BotShouldDuck(cBot * pBot);
bool BotShouldDuckJump(cBot* pBot);
void TryToGetHostageTargetToFollowMe(cBot * pBot);
Vector FUNC_CalculateAngles(const cBot * pBot);

// New funcs
bool FUNC_DoRadio(const cBot * pBot);

bool FUNC_ShouldTakeCover(cBot * pBot);
bool FUNC_TakeCover(cBot * pBot);

int FUNC_EdictHoldsWeapon(const edict_t * pEdict);

int FUNC_FindFarWaypoint(cBot * pBot, const Vector& avoid, bool safest);
int FUNC_FindCover(const cBot* pBot);
int FUNC_PlayerSpeed(const edict_t * edict);

bool FUNC_PlayerRuns(int speed);
void FUNC_HearingTodo(cBot * pBot);
void FUNC_ClearEnemyPointer(edict_t *pPtr); //pPtr muddled with c_pointer? [APG]RoboCop[CL]

bool FUNC_IsOnLadder(const edict_t * pEntity);
void FUNC_FindBreakable(cBot* pBot);
void FUNC_CheckForBombPlanted(edict_t* pEntity);

int FUNC_GiveHostage(cBot * pBot);                      // gives any hostage we still have to go for

bool isHostageRescueable(cBot *pBot, edict_t *pHostage);
bool isHostageRescued(cBot *pBot, const edict_t *pHostage);
bool isHostageFree(cBot * pBotWhoIsAsking, edict_t * pHostage);   // is this hostage not used by any other bot?

int FUNC_BotEstimateHearVector(cBot * pBot, const Vector& v_sound);

bool FUNC_EdictIsAlive(edict_t *pEdict);

bool FUNC_BotHoldsZoomWeapon(cBot * pBot);

int FUNC_InFieldOfView(edict_t * pEntity, const Vector& dest);

bool VectorIsVisibleWithEdict(edict_t * pEdict, const Vector& dest,
                              const char *checkname);

bool BOT_DecideTakeCover(cBot * pBot);

// bot_buycode.cpp
int PriceWeapon(int weapon_id);
int ListIdWeapon(int weapon_id);

void BotPrepareConsoleCommandsToBuyWeapon(cBot* pBot, const char* arg1, const char* arg2);

bool GoodWeaponForTeam(int weapon, int team);

void BotConsole(cBot * pBot);
void BotDecideWhatToBuy(cBot* pBot);
void rblog(const char* txt);

// bot.cpp

// util.cpp
int UTIL_GiveWeaponId(const char *name);
int UTIL_GiveWeaponType(int weapon_id);
int UTIL_GetGrenadeType(edict_t * pEntity);

bool UTIL_IsVip(edict_t * pEntity);

const char* UTIL_GiveWeaponName(int id);

void UTIL_SpeechSynth(edict_t * pEdict, char *szMessage);
void UTIL_BotRadioMessage(cBot * pBot, int radio, const char *arg1, const char *arg2);
void UTIL_BotPressKey(cBot * pBot, int type);
// bot_navigate.cpp

// ..
void CenterMessage(char *buffer);

#endif                          // BOT_FUNC_H
