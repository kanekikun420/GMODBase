class CInput
{
public:
	CUserCmd *GetUserCmd(int sqnum)
	{
		typedef CUserCmd*(__thiscall* Fn)(void*, int);
		return ((Fn)VMT.GetFunction(this, 8))(this, sqnum);
	}
};