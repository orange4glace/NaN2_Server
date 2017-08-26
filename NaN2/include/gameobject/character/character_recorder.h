// character_recorder.h
#ifndef CHARACTER_RECORDER_H_
#define CHARACTER_RECORDER_H_

#include "../../components/recorder.h"
#include "character_record.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class Character;

  class CharacterRecorder : public Recorder<CharacterRecord> {

    Character* character_;

  protected:
    void applyRecord(const CharacterRecord& record) override;
    const CharacterRecord saveCurrentRecord() const override;

  public:
    CharacterRecorder(Character* character);

  };

}

#endif