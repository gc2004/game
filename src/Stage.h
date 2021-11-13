#pragma once

#include <raylib.h>

#include <iostream>
#include <string>
#include <unordered_map>

#include "Scene.h"

class Stage {
    std::string_view title;

    Director director;
    Scene* active_scene = nullptr;
    std::unordered_map<std::string, Scene*> scenes;

public:
    Stage(const char* title) : title(title) {
        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
        InitWindow(640, 480, title);
    }

    ~Stage() {
        for (auto s : scenes) {
            delete s.second;
        }

        scenes.clear();

        CloseWindow();
    }

    std::string_view& getTitle() { return this->title; }

    void setTitle(const char* title) {
        this->title = title;
        SetWindowTitle(title);
    }

    template <typename T>
    void addScene(const char* title) {
        this->scenes[title] = new T(&this->director);
    }

    Scene* getScene(const char* title) { return this->scenes[title]; }

    void transition(const char* title) {
        if (active_scene != nullptr) {
            active_scene->onExit();
        }

        active_scene = this->scenes[title];

        if (active_scene != nullptr) {
            active_scene->onEnter();
        }
    }

    void present() {
        while (!WindowShouldClose()) {
            if (active_scene != nullptr) {
                float deltaTime = GetFrameTime();

                active_scene->onUpdate(deltaTime);

                ClearBackground(BLACK);
                BeginDrawing();

                active_scene->onRender(deltaTime);

                EndDrawing();

                // events
                for (auto cue : this->director.getCues()) {
                    switch (cue->type) {
                        case CueType::ChangeScene:
                            this->transition(
                                ((Cues::ChangeScene*)cue)->title.data());
                            break;
                        default:
                            active_scene->onCue(cue);
                            break;
                    }
                }
            } else {
                break;
            }
        }

        if (active_scene != nullptr) {
            active_scene->onExit();
            active_scene = nullptr;
        }
    }
};