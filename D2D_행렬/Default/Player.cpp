#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.vPos.x = 400.f;
	m_tInfo.vPos.y = 400.f;
	m_tInfo.vDir = { 1.f, 0.f, 0.f };


	sizeX = 50.f;
	sizeY = 50.f;
	
	// �� ���
	m_PlayerInfo[0] = { -sizeX * 0.5f, -sizeY * 0.5f, 0.f };

	// �� ���
	m_PlayerInfo[1] = { sizeX * 0.5f, -sizeY * 0.5f, 0.f };

	// ���ϴ� 
	m_PlayerInfo[2] = { sizeX * 0.5f, sizeY * 0.5f, 0.f };

	// ���ϴ�
	m_PlayerInfo[3] = { -sizeX * 0.5f, sizeY * 0.5f, 0.f };


	m_tPosin.x = sizeX;
	m_tPosin.y = 0.f;

	m_fAngle = 0.f;
	m_PosAngle = 0.f;
	m_fSpeed = 3.f;

	D3DXMatrixIdentity(&matScale);
	D3DXMatrixIdentity(&matRotZ);
	D3DXMatrixIdentity(&matTrans);

	D3DXMatrixIdentity(&PosMatScale);
	D3DXMatrixIdentity(&PosMatRotZ);
	D3DXMatrixIdentity(&PosMatTrans);

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixScaling(&PosMatScale, 1.f, 1.f, 1.f);

}

void CPlayer::Update(void)
{
	m_fAngle = 0.f;
	m_PosAngle = 0.f;

	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);
	m_tPosinInfo = m_tInfo;

	// ������ ����
	Key_Input();


	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixRotationZ(&PosMatRotZ, D3DXToRadian(m_PosAngle));

	m_tInfo.matWorld = matScale * matRotZ * matTrans;
	m_tPosinInfo.matWorld = PosMatScale * PosMatRotZ * PosMatRotZ;

	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);


	// ���Ϳ� ����� ������ �������ִ� dx �Լ�

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ��ġ ���͸� ��ȯ�ϴ� �Լ�

	D3DXVec3TransformCoord(&m_PlayerInfo[0], &m_PlayerInfo[0], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&m_PlayerInfo[1], &m_PlayerInfo[1], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&m_PlayerInfo[2], &m_PlayerInfo[2], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&m_PlayerInfo[3], &m_PlayerInfo[3], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&m_tPosin, &m_tPosin, &m_tPosinInfo.matWorld);

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ���� ���͸� ��ȯ�ϴ� �Լ�
	//D3DXVec3TransformNormal(&vDir, &vDir, &m_tInfo.matWorld);

}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.vPos.x + m_PlayerInfo[0].x, m_tInfo.vPos.y + m_PlayerInfo[0].y, NULL);
	LineTo(hDC, m_tInfo.vPos.x + m_PlayerInfo[1].x, m_tInfo.vPos.y + m_PlayerInfo[1].y);
	LineTo(hDC, m_tInfo.vPos.x + m_PlayerInfo[2].x, m_tInfo.vPos.y + m_PlayerInfo[2].y);
	LineTo(hDC, m_tInfo.vPos.x + m_PlayerInfo[3].x, m_tInfo.vPos.y + m_PlayerInfo[3].y);
	LineTo(hDC, m_tInfo.vPos.x + m_PlayerInfo[0].x, m_tInfo.vPos.y + m_PlayerInfo[0].y);

	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, NULL);
	LineTo(hDC, m_tInfo.vPos.x + m_tPosin.x, m_tInfo.vPos.y + m_tPosin.y);

}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_fAngle -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fAngle += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		//D3DXMatrixTranslation(&matTrans, m_fSpeed, 0.f, 0.f);
		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		//D3DXMatrixTranslation(&matTrans, -m_fSpeed, 0.f, 0.f);
		m_tInfo.vPos -= m_tInfo.vDir * m_fSpeed;

	}

	if (GetAsyncKeyState('A'))
	{
		m_PosAngle--;
	}

	if (GetAsyncKeyState('D'))
	{
		m_PosAngle++;
	}
}
