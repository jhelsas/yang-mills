#ifndef U1_H
#define U1_H

#include<complex.h>
#include<math.h>
#include<stdio.h>

#include"macro.h"
#include"tens_prod.h"
#include"tens_prod_adj.h"

typedef struct U1 {
     double complex comp __attribute__((aligned(DOUBLE_ALIGN)));
} U1;


typedef struct U1Adj {
     double comp __attribute__((aligned(DOUBLE_ALIGN)));
} U1Adj;
// defined just to avoid errors at compile time

typedef struct U1Vecs {
     double complex comp[NHIGGS] __attribute__((aligned(DOUBLE_ALIGN)));
} U1Vecs;


// ***************** for U1


// initialize
inline void init_U1(U1 * restrict A, double complex vec)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  A->comp=vec;
  }


// A=1
inline void one_U1(U1 * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  A->comp=1.0;
  }


// A=0
inline void zero_U1(U1 * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  A->comp=0.0;
  }


// A=B
inline void equal_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp=B->comp;
  }


// A=B^{dag}
inline void equal_dag_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp = conj(B->comp);
  }


// A+=B
inline void plus_equal_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp += B->comp;
  }


// A+=B^{dag}
inline void plus_equal_dag_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp += conj(B->comp);
  }


// A-=B
inline void minus_equal_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp -= B->comp;
  }


// A-=(r*B)
inline void minus_equal_times_real_U1(U1 * restrict A, U1 const * const restrict B, double r)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp -= (r*B->comp);
  }


// A-=B^{dag}
inline void minus_equal_dag_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp -= conj(B->comp);
  }


// A=b*B+c*C
inline void lin_comb_U1(U1 * restrict A,
                 double b, U1 const * const restrict B,
                 double c, U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = b*B->comp + c*C->comp;
  }


// A=b*B^{dag}+c*C
inline void lin_comb_dag1_U1(U1 * restrict A,
                      double b, U1 const * const restrict B,
                      double c, U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp =  b*conj(B->comp) + c*C->comp;
  }


// A=b*B+c*C^{dag}
inline void lin_comb_dag2_U1(U1 * restrict A,
                      double b, U1 const * const restrict B,
                      double c, U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = b*B->comp + c*conj(C->comp);
  }


// A=b*B^{dag}+c*C^{dag}
inline void lin_comb_dag12_U1(U1 * restrict A,
                       double b, U1 const * const restrict B,
                       double c, U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = b*conj(B->comp) + c*conj(C->comp);
  }


// A*=r
inline void times_equal_real_U1(U1 * restrict A, double r)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  A->comp*=r;
  }


// A*=r
inline void times_equal_complex_U1(U1 * restrict A, double complex r)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  A->comp*=r;
  }


// A*=B
inline void times_equal_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp *= B->comp;
  }


// A*=B^{dag}
inline void times_equal_dag_U1(U1 * restrict A, U1 const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  A->comp *= conj(B->comp);
  }


// A=B*C
inline void times_U1(U1 * restrict A,
              U1 const * const restrict B,
              U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp= B->comp * C->comp;
  }


// A=B^{dag}*C
inline void times_dag1_U1(U1 * restrict A,
                   U1 const * const restrict B,
                   U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = conj(B->comp)*C->comp;
  }


// A=B*C^{dag}
inline void times_dag2_U1(U1 * restrict A,
                   U1 const * const restrict B,
                   U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = B->comp*conj(C->comp);
  }


// A=B^{dag}*C^{dag}
inline void times_dag12_U1(U1 * restrict A,
                    U1 const * const restrict B,
                    U1 const * const restrict C)
  {
  #ifdef DEBUG
  if(A==B || A==C || B==C)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  __assume_aligned(&(C->comp), DOUBLE_ALIGN);
  #endif

  A->comp = conj(B->comp)*conj(C->comp);
  }


// random matrix
void rand_matrix_U1(U1 *A);


// l2 norm of the matrix
inline double norm_U1(U1 const * const restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  return sqrt(creal(A->comp)*creal(A->comp)+cimag(A->comp)*cimag(A->comp));
  }


// real part of the trace
inline double retr_U1(U1 const * const restrict A)
  {
  return creal(A->comp);
  }


// imaginary part of the trace
inline double imtr_U1(U1 const * const restrict A)
  {
  return cimag(A->comp);
  }


// unitarize the matrix
inline void unitarize_U1(U1 * restrict A)
  {
  double p;

  p=norm_U1(A);
  A->comp/=p;
  }


// antihermitian part (NO TRACELESS!)
inline void ta_U1(U1 * restrict A)
  {
  double complex aux;

  aux=cimag(A->comp);

  A->comp=aux;
  }


