#pragma once

#include "Director.h"

class Actor {
    Director* director;

public:
    Actor(Director* director) : director(director) {}
    ~Actor() {}

    virtual void onUpdate(float deltaTime) {}
    virtual void onRender(float deltaTime) {}
    virtual void onCue(Cue* cue) {}

protected:
    Director* getDirector() { return this->director; }
};
