#include "Skyrim.h"
#include "Skyrim/NetImmerse/NiTypes.h"


NiTransform::NiTransform()
{
	rot.MakeIdentity();
	scale = 1.0f;
}

NiTransform NiTransform::operator*(const NiTransform &rhs) const
{
	NiTransform tmp;
	tmp.scale = scale * rhs.scale;
	tmp.rot = rot * rhs.rot;
	tmp.pos = pos + (rot * rhs.pos) * scale;
	return tmp;
}

NiPoint3 NiTransform::operator*(const NiPoint3 & pt) const
{
	return (((rot * pt) * scale) + pos);
}
