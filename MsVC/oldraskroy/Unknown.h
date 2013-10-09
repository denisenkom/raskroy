#ifndef UNKNOWN_H_INCLUDED
#define UNKNOWN_H_INCLUDED

namespace raskroy_api {

	class CUnknown : public IUnknown
	{
		unsigned ref_counter;
	protected:
		CUnknown(void) : ref_counter(1) {}
		virtual ~CUnknown(void) {assert(ref_counter == 0);};
	public:
		STDMETHOD_(ULONG, AddRef)(void)
		{
			return ++ref_counter;
		}

		STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppiface)
		{
			if (!ppiface)
				return E_INVALIDARG;
			return E_NOTIMPL;
		}

		STDMETHOD_(ULONG, Release)(void)
		{
			unsigned new_ref_counter = --ref_counter;
			if (!ref_counter)
				delete this;
			return new_ref_counter;
		}
	};
}

#endif	// UNKNOWN_H_INCLUDED