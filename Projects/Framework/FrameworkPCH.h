﻿//STD
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <future>
#include <cmath>
#include <mutex>
#include <thread>
#include <chrono>

//GLAD
#include <glad/glad.h>

//SDL & OpenGL
#include <SDL.h>
#include <SDL_opengl.h>

//IMGUI
#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_sdl.h"
#include "ImGUI/imgui_impl_opengl3.h"

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/type_ptr.hpp>

//RADEON RAYS & OpenCL
#include "radeon_rays.h"
#include "radeon_rays_cl.h"
#include "CLW.h"

//FRAMEWORK
#include "Helpers/Helpers.h"
#include "Components/Components.h"
#include "Scenegraph/Scenegraph.h"
#include "Input/Input.h"
#include "Graphics/Graphics.h"
#include "Config/Config.h"
#include "Game/Game.h"
#include "Debug/Debug.h"
