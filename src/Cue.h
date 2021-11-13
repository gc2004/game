#pragma once

#include <string>

enum class CueType { ChangeScene };

struct Cue {
    CueType type;

    Cue(CueType type) : type(type) {}
};

namespace Cues {

struct ChangeScene : Cue {
    std::string_view title;

    ChangeScene(const char* title) : title(title), Cue(CueType::ChangeScene) {}
};

}  // namespace Cues