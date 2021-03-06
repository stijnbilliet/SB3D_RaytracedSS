#include "FrameworkPCH.h"
#include "BaseObject.h"

BaseObject::BaseObject()
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::Init(GameContext* pGameContext)
{
	PreInit(pGameContext);
	{
		OnInit(pGameContext);
	}
	PostInit(pGameContext);
}

void BaseObject::Update(GameContext * pGameContext)
{
	PreUpdate(pGameContext);
	{
		OnUpdate(pGameContext);
	}
	PostUpdate(pGameContext);
}

void BaseObject::Draw(GameContext* pGameContext) const
{
	PreDraw(pGameContext);
	{
		OnDraw(pGameContext);
	}
	PostDraw(pGameContext);
}

void BaseObject::PreInit(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::OnInit(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::PostInit(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::PreUpdate(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::OnUpdate(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::PostUpdate(GameContext* pGameContext)
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::PreDraw(GameContext* pGameContext) const
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::OnDraw(GameContext* pGameContext) const
{
	UNREFERENCED_PARAMETER(pGameContext);
}

void BaseObject::PostDraw(GameContext* pGameContext) const
{
	UNREFERENCED_PARAMETER(pGameContext);
}