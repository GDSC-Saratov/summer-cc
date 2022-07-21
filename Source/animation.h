#pragma once
#include "components.h"

namespace plat
{
    struct animation_struct
    {
        Texture2D texture; // текстурка
        float timer; // время проигрывания анимации
        float frame_texture; // фрэйм текстурки
        int maxFrames;
    };

    class Animation : public Component
    {
    public:
        Animation(const std::string& path);
        void update(float id, Entity_id parent_id, Storage &storage) override;
        std::string get_component_type();
    };

    class Animation_control : public Component
    {
        public:
        void update(float id, Entity_id parent_id, Storage &storage) override;
        void Animation_caller(Vector2 move_direction, bool attack_triger, Vector2 pos);
        std::string get_component_type();
    };
}