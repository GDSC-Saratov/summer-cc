#define RAYEXT_IMPLEMENTATION
#include <raylib-ext.hpp>
#include <iostream>
#include <algorithm>
#include "json_loader.h"
#include "render.h"

int
main()
{
    const Vector2 screen_size { 640, 480 };
    InitWindow(screen_size.x, screen_size.y, "Creative Coding: Platformer");
    SetTargetFPS(60);

    Viewport viewport = {0, screen_size.x, screen_size.y, 0};
    set_viewport(viewport, screen_size, { 0, 0, screen_size.x, screen_size.y });

    Storage storage = load_lvl("Asssets/Scenes/default.json");

    std::vector<Entity *> draw_queue = create_draw_order(storage.entities);

    while (!WindowShouldClose())
    {
        for (int i = 0; i < storage.entities.size(); ++i)
        {
            for(int j = 0; j < storage.entities[i].components.size(); ++j)
            {
                storage.entities[i].components[j]->Update(GetFrameTime(), storage.entities[i].id, storage);
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = 0; i < draw_queue.size(); ++i)
            {
                for(int j = 0; j < draw_queue[i]->components.size(); ++j)
                {
                    _Transform* transform = draw_queue[i]->getComponent<_Transform>();
                    _Sprite* sprite = draw_queue[i]->getComponent<_Sprite>();
                    Vector2 screen_transform = screen_to_local(viewport, screen_size, { transform->pos.x, transform->pos.y });
                    DrawTexture(sprite->texture, screen_transform.x, screen_transform.y-sprite->texture.height, WHITE);
                }   
            }

            if (IsKeyDown(KEY_LEFT))
            {
                viewport.left += 1;
                viewport.right += 1;
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                viewport.left -= 1;
                viewport.right -= 1;
            }
            if (IsKeyDown(KEY_UP))
            {
                viewport.top += 1;
                viewport.bottom += 1;
            }
            if (IsKeyDown(KEY_DOWN))
            {
                viewport.top -= 1;
                viewport.bottom -= 1;
            }

            DrawFPS(10, 10);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

