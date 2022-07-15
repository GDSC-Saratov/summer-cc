#include"components.h"
#include"raylib.h"
#include<vector>

typedef int Entity_id;

std::string _Player_control::get_component_type()
{

    return std::type_index(typeid(_Player_control)).name();
}

std::string _Transform::get_component_type()
{

    return std::type_index(typeid(_Transform)).name();
}


void _Transform::Update(float dt, int parent_id, Storage &storage)
{
    
}

void _Player_control::Update(float dt, int parent_id, Storage &storage)
{
    auto cur_transform = storage.entitys[parent_id].getComponent<_Transform>();
    
    if (IsKeyDown(KEY_W))
    {
        cur_transform->pos.y -= speed*dt;
    }
    else if (IsKeyDown(KEY_S))
    {
        cur_transform->pos.y += speed*dt;
    }
    
    if (IsKeyDown(KEY_A))
    {
        cur_transform->pos.x -= speed*dt;
    }
    else if (IsKeyDown(KEY_D))
    {
        cur_transform->pos.x += speed*dt;
    }
}
