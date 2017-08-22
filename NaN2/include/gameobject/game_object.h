// game_object.h
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "game_object_type.h"
#include "../components/component.h"

#include <vector>

namespace nan2 {

  class GameObject {

  private:
    GameObjectType type_;

    int internal_id_;
    int network_id_;

    bool is_network_object_;
    bool updatable_;
    bool rewindable_;
    std::vector<Component*> components_;

  protected:

  public:
    GameObject(GameObjectType type, bool updatable, bool rewindable, bool is_network_object);

    void AddComponent(Component* component);
    Component* GetComponent(ComponentType type);

    void InitializeComponents();

    virtual void FixedUpdate() {};
    virtual void Update() {};
    bool updatable();

    virtual void Rewind(int time) {};
    bool rewindable();

    int internal_id();
    int network_id();
    bool is_network_object();
    void AssignID(int internal_id, int network_id);

    GameObjectType type() const;
  };

}

#endif