#include "animation.h"

std::string plat::Animation::get_component_type()
{
    return std::type_index(typeid(Animation)).name();
}

std::string plat::Animation_control::get_component_type()
{
    return std::type_index(typeid(Animation_control)).name();
}

void plat::Animation::update(float dt, Entity_id parent_id, Storage &storage)
{}

void plat::Animation_control::update(float dt, Entity_id parent_id, Storage &storage)
{}

std::vector <plat::animation_struct> Animation_vector_adder()
{
    std::vector <plat::animation_struct> animation_array
    {
        // King idle animation
        {LoadTexture("Assets/Textures/Character/King_idle.png"), 0.2f, (float)(LoadTexture("Assets/Textures/Character/King_idle.png").width / 11), (int)(LoadTexture("Assets/Textures/Character/King_idle.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_idle.png").width / 11)))},
        // King walk/run animation
        {LoadTexture("Assets/Textures/Character/King_run.png"), 0.15f, (float)(LoadTexture("Assets/Textures/Character/King_run.png").width / 8), (int)(LoadTexture("Assets/Textures/Character/King_run.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_run.png").width / 8)))},
        // King attack animation
        {LoadTexture("Assets/Textures/Character/King_attack.png"), 0.1f, (float)(LoadTexture("Assets/Textures/Character/King_attack.png").width / 3), (int)(LoadTexture("Assets/Textures/Character/King_attack.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_attack.png").width / 3)))}, 
        // King dead animation
        {LoadTexture("Assets/Textures/Character/King_dead.png"), 1.0f, (float)(LoadTexture("Assets/Textures/Character/King_dead.png").width / 4), (int)(LoadTexture("Assets/Textures/Character/King_dead.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_dead.png").width / 4)))},
        // King hit animation
        {LoadTexture("Assets/Textures/Character/King_hit.png"), 0.5f, (float)(LoadTexture("Assets/Textures/Character/King_hit.png").width / 2), (int)(LoadTexture("Assets/Textures/Character/King_hit.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_hit.png").width / 2)))},
        // King jump "animation"
        {LoadTexture("Assets/Textures/Character/King_jump.png"), 1.0f, (float)(LoadTexture("Assets/Textures/Character/King_jump.png").width / 1), (int)(LoadTexture("Assets/Textures/Character/King_jump.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_jump.png").width / 1)))},
        // King fall "animation"
        {LoadTexture("Assets/Textures/Character/King_fall.png"), 1.0f, (float)(LoadTexture("Assets/Textures/Character/King_fall.png").width / 1), (int)(LoadTexture("Assets/Textures/Character/King_fall.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_fall.png").width / 1)))},
        // King ground animation
        {LoadTexture("Assets/Textures/Character/King_ground.png"), 1.0f, (float)(LoadTexture("Assets/Textures/Character/King_ground.png").width / 1), (int)(LoadTexture("Assets/Textures/Character/King_ground.png").width / (int)((float)(LoadTexture("Assets/Textures/Character/King_ground.png").width / 1)))} 
    };

    return animation_array;
}

void plat::Animation_control::Animation_caller(Vector2 move_direction, bool attack_triger, Vector2 pos)
{
    int frame = 0;

    std::vector <plat::animation_struct> animation_array = Animation_vector_adder();

    if (move_direction.x == 0)
    {
        for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);

        while (frame != animation_array[0].maxFrames || move_direction.x == 0)
        {
            DrawTextureRec(animation_array[0].texture, Rectangle{(animation_array[0].frame_texture * frame), 0, animation_array[0].frame_texture, (float)animation_array[0].texture.height}, Vector2{pos.x, pos.y}, WHITE);
            
            frame ++;
        }
    }
    else
    {
        for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);

        if (move_direction.x == 1) 
        while(frame != animation_array[1].maxFrames || move_direction.x == 1)
        {
            DrawTextureRec(animation_array[1].texture, Rectangle{(animation_array[1].frame_texture * frame), 1, animation_array[1].frame_texture, (float)animation_array[1].texture.height}, Vector2{pos.x, pos.y}, WHITE);
            
            frame ++;
        }
    }
/*
    // Прыжок, падение и призимление
    if (move_direction.y == 1)
    {
        for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);

        if (move_direction.x == 1) DrawTextureRec(animation_array[5].texture, Rectangle{(animation_array[5].frame_texture * frame), 1, animation_array[5].frame_texture, (float)animation_array[5].texture.height}, Vector2{pos.x, pos.y}, WHITE);
    }
    else
    {
        for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);

        if (move_direction.y == -1) DrawTextureRec(animation_array[6].texture, Rectangle{(animation_array[6].frame_texture * frame), 0, animation_array[6].frame_texture, (float)animation_array[6].texture.height}, Vector2{pos.x, pos.y}, WHITE);

        if (move_direction.y = 0)
        {
            for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);

            DrawTextureRec(animation_array[6].texture, Rectangle{(animation_array[6].frame_texture * frame), 0, animation_array[6].frame_texture, (float)animation_array[6].texture.height}, Vector2{pos.x, pos.y}, WHITE);
        }
    }
    // надо добавить ещё получения урона если было слишком высоко(но эт не обязательно)
*/
    // анимация атаки
    if (attack_triger)
    {
        for (int i = 0, j = sizeof(animation_array); i<j; i++) UnloadTexture(animation_array[i].texture);
                
        while (frame != animation_array[4].maxFrames || attack_triger == true)
        {
            DrawTextureRec(animation_array[4].texture, Rectangle{(animation_array[4].frame_texture * frame), 0, animation_array[4].frame_texture, (float)animation_array[4].texture.height}, Vector2{pos.x, pos.y}, WHITE);

            frame ++;
        }
    }
}