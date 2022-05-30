#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);


private:
	//사각형
	D3DXVECTOR3 m_PlayerInfo[4];

	//포신 회전을 위한 PlayerInfo 복사본
	INFO m_tPosinInfo;

	//포신
	D3DXVECTOR3 m_tPosin;

	float sizeX;
	float sizeY;

	float m_fAngle;
	float m_PosAngle;

	// 몸체 전용
	D3DXMATRIX	matScale;
	D3DXMATRIX  matRotZ;
	D3DXMATRIX  matTrans;

	// 포신 전용
	D3DXMATRIX	PosMatScale;
	D3DXMATRIX  PosMatRotZ;
	D3DXMATRIX  PosMatTrans;


/*

	D3DXVECTOR3		m_vPlayerPos;	// 위치 벡터
	
	D3DXVECTOR3		m_vPlayerDir;	// 방향 벡터
	D3DXVECTOR3		m_vPlayerLook;	// 방향 벡터

	D3DXVECTOR3		m_vPlayerNormal;	// 법선 벡터*/
};

	