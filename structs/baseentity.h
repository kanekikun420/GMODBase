class CBaseEntity
{
public:
	float Friction()
	{
		return *reinterpret_cast<float*>((DWORD)this + 0x25C);
	}
	int GetTeamNum()
	{
		return *reinterpret_cast<int*>((DWORD)this + 0x9c);
	}
	Vector Velocity()
	{
		return *reinterpret_cast<Vector*>((DWORD)this + 0x0F4);
	}

	int Health()
	{
		return *reinterpret_cast<int*>((DWORD)this + 0x90);
	}

	int Index()
	{
		
		return *(int*)((DWORD)this + 64);
	}

	int GetFlags()
	{
		return *reinterpret_cast<int*>((DWORD)this + 0x350);
	}

	Vector GetEyePosition()
	{
		Vector vecViewOffset = *reinterpret_cast<Vector*>((DWORD)this + 0xE8);
		return GetAbsOrigin() + vecViewOffset;
	}

	Vector& GetAbsOrigin()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 10))(this);
	}

	Vector& GetAbsAngles()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 11))(this);
	}

	void* GetClientClass()
	{
		void* Networkable = (void*)(this + 0x8);
		typedef void* (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(Networkable, 2))(Networkable);
	}
	
	bool IsDormant()
	{
		typedef bool(__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 73))(this);
	}

	float MaxSpeed()
	{
		return *reinterpret_cast<float*>((DWORD)this + 0x160C);
	}

	bool isAlive()
	{
		BYTE lifestate = *(BYTE*)((DWORD)this + 0x8F);
		return (lifestate == 0);
	}

	int GetIndex()
	{
		void* networkable = (void*)(this + 0x8);
		typedef int(__thiscall* OriginalFn)(PVOID);
		return ((OriginalFn)VMT.GetFunction(this, 76))(this);
	}

	bool SetupBones(VMatrix *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef bool(__thiscall* OriginalFn)(PVOID, VMatrix*, int, int, float);
		return ((OriginalFn)VMT.GetFunction(pRenderable, 16))(pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}

	void* GetModel()
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef void*(__thiscall* OriginalFn)(PVOID);
		return VMT.getvfunc<OriginalFn>(pRenderable, 9)(pRenderable);
	}

};