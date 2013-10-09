#include <assert.h>

namespace raskroy_api {

	class CRaskroyLibrary {
	//friend class Lonely;
	friend class Raskroy1;
	friend class Drawer1;
	public:
		LPCTSTR lpLibFileName;

		CRaskroyLibrary(void) : hLib(NULL), lpLibFileName("oldraskroy.dll"), pRaskroyCreate(0), pDrawerCreate(0) {}
		~CRaskroyLibrary(void) {if (hLib) assert(FreeLibrary(hLib));}
	private:
		HINSTANCE hLib;

		raskroy_api::pRaskroyCreate pRaskroyCreate;
		raskroy_api::pDrawerCreate pDrawerCreate;


		void Attach(void)
		{
			hLib = ::LoadLibrary(lpLibFileName);
		    if (hLib == NULL)
    			throw windows_error("Ошибка при загрузке модуля раскроя");

		    pRaskroyCreate = reinterpret_cast<raskroy_api::pRaskroyCreate>(::GetProcAddress(hLib, "RaskroyCreate"));
		    if (pRaskroyCreate == NULL)
		    {
    			assert(FreeLibrary(hLib));
		        hLib = NULL;
    				throw windows_error("Не удалось получить адрес процедуры RaskroyCreate");
		    }

		    pDrawerCreate = reinterpret_cast<raskroy_api::pDrawerCreate>(::GetProcAddress(hLib, "DrawerCreate"));
		}

		void RaskroyCreate(raskroy_api::IRaskroy1*& pRaskroy) {
			if (!hLib)
				Attach();
		    assert(hLib); assert(pRaskroyCreate);
			HRESULT hres;
			if (FAILED(hres = pRaskroyCreate(&pRaskroy)))
    			throw raskroy_error("Не удалось получить интерфейс раскроя", hres);
			assert(pRaskroy);
		}

		void DrawerCreate(raskroy_api::IDrawer1*& pDrawer)
		{
			if (!hLib)
    			Attach();
		    if (!hLib || !pDrawerCreate)
    			throw windows_error("Невозможна отрисовка результатов, т.к. не удалось загрузить программу отображения.");
		    HRESULT hres = pDrawerCreate(&pDrawer);
			if (FAILED(hres))
		    	throw raskroy_error("Не удалось получить интерфейс программы отображения", hres);
			assert(pDrawer);
		}
	};

	extern CRaskroyLibrary library;

	/*class Lonely {
	public:
		static CRaskroyLibrary library;
	};*/

	// класс оболочка для IResult1
	class Result1
	{
    friend class Drawer1;
		IResult1* pResult;
	public:
		Result1(IResult1 *pResult=0) : pResult(pResult) {}
		Result1(const Result1 &orig) : pResult(orig.pResult) {assert(pResult); pResult->AddRef();}
		~Result1(void) {if (pResult) pResult->Release();}

		//operator IResult1*(void) {return pResult;}

		IResult1* reset(IResult1 *pResult = 0) {IResult1 *pRet = this->pResult; this->pResult = pResult; return pRet;}

		long get_DetailsCount(void) {assert(pResult); HRESULT hRes; long Ret; if (FAILED(hRes = pResult->get_DetailsCount(&Ret))) throw raskroy_error("get_DetailsCount", hRes); return Ret;}
		raskroy::t_parsed_part get_DetailsItem(long Index) {assert(pResult); HRESULT hRes; raskroy::t_parsed_part Ret; if (FAILED(hRes = pResult->get_DetailsItem(Index, &Ret))) throw raskroy_error("get_DetailsItem", hRes); return Ret;}
		long get_CutsCount(void) {assert(pResult); HRESULT hRes; long Ret; if (FAILED(hRes = pResult->get_CutsCount(&Ret))) throw raskroy_error("get_CutsCount", hRes); return Ret;}
		raskroy::t_parsed_cut get_CutsItem(long Index) {assert(pResult); HRESULT hRes; raskroy::t_parsed_cut Ret; if (FAILED(hRes = pResult->get_CutsItem(Index, &Ret))) throw raskroy_error("get_CutsItem", hRes); return Ret;}
		raskroy::t_part get_Sheet(void) {assert(pResult); HRESULT hRes; raskroy::t_part Ret; if (FAILED(hRes = pResult->get_Sheet(&Ret))) throw raskroy_error("get_Sheet", hRes); return Ret;}
		long get_RepetitionFactor(void) {assert(pResult); HRESULT hRes; long Ret; if (FAILED(hRes = pResult->get_RepetitionFactor(&Ret))) throw raskroy_error("get_RepetitionFactor", hRes); return Ret;}
		raskroy::t_stat get_Statistic(void) {assert(pResult); HRESULT hRes; raskroy::t_stat Ret; if (FAILED(hRes = pResult->get_Statistic(&Ret))) throw raskroy_error("get_Statistic", hRes); return Ret;};
	};

