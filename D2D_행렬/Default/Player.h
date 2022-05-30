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
	//�簢��
	D3DXVECTOR3 m_PlayerInfo[4];

	//���� ȸ���� ���� PlayerInfo ���纻
	INFO m_tPosinInfo;

	//����
	D3DXVECTOR3 m_tPosin;

	float sizeX;
	float sizeY;

	float m_fAngle;
	float m_PosAngle;

	// ��ü ����
	D3DXMATRIX	matScale;
	D3DXMATRIX  matRotZ;
	D3DXMATRIX  matTrans;

	// ���� ����
	D3DXMATRIX	PosMatScale;
	D3DXMATRIX  PosMatRotZ;
	D3DXMATRIX  PosMatTrans;


/*

	D3DXVECTOR3		m_vPlayerPos;	// ��ġ ����
	
	D3DXVECTOR3		m_vPlayerDir;	// ���� ����
	D3DXVECTOR3		m_vPlayerLook;	// ���� ����

	D3DXVECTOR3		m_vPlayerNormal;	// ���� ����*/
};

	