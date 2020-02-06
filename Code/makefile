all: compilelib library main link

compilelib:
	cl /c search.c

library:
	lib /OUT:coursework.lib search.obj

main:
	cl /c find.c

link:
	link find.obj coursework.lib

clean:
	del *.exe
	del *.obj
	del *.lib
