
//-----------------------------------------------------------------------------------------
//   fonction relative ou util pour la classe tenseur
//-----------------------------------------------------------------------------------------



template<class T> Vec<T> prod_tensoriel(Vec<T> &V1,Vec<T> &V2){
    unsigned s1 = V1.size();
    unsigned s2 = V2.size();
    Vec<T> result;
    result.resize(s1*s2);
    for(unsigned i=0;i<s1;i++){
        for(unsigned j=0;j<s2;j++){
            result[j*s1+i]=V1[i]*V2[j];
        }
    }
    return result;
};
    
    
template<class T> Vec<Vec<T> > distrib_tensoriel(Vec<T> &V1,Vec<T> &V2){
    unsigned s1 = V1.size();
    unsigned s2 = V2.size();
    Vec<Vec<T> > result;
    result.resize(s1*s2);
    for(unsigned i=0;i<s1;i++){
        for(unsigned j=0;j<s2;j++){
            result[j*s1+i].push_back(V1[i]);
            result[j*s1+i].push_back(V2[j]);
        }
    }
    return result;
};
template<class T> Vec<Vec<T> > distrib_tensoriel(Vec<Vec<T> > &V1,Vec<T> &V2){
    unsigned s1 = V1.size();
    unsigned s2 = V2.size();
    Vec<Vec<T> > result;
    result.resize(s1*s2);
    for(unsigned i=0;i<s1;i++){
        for(unsigned j=0;j<s2;j++){
            for(unsigned k=0;k<V1[i].size();k++){
                result[j*s1+i].push_back(V1[i][k]);
            }
            result[j*s1+i].push_back(V2[j]);
        }
    }
    return result;
};
