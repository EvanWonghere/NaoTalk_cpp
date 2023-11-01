#ifndef TACTILE_H
#define TACTILE_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <alcommon/alproxy.h>
#include <string>

#include <alproxies/almemoryproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <althread/almutex.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alledsproxy.h>
#include <alproxies/alaudiodeviceproxy.h>

namespace AL
{
  class ALBroker;
}

class Tactile : public AL::ALModule
{
  public:

    Tactile(boost::shared_ptr<AL::ALBroker> broker, const std::string & name);

    virtual ~Tactile();

    virtual void init();

    void onFrontTactilTouched();

    bool chat;

  private:
    AL::ALMemoryProxy memoryProxy;
    AL::ALTextToSpeechProxy ttsProxy;
    boost::shared_ptr<AL::ALMutex> callbackMutex;
    AL::ALProxy * asrProxy;
    AL::ALMotionProxy motionProxy;
    AL::ALLedsProxy ledsProxy;
    AL::ALAudioDeviceProxy audProxy;

    float fState;

};

#endif
