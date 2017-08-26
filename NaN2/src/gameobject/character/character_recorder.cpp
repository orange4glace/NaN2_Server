// character_recorder.cpp
#include "gameobject/character/character_recorder.h"

#include "gameobject/character/character.h"

namespace nan2 {

  CharacterRecorder::CharacterRecorder(Character* character) : 
  Recorder<CharacterRecord>(static_cast<GameObject*>(character)),
  character_(character) {
  }

  void CharacterRecorder::applyRecord(const CharacterRecord& record) {
    character_->ApplyRecord(record);
  }

  const CharacterRecord CharacterRecorder::saveCurrentRecord() const {
    return character_->GetRecord();
  }

}