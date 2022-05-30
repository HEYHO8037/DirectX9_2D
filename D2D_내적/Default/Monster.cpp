#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.vPos	= { 100.f, 100.f, 0.f };
	m_fSpeed		= 5.f;

}

void CMonster::Update(void)
{
	m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	//float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	D3DXVec3Normalize(&m_pPlayer->Get_Info().vDir, &m_pPlayer->Get_Info().vDir);

	float fLength = D3DXVec3Dot(&m_tInfo.vDir, &m_pPlayer->Get_Info().vDir);

	float fAngle = acosf(fLength);

	if (m_tInfo.vPos.y < m_pPlayer->Get_Info().vPos.y)
	{
		fAngle *= -1.f;
	}

	m_tInfo.vPos.x += cosf(fAngle) * m_fSpeed;
	m_tInfo.vPos.y -= sinf(fAngle) * m_fSpeed;
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 50.f),
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CMonster::Release(void)
{
	
}

// ���� ���� : ũ�Ⱑ 1�� ����
// ������ ����ȭ : ���� ���͸� ����� ����

// ������ ������ ���� : �ݵ�� �� ���� ����(���� ����)�� ���� ����

// ���� : ��Į�� ��(����� ����� �߻�), ��ȣ�� A �� B, ������ ��� : x*x` + y*y`+ z*z`
// ���� : ���� ��(����� ���Ͱ� �߻�), ��ȣ�� A X B, ������ ��� 

/*
X		Y		Z

X`      Y`      Z`

(Y * Z` - Z * Y`, X * Z` - Z * X`, X * Y` - Y * X`);*/


// 1. ������ ������ �̿��Ͽ� �÷��̾ ����ٴϴ� ���͸� �����϶�.