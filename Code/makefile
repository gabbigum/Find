all: compilelib library main link

compilelib:
	cl /c searchfile.c

library:
	lib /OUT:coursework.lib searchfile.obj

main:
	cl /c find.c

link:
	link find.obj coursework.lib

clean:
	del *.exe
	del *.obj
	del *.lib
