/*
Author: Dhrumil Soni
*/
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<iomanip>
#define K 1
#define Gamma 1
class vector{
  public:
	std::pair<std::vector<double>, double> val;
	vector(std::vector<double> x,double group){
		val = std::make_pair(x,group);
	}
	void print(){
		for(int i=0;i<val.first.size();i++){
			std::cout<<val.first[i]<<" ";
		}
		std::cout<<"\n";
		std::cout<<val.second<<"\n";
		//std::cout<<val.first.first<<" "<<val.first.second<<"\n";
	}
};
double dot_product(vector v1, vector v2){
	double ans=0;
	for(int i=0;i<v1.val.first.size();i++){
		ans+=v1.val.first[i]*v2.val.first[i];
	}
	return ans;
}
double dist(vector v1,vector v2){
	double dis=0;
	for(int i=0;i<v1.val.first.size();i++){
		dis+=(v1.val.first[i]-v2.val.first[i])*(v1.val.first[i]-v2.val.first[i]);
	}
	return sqrt(dis);
}

double rbf(vector v1, vector v2){
	return exp(-0.5*Gamma*dist(v1,v2));
}
double kernel(vector v1, vector v2){
	if(K==0){
		return dot_product(v1,v2);
	}else if(K==1){
		return rbf(v1,v2);
	}
}