PROGRAM demo
      ! information on the topic of integration between C/C++ and
      ! FORTRAN
      !
      ! + gfortran:
      ! https://gcc.gnu.org/onlinedocs/gfortran/Interoperable-Subroutines-and-Functions.html 
      ! + PGI
      ! https://www.pgroup.com/support/interlan.htm 
      ! + intel
      ! https://software.intel.com/en-us/node/525330 
      ! 
      ! TYPES:
      ! https://gcc.gnu.org/onlinedocs/gfortran/ISO_005fC_005fBINDING.html#ISO_005fC_005fBINDING 

      USE iso_c_binding
      IMPLICIT NONE

      INTEGER :: summ,i,j
      INTEGER, PARAMETER :: N = 10
      INTEGER,DIMENSION(N) :: A = (/1,2,3,4,5,6,7,8,9,0/)
      
      ! C funcion names are case sensitive!
      ! interface for C function must be provided
      INTERFACE
          SUBROUTINE sampprint(a) BIND(C, name="sampPrint")
              USE iso_c_binding, ONLY: C_INT
              ! default in FORTRAN variables are passed by reference not value
              ! as it is in C!
              INTEGER(kind=C_INT),VALUE :: a
          END SUBROUTINE sampprint
      END INTERFACE

      INTERFACE
          INTEGER(kind=C_INT) FUNCTION sampadd(a, b) BIND(C, name="samp_add")
              USE iso_c_binding, ONLY: C_INT
              INTEGER(kind=C_INT),VALUE :: a
              INTEGER(kind=C_INT),VALUE :: b
          END FUNCTION sampadd
      END INTERFACE

      INTERFACE
          INTEGER(kind=C_INT) FUNCTION sampaddp(a, b) BIND(C, name="samp_addp")
              USE iso_c_binding, ONLY: C_INT
              INTEGER(kind=C_INT) :: a
              INTEGER(kind=C_INT) :: b
          END FUNCTION sampaddp
      END INTERFACE

      INTERFACE
          SUBROUTINE sampprintarr(a, n) BIND(C, name="samp_print_arr")
              USE iso_c_binding, ONLY: C_INT
              INTEGER(kind=C_INT), DIMENSION(n) :: a
              INTEGER(kind=C_INT),VALUE :: n
          END SUBROUTINE sampprintarr
      END INTERFACE

      CALL sampprint(10)
      summ = sampadd(1, 2)
      WRITE(*,*) 'Sum by sampadd is',summ
      summ = sampaddp(1, 2)
      WRITE(*,*) 'Sum by sampaddp (with pointers) is',summ
END PROGRAM demo
