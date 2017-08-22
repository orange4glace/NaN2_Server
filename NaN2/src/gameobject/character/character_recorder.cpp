// character_recorder.cpp
#include "gameobject/character/character_recorder.h"

namespace nan2 {

  CharacterRecorder::CharacterRecorder(GameObject* go) : 
  Recorder<CharacterRecord>(go) {
  }

  CharacterRecord CharacterRecorder::GetInterpolatedData(int time) {
    return {};
  }

}