
class error_COM : public std::runtime_error {
	HRESULT hres;
public:
	error_COM(std::string str, HRESULT hres)
		: std::runtime_error(str), hres(hres)
	{
	}
};