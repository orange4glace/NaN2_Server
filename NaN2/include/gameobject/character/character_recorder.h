// character_recorder.h
#ifndef CHARACTER_RECORDER_H_
#define CHARACTER_RECORDER_H_

#include "../../components/recorder.h"
#include "character_record.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class CharacterRecorder : public Recorder<CharacterRecord> {

  public:
    CharacterRecorder(GameObject* go);

    CharacterRecord GetInterpolatedData(int time);

  };

}

#endif