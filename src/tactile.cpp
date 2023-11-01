#include "tactile.h"
#include "demo.h"
#include "spark.h"

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>
#include <althread/alcriticalsection.h>

Tactile::Tactile(
  boost::shared_ptr<AL::ALBroker> broker,
  const std::string & name) : AL::ALModule(broker, name),
        callbackMutex(AL::ALMutex::createALMutex())
        {
          setModuleDescription("Say something when front tactile sensor touched.");
          functionName("onFrontTactilTouched", getName(), "Method called when front tactile touched and use a callback method.");
          BIND_METHOD(Tactile::onFrontTactilTouched);
        }

Tactile::~Tactile()
{
  memoryProxy.unsubscribeToEvent("onFrontTactilTouched", "Tactile");
}

void Tactile::init()
{
  try
  {
    memoryProxy = AL::ALMemoryProxy(getParentBroker());
    motionProxy = AL::ALMotionProxy(getParentBroker());
    ledsProxy = AL::ALLedsProxy(getParentBroker());
    audProxy = AL::ALAudioDeviceProxy(getParentBroker());

    audProxy.setOutputVolume(100);

    fState = memoryProxy.getData("FrontTactilTouched");

    memoryProxy.subscribeToEvent("FrontTactilTouched", "Tactile", "onFrontTactilTouched");

    chat = false;

    asrProxy = new AL::ALProxy(getParentBroker(), "ALSoundProcessing");
  }
  catch(const AL::ALError& e)
  {
    qiLogError("module.example") << e.what() << '\n';
  }
}

void Tactile::onFrontTactilTouched()
{
  qiLogInfo("module.example") << "executing callback method on front tactile sensor touched event" << std::endl;

  AL::ALCriticalSection section(callbackMutex);

  fState = memoryProxy.getData("FrontTactilTouched");
  if (fState > 0.5f)
  {
    return;
  }

  try
  {
    ttsProxy = AL::ALTextToSpeechProxy(getParentBroker());
    ttsProxy.setLanguage("Chinese");

    printf("point 0\n");

    ttsProxy.setVolume(1.0);
    ttsProxy.setLanguage("Chinese");
    ttsProxy.say("请稍等。");
    spark(ttsProxy, asrProxy, motionProxy, ledsProxy);
  }
  catch (const AL::ALError & e)
  {
    qiLogError("module.example") << e.what() << std::endl;
  }
}
