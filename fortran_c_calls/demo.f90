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

      USE iso_c_binding
      IMPLICIT NONE
      
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

      CALL sampprint(10)

END PROGRAM demo
