// Recorder.tcc

namespace nan2 {

  template <class T>
  Recorder<T>::Recorder(GameObject* game_object) :
  Component(game_object) {
  }

  template <class T>
  ComponentType Recorder<T>::type() const {
    return ComponentType::Recorder;
  }

}