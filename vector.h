#include<bits/stdc++.h>

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