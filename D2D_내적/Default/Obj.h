#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual		void	Initialize(void)	PURE;
	virtual		void	Update(void)		PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;

public:
	INFO& Get_Info() { return m_tInfo; }


protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;

};

