#pragma once

#include <vector>

#include "Actor.h"
#include "Director.h"

class Scene {
    Director* director;
    std::vector<Actor*> actors;

public:
    Scene(Director* director) : director(director) {}
    ~Scene() {}

    virtual void onEnter() {}

    virtual void onExit() {
        for (auto actor : this->actors) delete actor;

        this->actors.clear();
    }

    virtual void onUpdate(float deltaTime) {
        for (auto actor : this->actors) {
            actor->onUpdate(deltaTime);
        }
    }

    virtual void onRender(float deltaTime) {
        for (auto actor : this->actors) {
            actor->onRender(deltaTime);
        }
    }

    virtual void onCue(Cue* cue) {}

protected:
    template <typename T>
    void addActor() {
        this->actors.push_back(new T(this->director));
    }

    Director* getDirector() { return this->director; }
};