CC = cl.exe
OBJDIR = obj/
SRCDIR = ./
OBJS = $(OBJDIR)Parser.obj $(OBJDIR)drawer.obj $(OBJDIR)Perebor.obj $(OBJDIR)raskroy.obj $(OBJDIR)Perebor2d.obj
TARGET = raskroy
STDAFX = stdafx

COMMCFLAGS = /Od /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_MBCS" /Gm /EHsc /RTC1 /MLd \
	/Fo"$(OBJDIR)" /Fp"$(OBJDIR)$(TARGET).pch" /Fd"$(OBJDIR)$(TARGET).pdb" /W3 /nologo /c /Wp64 /ZI /TP

CFLAGS = $(COMMCFLAGS) /Yu"$(STDAFX).h"

lib: $(OBJS)
	lib.exe /OUT:"$(OBJDIR)$(TARGET).lib" /NOLOGO $(OBJS)

$(OBJDIR)$(TARGET).pch: $(STDAFX).cpp $(STDAFX).h
	$(CC) $(COMMCFLAGS) /Yc "$(STDAFX).h" $(STDAFX).cpp

$(OBJDIR)Parser.obj: $(SRCDIR)Parser.cpp $(SRCDIR)Parser.h $(OBJDIR)$(TARGET).pch
	$(CC) $(CFLAGS) $(SRCDIR)Parser.cpp

$(OBJDIR)drawer.obj: $(SRCDIR)drawer.cpp $(SRCDIR)drawer.h $(SRCDIR)Parser.h $(OBJDIR)$(TARGET).pch
	$(CC) $(CFLAGS) $(SRCDIR)drawer.cpp

$(OBJDIR)Perebor.obj: $(SRCDIR)Perebor.cpp $(SRCDIR)Perebor.h $(SRCDIR)common.h $(OBJDIR)$(TARGET).pch
	$(CC) $(CFLAGS) $(SRCDIR)Perebor.cpp

$(OBJDIR)raskroy.obj: $(SRCDIR)raskroy.cpp $(SRCDIR)raskroy.h $(SRCDIR)Perebor2d.h $(OBJDIR)$(TARGET).pch
	$(CC) $(CFLAGS) $(SRCDIR)raskroy.cpp

$(OBJDIR)Perebor2d.obj: $(SRCDIR)Perebor2d.cpp $(SRCDIR)Perebor2d.h $(SRCDIR)Perebor.h $(OBJDIR)$(TARGET).pch
	$(CC) $(CFLAGS) $(SRCDIR)Perebor2d.cpp
