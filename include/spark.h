#ifndef SPARK_H
#define SPARK_H

#include <iostream>
#include <fstream>
#include <assert.h>
#include <cstring>
#include <atomic>
#include <unistd.h>
#include <vector>
#include <json/json.h>
#include <fstream>

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>
#include <althread/alcriticalsection.h>
#include <alproxies/almemoryproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <althread/almutex.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alledsproxy.h>

#include "aikit_spark_api.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "thinkMotion.h"

using namespace AIKIT;
using namespace AL;

std::string getUsrInput();

void sparksay(ALTextToSpeechProxy * tts);

void say(ALTextToSpeechProxy * tts, std::string text);

std::string listen(AL::ALProxy * asr);

void thinkmotion(ALMotionProxy * motion);

void initHistory();

void addUserContent(std::string userContent);

void addAssistantContent(std::string assistantContent);

std::string getInputText();

int sendRequest();

void initialRequest();

void chatOnToken(AIChat_Handle* handle, const int& completionTokens, const int& promptTokens, const int& totalTokens);

static void chatOnOutput(AIChat_Handle* handle, const char* role, const char* content, const int& index);

static void chatOnError(AIChat_Handle* handle, const int& err, const char* errDesc);

void initSDK();

void unInit();

void spark(ALTextToSpeechProxy& tts, ALProxy * asr, ALMotionProxy& motion, ALLedsProxy& leds);

#endif