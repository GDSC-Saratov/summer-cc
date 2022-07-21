#include "components.h"

namespace plat
{
    Entity::Entity()
    {
        static Entity_id count = 0;
        id = count++;
    }

    std::string Transform::get_component_type()
    {
        return std::type_index(typeid(Transform)).name();
    }

    std::string Sprite::get_component_type()
    {
        return std::type_index(typeid(Sprite)).name();
    }

    std::string Player_control::get_component_type()
    {
        return std::type_index(typeid(Player_control)).name();
    }

    std::string Camera::get_component_type()
    {
        return std::type_index(typeid(Camera)).name();
    }

    void Transform::update(float dt, Entity_id parent_id, Storage &storage)
    {}

    void Sprite::update(float dt, Entity_id parent_id, Storage &storage)
    {}

    Sprite::Sprite(const std::string &path)
    {
        image = LoadImage(path);
        texture = LoadTextureFromImage(image);
    }

    void Player_control::update(float dt, int parent_id, Storage &storage)
    {
        auto cur_transform = storage.entities[parent_id].getComponent<Transform>();

        if (IsKeyDown(KEY_W))
        {
            cur_transform->pos.y += speed * dt;
            move_direction.y += 1;
        }
        if (IsKeyDown(KEY_S))
        {
            cur_transform->pos.y -= speed * dt;
            move_direction.y -= 1;
        }
        if (IsKeyDown(KEY_A))
        {
            cur_transform->pos.x -= speed * dt;
            move_direction.x += 1;
        }
        if (IsKeyDown(KEY_D))
        {
            cur_transform->pos.x += speed * dt;
            move_direction.x -= 1;
        }
        attack_triger = false;
    }

    void Camera::update(float dt, Entity_id parent_id, Storage &storage)
    {
        plat::Transform *t = storage.entities[parent_id].getComponent<Transform>();
        plat::Camera *cam = storage.entities[parent_id].getComponent<Camera>();

        if (IsKeyDown(KEY_LEFT))
        {
            t->pos.x -= 1;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            t->pos.x += 1;
        }
        if (IsKeyDown(KEY_UP))
        {
            if (IsKeyDown(KEY_LEFT_SHIFT))
            {
                cam->scale.x *= 1.25;
                cam->scale.y *= 1.25;
            }
            else
            {
                t->pos.y += 1;
            }
        }
        if (IsKeyDown(KEY_DOWN))
        {
            if (IsKeyDown(KEY_LEFT_SHIFT))
            {
                cam->scale.x *= 1 / 1.25;
                cam->scale.y *= 1 / 1.25;
            }
            else
            {
                t->pos.y -= 1;
            }
        }
    }
}
