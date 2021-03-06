//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once

#include <string>
#include <unordered_map>

#include "OrbitType.h"
#include "SerializationMacros.h"

class CaptureSerializer {
 public:
  CaptureSerializer();
  void Save(const std::string& filename);
  void Load(const std::string& filename);

  template <class T>
  void Save(T& archive);

  class TimeGraph* time_graph_;
  class SamplingProfiler* m_SamplingProfiler;

  std::string m_CaptureName;
  int m_Version;
  int m_TimerVersion;
  int m_NumTimers;
  int m_SizeOfTimer;

  ORBIT_SERIALIZABLE;
};
