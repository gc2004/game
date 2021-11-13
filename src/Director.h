#pragma once

#include <vector>

#include "Cue.h"

class Director {
    std::vector<Cue*> cues;

public:
    void addCue(Cue* cue) { this->cues.push_back(cue); }

    unsigned cueCount() { return this->cues.size(); }

    std::vector<Cue*> getCues() { return this->cues; }
};