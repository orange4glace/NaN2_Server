// game_object.cpp
#include "gameobject/game_object.h"

#include "logger/logger.h"

namespace nan2 {

  GameObject::GameObject(GameObjectType type, bool updatable, bool rewindable, bool is_network_object) : 
  type_(type),
  staging_state_(StagingState::NONE),
  internal_id_(-1),
  network_id_(0),
  updatable_(updatable),
  rewindable_(rewindable),
  is_network_object_(is_network_object) {
  }

  GameObjectType GameObject::type() const {
    return type_;
  }

  void GameObject::InitializeComponents() {
    for (auto component : components_) {
      component->Awake();
    }
  }

  void GameObject::addComponent(Component* component) {
    components_.push_back(component);
  }

  Component* GameObject::getComponent(ComponentType type) {
    for (auto component : components_) {
      if (component->type() == type)
        return component;
    }
    return nullptr;
  }

  void GameObject::Rewind(int time) {
    recorder_->Rewind(time);
  }

  void GameObject::Restore() {
    recorder_->Restore();
  }

  void GameObject::RecordCurrent() {
    recorder_->SaveCurrentRecord();
  }

  bool GameObject::updatable() {
    return updatable_;
  }

  bool GameObject::rewindable() {
    return rewindable_;
  }

  StagingState GameObject::staging_state() const {
    return staging_state_;
  }

  int GameObject::internal_id() const {
    return internal_id_;
  }

  int GameObject::network_id() const {
    return network_id_;
  }

  bool GameObject::is_network_object() const {
    return is_network_object_;
  }

  void GameObject::AssignID(int internal_id, int network_id) {
    internal_id_ = internal_id;
    network_id_ = network_id;
  }

  void GameObject::set_staging_state(StagingState state) {
    staging_state_ = state;
  }

}

/*

    GameObject(GameObjectType type, bool updatable, bool rewindable, bool is_network_object);

    void AddComponent(Component* component);
    Component* GetComponent(ComponentType type);

    virtual void FixedUpdate() {};
    virtual void Update() {};
    bool updatable();

    virtual void Rewind(int time) {};
    bool rewindable();

    int internal_id();
    unsigned short network_id();
    bool is_network_object();
    void AssignID(int internal_id, unsigned short network_id);

    GameObjectType type() const;

    */