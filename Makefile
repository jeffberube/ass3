cc = g++
obj = craps.o

craps: $(obj)
	$(cc) $(obj) -o $(@)

.cpp.o:
	$(cc) -c $<

clean:
	rm *.o craps
