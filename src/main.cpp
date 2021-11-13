#include "Stage.h"

class Player : public Actor {
    Rectangle pos;
    bool up, down, left, right;

    const float SPEED = 500.0;

public:
    Player(Director* _) : Actor(_) { pos = {0.0, 0.0, 50.0, 50.0}; }

    void onUpdate(float dt) override {
        up = IsKeyDown(KEY_UP);
        down = IsKeyDown(KEY_DOWN);
        left = IsKeyDown(KEY_LEFT);
        right = IsKeyDown(KEY_RIGHT);

        if (up) this->pos.y += -SPEED * dt;
        if (down) this->pos.y += SPEED * dt;
        if (left) this->pos.x += -SPEED * dt;
        if (right) this->pos.x += SPEED * dt;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Rectangle mouse = {static_cast<float>(GetMouseX()),
                               static_cast<float>(GetMouseY()), 0.0, 0.0};

            if (CheckCollisionRecs(this->pos, mouse)) {
                this->getDirector()->addCue(new Cues::ChangeScene(""));
            }
        }
    }

    void onRender(float dt) override {
        DrawRectanglePro(this->pos, (Vector2){0.0, 0.0}, 0.0F, RED);
    }
};

class Titlescreen : public Scene {
public:
    Titlescreen(Director* _) : Scene(_) {}

    void onEnter() override { this->addActor<Player>(); }

    void onExit() override { Scene::onExit(); }

    void onUpdate(float dt) override { Scene::onUpdate(dt); }

    void onRender(float dt) override {
        Scene::onRender(dt);
        DrawFPS(10, 10);
    }
};

int main() {
    Stage stage("Game");

    stage.addScene<Titlescreen>("title");
    stage.transition("title");

    stage.present();

    return 0;
}