	// оболочка для класса IRaskroy1
	class Raskroy1 {
		IRaskroy1* pRaskroy;
	public:
		Raskroy1(void) {library.RaskroyCreate(pRaskroy); assert(pRaskroy);}
		Raskroy1(IRaskroy1 *pRaskroy) : pRaskroy(pRaskroy) {assert(pRaskroy);}
		Raskroy1(Raskroy1 &orig) : pRaskroy(orig.pRaskroy) {assert(pRaskroy); pRaskroy->AddRef();}
		~Raskroy1(void) {assert(pRaskroy); pRaskroy->Release();}

		void SetCriteria(raskroy::criteria &criteria) {assert(pRaskroy); HRESULT hRes; if (FAILED(hRes=pRaskroy->SetCriteria(&criteria))) throw raskroy_error("SetCriteria", hRes);}
		void SetRecursionDepth(long Depth) {assert(pRaskroy); HRESULT hRes; if (FAILED(hRes=pRaskroy->SetRecursionDepth(Depth))) throw raskroy_error("SetRecursionDepth", hRes);}
	    void SetFactory(raskroy::t_factory &factory) {assert(pRaskroy); HRESULT hRes; if (FAILED(hRes=pRaskroy->SetFactory(&factory))) throw raskroy_error("SetFactory", hRes);}
		void SetMonitor(raskroy::monitor &monitor) {assert(pRaskroy); HRESULT hRes; if (FAILED(hRes=pRaskroy->SetMonitor(&monitor))) throw raskroy_error("SetMonitor", hRes);}
	    bool First(const std::vector<raskroy::t_part> &Parts, const std::vector<raskroy::t_part> &Sheets, Result1 &Result)  {assert(pRaskroy); HRESULT hRes; bool Ret; IResult1* pResult; if (FAILED(hRes = pRaskroy->First(Parts.begin(), Parts.size(), Sheets.begin(), Sheets.size(), &pResult, &Ret))) throw raskroy_error("Next", hRes); Result1 OldResult(Result.reset(pResult)); return Ret;}
		bool Next(Result1& Result) {assert(pRaskroy); HRESULT hRes; bool Ret; IResult1* pResult; if (FAILED(hRes = pRaskroy->Next(&pResult, &Ret))) throw raskroy_error("Next", hRes); Result1 OldResult(Result.reset(pResult)); return Ret;}
	};

	class drawer_error : public raskroy_error
	{
	public:
		drawer_error(char *str, HRESULT hres) : raskroy_error(str, hres) {}
	};

	class Drawer1 {
		IDrawer1* pDrawer;
	public:
		Drawer1(void) {library.DrawerCreate(pDrawer); assert(pDrawer);}
		Drawer1(IDrawer1 *pDrawer) : pDrawer(pDrawer) {assert(pDrawer);}
		Drawer1(Drawer1 &orig) : pDrawer(orig.pDrawer) {assert(pDrawer); pDrawer->AddRef();}
		~Drawer1(void) {assert(pDrawer); pDrawer->Release();}

		void Draw(HDC hDC, long Width, long Height, Result1 &Result) {assert(pDrawer); HRESULT hRes; if (FAILED(hRes=pDrawer->Draw(hDC, Width, Height, Result.pResult))) throw drawer_error("Draw", hRes);}
	};

}