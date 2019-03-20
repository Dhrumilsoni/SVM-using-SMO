/*
Author: Dhrumil Soni
*/
#include<bits/stdc++.h>
#include"vector.h"

double pos(double x){
	if(x<0)
		return -x;
	return x;
}

class compute{
   public:
	std::vector<double> alphas;
	std::vector<vector> data;
	int passes, max_passes, size;
	double b, tol, c;
	
	compute(double c, double tol, int max_passes, std::vector<vector> data, int size){
		alphas.resize(size);
		b=0;
		passes=0;
		this->c=c;
		this->tol=tol;
		this->max_passes=max_passes;
		//data.resize(size);
		this->data=data;
		this->size=size;
	}
	
	double get_function_value_at(vector a){
		double val=0;
		for(int i=0;i<size;i++){
			val+=alphas[i]*data[i].val.second*dot_product(data[i], a);
		}
		val+=b;
		return val;
	}

	void get_result(){
		srand(time(NULL));
		while(passes<max_passes){
			int num_changed_alphas=0;
			for(int i=0;i<size;i++){
				double Ei=get_function_value_at(data[i])-data[i].val.second;
				if((data[i].val.second*Ei<-tol && alphas[i]<c) || (data[i].val.second*Ei>tol && alphas[i]>0)){
					int j=rand()%size;
					double Ej=get_function_value_at(data[j])-data[j].val.second;
					double L, H;
					if(data[i].val.second!=data[j].val.second){
						L=std::max((double)0, alphas[j]-alphas[i]);
						H=std::min(c,c+alphas[j]-alphas[i]);
					}else{
						L=std::max((double)0,alphas[j]+alphas[i]-c);
						H=std::min(c,alphas[i]+alphas[j]);
					}
					if(L==H){
						continue;
					}
					double eta=2*dot_product(data[i],data[j])-dot_product(data[i],data[i])-dot_product(data[j],data[j]);
					if(eta>=0){
						continue;
					}
					double alphai=alphas[i],alphaj=alphas[j];
					alphas[j]=(alphas[j]-(data[j].val.second*(Ei-Ej))/eta);
					if(alphas[j]>H){
						alphas[j]=H;
					}
					else if(alphas[j]<L){
						alphas[j]=L;
					}
					if(pos(alphas[j]-alphaj)<1e-5)
						continue;
					alphas[i]=alphas[i]+data[i].val.second*data[j].val.second*(alphaj-alphas[j]);
					double b1=b-Ei-data[i].val.second*(alphas[i]-alphai)*dot_product(data[i],data[i])-data[j].val.second*(alphas[j]-alphaj)*dot_product(data[i],data[j]);
					double b2=b-Ej-data[i].val.second*(alphas[i]-alphai)*dot_product(data[i],data[j])-data[j].val.second*(alphas[j]-alphaj)*dot_product(data[j],data[j]);
					if(alphas[i]>0 && alphas[i]<c){
						b=b1;
					}else if(alphas[j]>0 && alphas[j]<c){
						b=b2;
					}else{
						b=(b1+b2)/2;
					}
					num_changed_alphas+=1;
				}
			}
			if(num_changed_alphas==0)
				passes+=1;
			else
				passes=0;
		}
	}
};


/*
Path:
C:\Users\dhrum\AppData\Roaming\Sublime Text 3\Packages\User\SVM*/