// exponential of the antihermitian part (NO TRACELESS!)
inline void taexp_U1(U1 * restrict A)
  {
  double angle, c, s;

  angle=cimag(A->comp);
  c=cos(angle);
  s=sin(angle);

  A->comp=c+I*s;
  }


// print on screen
void print_on_screen_U1(U1 const * const A);


// print on file
int print_on_file_U1(FILE *fp, U1 const * const A);


// print on binary file without changing endiannes
int print_on_binary_file_noswap_U1(FILE *fp, U1 const * const A);


// print on binary file changing endiannes
int print_on_binary_file_swap_U1(FILE *fp, U1 const * const A);


// print on binary file in big endian format
int print_on_binary_file_bigen_U1(FILE *fp, U1 const * const A);


// read from file
int read_from_file_U1(FILE *fp, U1 *A);


// read from binary file without changing endiannes
int read_from_binary_file_noswap_U1(FILE *fp, U1 *A);


// read from binary file changing endiannes
int read_from_binary_file_swap_U1(FILE *fp, U1 *A);


// read from binary file written in big endian
int read_from_binary_file_bigen_U1(FILE *fp, U1 *A);


// initialize tensor product
inline void TensProd_init_U1(TensProd * restrict TP, U1 const * const restrict A1, U1 const * const restrict A2)
  {
  #ifdef DEBUG
  if(A1==A2)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A1->comp), DOUBLE_ALIGN);
  __assume_aligned(&(A2->comp), DOUBLE_ALIGN);
  __assume_aligned(&(TP->comp), DOUBLE_ALIGN);
  #endif

  TP->comp[0][0][0][0]=conj(A1->comp)*A2->comp;
  }



// ***************** for U1Adj



// convert the fundamental representation matrix B to the adjoint representation matrix A
inline void fund_to_adj_U1(U1Adj * restrict A, U1 const * const restrict B)
  {
  (void) A;
  (void) B;

  fprintf(stderr, "The function fund_to_adj_U1 still has to be written (%s, %d)\n", __FILE__, __LINE__);
  exit(EXIT_FAILURE);
  }


// initialize tensor product in the adjoint representation
// using two matrices in the fundamental representation
inline void TensProdAdj_init_U1(TensProdAdj * restrict TP, U1 const * const restrict A1, U1 const * const restrict A2)
  {
  (void) TP;
  (void) A1;
  (void) A2;

  fprintf(stderr, "U(1) has no adjoint representation! (%s, %d)\n", __FILE__, __LINE__);
  exit(EXIT_FAILURE);
  }


// initialize tensor product in the adjoint representation
// using two matrices in the adjoint representation
inline void TensProdAdj_init_U1Adj(TensProdAdj * restrict TP, U1Adj const * const restrict A1, U1Adj const * const restrict A2)
  {
  (void) TP;
  (void) A1;
  (void) A2;

  fprintf(stderr, "U(1) has no adjoint representation! (%s, %d)\n", __FILE__, __LINE__);
  exit(EXIT_FAILURE);
  }


// A=1
inline void zero_U1Adj(U1Adj * restrict A)
  {
  A->comp=1.0;
  }


// A=0
inline void one_U1Adj(U1Adj * restrict A)
  {
  A->comp=0.0;
  }


// A+=B
inline void plus_equal_U1Adj(U1Adj * restrict A, U1Adj const * const restrict B)
  {
  #ifdef DEBUG
  if(A==B)
    {
    fprintf(stderr, "The same pointer is used twice in (%s, %d)\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
    }
  #endif

  A->comp += B->comp;
  }


// A*=r
inline void times_equal_real_U1Adj(U1Adj * restrict A, double r)
  {
  A->comp *=r;
  }


// A*=B
inline void times_equal_U1Adj(U1Adj * restrict A, U1Adj const * const restrict B)
  {
  (void) A;
  (void) B;
  }


// trace in the adjoint rep.
inline double retr_U1Adj(U1Adj * restrict A)
  {
  (void) A;
  return 0.0;
  }


// ***************** for U1Vecs


// A=1
inline void one_U1Vecs(U1Vecs * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]=1.0;
     }
  }


// A=0
inline void zero_U1Vecs(U1Vecs * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]=0.0;
     }
  }


// A=B
inline void equal_U1Vecs(U1Vecs * restrict A, U1Vecs const * const restrict B)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]=B->comp[i];
     }
  }


// A -> A^{dag}
inline void conjugate_U1Vecs(U1Vecs * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]=conj(A->comp[i]);
     }
  }


// A-=B
inline void minus_equal_U1Vecs(U1Vecs * restrict A, U1Vecs const * const restrict B)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]-=B->comp[i];
     }
  }


