
COMRaskroyps.dll: dlldata.obj COMRaskroy_p.obj COMRaskroy_i.obj
	link /dll /out:COMRaskroyps.dll /def:COMRaskroyps.def /entry:DllMain dlldata.obj COMRaskroy_p.obj COMRaskroy_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del COMRaskroyps.dll
	@del COMRaskroyps.lib
	@del COMRaskroyps.exp
	@del dlldata.obj
	@del COMRaskroy_p.obj
	@del COMRaskroy_i.obj
