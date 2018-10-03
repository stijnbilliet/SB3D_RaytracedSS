#include "FrameworkPCH.h"
#include "GameObject.h"
#include "Components/TransformComponent.h"
#include "Scenegraph/BasePanel.h"

using Super = ParentObject<GameObject>;

GameObject::GameObject()
	:ParentObject<GameObject>()
{
	m_pRootComponent = new TransformComponent();
	AddComponent(m_pRootComponent);
}

GameObject::~GameObject()
{
	//Remove yourself because baseclass removes children
	for (auto pComp : m_pComponents)
	{
		safe_delete(pComp);
	}
}

void GameObject::OnInit()
{
	Super::OnInit();

	for (auto comp : m_pComponents)
	{
		comp->Init();
	}

	for (auto child : m_pChildren)
	{
		child->Init();
	}
}

void GameObject::OnUpdate(float deltaTime)
{
	Super::OnUpdate(deltaTime);

	for (auto comp : m_pComponents)
	{
		comp->Update(deltaTime);
	}

	for (auto child : m_pChildren)
	{
		child->Update(deltaTime);
	}
}

void GameObject::OnDraw(Renderer* pContext) const
{
	Super::OnDraw(pContext);

	for (auto comp : m_pComponents)
	{
		comp->Draw(pContext);
	}

	for (auto child : m_pChildren)
	{
		child->Draw(pContext);
	}
}

BasePanel* GameObject::GetScene()
{
	return m_pScene;
}

void GameObject::SetScene(BasePanel * pScene)
{
	m_pScene = pScene;
}

std::list<BaseComponent*> GameObject::GetAllComponents() const
{
	return m_pComponents;
}

void GameObject::OnChildAdd(GameObject * pChild)
{
	pChild->SetScene(m_pScene);
}

void GameObject::AddComponent(BaseComponent * pComp)
{
	m_pComponents.push_back(pComp);
	pComp->Attach(this);
}

void GameObject::RemoveComponent(BaseComponent * pComp)
{
	if (pComp)
	{
		auto it = std::find(m_pComponents.begin(), m_pComponents.end(), pComp);
		m_pComponents.remove(*it);
		pComp->Detach();
		safe_delete(pComp);
	}
}

TransformComponent* GameObject::GetTransform() const
{
	return m_pRootComponent;
}