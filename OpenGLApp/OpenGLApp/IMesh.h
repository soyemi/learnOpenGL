#pragma once

class IMesh
{
public:
	IMesh() {};
	virtual ~IMesh()= 0;

	virtual void GetVertexCount() = 0;
};