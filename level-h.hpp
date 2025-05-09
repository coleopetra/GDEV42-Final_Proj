#ifndef LEVEL_H
#define LEVEL_H

#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <string>
#include "scene_manager.hpp"
#include "Player.hpp"
#include "Bee.hpp"
#include "Ghost.hpp"
#include "Slime.hpp"
#include "TileMap.hpp"

class Level : public Scene {
public:
    Level();
    ~Level();

    void Begin() override;
    void End() override;
    void Update() override;
    void Draw() override;

private:
    // Game state
    bool game_ongoing;
    
    // Camera
    Camera2D camera_view;
    Rectangle camera_window;
    float cam_drift;

    // Game entities
    Player* player;
    std::vector<BaseEnemy*> enemies;
    TileMap map;
    
    // Wave system
    int current_wave;
    int base_wave_points;
    float wave_timer;
    float wave_delay;
    bool wave_cleared;
    
    // Audio
    Music game_music;
    bool music_loaded;

    // Helper methods
    void MoveCamera(float delta_time);
    void SpawnWave(int wave_num);
    void CheckWaveStatus();
    void HandleCollisions();
    void CheckGameStatus();
};

#endif