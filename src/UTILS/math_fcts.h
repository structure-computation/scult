#ifndef MATH_FCTS_H
#define MATH_FCTS_H

//#include <iostream>
//#include <math.h>



// inline TYPE * sum(TYPE *V1, TYPE *V2, int dim){
//     TYPE res[3];
//     for(unsigned i=0;i< dim ;i++){
//         res[i]=V1[i]+V2[i];
//     }
//     return res;
// }
// 
// __device__ TYPE * diff(TYPE *V1, TYPE *V2, int dim){
//     TYPE res[3];
//     for(unsigned i=0;i< dim ;i++){
//         res[i]=V1[i]-V2[i];
//     }
//     return res;
// }
// 
// 
inline TYPE dot(TYPE *V1, TYPE *V2, int dim)
{
    TYPE res=0.;
    for(unsigned i=0;i< dim ;i++){
        res+=V1[i]*V2[i];
    }
    return res;
}

// 
// __device__ TYPE norm(TYPE *V, int dim)
// {
//     return (sqrt(dot(V,V,dim)));
// }
// 
//pour des vecteurs de taille 3
inline void prod_vec(TYPE *V1, TYPE *V2, TYPE *res){
    res[0]=V1[1]*V2[2]-V1[2]*V2[1];
    res[1]=V1[2]*V2[0]-V1[0]*V2[2];
    res[2]=V1[0]*V2[1]-V1[1]*V2[0];
}

inline void mat_mul(TYPE A[DIM][DIM], TYPE B[DIM][DIM], TYPE C[DIM][DIM]){
   for(unsigned i=0;i< DIM  ;i++){
       for(unsigned j=0;j< DIM ;j++){
           C[i][j]=0;
           for(unsigned k=0 ;k< DIM ;k++ ){
               C[i][j]+=A[i][k]*B[k][j];
           }
       }
   }
}

inline void mul(TYPE *A, TYPE *B, int dimA[2], int dimB[2],TYPE *C ){
    //TYPE * C;
//     TYPE C[dimA[0]*dimB[1]];
//     if(dimA[1]!=dimB[0]){assert(0);}
//     else{
        for(unsigned i=0;i< dimA[0]  ;i++){
            for(unsigned j=0;j< dimB[1] ;j++){
                C[i*dimB[1]+j]=0;
                for(unsigned k=0 ;k< dimA[1] ;k++ ){
                    C[i*dimB[1]+j]+=A[i*dimA[1]+k]*B[k*dimB[1]+j];
                }
            }
        }
//     }
//     return C;
}

inline void transp(TYPE *A, int dimA[2],TYPE *C ){
//     TYPE * C;
//     TYPE C[dimA[0]*dimA[1]];
    for(unsigned i=0;i< dimA[0]  ;i++){
        for(unsigned j=0;j< dimA[1] ;j++){
            C[j*dimA[0]+i]=A[i*dimA[1]+j];
                
        }
    }

//     return C;
}

inline void mul(TYPE *A, int dimA[2], TYPE k ){
//     TYPE * C;
//     TYPE C[dimA[0]*dimA[1]];
    for(unsigned i=0;i< dimA[0]  ;i++){
        for(unsigned j=0;j< dimA[1] ;j++){
            A[i*dimA[1]+j]*=k;
                
        }
    }
//     return C;
}

template<class TT> 
inline int sign(TT a){
    int res;
    double eps=1e-16;
    if((fabs(a)-a)<=eps){
        res=1;
    }
    else {
        res=-1;
    }
    return res;
}

