namespace raskroy_api
{
	class error
	{
	protected:
		const char *str;
	public:
		error(const char *str) : str(str) {}
		virtual std::string what(void) {return std::string(str);}
	};

	class raskroy_error : public error
	{
		HRESULT hRes;
	public:
		raskroy_error(const char *str, HRESULT hRes) : error(str), hRes(hRes) {}
		operator HRESULT(void) {return hRes;}
		std::string Hres2String(void) 
		{
			char buf[256];
			std::string ret;
			switch (hRes)
			{
			case E_INVALIDARG:
				return "не верные параметры";
		    case E_CANNOTSETPARTS:
      			return "не получилось расположить детали";
			case E_OUTOFMEMORY:
    			return "недостаточно памяти";
			case E_UNEXPECTED:
				return "неожиданный сбой";
			default:
				ret = "неопознанная ошибка ";
				ret += itoa(hRes, buf, sizeof(buf));
				return ret;
			}
		}
		virtual std::string what(void)
		{
			std::string ret(str);
			ret += ": ";
			ret += Hres2String();
			return ret;
		}
	};

	class windows_error : public error
	{
		DWORD ErrID;
	public:
		windows_error(const char *str, DWORD ErrID=GetLastError()) : error(str), ErrID(ErrID) {}
		operator DWORD(void) {return ErrID;}
		std::string ErrID2String() {TCHAR buf[256]; FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ErrID, 0, buf, sizeof(buf)/sizeof(TCHAR), 0); return std::string(buf);}
		virtual std::string what(void)
		{
			std::string ret(str);
			ret += ": ";
			ret += ErrID2String();
			return ret;
		}
	};
}