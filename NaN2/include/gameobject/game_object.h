// game_object.h
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "game_object_type.h"
#include "staging_state.h"
#include "game_object_base.h"
#include "../components/recorder_interface.h"

#include <vector>

namespace nan2 {

  class GameObject : public GameObjectBase {

  private:
    GameObjectType type_;

    int internal_id_;
    uint16_t network_id_;

    StagingState staging_state_;

    bool is_network_object_;
    bool updatable_;
    bool rewindable_;

    std::vector<Component*> components_;
    RecorderInterface* recorder_;

    void addComponent(Component* component) override;
    Component* getComponent(ComponentType type) override;

  protected:

  public:
    GameObject(GameObjectType type, bool updatable, bool rewindable, bool is_network_object);

    virtual void OnStage() {}
    virtual void OnDestroy() {}

    void InitializeComponents();

    virtual void FixedUpdate() {};
    virtual void Update() {};
    bool updatable();

    void Rewind(int time);
    void Restore();
    void RecordCurrent();
    bool rewindable();

    StagingState staging_state() const;
    int internal_id() const;
    int network_id() const;
    bool is_network_object() const;
    void AssignID(int internal_id, int network_id);

    void set_staging_state(StagingState state);

    GameObjectType type() const;
  };

}

#endif