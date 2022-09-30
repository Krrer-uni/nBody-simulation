#include <SDL.h>
#include "quadtree.h"
#pragma once
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);

void DrawFillCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);

void DrawQuadTree(SDL_Renderer * renderer, quadTree* tree);

void DrawQuadTreeNode(SDL_Renderer* renderer, Node* node);