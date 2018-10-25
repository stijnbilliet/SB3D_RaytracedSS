#pragma once
class GL_Renderer;
class SceneManager;
class BaseGamemode;
class GameContext;
class CL_Renderer : public SingleInstance<CL_Renderer>
{
public:
	CL_Renderer();
	virtual ~CL_Renderer();

	virtual void OnInit(GameContext* pGameContext) override;
	virtual void OnUpdate(GameContext* pContext) override;

	void InitCL(GameContext* pGameContext);
	void InitRadeonRays(GameContext* pGameContext);
	void InitKernels(GameContext* pGameContext);

	void RaytracedShadows(GameContext* pGameContext);
	RadeonRays::IntersectionApi* GetRaysAPI() const;
private:
	void GenerateShadowRays(GameContext* pGameContext);
	void GenerateLightingMask(GameContext* pGameContext);

	void InitShadowRaysKernel(GameContext* pGameContext);
	void InitLightMaskKernel(GameContext* pGameContext);

	//Radeon rays context
	RadeonRays::IntersectionApi* m_pRRContext;
	
	//OpenCL context
	CLWContext m_CLContext; //runtime interface between cpu and gpu
	CLWDevice m_CLDevice;

	//Kernels
	CLWProgram m_RayGenerator; //one or more kernels bundled in one
	CLWKernel m_ShadowRayGenerator;
	CLWKernel m_LightMaskGenerator;

	//KernelData
	cl_mem m_CLGLWorldPosBuffer;
	cl_mem m_CLGLNormalBuffer;
	cl_mem m_CLGLLightBuffer;
	cl_mem m_CLRRRaysBuffer;
	cl_mem m_CLRROcclusionBuffer;

	//Radeon rays data
	RadeonRays::Buffer* m_RaysBuffer;
	RadeonRays::Buffer* m_OcclusionBuffer;

	RadeonRays::ray* m_RayData;
	int* m_OcclusionData;

	int m_ScreenWidth;
	int m_ScreenHeight;
	std::string m_AssetPath;
};