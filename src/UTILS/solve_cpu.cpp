//
// C++ Implementation: solve_cpu
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "containers/vec.h"

void solve_cpu(int num_sst, TYPE *L, int *offL, int *indL,int nb_sst_motif_i, int nb_sst_motif_s, int dim_motif_i, TYPE * x1){
    for(int i=0;i<dim_motif_i;i++){
        for(int k=offL[i];k<offL[i+1]-1;k++){
            x1[i*nb_sst_motif_s+num_sst]-=L[k*nb_sst_motif_s+num_sst]*x1[indL[k]*nb_sst_motif_s+num_sst];
        }
        x1[i*nb_sst_motif_s+num_sst]*=L[(offL[i+1]-1)*nb_sst_motif_s+num_sst];
    }
    for(int i=dim_motif_i-1;i>=0;i--){
        for(int k=i+1;k<dim_motif_i;k++){
            int indLki=offL[k];
            while (indLki < offL[k+1]){
                if (indL[indLki]==i) x1[i*nb_sst_motif_s+num_sst]-=L[indLki*nb_sst_motif_s+num_sst]*x1[k*nb_sst_motif_s+num_sst];
                indLki++;
            }
        }
        x1[i*nb_sst_motif_s+num_sst]*=L[(offL[i+1]-1)*nb_sst_motif_s+num_sst];
    }
}
