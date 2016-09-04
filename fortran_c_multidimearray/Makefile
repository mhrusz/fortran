FLAGS = -O2
%: %.f90
	gfortran -o $@ $< lib_c $(FLAGS) 

%: %.c
	gcc -c -o $@ $< $(FLAGS)