// Recherche valeurs propres matrices 2x2 et 3x3
inline void eig_jacobi_carre(TYPE A[DIM][DIM], TYPE V[DIM][DIM], TYPE D[DIM]){

//std::cout << "Attention valable pour un matrice carree symetrique" << endl;
    TYPE eps=1e-8;
    TYPE pi=3.14159265358979;
    int n=DIM;
    int nc=DIM;
  
    TYPE B[DIM][DIM], G[DIM][DIM];
    for(unsigned i=0;i<DIM  ;i++){
        for(unsigned j=0;j< DIM ;j++){
            B[i][j]=A[i][j];
            G[i][j]=0.0;
        }
        G[i][i]+=1.0;
    }

    TYPE maxi=1.0;
    int pq[2] = {0,1};
//int debut=1;

    int nbiter=0;

    while (maxi>eps and nbiter<=10000) {
    // recherche de p et q
        maxi=0.0;
        for(int i=0;i<DIM;++i){
            for(int j=i+1;j<DIM;++j){
                if (abs(A[i][j])>=maxi){
                    pq[0]=i;pq[1]=j;
                    maxi=abs(A[i][j]);
                }
            }
        }

    // calcul de tantheta, cos et sin
        int q=pq[1];
        int p=pq[0];
        TYPE t;
        TYPE theta;

        if (abs(A[p][q])<eps){
            t=0.0;
            theta=0.0;
        }
        else {
            TYPE v=(A[q][q]-A[p][p])/(2.0*A[p][q]);

            if (abs(v)<eps){
                t=1.0;
                theta=pi/4.0;
            }
            else {
		
                t=-1.0*v + sign(v)*sqrt(1+pow(v,2));
                theta=1.0/2.0*(atan(1.0/v));
            }
        }
	
        TYPE c=rsqrt(1.0+pow(t,2));
        TYPE s=c*t;
        c=cos(theta);
        s=sin(theta);


   // calcul de la matrice de rotation
        TYPE Gnew[DIM][DIM], Gnewt[DIM][DIM], temp[DIM][DIM], Gnewtemp[DIM][DIM];
        for(unsigned i=0;i<  DIM ;i++){
            for(unsigned j=0;j< DIM ;j++){
                Gnew[i][j]=0.;
            }
            Gnew[i][i]+=1.0;
        }

        Gnew[p][p]=c;
        Gnew[p][q]=s;
        Gnew[q][p]=-s;
        Gnew[q][q]=c;
        
        for(unsigned i=0;i< DIM  ;i++){
            for(unsigned j=0;j< DIM ;j++){
                Gnewt[i][j]=Gnew[j][i];
                Gnewtemp[i][j]=Gnew[i][j];
            }
        }
        
        mat_mul(A,Gnew,temp);
        mat_mul(Gnewt,temp,B);

        mat_mul(G,Gnewtemp,Gnew);
    	//assignation de G et A
       
        for(unsigned i=0; i< DIM ; i++){
            for(unsigned j=0;j< DIM ;j++){
                A[i][j]=B[i][j];
                G[i][j]=Gnew[i][j];
            }
        }

        nbiter+=1;
  
    }

//     if (nbiter==10000){
//         printf("\n La methode n'a pas converge au bout de 10000 iterations, l'erreur est de : %f ",maxi);
//     }


    for(unsigned i=0;i<DIM;++i){
        D[i]=A[i][i];
    }

    for(int i=0;i<DIM;++i){
        for(unsigned j=0;j<DIM;++j){
            V[i][j]=G[j][i]; 
        } 
    }

};


inline void orthonormalisation_schmidt(TYPE V[DIM][DIM]){
    int n=DIM;
    for(unsigned i=0;i<n;++i){
        TYPE vnorm[DIM];
        for(unsigned j=0;j< DIM ;j++)
            vnorm[j]=0.0;
        
        for(unsigned j=0;j<i;++j){
            TYPE dotVjVi=0.0;
            for(unsigned k=0;k< DIM  ;k++)
                dotVjVi+=V[j][k]*V[i][k];
            for(unsigned k=0;k< DIM  ;k++)
                vnorm[k] -= dotVjVi*V[j][k];
        }
        for(unsigned k=0;k< DIM  ;k++){
            V[i][k]=(V[i][k]-vnorm[k]);
            TYPE dotViVi=0.0;
            for(unsigned j=0;j< DIM ;j++)
                dotViVi+=V[i][j]*V[i][j];
            V[i][k]*=rsqrt(dotViVi);
        }
    }
};

#endif