// A+=B
inline void plus_equal_U1Vecs(U1Vecs * restrict A, U1Vecs const * const restrict B)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  __assume_aligned(&(B->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]+=B->comp[i];
     }
  }


// *= with real number
inline void times_equal_real_U1Vecs(U1Vecs * restrict A, double r)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     A->comp[i]*=r;
     }
  }


// norm
inline double norm_U1Vecs(U1Vecs const * const restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  int i;
  double ris=0.0;

  for(i=0; i<NHIGGS; i++)
     {
     ris+=cabs(A->comp[i])*cabs(A->comp[i]);
     }

  return sqrt(ris);
  }


// normalize
inline void normalize_U1Vecs(U1Vecs * restrict A)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(A->comp), DOUBLE_ALIGN);
  #endif

  double norm=norm_U1Vecs(A);

  times_equal_real_U1Vecs(A, 1./norm);
  }


// random vector (normalized)
void rand_vec_U1Vecs(U1Vecs * restrict A);


// real part of the scalar product re(v_1^{\dag}v_2)
inline double re_scal_prod_U1Vecs(U1Vecs const * const restrict v1, U1Vecs const * const restrict v2)
  {
   #ifdef __INTEL_COMPILER
  __assume_aligned(&(v1->comp), DOUBLE_ALIGN);
  __assume_aligned(&(v2->comp), DOUBLE_ALIGN);
  #endif

  int i;
  double ris=0.0;

  for(i=0; i<NHIGGS; i++)
     {
     ris+=creal( conj(v1->comp[i]) * v2->comp[i] );
     }

  return ris;
  }


// the i-th component of v2 is multiplied by "matrix"
// v1=matrix*v2
inline void matrix_times_vector_single_U1Vecs(U1Vecs * restrict v1, U1 const * const restrict matrix, U1Vecs const * const restrict v2, int i)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(v1->comp), DOUBLE_ALIGN);
  __assume_aligned(&(matrix->comp), DOUBLE_ALIGN);
  __assume_aligned(&(v2->comp), DOUBLE_ALIGN);
  #endif

  equal_U1Vecs(v1, v2);

  v1->comp[i]=(matrix->comp)*(v2->comp[i]);
  }


// all the components of v2 are multiplied by "matrix"
// v1=matrix*v2
inline void matrix_times_vector_all_U1Vecs(U1Vecs * restrict v1, U1 const * const restrict matrix, U1Vecs const * const restrict v2)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(v1->comp), DOUBLE_ALIGN);
  __assume_aligned(&(matrix->comp), DOUBLE_ALIGN);
  __assume_aligned(&(v2->comp), DOUBLE_ALIGN);
  #endif

  int i;

  for(i=0; i<NHIGGS; i++)
     {
     v1->comp[i]=(matrix->comp)*(v2->comp[i]);
     }
  }


// tensor product of two vectors
// Re(v1^{\dag} * aux * v2) = ReTr(aux * matrix)
inline void vector_tensor_vector_U1Vecs(U1 * restrict matrix, U1Vecs const * const restrict v1, U1Vecs const * const restrict v2)
  {
  #ifdef __INTEL_COMPILER
  __assume_aligned(&(matrix->comp), DOUBLE_ALIGN);
  __assume_aligned(&(v1->comp), DOUBLE_ALIGN);
  __assume_aligned(&(v2->comp), DOUBLE_ALIGN);
  #endif

  int i;

  zero_U1(matrix);

  for(i=0; i<NHIGGS; i++)
     {
     matrix->comp+=conj(v1->comp[i])*v2->comp[i];
     }
  }


// print on file
int print_on_file_U1Vecs(FILE *fp, U1Vecs const * const A);


// print on binary file without changing endiannes
int print_on_binary_file_noswap_U1Vecs(FILE *fp, U1Vecs const * const A);


// print on binary file changing endiannes
int print_on_binary_file_swap_U1Vecs(FILE *fp, U1Vecs const * const A);


// print on binary file in big endian format
int print_on_binary_file_bigen_U1Vecs(FILE *fp, const U1Vecs * const A);


// read from file
int read_from_file_U1Vecs(FILE *fp, U1Vecs *A);


// read from binary file without changing endiannes
int read_from_binary_file_noswap_U1Vecs(FILE *fp, U1Vecs *A);


// read from binary file changing endiannes
int read_from_binary_file_swap_U1Vecs(FILE *fp, U1Vecs *A);


// read from binary file written in big endian
int read_from_binary_file_bigen_U1Vecs(FILE *fp, U1Vecs *A);


#endif // U1_H

