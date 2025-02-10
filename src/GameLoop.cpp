#include "lotus/GameLoop.h"
#include "lotus/RenderManager.h"
#include "SDL3/SDL.h"

#include <algorithm>
#include <chrono>
#include <vector>

int GameLoop::execute()
{
    SDL_Event e;
    bool running = true;

    std::vector<double> res;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
                running = false;
            if (e.type == SDL_EVENT_KEY_DOWN)
            {
                switch (e.key.key)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                }
            }
        }

        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        m_renderManager->render();
        
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> timeSpan = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);
        double fps = 1000.0 / timeSpan.count();
        res.push_back(fps);
    }
    std::sort(res.begin(), res.end());
    SDL_Log("Median FPS: %f", res[res.size() / 2]);
    return 0;
}
