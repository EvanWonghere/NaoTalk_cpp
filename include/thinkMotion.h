#ifndef THINKMOTION_H
#define THINKMOTION_H

#include <alproxies/almotionproxy.h>
#include <alproxies/alledsproxy.h>
#include <alvalue/alvalue.h>

void addParams(std::vector<std::string>& names, AL::ALValue& times, AL::ALValue& keys);

void thinking(const std::vector<std::string>& names, const AL::ALValue& times, const AL::ALValue& keys, AL::ALMotionProxy * motion, AL::ALLedsProxy * leds);

#endif